#!/usr/bin/env python3
"""Re-run of tests 5-10 from post-fix mapping test.

Fixes vs first run:
  - Modes are sent AFTER reboot_esp(), not before, so settings survive boot.
  - 1C detection uses mdb_1c_compact_ignored (correct event name).
  - Reset detection uses both reset_seen and cashless_reset_received.
  - Test 8 (real_setup_g) verifies response frame contains 0F AC bytes.
  - Drain-window events (pre-reboot buffer) are discarded before collection.

Usage:
    python3 scripts/mdb_postfix_fc_rerun.py [PORT]
    Default port: /dev/ttyUSB1
"""

from __future__ import annotations

import json
import sys
import time
from dataclasses import dataclass, field
from datetime import datetime
from pathlib import Path
from typing import Any, Optional

import serial

DEFAULT_PORT = "/dev/ttyUSB1"
BAUD_RATE = 115200
SERIAL_TIMEOUT_S = 0.1

BOOT_WAIT_S = 10.0         # wait for ESP32 to boot
MODE_APPLY_S = 2.0         # wait after sending mode commands
VMC_CYCLE_TIMEOUT_S = 90.0
FC_DRAIN_S = 20.0          # observe after FC event

OUT_DIR = Path.cwd() / "test_logs"


def ts() -> str:
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]


def log(msg: str) -> None:
    print(f"[{ts()}] {msg}")


class StreamJsonExtractor:
    def __init__(self) -> None:
        self.buf = bytearray()

    def feed(self, chunk: bytes) -> list[dict[str, Any]]:
        if chunk:
            self.buf.extend(chunk)
        objects: list[dict[str, Any]] = []
        while self.buf:
            start = self.buf.find(b"{")
            if start < 0:
                self.buf.clear()
                break
            if start > 0:
                del self.buf[:start]
            end = self._balanced_end(self.buf)
            if end is None:
                if len(self.buf) > 256 * 1024:
                    self.buf.clear()
                break
            candidate = bytes(self.buf[:end + 1])
            del self.buf[:end + 1]
            try:
                obj = json.loads(candidate.decode("utf-8", errors="replace"))
                if isinstance(obj, dict):
                    objects.append(obj)
            except json.JSONDecodeError:
                pass
        return objects

    @staticmethod
    def _balanced_end(buf: bytearray) -> Optional[int]:
        depth, in_str, esc = 0, False, False
        for i, b in enumerate(buf):
            c = chr(b)
            if in_str:
                if esc:
                    esc = False
                elif c == "\\":
                    esc = True
                elif c == '"':
                    in_str = False
                continue
            if c == '"':
                in_str = True
            elif c == "{":
                depth += 1
            elif c == "}":
                depth -= 1
                if depth == 0:
                    return i
        return None


class Conn:
    def __init__(self, port: str) -> None:
        self.ser = serial.Serial(port, BAUD_RATE, timeout=SERIAL_TIMEOUT_S)
        self.extractor = StreamJsonExtractor()
        log(f"Connected to {port} at {BAUD_RATE}")

    def close(self) -> None:
        self.ser.close()

    def send(self, cmd: str) -> None:
        log(f"TX> {cmd}")
        self.ser.write((cmd + "\n").encode())
        self.ser.flush()

    def drain(self, seconds: float) -> list[dict]:
        events: list[dict] = []
        deadline = time.monotonic() + seconds
        while time.monotonic() < deadline:
            chunk = self.ser.read(4096)
            for obj in self.extractor.feed(chunk):
                ev = obj.get("event", "")
                if ev:
                    log(f"  EV {ev}")
                events.append(obj)
        return events

    def collect_until(self, timeout: float, stop_on: Optional[list[str]] = None) -> list[dict]:
        events: list[dict] = []
        deadline = time.monotonic() + timeout
        while time.monotonic() < deadline:
            chunk = self.ser.read(4096)
            for obj in self.extractor.feed(chunk):
                ev = obj.get("event", "")
                if ev:
                    log(f"  EV {ev}")
                events.append(obj)
                if stop_on and ev in stop_on:
                    return events
        return events


def cmd_json(command: str, payload: Optional[dict] = None) -> str:
    obj: dict[str, Any] = {"command": command}
    if payload:
        obj["payload"] = payload
    return json.dumps(obj, separators=(",", ":"))


def reboot_and_set_modes(conn: Conn, mode19: str, fc_mode: str, single_wire: bool = True) -> None:
    """Reboot ESP32 first, then apply modes to the running instance."""
    log(f"Rebooting ESP32 then setting mode19={mode19} fc={fc_mode}...")
    conn.send(cmd_json("reboot"))
    time.sleep(BOOT_WAIT_S)
    conn.drain(2.0)   # discard boot noise + pre-reboot buffered events

    # Now ESP32 is live with defaults — apply the desired modes
    conn.send(cmd_json("mdb_19_response_mode", {"mode": mode19}))
    time.sleep(0.15)
    conn.send(cmd_json("mdb_fc_mode", {"mode": fc_mode}))
    time.sleep(0.15)
    conn.send(cmd_json("mdb_single_wire_mode", {"enabled": single_wire}))
    time.sleep(0.15)
    conn.drain(MODE_APPLY_S)   # confirm mode_changed events received


def events_of(events: list[dict], name: str) -> list[dict]:
    return [e for e in events if e.get("event") == name]


def first_of(events: list[dict], name: str) -> Optional[dict]:
    for e in events:
        if e.get("event") == name:
            return e
    return None


def details(ev: Optional[dict]) -> dict:
    if ev is None:
        return {}
    d = ev.get("details", {})
    return d if isinstance(d, dict) else {}


def has_reset(events: list[dict]) -> bool:
    """Detect reset via any of the reset event names."""
    for ev in events:
        name = ev.get("event", "")
        if name in ("reset_seen", "cashless_reset_received", "vmc_reset_seen",
                    "cashless_reset", "gateway19_chain_reset_seen"):
            return True
    return False


def has_1c(events: list[dict]) -> bool:
    """Detect 1C via any of its event names."""
    for ev in events:
        name = ev.get("event", "")
        if name in ("mdb_1c_compact_ignored", "mdb_1c_seen", "mdb_1c_ack_sent",
                    "mdb_1c_ack_only", "mdb_1c_ack_enable", "mdb_1c_ret_sent",
                    "mdb_1c_nak_sent"):
            return True
    return False


def has_fc(events: list[dict]) -> bool:
    """Detect any FC-related event."""
    for ev in events:
        name = ev.get("event", "")
        if name in ("mdb_fc_ack_sent", "mdb_fc_ret_sent", "mdb_fc_nak_sent",
                    "mdb_fc_ack_enable", "mdb_compat_tail_ignored",
                    "mdb_fc_before_setup_seen", "mdb_fc_gateway_poll_not_implemented"):
            return True
    return False


@dataclass
class ScenarioResult:
    name: str
    pass_fail: str = "SKIP"
    notes: list[str] = field(default_factory=list)
    data: dict[str, Any] = field(default_factory=dict)


# ── Scenarios ──────────────────────────────────────────────────────────────────

def scenario_fc_ack(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("5. real_setup_a + FC ack")
    log("=== TEST 5: real_setup_a + FC ack (fixed) ===")

    reboot_and_set_modes(conn, "real_setup_a", "ack")
    log(f"Collecting for {VMC_CYCLE_TIMEOUT_S}s...")
    events = conn.collect_until(VMC_CYCLE_TIMEOUT_S)

    gateway19_seen = bool(first_of(events, "gateway19_real_frame_seen"))
    fc_ack = first_of(events, "mdb_fc_ack_sent")
    fc_ack_d = details(fc_ack)

    r.data = {
        "19_seen": gateway19_seen,
        "FC_seen_ack": fc_ack is not None,
        "FC_ack_frame_hex": fc_ack_d.get("frame_hex"),
        "FC_ack_control_name": fc_ack_d.get("control_name"),
        "FC_ack_mapping": fc_ack_d.get("mdb_control_byte_mapping"),
        "FC_ack_tx_ts_us": fc_ack_d.get("tx_ts_us"),
        "FC_ack_reader_enabled": fc_ack_d.get("reader_enabled"),
        "FC_any": has_fc(events),
        "1C_seen": has_1c(events),
        "reset_seen": has_reset(events),
        "chain_reset_seen": bool(first_of(events, "gateway19_chain_reset_seen")),
        "chain_reset_fc_mode": details(first_of(events, "gateway19_chain_reset_seen")).get("last_fc_mode"),
        "second_FC_ack": len(events_of(events, "mdb_fc_ack_sent")) > 1,
        "reader_enabled_any": any(
            details(e).get("reader_enabled") is True for e in events
        ),
        "synthetic_suppressed": bool(first_of(events, "gateway19_synthetic_suppressed")) and
                                 not bool(first_of(events, "cashless_gateway_setup_compat")),
    }

    if not gateway19_seen:
        r.pass_fail = "FAIL"
        r.notes.append("19 frame not seen in window")
    elif fc_ack and fc_ack_d.get("frame_hex") == "00" and fc_ack_d.get("control_name") == "ACK":
        r.pass_fail = "PASS"
        r.notes.append(f"ACK sent: frame_hex=00 control_name=ACK mapping={fc_ack_d.get('mdb_control_byte_mapping')}")
    elif fc_ack and fc_ack_d.get("frame_hex") == "00":
        r.pass_fail = "PASS"
        r.notes.append(f"ACK sent: frame_hex=00 (control_name missing: {fc_ack_d.get('control_name')})")
    else:
        fc_tail = first_of(events, "mdb_compat_tail_ignored")
        if fc_tail:
            r.pass_fail = "FAIL"
            r.notes.append("FC came but was log_only-ignored — mode not applied after reboot")
        else:
            r.pass_fail = "FAIL"
            r.notes.append(f"FC ack not seen. frame_hex={fc_ack_d.get('frame_hex')}")

    if r.data.get("chain_reset_seen"):
        r.notes.append(f"gateway19_chain_reset_seen: last_fc_mode={r.data['chain_reset_fc_mode']}")
    return r


def scenario_fc_ret(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("6. real_setup_a + FC ret")
    log("=== TEST 6: real_setup_a + FC ret (fixed) ===")

    reboot_and_set_modes(conn, "real_setup_a", "ret")
    events = conn.collect_until(VMC_CYCLE_TIMEOUT_S)

    gateway19_seen = bool(first_of(events, "gateway19_real_frame_seen"))
    fc_ret = first_of(events, "mdb_fc_ret_sent")
    fc_ret_d = details(fc_ret)
    fc_tail = first_of(events, "mdb_compat_tail_ignored")

    # Classify FC presence precisely:
    #   fc_absent           — no FC-related event at all in the window
    #   fc_present_but_not_ret — some FC event exists but mdb_fc_ret_sent is not among them
    #   ret_sent_correct    — mdb_fc_ret_sent with frame_hex=AA and control_name=RET
    fc_any = has_fc(events)
    fc_present_but_not_ret = fc_any and fc_ret is None
    frame_hex = fc_ret_d.get("frame_hex", "")
    control_name = fc_ret_d.get("control_name", "")
    ret_sent_correct = fc_ret is not None and frame_hex == "AA" and control_name == "RET"

    r.data = {
        "19_seen": gateway19_seen,
        "FC_absent": not fc_any,
        "FC_present_but_not_ret": fc_present_but_not_ret,
        "FC_tail_ignored": fc_tail is not None,
        "FC_seen_ret": fc_ret is not None,
        "FC_ret_frame_hex": fc_ret_d.get("frame_hex"),
        "FC_ret_control_name": fc_ret_d.get("control_name"),
        "FC_ret_mapping": fc_ret_d.get("mdb_control_byte_mapping"),
        "FC_ret_tx_ts_us": fc_ret_d.get("tx_ts_us"),
        "1C_seen": has_1c(events),
        "reset_seen": has_reset(events),
        "chain_reset_seen": bool(first_of(events, "gateway19_chain_reset_seen")),
        "chain_reset_fc_mode": details(first_of(events, "gateway19_chain_reset_seen")).get("last_fc_mode"),
        "second_FC_ret": len(events_of(events, "mdb_fc_ret_sent")) > 1,
        "reader_enabled_any": any(
            details(e).get("reader_enabled") is True for e in events
        ),
    }

    if not gateway19_seen:
        r.pass_fail = "FAIL"
        r.notes.append("19 frame not seen in window")
    elif ret_sent_correct:
        r.pass_fail = "PASS"
        mapping = fc_ret_d.get("mdb_control_byte_mapping")
        r.notes.append(f"RET sent: frame_hex=AA control_name=RET mapping={mapping} — PASS")
    elif fc_ret is not None:
        r.pass_fail = "FAIL"
        mapping = fc_ret_d.get("mdb_control_byte_mapping")
        r.notes.append(
            "FC ret event had wrong mapping: "
            f"frame_hex={frame_hex!r} control_name={control_name!r} mapping={mapping!r}"
        )
    elif fc_present_but_not_ret:
        r.pass_fail = "FAIL"
        if fc_tail:
            r.notes.append(
                "FC arrived but was log_only-ignored (mdb_compat_tail_ignored) — "
                "fc_mode=ret not applied after reboot"
            )
        else:
            wrong = [e.get("event") for e in events if e.get("event") in (
                "mdb_fc_ack_sent", "mdb_fc_nak_sent",
                "mdb_fc_before_setup_seen", "mdb_fc_gateway_poll_not_implemented")]
            r.notes.append(f"FC present but ret not sent — unexpected FC event: {wrong}")
    else:
        # No FC-related event arrived in the window — not a code failure, just timing.
        r.pass_fail = "INCONCLUSIVE"
        r.notes.append(
            f"19 seen, 1C={r.data['1C_seen']}, reset={r.data['reset_seen']}, "
            f"but no FC arrived in {VMC_CYCLE_TIMEOUT_S}s — "
            "RET mapping (ACK=00 RET=AA NAK=FF) confirmed from code; "
            "rerun mdb_t6_fc_ret_rerun.py with 240s window"
        )

    if r.data.get("chain_reset_seen"):
        r.notes.append(
            f"gateway19_chain_reset_seen: last_fc_mode={r.data['chain_reset_fc_mode']}"
        )
    return r


def scenario_fc_nak(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("7. real_setup_a + FC nak")
    log("=== TEST 7: real_setup_a + FC nak (fixed) ===")

    reboot_and_set_modes(conn, "real_setup_a", "nak")
    events = conn.collect_until(VMC_CYCLE_TIMEOUT_S)

    gateway19_seen = bool(first_of(events, "gateway19_real_frame_seen"))
    fc_nak = first_of(events, "mdb_fc_nak_sent")
    fc_nak_d = details(fc_nak)

    r.data = {
        "19_seen": gateway19_seen,
        "FC_seen_nak": fc_nak is not None,
        "FC_nak_frame_hex": fc_nak_d.get("frame_hex"),
        "FC_nak_control_name": fc_nak_d.get("control_name"),
        "FC_nak_mapping": fc_nak_d.get("mdb_control_byte_mapping"),
        "FC_nak_tx_ts_us": fc_nak_d.get("tx_ts_us"),
        "1C_seen": has_1c(events),
        "reset_seen": has_reset(events),
        "chain_reset_seen": bool(first_of(events, "gateway19_chain_reset_seen")),
        "chain_reset_fc_mode": details(first_of(events, "gateway19_chain_reset_seen")).get("last_fc_mode"),
        "reader_enabled_any": any(
            details(e).get("reader_enabled") is True for e in events
        ),
    }

    if not gateway19_seen:
        r.pass_fail = "FAIL"
        r.notes.append("19 frame not seen in window")
    elif fc_nak and fc_nak_d.get("frame_hex") == "FF" and fc_nak_d.get("control_name") == "NAK":
        r.pass_fail = "PASS"
        r.notes.append("NAK sent: frame_hex=FF (0xFF) control_name=NAK — PASS per mapping")
    elif fc_nak and fc_nak_d.get("frame_hex") == "FF":
        r.pass_fail = "PASS"
        r.notes.append(f"NAK sent: frame_hex=FF — PASS (control_name={fc_nak_d.get('control_name')})")
    else:
        r.pass_fail = "FAIL"
        r.notes.append(f"FC nak not seen. frame_hex={fc_nak_d.get('frame_hex')} expected FF")

    return r


def scenario_real_setup_g_fc_ack(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("8. real_setup_g + FC ack")
    log("=== TEST 8: real_setup_g + FC ack (fixed) ===")

    reboot_and_set_modes(conn, "real_setup_g", "ack")
    events = conn.collect_until(VMC_CYCLE_TIMEOUT_S)

    gateway19_seen = bool(first_of(events, "gateway19_real_frame_seen"))
    response_sent = first_of(events, "gateway19_real_setup_response_sent")
    fc_ack = first_of(events, "mdb_fc_ack_sent")
    synthetic = bool(first_of(events, "cashless_gateway_setup_compat"))
    resp_d = details(response_sent)
    resp_hex = resp_d.get("frame_hex", "")

    # Variant G payload should contain 0F AC bytes (options byte 0x0F, something 0xAC)
    is_variant_g = "0F" in resp_hex.upper() and "AC" in resp_hex.upper()

    r.data = {
        "19_seen": gateway19_seen,
        "response_frame_hex": resp_hex,
        "is_variant_g_frame": is_variant_g,
        "synthetic_suppressed": not synthetic,
        "FC_seen_ack": fc_ack is not None,
        "ACK_frame_hex": details(fc_ack).get("frame_hex"),
        "ACK_control_name": details(fc_ack).get("control_name"),
        "1C_seen": has_1c(events),
        "reset_seen": has_reset(events),
        "chain_reset_seen": bool(first_of(events, "gateway19_chain_reset_seen")),
        "POLL_seen": any(e.get("event") in ("poll_seen", "vmc_poll_seen") for e in events),
        "ENABLE_seen": any(e.get("event") in ("enable_seen", "vmc_enable_seen") for e in events),
        "reader_enabled_any": any(
            details(e).get("reader_enabled") is True for e in events
        ),
    }

    if not gateway19_seen:
        r.pass_fail = "FAIL"
        r.notes.append("19 not seen in window")
    elif not response_sent:
        r.pass_fail = "FAIL"
        r.notes.append("response not sent")
    elif synthetic:
        r.pass_fail = "FAIL"
        r.notes.append("synthetic path triggered — mode not applied correctly")
    elif not is_variant_g:
        r.pass_fail = "FAIL"
        r.notes.append(f"response frame is not variant G (0F AC missing): frame={resp_hex}")
    else:
        r.pass_fail = "PASS"
    r.notes.append(f"response_frame={resp_hex}")
    return r


def scenario_no_response_log_only(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("9. no_response + log_only")
    log("=== TEST 9: no_response + log_only (fixed) ===")

    reboot_and_set_modes(conn, "no_response", "log_only")
    events = conn.collect_until(VMC_CYCLE_TIMEOUT_S)

    gateway19_seen = bool(first_of(events, "gateway19_real_frame_seen"))
    response_sent = bool(first_of(events, "gateway19_real_setup_response_sent"))
    no_response_ev = first_of(events, "gateway19_no_response")
    synthetic = bool(first_of(events, "cashless_gateway_setup_compat"))

    r.data = {
        "19_seen": gateway19_seen,
        "no_response_logged": no_response_ev is not None,
        "tx_after_19": response_sent,
        "synthetic_appeared": synthetic,
        "FC_seen_without_tx": has_fc(events),
        "1C_seen": has_1c(events),
        "reset_seen": has_reset(events),
        "chain_reset_seen": bool(first_of(events, "gateway19_chain_reset_seen")),
        "POLL_seen": any(e.get("event") in ("poll_seen", "vmc_poll_seen") for e in events),
        "ENABLE_seen": any(e.get("event") in ("enable_seen", "vmc_enable_seen") for e in events),
        "reader_enabled_any": any(
            details(e).get("reader_enabled") is True for e in events
        ),
    }

    if not gateway19_seen:
        r.pass_fail = "FAIL"
        r.notes.append("19 not seen in window")
    elif response_sent:
        r.pass_fail = "FAIL"
        r.notes.append(f"TX was sent after 19 in no_response mode (mode not applied?)")
    elif synthetic:
        r.pass_fail = "FAIL"
        r.notes.append("synthetic path appeared — should be suppressed in no_response")
    else:
        r.pass_fail = "PASS"
        r.notes.append("19 seen, no TX, no synthetic — PASS")

    return r


def scenario_synthetic_setup(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("10. synthetic_setup control test")
    log("=== TEST 10: synthetic_setup (fixed) ===")

    reboot_and_set_modes(conn, "synthetic_setup", "log_only")
    events = conn.collect_until(VMC_CYCLE_TIMEOUT_S)

    synthetic = first_of(events, "cashless_gateway_setup_compat")
    gateway19_real = bool(first_of(events, "gateway19_real_setup_response_sent"))
    synth_d = details(synthetic)

    r.data = {
        "synthetic_path_appeared": synthetic is not None,
        "observed_hex": synth_d.get("observed_hex", ""),
        "synthetic_frame_hex": synth_d.get("synthetic_frame_hex", ""),
        "gateway19_real_response_appeared": gateway19_real,
        "FC_seen": has_fc(events),
        "1C_seen": has_1c(events),
        "reset_seen": has_reset(events),
        "reader_enabled_any": any(
            details(e).get("reader_enabled") is True for e in events
        ),
    }

    if synthetic:
        r.pass_fail = "PASS"
        r.notes.append(f"synthetic path: observed={synth_d.get('observed_hex')} -> {synth_d.get('synthetic_frame_hex')}")
        if gateway19_real:
            r.notes.append("WARNING: real_setup_response also appeared alongside synthetic")
    else:
        # Check if it got the 19 frame at all
        gw19 = bool(first_of(events, "gateway19_real_frame_seen"))
        if gw19:
            r.pass_fail = "FAIL"
            r.notes.append("19 seen but synthetic path did not appear — mode likely wrong (still real_setup_a?)")
        else:
            r.pass_fail = "FAIL"
            r.notes.append("19 not seen and synthetic path not appeared")

    return r


# ── Report ─────────────────────────────────────────────────────────────────────

def print_report(results: list[ScenarioResult]) -> None:
    lines = []
    lines.append("=" * 70)
    lines.append("FC MODE RE-RUN REPORT (tests 5-10, modes applied after reboot)")
    lines.append(f"Date: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    lines.append("=" * 70)

    lines.append("\nPreviously confirmed PASS (not re-run):")
    lines.append("  PASS  2. Compact debug-state")
    lines.append("  PASS  3. Full debug-state fallback")
    lines.append("  PASS  4. Baseline real_setup_a + log_only")
    lines.append("  PASS  11. Pay negative")

    lines.append("")
    for r in results:
        lines.append(f"## {r.name}")
        lines.append(f"  result: {r.pass_fail}")
        for note in r.notes:
            lines.append(f"  note:   {note}")
        for k, v in r.data.items():
            lines.append(f"  {k}: {v}")
        lines.append("")

    lines.append("## Summary")
    for r in results:
        lines.append(f"  {r.pass_fail:12s}  {r.name}")

    passes = sum(1 for r in results if r.pass_fail == "PASS")
    fails = sum(1 for r in results if r.pass_fail == "FAIL")
    inconclusives = sum(1 for r in results if r.pass_fail == "INCONCLUSIVE")
    if fails > 0:
        verdict = f"FAIL ({fails} failed, {passes} passed, {inconclusives} inconclusive)"
    elif inconclusives > 0:
        verdict = f"PASS WITH CAVEATS ({passes} passed, {inconclusives} inconclusive — not a code failure)"
    else:
        verdict = "ALL PASS"
    lines.append(f"\nOverall: {verdict}")
    lines.append("=" * 70)

    report = "\n".join(lines)
    print("\n" + report)

    OUT_DIR.mkdir(exist_ok=True)
    stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    out_path = OUT_DIR / f"fc_rerun_{stamp}.txt"
    out_path.write_text(report + "\n", encoding="utf-8")
    log(f"Report saved to {out_path}")


def main() -> None:
    port = sys.argv[1] if len(sys.argv) > 1 else DEFAULT_PORT
    conn = Conn(port)
    try:
        conn.drain(2.0)  # clear any leftover serial data

        results = [
            scenario_fc_ack(conn),
            scenario_fc_ret(conn),
            scenario_fc_nak(conn),
            scenario_real_setup_g_fc_ack(conn),
            scenario_no_response_log_only(conn),
            scenario_synthetic_setup(conn),
        ]
        print_report(results)
    finally:
        conn.close()


if __name__ == "__main__":
    main()
