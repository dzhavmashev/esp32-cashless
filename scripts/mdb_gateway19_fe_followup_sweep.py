#!/usr/bin/env python3
"""Sweep gateway19 profile/FE-followup handshake modes over ESP32 USB serial.

The script only sends diagnostic USB commands and observes JSONL serial events.
It does not send pay commands and does not change firmware logic.
"""

from __future__ import annotations

import json
import time
import argparse
from dataclasses import asdict, dataclass, field
from datetime import datetime
from pathlib import Path
from typing import Any

import serial

DEFAULT_PORT = "/dev/ttyUSB0"
BAUD_RATE = 115200
SERIAL_TIMEOUT_S = 0.1
BOOT_WAIT_S = 8.0
MODE_APPLY_S = 1.0
OBSERVE_TIMEOUT_S = 90.0
DRAIN_BEFORE_TEST_S = 2.0
DRAIN_AFTER_COMMAND_S = 0.5
REBOOT_BETWEEN_SCENARIOS = False

PROFILES = [0, 1, 2]
FOLLOWUP_MODES = ["passthrough", "no_response", "ack", "ret", "nak", "just_reset_0b"]
FE_MODES = ["no_response", "ack", "ret", "nak", "just_reset_0b", "passthrough"]
FOCUSED_SCENARIOS = [(0, "just_reset_0b"), (1, "just_reset_0b"), (2, "ack")]
FOCUSED_CANDIDATE_MODES = ["just_reset_0b", "ack"]
COMPACT_FOCUSED_SCENARIOS = [
    (0, "just_reset_0b", "ack", "no_response", "no_response"),
    (0, "just_reset_0b", "no_response", "ack", "no_response"),
    (0, "just_reset_0b", "ack", "ack", "no_response"),
    (1, "ack", "ack", "no_response", "no_response"),
    (1, "ack", "just_reset_0b", "no_response", "no_response"),
    (2, "just_reset_0b", "no_response", "ack", "no_response"),
]
OUT_ROOT = Path.cwd() / "test_logs"

INTERESTING_EVENTS = {
    "gateway_compat_response_profile_changed",
    "gateway19_real_setup_response_sent",
    "gateway19_real_frame_seen",
    "gateway19_fe_followup_response_sent",
    "gateway19_compact_followup_response_sent",
    "gateway19_compact_followup_bypassed",
    "gateway19_followup_seen",
    "gateway_compat_sequence_event",
    "gateway_compat_sequence_summary",
    "gateway19_chain_reset_seen",
    "cashless_init_sequence_summary",
    "cashless_reset_received",
    "ACK_SENT",
    "mdb_fe_compat_poll_seen",
    "mdb_fe_no_pending_credit",
    "mdb_fe_idle_response_sent",
    "command_rejected",
    "usb_cmd_error",
}


def log(msg: str) -> None:
    print(f"[{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}] {msg}", flush=True)


def details(event: dict[str, Any] | None) -> dict[str, Any]:
    if not event:
        return {}
    d = event.get("details")
    return d if isinstance(d, dict) else {}


def event_name(event: dict[str, Any]) -> str:
    name = event.get("event")
    return name if isinstance(name, str) else ""


def is_mdb_event(obj: Any) -> bool:
    return isinstance(obj, dict) and obj.get("type") == "mdb_event" and isinstance(obj.get("event"), str)


def compact_json(obj: Any) -> str:
    return json.dumps(obj, ensure_ascii=False, separators=(",", ":"))


def make_reboot_command() -> str:
    return json.dumps({"command": "reboot", "payload": {}}, separators=(",", ":"))


@dataclass(frozen=True)
class Scenario:
    profile: int
    fe_mode: str
    one_c_mode: str = ""
    fc_mode: str = ""
    e0_mode: str = ""


@dataclass
class ScenarioResult:
    profile: int
    fe_mode: str
    one_c_mode: str = ""
    fc_mode: str = ""
    e0_mode: str = ""
    command_errors: list[str] = field(default_factory=list)
    profile_changed_event: dict[str, Any] | None = None
    setup_response_count: int = 0
    last_setup_frame_hex: str = ""
    last_setup_payload_hex: str = ""
    active_profile_index: int | None = None
    active_profile_id: str = ""
    currency_code_bytes_hex: str = ""
    response_time: int | None = None
    options: int | None = None
    fe_followup_response_count: int = 0
    fe_followup_response_hex_values: list[str] = field(default_factory=list)
    compact_followup_response_count: int = 0
    compact_followup_response_hex_values: list[str] = field(default_factory=list)
    compact_followup_symbols: list[str] = field(default_factory=list)
    compact_bypassed_count: int = 0
    first_followup_hex: str = ""
    sequence_hex: str = ""
    tx_sequence: str = ""
    last_rx_hex: str = ""
    last_tx_kind: str = ""
    reset_seen: bool = False
    poll_seen: bool = False
    enable_seen: bool = False
    reader_enabled: bool = False
    close_reason: str = ""
    conclusion_hint: str = ""
    cashless_reset_count: int = 0
    cashless_reset_count_after_setup: int = 0
    gateway19_chain_reset_seen_count: int = 0
    post_setup_events_5s: list[dict[str, Any]] = field(default_factory=list)
    post_setup_events_all: list[dict[str, Any]] = field(default_factory=list)
    seconds_after_setup_response: float = 0.0
    post_setup_any_rx_after_setup: bool = False
    post_setup_new_gateway19_seen: bool = False
    post_setup_reset_1010_seen: bool = False
    raw_event_count: int = 0
    duration_s: float = 0.0
    verdict: str = ""


class SerialJsonReader:
    def __init__(self, port: str) -> None:
        self.ser = serial.Serial(port, BAUD_RATE, timeout=SERIAL_TIMEOUT_S)
        self.ser.dtr = False
        self.ser.rts = False
        self._line_buf = bytearray()

    def close(self) -> None:
        self.ser.close()

    def send(self, command: str) -> None:
        self.ser.write((command + "\n").encode("utf-8"))
        self.ser.flush()

    def read_records(self, seconds: float) -> list[dict[str, Any]]:
        deadline = time.monotonic() + seconds
        records: list[dict[str, Any]] = []
        while time.monotonic() < deadline:
            data = self.ser.read(4096)
            if not data:
                continue
            self._line_buf.extend(data)
            while True:
                nl = self._line_buf.find(b"\n")
                if nl < 0:
                    if len(self._line_buf) > 64 * 1024:
                        self._line_buf.clear()
                    break
                raw = bytes(self._line_buf[:nl])
                del self._line_buf[: nl + 1]
                rec = self._parse_line(raw)
                if rec is not None:
                    records.append(rec)
        return records

    @staticmethod
    def _parse_line(raw: bytes) -> dict[str, Any] | None:
        text = raw.decode("utf-8", "replace").strip()
        if not text:
            return None
        if text.startswith("usb_cmd_error:"):
            return {
                "type": "plain_error",
                "event": "usb_cmd_error",
                "line": text,
                "ts_host": time.time(),
            }
        if not text.startswith("{"):
            return None
        try:
            obj = json.loads(text)
        except json.JSONDecodeError:
            return None
        if is_mdb_event(obj):
            obj.setdefault("ts_host", time.time())
            return obj
        return None


def write_records(path: Path, records: list[dict[str, Any]]) -> None:
    with path.open("a", encoding="utf-8") as f:
        for rec in records:
            f.write(compact_json(rec) + "\n")


def send_and_collect(conn: SerialJsonReader, command: str, log_path: Path) -> list[dict[str, Any]]:
    log(f"TX> {command}")
    conn.send(command)
    records = conn.read_records(DRAIN_AFTER_COMMAND_S)
    write_records(log_path, records)
    return records


def drain(conn: SerialJsonReader, seconds: float, log_path: Path | None = None) -> list[dict[str, Any]]:
    records = conn.read_records(seconds)
    if log_path is not None:
        write_records(log_path, records)
    return records


def command_error_lines(records: list[dict[str, Any]], command_names: set[str]) -> list[str]:
    errors: list[str] = []
    for rec in records:
        ev = event_name(rec)
        if ev == "usb_cmd_error":
            line = str(rec.get("line", "usb_cmd_error"))
            if any(cmd in line for cmd in command_names) or not command_names:
                errors.append(line)
        elif ev == "command_rejected":
            d = details(rec)
            cmd = str(d.get("command", ""))
            if cmd in command_names:
                errors.append(compact_json(rec))
    return errors


def apply_scenario_commands(conn: SerialJsonReader, result: ScenarioResult, log_path: Path) -> list[dict[str, Any]]:
    all_records: list[dict[str, Any]] = []
    commands = [
        "mdb_tx_invert_on",
        f"mdb_gateway_profile {result.profile}",
        f"gateway19_fe_followup_mode {result.fe_mode}",
    ]
    if result.one_c_mode:
        commands.append(f"gateway19_1c_followup_mode {result.one_c_mode}")
    if result.fc_mode:
        commands.append(f"gateway19_fc_followup_mode {result.fc_mode}")
    if result.e0_mode:
        commands.append(f"gateway19_e0_followup_mode {result.e0_mode}")

    for command in commands:
        records = send_and_collect(conn, command, log_path)
        all_records.extend(records)
    result.command_errors.extend(
        command_error_lines(
            all_records,
            {
                "mdb_gateway_profile",
                "gateway19_fe_followup_mode",
                "gateway19_1c_followup_mode",
                "gateway19_fc_followup_mode",
                "gateway19_e0_followup_mode",
            },
        )
    )
    return all_records


def summarize_events(
    result: ScenarioResult, records: list[dict[str, Any]], elapsed_s: float, scenario_end_ts: float
) -> None:
    events = [r for r in records if is_mdb_event(r) or event_name(r) == "usb_cmd_error"]
    result.raw_event_count = len(events)
    result.duration_s = round(elapsed_s, 3)

    setup_seen_index: int | None = None
    setup_markers: list[tuple[int, float]] = []
    last_setup_index: int | None = None
    last_setup_ts = 0.0
    last_summary: dict[str, Any] = {}

    for idx, rec in enumerate(events):
        ev = event_name(rec)
        d = details(rec)

        if ev == "gateway_compat_response_profile_changed":
            result.profile_changed_event = rec
        elif ev == "gateway19_real_setup_response_sent":
            if setup_seen_index is None:
                setup_seen_index = idx
            setup_ts = float(rec.get("ts_host", 0.0) or 0.0)
            setup_markers.append((idx, setup_ts))
            last_setup_index = idx
            last_setup_ts = setup_ts
            result.setup_response_count += 1
            result.last_setup_frame_hex = str(d.get("frame_hex") or result.last_setup_frame_hex)
            result.last_setup_payload_hex = str(d.get("payload_hex") or result.last_setup_payload_hex)
            result.active_profile_index = d.get("active_profile_index", result.active_profile_index)
            result.active_profile_id = str(d.get("active_profile_id") or result.active_profile_id)
            result.currency_code_bytes_hex = str(d.get("currency_code_bytes_hex") or result.currency_code_bytes_hex)
            result.response_time = d.get("response_time", result.response_time)
            result.options = d.get("options", result.options)
        elif ev == "gateway19_fe_followup_response_sent":
            result.fe_followup_response_count += 1
            response_hex = str(d.get("response_hex") or "")
            result.fe_followup_response_hex_values.append(response_hex)
        elif ev == "gateway19_compact_followup_response_sent":
            result.compact_followup_response_count += 1
            response_hex = str(d.get("response_hex") or "")
            symbol = str(d.get("symbol_kind") or "")
            result.compact_followup_response_hex_values.append(response_hex)
            if symbol:
                result.compact_followup_symbols.append(symbol)
        elif ev == "gateway19_compact_followup_bypassed":
            result.compact_bypassed_count += 1
        elif ev == "gateway_compat_sequence_summary":
            last_summary = d
        elif ev == "gateway19_chain_reset_seen":
            result.gateway19_chain_reset_seen_count += 1
        elif ev == "cashless_reset_received":
            result.cashless_reset_count += 1
            if setup_seen_index is not None and idx > setup_seen_index:
                result.cashless_reset_count_after_setup += 1
        elif ev in {"mdb_fe_compat_poll_seen", "mdb_fe_no_pending_credit", "mdb_fe_idle_response_sent"}:
            if setup_seen_index is not None and idx > setup_seen_index:
                result.poll_seen = True
        elif ev == "command_rejected":
            result.command_errors.extend(
                command_error_lines(
                    [rec],
                    {
                        "mdb_gateway_profile",
                        "gateway19_fe_followup_mode",
                        "gateway19_1c_followup_mode",
                        "gateway19_fc_followup_mode",
                        "gateway19_e0_followup_mode",
                    },
                )
            )
        elif ev == "usb_cmd_error":
            result.command_errors.extend(
                command_error_lines(
                    [rec],
                    {
                        "mdb_gateway_profile",
                        "gateway19_fe_followup_mode",
                        "gateway19_1c_followup_mode",
                        "gateway19_fc_followup_mode",
                        "gateway19_e0_followup_mode",
                    },
                )
            )

        if d.get("reader_enabled") is True:
            result.reader_enabled = True
        if setup_seen_index is not None and idx > setup_seen_index and (
            d.get("poll_seen") is True or d.get("event_kind") == "poll"
        ):
            result.poll_seen = True
        if d.get("enable_seen") is True or d.get("event_kind") == "enable":
            result.enable_seen = True

    if last_summary:
        result.first_followup_hex = str(last_summary.get("first_followup_hex") or result.first_followup_hex)
        result.sequence_hex = str(last_summary.get("sequence_hex") or result.sequence_hex)
        result.tx_sequence = str(last_summary.get("tx_sequence") or result.tx_sequence)
        result.last_rx_hex = str(last_summary.get("last_rx_hex") or result.last_rx_hex)
        result.last_tx_kind = str(last_summary.get("last_tx_kind") or result.last_tx_kind)
        result.reset_seen = bool(last_summary.get("reset_seen", result.reset_seen))
        if result.setup_response_count > 0:
            result.poll_seen = bool(last_summary.get("poll_seen", result.poll_seen))
        result.enable_seen = bool(last_summary.get("enable_seen", result.enable_seen))
        result.reader_enabled = bool(last_summary.get("reader_enabled", result.reader_enabled))
        result.close_reason = str(last_summary.get("close_reason") or "")
        result.conclusion_hint = str(last_summary.get("conclusion_hint") or "")

    if not result.first_followup_hex:
        followup = next((details(e).get("raw_hex") for e in events if event_name(e) == "gateway19_followup_seen"), "")
        result.first_followup_hex = str(followup or "")

    result.post_setup_events_5s = collect_post_setup_events(events, setup_markers)
    result.post_setup_events_all = collect_post_setup_events_after_last_setup(events, last_setup_index)
    if last_setup_ts > 0.0:
        result.seconds_after_setup_response = round(max(0.0, scenario_end_ts - last_setup_ts), 3)
    result.post_setup_any_rx_after_setup = any(
        post_setup_entry_is_rx(ev) for ev in result.post_setup_events_all
    )
    result.post_setup_new_gateway19_seen = result.close_reason == "new_gateway19" or any(
        ev.get("event") == "gateway19_real_frame_seen" for ev in result.post_setup_events_all
    )
    result.post_setup_reset_1010_seen = any(
        "10 10" in str(ev.get("raw_hex", "")) or ev.get("event") in {"cashless_reset_received", "gateway19_chain_reset_seen"}
        for ev in result.post_setup_events_all
    )
    result.command_errors = list(dict.fromkeys(result.command_errors))
    result.verdict = choose_verdict(result, meaningful_summary=bool(last_summary))


def choose_verdict(result: ScenarioResult, meaningful_summary: bool) -> str:
    if result.command_errors:
        return "FAIL_COMMAND_REJECTED"
    if result.setup_response_count == 0:
        return "INVALID_NO_SETUP"
    if result.reader_enabled:
        return "PASS_READER_ENABLED"
    if result.enable_seen:
        return "PASS_ENABLE_SEEN"
    if result.reset_seen or result.gateway19_chain_reset_seen_count > 0 or result.cashless_reset_count_after_setup > 0:
        return "FAIL_RESET"
    if result.poll_seen:
        return "MAYBE_POLL_AFTER_SETUP"
    if result.conclusion_hint == "no_progress":
        return "FAIL_NO_PROGRESS"
    if result.close_reason != "reset" and result.conclusion_hint != "no_progress":
        return "MAYBE_NO_RESET"
    return "FAIL_NO_PROGRESS"


def collect_post_setup_events(
    events: list[dict[str, Any]], setup_markers: list[tuple[int, float]]
) -> list[dict[str, Any]]:
    post_setup: list[dict[str, Any]] = []
    seen_keys: set[tuple[int, str, str, str]] = set()
    for setup_index, setup_ts in setup_markers:
        if setup_ts <= 0.0:
            continue
        window_end = setup_ts + 5.0
        for idx, rec in enumerate(events):
            if idx <= setup_index:
                continue
            ts = float(rec.get("ts_host", 0.0) or 0.0)
            if ts < setup_ts or ts > window_end:
                continue
            d = details(rec)
            entry = {
                "setup_index": setup_index,
                "event": event_name(rec),
                "raw_hex": str(d.get("raw_hex") or d.get("rx_hex") or d.get("last_rx_hex") or ""),
                "response_hex": str(d.get("response_hex") or d.get("tx_hex") or ""),
                "timestamp": ts,
            }
            key = (idx, entry["event"], entry["raw_hex"], entry["response_hex"])
            if key not in seen_keys:
                post_setup.append(entry)
                seen_keys.add(key)
    return post_setup


def post_setup_event_entry(setup_index: int, rec: dict[str, Any]) -> dict[str, Any]:
    d = details(rec)
    return {
        "setup_index": setup_index,
        "event": event_name(rec),
        "raw_hex": str(d.get("raw_hex") or d.get("rx_hex") or d.get("last_rx_hex") or ""),
        "response_hex": str(d.get("response_hex") or d.get("tx_hex") or ""),
        "timestamp": float(rec.get("ts_host", 0.0) or 0.0),
    }


def post_setup_entry_is_rx(entry: dict[str, Any]) -> bool:
    event = str(entry.get("event") or "")
    if event == "gateway_compat_sequence_summary":
        return False
    return event in {
        "gateway19_real_frame_seen",
        "gateway19_followup_seen",
        "gateway_compat_sequence_event",
        "gateway19_chain_reset_seen",
        "cashless_reset_received",
        "mdb_fe_compat_poll_seen",
        "mdb_fe_no_pending_credit",
        "mdb_fe_idle_response_sent",
        "gateway19_compact_followup_response_sent",
        "gateway19_compact_followup_bypassed",
    } and bool(entry.get("raw_hex"))


def collect_post_setup_events_after_last_setup(
    events: list[dict[str, Any]], last_setup_index: int | None
) -> list[dict[str, Any]]:
    if last_setup_index is None:
        return []
    out: list[dict[str, Any]] = []
    for idx, rec in enumerate(events):
        if idx <= last_setup_index:
            continue
        if event_name(rec) in INTERESTING_EVENTS:
            out.append(post_setup_event_entry(last_setup_index, rec))
    return out


def should_stop_early(records: list[dict[str, Any]], focused: bool) -> bool:
    setup_seen_index: int | None = None
    for idx, rec in enumerate(records):
        if event_name(rec) == "gateway19_real_setup_response_sent":
            setup_seen_index = idx

    for idx, rec in enumerate(records):
        ev = event_name(rec)
        d = details(rec)
        if d.get("reader_enabled") is True:
            return True
        if d.get("enable_seen") is True or d.get("event_kind") == "enable":
            return True
        if ev == "gateway19_chain_reset_seen":
            return True
        after_setup = setup_seen_index is not None and idx > setup_seen_index
        if after_setup and ev == "cashless_reset_received":
            return True
        if after_setup and d.get("reset_seen") is True:
            return True
        if ev == "gateway_compat_sequence_summary":
            if str(d.get("close_reason") or "") in {"reset", "new_gateway19"}:
                return True
    if focused:
        return False
    return False


def run_scenario(
    conn: SerialJsonReader,
    out_dir: Path,
    scenario: Scenario,
    reboot_between_scenarios: bool,
    focused: bool,
    observe_timeout_s: float,
    run_index: int = 1,
) -> ScenarioResult:
    result = ScenarioResult(
        profile=scenario.profile,
        fe_mode=scenario.fe_mode,
        one_c_mode=scenario.one_c_mode,
        fc_mode=scenario.fc_mode,
        e0_mode=scenario.e0_mode,
    )
    suffix = f"profile_{scenario.profile}__fe_{scenario.fe_mode}"
    if scenario.one_c_mode or scenario.fc_mode or scenario.e0_mode:
        suffix += (
            f"__1c_{scenario.one_c_mode or 'unset'}"
            f"__fc_{scenario.fc_mode or 'unset'}"
            f"__e0_{scenario.e0_mode or 'unset'}"
        )
    if run_index > 1:
        suffix += f"__run_{run_index}"
    log_path = out_dir / f"{suffix}.jsonl"
    log(
        f"=== profile={scenario.profile} fe={scenario.fe_mode} "
        f"1c={scenario.one_c_mode or '-'} fc={scenario.fc_mode or '-'} "
        f"e0={scenario.e0_mode or '-'} ==="
    )
    scenario_start = time.monotonic()
    collected: list[dict[str, Any]] = []

    if reboot_between_scenarios:
        send_and_collect(conn, make_reboot_command(), log_path)
        time.sleep(BOOT_WAIT_S)
        drain(conn, DRAIN_BEFORE_TEST_S)

    drain(conn, DRAIN_BEFORE_TEST_S)
    collected.extend(apply_scenario_commands(conn, result, log_path))
    time.sleep(MODE_APPLY_S)
    records = drain(conn, 0.0, log_path)
    collected.extend(records)

    deadline = time.monotonic() + observe_timeout_s
    while time.monotonic() < deadline:
        records = conn.read_records(min(SERIAL_TIMEOUT_S, max(0.0, deadline - time.monotonic())))
        if not records:
            continue
        write_records(log_path, records)
        collected.extend(records)
        if should_stop_early(collected, focused):
            break

    elapsed = time.monotonic() - scenario_start
    summarize_events(result, collected, elapsed, time.time())
    response = result.fe_followup_response_hex_values[0] if result.fe_followup_response_hex_values else ""
    print(
        f"[profile={scenario.profile} fe={scenario.fe_mode} "
        f"1c={scenario.one_c_mode or '-'} fc={scenario.fc_mode or '-'} "
        f"e0={scenario.e0_mode or '-'}] "
        f"setup={result.setup_response_count} first_followup={result.first_followup_hex} "
        f"response={response} "
        f"compact={result.compact_followup_response_count}/{result.compact_bypassed_count} "
        f"reset={result.reset_seen or result.cashless_reset_count_after_setup > 0 or result.gateway19_chain_reset_seen_count > 0} "
        f"poll={result.poll_seen} enable={result.enable_seen} reader={result.reader_enabled} "
        f"verdict={result.verdict}",
        flush=True,
    )
    return result


def render_report(
    results: list[ScenarioResult],
    port: str,
    single: bool,
    focused: bool,
    focused_candidates: bool,
    compact_focused: bool,
    reboot_between_scenarios: bool,
    observe_timeout_s: float,
) -> str:
    lines: list[str] = []
    lines.append("# MDB gateway19 FE follow-up sweep")
    lines.append("")
    lines.append(f"- Date: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    lines.append(f"- Port: `{port}`")
    lines.append(f"- Observe timeout: `{observe_timeout_s:.0f}s`")
    lines.append(f"- Single mode: `{single}`")
    lines.append(f"- Focused mode: `{focused}`")
    lines.append(f"- Focused candidates: `{focused_candidates}`")
    lines.append(f"- Compact focused: `{compact_focused}`")
    lines.append(f"- Reboot between scenarios: `{reboot_between_scenarios}`")
    lines.append("")
    lines.append("| Profile | FE mode | 1C mode | FC mode | E0 mode | Frame | FE response | Compact responses | Compact bypassed | Sequence | Reset | Poll | Enable | Reader | Close | Hint | Verdict |")
    lines.append("|---:|---|---|---|---|---|---|---|---:|---|---:|---:|---:|---:|---|---|---|")
    for r in results:
        fe_response = ",".join(x if x else "(none)" for x in r.fe_followup_response_hex_values) or ""
        compact_response = ",".join(
            f"{symbol}:{value if value else '(none)'}"
            for symbol, value in zip(r.compact_followup_symbols, r.compact_followup_response_hex_values)
        )
        lines.append(
            f"| {r.profile} | {r.fe_mode} | {r.one_c_mode} | {r.fc_mode} | {r.e0_mode} | "
            f"{r.last_setup_frame_hex} | {fe_response} | {compact_response} | "
            f"{r.compact_bypassed_count} | {r.sequence_hex} | "
            f"{r.reset_seen or r.cashless_reset_count_after_setup > 0 or r.gateway19_chain_reset_seen_count > 0} | "
            f"{r.poll_seen} | {r.enable_seen} | {r.reader_enabled} | {r.close_reason} | "
            f"{r.conclusion_hint} | {r.verdict} |"
        )
    lines.append("")

    if single and len(results) > 1:
        lines.append("## Repeats")
        lines.append("| run_index | setup | FE response | sequence | reset | poll | enable | reader | close | hint | verdict |")
        lines.append("|---:|---:|---|---|---:|---:|---:|---:|---|---|---|")
        for idx, r in enumerate(results, start=1):
            fe_response = ",".join(x if x else "(none)" for x in r.fe_followup_response_hex_values) or ""
            reset = r.reset_seen or r.cashless_reset_count_after_setup > 0 or r.gateway19_chain_reset_seen_count > 0
            lines.append(
                f"| {idx} | {r.setup_response_count} | {fe_response} | {r.sequence_hex} | "
                f"{reset} | {r.poll_seen} | {r.enable_seen} | {r.reader_enabled} | "
                f"{r.close_reason} | {r.conclusion_hint} | {r.verdict} |"
            )
        lines.append("")

    if focused:
        lines.append("## Post-setup first 5 seconds")
        for r in results:
            lines.append("")
            lines.append(f"### profile={r.profile} mode={r.fe_mode}")
            if not r.post_setup_events_5s:
                lines.append("_No events captured in the first 5 seconds after setup response._")
                continue
            lines.append("| Event | Raw hex | Response hex | Timestamp |")
            lines.append("|---|---|---|---:|")
            for ev in r.post_setup_events_5s:
                lines.append(
                    f"| {ev.get('event', '')} | {ev.get('raw_hex', '')} | "
                    f"{ev.get('response_hex', '')} | {ev.get('timestamp', 0):.3f} |"
                )
        lines.append("")

        maybe_no_reset = [r for r in results if r.verdict == "MAYBE_NO_RESET"]
        if maybe_no_reset:
            lines.append("## MAYBE_NO_RESET details")
            lines.append("| Profile | FE mode | Seconds after setup | Any RX after setup | New 19 | 10 10 reset |")
            lines.append("|---:|---|---:|---:|---:|---:|")
            for r in maybe_no_reset:
                lines.append(
                    f"| {r.profile} | {r.fe_mode} | {r.seconds_after_setup_response:.3f} | "
                    f"{r.post_setup_any_rx_after_setup} | {r.post_setup_new_gateway19_seen} | "
                    f"{r.post_setup_reset_1010_seen} |"
                )
            lines.append("")

        lines.append("## Post-setup interesting events")
        for r in results:
            lines.append("")
            lines.append(f"### profile={r.profile} mode={r.fe_mode}")
            if not r.post_setup_events_all:
                lines.append("_No interesting events captured after the last setup response._")
                continue
            lines.append("| Event | Raw hex | Response hex | Timestamp |")
            lines.append("|---|---|---|---:|")
            for ev in r.post_setup_events_all:
                lines.append(
                    f"| {ev.get('event', '')} | {ev.get('raw_hex', '')} | "
                    f"{ev.get('response_hex', '')} | {ev.get('timestamp', 0):.3f} |"
                )
        lines.append("")

    promising = [r for r in results if r.verdict.startswith("PASS_") or r.verdict.startswith("MAYBE_")]
    best = promising[0] if promising else None
    lines.append("## Итоги")
    if best:
        lines.append(f"- Лучший кандидат: profile={best.profile}, FE mode={best.fe_mode}, verdict={best.verdict}.")
    else:
        lines.append("- Лучший кандидат: не найден, PASS/MAYBE отсутствуют.")

    no_reset = [
        f"profile={r.profile} mode={r.fe_mode}"
        for r in results
        if not (r.reset_seen or r.cashless_reset_count_after_setup > 0 or r.gateway19_chain_reset_seen_count > 0)
    ]
    lines.append(f"- Сценарии без reset: {', '.join(no_reset) if no_reset else 'нет'}.")

    with_followup = [
        f"profile={r.profile} mode={r.fe_mode} first_followup={r.first_followup_hex}"
        for r in results
        if r.first_followup_hex
    ]
    lines.append(f"- Сценарии с first_followup_hex: {', '.join(with_followup) if with_followup else 'нет'}.")

    mode_scores: dict[str, int] = {}
    for r in results:
        score = 0
        if r.verdict.startswith("PASS_"):
            score += 100
        if r.verdict.startswith("MAYBE_"):
            score += 50
        if not (r.reset_seen or r.cashless_reset_count_after_setup > 0 or r.gateway19_chain_reset_seen_count > 0):
            score += 10
        if r.first_followup_hex:
            score += 3
        mode_scores[r.fe_mode] = mode_scores.get(r.fe_mode, 0) + score
    if mode_scores:
        best_mode = max(mode_scores, key=lambda m: mode_scores[m])
        lines.append(f"- Короткий вывод: наиболее перспективно выглядит FE mode `{best_mode}`.")
    else:
        lines.append("- Короткий вывод: данных для выбора FE mode нет.")
    return "\n".join(lines)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Sweep MDB gateway19 FE follow-up modes over ESP32 USB serial."
    )
    parser.add_argument("port", nargs="?", default=DEFAULT_PORT, help=f"serial port, default {DEFAULT_PORT}")
    parser.add_argument(
        "--focused",
        action="store_true",
        help="run only profile=0 just_reset_0b, profile=1 just_reset_0b, profile=2 ack; enables reboot per scenario",
    )
    parser.add_argument(
        "--focused-candidates",
        action="store_true",
        help="run candidate FE modes for every profile from 0 through the last configured profile; enables reboot per scenario",
    )
    parser.add_argument(
        "--compact-focused",
        action="store_true",
        help="run the six fixed gateway19 FE/1C/FC/E0 compact follow-up scenarios; enables reboot per scenario and defaults observe timeout to 180s",
    )
    parser.add_argument(
        "--single",
        action="store_true",
        help="run one scenario only; ignores focused and compact scenario sets",
    )
    parser.add_argument(
        "--repeat",
        type=int,
        default=1,
        help="repeat the --single scenario N times; each repeat reboots first",
    )
    parser.add_argument("--profile", type=int, choices=PROFILES, default=0)
    parser.add_argument("--fe", choices=FOLLOWUP_MODES, default="just_reset_0b")
    parser.add_argument("--one-c", dest="one_c", choices=FOLLOWUP_MODES, default="ack")
    parser.add_argument("--fc", choices=FOLLOWUP_MODES, default="no_response")
    parser.add_argument("--e0", choices=FOLLOWUP_MODES, default="no_response")
    parser.add_argument(
        "--observe-timeout",
        type=float,
        default=None,
        help=f"seconds to observe each scenario, default {OBSERVE_TIMEOUT_S:.0f}",
    )
    return parser.parse_args()


def build_repeat_aggregate(results: list[ScenarioResult]) -> dict[str, Any]:
    verdict_counts: dict[str, int] = {}
    reset_true_count = 0
    fe_response_count = 0
    reader_enabled_count = 0
    poll_seen_count = 0
    enable_seen_count = 0
    for r in results:
        reset = r.reset_seen or r.cashless_reset_count_after_setup > 0 or r.gateway19_chain_reset_seen_count > 0
        if reset:
            reset_true_count += 1
        if r.fe_followup_response_count > 0:
            fe_response_count += 1
        if r.reader_enabled:
            reader_enabled_count += 1
        if r.poll_seen:
            poll_seen_count += 1
        if r.enable_seen:
            enable_seen_count += 1
        verdict_counts[r.verdict] = verdict_counts.get(r.verdict, 0) + 1
    return {
        "repeat_count": len(results),
        "reset_false_count": len(results) - reset_true_count,
        "reset_true_count": reset_true_count,
        "fe_response_count": fe_response_count,
        "reader_enabled_count": reader_enabled_count,
        "poll_seen_count": poll_seen_count,
        "enable_seen_count": enable_seen_count,
        "verdict_counts": verdict_counts,
    }


def main() -> int:
    args = parse_args()
    port = args.port
    single = bool(args.single)
    focused_candidates = bool(args.focused_candidates)
    compact_focused = bool(args.compact_focused)
    focused = bool(single or args.focused or focused_candidates or compact_focused)
    repeat = int(args.repeat)
    if repeat < 1:
        raise SystemExit("--repeat must be >= 1")
    if repeat > 1 and not single:
        raise SystemExit("--repeat is only supported with --single")
    observe_timeout_s = float(180.0 if compact_focused and args.observe_timeout is None else (args.observe_timeout or OBSERVE_TIMEOUT_S))
    if observe_timeout_s <= 0:
        raise SystemExit("--observe-timeout must be > 0")
    reboot_between_scenarios = True if focused else REBOOT_BETWEEN_SCENARIOS
    if single:
        scenarios = [Scenario(args.profile, args.fe, args.one_c, args.fc, args.e0) for _ in range(repeat)]
    elif compact_focused:
        scenarios = [Scenario(*s) for s in COMPACT_FOCUSED_SCENARIOS]
    elif focused_candidates:
        scenarios = [Scenario(p, m) for p in PROFILES for m in FOCUSED_CANDIDATE_MODES]
    elif focused:
        scenarios = [Scenario(p, m) for p, m in FOCUSED_SCENARIOS]
    else:
        scenarios = [Scenario(p, m) for p in PROFILES for m in FE_MODES]
    stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    out_dir = OUT_ROOT / f"gateway19_fe_sweep_{stamp}"
    out_dir.mkdir(parents=True, exist_ok=True)

    log(f"connecting port={port} baud={BAUD_RATE}")
    conn = SerialJsonReader(port)
    try:
        drain(conn, DRAIN_BEFORE_TEST_S)
        results: list[ScenarioResult] = []
        for run_index, scenario in enumerate(scenarios, start=1):
            results.append(
                run_scenario(
                    conn,
                    out_dir,
                    scenario,
                    reboot_between_scenarios,
                    focused,
                    observe_timeout_s,
                    run_index,
                )
            )

        summary = {
            "port": port,
            "baud_rate": BAUD_RATE,
            "created_at": datetime.now().isoformat(timespec="seconds"),
            "settings": {
                "serial_timeout_s": SERIAL_TIMEOUT_S,
                "boot_wait_s": BOOT_WAIT_S,
                "mode_apply_s": MODE_APPLY_S,
                "observe_timeout_s": observe_timeout_s,
                "drain_before_test_s": DRAIN_BEFORE_TEST_S,
                "drain_after_command_s": DRAIN_AFTER_COMMAND_S,
                "reboot_between_scenarios": reboot_between_scenarios,
                "single": single,
                "repeat": repeat,
                "focused": focused,
                "focused_candidates": focused_candidates,
                "compact_focused": compact_focused,
            },
            "interesting_events": sorted(INTERESTING_EVENTS),
            "results": [asdict(r) for r in results],
        }
        if single:
            summary["aggregate"] = build_repeat_aggregate(results)
        summary_path = out_dir / "summary.json"
        report_path = out_dir / "report.md"
        summary_path.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        report_path.write_text(
            render_report(
                results,
                port,
                single,
                focused,
                focused_candidates,
                compact_focused,
                reboot_between_scenarios,
                observe_timeout_s,
            ) + "\n",
            encoding="utf-8",
        )
        log(f"summary: {summary_path}")
        log(f"report: {report_path}")
    finally:
        conn.close()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
