#!/usr/bin/env python3
"""Combined 1C/FE MDB bench sweep.

Firmware is not modified. Each scenario reboots ESP32 first, drains old serial
data, applies modes, then starts the collection window.
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

DEFAULT_PORT = "/dev/ttyUSB0"
BAUD = 115200
BOOT_WAIT_S = 10.0
MODE_APPLY_S = 2.0
OBSERVE_S = 180.0
CMD_WAIT_S = 1.5
OUT_DIR = Path.cwd() / "test_logs"

ONE_C_EVENTS = {
    "mdb_1c_compact_ignored", "mdb_1c_seen", "mdb_1c_ack_sent",
    "mdb_1c_ret_sent", "mdb_1c_nak_sent", "mdb_1c_ack_only",
    "mdb_1c_ack_enable", "mdb_1c_ret", "mdb_1c_nak",
}
FE_EVENTS = {
    "mdb_fe_compat_poll_seen", "mdb_fe_seen", "mdb_fe_credit_poll_seen",
    "mdb_fe_idle_response_sent", "mdb_fe_no_pending_credit",
    "mdb_fe_compat_ignored", "mdb_fe_ack_only", "mdb_fe_credit_sent",
    "mdb_fe_credit_deferred_until_reader_enabled",
}
FC_EVENTS = {
    "mdb_compat_tail_ignored", "mdb_fc_ack_sent", "mdb_fc_ret_sent",
    "mdb_fc_nak_sent", "mdb_fc_gateway_poll_not_implemented",
    "mdb_fc_before_setup_seen", "gateway19_followup_seen",
}
RESET_EVENTS = {
    "gateway19_chain_reset_seen", "cashless_reset_received", "reset_seen",
    "vmc_reset_seen", "cashless_reset",
}
POLL_EVENTS = {"poll_seen", "vmc_poll_seen", "cashless_poll_seen"}
ENABLE_EVENTS = {"enable_seen", "vmc_enable_seen", "cashless_enable_seen"}
ACCEPT_EVENTS = {
    "command_applied", "mdb_1c_mode_changed", "mdb_fe_idle_mode_changed",
    "mdb_fc_mode_changed", "mdb_19_response_mode_changed",
    "mdb_single_wire_mode_changed",
}
REJECT_EVENTS = {
    "command_rejected", "command_unknown", "unknown_command", "command_error",
    "mdb_1c_mode_rejected", "mdb_fe_idle_mode_rejected",
}


def log(msg: str) -> None:
    print(f"[{datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3]}] {msg}", flush=True)


def cmd(command: str, payload: dict[str, Any] | None = None) -> str:
    o: dict[str, Any] = {"command": command}
    if payload is not None:
        o["payload"] = payload
    return json.dumps(o, separators=(",", ":"))


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
            raw = bytes(self.buf[:end + 1])
            del self.buf[:end + 1]
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

    def send(self, s: str) -> None:
        log(f"TX> {s}")
        self.ser.write((s + "\n").encode())
        self.ser.flush()

    def collect(self, seconds: float, verbose: bool = False) -> list[dict[str, Any]]:
        end = time.monotonic() + seconds
        evs: list[dict[str, Any]] = []
        while time.monotonic() < end:
            data = self.ser.read(4096)
            for obj in self.ext.feed(data):
                evs.append(obj)
                if verbose and obj.get("event"):
                    log(f"  EV {obj.get('event')}")
        return evs


def details(e: dict[str, Any] | None) -> dict[str, Any]:
    if not e:
        return {}
    d = e.get("details")
    return d if isinstance(d, dict) else {}


def events_of(evs: list[dict[str, Any]], names: set[str] | tuple[str, ...] | str) -> list[dict[str, Any]]:
    if isinstance(names, str):
        names = {names}
    return [e for e in evs if e.get("event") in names]


def has_raw(e: dict[str, Any], raw: str) -> bool:
    d = details(e)
    return str(d.get("raw_hex", "")).upper() == raw or str(d.get("normalized_hex", "")).upper() == raw


def reboot(conn: Conn) -> None:
    conn.send(cmd("reboot"))
    time.sleep(BOOT_WAIT_S)
    conn.collect(2.0)


def send_modes(conn: Conn, mode19: str, fc_mode: str, one_c: str | None = None,
               fe_idle: str | None = None) -> list[dict[str, Any]]:
    conn.send(cmd("mdb_19_response_mode", {"mode": mode19}))
    time.sleep(0.15)
    conn.send(cmd("mdb_fc_mode", {"mode": fc_mode}))
    time.sleep(0.15)
    conn.send(cmd("mdb_single_wire_mode", {"enabled": True}))
    time.sleep(0.15)
    if one_c:
        conn.send(cmd("mdb_1c_mode", {"mode": one_c}))
        time.sleep(0.15)
    if fe_idle:
        conn.send(cmd("mdb_fe_idle_mode", {"mode": fe_idle}))
        time.sleep(0.15)
    return conn.collect(MODE_APPLY_S, verbose=True)


def probe_command(conn: Conn, command: str, mode: str) -> str:
    conn.send(cmd(command, {"mode": mode}))
    evs = conn.collect(CMD_WAIT_S)
    if any(e.get("event") in REJECT_EVENTS or str(details(e).get("reason", "")).startswith("invalid") for e in evs):
        return "rejected"
    if any(e.get("event") in ACCEPT_EVENTS or e.get("event") == "command_applied" for e in evs):
        return "supported"
    if any(command in json.dumps(e) for e in evs):
        return "supported"
    return "no_response"


def debug_sanity(conn: Conn) -> dict[str, Any]:
    reboot(conn)
    conn.send(cmd("mdb_debug_state_compact"))
    compact = conn.collect(3.0)
    conn.send(cmd("mdb_debug_state"))
    full = conn.collect(4.0)
    c = next((e for e in compact if e.get("event") == "mdb_debug_state_compact"), None)
    f = next((e for e in full if e.get("event") in ("mdb_debug_state", "mdb_debug_state_compact")), None)
    return {
        "compact_event": c,
        "full_or_fallback_event": f,
        "compact_works": c is not None,
        "full_fallback_works": f is not None,
    }


@dataclass
class Scenario:
    name: str
    mode19: str
    fc_mode: str
    one_c: str | None = None
    fe_idle: str | None = None
    apply_events: list[dict[str, Any]] = field(default_factory=list)
    events: list[dict[str, Any]] = field(default_factory=list)
    summary: dict[str, Any] = field(default_factory=dict)
    timeline: list[str] = field(default_factory=list)
    one_c_contexts: list[dict[str, Any]] = field(default_factory=list)
    fe_contexts: list[dict[str, Any]] = field(default_factory=list)
    reset_contexts: list[dict[str, Any]] = field(default_factory=list)


def context(evs: list[dict[str, Any]], idx: int, before: int, after: int) -> dict[str, Any]:
    return {
        "index": idx,
        "event": evs[idx].get("event"),
        "details": details(evs[idx]),
        "before": [e.get("event") for e in evs[max(0, idx - before):idx]],
        "after": [e.get("event") for e in evs[idx + 1:idx + 1 + after]],
    }


def summarize(sc: Scenario) -> None:
    evs = sc.events
    names = [e.get("event", "") for e in evs]
    gateway = events_of(evs, "gateway19_real_frame_seen")
    setup = events_of(evs, "gateway19_real_setup_response_sent")
    synth = events_of(evs, "cashless_gateway_setup_compat")
    suppressed = events_of(evs, "gateway19_synthetic_suppressed")
    fe = events_of(evs, FE_EVENTS)
    fc = events_of(evs, FC_EVENTS)
    onec = events_of(evs, ONE_C_EVENTS)
    resets = events_of(evs, RESET_EVENTS)
    poll = events_of(evs, POLL_EVENTS)
    enable = events_of(evs, ENABLE_EVENTS)
    rx_1c = [e for e in evs if e.get("event") == "mdb_rx_classified" and details(e).get("first_byte") == "1C"]
    ninth_true = sum(1 for e in rx_1c if details(e).get("first_ninth_bit") is True)
    ninth_false = sum(1 for e in rx_1c if details(e).get("first_ninth_bit") is False)
    fc_resp = next((details(e).get("frame_hex") for e in fc if details(e).get("frame_hex")), "")
    fe_resp = next((details(e).get("frame_hex") or details(e).get("payload_hex") for e in fe if details(e).get("frame_hex") or details(e).get("payload_hex")), "")
    setup_resp = next((details(e).get("frame_hex") for e in setup if details(e).get("frame_hex")), "")
    first19 = names.index("gateway19_real_frame_seen") if "gateway19_real_frame_seen" in names else None
    fe_before19 = sum(1 for i, e in enumerate(evs) if e.get("event") in FE_EVENTS and first19 is not None and i < first19)
    fe_after19 = sum(1 for i, e in enumerate(evs) if e.get("event") in FE_EVENTS and first19 is not None and i > first19)
    reader_enabled_any = any(details(e).get("reader_enabled") is True for e in evs)
    sc.summary = {
        "events": len(evs),
        "gateway19_count": len(gateway),
        "setup_response_count": len(setup),
        "setup_response_frame": setup_resp,
        "synthetic_suppressed_count": len(suppressed),
        "cashless_gateway_setup_compat_count": len(synth),
        "FE_count": len(fe),
        "FE_response": fe_resp,
        "FE_before19": fe_before19,
        "FE_after19": fe_after19,
        "FC_count": len(fc),
        "FC_response": fc_resp,
        "1C_count": len(onec),
        "1C_ninth_true": ninth_true,
        "1C_ninth_false": ninth_false,
        "reset_count": len(resets),
        "POLL_count": len(poll),
        "ENABLE_count": len(enable),
        "reader_enabled_any": reader_enabled_any,
        "last_tx_kind_before_reset": next((details(e).get("last_tx_kind") for e in resets if details(e).get("last_tx_kind")), ""),
        "last_fc_mode_before_reset": next((details(e).get("last_fc_mode") for e in resets if details(e).get("last_fc_mode")), ""),
        "delta_us_from_last_tx": next((details(e).get("delta_us_from_last_fc_tx") or details(e).get("delta_us_from_last_tx") for e in resets if details(e)), 0),
    }
    relevant = FE_EVENTS | FC_EVENTS | ONE_C_EVENTS | RESET_EVENTS | POLL_EVENTS | ENABLE_EVENTS | {
        "gateway19_real_frame_seen", "gateway19_real_setup_response_sent",
        "gateway19_synthetic_suppressed", "cashless_gateway_setup_compat",
        "mdb_rx_classified",
    }
    sc.timeline = [n for n in names if n in relevant][:40]
    for i, e in enumerate(evs):
        if e.get("event") in ONE_C_EVENTS or (e.get("event") == "mdb_rx_classified" and details(e).get("first_byte") == "1C"):
            sc.one_c_contexts.append(context(evs, i, 5, 10))
        if e.get("event") in FE_EVENTS:
            sc.fe_contexts.append(context(evs, i, 5, 10))
        if e.get("event") in RESET_EVENTS:
            sc.reset_contexts.append(context(evs, i, 10, 5))


def run_scenario(conn: Conn, sc: Scenario) -> Scenario:
    log(f"=== {sc.name}: mode19={sc.mode19} fc={sc.fc_mode} 1c={sc.one_c} fe_idle={sc.fe_idle} ===")
    reboot(conn)
    sc.apply_events = send_modes(conn, sc.mode19, sc.fc_mode, sc.one_c, sc.fe_idle)
    log(f"collecting {OBSERVE_S:.0f}s")
    sc.events = conn.collect(OBSERVE_S)
    summarize(sc)
    log(f"done {sc.name}: 19={sc.summary['gateway19_count']} FE={sc.summary['FE_count']} FC={sc.summary['FC_count']} 1C={sc.summary['1C_count']} reset={sc.summary['reset_count']} reader={sc.summary['reader_enabled_any']}")
    return sc


def write_outputs(stamp: str, report: str, payload: dict[str, Any]) -> tuple[Path, Path]:
    OUT_DIR.mkdir(exist_ok=True)
    txt = OUT_DIR / f"mdb_1c_fe_sweep_{stamp}.txt"
    js = OUT_DIR / f"mdb_1c_fe_sweep_{stamp}.json"
    txt.write_text(report + "\n", encoding="utf-8")
    js.write_text(json.dumps(payload, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    return txt, js


def report(port: str, debug: dict[str, Any], support_1c: dict[str, str],
           support_fe: dict[str, str], support_fe_idle: dict[str, str],
           scenarios: list[Scenario]) -> str:
    lines: list[str] = []
    lines.append("MDB 1C/FE SWEEP REPORT")
    lines.append(f"date: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    lines.append(f"port: {port}")
    lines.append(f"observation_s: {OBSERVE_S:.0f}")
    lines.append("")
    c = details(debug.get("compact_event"))
    lines.append("Debug-state:")
    lines.append(f"  compact works: {debug['compact_works']}")
    lines.append(f"  full fallback works: {debug['full_fallback_works']}")
    lines.append(f"  mdb_19_response_mode: {c.get('mdb_19_response_mode')}")
    lines.append(f"  mdb_fc_mode: {c.get('mdb_fc_mode')}")
    lines.append(f"  single_wire_mode_enabled: {c.get('single_wire_mode_enabled')}")
    lines.append(f"  mapping: {c.get('mdb_control_byte_mapping')}")
    lines.append(f"  reader_enabled: {c.get('reader_enabled')}")
    lines.append("")
    lines.append("Runtime support:")
    lines.append(f"  mdb_1c_mode supported: {any(v == 'supported' for v in support_1c.values())}")
    lines.append(f"  1C modes: {support_1c}")
    lines.append(f"  mdb_fe_mode supported: {any(v == 'supported' for v in support_fe.values())}")
    lines.append(f"  FE modes via mdb_fe_mode: {support_fe}")
    lines.append(f"  mdb_fe_idle_mode supported: {any(v == 'supported' for v in support_fe_idle.values())}")
    lines.append(f"  FE idle modes: {support_fe_idle}")
    lines.append("")
    lines.append("Scenario table:")
    lines.append("Scenario | mode19 | fc_mode | FE | FE_resp | 19 | setup_resp | FC | FC_resp | 1C true | 1C false | reset | POLL | ENABLE | reader_enabled")
    for sc in scenarios:
        s = sc.summary
        lines.append(
            f"{sc.name} | {sc.mode19} | {sc.fc_mode} | {s['FE_count']} | {s['FE_response']} | "
            f"{s['gateway19_count']} | {s['setup_response_frame']} | {s['FC_count']} | {s['FC_response']} | "
            f"{s['1C_ninth_true']} | {s['1C_ninth_false']} | {s['reset_count']} | {s['POLL_count']} | "
            f"{s['ENABLE_count']} | {s['reader_enabled_any']}"
        )
    lines.append("")
    lines.append("Per-scenario timelines and contexts:")
    for sc in scenarios:
        lines.append(f"\n[{sc.name}] first 40 relevant events:")
        lines.append("  " + " -> ".join(sc.timeline))
        lines.append(f"  FE_before19={sc.summary['FE_before19']} FE_after19={sc.summary['FE_after19']}")
        lines.append(f"  one_c_contexts={len(sc.one_c_contexts)} fe_contexts={len(sc.fe_contexts)} reset_contexts={len(sc.reset_contexts)}")
        for label, ctxs in (("1C", sc.one_c_contexts[:3]), ("FE", sc.fe_contexts[:3]), ("reset", sc.reset_contexts[:3])):
            for ctx in ctxs:
                lines.append(f"  {label} ctx idx={ctx['index']} event={ctx['event']} details={ctx['details']}")
                lines.append(f"    before={ctx['before']}")
                lines.append(f"    after={ctx['after']}")
    lines.append("")
    total_fe_before = sum(sc.summary["FE_before19"] for sc in scenarios)
    total_fe_after = sum(sc.summary["FE_after19"] for sc in scenarios)
    total_1c_true = sum(sc.summary["1C_ninth_true"] for sc in scenarios)
    total_1c_false = sum(sc.summary["1C_ninth_false"] for sc in scenarios)
    any_poll = any(sc.summary["POLL_count"] for sc in scenarios)
    any_enable = any(sc.summary["ENABLE_count"] for sc in scenarios)
    any_reader = any(sc.summary["reader_enabled_any"] for sc in scenarios)
    lines.append("Analysis:")
    lines.append(f"  FE before 19 count: {total_fe_before}")
    lines.append(f"  FE after 19 count: {total_fe_after}")
    lines.append(f"  1C ninth_bit=true count: {total_1c_true}")
    lines.append(f"  1C ninth_bit=false count: {total_1c_false}")
    lines.append(f"  POLL seen: {any_poll}")
    lines.append(f"  ENABLE seen: {any_enable}")
    lines.append(f"  reader_enabled_any: {any_reader}")
    if not any_reader:
        lines.append("  Handshake still not accepted by VMC. Payment delivery must remain gated.")
    lines.append("")
    lines.append("Conclusion questions:")
    lines.append("  Is FC response enough? no" if not any_reader else "  Is FC response enough? unclear/possibly")
    lines.append("  Is 1C likely the next command to answer? see 1C contexts above; do not treat as ENABLE/POLL without proof")
    lines.append("  Is FE likely the earlier key? see FE contexts above; FE is observed separately from POLL")
    lines.append("  Should next patch implement mdb_1c_mode? only if supported modes show better continuation; otherwise no")
    lines.append("  Should next patch implement mdb_fe_mode? mdb_fe_mode alias is unsupported; consider only a diagnostic alias to existing mdb_fe_idle_mode if needed")
    return "\n".join(lines)


def main() -> None:
    port = sys.argv[1] if len(sys.argv) > 1 else DEFAULT_PORT
    conn = Conn(port)
    try:
        conn.collect(2.0)
        debug = debug_sanity(conn)

        reboot(conn)
        support_1c = {m: probe_command(conn, "mdb_1c_mode", m) for m in ["ignore", "ack", "ret", "nak", "ack_enable", "ack_only"]}
        support_fe = {m: probe_command(conn, "mdb_fe_mode", m) for m in ["ignore", "idle_0b", "ack", "ret", "nak", "no_response", "credit"]}
        support_fe_idle = {m: probe_command(conn, "mdb_fe_idle_mode", m) for m in ["no_response", "ack", "just_reset_0b_once", "just_reset_0b_always"]}

        scenarios = [
            Scenario("A", "real_setup_a", "log_only"),
            Scenario("B", "real_setup_a", "ack"),
            Scenario("C", "real_setup_a", "ret"),
            Scenario("D", "real_setup_a", "nak"),
            Scenario("E", "real_setup_g", "ack"),
            Scenario("F", "no_response", "log_only"),
        ]
        for m, name in [("ack", "G_1C_ACK"), ("ret", "H_1C_RET"), ("nak", "I_1C_NAK"), ("ack_enable", "J_1C_ACK_ENABLE")]:
            if support_1c.get(m) == "supported":
                scenarios.append(Scenario(name, "real_setup_a", "ack", one_c=m))
        for m, name in [("no_response", "K_FE_NO_RESPONSE"), ("ack", "L_FE_ACK"), ("just_reset_0b_once", "O_FE_IDLE_0B")]:
            if support_fe_idle.get(m) == "supported":
                scenarios.append(Scenario(name, "real_setup_a", "log_only", fe_idle=m))

        for sc in scenarios:
            run_scenario(conn, sc)

        stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        rep = report(port, debug, support_1c, support_fe, support_fe_idle, scenarios)
        payload = {
            "debug": debug,
            "support_1c": support_1c,
            "support_fe": support_fe,
            "support_fe_idle": support_fe_idle,
            "scenarios": [
                {
                    "name": sc.name,
                    "mode19": sc.mode19,
                    "fc_mode": sc.fc_mode,
                    "one_c": sc.one_c,
                    "fe_idle": sc.fe_idle,
                    "summary": sc.summary,
                    "timeline": sc.timeline,
                    "one_c_contexts": sc.one_c_contexts,
                    "fe_contexts": sc.fe_contexts,
                    "reset_contexts": sc.reset_contexts,
                    "apply_events": sc.apply_events,
                    "events": sc.events,
                }
                for sc in scenarios
            ],
        }
        txt, js = write_outputs(stamp, rep, payload)
        print("\n" + rep)
        log(f"saved txt={txt}")
        log(f"saved json={js}")
    finally:
        conn.close()


if __name__ == "__main__":
    main()
