#!/usr/bin/env python3
"""MDB TX-line end-to-end tester for the ESP32 cashless reader.

The script talks to the USB serial console, uses the real command hooks already
present in firmware, and records a structured report for:
  - reader/dialogue initialization progress,
  - credit arming,
  - BEGIN SESSION transmission on the MDB bus,
  - ACK/timeout after BEGIN SESSION.

Important:
  - rx_invert is fixed to OFF for this hardware revision.
  - credit amounts are passed in minor units used by the firmware. With the
    current setup scale factor 100, --credit 1 means 0.01 currency units on MDB.
"""

from __future__ import annotations

import argparse
import json
import sys
import threading
import time
import traceback
import uuid
from collections import deque
from dataclasses import asdict, dataclass, field
from datetime import datetime
from pathlib import Path
from typing import Any, Callable, Optional

import serial
from serial import SerialException


DEFAULT_PORT = "/dev/ttyUSB0"
DEFAULT_BAUD = 115200
DEFAULT_SERIAL_TIMEOUT_S = 0.20
DEFAULT_OUT_DIR = Path.cwd()
DEFAULT_CREDIT_MINOR = 1

PROBE_TIMEOUT_S = 8.0
PROBE_RETRY_INTERVAL_S = 0.75
BASELINE_TAIL_WINDOW_S = 2.5
DECODER_TIMEOUT_S = 8.0
DECODER_RETRY_INTERVAL_S = 1.0
PAYMENT_TIMEOUT_S = 4.0
APPROVE_TIMEOUT_S = 4.0
INIT_TIMEOUT_S = 60.0
INIT_PROBE_INTERVAL_S = 5.0
BEGIN_SESSION_TX_TIMEOUT_S = 20.0
BEGIN_SESSION_ACK_TIMEOUT_S = 6.0
FINAL_DRAIN_S = 1.5
RECENT_EVENT_LIMIT = 300
RAW_LINE_BUFFER_LIMIT = 32 * 1024
JSON_BUFFER_LIMIT = 256 * 1024
MALFORMED_FRAGMENT_LOG_LIMIT = 240
PARSED_OBJECT_QUEUE_LIMIT = 512
EVENT_QUEUE_LIMIT = 512
RAW_FRAGMENT_QUEUE_LIMIT = 512
BACKGROUND_WAIT_SLICE_S = 0.05
PROTOCOL_EVIDENCE_GRACE_S = 0.35

EXPLICIT_SNAPSHOT_EVENTS = {"probe"}
ALTERNATIVE_SNAPSHOT_EVENTS = {
    "phy_decoder_status",
    "response_path_state",
    "reader_state_transition",
    "state_changed",
}
PROTOCOL_ALIVE_EVENTS = {
    "dialogue_trace",
    "rx_frame_accepted",
    "rx_frame_tentative",
    "response_path_state",
    "reader_state_transition",
    "state_changed",
    "response_decision",
    "mdb_bus_tx_raw",
    "cashless_setup_response",
    "cashless_setup_response_timing",
    "poll_rx_seen",
    "enable_seen",
    "enable_accepted",
    "enable_state_applied",
    "disable_seen",
    "disable_state_applied",
}
CONFIG_ONLY_EVENTS = {
    "rx_invert_changed",
    "passive_sniff_changed",
}


def now_iso() -> str:
    return datetime.now().astimezone().isoformat(timespec="milliseconds")


def compact_json(value: Any) -> str:
    return json.dumps(value, ensure_ascii=False, separators=(",", ":"))


def summarize_fragment(text: str, limit: int = MALFORMED_FRAGMENT_LOG_LIMIT) -> str:
    compact = text.replace("\r", "\\r").replace("\n", "\\n")
    if len(compact) <= limit:
        return compact
    return compact[:limit] + "...<trimmed>"


class StreamJsonExtractor:
    """Incremental extractor for noisy serial JSON streams.

    It keeps a byte buffer across reads, extracts every complete top-level JSON
    object, preserves trailing partial JSON for the next feed, and classifies
    discarded fragments so the caller can distinguish real noise from partial
    or concatenated JSON traffic.
    """

    def __init__(self, buffer_limit: int = JSON_BUFFER_LIMIT) -> None:
        self.buffer_limit = buffer_limit
        self.buffer = bytearray()
        self.parser_buffer_peak_bytes = 0

    def extract_text(self, text: str) -> tuple[list[dict[str, Any]], list[dict[str, Any]]]:
        objects: list[dict[str, Any]] = []
        dropped: list[dict[str, Any]] = []
        decoder = json.JSONDecoder()
        cursor = 0

        while cursor < len(text):
            start = text.find("{", cursor)
            if start < 0:
                if cursor < len(text):
                    tail = text[cursor:]
                    dropped.append(
                        {
                            "kind": "true_noise_fragment",
                            "text": tail,
                            "summary": summarize_fragment(tail),
                        }
                    )
                break

            if start > cursor:
                noise = text[cursor:start]
                dropped.append(
                    {
                        "kind": "true_noise_fragment",
                        "text": noise,
                        "summary": summarize_fragment(noise),
                    }
                )

            try:
                parsed, end = decoder.raw_decode(text, start)
                consumed = text[start:end]
                cursor = end
            except json.JSONDecodeError:
                balanced_end = self._find_balanced_end_text(text[start:])
                if balanced_end is None:
                    fragment = text[start:]
                    dropped.append(
                        {
                            "kind": "partial_json_fragment",
                            "text": fragment,
                            "summary": summarize_fragment(fragment),
                        }
                    )
                    break

                candidate_end = start + balanced_end + 1
                candidate = text[start:candidate_end]
                try:
                    parsed, end = decoder.raw_decode(candidate)
                    consumed = candidate[:end]
                    cursor = start + end
                except json.JSONDecodeError:
                    dropped.append(
                        {
                            "kind": "malformed_json",
                            "text": candidate,
                            "summary": summarize_fragment(candidate),
                        }
                    )
                    cursor = candidate_end
                    continue

            if isinstance(parsed, dict):
                objects.append(parsed)
                if cursor < len(text) and text[cursor:cursor + 1] == "{":
                    dropped.append(
                        {
                            "kind": "concatenated_json_fragment",
                            "text": "",
                            "summary": "adjacent_json_objects_without_separator",
                        }
                    )
            else:
                dropped.append(
                    {
                        "kind": "non_object_json",
                        "text": consumed,
                        "summary": summarize_fragment(consumed),
                    }
                )

        return objects, dropped

    def feed(
        self, chunk: bytes
    ) -> tuple[list[dict[str, Any]], list[dict[str, Any]], dict[str, int]]:
        objects: list[dict[str, Any]] = []
        fragments: list[dict[str, Any]] = []
        stats = {
            "concatenated_json_count": 0,
            "partial_json_count": 0,
            "partial_buffer_flush_count": 0,
            "parser_buffer_peak_bytes": 0,
        }

        if chunk:
            self.buffer.extend(chunk)
            self.parser_buffer_peak_bytes = max(self.parser_buffer_peak_bytes, len(self.buffer))
            stats["parser_buffer_peak_bytes"] = self.parser_buffer_peak_bytes

        while self.buffer:
            start = self.buffer.find(b"{")
            if start < 0:
                if self.buffer:
                    noise = bytes(self.buffer)
                    fragments.append(
                        {
                            "kind": "true_noise_fragment",
                            "text": noise.decode("utf-8", errors="replace"),
                            "summary": summarize_fragment(
                                noise.decode("utf-8", errors="replace")
                            ),
                            "bytes_len": len(noise),
                        }
                    )
                    self.buffer.clear()
                break

            if start > 0:
                noise = bytes(self.buffer[:start])
                fragments.append(
                    {
                        "kind": "true_noise_fragment",
                        "text": noise.decode("utf-8", errors="replace"),
                        "summary": summarize_fragment(noise.decode("utf-8", errors="replace")),
                        "bytes_len": len(noise),
                    }
                )
                del self.buffer[:start]

            end = self._find_balanced_end_bytes(self.buffer)
            if end is None:
                newline_index = self.buffer.find(b"\n")
                if newline_index >= 0:
                    malformed = bytes(self.buffer[: newline_index + 1])
                    fragments.append(
                        {
                            "kind": "malformed_json",
                            "text": malformed.decode("utf-8", errors="replace"),
                            "summary": summarize_fragment(
                                malformed.decode("utf-8", errors="replace")
                            ),
                            "bytes_len": len(malformed),
                        }
                    )
                    del self.buffer[: newline_index + 1]
                    continue
                stats["partial_json_count"] += 1
                fragments.append(
                    {
                        "kind": "partial_json_fragment",
                        "text": self.buffer.decode("utf-8", errors="replace"),
                        "summary": summarize_fragment(
                            self.buffer.decode("utf-8", errors="replace")
                        ),
                        "bytes_len": len(self.buffer),
                    }
                )
                break

            candidate = bytes(self.buffer[: end + 1])
            del self.buffer[: end + 1]
            candidate_text = candidate.decode("utf-8", errors="replace")
            try:
                parsed = json.loads(candidate_text)
            except json.JSONDecodeError:
                fragments.append(
                    {
                        "kind": "malformed_json",
                        "text": candidate_text,
                        "summary": summarize_fragment(candidate_text),
                        "bytes_len": len(candidate),
                    }
                )
                continue

            if isinstance(parsed, dict):
                objects.append(parsed)
                if self.buffer.startswith(b"{"):
                    stats["concatenated_json_count"] += 1
                    fragments.append(
                        {
                            "kind": "concatenated_json_fragment",
                            "text": "",
                            "summary": "adjacent_json_objects_without_separator",
                            "bytes_len": 0,
                        }
                    )
            else:
                fragments.append(
                    {
                        "kind": "non_object_json",
                        "text": candidate_text,
                        "summary": summarize_fragment(candidate_text),
                        "bytes_len": len(candidate),
                    }
                )

        if len(self.buffer) > self.buffer_limit:
            fragments.append(
                {
                    "kind": "partial_buffer_flush",
                    "text": self.buffer.decode("utf-8", errors="replace"),
                    "summary": summarize_fragment(
                        self.buffer.decode("utf-8", errors="replace")
                    ),
                    "bytes_len": len(self.buffer),
                }
            )
            self.buffer.clear()
            stats["partial_buffer_flush_count"] += 1

        stats["parser_buffer_peak_bytes"] = max(
            stats["parser_buffer_peak_bytes"], self.parser_buffer_peak_bytes
        )
        return objects, fragments, stats

    @staticmethod
    def _find_balanced_end_bytes(buffer: bytearray) -> int | None:
        depth = 0
        in_string = False
        escape = False
        for index, byte in enumerate(buffer):
            ch = chr(byte)
            if in_string:
                if escape:
                    escape = False
                elif ch == "\\":
                    escape = True
                elif ch == '"':
                    in_string = False
                continue

            if ch == '"':
                in_string = True
                continue
            if ch == "{":
                depth += 1
                continue
            if ch == "}":
                depth -= 1
                if depth == 0:
                    return index
        return None

    @staticmethod
    def _find_balanced_end_text(text: str) -> int | None:
        depth = 0
        in_string = False
        escape = False
        for index, ch in enumerate(text):
            if in_string:
                if escape:
                    escape = False
                elif ch == "\\":
                    escape = True
                elif ch == '"':
                    in_string = False
                continue

            if ch == '"':
                in_string = True
                continue
            if ch == "{":
                depth += 1
                continue
            if ch == "}":
                depth -= 1
                if depth == 0:
                    return index
        return None


@dataclass
class StepRecord:
    name: str
    started_at: str
    status: str = "running"
    ended_at: str | None = None
    commands: list[dict[str, Any]] = field(default_factory=list)
    raw_lines: list[str] = field(default_factory=list)
    parsed_events: list[dict[str, Any]] = field(default_factory=list)
    parsed_result: dict[str, Any] = field(default_factory=dict)
    error: str | None = None

    def finish(self, status: str, parsed_result: Optional[dict[str, Any]] = None) -> None:
        self.status = status
        self.ended_at = now_iso()
        if parsed_result:
            self.parsed_result.update(parsed_result)


@dataclass
class EventRecord:
    seq: int
    ts: str
    event: str
    details: dict[str, Any]


@dataclass
class ExtractedObjectRecord:
    seq: int
    ts: str
    obj: dict[str, Any]


@dataclass
class ActiveCommandMetrics:
    command: str
    expected_events: set[str]
    send_ts: float
    attempt_count: int = 1
    first_byte_rx_ts: float | None = None
    first_json_extracted_ts: float | None = None
    event_dispatched_ts: float | None = None
    first_probe_event_ts: float | None = None
    wait_completed_ts: float | None = None


@dataclass
class TestState:
    latest_probe: dict[str, Any] = field(default_factory=dict)
    latest_decoder_status: dict[str, Any] = field(default_factory=dict)
    event_seq: int = 0
    recent_events: deque[EventRecord] = field(
        default_factory=lambda: deque(maxlen=RECENT_EVENT_LIMIT)
    )
    explicit_probe_seen: bool = False
    last_dialogue_trace: dict[str, Any] = field(default_factory=dict)
    last_rx_frame_accepted: dict[str, Any] = field(default_factory=dict)
    last_rx_frame_tentative: dict[str, Any] = field(default_factory=dict)
    last_response_path_state_event: dict[str, Any] = field(default_factory=dict)
    last_state_changed: dict[str, Any] = field(default_factory=dict)

    current_dialogue_phase: str = "unknown"
    last_reader_state: str = "unknown"
    last_rx_kind: str = "unknown"
    last_tx_kind: str = "unknown"
    last_no_response_reason: str = ""
    last_state_transition_reason: str = ""
    last_tx_error_reason: str = ""
    session_state: str = "unknown"

    response_path_state: str = "unknown"
    rx_frame_count: int = 0
    tx_frame_count: int = 0
    poll_rx_count: int = 0
    poll_tx_count: int = 0
    enable_rx_count: int = 0
    enable_applied_count: int = 0
    setup_rx_count: int = 0
    setup_tx_count: int = 0
    expansion_rx_count: int = 0
    expansion_tx_count: int = 0
    ack_tx_count: int = 0
    no_response_count: int = 0
    state_transition_count: int = 0
    tx_attempt_count: int = 0
    tx_success_count: int = 0
    tx_abort_count: int = 0
    tx_timeout_count: int = 0
    begin_session_tx_count: int = 0
    begin_session_ack_count: int = 0
    last_begin_session_status: str = ""
    last_begin_session_tx_us: int = 0
    last_begin_session_ack_us: int = 0
    rx_to_tx_latency_us: int = 0
    rx_invert: Optional[bool] = None
    passive_sniff: Optional[bool] = None
    reader_enabled: Optional[bool] = None

    last_rx_frame: dict[str, Any] = field(default_factory=dict)
    last_tx_frame: dict[str, Any] = field(default_factory=dict)
    last_response_decision: dict[str, Any] = field(default_factory=dict)

    saw_reset_phase: bool = False
    saw_setup: bool = False
    saw_setup_response: bool = False
    saw_enable: bool = False
    saw_poll: bool = False

    payment_recorded: bool = False
    payment_rejected: bool = False
    credit_approved: bool = False
    approve_rejected: bool = False
    begin_session_armed: bool = False
    begin_session_sent: bool = False
    begin_session_bus_tx: bool = False
    begin_session_ack_received: bool = False
    begin_session_ack_missing: bool = False

    last_payment_reason: str = ""
    last_approve_reason: str = ""

    def sync_from_probe(self, details: dict[str, Any]) -> None:
        self.latest_probe = details
        self.current_dialogue_phase = details.get(
            "current_dialogue_phase", self.current_dialogue_phase
        )
        self.last_reader_state = details.get("last_reader_state", self.last_reader_state)
        self.last_rx_kind = details.get("last_rx_kind", self.last_rx_kind)
        self.last_tx_kind = details.get("last_tx_kind", self.last_tx_kind)
        self.last_no_response_reason = details.get(
            "last_no_response_reason", self.last_no_response_reason
        )
        self.last_state_transition_reason = details.get(
            "last_state_transition_reason", self.last_state_transition_reason
        )
        self.last_tx_error_reason = details.get(
            "last_tx_error_reason", self.last_tx_error_reason
        )
        self.response_path_state = details.get(
            "response_path_state", self.response_path_state
        )
        self.session_state = details.get("state", self.session_state)

        self.rx_frame_count = int(details.get("rx_frame_count", self.rx_frame_count))
        self.tx_frame_count = int(details.get("tx_frame_count", self.tx_frame_count))
        self.poll_rx_count = int(details.get("poll_rx_count", self.poll_rx_count))
        self.poll_tx_count = int(details.get("poll_tx_count", self.poll_tx_count))
        self.enable_rx_count = int(details.get("enable_rx_count", self.enable_rx_count))
        self.enable_applied_count = int(
            details.get("enable_applied_count", self.enable_applied_count)
        )
        self.setup_rx_count = int(details.get("setup_rx_count", self.setup_rx_count))
        self.setup_tx_count = int(details.get("setup_tx_count", self.setup_tx_count))
        self.expansion_rx_count = int(
            details.get("expansion_rx_count", self.expansion_rx_count)
        )
        self.expansion_tx_count = int(
            details.get("expansion_tx_count", self.expansion_tx_count)
        )
        self.ack_tx_count = int(details.get("ack_tx_count", self.ack_tx_count))
        self.no_response_count = int(
            details.get("no_response_count", self.no_response_count)
        )
        self.state_transition_count = int(
            details.get("state_transition_count", self.state_transition_count)
        )
        self.tx_attempt_count = int(details.get("tx_attempt_count", self.tx_attempt_count))
        self.tx_success_count = int(details.get("tx_success_count", self.tx_success_count))
        self.tx_abort_count = int(details.get("tx_abort_count", self.tx_abort_count))
        self.tx_timeout_count = int(details.get("tx_timeout_count", self.tx_timeout_count))
        self.begin_session_tx_count = int(
            details.get("begin_session_tx_count", self.begin_session_tx_count)
        )
        self.begin_session_ack_count = int(
            details.get("begin_session_ack_count", self.begin_session_ack_count)
        )
        self.last_begin_session_status = details.get(
            "last_begin_session_status", self.last_begin_session_status
        )
        self.last_begin_session_tx_us = int(
            details.get("last_begin_session_tx_us", self.last_begin_session_tx_us)
        )
        self.last_begin_session_ack_us = int(
            details.get("last_begin_session_ack_us", self.last_begin_session_ack_us)
        )
        self.rx_to_tx_latency_us = int(
            details.get("rx_to_tx_latency_us", self.rx_to_tx_latency_us)
        )
        if "rx_invert" in details:
            self.rx_invert = bool(details.get("rx_invert"))
        if "passive_sniff" in details:
            self.passive_sniff = bool(details.get("passive_sniff"))
        if "reader_enabled" in details:
            self.reader_enabled = bool(details.get("reader_enabled"))

        self.last_rx_frame = details.get("last_rx_frame", self.last_rx_frame)
        self.last_tx_frame = details.get("last_tx_frame", self.last_tx_frame)
        self.last_response_decision = details.get(
            "last_response_decision", self.last_response_decision
        )

        self.saw_setup |= self.setup_rx_count > 0
        self.saw_setup_response |= self.setup_tx_count > 0
        self.saw_enable |= self.enable_applied_count > 0 or bool(self.reader_enabled)
        self.saw_poll |= self.poll_rx_count > 0
        self.begin_session_sent |= self.begin_session_tx_count > 0
        self.begin_session_ack_received |= self.begin_session_ack_count > 0

        for event in details.get("dialogue_history", []):
            self._digest_dialogue_history_item(event)

    def sync_from_decoder_status(self, details: dict[str, Any]) -> None:
        self.latest_decoder_status = details

    def update_from_event(self, event: str, details: dict[str, Any]) -> None:
        self.event_seq += 1
        self.recent_events.append(
            EventRecord(seq=self.event_seq, ts=now_iso(), event=event, details=details)
        )

        if event == "probe":
            self.explicit_probe_seen = True
            self.sync_from_probe(details)
            return
        if event == "phy_decoder_status":
            self.sync_from_decoder_status(details)
            return
        if event == "dialogue_trace":
            self.last_dialogue_trace = details
            self._digest_dialogue_trace(details)
            return
        if event == "rx_frame_accepted":
            self.last_rx_frame_accepted = details
            self.last_rx_frame = details
            return
        if event == "rx_frame_tentative":
            self.last_rx_frame_tentative = details
            return
        if event == "reader_state_transition":
            self.last_state_changed = details
            self.last_reader_state = details.get("new_state", self.last_reader_state)
            self.last_state_transition_reason = details.get(
                "reason", self.last_state_transition_reason
            )
            return
        if event == "state_changed":
            self.last_state_changed = details
            self.last_reader_state = details.get("new_state", self.last_reader_state)
            return
        if event in {"enable_seen", "enable_accepted", "enable_state_applied"}:
            self.saw_enable = True
            if event == "enable_state_applied":
                self.reader_enabled = True
                self.enable_applied_count += 1
            return
        if event in {"disable_seen", "disable_state_applied"}:
            if event == "disable_state_applied":
                self.reader_enabled = False
            return
        if event == "poll_rx_seen":
            self.saw_poll = True
            return
        if event in {"cashless_setup_response", "cashless_setup_response_timing"}:
            self.saw_setup_response = True
            return
        if event in {"payment_received", "payment_ignored"}:
            self.payment_recorded = event == "payment_received"
            if event == "payment_ignored":
                self.last_payment_reason = details.get("reason", "payment_ignored")
            return
        if event == "payment_rejected":
            self.payment_rejected = True
            self.last_payment_reason = details.get("reason", "")
            return
        if event == "credit_approved":
            self.credit_approved = True
            self.last_approve_reason = "payment_approved"
            return
        if event == "approve_rejected":
            self.approve_rejected = True
            self.last_approve_reason = details.get("reason", "")
            return
        if event == "cashless_begin_session_armed":
            self.begin_session_armed = True
            return
        if event in {"cashless_begin_session_sent", "cashless_begin_session_tx_state"}:
            self.begin_session_sent = True
            status = details.get("status")
            if isinstance(status, str):
                self.last_begin_session_status = status
            return
        if event == "cashless_begin_session_ack_received":
            self.begin_session_ack_received = True
            self.last_begin_session_status = "ack_received"
            return
        if event == "cashless_begin_session_ack_missing":
            self.begin_session_ack_missing = True
            self.last_begin_session_status = details.get("reason", "ack_missing")
            return
        if event == "mdb_bus_tx_raw":
            tx_kind = str(details.get("tx_kind", ""))
            if tx_kind == "begin_session":
                self.begin_session_bus_tx = True
                self.begin_session_sent = True
            self.last_tx_kind = tx_kind or self.last_tx_kind
            return
        if event == "response_path_state":
            self.last_response_path_state_event = details
            self.response_path_state = details.get("state", self.response_path_state)
            return

    def _digest_dialogue_history_item(self, event: dict[str, Any]) -> None:
        direction = str(event.get("direction", ""))
        kind = str(event.get("kind", ""))
        state_after = str(event.get("state_after", ""))
        self._apply_dialogue_kind(direction, kind, state_after)

    def _digest_dialogue_trace(self, details: dict[str, Any]) -> None:
        direction = str(details.get("direction", ""))
        kind = str(details.get("kind", ""))
        state_after = str(details.get("reader_state_after", ""))
        self._apply_dialogue_kind(direction, kind, state_after)

    def _apply_dialogue_kind(self, direction: str, kind: str, state_after: str) -> None:
        if kind == "RESET":
            self.saw_reset_phase = True
        if kind == "SETUP":
            self.saw_setup = True
        if direction == "TX_TO_MACHINE" and kind == "READER_CONFIG":
            self.saw_setup_response = True
        if kind == "ENABLE":
            self.saw_enable = True
        if kind == "POLL":
            self.saw_poll = True
        if state_after:
            self.last_reader_state = state_after

    def initialization_ready(self) -> bool:
        return self.saw_setup_response and self.saw_enable and self.saw_poll

    def recent_event_kinds(self) -> list[str]:
        return sorted({evt.event for evt in self.recent_events})

    def protocol_alive(self) -> bool:
        if self.explicit_probe_seen:
            return True
        if self.saw_setup or self.saw_setup_response or self.saw_enable or self.saw_poll:
            return True
        return any(evt.event in PROTOCOL_ALIVE_EVENTS for evt in self.recent_events)

    def baseline_health(self, probe_supported: str = "unknown") -> dict[str, Any]:
        events_seen = self.recent_event_kinds()
        if self.explicit_probe_seen:
            baseline_status = "BASELINE_OK_EXPLICIT_PROBE"
            health_score = 100
        elif self.protocol_alive():
            baseline_status = "BASELINE_OK_PROTOCOL_ALIVE_NO_PROBE"
            health_score = 60
        elif events_seen and set(events_seen).issubset(CONFIG_ONLY_EVENTS):
            baseline_status = "BASELINE_WEAK_CONFIG_ONLY"
            health_score = 30
        elif events_seen:
            baseline_status = "BASELINE_FAIL_PARSER_BROKEN"
            health_score = 10
        else:
            baseline_status = "BASELINE_FAIL_NO_PROTOCOL"
            health_score = 0
        return {
            "baseline_status": baseline_status,
            "health_score": health_score,
            "probe_supported": probe_supported,
            "protocol_alive": self.protocol_alive(),
            "events_seen": events_seen,
        }

    def machine_acceptance_status(self) -> str:
        if self.begin_session_ack_received:
            return "accepted"
        if self.begin_session_ack_missing:
            return "not_accepted"
        return "unknown"

    def summary(self) -> dict[str, Any]:
        return {
            "current_dialogue_phase": self.current_dialogue_phase,
            "last_reader_state": self.last_reader_state,
            "session_state": self.session_state,
            "response_path_state": self.response_path_state,
            "last_rx_kind": self.last_rx_kind,
            "last_tx_kind": self.last_tx_kind,
            "rx_invert": self.rx_invert,
            "passive_sniff": self.passive_sniff,
            "reader_enabled": self.reader_enabled,
            "rx_frame_count": self.rx_frame_count,
            "tx_frame_count": self.tx_frame_count,
            "poll_rx_count": self.poll_rx_count,
            "poll_tx_count": self.poll_tx_count,
            "enable_rx_count": self.enable_rx_count,
            "enable_applied_count": self.enable_applied_count,
            "setup_rx_count": self.setup_rx_count,
            "setup_tx_count": self.setup_tx_count,
            "expansion_rx_count": self.expansion_rx_count,
            "expansion_tx_count": self.expansion_tx_count,
            "ack_tx_count": self.ack_tx_count,
            "no_response_count": self.no_response_count,
            "state_transition_count": self.state_transition_count,
            "tx_attempt_count": self.tx_attempt_count,
            "tx_success_count": self.tx_success_count,
            "tx_abort_count": self.tx_abort_count,
            "tx_timeout_count": self.tx_timeout_count,
            "begin_session_tx_count": self.begin_session_tx_count,
            "begin_session_ack_count": self.begin_session_ack_count,
            "last_begin_session_status": self.last_begin_session_status,
            "last_begin_session_tx_us": self.last_begin_session_tx_us,
            "last_begin_session_ack_us": self.last_begin_session_ack_us,
            "last_response_decision": self.last_response_decision,
            "last_rx_frame": self.last_rx_frame,
            "last_tx_frame": self.last_tx_frame,
            "last_dialogue_trace": self.last_dialogue_trace,
            "last_rx_frame_accepted": self.last_rx_frame_accepted,
            "last_rx_frame_tentative": self.last_rx_frame_tentative,
            "last_response_path_state_event": self.last_response_path_state_event,
            "last_state_changed": self.last_state_changed,
            "recent_event_kinds": self.recent_event_kinds(),
            "last_tx_error_reason": self.last_tx_error_reason,
            "last_no_response_reason": self.last_no_response_reason,
            "last_state_transition_reason": self.last_state_transition_reason,
            "rx_to_tx_latency_us": self.rx_to_tx_latency_us,
            "phases": {
                "reset_observed": self.saw_reset_phase,
                "setup_observed": self.saw_setup,
                "setup_response_observed": self.saw_setup_response,
                "enable_observed": self.saw_enable,
                "poll_observed": self.saw_poll,
            },
            "credit_flow": {
                "payment_recorded": self.payment_recorded,
                "payment_rejected": self.payment_rejected,
                "credit_approved": self.credit_approved,
                "approve_rejected": self.approve_rejected,
                "begin_session_armed": self.begin_session_armed,
                "begin_session_sent": self.begin_session_sent,
                "begin_session_bus_tx": self.begin_session_bus_tx,
                "begin_session_ack_received": self.begin_session_ack_received,
                "begin_session_ack_missing": self.begin_session_ack_missing,
                "machine_acceptance_status": self.machine_acceptance_status(),
                "payment_reason": self.last_payment_reason,
                "approve_reason": self.last_approve_reason,
            },
        }


class StepFailure(RuntimeError):
    """Raised when a test step fails."""


class SerialCommandClient:
    def __init__(
        self,
        port: str,
        baud: int,
        serial_timeout: float,
        log_path: Path,
        verbose: bool,
    ) -> None:
        self.port = port
        self.baud = baud
        self.serial_timeout = serial_timeout
        self.log_path = log_path
        self.verbose = verbose
        self.ser: serial.Serial | None = None
        self.log_file = None
        self.current_step: StepRecord | None = None
        self.state = TestState()
        self.last_exception: str | None = None
        self._raw_line_buffer = ""
        self._extractor = StreamJsonExtractor()
        self._reader_thread: threading.Thread | None = None
        self._stop_reader = threading.Event()
        self._condition = threading.Condition()
        self._reader_exception: str | None = None
        self._event_queue: deque[EventRecord] = deque(maxlen=EVENT_QUEUE_LIMIT)
        self._parsed_object_queue: deque[ExtractedObjectRecord] = deque(
            maxlen=PARSED_OBJECT_QUEUE_LIMIT
        )
        self._raw_fragment_queue: deque[dict[str, Any]] = deque(maxlen=RAW_FRAGMENT_QUEUE_LIMIT)
        self._parsed_object_seq = 0
        self._active_request: ActiveCommandMetrics | None = None

        self.malformed_fragment_count = 0
        self.recovered_json_count = 0
        self.skipped_noise_count = 0
        self.partial_buffer_flush_count = 0
        self.concatenated_json_count = 0
        self.partial_json_count = 0
        self.parser_buffer_peak_bytes = 0
        self.parser_queue_peak_len = 0
        self.event_queue_peak_len = 0
        self.probe_request_count = 0
        self.probe_response_count = 0
        self.probe_timeout_count = 0
        self.noise_bytes_total = 0
        self.json_bytes_total = 0
        self.retry_count = 0
        self.malformed_resync_count = 0
        self.recovered_after_malformed_count = 0
        self._probe_roundtrip_samples_ms: list[float] = []
        self._parse_latency_samples_ms: list[float] = []
        self._dispatch_latency_samples_ms: list[float] = []
        self.last_request_metrics: dict[str, Any] = {}
        self._pending_noise_summary = ""
        self._pending_noise_count = 0
        self._pending_noise_bytes = 0
        self._awaiting_malformed_recovery = False
        self._last_malformed_skipped_bytes = 0

    def __enter__(self) -> "SerialCommandClient":
        self.log_path.parent.mkdir(parents=True, exist_ok=True)
        self.log_file = self.log_path.open("w", encoding="utf-8", buffering=8192)
        self._log_human("INFO", f"Opening {self.port} at {self.baud} baud")
        self.ser = serial.Serial(
            self.port,
            self.baud,
            timeout=min(self.serial_timeout, 0.02),
            write_timeout=self.serial_timeout,
        )
        self.ser.reset_input_buffer()
        self._stop_reader.clear()
        self._reader_thread = threading.Thread(
            target=self._reader_loop,
            name="mdb-tx-line-reader",
            daemon=True,
        )
        self._reader_thread.start()
        time.sleep(0.10)
        self.drain(0.4)
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        if exc is not None:
            self.last_exception = "".join(traceback.format_exception(exc_type, exc, tb))
            self._log_human("ERROR", self.last_exception.rstrip())
        try:
            self.drain(FINAL_DRAIN_S)
        except Exception:
            pass
        self._flush_pending_noise_log()
        self._stop_reader.set()
        if self._reader_thread is not None:
            self._reader_thread.join(timeout=1.0)
        if self.ser is not None:
            try:
                self.ser.close()
            except Exception:
                pass
        if self.log_file is not None:
            self.log_file.flush()
            self.log_file.close()

    def _log_human(self, level: str, message: str) -> None:
        line = f"[{now_iso()}] {level} {message}"
        if self.verbose or level in {"ERROR", "WARN"}:
            print(line)
        if self.log_file is not None:
            self.log_file.write(line + "\n")

    def _log_serial(self, direction: str, message: str) -> None:
        line = f"[{now_iso()}] {direction} {message}"
        if self.verbose:
            print(line)
        if self.log_file is not None:
            self.log_file.write(line + "\n")

    def _flush_pending_noise_log(self) -> None:
        if self._pending_noise_count <= 0 or not self._pending_noise_summary:
            return
        if self._pending_noise_count == 1:
            message = self._pending_noise_summary
        else:
            message = (
                f"x{self._pending_noise_count} bytes={self._pending_noise_bytes} "
                f"{self._pending_noise_summary}"
            )
        self._log_serial("NOISE", message)
        if self.current_step is not None:
            self.current_step.raw_lines.append(f"<noise>{message}")
        self._pending_noise_summary = ""
        self._pending_noise_count = 0
        self._pending_noise_bytes = 0

    @staticmethod
    def _average(values: list[float]) -> float | None:
        if not values:
            return None
        return round(sum(values) / len(values), 3)

    def parser_stats(self) -> dict[str, Any]:
        return {
            "malformed_fragment_count": self.malformed_fragment_count,
            "recovered_json_count": self.recovered_json_count,
            "skipped_noise_count": self.skipped_noise_count,
            "partial_buffer_flush_count": self.partial_buffer_flush_count,
            "concatenated_json_count": self.concatenated_json_count,
            "partial_json_count": self.partial_json_count,
            "parser_buffer_peak_bytes": self.parser_buffer_peak_bytes,
            "parser_queue_peak_len": self.parser_queue_peak_len,
            "event_queue_peak_len": self.event_queue_peak_len,
            "probe_request_count": self.probe_request_count,
            "probe_response_count": self.probe_response_count,
            "probe_timeout_count": self.probe_timeout_count,
            "average_probe_roundtrip_ms": self._average(self._probe_roundtrip_samples_ms),
            "average_parse_latency_ms": self._average(self._parse_latency_samples_ms),
            "average_dispatch_latency_ms": self._average(self._dispatch_latency_samples_ms),
            "recovered_probe_count": self.probe_response_count,
            "retry_count": self.retry_count,
            "noise_bytes_total": self.noise_bytes_total,
            "json_bytes_total": self.json_bytes_total,
            "recovered_after_malformed_count": self.recovered_after_malformed_count,
            "malformed_resync_count": self.malformed_resync_count,
        }

    def request_metrics(self) -> dict[str, Any]:
        return json.loads(json.dumps(self.last_request_metrics))

    def begin_step(self, name: str) -> StepRecord:
        step = StepRecord(name=name, started_at=now_iso())
        self.current_step = step
        self._log_human("STEP", f"BEGIN {name}")
        return step

    def end_step(self, step: StepRecord, status: str, parsed_result: Optional[dict[str, Any]] = None) -> StepRecord:
        self._flush_pending_noise_log()
        step.finish(status, parsed_result)
        self._log_human("STEP", f"END {step.name}: {status}")
        if self.log_file is not None:
            self.log_file.flush()
        self.current_step = None
        return step

    def send_command(self, command: str, payload: Optional[dict[str, Any]] = None) -> None:
        if self.ser is None:
            raise StepFailure("serial_port_not_open")
        envelope = {
            "type": "command",
            "payload": {
                "command": command,
                "payload": payload or {},
            },
        }
        text = compact_json(envelope)
        if self.current_step is not None:
            self.current_step.commands.append({"command": command, "payload": payload or {}})
        if command == "mdb_probe":
            self.probe_request_count += 1
        self._log_serial("TX", text)
        with self._condition:
            self.ser.write((text + "\n").encode("utf-8"))
            self.ser.flush()

    def drain(self, duration_s: float) -> None:
        deadline = time.monotonic() + duration_s
        while time.monotonic() < deadline:
            self._raise_reader_exception_if_needed()
            time.sleep(0.01)

    def clear_transport_backlog(self) -> None:
        if self.ser is None:
            raise StepFailure("serial_port_not_open")
        with self._condition:
            self.ser.reset_input_buffer()
            self._extractor = StreamJsonExtractor()
            self._raw_line_buffer = ""
            self._event_queue.clear()
            self._parsed_object_queue.clear()
            self._raw_fragment_queue.clear()
            self._condition.notify_all()
        self._flush_pending_noise_log()
        self._log_human("INFO", "transport backlog cleared before baseline probe")

    def _reader_loop(self) -> None:
        try:
            while not self._stop_reader.is_set():
                if self.ser is None:
                    return
                raw = self.ser.read(self.ser.in_waiting or 1)
                if not raw:
                    continue
                received_ts = time.monotonic()
                self._mark_first_byte_rx(received_ts)
                text = raw.decode("utf-8", errors="replace")
                self._capture_raw_lines(text)
                self._consume_json_stream(raw, received_ts)
        except Exception:
            self._reader_exception = traceback.format_exc()
            self._log_human("ERROR", self._reader_exception.rstrip())
            with self._condition:
                self._condition.notify_all()

    def _raise_reader_exception_if_needed(self) -> None:
        if self._reader_exception:
            raise StepFailure(f"reader_thread_failed:{self._reader_exception.splitlines()[-1]}")

    def _mark_first_byte_rx(self, received_ts: float) -> None:
        with self._condition:
            if (
                self._active_request
                and received_ts >= self._active_request.send_ts
                and self._active_request.first_byte_rx_ts is None
            ):
                self._active_request.first_byte_rx_ts = received_ts

    def _capture_raw_lines(self, text: str) -> None:
        self._raw_line_buffer += text
        while "\n" in self._raw_line_buffer:
            line, self._raw_line_buffer = self._raw_line_buffer.split("\n", 1)
            line = line.rstrip("\r")
            if not line:
                continue
            # Raw line buffering stays separate from JSON extraction, but we do
            # not want repeated broken transport fragments to drown the log.
            # Noise and malformed balanced chunks are logged by the stream
            # extractor below with explicit recovery labels.
            if "{" in line:
                self._log_serial("RX", line)
                if self.current_step is not None:
                    self.current_step.raw_lines.append(line)
        if len(self._raw_line_buffer) > RAW_LINE_BUFFER_LIMIT:
            fragment = summarize_fragment(self._raw_line_buffer)
            self._log_serial("RX_PARTIAL_FLUSH", fragment)
            if self.current_step is not None:
                self.current_step.raw_lines.append(f"<partial_flush>{fragment}")
            self._raw_line_buffer = ""
            self.partial_buffer_flush_count += 1

    def _consume_json_stream(
        self, raw_chunk: bytes, received_ts: float
    ) -> list[dict[str, Any]]:
        parsed_items: list[dict[str, Any]] = []
        objects, fragments, stats = self._extractor.feed(raw_chunk)
        self.parser_buffer_peak_bytes = max(
            self.parser_buffer_peak_bytes,
            int(stats.get("parser_buffer_peak_bytes", 0)),
        )
        self.concatenated_json_count += int(stats.get("concatenated_json_count", 0))
        self.partial_buffer_flush_count += int(stats.get("partial_buffer_flush_count", 0))

        for fragment in fragments:
            kind = str(fragment.get("kind", "unknown"))
            summary = str(fragment.get("summary", ""))
            fragment_bytes = int(fragment.get("bytes_len", len(fragment.get("text", ""))))

            if kind == "true_noise_fragment":
                self.skipped_noise_count += 1
                self.noise_bytes_total += fragment_bytes
                if summary == self._pending_noise_summary:
                    self._pending_noise_count += 1
                    self._pending_noise_bytes += fragment_bytes
                else:
                    self._flush_pending_noise_log()
                    self._pending_noise_summary = summary
                    self._pending_noise_count = 1
                    self._pending_noise_bytes = fragment_bytes
            else:
                self._flush_pending_noise_log()
                if kind == "partial_json_fragment":
                    self.partial_json_count += 1
                elif kind == "concatenated_json_fragment":
                    if summary:
                        self._log_serial("CONCAT", summary)
                else:
                    self.malformed_fragment_count += 1
                    self.malformed_resync_count += 1
                    self._awaiting_malformed_recovery = True
                    self._last_malformed_skipped_bytes = fragment_bytes
                    if summary:
                        self._log_serial(
                            "MALFORMED",
                            f"skipped_bytes={fragment_bytes} sample={summary}",
                        )

            self._raw_fragment_queue.append(
                {
                    "ts": now_iso(),
                    "kind": kind,
                    "summary": summary,
                }
            )
            parsed_items.append({"parser_event": kind, "summary": summary})

        for obj in objects:
            self.recovered_json_count += 1
            object_text = compact_json(obj)
            self.json_bytes_total += len(object_text.encode("utf-8"))
            self._parsed_object_seq += 1
            extracted = ExtractedObjectRecord(
                seq=self._parsed_object_seq,
                ts=now_iso(),
                obj=obj,
            )
            with self._condition:
                self._parsed_object_queue.append(extracted)
                self.parser_queue_peak_len = max(
                    self.parser_queue_peak_len, len(self._parsed_object_queue)
                )
                if self._active_request and self._active_request.first_json_extracted_ts is None:
                    self._active_request.first_json_extracted_ts = received_ts
                self._condition.notify_all()
            self._flush_pending_noise_log()
            self._log_serial("JSON", object_text)
            if self._awaiting_malformed_recovery:
                event_name = str(obj.get("event", obj.get("type", "json_object")))
                self.recovered_after_malformed_count += 1
                self._log_human(
                    "INFO",
                    (
                        "malformed blob recovered: "
                        f"skipped_bytes={self._last_malformed_skipped_bytes} "
                        f"recovered_event={event_name}"
                    ),
                )
                self._awaiting_malformed_recovery = False
                self._last_malformed_skipped_bytes = 0
            parsed_items.extend(self._parse_event_object(obj, received_ts))

        return parsed_items

    def _parse_event_object(self, obj: dict[str, Any], dispatched_ts: float) -> list[dict[str, Any]]:
        parsed_items: list[dict[str, Any]] = []
        if obj.get("type") != "mdb_event":
            parsed_items.append(obj)
            return parsed_items

        event_name = str(obj.get("event", ""))
        details = obj.get("details", {})
        if not isinstance(details, dict):
            details = {"value": details}
        with self._condition:
            self.state.update_from_event(event_name, details)
            evt = EventRecord(
                seq=self.state.event_seq,
                ts=now_iso(),
                event=event_name,
                details=details,
            )
            self._event_queue.append(evt)
            self.event_queue_peak_len = max(self.event_queue_peak_len, len(self._event_queue))
            if self.current_step is not None:
                self.current_step.parsed_events.append(
                    {"event": event_name, "details": details, "seq": evt.seq}
                )
            if self._active_request and self._active_request.event_dispatched_ts is None:
                self._active_request.event_dispatched_ts = dispatched_ts
            if (
                self._active_request
                and event_name == "probe"
                and self._active_request.first_probe_event_ts is None
            ):
                self._active_request.first_probe_event_ts = dispatched_ts
            self._condition.notify_all()
        if event_name == "probe":
            self.probe_response_count += 1
        parsed_items.append({"event": event_name, "details": details, "seq": evt.seq})
        return parsed_items

    def wait_for(
        self,
        predicate: Callable[[TestState], bool],
        timeout_s: float,
        description: str,
        on_poll: Optional[Callable[[], None]] = None,
        poll_interval_s: float = INIT_PROBE_INTERVAL_S,
    ) -> None:
        deadline = time.monotonic() + timeout_s
        next_poll = time.monotonic() + poll_interval_s
        while True:
            self._raise_reader_exception_if_needed()
            with self._condition:
                if predicate(self.state):
                    return
                now = time.monotonic()
                if now >= deadline:
                    break
                wait_timeout = deadline - now
                if on_poll is not None:
                    wait_timeout = min(wait_timeout, max(0.0, next_poll - now))
                self._condition.wait(timeout=max(0.0, wait_timeout))
            now = time.monotonic()
            if on_poll is not None and now >= next_poll:
                on_poll()
                next_poll = now + poll_interval_s
        raise StepFailure(f"timeout_waiting_for_{description}")

    def wait_for_event(
        self,
        event_name: str,
        timeout_s: float,
        predicate: Optional[Callable[[dict[str, Any]], bool]] = None,
        min_seq: int = 0,
    ) -> EventRecord:
        deadline = time.monotonic() + timeout_s
        while True:
            self._raise_reader_exception_if_needed()
            with self._condition:
                for evt in reversed(self._event_queue):
                    if evt.seq <= min_seq:
                        break
                    if evt.event != event_name:
                        continue
                    if predicate is not None and not predicate(evt.details):
                        continue
                    return evt
                now = time.monotonic()
                if now >= deadline:
                    break
                self._condition.wait(timeout=deadline - now)
        raise StepFailure(f"timeout_waiting_for_event_{event_name}")

    def _events_after_seq(self, min_seq: int) -> list[EventRecord]:
        with self._condition:
            return [evt for evt in self._event_queue if evt.seq > min_seq]

    def _protocol_evidence_after_seq(self, min_seq: int) -> dict[str, Any]:
        events = self._events_after_seq(min_seq)
        explicit_probe = next((evt for evt in events if evt.event in EXPLICIT_SNAPSHOT_EVENTS), None)
        alt_snapshot = next(
            (evt for evt in events if evt.event in ALTERNATIVE_SNAPSHOT_EVENTS),
            None,
        )
        protocol_events = [evt for evt in events if evt.event in PROTOCOL_ALIVE_EVENTS]
        return {
            "explicit_probe": explicit_probe,
            "alt_snapshot": alt_snapshot,
            "protocol_events": protocol_events,
            "events_seen": sorted({evt.event for evt in events}),
        }

    def _build_synthetic_probe_summary(
        self,
        min_seq: int,
        probe_supported: str,
        reason: str,
    ) -> dict[str, Any]:
        evidence = self._protocol_evidence_after_seq(min_seq)
        state_summary = self.state.summary()
        health = self.state.baseline_health(probe_supported=probe_supported)
        synthetic = {
            **state_summary,
            **health,
            "synthetic": True,
            "synthetic_reason": reason,
            "command_probe_supported": probe_supported,
            "device_protocol_alive": health["protocol_alive"],
            "synthetic_state_summary": state_summary,
            "events_seen": evidence["events_seen"],
        }
        if evidence["alt_snapshot"] is not None:
            synthetic["status_like_event"] = {
                "event": evidence["alt_snapshot"].event,
                "details": ensure_dict_copy(evidence["alt_snapshot"].details),
            }
        if evidence["protocol_events"]:
            synthetic["protocol_event_samples"] = [
                {
                    "event": evt.event,
                    "details": ensure_dict_copy(evt.details),
                    "seq": evt.seq,
                }
                for evt in evidence["protocol_events"][-5:]
            ]
        return synthetic

    def send_and_wait_for_event(
        self,
        command: str,
        payload: Optional[dict[str, Any]],
        expected_events: set[str],
        timeout_s: float,
        retry_interval_s: float | None = None,
        max_attempts: int | None = None,
    ) -> EventRecord:
        started = time.monotonic()
        with self._condition:
            baseline_seq = self.state.event_seq
            self._active_request = ActiveCommandMetrics(
                command=command,
                expected_events=set(expected_events),
                send_ts=started,
            )

        self.send_command(command, payload)
        attempts = 1
        deadline = started + timeout_s
        next_retry = started + retry_interval_s if retry_interval_s is not None else None

        matched: EventRecord | None = None
        while True:
            self._raise_reader_exception_if_needed()
            with self._condition:
                for evt in reversed(self._event_queue):
                    if evt.seq <= baseline_seq:
                        break
                    if evt.event in expected_events:
                        matched = evt
                        break
                if matched is not None:
                    active = self._active_request
                    if active is not None:
                        active.event_dispatched_ts = time.monotonic()
                        active.wait_completed_ts = active.event_dispatched_ts
                    break

                now = time.monotonic()
                if now >= deadline:
                    break

                wait_timeout = deadline - now
                if next_retry is not None:
                    wait_timeout = min(wait_timeout, max(0.0, next_retry - now))
                self._condition.wait(timeout=max(0.0, wait_timeout))

            now = time.monotonic()
            if next_retry is not None and now >= next_retry:
                if max_attempts is not None and attempts >= max_attempts:
                    next_retry = None
                    continue
                self.retry_count += 1
                self.send_command(command, payload)
                attempts += 1
                with self._condition:
                    if self._active_request is not None:
                        self._active_request.attempt_count = attempts
                next_retry = now + retry_interval_s

        if matched is None:
            elapsed = time.monotonic() - started
            if command == "mdb_probe":
                self.probe_timeout_count += 1
            with self._condition:
                active = self._active_request
                self.last_request_metrics = {
                    "command": command,
                    "expected_events": sorted(expected_events),
                    "command_send_ts": started,
                    "first_byte_rx_ts": active.first_byte_rx_ts if active else None,
                    "first_complete_json_ts": active.first_json_extracted_ts if active else None,
                    "first_json_extracted_ts": active.first_json_extracted_ts if active else None,
                    "first_probe_event_ts": active.first_probe_event_ts if active else None,
                    "event_dispatched_ts": active.event_dispatched_ts if active else None,
                    "dispatch_ts": active.event_dispatched_ts if active else None,
                    "wait_return_ts": time.monotonic(),
                    "wait_completed_ts": time.monotonic(),
                    "attempt_count": attempts,
                    "probe_roundtrip_ms": round(elapsed * 1000.0, 3),
                    "parse_latency_ms": (
                        round(
                            (active.first_json_extracted_ts - active.first_byte_rx_ts) * 1000.0,
                            3,
                        )
                        if active
                        and active.first_byte_rx_ts is not None
                        and active.first_json_extracted_ts is not None
                        else None
                    ),
                    "dispatch_latency_ms": (
                        round(
                            (active.event_dispatched_ts - active.first_json_extracted_ts) * 1000.0,
                            3,
                        )
                        if active
                        and active.first_json_extracted_ts is not None
                        and active.event_dispatched_ts is not None
                        else None
                    ),
                    "baseline_probe_total_ms": (
                        round(elapsed * 1000.0, 3) if command == "mdb_probe" else None
                    ),
                }
            self._log_human(
                "WARN",
                (
                    f"{command} timed out after {elapsed:.3f}s waiting for "
                    f"{sorted(expected_events)}; parser_recovery="
                    f"{compact_json(self.parser_stats())}"
                ),
            )
            with self._condition:
                self._active_request = None
            raise StepFailure(f"timeout_waiting_for_events_{'_'.join(sorted(expected_events))}")

        elapsed = time.monotonic() - started
        with self._condition:
            active = self._active_request
            if active is not None:
                parse_latency_ms = (
                    round(
                        (active.first_json_extracted_ts - active.first_byte_rx_ts) * 1000.0,
                        3,
                    )
                    if active.first_byte_rx_ts is not None
                    and active.first_json_extracted_ts is not None
                    else None
                )
                dispatch_latency_ms = (
                    round(
                        (active.event_dispatched_ts - active.first_json_extracted_ts) * 1000.0,
                        3,
                    )
                    if active.first_json_extracted_ts is not None
                    and active.event_dispatched_ts is not None
                    else None
                )
                self.last_request_metrics = {
                    "command": command,
                    "expected_events": sorted(expected_events),
                    "command_send_ts": started,
                    "first_byte_rx_ts": active.first_byte_rx_ts,
                    "first_complete_json_ts": active.first_json_extracted_ts,
                    "first_json_extracted_ts": active.first_json_extracted_ts,
                    "first_probe_event_ts": active.first_probe_event_ts,
                    "event_dispatched_ts": active.event_dispatched_ts,
                    "dispatch_ts": active.event_dispatched_ts,
                    "wait_return_ts": active.wait_completed_ts,
                    "wait_completed_ts": active.wait_completed_ts,
                    "attempt_count": attempts,
                    "probe_roundtrip_ms": round(elapsed * 1000.0, 3),
                    "parse_latency_ms": parse_latency_ms,
                    "dispatch_latency_ms": dispatch_latency_ms,
                    "baseline_probe_total_ms": (
                        round(elapsed * 1000.0, 3) if command == "mdb_probe" else None
                    ),
                }
                if command == "mdb_probe":
                    self._probe_roundtrip_samples_ms.append(elapsed * 1000.0)
                    if parse_latency_ms is not None:
                        self._parse_latency_samples_ms.append(parse_latency_ms)
                    if dispatch_latency_ms is not None:
                        self._dispatch_latency_samples_ms.append(dispatch_latency_ms)
                self._active_request = None
        self._log_human(
            "INFO",
            f"{command} received {matched.event} after {elapsed:.3f}s",
        )
        if command == "mdb_probe":
            roundtrip_ms = round(elapsed * 1000.0, 3)
            self._log_human("INFO", f"mdb_probe roundtrip_ms={roundtrip_ms}")
        return matched

    def request_probe(self) -> dict[str, Any]:
        command = "mdb_probe"
        started = time.monotonic()
        with self._condition:
            baseline_seq = self.state.event_seq
            self._active_request = ActiveCommandMetrics(
                command=command,
                expected_events={"probe"},
                send_ts=started,
            )

        self.send_command(command, {})
        attempts = 1
        deadline = started + PROBE_TIMEOUT_S
        next_retry = started + PROBE_RETRY_INTERVAL_S
        protocol_grace_deadline: float | None = None
        matched_probe: EventRecord | None = None
        evidence_seen = False
        tail_window_ms = 0.0
        protocol_evidence_after_timeout: list[str] = []
        last_protocol_event_after_timeout: dict[str, Any] | None = None

        while True:
            self._raise_reader_exception_if_needed()
            with self._condition:
                evidence = self._protocol_evidence_after_seq(baseline_seq)
                if evidence["explicit_probe"] is not None:
                    matched_probe = evidence["explicit_probe"]
                    active = self._active_request
                    if active is not None:
                        active.wait_completed_ts = time.monotonic()
                    break
                if evidence["alt_snapshot"] is not None or evidence["protocol_events"]:
                    evidence_seen = True
                    if protocol_grace_deadline is None:
                        protocol_grace_deadline = time.monotonic() + PROTOCOL_EVIDENCE_GRACE_S

                now = time.monotonic()
                if protocol_grace_deadline is not None and now >= protocol_grace_deadline:
                    break
                if now >= deadline:
                    break

                wait_timeout = deadline - now
                if next_retry is not None:
                    wait_timeout = min(wait_timeout, max(0.0, next_retry - now))
                if protocol_grace_deadline is not None:
                    wait_timeout = min(
                        wait_timeout,
                        max(0.0, protocol_grace_deadline - now),
                    )
                self._condition.wait(timeout=max(0.0, wait_timeout))

            now = time.monotonic()
            if next_retry is not None and now >= next_retry:
                if attempts >= 3:
                    next_retry = None
                    continue
                self.retry_count += 1
                self.send_command(command, {})
                attempts += 1
                with self._condition:
                    if self._active_request is not None:
                        self._active_request.attempt_count = attempts
                next_retry = now + PROBE_RETRY_INTERVAL_S

        elapsed = time.monotonic() - started
        with self._condition:
            active = self._active_request
            parse_latency_ms = (
                round(
                    (active.first_json_extracted_ts - active.first_byte_rx_ts) * 1000.0,
                    3,
                )
                if active
                and active.first_byte_rx_ts is not None
                and active.first_json_extracted_ts is not None
                else None
            )
            dispatch_latency_ms = (
                round(
                    (active.event_dispatched_ts - active.first_json_extracted_ts) * 1000.0,
                    3,
                )
                if active
                and active.first_json_extracted_ts is not None
                and active.event_dispatched_ts is not None
                else None
            )

        if matched_probe is not None:
            with self._condition:
                self.last_request_metrics = {
                    "command": command,
                    "expected_events": ["probe"],
                    "command_send_ts": started,
                    "first_rx_byte_ts": active.first_byte_rx_ts if active else None,
                    "first_byte_rx_ts": active.first_byte_rx_ts if active else None,
                    "first_complete_json_ts": active.first_json_extracted_ts if active else None,
                    "first_json_extracted_ts": active.first_json_extracted_ts if active else None,
                    "first_probe_event_ts": active.first_probe_event_ts if active else None,
                    "dispatch_ts": active.event_dispatched_ts if active else None,
                    "event_dispatched_ts": active.event_dispatched_ts if active else None,
                    "wait_return_ts": active.wait_completed_ts if active else time.monotonic(),
                    "wait_completed_ts": active.wait_completed_ts if active else time.monotonic(),
                    "attempt_count": attempts,
                    "probe_roundtrip_ms": round(elapsed * 1000.0, 3),
                    "parse_latency_ms": parse_latency_ms,
                    "dispatch_latency_ms": dispatch_latency_ms,
                    "baseline_probe_total_ms": round(elapsed * 1000.0, 3),
                    "probe_supported": True,
                    "protocol_alive": True,
                }
                self._active_request = None
            self._probe_roundtrip_samples_ms.append(elapsed * 1000.0)
            if parse_latency_ms is not None:
                self._parse_latency_samples_ms.append(parse_latency_ms)
            if dispatch_latency_ms is not None:
                self._dispatch_latency_samples_ms.append(dispatch_latency_ms)
            self._log_human("INFO", f"mdb_probe received probe after {elapsed:.3f}s")
            return matched_probe.details

        evidence = self._protocol_evidence_after_seq(baseline_seq)
        if evidence_seen or evidence["alt_snapshot"] is not None or evidence["protocol_events"]:
            synthetic = self._build_synthetic_probe_summary(
                baseline_seq,
                probe_supported="false",
                reason="no_probe_but_protocol_alive",
            )
            with self._condition:
                self.last_request_metrics = {
                    "command": command,
                    "expected_events": ["probe"],
                    "command_send_ts": started,
                    "first_rx_byte_ts": active.first_byte_rx_ts if active else None,
                    "first_byte_rx_ts": active.first_byte_rx_ts if active else None,
                    "first_complete_json_ts": active.first_json_extracted_ts if active else None,
                    "first_json_extracted_ts": active.first_json_extracted_ts if active else None,
                    "first_probe_event_ts": None,
                    "dispatch_ts": active.event_dispatched_ts if active else None,
                    "event_dispatched_ts": active.event_dispatched_ts if active else None,
                    "wait_return_ts": time.monotonic(),
                    "wait_completed_ts": time.monotonic(),
                    "attempt_count": attempts,
                    "probe_roundtrip_ms": round(elapsed * 1000.0, 3),
                    "parse_latency_ms": parse_latency_ms,
                    "dispatch_latency_ms": dispatch_latency_ms,
                    "baseline_probe_total_ms": round(elapsed * 1000.0, 3),
                    "probe_supported": False,
                    "protocol_alive": True,
                    "baseline_status": synthetic["baseline_status"],
                    "baseline_tail_window_ms": tail_window_ms,
                    "protocol_evidence_after_timeout": protocol_evidence_after_timeout,
                    "last_protocol_event_after_timeout": last_protocol_event_after_timeout,
                }
                self._active_request = None
            self._log_human(
                "WARN",
                "baseline degraded: protocol alive, explicit probe missing",
            )
            return synthetic

        tail_started = time.monotonic()
        tail_deadline = tail_started + BASELINE_TAIL_WINDOW_S
        while True:
            self._raise_reader_exception_if_needed()
            evidence = self._protocol_evidence_after_seq(baseline_seq)
            if evidence["alt_snapshot"] is not None or evidence["protocol_events"]:
                protocol_evidence_after_timeout = evidence["events_seen"]
                if evidence["protocol_events"]:
                    last_evt = evidence["protocol_events"][-1]
                    last_protocol_event_after_timeout = {
                        "event": last_evt.event,
                        "details": ensure_dict_copy(last_evt.details),
                        "seq": last_evt.seq,
                    }
                elif evidence["alt_snapshot"] is not None:
                    last_evt = evidence["alt_snapshot"]
                    last_protocol_event_after_timeout = {
                        "event": last_evt.event,
                        "details": ensure_dict_copy(last_evt.details),
                        "seq": last_evt.seq,
                    }
                break
            now = time.monotonic()
            if now >= tail_deadline:
                break
            with self._condition:
                self._condition.wait(timeout=max(0.0, tail_deadline - now))

        tail_window_ms = round((time.monotonic() - tail_started) * 1000.0, 3)
        evidence = self._protocol_evidence_after_seq(baseline_seq)
        if protocol_evidence_after_timeout or evidence["alt_snapshot"] is not None or evidence["protocol_events"]:
            synthetic = self._build_synthetic_probe_summary(
                baseline_seq,
                probe_supported="false",
                reason="late_protocol_evidence_after_probe_timeout",
            )
            with self._condition:
                self.last_request_metrics = {
                    "command": command,
                    "expected_events": ["probe"],
                    "command_send_ts": started,
                    "first_rx_byte_ts": active.first_byte_rx_ts if active else None,
                    "first_byte_rx_ts": active.first_byte_rx_ts if active else None,
                    "first_complete_json_ts": active.first_json_extracted_ts if active else None,
                    "first_json_extracted_ts": active.first_json_extracted_ts if active else None,
                    "first_probe_event_ts": None,
                    "dispatch_ts": active.event_dispatched_ts if active else None,
                    "event_dispatched_ts": active.event_dispatched_ts if active else None,
                    "wait_return_ts": time.monotonic(),
                    "wait_completed_ts": time.monotonic(),
                    "attempt_count": attempts,
                    "probe_roundtrip_ms": round(elapsed * 1000.0, 3),
                    "parse_latency_ms": parse_latency_ms,
                    "dispatch_latency_ms": dispatch_latency_ms,
                    "baseline_probe_total_ms": round(elapsed * 1000.0, 3),
                    "baseline_tail_window_ms": tail_window_ms,
                    "protocol_evidence_after_timeout": evidence["events_seen"],
                    "last_protocol_event_after_timeout": last_protocol_event_after_timeout,
                    "probe_supported": False,
                    "protocol_alive": True,
                    "baseline_status": synthetic["baseline_status"],
                }
                self._active_request = None
            self._log_human(
                "WARN",
                "baseline degraded: late protocol evidence arrived after explicit probe timeout",
            )
            return synthetic

        if self.state.protocol_alive():
            synthetic = self._build_synthetic_probe_summary(
                baseline_seq,
                probe_supported="false",
                reason="no_probe_but_protocol_alive_cached_state",
            )
            with self._condition:
                self.last_request_metrics = {
                    "command": command,
                    "expected_events": ["probe"],
                    "command_send_ts": started,
                    "first_rx_byte_ts": active.first_byte_rx_ts if active else None,
                    "first_byte_rx_ts": active.first_byte_rx_ts if active else None,
                    "first_complete_json_ts": active.first_json_extracted_ts if active else None,
                    "first_json_extracted_ts": active.first_json_extracted_ts if active else None,
                    "first_probe_event_ts": None,
                    "dispatch_ts": active.event_dispatched_ts if active else None,
                    "event_dispatched_ts": active.event_dispatched_ts if active else None,
                    "wait_return_ts": time.monotonic(),
                    "wait_completed_ts": time.monotonic(),
                    "attempt_count": attempts,
                    "probe_roundtrip_ms": round(elapsed * 1000.0, 3),
                    "parse_latency_ms": parse_latency_ms,
                    "dispatch_latency_ms": dispatch_latency_ms,
                    "baseline_probe_total_ms": round(elapsed * 1000.0, 3),
                    "probe_supported": False,
                    "protocol_alive": True,
                    "baseline_status": synthetic["baseline_status"],
                    "baseline_tail_window_ms": tail_window_ms,
                    "protocol_evidence_after_timeout": protocol_evidence_after_timeout,
                    "last_protocol_event_after_timeout": last_protocol_event_after_timeout,
                }
                self._active_request = None
            self._log_human(
                "WARN",
                "baseline degraded: using cached protocol-alive state without explicit probe",
            )
            return synthetic

        seen_after_seq = evidence["events_seen"]
        if seen_after_seq and set(seen_after_seq).issubset(CONFIG_ONLY_EVENTS):
            synthetic = self._build_synthetic_probe_summary(
                baseline_seq,
                probe_supported="unknown",
                reason="config_only_without_protocol_progress",
            )
            with self._condition:
                self.last_request_metrics = {
                    "command": command,
                    "expected_events": ["probe"],
                    "command_send_ts": started,
                    "first_rx_byte_ts": active.first_byte_rx_ts if active else None,
                    "first_byte_rx_ts": active.first_byte_rx_ts if active else None,
                    "first_complete_json_ts": active.first_json_extracted_ts if active else None,
                    "first_json_extracted_ts": active.first_json_extracted_ts if active else None,
                    "first_probe_event_ts": None,
                    "dispatch_ts": active.event_dispatched_ts if active else None,
                    "event_dispatched_ts": active.event_dispatched_ts if active else None,
                    "wait_return_ts": time.monotonic(),
                    "wait_completed_ts": time.monotonic(),
                    "attempt_count": attempts,
                    "probe_roundtrip_ms": round(elapsed * 1000.0, 3),
                    "parse_latency_ms": parse_latency_ms,
                    "dispatch_latency_ms": dispatch_latency_ms,
                    "baseline_probe_total_ms": round(elapsed * 1000.0, 3),
                    "baseline_tail_window_ms": tail_window_ms,
                    "protocol_evidence_after_timeout": protocol_evidence_after_timeout,
                    "last_protocol_event_after_timeout": last_protocol_event_after_timeout,
                    "probe_supported": "unknown",
                    "protocol_alive": False,
                    "baseline_status": synthetic["baseline_status"],
                }
                self._active_request = None
            self._log_human(
                "WARN",
                "baseline weak: only config acknowledgements observed, no MDB protocol progression yet",
            )
            return synthetic

        self.probe_timeout_count += 1
        with self._condition:
            self.last_request_metrics = {
                "command": command,
                "expected_events": ["probe"],
                "command_send_ts": started,
                "first_rx_byte_ts": active.first_byte_rx_ts if active else None,
                "first_byte_rx_ts": active.first_byte_rx_ts if active else None,
                "first_complete_json_ts": active.first_json_extracted_ts if active else None,
                "first_json_extracted_ts": active.first_json_extracted_ts if active else None,
                "first_probe_event_ts": None,
                "dispatch_ts": active.event_dispatched_ts if active else None,
                "event_dispatched_ts": active.event_dispatched_ts if active else None,
                "wait_return_ts": time.monotonic(),
                "wait_completed_ts": time.monotonic(),
                "attempt_count": attempts,
                "probe_roundtrip_ms": round(elapsed * 1000.0, 3),
                "parse_latency_ms": parse_latency_ms,
                "dispatch_latency_ms": dispatch_latency_ms,
                "baseline_probe_total_ms": round(elapsed * 1000.0, 3),
                "baseline_tail_window_ms": tail_window_ms,
                "protocol_evidence_after_timeout": protocol_evidence_after_timeout,
                "last_protocol_event_after_timeout": last_protocol_event_after_timeout,
                "probe_supported": "unknown",
                "protocol_alive": False,
            }
            self._active_request = None
        self._log_human(
            "WARN",
            (
                f"{command} timed out after {elapsed:.3f}s with no explicit probe and "
                f"no sufficient protocol evidence; parser_recovery={compact_json(self.parser_stats())}"
            ),
        )
        raise StepFailure("timeout_waiting_for_events_probe")

    def request_decoder_status(self) -> dict[str, Any]:
        event = self.send_and_wait_for_event(
            "phy_decoder_status",
            {},
            {"phy_decoder_status"},
            DECODER_TIMEOUT_S,
            retry_interval_s=DECODER_RETRY_INTERVAL_S,
            max_attempts=2,
        )
        return event.details


def build_paths(out_dir: Path) -> tuple[Path, Path]:
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    base = out_dir / f"mdb_tx_line_test_{timestamp}"
    return base.with_suffix(".log"), base.with_suffix(".json")


def ensure_dict_copy(value: Any) -> dict[str, Any]:
    if isinstance(value, dict):
        return json.loads(json.dumps(value))
    return {"value": value}


def collect_step_snapshot(client: SerialCommandClient) -> dict[str, Any]:
    snapshot = client.state.summary()
    snapshot["baseline_health"] = client.state.baseline_health(
        probe_supported="true" if client.state.explicit_probe_seen else "unknown"
    )
    snapshot["parser_recovery"] = client.parser_stats()
    snapshot["request_latency"] = client.request_metrics()
    return snapshot


def write_report(path: Path, report: dict[str, Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as handle:
        json.dump(report, handle, ensure_ascii=False, indent=2)
        handle.write("\n")


def run_test(args: argparse.Namespace, log_path: Path, json_path: Path) -> dict[str, Any]:
    report: dict[str, Any] = {
        "meta": {
            "test_name": "mdb_tx_line_test",
            "started_at": now_iso(),
            "port": args.port,
            "baud": args.baud,
            "serial_timeout_s": args.timeout,
            "credit_minor": args.credit,
            "out_dir": str(args.out_dir),
            "log_path": str(log_path),
            "json_path": str(json_path),
            "rx_invert_policy": "fixed_off",
            "credit_units_note": (
                "Amounts use firmware minor units. With scale factor 100, "
                "--credit 1 means 0.01 displayed currency units."
            ),
            "commands_used": [
                "mdb_probe",
                "phy_decoder_status",
                "mdb_passive_sniff_off",
                "mdb_rx_invert_off",
                "mdb_clear_session",
                "pay transport=mdb",
                "mdb_approve",
            ],
        },
        "steps": [],
        "result": {},
    }

    with SerialCommandClient(
        port=args.port,
        baud=args.baud,
        serial_timeout=args.timeout,
        log_path=log_path,
        verbose=args.verbose,
    ) as client:
        try:
            step = client.begin_step("serial_access")
            client.drain(0.5)
            report["steps"].append(
                asdict(client.end_step(step, "PASS", {"serial_open": True}))
            )

            step = client.begin_step("baseline_probe")
            client.send_command("mdb_rx_invert_off", {})
            client.send_command("mdb_passive_sniff_off", {})
            client.drain(0.25)
            rx_invert_event = {"rx_invert": client.state.rx_invert}
            passive_sniff_event = {"enabled": client.state.passive_sniff}
            client.clear_transport_backlog()
            baseline_probe_started = time.monotonic()
            probe = client.request_probe()
            baseline_probe_total_ms = round(
                (time.monotonic() - baseline_probe_started) * 1000.0, 3
            )
            baseline_status = str(probe.get("baseline_status", "BASELINE_OK_PROBE"))
            health_score = probe.get("health_score", 100 if probe.get("synthetic") is not True else 60)
            probe_supported = probe.get(
                "probe_supported",
                True if probe.get("synthetic") is not True else False,
            )
            protocol_alive = probe.get(
                "protocol_alive",
                True if probe.get("synthetic") is not True else bool(client.state.protocol_alive()),
            )
            decoder: dict[str, Any] | None = None
            decoder_error: str | None = None
            try:
                decoder = client.request_decoder_status()
            except Exception as exc:
                decoder_error = str(exc)
                client._log_human(
                    "WARN",
                    f"baseline_probe decoder status skipped: {decoder_error}",
                )
            parsed = {
                "rx_invert_event": ensure_dict_copy(rx_invert_event),
                "passive_sniff_event": ensure_dict_copy(passive_sniff_event),
                "probe": ensure_dict_copy(probe),
                "baseline_status": baseline_status,
                "health_score": health_score,
                "probe_supported": probe_supported,
                "protocol_alive": protocol_alive,
                "events_seen": json.loads(
                    json.dumps(probe.get("events_seen", client.state.recent_event_kinds()))
                ),
                "phy_decoder_status_present": bool(decoder),
                "phy_decoder_status_error": decoder_error,
                "baseline_probe_total_ms": baseline_probe_total_ms,
                "state_summary": collect_step_snapshot(client),
            }
            if baseline_status == "BASELINE_OK_PROTOCOL_ALIVE_NO_PROBE":
                client._log_human(
                    "WARN",
                    "baseline degraded: protocol alive, explicit probe missing",
                )
            if baseline_status in {"BASELINE_WEAK_CONFIG_ONLY", "BASELINE_FAIL_NO_PROTOCOL", "BASELINE_FAIL_PARSER_BROKEN"}:
                step.parsed_result.update(parsed)
                raise StepFailure(f"baseline_unhealthy:{baseline_status}")
            if probe.get("rx_invert") is True:
                raise StepFailure("rx_invert_is_not_false")
            if not isinstance(probe.get("response_path_state"), str):
                raise StepFailure("response_path_state_missing")
            report["steps"].append(asdict(client.end_step(step, "PASS", parsed)))

            step = client.begin_step("clear_session")
            client.send_command("mdb_clear_session", {})
            client.drain(1.0)
            probe = client.request_probe()
            report["steps"].append(
                asdict(
                    client.end_step(
                        step,
                        "PASS",
                        {
                            "clear_session_sent": True,
                            "state_summary": collect_step_snapshot(client),
                            "probe": ensure_dict_copy(probe),
                        },
                    )
                )
            )

            step = client.begin_step("wait_init_phase")

            def init_ready(state: TestState) -> bool:
                return state.initialization_ready()

            def poll_probe() -> None:
                client.send_command("mdb_probe", {})

            client.wait_for(
                init_ready,
                INIT_TIMEOUT_S,
                "initialization_phase",
                on_poll=poll_probe,
                poll_interval_s=INIT_PROBE_INTERVAL_S,
            )
            final_init_probe = client.request_probe()
            init_parsed = {
                "initialization_passed": True,
                "state_summary": collect_step_snapshot(client),
                "probe": ensure_dict_copy(final_init_probe),
            }
            report["steps"].append(asdict(client.end_step(step, "PASS", init_parsed)))

            txid = f"txline-{uuid.uuid4().hex[:12]}"

            step = client.begin_step("record_payment")
            pay_event = client.send_and_wait_for_event(
                "pay",
                {
                    "amount": int(args.credit),
                    "transport": "mdb",
                    "transaction_id": txid,
                },
                {"payment_received", "payment_rejected", "payment_ignored"},
                PAYMENT_TIMEOUT_S,
            )
            if pay_event.event != "payment_received":
                raise StepFailure(f"payment_recording_failed:{pay_event.event}")
            report["steps"].append(
                asdict(
                    client.end_step(
                        step,
                        "PASS",
                        {
                            "transaction_id": txid,
                            "event": pay_event.event,
                            "details": ensure_dict_copy(pay_event.details),
                            "state_summary": collect_step_snapshot(client),
                        },
                    )
                )
            )

            step = client.begin_step("approve_credit")
            approve_event = client.send_and_wait_for_event(
                "mdb_approve",
                {
                    "amount": int(args.credit),
                    "transaction_id": txid,
                },
                {"credit_approved", "approve_rejected"},
                APPROVE_TIMEOUT_S,
            )
            if approve_event.event != "credit_approved":
                raise StepFailure(f"credit_approval_failed:{approve_event.event}")
            client.wait_for(
                lambda state: state.begin_session_armed,
                2.0,
                "begin_session_armed",
            )
            report["steps"].append(
                asdict(
                    client.end_step(
                        step,
                        "PASS",
                        {
                            "transaction_id": txid,
                            "event": approve_event.event,
                            "details": ensure_dict_copy(approve_event.details),
                            "state_summary": collect_step_snapshot(client),
                        },
                    )
                )
            )

            step = client.begin_step("wait_begin_session_tx")
            client.wait_for(
                lambda state: state.begin_session_sent or state.begin_session_bus_tx,
                BEGIN_SESSION_TX_TIMEOUT_S,
                "begin_session_bus_tx",
                on_poll=lambda: client.send_command("mdb_probe", {}),
                poll_interval_s=INIT_PROBE_INTERVAL_S,
            )
            report["steps"].append(
                asdict(
                    client.end_step(
                        step,
                        "PASS",
                        {
                            "credit_sent": True,
                            "state_summary": collect_step_snapshot(client),
                        },
                    )
                )
            )

            step = client.begin_step("wait_credit_ack")
            try:
                client.wait_for(
                    lambda state: state.begin_session_ack_received
                    or state.begin_session_ack_missing,
                    BEGIN_SESSION_ACK_TIMEOUT_S,
                    "begin_session_ack_or_timeout",
                    on_poll=lambda: client.send_command("mdb_probe", {}),
                    poll_interval_s=2.0,
                )
            except StepFailure:
                # One last probe for explicit begin_session_* telemetry before failing.
                client.request_probe()
                if not (
                    client.state.begin_session_ack_received
                    or client.state.begin_session_ack_missing
                ):
                    raise
            accepted = client.state.begin_session_ack_received
            step_status = "PASS" if accepted else "FAIL"
            report["steps"].append(
                asdict(
                    client.end_step(
                        step,
                        step_status,
                        {
                            "machine_acceptance_status": client.state.machine_acceptance_status(),
                            "state_summary": collect_step_snapshot(client),
                        },
                    )
                )
            )
            if not accepted:
                raise StepFailure("machine_did_not_ack_begin_session")

            step = client.begin_step("final_probe")
            final_probe = client.request_probe()
            final_decoder = client.request_decoder_status()
            report["steps"].append(
                asdict(
                    client.end_step(
                        step,
                        "PASS",
                        {
                            "probe": ensure_dict_copy(final_probe),
                            "phy_decoder_status_present": bool(final_decoder),
                            "state_summary": collect_step_snapshot(client),
                        },
                    )
                )
            )

            report["result"] = {
                "pass": True,
                "initialization_passed": client.state.initialization_ready(),
                "credit_1_sent": client.state.begin_session_sent
                or client.state.begin_session_bus_tx,
                "machine_accepted": client.state.begin_session_ack_received,
                "probe_supported": client.state.explicit_probe_seen,
                "protocol_alive": client.state.protocol_alive(),
                "failure_step": None,
                "failure_reason": None,
                "state_summary": collect_step_snapshot(client),
            }
        except Exception as exc:
            if client.current_step is not None:
                report["steps"].append(
                    asdict(
                        client.end_step(
                            client.current_step,
                            "FAIL",
                            {
                                "state_summary": collect_step_snapshot(client),
                            },
                        )
                    )
                )
            failure_probe: dict[str, Any] | None = None
            try:
                failure_probe = ensure_dict_copy(client.request_probe())
            except Exception:
                pass
            report["result"] = {
                "pass": False,
                "initialization_passed": client.state.initialization_ready(),
                "credit_1_sent": client.state.begin_session_sent
                or client.state.begin_session_bus_tx,
                "machine_accepted": client.state.begin_session_ack_received,
                "probe_supported": client.state.explicit_probe_seen,
                "protocol_alive": client.state.protocol_alive(),
                "failure_step": report["steps"][-1]["name"] if report["steps"] else "unknown",
                "failure_reason": str(exc),
                "exception_traceback": traceback.format_exc(),
                "state_summary": collect_step_snapshot(client),
                "failure_probe": failure_probe,
            }

        report["meta"]["ended_at"] = now_iso()
        report["meta"]["log_path"] = str(log_path)
        report["meta"]["json_path"] = str(json_path)

    write_report(json_path, report)
    return report


def build_arg_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Test MDB TX line, initialization flow, and credit transmission."
    )
    parser.add_argument("--port", default=DEFAULT_PORT, help="Serial port path")
    parser.add_argument("--baud", type=int, default=DEFAULT_BAUD, help="Serial baud rate")
    parser.add_argument(
        "--timeout",
        type=float,
        default=DEFAULT_SERIAL_TIMEOUT_S,
        help="Serial read/write timeout in seconds",
    )
    parser.add_argument(
        "--out-dir",
        type=Path,
        default=DEFAULT_OUT_DIR,
        help="Directory for .log and .json outputs",
    )
    parser.add_argument(
        "--credit",
        type=int,
        default=DEFAULT_CREDIT_MINOR,
        help="Credit amount in firmware minor units",
    )
    parser.add_argument(
        "--verbose",
        action="store_true",
        help="Print serial RX/TX lines to stdout while running",
    )
    return parser


def main() -> int:
    args = build_arg_parser().parse_args()
    log_path, json_path = build_paths(args.out_dir)
    try:
        report = run_test(args, log_path, json_path)
    except Exception as exc:
        failure_report = {
            "meta": {
                "test_name": "mdb_tx_line_test",
                "started_at": now_iso(),
                "ended_at": now_iso(),
                "port": args.port,
                "baud": args.baud,
                "serial_timeout_s": args.timeout,
                "credit_minor": args.credit,
                "out_dir": str(args.out_dir),
                "log_path": str(log_path),
                "json_path": str(json_path),
                "rx_invert_policy": "fixed_off",
            },
            "steps": [],
            "result": {
                "pass": False,
                "initialization_passed": False,
                "credit_1_sent": False,
                "machine_accepted": False,
                "failure_step": "startup",
                "failure_reason": str(exc),
                "exception_traceback": traceback.format_exc(),
            },
        }
        log_path.parent.mkdir(parents=True, exist_ok=True)
        with log_path.open("a", encoding="utf-8") as handle:
            handle.write(f"[{now_iso()}] ERROR {exc}\n")
            handle.write(traceback.format_exc())
            handle.write("\n")
        write_report(json_path, failure_report)
        if isinstance(exc, SerialException):
            print(f"Serial open/IO failed: {exc}", file=sys.stderr)
            return 2
        print(f"Unexpected failure: {exc}", file=sys.stderr)
        return 3

    result = report.get("result", {})
    print(
        compact_json(
            {
                "pass": result.get("pass"),
                "initialization_passed": result.get("initialization_passed"),
                "credit_1_sent": result.get("credit_1_sent"),
                "machine_accepted": result.get("machine_accepted"),
                "failure_step": result.get("failure_step"),
                "failure_reason": result.get("failure_reason"),
                "log_path": report["meta"]["log_path"],
                "json_path": report["meta"]["json_path"],
            }
        )
    )
    return 0 if result.get("pass") else 1


if __name__ == "__main__":
    sys.exit(main())
