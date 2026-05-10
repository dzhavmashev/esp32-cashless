#!/usr/bin/env python3
"""Diagnostic gateway compatibility sequence tracker bench sweep.

This script does not change firmware. For every scenario it reboots ESP32,
drains old serial data, applies modes, then starts a clean observation window.
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

FE_EVENTS = {
    "mdb_fe_compat_poll_seen", "mdb_fe_seen", "mdb_fe_credit_poll_seen",
    "mdb_fe_idle_response_sent", "mdb_fe_no_pending_credit",
    "mdb_fe_compat_ignored", "mdb_fe_ack_only",
}
FC_EVENTS = {
    "mdb_compat_tail_ignored", "mdb_fc_ack_sent", "mdb_fc_ret_sent",
    "mdb_fc_nak_sent", "mdb_fc_gateway_poll_not_implemented",
    "mdb_fc_before_setup_seen", "mdb_fc_mode_bypassed",
}
ONE_C_EVENTS = {
    "mdb_1c_compact_ignored", "mdb_1c_seen", "mdb_1c_ack_only",
    "mdb_1c_ack_enable", "mdb_1c_ret", "mdb_1c_nak",
    "mdb_1c_ret_sent", "mdb_1c_nak_sent",
}
RESET_EVENTS = {"gateway19_chain_reset_seen", "cashless_reset_received", "reset_seen", "vmc_reset_seen"}
POLL_EVENTS = {"poll_seen", "vmc_poll_seen", "cashless_poll_seen"}
ENABLE_EVENTS = {"enable_seen", "vmc_enable_seen", "cashless_enable_seen"}
E0_EVENTS = {"mdb_e0_seen"}
SEQ_EVENTS = {"gateway_compat_sequence_event"}
SEQ_SUMMARIES = {"gateway_compat_sequence_summary"}
ACCEPT_EVENTS = {
    "command_applied", "mdb_fe_mode_changed", "mdb_fe_idle_mode_changed",
    "mdb_e0_mode_changed", "mdb_fc_mode_changed", "mdb_19_response_mode_changed",
    "mdb_single_wire_mode_changed",
}
REJECT_EVENTS = {
    "command_rejected", "command_unknown", "unknown_command", "command_error",
    "mdb_fe_idle_mode_rejected", "mdb_e0_mode_rejected",
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


def events_of(events: list[dict[str, Any]], names: set[str] | str) -> list[dict[str, Any]]:
    if isinstance(names, str):
        names = {names}
    return [e for e in events if e.get("event") in names]


def reboot(conn: Conn) -> None:
    conn.send(cmd("reboot"))
    time.sleep(BOOT_WAIT_S)
    conn.collect(2.0)


def send_modes(conn: Conn, mode19: str, fc: str, fe: str, e0: str) -> list[dict[str, Any]]:
    for command, payload in [
        ("mdb_19_response_mode", {"mode": mode19}),
        ("mdb_fc_mode", {"mode": fc}),
        ("mdb_fe_mode", {"mode": fe}),
        ("mdb_e0_mode", {"mode": e0}),
        ("mdb_single_wire_mode", {"enabled": True}),
    ]:
        conn.send(cmd(command, payload))
        time.sleep(0.15)
    return conn.collect(MODE_APPLY_S, verbose=True)


def probe(conn: Conn, command: str, mode: str) -> str:
    conn.send(cmd(command, {"mode": mode}))
    events = conn.collect(CMD_WAIT_S)
    if any(e.get("event") in REJECT_EVENTS or details(e).get("reason") == "invalid_mode" for e in events):
        return "rejected"
    if any(e.get("event") in ACCEPT_EVENTS for e in events):
        return "accepted"
    if any(command in json.dumps(e) for e in events):
        return "accepted"
    return "no_response"


def debug_sanity(conn: Conn) -> dict[str, Any]:
    reboot(conn)
    conn.send(cmd("mdb_debug_state_compact"))
    events = conn.collect(4.0)
    ev = next((e for e in events if e.get("event") == "mdb_debug_state_compact"), None)
    d = details(ev)
    required = [
        "gateway_compat_seq_active", "gateway_compat_seq_id",
        "gateway_compat_seq_event_count", "gateway_compat_seq_last_bytes_hex",
        "gateway_compat_seq_first_followup_hex", "gateway_compat_seq_reset_seen",
        "gateway_compat_seq_poll_seen", "gateway_compat_seq_enable_seen",
        "e0_count", "last_e0_seen_us", "mdb_fe_mode_alias_supported",
    ]
    return {
        "event": ev,
        "details": d,
        "works": ev is not None,
        "missing_fields": [k for k in required if k not in d],
    }


@dataclass
class Scenario:
    name: str
    mode19: str
    fc: str
    fe: str
    e0: str
    apply_events: list[dict[str, Any]] = field(default_factory=list)
    events: list[dict[str, Any]] = field(default_factory=list)
    summary: dict[str, Any] = field(default_factory=dict)
    seq_summaries: list[dict[str, Any]] = field(default_factory=list)


def summarize(sc: Scenario) -> None:
    ev = sc.events
    seq_events = events_of(ev, SEQ_EVENTS)
    seq_summ = events_of(ev, SEQ_SUMMARIES)
    fc = events_of(ev, FC_EVENTS)
    fe = events_of(ev, FE_EVENTS)
    onec = events_of(ev, ONE_C_EVENTS)
    e0 = events_of(ev, E0_EVENTS)
    reset = events_of(ev, RESET_EVENTS)
    poll = events_of(ev, POLL_EVENTS)
    enable = events_of(ev, ENABLE_EVENTS)
    setup = events_of(ev, "gateway19_real_setup_response_sent")
    gateway19 = events_of(ev, "gateway19_real_frame_seen")
    sc.seq_summaries = [details(e) for e in seq_summ]
    sc.summary = {
        "gateway19": len(gateway19),
        "setup_response_frame": next((details(e).get("frame_hex") for e in setup if details(e).get("frame_hex")), ""),
        "FC": len(fc),
        "FC_response": next((details(e).get("frame_hex") for e in fc if details(e).get("frame_hex")), ""),
        "FE": len(fe),
        "FE_response": next((details(e).get("frame_hex") or details(e).get("payload_hex") for e in fe if details(e).get("frame_hex") or details(e).get("payload_hex")), ""),
        "1C": len(onec),
        "E0": len(e0),
        "reset": len(reset),
        "POLL": len(poll),
        "ENABLE": len(enable),
        "reader_enabled": any(details(e).get("reader_enabled") is True for e in ev),
        "seq_event_count": len(seq_events),
        "seq_summary_count": len(seq_summ),
        "sequence_hex": [details(e).get("sequence_hex", "") for e in seq_summ],
        "close_reason": [details(e).get("close_reason", "") for e in seq_summ],
        "first_followup": [details(e).get("first_followup_hex", "") for e in seq_summ],
    }


def run_scenario(conn: Conn, sc: Scenario) -> Scenario:
    log(f"=== {sc.name}: 19={sc.mode19} fc={sc.fc} fe={sc.fe} e0={sc.e0} ===")
    reboot(conn)
    sc.apply_events = send_modes(conn, sc.mode19, sc.fc, sc.fe, sc.e0)
    log(f"collecting {OBSERVE_S:.0f}s")
    sc.events = conn.collect(OBSERVE_S)
    summarize(sc)
    s = sc.summary
    log(
        f"done {sc.name}: 19={s['gateway19']} seq={s['seq_summary_count']} "
        f"FE={s['FE']} FC={s['FC']} 1C={s['1C']} E0={s['E0']} reset={s['reset']} reader={s['reader_enabled']}"
    )
    return sc


def pay_negative(conn: Conn) -> dict[str, Any]:
    conn.send(cmd("mdb_debug_state_compact"))
    debug_events = conn.collect(3.0)
    conn.send(cmd("pay", {"amount": 100, "transport": "mdb", "transaction_id": "seq-tracker-negative-100"}))
    events = conn.collect(PAY_WAIT_S)
    return {
        "debug": next((e for e in debug_events if e.get("event") == "mdb_debug_state_compact"), None),
        "events": events,
        "queued": any(e.get("event") == "coin_payment_queued" for e in events),
        "waiting": any(e.get("event") == "coin_payment_queued_waiting_for_reader" for e in events),
        "false_completed": any(e.get("event") == "coin_payment_completed" for e in events),
        "credit_sent": any(e.get("event") == "mdb_fe_credit_sent" for e in events),
        "pulse_completed": any(e.get("event") == "pulse_payment_completed" for e in events),
    }


def make_report(port: str, debug: dict[str, Any], fe_probe: dict[str, str],
                e0_probe: dict[str, str], scenarios: list[Scenario],
                pay: dict[str, Any]) -> str:
    d = debug["details"]
    lines: list[str] = []
    lines.append("MDB DIAGNOSTIC SEQUENCE TRACKER SWEEP")
    lines.append(f"date: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    lines.append(f"port: {port}")
    lines.append("")
    lines.append("Debug-state:")
    lines.append(f"  compact works: {debug['works']}")
    lines.append(f"  missing sequence/e0 fields: {debug['missing_fields']}")
    lines.append(f"  defaults: 19={d.get('mdb_19_response_mode')} fc={d.get('mdb_fc_mode')} single_wire={d.get('single_wire_mode_enabled')} reader={d.get('reader_enabled')}")
    lines.append(f"  mapping: {d.get('mdb_control_byte_mapping')}")
    lines.append(f"  mdb_fe_mode_alias_supported: {d.get('mdb_fe_mode_alias_supported')}")
    lines.append("")
    lines.append("Command parser:")
    lines.append(f"  mdb_fe_mode: {fe_probe}")
    lines.append(f"  mdb_e0_mode: {e0_probe}")
    lines.append("")
    lines.append("Scenario | mode19 | fc_mode | fe_mode | e0_mode | seq_count | sequence_hex examples | close_reason | FE | FC | 1C | E0 | reset | POLL | ENABLE | reader_enabled")
    for sc in scenarios:
        s = sc.summary
        examples = "; ".join(s["sequence_hex"][:2])
        reasons = ",".join(s["close_reason"][:3])
        lines.append(
            f"{sc.name} | {sc.mode19} | {sc.fc} | {sc.fe} | {sc.e0} | {s['seq_summary_count']} | "
            f"{examples} | {reasons} | {s['FE']} | {s['FC']} | {s['1C']} | {s['E0']} | "
            f"{s['reset']} | {s['POLL']} | {s['ENABLE']} | {s['reader_enabled']}"
        )
    lines.append("")
    lines.append("Sequence summaries:")
    for sc in scenarios:
        lines.append(f"{sc.name}:")
        for seq in sc.seq_summaries[:3]:
            lines.append(f"  seq_id: {seq.get('seq_id')}")
            lines.append(f"  sequence_hex: {seq.get('sequence_hex')}")
            lines.append(f"  tx_sequence: {seq.get('tx_sequence')}")
            lines.append(f"  first_followup_hex: {seq.get('first_followup_hex')}")
            lines.append(f"  close_reason: {seq.get('close_reason')}")
            lines.append(f"  conclusion_hint: {seq.get('conclusion_hint')}")
            lines.append(f"  duration_us: {seq.get('duration_us')}")
    lines.append("")
    e0_total = sum(sc.summary["E0"] for sc in scenarios)
    lines.append("E0 analysis:")
    lines.append(f"  E0 seen count: {e0_total}")
    lines.append(f"  scenarios with E0: {[sc.name for sc in scenarios if sc.summary['E0']]}")
    lines.append("  E0 mode effect: compare J/K/L rows if E0 appears")
    lines.append("")
    lines.append("FE analysis:")
    lines.append(f"  FE total: {sum(sc.summary['FE'] for sc in scenarios)}")
    lines.append("  FE mode effect: compare A/E/F/G rows")
    lines.append("")
    lines.append("FC analysis:")
    lines.append(f"  FC total: {sum(sc.summary['FC'] for sc in scenarios)}")
    lines.append("  FC mode effect: compare A/B/C/D rows")
    lines.append("")
    any_poll = any(sc.summary["POLL"] for sc in scenarios)
    any_enable = any(sc.summary["ENABLE"] for sc in scenarios)
    any_reader = any(sc.summary["reader_enabled"] for sc in scenarios)
    lines.append("Reader-flow analysis:")
    lines.append(f"  POLL seen: {any_poll}")
    lines.append(f"  ENABLE seen: {any_enable}")
    lines.append(f"  reader_enabled_any: {any_reader}")
    if not any_reader:
        lines.append("  Handshake still not accepted by VMC. Payment delivery must remain gated.")
    lines.append("")
    lines.append("Pay negative:")
    lines.append(f"  queued: {pay['queued']}")
    lines.append(f"  waiting_for_reader: {pay['waiting']}")
    lines.append(f"  false_completed: {pay['false_completed']}")
    lines.append(f"  credit_sent: {pay['credit_sent']}")
    lines.append(f"  pulse_completed: {pay['pulse_completed']}")
    lines.append(f"  result: {'PASS' if pay['queued'] and pay['waiting'] and not pay['false_completed'] and not pay['credit_sent'] and not pay['pulse_completed'] else 'FAIL'}")
    lines.append("")
    seq_counts: dict[str, int] = {}
    reasons: dict[str, int] = {}
    firsts: dict[str, int] = {}
    for sc in scenarios:
        for seq in sc.seq_summaries:
            seq_counts[seq.get("sequence_hex", "")] = seq_counts.get(seq.get("sequence_hex", ""), 0) + 1
            reasons[seq.get("close_reason", "")] = reasons.get(seq.get("close_reason", ""), 0) + 1
            firsts[seq.get("first_followup_hex", "")] = firsts.get(seq.get("first_followup_hex", ""), 0) + 1
    lines.append("Final conclusion:")
    lines.append(f"  Most common sequence_hex: {max(seq_counts, key=seq_counts.get) if seq_counts else ''}")
    lines.append(f"  Most common close_reason: {max(reasons, key=reasons.get) if reasons else ''}")
    lines.append(f"  First follow-up most often: {max(firsts, key=firsts.get) if firsts else ''}")
    lines.append("  Is E0 meaningful? see J/K/L; do not treat as POLL/ENABLE")
    lines.append("  Is FE meaningful? FE participates in sequences; current modes did not prove handshake acceptance")
    lines.append("  Is 1C meaningful? 1C appears in reset chains; not proven ENABLE/POLL")
    lines.append("  Minimal next patch: only diagnostic refinements unless a mode produces POLL/ENABLE")
    return "\n".join(lines)


def save(stamp: str, report: str, payload: dict[str, Any]) -> tuple[Path, Path]:
    OUT_DIR.mkdir(exist_ok=True)
    txt = OUT_DIR / f"mdb_sequence_tracker_sweep_{stamp}.txt"
    js = OUT_DIR / f"mdb_sequence_tracker_sweep_{stamp}.json"
    txt.write_text(report + "\n", encoding="utf-8")
    js.write_text(json.dumps(payload, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    return txt, js


def main() -> None:
    port = sys.argv[1] if len(sys.argv) > 1 else DEFAULT_PORT
    conn = Conn(port)
    try:
        conn.collect(2.0)
        debug = debug_sanity(conn)

        reboot(conn)
        fe_probe = {m: probe(conn, "mdb_fe_mode", m) for m in ["no_response", "ack", "just_reset_0b_once", "just_reset_0b_always", "bad_mode"]}
        e0_probe = {m: probe(conn, "mdb_e0_mode", m) for m in ["ignore", "no_response", "ack", "ret", "nak", "bad_mode"]}

        scenarios = [
            Scenario("A", "real_setup_a", "log_only", "just_reset_0b_once", "ignore"),
            Scenario("B", "real_setup_a", "ack", "just_reset_0b_once", "ignore"),
            Scenario("C", "real_setup_a", "ret", "just_reset_0b_once", "ignore"),
            Scenario("D", "real_setup_a", "nak", "just_reset_0b_once", "ignore"),
            Scenario("E", "real_setup_a", "log_only", "no_response", "ignore"),
            Scenario("F", "real_setup_a", "log_only", "ack", "ignore"),
            Scenario("G", "real_setup_a", "log_only", "just_reset_0b_always", "ignore"),
            Scenario("H", "real_setup_g", "ack", "just_reset_0b_once", "ignore"),
            Scenario("I", "no_response", "log_only", "just_reset_0b_once", "ignore"),
            Scenario("J", "real_setup_a", "log_only", "just_reset_0b_once", "ack"),
            Scenario("K", "real_setup_a", "log_only", "just_reset_0b_once", "ret"),
            Scenario("L", "real_setup_a", "log_only", "just_reset_0b_once", "nak"),
        ]
        for sc in scenarios:
            run_scenario(conn, sc)
        pay = pay_negative(conn)
        stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        rep = make_report(port, debug, fe_probe, e0_probe, scenarios, pay)
        payload = {
            "debug": debug,
            "fe_probe": fe_probe,
            "e0_probe": e0_probe,
            "scenarios": [
                {
                    "name": sc.name,
                    "mode19": sc.mode19,
                    "fc": sc.fc,
                    "fe": sc.fe,
                    "e0": sc.e0,
                    "summary": sc.summary,
                    "seq_summaries": sc.seq_summaries,
                    "apply_events": sc.apply_events,
                    "events": sc.events,
                }
                for sc in scenarios
            ],
            "pay_negative": pay,
        }
        txt, js = save(stamp, rep, payload)
        print("\n" + rep)
        log(f"saved txt={txt}")
        log(f"saved json={js}")
    finally:
        conn.close()


if __name__ == "__main__":
    main()
