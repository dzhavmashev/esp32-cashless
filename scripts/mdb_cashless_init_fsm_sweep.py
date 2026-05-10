#!/usr/bin/env python3
"""Cashless init FSM diagnostic sweep.

Only uses serial JSON commands and reads firmware events. Firmware/business
logic is not modified. Every scenario reboots ESP32, drains boot noise, applies
modes, then starts a clean 180s collection window.
"""

from __future__ import annotations

import json
import sys
import time
from dataclasses import dataclass, field
from datetime import datetime
from pathlib import Path
from typing import Any

import serial

DEFAULT_PORT = "/dev/serial/by-id/usb-Silicon_Labs_CP2102_USB_to_UART_Bridge_Controller_0001-if00-port0"
BAUD = 115200
BOOT_WAIT_S = 10.0
MODE_APPLY_S = 2.0
OBSERVE_S = 180.0
CMD_WAIT_S = 1.5
PAY_WAIT_S = 12.0
OUT_DIR = Path.cwd() / "test_logs"

ACCEPT_EVENTS = {
    "command_applied", "mdb_setup_response_profile_changed",
    "mdb_19_response_mode_changed", "mdb_fc_mode_changed", "mdb_1c_mode_changed",
    "mdb_fe_mode_changed", "mdb_fe_idle_mode_changed", "mdb_e0_mode_changed",
    "mdb_single_wire_mode_changed",
}
REJECT_EVENTS = {
    "command_rejected", "command_unknown", "unknown_command", "command_error",
    "mdb_setup_response_profile_rejected",
}


def log(msg: str) -> None:
    print(f"[{datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3]}] {msg}", flush=True)


def cmd(command: str, payload: dict[str, Any] | None = None) -> str:
    obj: dict[str, Any] = {"command": command}
    if payload is not None:
        obj["payload"] = payload
    return json.dumps(obj, separators=(",", ":"))


class Extractor:
    def __init__(self) -> None:
        self.buf = bytearray()

    def feed(self, data: bytes) -> list[dict[str, Any]]:
        if data:
            self.buf.extend(data)
        out: list[dict[str, Any]] = []
        while self.buf:
            start = self.buf.find(b"{")
            if start < 0:
                self.buf.clear()
                break
            if start:
                del self.buf[:start]
            end = self._end(self.buf)
            if end is None:
                if len(self.buf) > 512 * 1024:
                    self.buf.clear()
                break
            raw = bytes(self.buf[: end + 1])
            del self.buf[: end + 1]
            try:
                obj = json.loads(raw.decode("utf-8", "replace"))
                if isinstance(obj, dict):
                    out.append(obj)
            except json.JSONDecodeError:
                pass
        return out

    @staticmethod
    def _end(buf: bytearray) -> int | None:
        depth = 0
        in_str = False
        esc = False
        for i, b in enumerate(buf):
            ch = chr(b)
            if in_str:
                if esc:
                    esc = False
                elif ch == "\\":
                    esc = True
                elif ch == '"':
                    in_str = False
            elif ch == '"':
                in_str = True
            elif ch == "{":
                depth += 1
            elif ch == "}":
                depth -= 1
                if depth == 0:
                    return i
        return None


class Conn:
    def __init__(self, port: str) -> None:
        self.ser = serial.Serial(port, BAUD, timeout=0.1)
        self.ser.dtr = False
        self.ser.rts = False
        self.ext = Extractor()
        log(f"connected port={port} baud={BAUD}")

    def close(self) -> None:
        self.ser.close()

    def send(self, text: str) -> None:
        log(f"TX> {text}")
        self.ser.write((text + "\n").encode())
        self.ser.flush()

    def collect(self, seconds: float, verbose: bool = False) -> list[dict[str, Any]]:
        deadline = time.monotonic() + seconds
        events: list[dict[str, Any]] = []
        while time.monotonic() < deadline:
            data = self.ser.read(4096)
            for obj in self.ext.feed(data):
                events.append(obj)
                if verbose and obj.get("event"):
                    log(f"  EV {obj.get('event')}")
        return events


def details(event: dict[str, Any] | None) -> dict[str, Any]:
    if not event:
        return {}
    d = event.get("details")
    return d if isinstance(d, dict) else {}


def events_of(events: list[dict[str, Any]], name: str) -> list[dict[str, Any]]:
    return [e for e in events if e.get("event") == name]


def reboot(conn: Conn) -> None:
    conn.send(cmd("reboot"))
    time.sleep(BOOT_WAIT_S)
    conn.collect(2.0)


def debug_sanity(conn: Conn) -> dict[str, Any]:
    reboot(conn)
    conn.send(cmd("mdb_debug_state_compact"))
    events = conn.collect(4.0)
    ev = next((e for e in events if e.get("event") == "mdb_debug_state_compact"), None)
    d = details(ev)
    required = [
        "mdb_setup_response_profile",
        "cashless_init_seq_active",
        "cashless_init_seq_id",
        "cashless_init_seq_event_count",
        "cashless_init_seq_stable_poll_count",
        "cashless_init_seq_reset_seen",
        "cashless_init_seq_setup_seen",
        "cashless_init_seq_poll_seen",
        "cashless_init_seq_expansion_seen",
        "cashless_init_seq_reader_cmd_seen",
        "cashless_init_seq_reader_enabled",
    ]
    return {
        "event": ev,
        "details": d,
        "works": ev is not None,
        "missing_fields": [k for k in required if k not in d],
    }


def probe_profile(conn: Conn, mode: str) -> dict[str, Any]:
    conn.send(cmd("mdb_setup_response_profile", {"mode": mode}))
    events = conn.collect(CMD_WAIT_S)
    accepted = any(e.get("event") == "mdb_setup_response_profile_changed" for e in events)
    rejected = any(e.get("event") in REJECT_EVENTS for e in events)
    actual = next((details(e).get("mode") for e in events if e.get("event") == "mdb_setup_response_profile_changed"), None)
    return {"accepted": accepted, "rejected": rejected, "mode": actual, "events": events}


@dataclass
class Scenario:
    name: str
    profile: str
    gateway19_mode: str
    apply_events: list[dict[str, Any]] = field(default_factory=list)
    events: list[dict[str, Any]] = field(default_factory=list)
    summary: dict[str, Any] = field(default_factory=dict)


def apply_modes(conn: Conn, sc: Scenario) -> list[dict[str, Any]]:
    commands = [
        ("mdb_single_wire_mode", {"enabled": True}),
        ("mdb_fc_mode", {"mode": "log_only"}),
        ("mdb_1c_mode", {"mode": "ignore"}),
        ("mdb_fe_mode", {"mode": "just_reset_0b_once"}),
        ("mdb_e0_mode", {"mode": "ignore"}),
        ("mdb_setup_response_profile", {"mode": sc.profile}),
        ("mdb_19_response_mode", {"mode": sc.gateway19_mode}),
    ]
    for command, payload in commands:
        conn.send(cmd(command, payload))
        time.sleep(0.15)
    return conn.collect(MODE_APPLY_S, verbose=True)


def summarize(sc: Scenario) -> None:
    ev = sc.events
    init_events = events_of(ev, "cashless_init_sequence_event")
    init_summaries = events_of(ev, "cashless_init_sequence_summary")
    setup_seen = events_of(ev, "cashless_setup_seen")
    gateway19 = events_of(ev, "gateway19_real_frame_seen")
    gateway19_tx = events_of(ev, "gateway19_real_setup_response_sent")
    resets = events_of(ev, "cashless_reset_received") + events_of(ev, "reset_seen") + events_of(ev, "gateway19_chain_reset_seen")
    poll_events = [
        e for e in ev
        if e.get("event") in ("cashless_poll_seen", "poll_seen", "vmc_poll_seen")
        or details(e).get("event_kind") == "poll"
    ]
    expansion_events = [
        e for e in ev
        if "expansion" in str(e.get("event", "")).lower()
        or details(e).get("event_kind") == "expansion"
    ]
    reader_cmd_events = [
        e for e in ev
        if "reader_cmd" in str(e.get("event", "")).lower()
        or details(e).get("event_kind") == "reader_cmd"
    ]
    reader_enabled_any = any(details(e).get("reader_enabled") is True for e in ev)
    first_summary = details(init_summaries[0]) if init_summaries else {}
    first_setup = details(setup_seen[0]) if setup_seen else {}
    poll_init_events = [details(e) for e in init_events if details(e).get("event_kind") == "poll"]
    expansion_init_events = [details(e) for e in init_events if details(e).get("event_kind") == "expansion"]
    reader_init_events = [details(e) for e in init_events if details(e).get("event_kind") == "reader_cmd"]
    sc.summary = {
        "event_count": len(ev),
        "cashless_init_sequence_event": len(init_events),
        "cashless_init_sequence_summary": len(init_summaries),
        "cashless_setup_seen": len(setup_seen),
        "gateway19_real_frame_seen": len(gateway19),
        "gateway19_real_setup_response_sent": len(gateway19_tx),
        "reset": len(resets),
        "poll12": len(poll_events),
        "expansion17": len(expansion_events),
        "reader14": len(reader_cmd_events),
        "reader_enabled": reader_enabled_any,
        "first_summary": first_summary,
        "summaries": [details(e) for e in init_summaries[:5]],
        "first_setup": first_setup,
        "setup_tx": first_setup.get("frame_hex") or first_setup.get("tx_response_hex") or "",
        "poll_tx": next((e.get("response_hex", "") for e in poll_init_events if e.get("response_hex")), ""),
        "expansion_tx": next((e.get("response_hex", "") for e in expansion_init_events if e.get("response_hex")), ""),
        "reader_cmd_action": next((e.get("action", "") for e in reader_init_events if e.get("action")), ""),
        "reader_cmd_tx": next((e.get("response_hex", "") for e in reader_init_events if e.get("response_hex")), ""),
    }


def run_scenario(conn: Conn, sc: Scenario) -> Scenario:
    log(f"=== {sc.name}: profile={sc.profile} g19={sc.gateway19_mode} ===")
    reboot(conn)
    sc.apply_events = apply_modes(conn, sc)
    log(f"collecting {OBSERVE_S:.0f}s")
    sc.events = conn.collect(OBSERVE_S)
    summarize(sc)
    s = sc.summary
    log(
        f"done {sc.name}: init_ev={s['cashless_init_sequence_event']} init_sum={s['cashless_init_sequence_summary']} "
        f"setup={s['cashless_setup_seen']} poll={s['poll12']} exp={s['expansion17']} reader14={s['reader14']} "
        f"reset={s['reset']} reader={s['reader_enabled']}"
    )
    return sc


def pay_negative(conn: Conn) -> dict[str, Any]:
    conn.send(cmd("mdb_debug_state_compact"))
    debug = conn.collect(3.0)
    conn.send(cmd("pay", {"amount": 100, "transport": "mdb", "transaction_id": "cashless-init-negative-100"}))
    events = conn.collect(PAY_WAIT_S)
    return {
        "debug": next((e for e in debug if e.get("event") == "mdb_debug_state_compact"), None),
        "events": events,
        "queued": any(e.get("event") == "coin_payment_queued" for e in events),
        "waiting": any(e.get("event") == "coin_payment_queued_waiting_for_reader" for e in events),
        "false_completed": any(e.get("event") == "coin_payment_completed" for e in events),
        "credit_sent": any(e.get("event") == "mdb_fe_credit_sent" for e in events),
        "pulse_completed": any(e.get("event") == "pulse_payment_completed" for e in events),
    }


def make_report(port: str, debug: dict[str, Any], parser: dict[str, Any],
                scenarios: list[Scenario], pay: dict[str, Any]) -> str:
    d = debug["details"]
    lines: list[str] = []
    lines.append("MDB CASHLESS INIT FSM DIAGNOSTIC SWEEP")
    lines.append(f"date: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    lines.append(f"port: {port}")
    lines.append("")
    lines.append("2. Debug-state:")
    lines.append(f"- compact works: {debug['works']}")
    lines.append(f"- missing fields: {debug['missing_fields']}")
    lines.append(f"- default setup profile: {d.get('mdb_setup_response_profile')}")
    lines.append(f"- reader_enabled: {d.get('reader_enabled')}")
    lines.append("")
    lines.append("3. Command parser:")
    for mode in ["current_a", "current_g", "minimal_level1", "no_response", "bad_mode"]:
        p = parser.get(mode, {})
        lines.append(f"- {mode}: accepted={p.get('accepted')} rejected={p.get('rejected')} mode={p.get('mode')}")
    lines.append("")
    lines.append("4. Scenario table:")
    lines.append("Scenario | setup_profile | g19_mode | reset | setup11 | poll12 | expansion17 | reader14 | stable_poll_count | reader_enabled | close_reason | conclusion")
    for sc in scenarios:
        s = sc.summary
        fs = s["first_summary"]
        lines.append(
            f"{sc.name} | {sc.profile} | {sc.gateway19_mode} | {s['reset']} | {s['cashless_setup_seen']} | "
            f"{s['poll12']} | {s['expansion17']} | {s['reader14']} | {fs.get('stable_poll_count', 0)} | "
            f"{s['reader_enabled']} | {fs.get('close_reason', '')} | {fs.get('conclusion_hint', '')}"
        )
    lines.append("")
    lines.append("5. Scenario details:")
    for sc in scenarios:
        s = sc.summary
        lines.append(f"{sc.name}:")
        lines.append(f"  first init summary: {s['first_summary']}")
        lines.append(f"  setup response tx: {s['setup_tx']}")
        lines.append(f"  poll response tx: {s['poll_tx']}")
        lines.append(f"  expansion response tx: {s['expansion_tx']}")
        lines.append(f"  reader cmd action/tx: {s['reader_cmd_action']} / {s['reader_cmd_tx']}")
        lines.append(f"  summaries: {s['summaries']}")
    lines.append("")
    lines.append("6. Comparison to old device:")
    lines.append("Old path: 10 10 -> 11 -> 12 -> 11 -> 17 -> 14 -> stable 12 polling")
    for sc in scenarios:
        s = sc.summary
        lines.append(
            f"ESP {sc.name}: reset={s['reset']} setup11={s['cashless_setup_seen']} "
            f"poll12={s['poll12']} expansion17={s['expansion17']} reader14={s['reader14']} "
            f"stable={s['first_summary'].get('stable_poll_count', 0)} reader={s['reader_enabled']}"
        )
    lines.append("")
    lines.append("7. Pay negative:")
    lines.append(f"- queued: {pay['queued']}")
    lines.append(f"- waiting_for_reader: {pay['waiting']}")
    lines.append(f"- false_completed: {pay['false_completed']}")
    lines.append(f"- credit_sent: {pay['credit_sent']}")
    lines.append(f"- pulse_completed: {pay['pulse_completed']}")
    ok_pay = pay["queued"] and pay["waiting"] and not pay["false_completed"] and not pay["credit_sent"] and not pay["pulse_completed"]
    lines.append(f"- result: {'PASS' if ok_pay else 'FAIL'}")
    lines.append("")
    any_poll = any(sc.summary["poll12"] > 0 for sc in scenarios)
    any_exp = any(sc.summary["expansion17"] > 0 for sc in scenarios)
    any_reader_cmd = any(sc.summary["reader14"] > 0 for sc in scenarios)
    any_reader = any(sc.summary["reader_enabled"] for sc in scenarios)
    best = max(scenarios, key=lambda sc: (
        sc.summary["first_summary"].get("stable_poll_count", 0) if sc.summary["first_summary"] else 0,
        sc.summary["poll12"],
        sc.summary["expansion17"],
        sc.summary["reader14"],
        sc.summary["cashless_setup_seen"],
    ))
    lines.append("8. Final conclusion:")
    lines.append(f"- closest profile: {best.name} ({best.profile}, g19={best.gateway19_mode})")
    lines.append(f"- reached 12 polling: {any_poll}")
    lines.append(f"- reached 17 expansion: {any_exp}")
    lines.append(f"- reached 14 reader cmd: {any_reader_cmd}")
    lines.append(f"- reader_enabled_any: {any_reader}")
    if not any_poll:
        lines.append("- none reached setup/poll: next suspect is timing/electrical or earlier gateway/init path")
    elif not any_exp:
        lines.append("- setup/poll reached but no expansion: next suspect is setup payload/profile")
    elif not any_reader_cmd:
        lines.append("- expansion reached but no reader cmd: next suspect is expansion ID response")
    elif not any_reader:
        lines.append("- reader cmd reached but no stable polling: next suspect is reader cmd ACK/action")
    return "\n".join(lines)


def save(stamp: str, report: str, payload: dict[str, Any]) -> tuple[Path, Path]:
    OUT_DIR.mkdir(exist_ok=True)
    txt = OUT_DIR / f"mdb_cashless_init_fsm_sweep_{stamp}.txt"
    js = OUT_DIR / f"mdb_cashless_init_fsm_sweep_{stamp}.json"
    txt.write_text(report + "\n", encoding="utf-8")
    js.write_text(json.dumps(payload, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    return txt, js


def main() -> int:
    port = sys.argv[1] if len(sys.argv) > 1 else DEFAULT_PORT
    conn = Conn(port)
    try:
        conn.collect(2.0)
        debug = debug_sanity(conn)
        reboot(conn)
        parser = {m: probe_profile(conn, m) for m in ["current_a", "current_g", "no_response", "minimal_level1", "bad_mode"]}
        scenarios = [
            Scenario("A", "current_a", "real_setup_a"),
            Scenario("B", "current_g", "real_setup_a"),
            Scenario("C", "minimal_level1", "real_setup_a"),
            Scenario("D", "no_response", "real_setup_a"),
            Scenario("E", "current_a", "no_response"),
            Scenario("F", "minimal_level1", "no_response"),
        ]
        for sc in scenarios:
            run_scenario(conn, sc)
        pay = pay_negative(conn)
        stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        report = make_report(port, debug, parser, scenarios, pay)
        payload = {
            "debug": debug,
            "parser": parser,
            "scenarios": [
                {
                    "name": sc.name,
                    "profile": sc.profile,
                    "gateway19_mode": sc.gateway19_mode,
                    "apply_events": sc.apply_events,
                    "events": sc.events,
                    "summary": sc.summary,
                }
                for sc in scenarios
            ],
            "pay_negative": pay,
        }
        txt, js = save(stamp, report, payload)
        print("\n" + report)
        log(f"saved txt={txt}")
        log(f"saved json={js}")
        return 0
    finally:
        conn.close()


if __name__ == "__main__":
    raise SystemExit(main())
