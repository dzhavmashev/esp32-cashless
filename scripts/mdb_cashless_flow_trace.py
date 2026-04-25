#!/usr/bin/env python3
"""Trace the MDB cashless flow and print it in a human-readable order.

This script is derived from the TX-line test approach used in the uploaded
MDB tester, but focuses on a different output: a normalized cashless flow that
shows, step by step, what the slave received from the VMC and what the slave
sent back.

It uses the same firmware command hooks that already exist in the tester:
  - mdb_rx_invert_off
  - mdb_passive_sniff_off
  - mdb_clear_session
  - mdb_probe
  - pay transport=mdb
  - mdb_approve

Outputs:
  1. .log  - human-readable serial/session log
  2. .json - structured report with raw events + normalized flow
  3. .txt  - concise step-by-step cashless flow
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

DEFAULT_PORT = "/dev/ttyUSB0"
DEFAULT_BAUD = 115200
DEFAULT_SERIAL_TIMEOUT_S = 0.20
DEFAULT_OUT_DIR = Path.cwd()
DEFAULT_CREDIT_MINOR = 100

PROBE_TIMEOUT_S = 8.0
PROBE_RETRY_INTERVAL_S = 0.75
DECODER_WAIT_S = 1.0
INIT_TIMEOUT_S = 60.0
INIT_PROBE_INTERVAL_S = 5.0
PAYMENT_TIMEOUT_S = 4.0
APPROVE_TIMEOUT_S = 4.0
BEGIN_SESSION_TX_TIMEOUT_S = 20.0
BEGIN_SESSION_ACK_TIMEOUT_S = 6.0
FINAL_DRAIN_S = 1.5
SETUP_SWEEP_INIT_TIMEOUT_S = 14.0

POPULAR_SETUP_SWEEP_CANDIDATES = [
    {"label": "kgs_r1_o00", "currency_code_hi": 0x14, "currency_code_lo": 0x17, "max_response_time": 0x01, "options": 0x00},
    {"label": "kgs_r0_o00", "currency_code_hi": 0x14, "currency_code_lo": 0x17, "max_response_time": 0x00, "options": 0x00},
    {"label": "kgs_r3_o00", "currency_code_hi": 0x14, "currency_code_lo": 0x17, "max_response_time": 0x03, "options": 0x00},
    {"label": "kgs_r1_o09", "currency_code_hi": 0x14, "currency_code_lo": 0x17, "max_response_time": 0x01, "options": 0x09},
    {"label": "kgs_r3_o09", "currency_code_hi": 0x14, "currency_code_lo": 0x17, "max_response_time": 0x03, "options": 0x09},
    {"label": "zero_r1_o00", "currency_code_hi": 0x00, "currency_code_lo": 0x00, "max_response_time": 0x01, "options": 0x00},
    {"label": "zero_r0_o00", "currency_code_hi": 0x00, "currency_code_lo": 0x00, "max_response_time": 0x00, "options": 0x00},
    {"label": "zero_r3_o09", "currency_code_hi": 0x00, "currency_code_lo": 0x00, "max_response_time": 0x03, "options": 0x09},
    {"label": "tel0996_r3_o09", "currency_code_hi": 0x09, "currency_code_lo": 0x96, "max_response_time": 0x03, "options": 0x09},
]

RAW_LINE_BUFFER_LIMIT = 32 * 1024
JSON_BUFFER_LIMIT = 256 * 1024
EVENT_QUEUE_LIMIT = 512
RECENT_EVENT_LIMIT = 512


def now_iso() -> str:
    return datetime.now().astimezone().isoformat(timespec="milliseconds")


def compact_json(value: Any) -> str:
    return json.dumps(value, ensure_ascii=False, separators=(",", ":"))


class StepFailure(RuntimeError):
    pass


class StreamJsonExtractor:
    """Extract complete top-level JSON objects from a noisy serial stream."""

    def __init__(self, buffer_limit: int = JSON_BUFFER_LIMIT) -> None:
        self.buffer_limit = buffer_limit
        self.buffer = bytearray()

    def feed(self, chunk: bytes) -> tuple[list[dict[str, Any]], list[str]]:
        if chunk:
            self.buffer.extend(chunk)
        objects: list[dict[str, Any]] = []
        notes: list[str] = []

        while self.buffer:
            start = self.buffer.find(b"{")
            if start < 0:
                self.buffer.clear()
                break
            if start > 0:
                del self.buffer[:start]

            end = self._find_balanced_end(self.buffer)
            if end is None:
                if len(self.buffer) > self.buffer_limit:
                    notes.append("partial_buffer_flush")
                    self.buffer.clear()
                break

            candidate = bytes(self.buffer[: end + 1])
            del self.buffer[: end + 1]
            try:
                parsed = json.loads(candidate.decode("utf-8", errors="replace"))
            except json.JSONDecodeError:
                notes.append("malformed_json")
                continue

            if isinstance(parsed, dict):
                objects.append(parsed)
            else:
                notes.append("non_object_json")

        return objects, notes

    @staticmethod
    def _find_balanced_end(buffer: bytearray) -> int | None:
        depth = 0
        in_string = False
        escape = False
        for i, byte in enumerate(buffer):
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
            elif ch == "{":
                depth += 1
            elif ch == "}":
                depth -= 1
                if depth == 0:
                    return i
        return None


@dataclass
class EventRecord:
    seq: int
    ts: str
    event: str
    details: dict[str, Any]


@dataclass
class FlowStep:
    order: int
    code: str
    side: str
    summary: str
    observed_at: str
    details: dict[str, Any] = field(default_factory=dict)


@dataclass
class FlowExchange:
    order: int
    code: str
    received_from_vmc: Optional[str] = None
    sent_to_vmc: Optional[str] = None
    local_action: Optional[str] = None
    status: str = "observed"
    evidence: list[dict[str, Any]] = field(default_factory=list)


@dataclass
class TestState:
    event_seq: int = 0
    explicit_probe_seen: bool = False

    saw_setup: bool = False
    saw_setup_response: bool = False
    saw_enable: bool = False
    saw_poll: bool = False
    reader_enabled: Optional[bool] = None

    payment_recorded: bool = False
    payment_rejected: bool = False
    credit_approved: bool = False
    approve_rejected: bool = False
    begin_session_armed: bool = False
    begin_session_sent: bool = False
    begin_session_bus_tx: bool = False
    begin_session_ack_received: bool = False
    begin_session_ack_missing: bool = False
    stray_ack_seen: bool = False

    last_probe: dict[str, Any] = field(default_factory=dict)
    last_probe_uptime_ms: Optional[int] = None
    reboot_detected: bool = False
    reboot_from_uptime_ms: Optional[int] = None
    reboot_to_uptime_ms: Optional[int] = None
    recent_events: deque[EventRecord] = field(default_factory=lambda: deque(maxlen=RECENT_EVENT_LIMIT))

    def initialization_ready(self) -> bool:
        return self.saw_setup_response and self.saw_enable and self.saw_poll

    def protocol_alive(self) -> bool:
        return (
            self.explicit_probe_seen
            or self.saw_setup
            or self.saw_setup_response
            or self.saw_enable
            or self.saw_poll
        )

    def machine_acceptance_status(self) -> str:
        if self.begin_session_ack_received:
            return "accepted"
        if self.begin_session_ack_missing:
            return "not_accepted"
        return "unknown"


class FlowCollector:
    """Collect a normalized cashless flow from raw firmware events."""

    ORDER_MAP = {
        "vmc_reset": 10,
        "slave_just_reset": 20,
        "vmc_setup": 30,
        "slave_reader_config": 40,
        "vmc_enable": 50,
        "vmc_poll": 60,
        "local_payment_received": 70,
        "local_credit_approved": 80,
        "local_begin_session_armed": 90,
        "slave_begin_session": 100,
        "vmc_begin_session_ack": 110,
        "vmc_begin_session_ack_missing": 111,
    }

    def __init__(self) -> None:
        self._steps_by_code: dict[str, FlowStep] = {}
        self._exchanges_by_code: dict[str, FlowExchange] = {}
        self._begin_session_observed = False

    def _mark_begin_session_observed(self) -> None:
        self._begin_session_observed = True

    def _can_attribute_ack_to_begin_session(self, details: dict[str, Any]) -> bool:
        if self._begin_session_observed:
            return True
        tx_ts = details.get("begin_session_tx_ts_us")
        try:
            return int(tx_ts) > 0
        except (TypeError, ValueError):
            return False

    def add_step(self, code: str, side: str, summary: str, details: dict[str, Any]) -> None:
        if code in self._steps_by_code:
            return
        self._steps_by_code[code] = FlowStep(
            order=self.ORDER_MAP.get(code, 999),
            code=code,
            side=side,
            summary=summary,
            observed_at=now_iso(),
            details=self._safe_copy(details),
        )

    def add_exchange(
        self,
        code: str,
        *,
        received_from_vmc: str | None = None,
        sent_to_vmc: str | None = None,
        local_action: str | None = None,
        status: str = "observed",
        evidence: dict[str, Any] | None = None,
    ) -> None:
        exchange = self._exchanges_by_code.get(code)
        if exchange is None:
            exchange = FlowExchange(order=self.ORDER_MAP.get(code, 999), code=code)
            self._exchanges_by_code[code] = exchange
        if received_from_vmc and not exchange.received_from_vmc:
            exchange.received_from_vmc = received_from_vmc
        if sent_to_vmc and not exchange.sent_to_vmc:
            exchange.sent_to_vmc = sent_to_vmc
        if local_action and not exchange.local_action:
            exchange.local_action = local_action
        if status != "observed" or exchange.status == "observed":
            exchange.status = status
        if evidence is not None:
            exchange.evidence.append(self._safe_copy(evidence))

    def ingest_dialogue_item(self, item: dict[str, Any]) -> None:
        direction = str(item.get("direction", ""))
        kind = str(item.get("kind", "")).upper()
        if not kind:
            return

        if direction == "RX_FROM_MACHINE":
            if kind == "RESET":
                self.add_step("vmc_reset", "VMC -> SLAVE", "RESET", item)
                self.add_exchange("vmc_reset", received_from_vmc="RESET", evidence=item)
            elif kind == "SETUP":
                self.add_step("vmc_setup", "VMC -> SLAVE", "SETUP", item)
                self.add_exchange("vmc_setup", received_from_vmc="SETUP", evidence=item)
            elif kind == "ENABLE":
                self.add_step("vmc_enable", "VMC -> SLAVE", "ENABLE", item)
                self.add_exchange("vmc_enable", received_from_vmc="ENABLE", evidence=item)
            elif kind == "POLL":
                self.add_step("vmc_poll", "VMC -> SLAVE", "POLL", item)
                self.add_exchange("vmc_poll", received_from_vmc="POLL", evidence=item)
            elif kind == "ACK":
                if self._can_attribute_ack_to_begin_session(item):
                    self.add_step("vmc_begin_session_ack", "VMC -> SLAVE", "ACK", item)
                    self.add_exchange(
                        "vmc_begin_session_ack",
                        received_from_vmc="ACK after BEGIN SESSION",
                        status="accepted",
                        evidence=item,
                    )
        elif direction == "TX_TO_MACHINE":
            if kind in {"JUST_RESET", "JUST RESET"}:
                self.add_step("slave_just_reset", "SLAVE -> VMC", "JUST RESET", item)
                self.add_exchange("slave_just_reset", sent_to_vmc="JUST RESET", evidence=item)
            elif kind in {"READER_CONFIG", "READER CONFIG", "SETUP_RESPONSE"}:
                self.add_step("slave_reader_config", "SLAVE -> VMC", "READER CONFIG", item)
                self.add_exchange(
                    "vmc_setup",
                    sent_to_vmc="READER CONFIG / setup response",
                    evidence=item,
                )
            elif kind in {"BEGIN_SESSION", "BEGIN SESSION"}:
                self._mark_begin_session_observed()
                self.add_step("slave_begin_session", "SLAVE -> VMC", "BEGIN SESSION", item)
                self.add_exchange(
                    "slave_begin_session",
                    sent_to_vmc="BEGIN SESSION",
                    evidence=item,
                )

    def ingest_event(self, event_name: str, details: dict[str, Any]) -> None:
        if event_name == "payment_received":
            self.add_step("local_payment_received", "LOCAL", "payment_received", details)
            self.add_exchange(
                "local_payment_received",
                local_action="Payment recorded in firmware",
                evidence=details,
            )
        elif event_name == "credit_approved":
            self.add_step("local_credit_approved", "LOCAL", "credit_approved", details)
            self.add_exchange(
                "local_credit_approved",
                local_action="Credit approved",
                evidence=details,
            )
        elif event_name == "cashless_begin_session_armed":
            self.add_step("local_begin_session_armed", "LOCAL", "BEGIN SESSION armed", details)
            self.add_exchange(
                "local_begin_session_armed",
                local_action="BEGIN SESSION armed",
                evidence=details,
            )
        elif event_name in {"cashless_begin_session_sent", "cashless_begin_session_tx_state"}:
            self._mark_begin_session_observed()
            self.add_step("slave_begin_session", "SLAVE -> VMC", "BEGIN SESSION", details)
            self.add_exchange(
                "slave_begin_session",
                sent_to_vmc="BEGIN SESSION",
                evidence=details,
            )
        elif event_name == "mdb_bus_tx_raw":
            tx_kind = str(details.get("tx_kind", ""))
            if tx_kind == "begin_session":
                self._mark_begin_session_observed()
                self.add_step("slave_begin_session", "SLAVE -> VMC", "BEGIN SESSION", details)
                self.add_exchange(
                    "slave_begin_session",
                    sent_to_vmc="BEGIN SESSION",
                    evidence=details,
                )
        elif event_name == "cashless_begin_session_ack_received":
            if self._can_attribute_ack_to_begin_session(details):
                self.add_step("vmc_begin_session_ack", "VMC -> SLAVE", "ACK", details)
                self.add_exchange(
                    "vmc_begin_session_ack",
                    received_from_vmc="ACK after BEGIN SESSION",
                    status="accepted",
                    evidence=details,
                )
        elif event_name == "cashless_begin_session_ack_missing":
            if self._begin_session_observed:
                self.add_step("vmc_begin_session_ack_missing", "VMC -> SLAVE", "ACK missing / timeout", details)
                self.add_exchange(
                    "vmc_begin_session_ack_missing",
                    received_from_vmc="No ACK after BEGIN SESSION",
                    status="timeout",
                    evidence=details,
                )
        elif event_name == "cashless_setup_response":
            self.add_step("slave_reader_config", "SLAVE -> VMC", "READER CONFIG", details)
            self.add_exchange(
                "vmc_setup",
                sent_to_vmc="READER CONFIG / setup response",
                evidence=details,
            )
        elif event_name in {"enable_seen", "enable_accepted", "enable_state_applied"}:
            self.add_step("vmc_enable", "VMC -> SLAVE", "ENABLE", details)
            self.add_exchange("vmc_enable", received_from_vmc="ENABLE", evidence=details)
        elif event_name == "poll_rx_seen":
            self.add_step("vmc_poll", "VMC -> SLAVE", "POLL", details)
            self.add_exchange("vmc_poll", received_from_vmc="POLL", evidence=details)

    def steps(self) -> list[dict[str, Any]]:
        ordered = sorted(self._steps_by_code.values(), key=lambda x: (x.order, x.observed_at, x.code))
        return [asdict(x) for x in ordered]

    def exchanges(self) -> list[dict[str, Any]]:
        ordered = sorted(self._exchanges_by_code.values(), key=lambda x: (x.order, x.code))
        return [asdict(x) for x in ordered]

    def text_summary(self) -> str:
        lines = ["Cashless flow:", ""]
        for idx, item in enumerate(sorted(self._exchanges_by_code.values(), key=lambda x: (x.order, x.code)), start=1):
            lines.append(f"{idx}. {item.code}")
            if item.received_from_vmc:
                lines.append(f"   got:  {item.received_from_vmc}")
            if item.sent_to_vmc:
                lines.append(f"   sent: {item.sent_to_vmc}")
            if item.local_action:
                lines.append(f"   local: {item.local_action}")
            lines.append(f"   status: {item.status}")
            lines.append("")
        if len(lines) == 2:
            lines.append("No normalized cashless steps were observed.")
        return "\n".join(lines).rstrip() + "\n"

    @staticmethod
    def _safe_copy(value: Any) -> dict[str, Any]:
        if isinstance(value, dict):
            return json.loads(json.dumps(value))
        return {"value": value}


@dataclass
class StepRecord:
    name: str
    started_at: str
    status: str = "running"
    ended_at: str | None = None
    commands: list[dict[str, Any]] = field(default_factory=list)
    parsed_result: dict[str, Any] = field(default_factory=dict)

    def finish(self, status: str, parsed_result: Optional[dict[str, Any]] = None) -> None:
        self.status = status
        self.ended_at = now_iso()
        if parsed_result:
            self.parsed_result.update(parsed_result)


class SerialFlowClient:
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
        self._reader_thread: threading.Thread | None = None
        self._stop_reader = threading.Event()
        self._condition = threading.Condition()
        self._reader_exception: str | None = None

        self.state = TestState()
        self.flow = FlowCollector()
        self.current_step: StepRecord | None = None
        self.extractor = StreamJsonExtractor()
        self.raw_line_buffer = ""
        self.events: deque[EventRecord] = deque(maxlen=EVENT_QUEUE_LIMIT)

    def __enter__(self) -> "SerialFlowClient":
        self.log_path.parent.mkdir(parents=True, exist_ok=True)
        self.log_file = self.log_path.open("w", encoding="utf-8", buffering=8192)
        self._log("INFO", f"Opening {self.port} at {self.baud} baud")
        self.ser = serial.Serial(
            self.port,
            self.baud,
            timeout=min(self.serial_timeout, 0.02),
            write_timeout=self.serial_timeout,
        )
        self.ser.reset_input_buffer()
        self._stop_reader.clear()
        self._reader_thread = threading.Thread(target=self._reader_loop, daemon=True)
        self._reader_thread.start()
        time.sleep(0.10)
        self.drain(0.4)
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        try:
            self.drain(FINAL_DRAIN_S)
        except Exception:
            pass
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

    def _log(self, level: str, message: str) -> None:
        line = f"[{now_iso()}] {level} {message}"
        if self.verbose or level in {"WARN", "ERROR"}:
            print(line)
        if self.log_file is not None:
            self.log_file.write(line + "\n")

    def begin_step(self, name: str) -> StepRecord:
        step = StepRecord(name=name, started_at=now_iso())
        self.current_step = step
        self._log("STEP", f"BEGIN {name}")
        return step

    def end_step(self, step: StepRecord, status: str, parsed_result: Optional[dict[str, Any]] = None) -> StepRecord:
        step.finish(status, parsed_result)
        self._log("STEP", f"END {step.name}: {status}")
        self.current_step = None
        return step

    def send_command(self, command: str, payload: Optional[dict[str, Any]] = None) -> None:
        if self.ser is None:
            raise StepFailure("serial_port_not_open")
        envelope = {
            "type": "command",
            "payload": {"command": command, "payload": payload or {}},
        }
        text = compact_json(envelope)
        if self.current_step is not None:
            self.current_step.commands.append({"command": command, "payload": payload or {}})
        with self._condition:
            self.ser.write((text + "\n").encode("utf-8"))
            self.ser.flush()
        self._log("TX", text)

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
            self.extractor = StreamJsonExtractor()
            self.raw_line_buffer = ""
            self.events.clear()
            self._condition.notify_all()

    def _reader_loop(self) -> None:
        try:
            while not self._stop_reader.is_set():
                if self.ser is None:
                    return
                raw = self.ser.read(self.ser.in_waiting or 1)
                if not raw:
                    continue
                self._capture_raw_lines(raw.decode("utf-8", errors="replace"))
                objects, notes = self.extractor.feed(raw)
                for note in notes:
                    self._log("NOTE", note)
                for obj in objects:
                    self._handle_object(obj)
        except Exception:
            self._reader_exception = traceback.format_exc()
            self._log("ERROR", self._reader_exception.rstrip())
            with self._condition:
                self._condition.notify_all()

    def _capture_raw_lines(self, text: str) -> None:
        self.raw_line_buffer += text
        while "\n" in self.raw_line_buffer:
            line, self.raw_line_buffer = self.raw_line_buffer.split("\n", 1)
            line = line.rstrip("\r")
            if not line:
                continue
            if "{" in line:
                self._log("RX", line)
        if len(self.raw_line_buffer) > RAW_LINE_BUFFER_LIMIT:
            self.raw_line_buffer = ""

    def _handle_object(self, obj: dict[str, Any]) -> None:
        self._log("JSON", compact_json(obj))
        if obj.get("type") != "mdb_event":
            return
        event_name = str(obj.get("event", ""))
        details = obj.get("details", {})
        if not isinstance(details, dict):
            details = {"value": details}

        with self._condition:
            self.state.event_seq += 1
            evt = EventRecord(self.state.event_seq, now_iso(), event_name, details)
            self.events.append(evt)
            self.state.recent_events.append(evt)
            self._apply_event_to_state(event_name, details)
            self._condition.notify_all()

    def _apply_event_to_state(self, event_name: str, details: dict[str, Any]) -> None:
        self.flow.ingest_event(event_name, details)

        if event_name == "probe":
            self.state.explicit_probe_seen = True
            self.state.last_probe = details
            uptime_ms_value = details.get("uptime_ms")
            try:
                uptime_ms = int(uptime_ms_value)
            except (TypeError, ValueError):
                uptime_ms = None
            if uptime_ms is not None:
                last_uptime = self.state.last_probe_uptime_ms
                if last_uptime is not None and uptime_ms + 5000 < last_uptime:
                    self.state.reboot_detected = True
                    self.state.reboot_from_uptime_ms = last_uptime
                    self.state.reboot_to_uptime_ms = uptime_ms
                    self._log(
                        "WARN",
                        "reboot_detected_by_uptime_drop="
                        + compact_json({
                            "from_uptime_ms": last_uptime,
                            "to_uptime_ms": uptime_ms,
                        }),
                    )
                self.state.last_probe_uptime_ms = uptime_ms
            for item in details.get("dialogue_history", []):
                if isinstance(item, dict):
                    self._ingest_dialogue_item(item)
            self.state.saw_setup |= int(details.get("setup_rx_count", 0)) > 0
            self.state.saw_setup_response |= int(details.get("setup_tx_count", 0)) > 0
            self.state.saw_enable |= int(details.get("enable_applied_count", 0)) > 0 or bool(details.get("reader_enabled"))
            self.state.saw_poll |= int(details.get("poll_rx_count", 0)) > 0
            probe_begin_tx = int(details.get("begin_session_tx_count", 0)) > 0
            probe_begin_ack = int(details.get("begin_session_ack_count", 0)) > 0
            self.state.begin_session_sent |= probe_begin_tx
            if probe_begin_ack and (probe_begin_tx or self.state.begin_session_sent or self.state.begin_session_bus_tx):
                self.state.begin_session_ack_received = True
            elif probe_begin_ack:
                self.state.stray_ack_seen = True
            return

        if event_name == "dialogue_trace":
            self._ingest_dialogue_item(details)
            return

        if event_name in {"cashless_setup_response", "cashless_setup_response_timing"}:
            self.state.saw_setup_response = True
            return

        if event_name in {"enable_seen", "enable_accepted", "enable_state_applied"}:
            self.state.saw_enable = True
            if event_name == "enable_state_applied":
                self.state.reader_enabled = True
            return

        if event_name == "poll_rx_seen":
            self.state.saw_poll = True
            return

        if event_name == "payment_received":
            self.state.payment_recorded = True
            return
        if event_name == "payment_rejected":
            self.state.payment_rejected = True
            return
        if event_name == "credit_approved":
            self.state.credit_approved = True
            return
        if event_name == "approve_rejected":
            self.state.approve_rejected = True
            return
        if event_name == "cashless_begin_session_armed":
            self.state.begin_session_armed = True
            return
        if event_name in {"cashless_begin_session_sent", "cashless_begin_session_tx_state"}:
            self.state.begin_session_sent = True
            return
        if event_name == "mdb_bus_tx_raw":
            if str(details.get("tx_kind", "")) == "begin_session":
                self.state.begin_session_bus_tx = True
                self.state.begin_session_sent = True
            return
        if event_name == "cashless_begin_session_ack_received":
            tx_ts = details.get("begin_session_tx_ts_us")
            tx_seen = self.state.begin_session_sent or self.state.begin_session_bus_tx
            if tx_seen:
                self.state.begin_session_ack_received = True
            else:
                try:
                    self.state.begin_session_ack_received = int(tx_ts) > 0
                except (TypeError, ValueError):
                    self.state.stray_ack_seen = True
            return
        if event_name == "cashless_begin_session_ack_missing":
            if self.state.begin_session_sent or self.state.begin_session_bus_tx:
                self.state.begin_session_ack_missing = True
            return

    def _ingest_dialogue_item(self, item: dict[str, Any]) -> None:
        direction = str(item.get("direction", ""))
        kind = str(item.get("kind", "")).upper()
        self.flow.ingest_dialogue_item(item)
        if kind == "SETUP":
            self.state.saw_setup = True
        if direction == "TX_TO_MACHINE" and kind in {"READER_CONFIG", "READER CONFIG", "SETUP_RESPONSE"}:
            self.state.saw_setup_response = True
        if kind == "ENABLE":
            self.state.saw_enable = True
        if kind == "POLL":
            self.state.saw_poll = True

    def _raise_reader_exception_if_needed(self) -> None:
        if self._reader_exception:
            raise StepFailure(f"reader_thread_failed:{self._reader_exception.splitlines()[-1]}")

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
        names: str | set[str],
        predicate: Optional[Callable[[dict[str, Any]], bool]] = None,
        timeout_s: float = 3.0,
    ) -> EventRecord:
        wanted_names = {names} if isinstance(names, str) else set(names)
        baseline_seq = self.state.event_seq
        deadline = time.monotonic() + timeout_s
        while True:
            self._raise_reader_exception_if_needed()
            with self._condition:
                for evt in reversed(self.events):
                    if evt.seq <= baseline_seq:
                        break
                    if evt.event not in wanted_names:
                        continue
                    if predicate is None or predicate(evt.details):
                        return evt
                now = time.monotonic()
                if now >= deadline:
                    break
                self._condition.wait(timeout=max(0.0, min(0.10, deadline - now)))
        if len(wanted_names) == 1:
            raise StepFailure(f"timeout_waiting_for_event_{next(iter(wanted_names))}")
        raise StepFailure(f"timeout_waiting_for_events_{'_'.join(sorted(wanted_names))}")

    def wait_for_any_event(self, names: set[str], timeout_s: float) -> EventRecord:
        return self.wait_for_event(names, timeout_s=timeout_s)

    def request_probe(self) -> dict[str, Any]:
        attempts = 0
        deadline = time.monotonic() + PROBE_TIMEOUT_S
        baseline_seq = self.state.event_seq
        next_retry = time.monotonic()
        while time.monotonic() < deadline:
            if time.monotonic() >= next_retry:
                self.send_command("mdb_probe", {})
                attempts += 1
                next_retry = time.monotonic() + PROBE_RETRY_INTERVAL_S
            with self._condition:
                for evt in reversed(self.events):
                    if evt.seq <= baseline_seq:
                        break
                    if evt.event == "probe":
                        return evt.details
                self._condition.wait(timeout=0.10)
        raise StepFailure("timeout_waiting_for_probe")


def candidate_currency_hex(candidate: dict[str, Any]) -> str:
    return f"{int(candidate['currency_code_hi']) & 0xFF:02X} {int(candidate['currency_code_lo']) & 0xFF:02X}"


def probe_matches_clean_reset_state(probe: dict[str, Any]) -> bool:
    if not isinstance(probe, dict):
        return False
    reader_state = str(probe.get("last_reader_state") or probe.get("reader_state") or "")
    expected_next_rx_kind = str(probe.get("expected_next_rx_kind") or "")
    expected_next_tx_kind = str(probe.get("expected_next_tx_kind") or "")
    blocker = str(probe.get("protocol_progress_blocker") or "")
    return (
        reader_state == "UNINITIALIZED"
        and expected_next_rx_kind == "POLL"
        and expected_next_tx_kind == "just_reset_status"
        and blocker.startswith("waiting_for_poll_after_reset")
    )


def request_probe_checked(client: SerialFlowClient, timeout_s: float = PROBE_TIMEOUT_S) -> dict[str, Any]:
    probe = client.request_probe()
    if not isinstance(probe, dict):
        raise StepFailure("probe_not_dict")
    return probe


def ensure_clean_reset_state(client: SerialFlowClient, timeout_s: float = 6.0) -> dict[str, Any]:
    client.clear_transport_backlog()
    client.send_command("mdb_rx_invert_off", {})
    client.drain(0.10)
    client.send_command("mdb_passive_sniff_off", {})
    client.drain(0.10)
    client.send_command("mdb_clear_session", {})
    client.drain(0.35)
    deadline = time.monotonic() + timeout_s
    last_probe: dict[str, Any] | None = None
    last_error: Exception | None = None
    while time.monotonic() < deadline:
        try:
            probe = request_probe_checked(client)
            last_probe = probe
            if probe_matches_clean_reset_state(probe):
                return probe
        except Exception as exc:
            last_error = exc
        client.drain(0.25)
    if last_probe is not None:
        raise StepFailure(f"candidate_reset_did_not_reach_clean_state:{compact_json(last_probe)}")
    if last_error is not None:
        raise StepFailure(f"candidate_reset_did_not_reach_clean_state:{last_error}")
    raise StepFailure("candidate_reset_did_not_reach_clean_state:no_probe")


def probe_matches_setup_response_experiment(probe: dict[str, Any], candidate: dict[str, Any]) -> bool:
    if not isinstance(probe, dict):
        return False
    if not bool(probe.get("setup_response_experiment_enabled")):
        return False
    if str(probe.get("setup_response_experiment_label") or "") != str(candidate["label"]):
        return False
    if str(probe.get("setup_response_experiment_currency_code_bytes_hex") or "").upper() != candidate_currency_hex(candidate):
        return False
    try:
        if int(probe.get("setup_response_experiment_max_response_time")) != int(candidate["max_response_time"]):
            return False
        if int(probe.get("setup_response_experiment_options")) != int(candidate["options"]):
            return False
    except (TypeError, ValueError):
        return False
    return True


def configure_setup_response_experiment_verified(client: SerialFlowClient, candidate: dict[str, Any], retries: int = 3) -> dict[str, Any]:
    last_probe: dict[str, Any] | None = None

    # If the requested candidate is already active, do not churn the transport.
    try:
        probe = request_probe_checked(client, timeout_s=3.0)
        last_probe = probe
        if probe_matches_setup_response_experiment(probe, candidate):
            return probe
    except Exception:
        pass

    for _ in range(retries):
        client.clear_transport_backlog()
        client.send_command(
            "mdb_setup_response_experiment",
            {
                "enabled": True,
                "label": str(candidate["label"]),
                "currency_code_hi": int(candidate["currency_code_hi"]),
                "currency_code_lo": int(candidate["currency_code_lo"]),
                "max_response_time": int(candidate["max_response_time"]),
                "options": int(candidate["options"]),
            },
        )
        client.drain(0.50)
        deadline = time.monotonic() + 3.5
        while time.monotonic() < deadline:
            try:
                probe = request_probe_checked(client, timeout_s=3.0)
                last_probe = probe
                if probe_matches_setup_response_experiment(probe, candidate):
                    return probe
            except Exception:
                pass
            client.drain(0.20)

    raise StepFailure("setup_response_experiment_not_visible_in_probe:" + compact_json(last_probe or {}))


def reset_candidate_state(client: SerialFlowClient, timeout_s: float = 6.0) -> dict[str, Any]:
    return ensure_clean_reset_state(client, timeout_s=timeout_s)


def apply_setup_response_experiment_candidate(client: SerialFlowClient, candidate: dict[str, Any], retries: int = 3) -> dict[str, Any]:
    return configure_setup_response_experiment_verified(client, candidate, retries=retries)


def run_setup_sweep(args: argparse.Namespace) -> tuple[dict[str, Any] | None, list[dict[str, Any]]]:
    results: list[dict[str, Any]] = []
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    for index, candidate in enumerate(POPULAR_SETUP_SWEEP_CANDIDATES, start=1):
        log_path = args.out_dir / f"mdb_setup_sweep_{timestamp}_{index:02d}_{candidate['label']}.log"
        outcome: dict[str, Any] = {
            "candidate": candidate,
            "pass": False,
            "log_path": str(log_path),
        }
        with SerialFlowClient(
            port=args.port,
            baud=args.baud,
            serial_timeout=args.timeout,
            log_path=log_path,
            verbose=args.verbose,
        ) as client:
            try:
                pre_reset_probe = ensure_clean_reset_state(client)
                applied_probe = configure_setup_response_experiment_verified(client, candidate)
                post_apply_clean_probe = ensure_clean_reset_state(client)

                def poll_init_state() -> None:
                    client.send_command("mdb_probe", {})

                client.wait_for(
                    lambda state: state.initialization_ready(),
                    args.setup_sweep_timeout,
                    "initialization_phase",
                    on_poll=poll_init_state,
                    poll_interval_s=INIT_PROBE_INTERVAL_S,
                )
                final_probe = request_probe_checked(client)
                outcome.update({
                    "pass": True,
                    "pre_reset_probe": pre_reset_probe,
                    "applied_probe": applied_probe,
                    "post_apply_clean_probe": post_apply_clean_probe,
                    "final_probe": final_probe,
                    "experiment_verified": True,
                    "reboot_detected": client.state.reboot_detected,
                })
            except Exception as exc:
                failure_probe = None
                try:
                    failure_probe = request_probe_checked(client)
                except Exception:
                    failure_probe = None
                blocker_probe = failure_probe if isinstance(failure_probe, dict) else (
                    client.state.last_probe if isinstance(client.state.last_probe, dict) else {}
                )
                outcome.update({
                    "pass": False,
                    "failure_reason": str(exc),
                    "classified_failure_reason": classify_init_phase_blocker(
                        blocker_probe, client.state.reboot_detected
                    ),
                    "blocker_snapshot": summarize_probe_blocker(blocker_probe),
                    "failure_probe": failure_probe,
                    "reboot_detected": client.state.reboot_detected,
                    "reboot_from_uptime_ms": client.state.reboot_from_uptime_ms,
                    "reboot_to_uptime_ms": client.state.reboot_to_uptime_ms,
                    "experiment_verified": bool(
                        isinstance(client.state.last_probe, dict)
                        and probe_matches_setup_response_experiment(client.state.last_probe, candidate)
                    ),
                })
        results.append(outcome)
        if outcome.get("pass"):
            return candidate, results
    return None, results


def build_paths(out_dir: Path) -> tuple[Path, Path, Path]:
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    base = out_dir / f"mdb_cashless_flow_{timestamp}"
    return base.with_suffix(".log"), base.with_suffix(".json"), base.with_suffix(".txt")


def write_json(path: Path, payload: dict[str, Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as handle:
        json.dump(payload, handle, ensure_ascii=False, indent=2)
        handle.write("\n")


def write_text(path: Path, content: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(content, encoding="utf-8")


def minor_to_display(amount_minor: int, scale_factor: int = 100, decimal_places: int = 2) -> str:
    return f"{amount_minor / float(scale_factor):.{decimal_places}f}"


def summarize_probe_blocker(probe: dict[str, Any]) -> dict[str, Any]:
    if not isinstance(probe, dict):
        return {
            "reader_state": None,
            "last_rx_kind": None,
            "last_tx_kind": None,
            "expected_next_rx_kind": None,
            "expected_next_tx_kind": None,
            "protocol_progress_blocker": None,
            "wrapper_phase": None,
            "wrapper_fsm_state": None,
            "wrapper_transition_reason": None,
        }

    return {
        "reader_state": probe.get("last_reader_state") or probe.get("reader_state"),
        "last_rx_kind": probe.get("last_rx_kind"),
        "last_tx_kind": probe.get("last_tx_kind"),
        "expected_next_rx_kind": probe.get("expected_next_rx_kind"),
        "expected_next_tx_kind": probe.get("expected_next_tx_kind"),
        "protocol_progress_blocker": probe.get("protocol_progress_blocker"),
        "wrapper_phase": probe.get("wrapper_phase"),
        "wrapper_fsm_state": probe.get("wrapper_fsm_state"),
        "wrapper_transition_reason": probe.get("wrapper_transition_reason"),
    }


def classify_init_phase_blocker(probe: dict[str, Any], reboot_detected: bool = False) -> str:
    if reboot_detected:
        return "reboot_detected_during_init"

    blocker = str(probe.get("protocol_progress_blocker") or "")
    expected_rx = str(probe.get("expected_next_rx_kind") or "")
    reader_state = str(probe.get("last_reader_state") or probe.get("reader_state") or "")
    setup_rx_count = int(probe.get("setup_rx_count") or 0)
    setup_tx_count = int(probe.get("setup_tx_count") or 0)
    last_rx_kind = str(probe.get("last_rx_kind") or "")

    if blocker == "waiting_for_poll_after_reset" or (
        expected_rx == "POLL" and reader_state == "UNINITIALIZED"
    ):
        return "still_waiting_for_poll_after_reset"

    if setup_rx_count > 0 and setup_tx_count > 0 and last_rx_kind == "SETUP":
        return "setup_seen_but_no_followup"

    if setup_rx_count > 0 and setup_tx_count > 0:
        return "setup_response_sent_but_init_not_completed"

    return "initialization_phase_unknown"


def compact_flow_state_snapshot(client: SerialFlowClient) -> dict[str, Any]:
    probe = client.state.last_probe if isinstance(client.state.last_probe, dict) else {}
    return {
        "saw_setup": client.state.saw_setup,
        "saw_setup_response": client.state.saw_setup_response,
        "saw_enable": client.state.saw_enable,
        "saw_poll": client.state.saw_poll,
        "reader_enabled": client.state.reader_enabled,
        "begin_session_armed": client.state.begin_session_armed,
        "begin_session_sent": client.state.begin_session_sent,
        "begin_session_ack_received": client.state.begin_session_ack_received,
        "last_probe_reader_state": probe.get("last_reader_state"),
        "last_probe_rx_kind": probe.get("last_rx_kind"),
        "last_probe_tx_kind": probe.get("last_tx_kind"),
        "last_probe_setup_rx_count": probe.get("setup_rx_count"),
        "last_probe_setup_tx_count": probe.get("setup_tx_count"),
        "last_probe_poll_rx_count": probe.get("poll_rx_count"),
        "last_probe_enable_rx_count": probe.get("enable_rx_count"),
        "last_probe_protocol_progress_blocker": probe.get("protocol_progress_blocker"),
        "last_probe_wrapper_phase": probe.get("wrapper_phase"),
        "last_probe_wrapper_fsm_state": probe.get("wrapper_fsm_state"),
        "last_probe_wrapper_transition_reason": probe.get("wrapper_transition_reason"),
        "reboot_detected": client.state.reboot_detected,
        "reboot_from_uptime_ms": client.state.reboot_from_uptime_ms,
        "reboot_to_uptime_ms": client.state.reboot_to_uptime_ms,
    }


def capture_flow_snapshot(client: SerialFlowClient, label: str) -> dict[str, Any]:
    snapshot = compact_flow_state_snapshot(client)
    client._log("INFO", f"{label}={compact_json(snapshot)}")
    return snapshot


def run_trace(args: argparse.Namespace, log_path: Path, json_path: Path, txt_path: Path, selected_candidate: dict[str, Any] | None = None, sweep_results: list[dict[str, Any]] | None = None) -> dict[str, Any]:
    report: dict[str, Any] = {
        "meta": {
            "test_name": "mdb_cashless_flow_trace",
            "started_at": now_iso(),
            "port": args.port,
            "baud": args.baud,
            "serial_timeout_s": args.timeout,
            "credit_minor": args.credit,
            "credit_display": minor_to_display(args.credit),
            "scale_factor": 100,
            "decimal_places": 2,
            "log_path": str(log_path),
            "json_path": str(json_path),
            "txt_path": str(txt_path),
            "rx_invert_policy": "fixed_off",
            "commands_used": [
                "mdb_rx_invert_off",
                "mdb_passive_sniff_off",
                "mdb_clear_session",
                "mdb_probe",
                "pay transport=mdb",
                "mdb_approve",
            ] + (["mdb_setup_response_experiment"] if selected_candidate else []),
            "setup_sweep_selected": selected_candidate,
        },
        "setup_sweep": sweep_results or [],
        "steps": [],
        "cashless_flow": {"steps": [], "exchanges": [], "text": ""},
        "result": {},
    }

    with SerialFlowClient(
        port=args.port,
        baud=args.baud,
        serial_timeout=args.timeout,
        log_path=log_path,
        verbose=args.verbose,
    ) as client:
        try:
            step = client.begin_step("serial_access")
            client.drain(0.5)
            report["steps"].append(asdict(client.end_step(step, "PASS", {"serial_open": True})))

            step = client.begin_step("startup_state_snapshot")
            startup_snapshot = capture_flow_snapshot(client, "startup_state_snapshot")
            report["steps"].append(asdict(client.end_step(step, "PASS", {"snapshot": startup_snapshot})))

            if selected_candidate is not None:
                step = client.begin_step("setup_response_experiment")
                pre_apply_clean_probe = ensure_clean_reset_state(client)
                verification_probe = configure_setup_response_experiment_verified(client, selected_candidate)
                post_apply_clean_probe = ensure_clean_reset_state(client)
                report["steps"].append(
                    asdict(
                        client.end_step(
                            step,
                            "PASS",
                            {
                                "candidate": selected_candidate,
                                "pre_apply_clean_probe": pre_apply_clean_probe,
                                "verification_probe": verification_probe,
                                "post_apply_clean_probe": post_apply_clean_probe,
                            },
                        )
                    )
                )

            step = client.begin_step("baseline_probe")
            client.send_command("mdb_rx_invert_off", {})
            client.send_command("mdb_passive_sniff_off", {})
            client.drain(0.25)
            client.clear_transport_backlog()
            baseline_probe = client.request_probe()
            report["steps"].append(
                asdict(
                    client.end_step(
                        step,
                        "PASS",
                        {
                            "probe_received": True,
                            "protocol_alive": client.state.protocol_alive(),
                            "probe": baseline_probe,
                        },
                    )
                )
            )

            step = client.begin_step("clear_session")
            client.send_command("mdb_clear_session", {})
            client.drain(1.0)
            clear_probe = client.request_probe()
            report["steps"].append(
                asdict(
                    client.end_step(
                        step,
                        "PASS",
                        {"clear_session_sent": True, "probe": clear_probe},
                    )
                )
            )

            step = client.begin_step("wait_init_phase")
            init_probe, first_setup_snapshot = wait_for_initialization_phase(client, INIT_TIMEOUT_S)
            report["steps"].append(
                asdict(
                    client.end_step(
                        step,
                        "PASS",
                        {
                            "initialization_passed": True,
                            "probe": init_probe,
                            "startup_snapshot": startup_snapshot,
                            "first_setup_snapshot": first_setup_snapshot,
                            "selected_setup_candidate": selected_candidate,
                        },
                    )
                )
            )

            txid = f"flow-{uuid.uuid4().hex[:12]}"

            step = client.begin_step("record_payment")
            client.send_command(
                "pay",
                {"amount": int(args.credit), "transport": "mdb", "transaction_id": txid},
            )
            pay_event = client.wait_for_event({"payment_received", "payment_rejected", "payment_ignored"}, PAYMENT_TIMEOUT_S)
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
                            "details": pay_event.details,
                        },
                    )
                )
            )

            step = client.begin_step("approve_credit")
            client.send_command("mdb_approve", {"amount": int(args.credit), "transaction_id": txid})
            approve_event = client.wait_for_event({"credit_approved", "approve_rejected"}, APPROVE_TIMEOUT_S)
            if approve_event.event != "credit_approved":
                raise StepFailure(f"credit_approval_failed:{approve_event.event}")
            client.wait_for(lambda state: state.begin_session_armed, 2.0, "begin_session_armed")
            report["steps"].append(
                asdict(
                    client.end_step(
                        step,
                        "PASS",
                        {
                            "transaction_id": txid,
                            "event": approve_event.event,
                            "details": approve_event.details,
                        },
                    )
                )
            )

            step = client.begin_step("wait_begin_session_tx")
            client.wait_for(
                lambda state: state.begin_session_sent or state.begin_session_bus_tx,
                BEGIN_SESSION_TX_TIMEOUT_S,
                "begin_session_tx",
                on_poll=lambda: client.send_command("mdb_probe", {}),
                poll_interval_s=INIT_PROBE_INTERVAL_S,
            )
            report["steps"].append(
                asdict(
                    client.end_step(
                        step,
                        "PASS",
                        {"begin_session_sent": True},
                    )
                )
            )

            step = client.begin_step("wait_begin_session_ack")
            client.wait_for(
                lambda state: state.begin_session_ack_received or state.begin_session_ack_missing,
                BEGIN_SESSION_ACK_TIMEOUT_S,
                "begin_session_ack_or_timeout",
                on_poll=lambda: client.send_command("mdb_probe", {}),
                poll_interval_s=2.0,
            )
            ack_status = "PASS" if client.state.begin_session_ack_received else "FAIL"
            report["steps"].append(
                asdict(
                    client.end_step(
                        step,
                        ack_status,
                        {"machine_acceptance_status": client.state.machine_acceptance_status()},
                    )
                )
            )
            if not client.state.begin_session_ack_received:
                raise StepFailure("machine_did_not_ack_begin_session")

            step = client.begin_step("final_probe")
            final_probe = client.request_probe()
            client.drain(DECODER_WAIT_S)
            report["steps"].append(
                asdict(
                    client.end_step(
                        step,
                        "PASS",
                        {"probe": final_probe},
                    )
                )
            )

            report["result"] = {
                "pass": True,
                "initialization_passed": client.state.initialization_ready(),
                "machine_accepted": client.state.begin_session_ack_received,
                "probe_supported": client.state.explicit_probe_seen,
                "protocol_alive": client.state.protocol_alive(),
                "failure_step": None,
                "failure_reason": None,
                "credit_minor": args.credit,
                "credit_display": minor_to_display(args.credit),
                "scale_factor": 100,
                "decimal_places": 2,
            }
        except Exception as exc:
            failure_probe: dict[str, Any] | None = None
            try:
                failure_probe = client.request_probe()
            except Exception:
                failure_probe = None

            blocker_probe = failure_probe if isinstance(failure_probe, dict) else (
                client.state.last_probe if isinstance(client.state.last_probe, dict) else {}
            )
            blocker_snapshot = summarize_probe_blocker(blocker_probe)
            blocker_code = classify_init_phase_blocker(blocker_probe, client.state.reboot_detected)

            step_extra: dict[str, Any] = {
                "credit_minor": args.credit,
                "credit_display": minor_to_display(args.credit),
            }
            if blocker_probe:
                step_extra.update(
                    {
                        "failure_reason": blocker_code,
                        "blocker_snapshot": blocker_snapshot,
                        "setup_rx_count": blocker_probe.get("setup_rx_count"),
                        "setup_tx_count": blocker_probe.get("setup_tx_count"),
                        "poll_rx_count": blocker_probe.get("poll_rx_count"),
                        "enable_rx_count": blocker_probe.get("enable_rx_count"),
                        "reboot_detected": client.state.reboot_detected,
                        "reboot_from_uptime_ms": client.state.reboot_from_uptime_ms,
                        "reboot_to_uptime_ms": client.state.reboot_to_uptime_ms,
                    }
                )

            if client.current_step is not None:
                report["steps"].append(
                    asdict(client.end_step(client.current_step, "FAIL", step_extra))
                )

            report["result"] = {
                "pass": False,
                "initialization_passed": client.state.initialization_ready(),
                "machine_accepted": client.state.begin_session_ack_received,
                "probe_supported": client.state.explicit_probe_seen,
                "protocol_alive": client.state.protocol_alive(),
                "failure_step": report["steps"][-1]["name"] if report["steps"] else "unknown",
                "failure_reason": str(exc),
                "classified_failure_reason": blocker_code,
                "blocker_snapshot": blocker_snapshot,
                "exception_traceback": traceback.format_exc(),
                "failure_probe": failure_probe,
                "reboot_detected": client.state.reboot_detected,
                "reboot_from_uptime_ms": client.state.reboot_from_uptime_ms,
                "reboot_to_uptime_ms": client.state.reboot_to_uptime_ms,
                "credit_minor": args.credit,
                "credit_display": minor_to_display(args.credit),
                "scale_factor": 100,
                "decimal_places": 2,
            }

        flow_text = (
            f"Credit requested: {args.credit} minor units ({minor_to_display(args.credit)})\n\n"
            + client.flow.text_summary()
        )
        report["cashless_flow"] = {
            "steps": client.flow.steps(),
            "exchanges": client.flow.exchanges(),
            "text": flow_text,
        }
        report["meta"]["ended_at"] = now_iso()

    write_json(json_path, report)
    write_text(txt_path, report["cashless_flow"]["text"])
    return report


def build_arg_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Trace the MDB cashless flow and show what was received and what was sent back."
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
        help="Directory for .log/.json/.txt outputs",
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
        help="Print serial RX/TX lines to stdout",
    )
    parser.add_argument(
        "--setup-sweep",
        action="store_true",
        help="Try a small set of popular READER CONFIG combinations before the full trace",
    )
    parser.add_argument(
        "--setup-sweep-timeout",
        type=float,
        default=SETUP_SWEEP_INIT_TIMEOUT_S,
        help="Per-candidate initialization timeout for the setup sweep",
    )
    return parser


def main() -> int:
    args = build_arg_parser().parse_args()
    log_path, json_path, txt_path = build_paths(args.out_dir)
    try:
        selected_candidate = None
        sweep_results: list[dict[str, Any]] | None = None
        if args.setup_sweep:
            selected_candidate, sweep_results = run_setup_sweep(args)
            if selected_candidate is None:
                fallback = {
                    "meta": {
                        "test_name": "mdb_cashless_flow_trace",
                        "started_at": now_iso(),
                        "ended_at": now_iso(),
                        "port": args.port,
                        "baud": args.baud,
                        "serial_timeout_s": args.timeout,
                        "credit_minor": args.credit,
                        "credit_display": minor_to_display(args.credit),
                        "scale_factor": 100,
                        "decimal_places": 2,
                        "log_path": str(log_path),
                        "json_path": str(json_path),
                        "txt_path": str(txt_path),
                    },
                    "steps": [],
                    "setup_sweep": sweep_results or [],
                    "cashless_flow": {
                        "steps": [],
                        "exchanges": [],
                        "text": f"Credit requested: {args.credit} minor units ({minor_to_display(args.credit)})\n\nNo working setup candidate found.\n",
                    },
                    "result": {
                        "pass": False,
                        "failure_step": "setup_sweep",
                        "failure_reason": "no_working_setup_candidate",
                        "credit_minor": args.credit,
                        "credit_display": minor_to_display(args.credit),
                        "scale_factor": 100,
                        "decimal_places": 2,
                    },
                }
                write_json(json_path, fallback)
                write_text(txt_path, fallback["cashless_flow"]["text"])
                print(compact_json({"pass": False, "json_path": str(json_path), "txt_path": str(txt_path), "log_path": str(log_path)}))
                return 1
        report = run_trace(args, log_path, json_path, txt_path, selected_candidate, sweep_results)
    except Exception as exc:
        fallback = {
            "meta": {
                "test_name": "mdb_cashless_flow_trace",
                "started_at": now_iso(),
                "ended_at": now_iso(),
                "port": args.port,
                "baud": args.baud,
                "serial_timeout_s": args.timeout,
                "credit_minor": args.credit,
                "credit_display": minor_to_display(args.credit),
                "scale_factor": 100,
                "decimal_places": 2,
                "log_path": str(log_path),
                "json_path": str(json_path),
                "txt_path": str(txt_path),
            },
            "steps": [],
            "cashless_flow": {
                "steps": [],
                "exchanges": [],
                "text": f"Credit requested: {args.credit} minor units ({minor_to_display(args.credit)})\n\nNo flow captured.\n",
            },
            "result": {
                "pass": False,
                "failure_step": "startup",
                "failure_reason": str(exc),
                "credit_minor": args.credit,
                "credit_display": minor_to_display(args.credit),
                "scale_factor": 100,
                "decimal_places": 2,
                "exception_traceback": traceback.format_exc(),
            },
        }
        write_json(json_path, fallback)
        write_text(txt_path, fallback["cashless_flow"]["text"])
        print(compact_json({"pass": False, "json_path": str(json_path), "txt_path": str(txt_path)}))
        return 1

    print(compact_json({
        "pass": report["result"].get("pass"),
        "json_path": str(json_path),
        "txt_path": str(txt_path),
        "log_path": str(log_path),
    }))
    return 0 if report["result"].get("pass") else 1


if __name__ == "__main__":
    raise SystemExit(main())
