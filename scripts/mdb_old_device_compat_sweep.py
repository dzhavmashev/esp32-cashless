#!/usr/bin/env python3
"""Sweep old-device MDB compatibility modes over ESP32 USB serial.

The script enables mdb_old_device_compat, observes JSONL serial events, and
never sends pay commands.
"""

from __future__ import annotations

import argparse
import json
import time
from collections import Counter
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
OBSERVE_TIMEOUT_S = 180.0
DRAIN_BEFORE_TEST_S = 2.0
DRAIN_AFTER_COMMAND_S = 0.5
REBOOT_BETWEEN_SCENARIOS = True

RESET_MODES = ("ack", "fe", "no_response")
POLL_MODES = ("fe", "ff", "zero", "no_response")
ENABLE_MODES = ("ack", "no_response")
EXPANSION_MODES = ("no_response", "raw_replay")

SWEEP_SCENARIOS = [
    ("ack", "fe", "ack", "no_response"),
    ("fe", "fe", "ack", "no_response"),
    ("ack", "ff", "ack", "no_response"),
    ("ack", "zero", "ack", "no_response"),
    ("ack", "no_response", "ack", "no_response"),
    ("no_response", "fe", "ack", "no_response"),
]

OUT_ROOT = Path.cwd() / "test_logs"
OLD_COMPAT_COMMANDS = {
    "mdb_tx_invert_on",
    "mdb_old_device_compat_on",
    "old_reset_response_mode",
    "old_idle_poll_response_mode",
    "old_enable_response_mode",
    "old_expansion_response_mode",
}

INTERESTING_EVENTS = {
    "old_gateway19_ignored",
    "old_gateway19_seen",
    "old_reset_seen",
    "old_poll_seen",
    "old_setup_1100_response_sent",
    "old_setup_price_or_limits_seen",
    "old_expansion_1700_seen",
    "old_reader_enable_seen",
    "gateway19_real_setup_response_sent",
    "gateway19_fe_followup_response_sent",
    "gateway19_compact_followup_response_sent",
    "cashless_reset_received",
    "ACK_SENT",
    "mdb_raw_family_seen",
    "mdb_rx_classified",
    "command_rejected",
    "usb_cmd_error",
}


def log(message: str) -> None:
    print(f"[{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}] {message}", flush=True)


def compact_json(obj: Any) -> str:
    return json.dumps(obj, ensure_ascii=False, separators=(",", ":"))


def details(record: dict[str, Any] | None) -> dict[str, Any]:
    if not record:
        return {}
    value = record.get("details")
    return value if isinstance(value, dict) else {}


def event_name(record: dict[str, Any]) -> str:
    value = record.get("event")
    return value if isinstance(value, str) else ""


def is_json_event(obj: Any) -> bool:
    return isinstance(obj, dict) and isinstance(obj.get("event"), str)


def is_mdb_event(obj: Any) -> bool:
    return isinstance(obj, dict) and obj.get("type") == "mdb_event" and isinstance(obj.get("event"), str)


def make_reboot_command() -> str:
    return compact_json({"command": "reboot", "payload": {}})


@dataclass(frozen=True)
class Scenario:
    reset_mode: str
    poll_mode: str
    enable_mode: str
    expansion_mode: str
    run_index: int = 1


@dataclass
class ScenarioResult:
    reset_mode: str
    poll_mode: str
    enable_mode: str
    expansion_mode: str
    run_index: int = 1
    command_errors: list[str] = field(default_factory=list)
    old_gateway19_ignored_count: int = 0
    gateway19_response_sent_count: int = 0
    old_reset_seen_count: int = 0
    old_poll_seen_count: int = 0
    old_setup_1100_seen_count: int = 0
    old_setup_1100_response_count: int = 0
    old_setup_price_or_limits_seen_count: int = 0
    old_expansion_1700_seen_count: int = 0
    old_reader_enable_seen_count: int = 0
    reader_enabled: bool = False
    poll_seen: bool = False
    enable_seen: bool = False
    reset_seen: bool = False
    cashless_reset_count: int = 0
    ack_sent_count: int = 0
    last_old_reset_response_hex: str = ""
    last_old_poll_response_hex: str = ""
    last_old_setup_response_hex: str = ""
    last_old_enable_response_hex: str = ""
    first_old_flow_event: str = ""
    old_flow_sequence: str = ""
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
                newline = self._line_buf.find(b"\n")
                if newline < 0:
                    if len(self._line_buf) > 64 * 1024:
                        self._line_buf.clear()
                    break
                raw = bytes(self._line_buf[:newline])
                del self._line_buf[: newline + 1]
                record = self._parse_line(raw)
                if record is not None:
                    records.append(record)
        return records

    @staticmethod
    def _parse_line(raw: bytes) -> dict[str, Any] | None:
        text = raw.decode("utf-8", "replace").strip()
        if not text:
            return None
        if text.startswith("usb_cmd_error:"):
            return {"type": "plain_error", "event": "usb_cmd_error", "line": text, "ts_host": time.time()}
        if text.startswith("WS JSON parse failed"):
            return {"type": "plain_error", "event": "ws_json_parse_failed", "line": text, "ts_host": time.time()}
        if "command_rejected" in text and not text.startswith("{"):
            return {"type": "plain_error", "event": "command_rejected", "line": text, "ts_host": time.time()}
        if not text.startswith("{"):
            return None
        try:
            obj = json.loads(text)
        except json.JSONDecodeError:
            return None
        if is_json_event(obj):
            obj.setdefault("ts_host", time.time())
            return obj
        return None


def write_records(path: Path, records: list[dict[str, Any]]) -> None:
    with path.open("a", encoding="utf-8") as handle:
        for record in records:
            handle.write(compact_json(record) + "\n")


def drain(conn: SerialJsonReader, seconds: float, log_path: Path | None = None) -> list[dict[str, Any]]:
    records = conn.read_records(seconds)
    if log_path is not None:
        write_records(log_path, records)
    return records


def send_and_collect(conn: SerialJsonReader, command: str, log_path: Path) -> list[dict[str, Any]]:
    log(f"TX> {command}")
    conn.send(command)
    records = conn.read_records(DRAIN_AFTER_COMMAND_S)
    write_records(log_path, records)
    return records


def command_error_lines(records: list[dict[str, Any]], command_names: set[str]) -> list[str]:
    errors: list[str] = []
    for record in records:
        event = event_name(record)
        if event in {"usb_cmd_error", "ws_json_parse_failed"}:
            line = str(record.get("line", event))
            if any(command in line for command in command_names):
                errors.append(line)
        elif event == "command_rejected":
            data = details(record)
            command = str(data.get("command", ""))
            line = str(record.get("line", "")) or compact_json(record)
            if command in command_names or any(name in line for name in command_names):
                errors.append(line)
    return errors


def apply_scenario_commands(conn: SerialJsonReader, scenario: Scenario, log_path: Path) -> list[dict[str, Any]]:
    commands = [
        "mdb_tx_invert_on",
        "mdb_old_device_compat_on",
        f"old_reset_response_mode {scenario.reset_mode}",
        f"old_idle_poll_response_mode {scenario.poll_mode}",
        f"old_enable_response_mode {scenario.enable_mode}",
        f"old_expansion_response_mode {scenario.expansion_mode}",
    ]
    records: list[dict[str, Any]] = []
    for command in commands:
        records.extend(send_and_collect(conn, command, log_path))
    return records


def sequence_label(event: str, data: dict[str, Any]) -> str:
    if event in {"old_gateway19_ignored", "old_gateway19_seen"}:
        return "19_ignored"
    if event == "old_reset_seen":
        return "10_10"
    if event == "old_poll_seen":
        return "12"
    if event == "old_setup_1100_response_sent":
        return "11_00"
    if event == "old_setup_price_or_limits_seen":
        return "11_FF"
    if event == "old_expansion_1700_seen":
        return "17_00"
    if event == "old_reader_enable_seen":
        return "14_01_00"
    if event == "cashless_reset_received":
        return "reset"
    if data.get("reader_enabled") is True:
        return "reader_enabled"
    return ""


def summarize_events(result: ScenarioResult, records: list[dict[str, Any]], elapsed_s: float) -> None:
    events = [record for record in records if is_mdb_event(record) or event_name(record) in INTERESTING_EVENTS]
    sequence: list[str] = []
    first_old_flow_event = ""

    for record in events:
        event = event_name(record)
        data = details(record)
        label = sequence_label(event, data)
        if label:
            sequence.append(label)
            if not first_old_flow_event and label != "reader_enabled":
                first_old_flow_event = label

        if event in {"old_gateway19_ignored", "old_gateway19_seen"}:
            result.old_gateway19_ignored_count += 1
        elif event == "gateway19_real_setup_response_sent":
            result.gateway19_response_sent_count += 1
        elif event in {"gateway19_fe_followup_response_sent", "gateway19_compact_followup_response_sent"}:
            result.gateway19_response_sent_count += 1
        elif event == "old_reset_seen":
            result.old_reset_seen_count += 1
            result.reset_seen = True
            result.last_old_reset_response_hex = str(data.get("response_hex") or result.last_old_reset_response_hex)
        elif event == "old_poll_seen":
            result.old_poll_seen_count += 1
            result.poll_seen = True
            result.last_old_poll_response_hex = str(data.get("response_hex") or result.last_old_poll_response_hex)
        elif event == "old_setup_1100_response_sent":
            result.old_setup_1100_seen_count += 1
            result.old_setup_1100_response_count += 1
            result.last_old_setup_response_hex = str(data.get("response_hex") or result.last_old_setup_response_hex)
        elif event == "old_setup_price_or_limits_seen":
            result.old_setup_price_or_limits_seen_count += 1
        elif event == "old_expansion_1700_seen":
            result.old_expansion_1700_seen_count += 1
        elif event == "old_reader_enable_seen":
            result.old_reader_enable_seen_count += 1
            result.enable_seen = True
            result.reader_enabled = True
            result.last_old_enable_response_hex = str(data.get("response_hex") or result.last_old_enable_response_hex)
        elif event == "cashless_reset_received":
            result.cashless_reset_count += 1
        elif event == "ACK_SENT":
            result.ack_sent_count += 1

        if data.get("reader_enabled") is True:
            result.reader_enabled = True
            result.enable_seen = True
        if data.get("poll_seen") is True:
            result.poll_seen = True
        if data.get("enable_seen") is True:
            result.enable_seen = True

    result.raw_event_count = len(events)
    result.duration_s = round(elapsed_s, 3)
    result.command_errors = list(dict.fromkeys(command_error_lines(records, OLD_COMPAT_COMMANDS)))
    result.first_old_flow_event = first_old_flow_event
    result.old_flow_sequence = "->".join(sequence)
    result.verdict = choose_verdict(result)


def choose_verdict(result: ScenarioResult) -> str:
    if result.command_errors:
        return "FAIL_COMMAND_REJECTED"
    if result.gateway19_response_sent_count > 0:
        return "FAIL_GATEWAY19_RESPONSE_LEAK"
    if result.reader_enabled or result.old_reader_enable_seen_count > 0:
        return "PASS_READER_ENABLED"
    if result.old_reader_enable_seen_count > 0:
        return "PASS_ENABLE_SEEN"
    if result.old_setup_1100_response_count > 0 or result.old_expansion_1700_seen_count > 0:
        return "MAYBE_OLD_FLOW"
    if result.old_poll_seen_count >= 3 and not result.reset_seen:
        return "MAYBE_POLL_LOOP"
    if result.old_reset_seen_count >= 2 and result.old_poll_seen_count == 0:
        return "FAIL_RESET_LOOP"
    if (
        result.old_gateway19_ignored_count > 0
        and result.old_reset_seen_count == 0
        and result.old_poll_seen_count == 0
        and result.old_setup_1100_response_count == 0
    ):
        return "FAIL_NO_OLD_FLOW"
    if (
        result.old_gateway19_ignored_count == 0
        and result.old_reset_seen_count == 0
        and result.old_poll_seen_count == 0
        and result.old_setup_1100_response_count == 0
        and result.old_expansion_1700_seen_count == 0
        and result.old_reader_enable_seen_count == 0
    ):
        return "FAIL_TIMEOUT"
    return "FAIL_NO_OLD_FLOW"


def should_stop_early(records: list[dict[str, Any]]) -> bool:
    errors = command_error_lines(records, OLD_COMPAT_COMMANDS)
    if errors:
        return True
    for record in records:
        event = event_name(record)
        data = details(record)
        if event == "old_reader_enable_seen" or data.get("reader_enabled") is True:
            return True
        if event in {
            "gateway19_real_setup_response_sent",
            "gateway19_fe_followup_response_sent",
            "gateway19_compact_followup_response_sent",
        }:
            return True
    return False


def log_filename(scenario: Scenario, repeat_mode: bool) -> str:
    name = (
        f"reset_{scenario.reset_mode}__poll_{scenario.poll_mode}"
        f"__enable_{scenario.enable_mode}__exp_{scenario.expansion_mode}"
    )
    if repeat_mode:
        name += f"__run_{scenario.run_index}"
    return name + ".jsonl"


def run_scenario(
    conn: SerialJsonReader,
    out_dir: Path,
    scenario: Scenario,
    observe_timeout_s: float,
    repeat_mode: bool = False,
) -> ScenarioResult:
    result = ScenarioResult(
        reset_mode=scenario.reset_mode,
        poll_mode=scenario.poll_mode,
        enable_mode=scenario.enable_mode,
        expansion_mode=scenario.expansion_mode,
        run_index=scenario.run_index,
    )
    log_path = out_dir / log_filename(scenario, repeat_mode)
    log(
        "=== "
        f"reset={scenario.reset_mode} poll={scenario.poll_mode} "
        f"enable={scenario.enable_mode} expansion={scenario.expansion_mode} "
        f"run={scenario.run_index} ==="
    )

    scenario_start = time.monotonic()
    collected: list[dict[str, Any]] = []

    drain(conn, DRAIN_BEFORE_TEST_S)
    if REBOOT_BETWEEN_SCENARIOS:
        send_and_collect(conn, make_reboot_command(), log_path)
        time.sleep(BOOT_WAIT_S)
        drain(conn, DRAIN_BEFORE_TEST_S)

    collected.extend(apply_scenario_commands(conn, scenario, log_path))
    time.sleep(MODE_APPLY_S)
    collected.extend(drain(conn, 0.0, log_path))

    deadline = time.monotonic() + observe_timeout_s
    while time.monotonic() < deadline:
        records = conn.read_records(min(SERIAL_TIMEOUT_S, max(0.0, deadline - time.monotonic())))
        if not records:
            continue
        write_records(log_path, records)
        collected.extend(records)
        if should_stop_early(collected):
            break

    summarize_events(result, collected, time.monotonic() - scenario_start)
    print(
        f"[reset={result.reset_mode} poll={result.poll_mode} "
        f"enable={result.enable_mode} expansion={result.expansion_mode}] "
        f"19_ignored={result.old_gateway19_ignored_count} "
        f"reset={result.old_reset_seen_count} poll={result.old_poll_seen_count} "
        f"setup1100={result.old_setup_1100_response_count} "
        f"expansion1700={result.old_expansion_1700_seen_count} "
        f"enable140100={result.old_reader_enable_seen_count} "
        f"reader={result.reader_enabled} "
        f"gateway19_leak={result.gateway19_response_sent_count} "
        f"verdict={result.verdict}",
        flush=True,
    )
    return result


def best_candidates(results: list[ScenarioResult]) -> tuple[str, list[ScenarioResult]]:
    passes = [r for r in results if r.verdict in {"PASS_READER_ENABLED", "PASS_ENABLE_SEEN"}]
    if passes:
        return "PASS_READER_ENABLED / PASS_ENABLE_SEEN", passes
    maybe_flow = [r for r in results if r.verdict == "MAYBE_OLD_FLOW"]
    if maybe_flow:
        return "MAYBE_OLD_FLOW", maybe_flow
    maybe_poll = [r for r in results if r.verdict == "MAYBE_POLL_LOOP"]
    return "MAYBE_POLL_LOOP", maybe_poll


def scenario_label(result: ScenarioResult) -> str:
    suffix = f" run={result.run_index}" if result.run_index > 1 else ""
    return (
        f"reset={result.reset_mode}, poll={result.poll_mode}, "
        f"enable={result.enable_mode}, expansion={result.expansion_mode}{suffix}"
    )


def render_report(results: list[ScenarioResult], port: str, observe_timeout_s: float, single: bool, repeat: int) -> str:
    lines: list[str] = []
    lines.append("# MDB old-device compat sweep")
    lines.append("")
    lines.append(f"- Date: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    lines.append(f"- Port: `{port}`")
    lines.append(f"- Observe timeout: `{observe_timeout_s:.0f}s`")
    lines.append(f"- Single: `{single}`")
    lines.append(f"- Repeat: `{repeat}`")
    lines.append(f"- Reboot between scenarios: `{REBOOT_BETWEEN_SCENARIOS}`")
    lines.append("- Pay sent: `false`")
    lines.append("")
    lines.append(
        "| Reset mode | Poll mode | Enable mode | Expansion mode | 19 ignored | 10 10 | 12 poll | 11 00 | 17 00 | 14 01 00 | Reader | Gateway19 leak | Old sequence | Verdict |"
    )
    lines.append(
        "|---|---|---|---|---:|---:|---:|---:|---:|---:|---|---:|---|---|"
    )
    for result in results:
        lines.append(
            f"| {result.reset_mode} | {result.poll_mode} | {result.enable_mode} | "
            f"{result.expansion_mode} | {result.old_gateway19_ignored_count} | "
            f"{result.old_reset_seen_count} | {result.old_poll_seen_count} | "
            f"{result.old_setup_1100_response_count} | {result.old_expansion_1700_seen_count} | "
            f"{result.old_reader_enable_seen_count} | {result.reader_enabled} | "
            f"{result.gateway19_response_sent_count} | `{result.old_flow_sequence}` | "
            f"{result.verdict} |"
        )

    title, candidates = best_candidates(results)
    lines.append("")
    lines.append("## Best candidates")
    lines.append("")
    lines.append(f"- Selection tier: `{title}`")
    if candidates:
        for result in candidates:
            lines.append(f"- {scenario_label(result)}: `{result.verdict}`, sequence `{result.old_flow_sequence}`")
    else:
        lines.append("- No PASS/MAYBE candidates found.")

    lines.append("")
    lines.append("## Gateway19 leak check")
    lines.append("")
    leaks = [r for r in results if r.gateway19_response_sent_count > 0]
    if leaks:
        for result in leaks:
            lines.append(f"- CRITICAL: {scenario_label(result)} leaked {result.gateway19_response_sent_count} gateway19 responses")
    else:
        lines.append("- No `gateway19_real_setup_response_sent` / follow-up response leaks observed.")

    lines.append("")
    lines.append("## Raw old flow sequences")
    lines.append("")
    for result in results:
        lines.append(f"- {scenario_label(result)}: `{result.old_flow_sequence or '(empty)'}`")

    lines.append("")
    lines.append("## Recommendations")
    lines.append("")
    if not any(r.old_poll_seen_count > 0 for r in results):
        lines.append("- No `12` poll seen in any scenario: try changing `old_reset_response_mode` first.")
    elif not any(r.old_setup_1100_response_count > 0 for r in results):
        lines.append("- `12` poll exists but no `11 00`: try changing `old_idle_poll_response_mode`.")
    elif not any(r.old_reader_enable_seen_count > 0 for r in results):
        lines.append("- `11 00` exists but no `14 01 00`: check the raw replay setup response.")
    else:
        lines.append("- `14 01 00` was seen: next useful test is a controlled pay test.")

    return "\n".join(lines) + "\n"


def aggregate_repeats(results: list[ScenarioResult]) -> dict[str, Any]:
    verdict_counts = Counter(result.verdict for result in results)
    return {
        "repeat_count": len(results),
        "reset_false_count": sum(1 for r in results if not r.reset_seen),
        "reset_true_count": sum(1 for r in results if r.reset_seen),
        "reader_enabled_count": sum(1 for r in results if r.reader_enabled),
        "poll_seen_count": sum(1 for r in results if r.poll_seen),
        "enable_seen_count": sum(1 for r in results if r.enable_seen),
        "old_setup_1100_response_count": sum(r.old_setup_1100_response_count for r in results),
        "gateway19_leak_count": sum(r.gateway19_response_sent_count for r in results),
        "verdict_counts": dict(verdict_counts),
    }


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("port", nargs="?", default=DEFAULT_PORT, help=f"serial port, default {DEFAULT_PORT}")
    parser.add_argument("--observe-timeout", type=float, default=OBSERVE_TIMEOUT_S)
    parser.add_argument("--single", action="store_true", help="run one scenario only")
    parser.add_argument("--repeat", type=int, default=1, help="repeat the --single scenario N times")
    parser.add_argument("--reset-mode", choices=RESET_MODES, default="ack")
    parser.add_argument("--poll-mode", choices=POLL_MODES, default="fe")
    parser.add_argument("--enable-mode", choices=ENABLE_MODES, default="ack")
    parser.add_argument("--expansion-mode", choices=EXPANSION_MODES, default="no_response")
    return parser.parse_args()


def build_scenarios(args: argparse.Namespace) -> list[Scenario]:
    if args.repeat < 1:
        raise SystemExit("--repeat must be >= 1")
    if args.repeat > 1 and not args.single:
        raise SystemExit("--repeat is only supported with --single")
    if args.single:
        return [
            Scenario(
                reset_mode=args.reset_mode,
                poll_mode=args.poll_mode,
                enable_mode=args.enable_mode,
                expansion_mode=args.expansion_mode,
                run_index=i,
            )
            for i in range(1, args.repeat + 1)
        ]
    return [Scenario(reset, poll, enable, expansion) for reset, poll, enable, expansion in SWEEP_SCENARIOS]


def main() -> int:
    args = parse_args()
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    out_dir = OUT_ROOT / f"old_device_compat_sweep_{timestamp}"
    out_dir.mkdir(parents=True, exist_ok=True)
    scenarios = build_scenarios(args)
    repeat_mode = args.single and args.repeat > 1

    log(f"Opening {args.port} @ {BAUD_RATE}")
    conn = SerialJsonReader(args.port)
    results: list[ScenarioResult] = []
    try:
        for scenario in scenarios:
            results.append(
                run_scenario(
                    conn,
                    out_dir,
                    scenario,
                    observe_timeout_s=args.observe_timeout,
                    repeat_mode=repeat_mode,
                )
            )
    finally:
        conn.close()

    summary: dict[str, Any] = {
        "port": args.port,
        "observe_timeout_s": args.observe_timeout,
        "single": args.single,
        "repeat": args.repeat,
        "reboot_between_scenarios": REBOOT_BETWEEN_SCENARIOS,
        "pay_sent": False,
        "results": [asdict(result) for result in results],
    }
    if repeat_mode:
        summary["aggregate"] = aggregate_repeats(results)

    (out_dir / "summary.json").write_text(
        json.dumps(summary, ensure_ascii=False, indent=2) + "\n",
        encoding="utf-8",
    )
    (out_dir / "report.md").write_text(
        render_report(results, args.port, args.observe_timeout, args.single, args.repeat),
        encoding="utf-8",
    )
    log(f"Wrote {out_dir / 'summary.json'}")
    log(f"Wrote {out_dir / 'report.md'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
