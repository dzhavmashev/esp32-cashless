#!/usr/bin/env python3
"""Automated Jofemar / MDB Gateway FSM tester for ESP32 USB console.

Example:
  python3 tools/jofemar_auto_test.py --port /dev/ttyUSB0 --baud 115200 --require-samples 3 --scenario-timeout 20 --hard-timeout 90

Manual VMC power-cycle:
  python3 tools/jofemar_auto_test.py --port /dev/ttyUSB0 --manual-power-cycle --require-samples 3

Unsafe diagnostic modes:
  python3 tools/jofemar_auto_test.py --port /dev/ttyUSB0 --include-unsafe

Negative payment test:
  python3 tools/jofemar_auto_test.py --port /dev/ttyUSB0 --pay-negative-test
"""

from __future__ import annotations

import argparse
import csv
import json
import sys
import time
from collections import Counter
from dataclasses import asdict, dataclass, field
from datetime import datetime
from pathlib import Path
from typing import Any

try:
    import serial
    from serial import SerialException
except ImportError:
    print("pyserial is not installed. Install it with:\n  pip install pyserial", file=sys.stderr)
    raise SystemExit(2)


DEFAULT_SCENARIOS = [
    ("test_01_passive_ignore", "passive", "ignore"),
    ("test_02_old_0b_ignore", "old_0b", "ignore"),
    ("test_03_old_60_ignore", "old_60", "ignore"),
    ("test_04_old_33_ignore", "old_33", "ignore"),
    ("test_05_old_status_cycle_ignore", "old_status_cycle", "ignore"),
    ("test_06_ack_ignore", "ack", "ignore"),
    ("test_07_fe_ignore", "fe", "ignore"),
    ("test_08_old_0b_compact_cycle", "old_0b", "old_status_cycle"),
    ("test_09_old_60_compact_cycle", "old_60", "old_status_cycle"),
    ("test_10_old_33_compact_cycle", "old_33", "old_status_cycle"),
    ("test_11_passive_compact_ack", "passive", "ack"),
    ("test_12_passive_compact_ret", "passive", "ret"),
    ("test_13_passive_compact_nak", "passive", "nak"),
]
UNSAFE_SCENARIOS = [
    ("test_unsafe_a_real_setup_a", "real_setup_a", "ignore"),
    ("test_unsafe_g_real_setup_g", "real_setup_g", "ignore"),
]
OLD60_COMPACT_SWEEP_SCENARIOS = [
    ("old60_compact_01_ignore", "old_60", "ignore"),
    ("old60_compact_02_ack", "old_60", "ack"),
    ("old60_compact_03_ret", "old_60", "ret"),
    ("old60_compact_04_nak", "old_60", "nak"),
    ("old60_compact_05_old_60", "old_60", "old_60"),
    ("old60_compact_06_old_0b", "old_60", "old_0b"),
    ("old60_compact_07_old_33", "old_60", "old_33"),
    ("old60_compact_08_old_status_cycle", "old_60", "old_status_cycle"),
]
OLD60_FC_ACK_1C_SWEEP_SCENARIOS = [
    ("old60_fc_ack_1c_ignore", "old_60", "ignore", "ack", "inherit", "ignore", "inherit"),
    ("old60_fc_ack_1c_ack", "old_60", "ignore", "ack", "inherit", "ack", "inherit"),
    ("old60_fc_ack_1c_ret", "old_60", "ignore", "ack", "inherit", "ret", "inherit"),
    ("old60_fc_ack_1c_nak", "old_60", "ignore", "ack", "inherit", "nak", "inherit"),
    ("old60_fc_ack_1c_old_60", "old_60", "ignore", "ack", "inherit", "old_60", "inherit"),
    ("old60_fc_ack_1c_old_0b", "old_60", "ignore", "ack", "inherit", "old_0b", "inherit"),
    ("old60_fc_ack_1c_old_33", "old_60", "ignore", "ack", "inherit", "old_33", "inherit"),
    ("old60_fc_ack_1c_fe", "old_60", "ignore", "ack", "inherit", "fe", "inherit"),
    ("old60_fc_ack_1c_cycle", "old_60", "ignore", "ack", "inherit", "old_status_cycle", "inherit"),
]
OLD60_FC_ACK_1C_OLD60_LONG_SCENARIOS = [
    ("old60_fc_ack_1c_old60_long", "old_60", "ignore", "ack", "inherit", "old_60", "inherit"),
]

PHASE_PRE_ARM = "pre_arm_drain"
PHASE_ARMING = "arming"
PHASE_SCENARIO = "scenario"
PHASE_POST = "post_scenario_drain"

CONTAMINATION_EVENTS = {
    "jofemar_gateway_identify_seen",
    "jofemar_gateway_response_sent",
    "jofemar_gateway_compact_seen",
    "jofemar_gateway_sequence_summary",
}
FAIL_EVENTS_SYNTHETIC = {"cashless_gateway_setup_compat", "gateway19_real_setup_response_sent"}
CREDIT_TX_EVENTS = {
    "mdb_fe_credit_sent",
    "coin_credit_reply_sent",
    "coin_credit_sent",
    "cashless_begin_session_sent",
    "poll_begin_session",
    "vend_approved",
    "legacy_credit_sent",
}


def compact_json(obj: Any) -> str:
    return json.dumps(obj, ensure_ascii=False, separators=(",", ":"))


def now_label() -> str:
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S")


def log(message: str, verbose: bool = True) -> None:
    if verbose:
        print(f"[{now_label()}] {message}", flush=True)


def event_name(record: dict[str, Any]) -> str:
    value = record.get("event")
    return value if isinstance(value, str) else ""


def details(record: dict[str, Any] | None) -> dict[str, Any]:
    if not record:
        return {}
    value = record.get("details")
    return value if isinstance(value, dict) else {}


def has_reader_enabled(record: dict[str, Any]) -> bool:
    return details(record).get("reader_enabled") is True


def split_hex_sequence(value: str) -> list[str]:
    return [part.strip().upper() for part in value.replace(",", "->").split("->") if part.strip()]


def has_ordered_pair(values: list[str], first: str, second: str) -> bool:
    seen_first = False
    for value in values:
        if value == first:
            seen_first = True
        elif seen_first and value == second:
            return True
    return False


@dataclass(frozen=True)
class Scenario:
    name: str
    gateway_mode: str
    compact_response_mode: str
    fc_response_mode: str = "inherit"
    fe_response_mode: str = "inherit"
    one_c_response_mode: str = "inherit"
    e0_response_mode: str = "inherit"
    unsafe: bool = False


@dataclass
class ScenarioResult:
    scenario: str
    gateway_mode: str
    compact_response_mode: str
    fc_response_mode: str = "inherit"
    fe_response_mode: str = "inherit"
    one_c_response_mode: str = "inherit"
    e0_response_mode: str = "inherit"
    started_at: str = ""
    duration_sec: float = 0.0
    scenario_armed_at_monotonic: float = 0.0
    identify_seen_count: int = 0
    synthetic_suppressed_count: int = 0
    gateway_response_sent_count: int = 0
    compact_seen_count: int = 0
    compact_response_sent_count: int = 0
    sequence_summary_count: int = 0
    window_closed_count: int = 0
    post_scenario_attached_summary_count: int = 0
    sequence_close_status: str = ""
    sequence_close_wait_ms: int = 0
    reset_seen_count: int = 0
    poll_seen_count: int = 0
    enable_seen_count: int = 0
    reader_enabled_seen: bool = False
    timeout_count: int = 0
    new_gateway19_count: int = 0
    first_tx_hex_values: list[str] = field(default_factory=list)
    followups_hex_values: list[str] = field(default_factory=list)
    close_reason_counts: dict[str, int] = field(default_factory=dict)
    response_hex_counts: dict[str, int] = field(default_factory=dict)
    compact_response_hex_counts: dict[str, int] = field(default_factory=dict)
    compact_symbol_counts: dict[str, int] = field(default_factory=dict)
    old60_fe_after_tx_samples: int = 0
    old60_1c_after_fe_samples: int = 0
    compact_response_then_followup_samples: int = 0
    old60_fc_after_tx_samples: int = 0
    old60_fc_ack_samples: int = 0
    old60_1c_after_fc_samples: int = 0
    old60_followup_after_1c_response_samples: int = 0
    fc_seen_count: int = 0
    fc_ack_count: int = 0
    one_c_seen_count: int = 0
    one_c_old60_count: int = 0
    followup_after_1c_old60_count: int = 0
    followup_after_1c_old60_symbols: dict[str, int] = field(default_factory=dict)
    post_1c_old60_followup_detected: bool = False
    unique_sequences: dict[str, int] = field(default_factory=dict)
    compact_orders: list[str] = field(default_factory=list)
    raw_unexpected_events_count: int = 0
    contamination_warnings: list[str] = field(default_factory=list)
    warnings: list[str] = field(default_factory=list)
    failures: list[str] = field(default_factory=list)
    critical_failures: list[str] = field(default_factory=list)
    pay_negative_test_ran: bool = False
    pay_negative_test_skipped: bool = False
    sample_quality: str = "none"
    score: int | None = 0
    status: str = "UNKNOWN"


class SerialConsole:
    def __init__(self, port: str, baud: int, raw_all_path: Path) -> None:
        self.ser = serial.Serial(port, baud, timeout=0.1)
        self.ser.dtr = False
        self.ser.rts = False
        self.raw_all_path = raw_all_path
        self._buf = bytearray()

    def close(self) -> None:
        self.ser.close()

    def send(self, command: str) -> None:
        self.ser.write((command + "\n").encode("utf-8"))
        self.ser.flush()

    def read_records(self, seconds: float, phase: str) -> list[dict[str, Any]]:
        deadline = time.monotonic() + seconds
        records: list[dict[str, Any]] = []
        while time.monotonic() < deadline:
            data = self.ser.read(4096)
            if not data:
                continue
            self._buf.extend(data)
            while True:
                newline = self._buf.find(b"\n")
                if newline < 0:
                    if len(self._buf) > 64 * 1024:
                        self._buf.clear()
                    break
                raw = bytes(self._buf[:newline])
                del self._buf[: newline + 1]
                record = self._parse_line(raw, phase)
                records.append(record)
                append_jsonl(self.raw_all_path, [record])
        return records

    @staticmethod
    def _parse_line(raw: bytes, phase: str) -> dict[str, Any]:
        text = raw.decode("utf-8", "replace").strip()
        base = {"ts_host": time.time(), "runner_phase": phase, "raw_line": text}
        if not text:
            return {**base, "type": "serial_text", "event": "serial_blank"}
        if text.startswith("{"):
            try:
                obj = json.loads(text)
            except json.JSONDecodeError:
                return {**base, "type": "serial_text", "event": "serial_json_invalid"}
            if isinstance(obj, dict):
                obj.setdefault("ts_host", base["ts_host"])
                obj.setdefault("raw_line", text)
                obj["runner_phase"] = phase
                return obj
        if text.startswith("usb_cmd_error:"):
            return {**base, "type": "plain_error", "event": "usb_cmd_error"}
        if text.startswith("WS JSON parse failed"):
            return {**base, "type": "plain_error", "event": "ws_json_parse_failed"}
        if "command_rejected" in text:
            return {**base, "type": "plain_error", "event": "command_rejected"}
        return {**base, "type": "serial_text", "event": "serial_text"}


def append_jsonl(path: Path, records: list[dict[str, Any]]) -> None:
    with path.open("a", encoding="utf-8") as handle:
        for record in records:
            handle.write(compact_json(record) + "\n")


def make_runner_event(event: str, phase: str, payload: dict[str, Any] | None = None) -> dict[str, Any]:
    return {
        "type": "runner_event",
        "event": event,
        "details": payload or {},
        "runner_phase": phase,
        "ts_host": time.time(),
        "raw_line": "",
    }


def send_command(
    conn: SerialConsole,
    command: str,
    scenario_log: Path,
    settle_ms: int,
    verbose: bool,
    phase: str,
) -> list[dict[str, Any]]:
    log(f"TX> {command}", verbose)
    conn.send(command)
    records = conn.read_records(max(0.0, settle_ms / 1000.0), phase)
    append_jsonl(scenario_log, records)
    return records


def wait_for_events(
    conn: SerialConsole,
    scenario_log: Path,
    names: set[str],
    timeout_s: float,
    phase: str,
) -> list[dict[str, Any]]:
    records: list[dict[str, Any]] = []
    deadline = time.monotonic() + timeout_s
    seen: set[str] = set()
    while time.monotonic() < deadline and not names.issubset(seen):
        chunk = conn.read_records(min(0.1, max(0.0, deadline - time.monotonic())), phase)
        if not chunk:
            continue
        append_jsonl(scenario_log, chunk)
        records.extend(chunk)
        seen.update(event_name(record) for record in chunk if event_name(record) in names)
    return records


def mark_contamination(result: ScenarioResult, records: list[dict[str, Any]]) -> None:
    for record in records:
        event = event_name(record)
        if event in CONTAMINATION_EVENTS:
            result.contamination_warnings.append(
                f"{record.get('runner_phase')} saw {event}: {details(record)}"
            )


def last_jofemar_status(records: list[dict[str, Any]]) -> dict[str, Any]:
    for record in reversed(records):
        if event_name(record) == "jofemar_status":
            return details(record)
    return {}


def arm_scenario(
    conn: SerialConsole,
    scenario: Scenario,
    result: ScenarioResult,
    scenario_log: Path,
    args: argparse.Namespace,
) -> list[dict[str, Any]]:
    records: list[dict[str, Any]] = []
    if args.manual_power_cycle:
        input(f"\nPower-cycle VMC now for {scenario.name}, then press Enter...")

    records.extend(send_command(conn, "jofemar_gateway_mode passive", scenario_log, args.settle_ms, args.verbose, PHASE_ARMING))
    records.extend(send_command(conn, "jofemar_compact_response_mode ignore", scenario_log, args.settle_ms, args.verbose, PHASE_ARMING))
    quiet_status = send_command(conn, "jofemar_status", scenario_log, args.settle_ms, args.verbose, PHASE_ARMING)
    records.extend(quiet_status)
    quiet_status_data = last_jofemar_status(quiet_status)
    quiet_window_active = quiet_status_data.get("jofemar_gateway_window_active") is True

    quiet_wait = conn.read_records(2.2, PHASE_PRE_ARM)
    append_jsonl(scenario_log, quiet_wait)
    records.extend(quiet_wait)

    if quiet_window_active and not any(event_name(record) == "jofemar_gateway_window_closed" for record in quiet_wait):
        close_wait = wait_for_events(conn, scenario_log, {"jofemar_gateway_window_closed"}, 2.0, PHASE_PRE_ARM)
        records.extend(close_wait)

    pre_drain = conn.read_records(0.5, PHASE_PRE_ARM)
    append_jsonl(scenario_log, pre_drain)
    records.extend(pre_drain)

    records.extend(send_command(conn, "jofemar_symbol_response_modes_reset", scenario_log, args.settle_ms, args.verbose, PHASE_ARMING))
    records.extend(send_command(conn, f"jofemar_gateway_mode {scenario.gateway_mode}", scenario_log, args.settle_ms, args.verbose, PHASE_ARMING))
    records.extend(send_command(conn, f"jofemar_compact_response_mode {scenario.compact_response_mode}", scenario_log, args.settle_ms, args.verbose, PHASE_ARMING))
    records.extend(send_command(conn, f"jofemar_fc_response_mode {scenario.fc_response_mode}", scenario_log, args.settle_ms, args.verbose, PHASE_ARMING))
    records.extend(send_command(conn, f"jofemar_fe_response_mode {scenario.fe_response_mode}", scenario_log, args.settle_ms, args.verbose, PHASE_ARMING))
    records.extend(send_command(conn, f"jofemar_1c_response_mode {scenario.one_c_response_mode}", scenario_log, args.settle_ms, args.verbose, PHASE_ARMING))
    records.extend(send_command(conn, f"jofemar_e0_response_mode {scenario.e0_response_mode}", scenario_log, args.settle_ms, args.verbose, PHASE_ARMING))
    records.extend(wait_for_events(
        conn,
        scenario_log,
        {"jofemar_gateway_mode_changed", "jofemar_compact_response_mode_changed"},
        2.0,
        PHASE_ARMING,
    ))
    records.extend(send_command(conn, "jofemar_status", scenario_log, args.settle_ms, args.verbose, PHASE_ARMING))
    records.extend(send_command(conn, "jofemar_reset_counters", scenario_log, args.settle_ms, args.verbose, PHASE_ARMING))
    records.extend(send_command(conn, "jofemar_status", scenario_log, args.settle_ms, args.verbose, PHASE_ARMING))

    status = last_jofemar_status(records)
    if status:
        if status.get("jofemar_gateway_mode") != scenario.gateway_mode:
            result.warnings.append(f"arming status gateway mode mismatch: {status.get('jofemar_gateway_mode')}")
        if status.get("jofemar_compact_response_mode") != scenario.compact_response_mode:
            result.warnings.append(f"arming status compact mode mismatch: {status.get('jofemar_compact_response_mode')}")
        if status.get("jofemar_fc_response_mode") != scenario.fc_response_mode:
            result.warnings.append(f"arming status FC mode mismatch: {status.get('jofemar_fc_response_mode')}")
        if status.get("jofemar_fe_response_mode") != scenario.fe_response_mode:
            result.warnings.append(f"arming status FE mode mismatch: {status.get('jofemar_fe_response_mode')}")
        if status.get("jofemar_1c_response_mode") != scenario.one_c_response_mode:
            result.warnings.append(f"arming status 1C mode mismatch: {status.get('jofemar_1c_response_mode')}")
        if status.get("jofemar_e0_response_mode") != scenario.e0_response_mode:
            result.warnings.append(f"arming status E0 mode mismatch: {status.get('jofemar_e0_response_mode')}")
        if int(status.get("jofemar_gateway_seen_count") or 0) != 0:
            result.warnings.append(f"arming status seen_count not zero: {status.get('jofemar_gateway_seen_count')}")
        if status.get("jofemar_gateway_window_active") is True:
            result.warnings.append("arming status window still active")
    else:
        result.warnings.append("no jofemar_status received during arming")

    mark_contamination(result, [r for r in records if r.get("runner_phase") != PHASE_SCENARIO])
    result.scenario_armed_at_monotonic = time.monotonic()
    return records


def should_stop(records: list[dict[str, Any]], max_sequences: int, require_samples: int, normal_deadline: float) -> bool:
    identify = sum(1 for record in records if event_name(record) == "jofemar_gateway_identify_seen")
    summaries = sum(1 for record in records if event_name(record) == "jofemar_gateway_sequence_summary")
    if identify >= require_samples or summaries >= max_sequences:
        return True
    for record in records:
        data = details(record)
        if data.get("reader_enabled") is True or data.get("enable_seen") is True or data.get("poll_seen") is True:
            return True
        if event_name(record) in {"jofemar_gateway_poll_seen", "jofemar_gateway_enable_seen"}:
            return True
    return time.monotonic() >= normal_deadline and identify > 0


def progress_seen(records: list[dict[str, Any]]) -> bool:
    for record in records:
        data = details(record)
        if data.get("reader_enabled") is True or data.get("enable_seen") is True or data.get("poll_seen") is True:
            return True
        if event_name(record) in {"jofemar_gateway_poll_seen", "jofemar_gateway_enable_seen"}:
            return True
    return False


def attach_late_summary(records: list[dict[str, Any]]) -> int:
    attached = 0
    for record in records:
        if event_name(record) == "jofemar_gateway_sequence_summary":
            record["runner_attached_from_phase"] = record.get("runner_phase")
            record["runner_phase"] = PHASE_SCENARIO
            attached += 1
    return attached


def run_pay_negative_test(conn: SerialConsole, scenario_log: Path, args: argparse.Namespace) -> tuple[list[dict[str, Any]], list[str]]:
    warnings: list[str] = []
    records = send_command(conn, "pay amount=100 transport=mdb", scenario_log, args.settle_ms, args.verbose, PHASE_POST)
    extra = conn.read_records(1.5, PHASE_POST)
    append_jsonl(scenario_log, extra)
    records.extend(extra)
    if any(event_name(record) in {"usb_cmd_error", "command_rejected"} for record in records):
        warnings.append("pay command not supported or rejected; negative payment test skipped")
    return records, warnings


def command_errors(records: list[dict[str, Any]]) -> list[str]:
    errors: list[str] = []
    for record in records:
        event = event_name(record)
        line = str(record.get("raw_line") or "")
        if event == "usb_cmd_error":
            errors.append(line or "usb_cmd_error")
        elif event == "command_rejected":
            errors.append(line or compact_json(record))
    return errors


def analyze_result(result: ScenarioResult, records: list[dict[str, Any]], require_samples: int) -> None:
    scenario_records = [record for record in records if record.get("runner_phase") == PHASE_SCENARIO]
    guarded_records = [
        record for record in records
        if record.get("runner_phase") in {PHASE_SCENARIO, PHASE_POST}
    ]
    close_reasons: Counter[str] = Counter()
    response_hex: Counter[str] = Counter()
    compact_response_hex: Counter[str] = Counter()
    compact_symbols: Counter[str] = Counter()
    post_1c_symbols: Counter[str] = Counter()
    unique_sequences: Counter[str] = Counter()
    unexpected = 0
    reader_enabled_ever = False
    active_sequence_response: str = ""
    active_sequence_followups: list[str] = []
    active_sequence_steps: list[str] = []
    sequence_has_summary = False
    sequence_compact_response_seen = False
    sequence_followup_after_compact = False
    sequence_fc_ack_seen = False
    sequence_1c_response_seen = False
    sequence_1c_old60_seen = False
    sequence_followup_after_1c_response = False
    standard_enable_seen = False

    def finish_sequence(reason: str) -> None:
        nonlocal active_sequence_steps
        if not active_sequence_steps:
            return
        compact_order = " -> ".join(active_sequence_steps + [reason])
        result.compact_orders.append(compact_order)
        unique_sequences[compact_order] += 1
        active_sequence_steps = []

    for record in scenario_records:
        event = event_name(record)
        data = details(record)
        if record.get("type") == "serial_text":
            continue
        if event == "jofemar_gateway_identify_seen":
            result.identify_seen_count += 1
            active_sequence_response = ""
            active_sequence_followups = []
            active_sequence_steps = ["19"]
            sequence_has_summary = False
            sequence_compact_response_seen = False
            sequence_followup_after_compact = False
            sequence_fc_ack_seen = False
            sequence_1c_response_seen = False
            sequence_1c_old60_seen = False
            sequence_followup_after_1c_response = False
        elif event == "jofemar_gateway_synthetic_suppressed":
            result.synthetic_suppressed_count += 1
        elif event == "jofemar_gateway_response_sent":
            result.gateway_response_sent_count += 1
            resp = str(data.get("response_hex") or "")
            if resp:
                response_hex[resp] += 1
                active_sequence_response = resp
                active_sequence_steps.append(resp)
                if resp not in result.first_tx_hex_values:
                    result.first_tx_hex_values.append(resp)
        elif event == "jofemar_gateway_compact_seen":
            result.compact_seen_count += 1
            symbol = str(data.get("symbol_kind") or "")
            if symbol:
                compact_symbols[symbol] += 1
                active_sequence_followups.append(symbol)
                active_sequence_steps.append(symbol)
                if symbol == "FC":
                    result.fc_seen_count += 1
                if symbol == "1C":
                    result.one_c_seen_count += 1
                if sequence_compact_response_seen:
                    sequence_followup_after_compact = True
                if sequence_1c_old60_seen:
                    sequence_followup_after_1c_response = True
                    result.post_1c_old60_followup_detected = True
                    result.followup_after_1c_old60_count += 1
                    post_1c_symbols[symbol] += 1
                elif sequence_1c_response_seen:
                    sequence_followup_after_1c_response = True
            resp = str(data.get("response_hex") or "")
            if resp:
                response_hex[resp] += 1
        elif event == "jofemar_gateway_compact_response_sent":
            result.compact_response_sent_count += 1
            sequence_compact_response_seen = True
            response_symbol = str(data.get("symbol_kind") or "")
            resp = str(data.get("response_hex") or "")
            if resp:
                response_hex[resp] += 1
                compact_response_hex[resp] += 1
                active_sequence_steps.append(resp)
            if response_symbol == "FC" and resp == "00":
                sequence_fc_ack_seen = True
                result.fc_ack_count += 1
            if response_symbol == "1C":
                sequence_1c_response_seen = True
                if resp == "60 60":
                    sequence_1c_old60_seen = True
                    result.one_c_old60_count += 1
        elif event == "jofemar_gateway_sequence_summary":
            result.sequence_summary_count += 1
            sequence_has_summary = True
            result.sequence_close_status = result.sequence_close_status or "summary"
            reason = str(data.get("close_reason") or "")
            if reason:
                close_reasons[reason] += 1
            first_tx = str(data.get("first_tx_hex") or active_sequence_response or "")
            if first_tx:
                result.first_tx_hex_values.append(first_tx)
            followups = str(data.get("followups_hex") or "")
            followup_parts = split_hex_sequence(followups)
            for symbol in active_sequence_followups:
                if symbol not in followup_parts:
                    followup_parts.append(symbol)
            if followups:
                result.followups_hex_values.append(followups)
            if first_tx.upper() == "60 60":
                if "FC" in followup_parts:
                    result.old60_fc_after_tx_samples += 1
                if sequence_fc_ack_seen:
                    result.old60_fc_ack_samples += 1
                if has_ordered_pair(followup_parts, "FC", "1C"):
                    result.old60_1c_after_fc_samples += 1
                if "FE" in followup_parts:
                    result.old60_fe_after_tx_samples += 1
                if has_ordered_pair(followup_parts, "FE", "1C"):
                    result.old60_1c_after_fe_samples += 1
                if sequence_followup_after_1c_response:
                    result.old60_followup_after_1c_response_samples += 1
            if sequence_compact_response_seen and (sequence_followup_after_compact or followup_parts):
                result.compact_response_then_followup_samples += 1
            finish_sequence(reason or "summary")
            if data.get("reset_seen") is True:
                result.reset_seen_count += 1
            if data.get("poll_seen") is True:
                result.poll_seen_count += 1
            if data.get("enable_seen") is True:
                result.enable_seen_count += 1
            if data.get("reader_enabled") is True:
                result.reader_enabled_seen = True
            if reason == "timeout":
                result.timeout_count += 1
            if reason == "new_gateway19":
                result.new_gateway19_count += 1
            sequence_compact_response_seen = False
            sequence_followup_after_compact = False
            sequence_fc_ack_seen = False
            sequence_1c_response_seen = False
            sequence_1c_old60_seen = False
            sequence_followup_after_1c_response = False
            active_sequence_followups = []
        elif event == "jofemar_gateway_reset_after_sequence":
            result.reset_seen_count += 1
            finish_sequence("reset")
        elif event == "jofemar_gateway_window_closed":
            result.window_closed_count += 1
            finish_sequence("window_closed")
        elif event == "runner_sequence_close":
            reason = str(data.get("close_reason") or "")
            if reason:
                close_reasons[reason] += 1
                result.sequence_close_status = reason
                finish_sequence(reason)
            result.sequence_close_wait_ms = max(
                result.sequence_close_wait_ms,
                int(data.get("sequence_close_wait_ms") or 0),
            )
        elif event == "jofemar_gateway_poll_seen":
            result.poll_seen_count += 1
            if sequence_1c_old60_seen:
                result.post_1c_old60_followup_detected = True
                result.followup_after_1c_old60_count += 1
                post_1c_symbols["POLL"] += 1
        elif event == "jofemar_gateway_enable_seen":
            result.enable_seen_count += 1
            standard_enable_seen = True
            if sequence_1c_old60_seen:
                result.post_1c_old60_followup_detected = True
                result.followup_after_1c_old60_count += 1
                post_1c_symbols["ENABLE"] += 1
        elif event == "cashless_init_sequence_summary":
            if data.get("poll_seen") is True:
                result.poll_seen_count += 1
            if data.get("enable_seen") is True:
                result.enable_seen_count += 1
                standard_enable_seen = True
            if data.get("reader_enabled") is True:
                result.reader_enabled_seen = True
        elif event in FAIL_EVENTS_SYNTHETIC:
            result.failures.append(f"unexpected {event}")
        elif event == "setup_response_frame_built" and result.gateway_mode not in {"real_setup_a", "real_setup_g"}:
            result.failures.append("setup_response_frame_built in non-unsafe mode")
        elif event and event not in {
            "command_received",
            "jofemar_gateway_identify_seen",
            "jofemar_gateway_synthetic_suppressed",
            "jofemar_gateway_response_sent",
            "jofemar_gateway_no_response",
            "jofemar_gateway_compact_seen",
            "jofemar_gateway_compact_response_sent",
            "jofemar_gateway_window_closed",
            "jofemar_gateway_sequence_summary",
            "jofemar_gateway_reset_after_sequence",
            "jofemar_gateway_poll_seen",
            "jofemar_gateway_enable_seen",
            "old_pre_reader_compact_noise_ignored",
            "old_pre_reader_compact_response_sent",
            "runner_sequence_close",
        }:
            unexpected += 1

        if sequence_1c_old60_seen and event not in {
            "jofemar_gateway_compact_seen",
            "jofemar_gateway_compact_response_sent",
            "jofemar_gateway_sequence_summary",
            "jofemar_gateway_window_closed",
            "runner_sequence_close",
            "command_received",
        }:
            raw_followup = str(
                data.get("raw_hex")
                or data.get("rx_hex")
                or data.get("frame_hex")
                or ""
            )
            if raw_followup:
                result.post_1c_old60_followup_detected = True
                result.followup_after_1c_old60_count += 1
                post_1c_symbols[raw_followup] += 1

        if has_reader_enabled(record):
            reader_enabled_ever = True
            result.reader_enabled_seen = True

    if active_sequence_steps:
        finish_sequence("open")

    guarded_reader_enabled = False
    for record in guarded_records:
        event = event_name(record)
        if event == "coin_payment_completed" and not guarded_reader_enabled:
            result.critical_failures.append("coin_payment_completed while reader_enabled=false")
        elif event in CREDIT_TX_EVENTS and not guarded_reader_enabled:
            result.critical_failures.append(f"{event} while reader_enabled=false")
        if has_reader_enabled(record):
            guarded_reader_enabled = True

    has_sequence_close = bool(sequence_has_summary or result.window_closed_count > 0 or result.sequence_close_status)
    if result.identify_seen_count > 0 and not has_sequence_close:
        result.warnings.append("identify/response observed but no sequence_summary")
        result.sequence_close_status = "missing_summary"
        close_reasons["missing_summary"] += 1
        if active_sequence_response and active_sequence_response not in result.first_tx_hex_values:
            result.first_tx_hex_values.append(active_sequence_response)

    result.close_reason_counts = dict(close_reasons)
    if not result.sequence_close_status:
        if result.sequence_summary_count > 0:
            result.sequence_close_status = "summary"
        elif result.window_closed_count > 0:
            result.sequence_close_status = "window_closed"
        else:
            result.sequence_close_status = "none"
    result.response_hex_counts = dict(response_hex)
    result.compact_response_hex_counts = dict(compact_response_hex)
    result.compact_symbol_counts = dict(compact_symbols)
    result.followup_after_1c_old60_symbols = dict(post_1c_symbols)
    result.unique_sequences = dict(unique_sequences)
    result.compact_orders = sorted(set(result.compact_orders))
    result.raw_unexpected_events_count = unexpected
    result.first_tx_hex_values = sorted(set(result.first_tx_hex_values))
    result.followups_hex_values = sorted(set(result.followups_hex_values))
    result.failures.extend(command_errors(scenario_records))

    if result.gateway_mode == "passive":
        if result.first_tx_hex_values and result.compact_response_sent_count == 0:
            result.failures.append("passive mode produced first_tx_hex during scenario")
        if result.gateway_response_sent_count > 0:
            result.failures.append("passive mode sent jofemar_gateway_response during scenario")

    for record in records:
        if record.get("runner_phase") == PHASE_SCENARIO:
            continue
        event = event_name(record)
        if result.gateway_mode == "passive" and event == "jofemar_gateway_response_sent":
            result.warnings.append("pre-scenario passive contamination response ignored")

    if any(
        record.get("runner_phase") == PHASE_SCENARIO
        and "11 03 01 00 15" in str(record.get("raw_line") or "")
        and "synthetic_suppressed" not in str(record.get("raw_line") or "")
        for record in records
    ):
        result.failures.append("synthetic 11 03 01 00 15 appeared outside suppression log")

    if result.reader_enabled_seen and not (result.enable_seen_count > 0 or standard_enable_seen):
        result.critical_failures.append("reader_enabled=true without enable_seen / standard Reader Enable evidence")

    if result.identify_seen_count >= require_samples:
        result.sample_quality = "good"
    elif result.identify_seen_count > 0:
        result.sample_quality = "weak"
    else:
        result.sample_quality = "none"
        result.warnings.append("no gateway identify observed during hard timeout")

    result.score = score_result(result)
    if result.critical_failures:
        result.status = "FAIL_CRITICAL"
    elif result.failures:
        result.status = "FAIL"
    elif result.identify_seen_count == 0 and result.sequence_summary_count == 0:
        result.status = "NO_SAMPLE"
        result.score = None
    elif (
        result.reader_enabled_seen
        or result.enable_seen_count > 0
        or result.poll_seen_count > 0
        or (
            result.scenario == "old60_fc_ack_1c_old60_long"
            and result.post_1c_old60_followup_detected
        )
    ):
        result.status = "PROGRESS"
    else:
        result.status = "NO_PROGRESS"


def score_result(result: ScenarioResult) -> int:
    score = 0
    if result.reader_enabled_seen:
        score += 1000
    if result.enable_seen_count > 0:
        score += 500
    if result.poll_seen_count > 0:
        score += 250
    if result.compact_seen_count > 0:
        score += 50
    if result.followups_hex_values:
        score += 20
    score -= 100 * result.reset_seen_count
    score -= 50 * result.timeout_count
    score -= 500 * len(result.failures)
    score -= 5000 * len(result.critical_failures)
    score += 100 * result.old60_fe_after_tx_samples
    score += 100 * result.old60_1c_after_fe_samples
    score += 200 * result.compact_response_then_followup_samples
    if result.scenario == "old60_fc_ack_1c_old60_long":
        score += 100 * result.gateway_response_sent_count
        score += 200 * result.old60_fc_after_tx_samples
        score += 200 * result.old60_fc_ack_samples
        score += 300 * result.old60_1c_after_fc_samples
        score += 300 * result.one_c_old60_count
        score += 500 * result.followup_after_1c_old60_count
        if result.poll_seen_count > 0:
            score += 1000
        if result.enable_seen_count > 0:
            score += 1500
        if result.reader_enabled_seen:
            score += 3000
    if result.scenario.startswith("old60_fc_ack_1c_"):
        score += 100 * result.old60_fc_after_tx_samples
        score += 150 * result.old60_fc_ack_samples
        score += 200 * result.old60_1c_after_fc_samples
        score += 300 * result.old60_followup_after_1c_response_samples
    if result.poll_seen_count > 0:
        score += 500
    if result.enable_seen_count > 0:
        score += 700
    if result.reader_enabled_seen:
        score += 1000
    return score


def scenario_file_name(scenario: Scenario) -> str:
    return f"raw_{scenario.name}.jsonl"


def run_scenario(conn: SerialConsole, scenario: Scenario, args: argparse.Namespace, run_dir: Path) -> ScenarioResult:
    scenario_log = run_dir / scenario_file_name(scenario)
    result = ScenarioResult(
        scenario=scenario.name,
        gateway_mode=scenario.gateway_mode,
        compact_response_mode=scenario.compact_response_mode,
        fc_response_mode=scenario.fc_response_mode,
        fe_response_mode=scenario.fe_response_mode,
        one_c_response_mode=scenario.one_c_response_mode,
        e0_response_mode=scenario.e0_response_mode,
        started_at=datetime.now().isoformat(timespec="seconds"),
    )
    log(f"=== {scenario.name}: gateway={scenario.gateway_mode} compact={scenario.compact_response_mode} ===", True)
    start = time.monotonic()
    all_records: list[dict[str, Any]] = []
    all_records.extend(arm_scenario(conn, scenario, result, scenario_log, args))

    scenario_records: list[dict[str, Any]] = []
    active_sequence = False
    active_sequence_started_at = 0.0
    last_identify_at = 0.0
    sequence_close_started_at = 0.0
    sequence_close_status = ""
    identify_count = 0
    summary_count = 0
    hard_deadline = time.monotonic() + args.hard_timeout

    def add_runner_close(reason: str) -> None:
        nonlocal active_sequence, sequence_close_status
        wait_ms = int((time.monotonic() - sequence_close_started_at) * 1000) if sequence_close_started_at else 0
        record = make_runner_event(
            "runner_sequence_close",
            PHASE_SCENARIO,
            {
                "close_reason": reason,
                "sequence_close_wait_ms": wait_ms,
            },
        )
        append_jsonl(conn.raw_all_path, [record])
        append_jsonl(scenario_log, [record])
        scenario_records.append(record)
        all_records.append(record)
        result.warnings.append(reason)
        active_sequence = False
        sequence_close_status = reason

    while time.monotonic() < hard_deadline:
        chunk = conn.read_records(min(0.2, max(0.0, hard_deadline - time.monotonic())), PHASE_SCENARIO)
        if chunk:
            append_jsonl(scenario_log, chunk)
            scenario_records.extend(chunk)
            all_records.extend(chunk)
            for record in chunk:
                event = event_name(record)
                if event == "jofemar_gateway_identify_seen":
                    active_sequence = True
                    active_sequence_started_at = time.monotonic()
                    sequence_close_started_at = active_sequence_started_at
                    last_identify_at = active_sequence_started_at
                    identify_count += 1
                    sequence_close_status = "active"
                elif event == "jofemar_gateway_sequence_summary":
                    summary_count += 1
                    if active_sequence:
                        active_sequence = False
                        sequence_close_status = "summary"
                        result.sequence_close_wait_ms = int((time.monotonic() - sequence_close_started_at) * 1000)
                elif event == "jofemar_gateway_window_closed":
                    if active_sequence:
                        add_runner_close("window_closed_without_summary")

        if active_sequence and time.monotonic() - active_sequence_started_at >= args.sequence_close_timeout:
            add_runner_close("sequence_close_timeout")

        if active_sequence:
            continue

        if (
            identify_count >= args.require_samples
            or summary_count >= args.max_sequences
            or progress_seen(scenario_records)
        ):
            break

    post = conn.read_records(2.5, PHASE_POST)
    attached = 0
    if identify_count > summary_count:
        attached = attach_late_summary(post)
        if attached:
            summary_count += attached
            result.post_scenario_attached_summary_count = attached
            result.warnings.append(f"attached {attached} late sequence_summary from post_scenario_drain")
            if sequence_close_status in {"", "active", "sequence_close_timeout"}:
                sequence_close_status = "late_summary"
    if not attached:
        for record in post:
            if event_name(record) in CONTAMINATION_EVENTS:
                result.contamination_warnings.append(
                    f"{PHASE_POST} saw stale {event_name(record)}: {details(record)}"
                )
    append_jsonl(scenario_log, post)
    all_records.extend(post)

    if last_identify_at and sequence_close_status in {"", "active"}:
        add_runner_close("sequence_close_timeout")
        sequence_close_status = "sequence_close_timeout"

    result.sequence_close_status = sequence_close_status or "none"

    if args.pay_negative_test and not any(has_reader_enabled(record) for record in scenario_records):
        result.pay_negative_test_ran = True
        pay_records, warnings = run_pay_negative_test(conn, scenario_log, args)
        all_records.extend(pay_records)
        result.warnings.extend(warnings)
        result.pay_negative_test_skipped = bool(warnings)

    result.duration_sec = round(time.monotonic() - start, 3)
    analyze_result(result, all_records, args.require_samples)
    score_text = "None" if result.score is None else str(result.score)
    print(
        f"[{scenario.name}] gateway={scenario.gateway_mode} compact={scenario.compact_response_mode} "
        f"score={score_text} status={result.status} sample={result.sample_quality} "
        f"identify={result.identify_seen_count} summaries={result.sequence_summary_count} "
        f"poll={result.poll_seen_count} enable={result.enable_seen_count} reader={result.reader_enabled_seen}",
        flush=True,
    )
    return result


def build_scenarios(args: argparse.Namespace) -> list[Scenario]:
    if args.profile == "old60-compact-sweep":
        return [Scenario(name, gateway, compact) for name, gateway, compact in OLD60_COMPACT_SWEEP_SCENARIOS]
    if args.profile == "old60-fc-ack-1c-sweep":
        return [
            Scenario(name, gateway, compact, fc, fe, one_c, e0)
            for name, gateway, compact, fc, fe, one_c, e0
            in OLD60_FC_ACK_1C_SWEEP_SCENARIOS
        ]
    if args.profile in {"old60-fc-ack-1c-old60-long", "best-known"}:
        return [
            Scenario(name, gateway, compact, fc, fe, one_c, e0)
            for name, gateway, compact, fc, fe, one_c, e0
            in OLD60_FC_ACK_1C_OLD60_LONG_SCENARIOS
        ]

    if args.only:
        by_symbol_name = {
            name: (gateway, compact, fc, fe, one_c, e0)
            for name, gateway, compact, fc, fe, one_c, e0
            in OLD60_FC_ACK_1C_SWEEP_SCENARIOS + OLD60_FC_ACK_1C_OLD60_LONG_SCENARIOS
        }
        if args.only in by_symbol_name:
            gateway, compact, fc, fe, one_c, e0 = by_symbol_name[args.only]
            return [Scenario(args.only, args.gateway_mode or gateway,
                             args.compact_response_mode or compact,
                             fc, fe, one_c, e0)]
        by_name = {name: (gateway, compact, False) for name, gateway, compact in DEFAULT_SCENARIOS}
        by_name.update({name: (gateway, compact, True) for name, gateway, compact in UNSAFE_SCENARIOS})
        by_name.update({name: (gateway, compact, False) for name, gateway, compact in OLD60_COMPACT_SWEEP_SCENARIOS})
        if args.only in by_name:
            gateway, compact, unsafe = by_name[args.only]
            return [Scenario(args.only, args.gateway_mode or gateway, args.compact_response_mode or compact, unsafe)]
        if not args.gateway_mode or not args.compact_response_mode:
            raise SystemExit("--only with a custom name requires --gateway-mode and --compact-response-mode")
        return [Scenario(args.only, args.gateway_mode, args.compact_response_mode)]

    scenarios = [Scenario(name, gateway, compact) for name, gateway, compact in DEFAULT_SCENARIOS]
    if args.include_unsafe:
        scenarios.extend(Scenario(name, gateway, compact, unsafe=True) for name, gateway, compact in UNSAFE_SCENARIOS)
    return scenarios


def sort_score(result: ScenarioResult) -> int:
    return -10**9 if result.score is None else result.score


def write_summary_csv(path: Path, results: list[ScenarioResult]) -> None:
    fields = [
        "scenario", "gateway_mode", "compact_response_mode", "status", "sample_quality",
        "fc_response_mode", "fe_response_mode", "one_c_response_mode", "e0_response_mode",
        "score", "identify_seen_count", "sequence_summary_count", "first_tx_hex_values",
        "response_hex_counts", "compact_response_hex_counts", "followups_hex_values",
        "compact_symbol_counts", "old60_fe_after_tx_samples", "old60_1c_after_fe_samples",
        "compact_response_then_followup_samples", "old60_fc_after_tx_samples",
        "old60_fc_ack_samples", "old60_1c_after_fc_samples",
        "old60_followup_after_1c_response_samples", "fc_seen_count",
        "fc_ack_count", "one_c_seen_count", "one_c_old60_count",
        "followup_after_1c_old60_count", "followup_after_1c_old60_symbols",
        "post_1c_old60_followup_detected", "unique_sequences", "compact_orders",
        "reset_seen_count", "poll_seen_count",
        "enable_seen_count", "reader_enabled_seen", "close_reason_counts",
        "sequence_close_status", "sequence_close_wait_ms", "window_closed_count",
        "post_scenario_attached_summary_count", "warnings",
    ]
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fields)
        writer.writeheader()
        for result in results:
            row = asdict(result)
            for key in (
                "first_tx_hex_values", "followups_hex_values", "close_reason_counts",
                "response_hex_counts", "compact_response_hex_counts", "compact_symbol_counts",
                "followup_after_1c_old60_symbols", "unique_sequences", "compact_orders",
                "warnings",
            ):
                row[key] = compact_json(row[key])
            writer.writerow({field: row.get(field, "") for field in fields})


def render_report(args: argparse.Namespace, scenarios: list[Scenario], results: list[ScenarioResult]) -> str:
    sorted_results = sorted(results, key=sort_score, reverse=True)
    lines: list[str] = []
    lines.append("# Jofemar / MDB Gateway FSM Auto Test")
    lines.append("")
    lines.append(f"- Date: {now_label()}")
    lines.append(f"- Serial port: `{args.port}`")
    lines.append(f"- Baud: `{args.baud}`")
    lines.append(f"- Profile: `{args.profile}`")
    lines.append(f"- Require samples: `{args.require_samples}`")
    lines.append(f"- Scenario timeout: `{args.scenario_timeout}s`")
    lines.append(f"- Hard timeout: `{args.hard_timeout}s`")
    lines.append(f"- Sequence close timeout: `{args.sequence_close_timeout}s`")
    lines.append(f"- Manual power-cycle: `{args.manual_power_cycle}`")
    lines.append("")
    lines.append("## Scenarios")
    lines.append("")
    for scenario in scenarios:
        unsafe = " unsafe" if scenario.unsafe else ""
        lines.append(f"- `{scenario.name}`: gateway `{scenario.gateway_mode}`, compact `{scenario.compact_response_mode}`{unsafe}")
    lines.append("")
    lines.append("## Results")
    lines.append("")
    lines.append("| scenario | gateway_mode | compact_response_mode | status | sample_quality | score | identify_seen | sequence_summary_count | sequence_close_status | sequence_close_wait_ms | window_closed_count | post_attached_summary | first_tx_hex | response_hex_counts | followups | close_reasons | warnings |")
    lines.append("|---|---|---|---|---|---:|---:|---:|---|---:|---:|---:|---|---|---|---|---|")
    for result in sorted_results:
        score = "" if result.score is None else str(result.score)
        lines.append(
            f"| {result.scenario} | {result.gateway_mode} | {result.compact_response_mode} | "
            f"{result.status} | {result.sample_quality} | {score} | "
            f"{result.identify_seen_count} | {result.sequence_summary_count} | "
            f"{result.sequence_close_status} | {result.sequence_close_wait_ms} | "
            f"{result.window_closed_count} | {result.post_scenario_attached_summary_count} | "
            f"`{', '.join(result.first_tx_hex_values)}` | `{compact_json(result.response_hex_counts)}` | "
            f"`{', '.join(result.followups_hex_values)}` | `{compact_json(result.close_reason_counts)}` | "
            f"{'; '.join(result.warnings)} |"
        )
    lines.append("")
    if args.profile == "old60-compact-sweep":
        lines.append("## Old60 Compact Sweep")
        lines.append("")
        lines.append("| scenario | compact_response_mode | samples | first_tx_hex | followups_hex | compact_symbol_counts | compact_response_hex_counts | reset_seen | poll_seen | enable_seen | reader_enabled | close_reasons | score |")
        lines.append("|---|---|---:|---|---|---|---|---:|---:|---:|---|---|---:|")
        for result in sorted_results:
            score = "" if result.score is None else str(result.score)
            lines.append(
                f"| {result.scenario} | {result.compact_response_mode} | {result.identify_seen_count} | "
                f"`{', '.join(result.first_tx_hex_values)}` | `{', '.join(result.followups_hex_values)}` | "
                f"`{compact_json(result.compact_symbol_counts)}` | `{compact_json(result.compact_response_hex_counts)}` | "
                f"{result.reset_seen_count} | {result.poll_seen_count} | {result.enable_seen_count} | "
                f"{result.reader_enabled_seen} | `{compact_json(result.close_reason_counts)}` | {score} |"
            )
        lines.append("")
    if args.profile == "old60-fc-ack-1c-sweep":
        lines.append("## Old60 FC ACK 1C Sweep")
        lines.append("")
        lines.append("| scenario | fc_response_mode | one_c_response_mode | identify_seen | first_tx_hex | followups_hex | compact_symbol_counts | compact_response_hex_counts | reset_seen | poll_seen | enable_seen | reader_enabled | close_reasons | score |")
        lines.append("|---|---|---|---:|---|---|---|---|---:|---:|---:|---|---|---:|")
        for result in sorted_results:
            score = "" if result.score is None else str(result.score)
            lines.append(
                f"| {result.scenario} | {result.fc_response_mode} | {result.one_c_response_mode} | "
                f"{result.identify_seen_count} | `{', '.join(result.first_tx_hex_values)}` | "
                f"`{', '.join(result.followups_hex_values)}` | `{compact_json(result.compact_symbol_counts)}` | "
                f"`{compact_json(result.compact_response_hex_counts)}` | {result.reset_seen_count} | "
                f"{result.poll_seen_count} | {result.enable_seen_count} | {result.reader_enabled_seen} | "
                f"`{compact_json(result.close_reason_counts)}` | {score} |"
            )
        lines.append("")
    if args.profile in {"old60-fc-ack-1c-old60-long", "best-known"}:
        result = sorted_results[0] if sorted_results else None
        lines.append("## Best Known Long Profile")
        lines.append("")
        if result:
            lines.append("| metric | value |")
            lines.append("|---|---|")
            lines.append(f"| total_samples | {result.identify_seen_count} |")
            lines.append(f"| identify_seen_count | {result.identify_seen_count} |")
            lines.append(f"| gateway_response_sent_count | {result.gateway_response_sent_count} |")
            lines.append(f"| fc_seen_count | {result.fc_seen_count} |")
            lines.append(f"| fc_ack_count | {result.fc_ack_count} |")
            lines.append(f"| one_c_seen_count | {result.one_c_seen_count} |")
            lines.append(f"| one_c_old60_count | {result.one_c_old60_count} |")
            lines.append(f"| followup_after_1c_old60_count | {result.followup_after_1c_old60_count} |")
            lines.append(f"| followup_after_1c_old60_symbols | `{compact_json(result.followup_after_1c_old60_symbols)}` |")
            lines.append(f"| reset_seen_count | {result.reset_seen_count} |")
            lines.append(f"| poll_seen_count | {result.poll_seen_count} |")
            lines.append(f"| enable_seen_count | {result.enable_seen_count} |")
            lines.append(f"| reader_enabled_seen | {result.reader_enabled_seen} |")
            lines.append(f"| close_reason_counts | `{compact_json(result.close_reason_counts)}` |")
            lines.append(f"| unique_sequences | `{compact_json(result.unique_sequences)}` |")
            lines.append("")
            lines.append("### Compact Orders")
            lines.append("")
            for order in result.compact_orders:
                lines.append(f"- `{order}`")
            lines.append("")
            lines.append("### Best Findings")
            lines.append("")
            lines.append(f"- post_1c_old60_followup_detected = `{result.post_1c_old60_followup_detected}`")
            if result.post_1c_old60_followup_detected:
                lines.append(f"- Followup symbols after `1C -> 60 60`: `{compact_json(result.followup_after_1c_old60_symbols)}`")
            elif result.poll_seen_count or result.enable_seen_count or result.reader_enabled_seen:
                lines.append("- Standard MDB progress was observed.")
            else:
                lines.append("- No byte after `1C -> 60 60` was observed in sampled sequences.")
        lines.append("")
    lines.append("## Best candidates")
    lines.append("")
    candidates = [
        result for result in sorted_results
        if result.status != "NO_SAMPLE" and (result.identify_seen_count > 0 or result.sequence_summary_count > 0)
    ][:5]
    if candidates:
        for result in candidates:
            lines.append(f"- `{result.scenario}` score `{result.score}` status `{result.status}` sample `{result.sample_quality}`")
    else:
        lines.append("- No sampled candidates.")
    lines.append("")
    lines.append("## Critical failures")
    lines.append("")
    criticals = [result for result in results if result.critical_failures]
    if criticals:
        for result in criticals:
            lines.append(f"- `{result.scenario}`: {'; '.join(result.critical_failures)}")
    else:
        lines.append("- None observed.")
    lines.append("")
    lines.append("## Invalid / no-sample scenarios")
    lines.append("")
    no_samples = [result for result in results if result.status == "NO_SAMPLE"]
    if no_samples:
        for result in no_samples:
            lines.append(f"- `{result.scenario}`: {'; '.join(result.warnings)}")
    else:
        lines.append("- None.")
    lines.append("")
    lines.append("## Runner contamination warnings")
    lines.append("")
    contaminated = [result for result in results if result.contamination_warnings]
    if contaminated:
        for result in contaminated:
            lines.append(f"- `{result.scenario}`")
            for warning in result.contamination_warnings[:20]:
                lines.append(f"  - {warning}")
    else:
        lines.append("- None.")
    lines.append("")
    lines.append("## Observed sequences")
    lines.append("")
    for result in sorted_results:
        lines.append(f"- `{result.scenario}`: first_tx `{', '.join(result.first_tx_hex_values)}`, followups `{', '.join(result.followups_hex_values)}`, close `{compact_json(result.close_reason_counts)}`")
    return "\n".join(lines) + "\n"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Automated Jofemar / MDB Gateway FSM tester")
    parser.add_argument("--port", required=True, help="serial port, e.g. /dev/ttyUSB0 or /dev/ttyACM0")
    parser.add_argument("--baud", type=int, default=115200)
    parser.add_argument("--out-dir", default="./jofemar_test_runs")
    parser.add_argument("--scenario-timeout", type=float, default=15.0)
    parser.add_argument("--hard-timeout", type=float, default=60.0)
    parser.add_argument("--sequence-close-timeout", type=float, default=5.0)
    parser.add_argument("--max-sequences", type=int, default=5)
    parser.add_argument("--require-samples", type=int, default=3)
    parser.add_argument("--settle-ms", type=int, default=500)
    parser.add_argument(
        "--profile",
        choices=[
            "default",
            "old60-compact-sweep",
            "old60-fc-ack-1c-sweep",
            "old60-fc-ack-1c-old60-long",
            "best-known",
        ],
        default="default",
        help="scenario profile to run",
    )
    parser.add_argument("--include-unsafe", action="store_true")
    parser.add_argument("--pay-negative-test", action="store_true")
    parser.add_argument("--manual-power-cycle", action="store_true")
    parser.add_argument("--only", default="", help="run one named scenario or custom scenario name")
    parser.add_argument("--gateway-mode", default="", help="override gateway mode for --only")
    parser.add_argument("--compact-response-mode", default="", help="override compact mode for --only")
    parser.add_argument("--device-id", default="")
    parser.add_argument("--verbose", action="store_true")
    return parser.parse_args()


def write_outputs(run_dir: Path, args: argparse.Namespace, scenarios: list[Scenario], results: list[ScenarioResult]) -> None:
    sorted_results = sorted(results, key=sort_score, reverse=True)
    summary = {
        "started_at": now_label(),
        "port": args.port,
        "baud": args.baud,
        "device_id": args.device_id,
        "profile": args.profile,
        "scenario_timeout": args.scenario_timeout,
        "hard_timeout": args.hard_timeout,
        "sequence_close_timeout": args.sequence_close_timeout,
        "max_sequences": args.max_sequences,
        "require_samples": args.require_samples,
        "include_unsafe": args.include_unsafe,
        "pay_negative_test": args.pay_negative_test,
        "manual_power_cycle": args.manual_power_cycle,
        "scenarios": [asdict(scenario) for scenario in scenarios],
        "results": [asdict(result) for result in sorted_results],
    }
    (run_dir / "summary.json").write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    write_summary_csv(run_dir / "summary.csv", sorted_results)
    (run_dir / "report.md").write_text(render_report(args, scenarios, sorted_results), encoding="utf-8")


def main() -> int:
    args = parse_args()
    if args.hard_timeout < args.scenario_timeout:
        args.hard_timeout = args.scenario_timeout
    if args.profile in {"old60-compact-sweep", "old60-fc-ack-1c-sweep"} and args.require_samples < 5:
        args.require_samples = 5
    if args.profile in {"old60-fc-ack-1c-old60-long", "best-known"}:
        if args.require_samples < 20:
            args.require_samples = 20
        if args.scenario_timeout < 60:
            args.scenario_timeout = 60
        if args.hard_timeout < 600:
            args.hard_timeout = 600
        if args.sequence_close_timeout < 5:
            args.sequence_close_timeout = 5
    run_dir = Path(args.out_dir) / datetime.now().strftime("%Y%m%d_%H%M%S")
    run_dir.mkdir(parents=True, exist_ok=True)
    raw_all = run_dir / "raw_all.jsonl"
    scenarios = build_scenarios(args)
    results: list[ScenarioResult] = []

    try:
        conn = SerialConsole(args.port, args.baud, raw_all)
    except FileNotFoundError:
        print(f"Serial port not found: {args.port}", file=sys.stderr)
        return 2
    except SerialException as exc:
        print(f"Could not open serial port {args.port}: {exc}", file=sys.stderr)
        return 2

    try:
        conn.read_records(1.0, PHASE_PRE_ARM)
        for scenario in scenarios:
            results.append(run_scenario(conn, scenario, args, run_dir))
            write_outputs(run_dir, args, scenarios, results)
    except KeyboardInterrupt:
        print("\nInterrupted; writing partial summary...", file=sys.stderr)
    finally:
        conn.close()
        write_outputs(run_dir, args, scenarios, results)

    print(f"Wrote {run_dir / 'summary.json'}")
    print(f"Wrote {run_dir / 'summary.csv'}")
    print(f"Wrote {run_dir / 'report.md'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
