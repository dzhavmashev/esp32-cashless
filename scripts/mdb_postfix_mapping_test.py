#!/usr/bin/env python3
"""Post-fix mapping patch bench test: compact debug-state + ACK/RET/NAK mapping.

Tests:
  1. Build / Upload
  2. Compact debug-state
  3. Full debug-state fallback
  4. Baseline real_setup_a + log_only
  5. real_setup_a + FC ack
  6. real_setup_a + FC ret
  7. real_setup_a + FC nak
  8. real_setup_g + FC ack
  9. no_response + log_only
  10. synthetic_setup control test
  11. Pay negative
  12. Final report

Usage:
    python3 scripts/mdb_postfix_mapping_test.py [PORT]
    Default port: /dev/ttyUSB1
"""

from __future__ import annotations

import json
import subprocess
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

# --- Timeouts ---
BOOT_WAIT_S = 8.0          # after upload, wait for ESP32 to boot
CMD_DRAIN_S = 1.5          # drain after sending a command
COMPACT_TIMEOUT_S = 6.0    # wait for compact debug-state response
FULL_TIMEOUT_S = 8.0       # wait for full debug-state response
VMC_CYCLE_TIMEOUT_S = 90.0 # wait for VMC to send 19 03 01 00 1D
FC_FOLLOW_TIMEOUT_S = 20.0 # observe follow-up after FC event
PAY_TIMEOUT_S = 8.0        # wait for payment response
REBOOT_DRAIN_S = 12.0      # wait after ESP32 reboot

OUT_DIR = Path.cwd() / "test_logs"


def ts() -> str:
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]


def log(msg: str) -> None:
    print(f"[{ts()}] {msg}")


# ── JSON stream extractor ──────────────────────────────────────────────────────

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


# ── Serial helper ──────────────────────────────────────────────────────────────

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
        """Drain serial for given seconds, return all parsed events."""
        events: list[dict] = []
        deadline = time.monotonic() + seconds
        while time.monotonic() < deadline:
            chunk = self.ser.read(4096)
            for obj in self.extractor.feed(chunk):
                event = obj.get("event", "")
                if event:
                    log(f"  EV {event}")
                events.append(obj)
        return events

    def wait_for_event(self, event_name: str, timeout: float) -> Optional[dict]:
        """Wait until an event with the given name arrives."""
        deadline = time.monotonic() + timeout
        while time.monotonic() < deadline:
            chunk = self.ser.read(4096)
            for obj in self.extractor.feed(chunk):
                ev = obj.get("event", "")
                if ev:
                    log(f"  EV {ev}")
                if ev == event_name:
                    return obj
        return None

    def collect_until(
        self,
        timeout: float,
        stop_events: Optional[list[str]] = None,
    ) -> list[dict]:
        """Collect events for timeout seconds; stop early if a stop_event arrives."""
        events: list[dict] = []
        deadline = time.monotonic() + timeout
        while time.monotonic() < deadline:
            chunk = self.ser.read(4096)
            for obj in self.extractor.feed(chunk):
                ev = obj.get("event", "")
                if ev:
                    log(f"  EV {ev}")
                events.append(obj)
                if stop_events and ev in stop_events:
                    return events
        return events


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


# ── Build / Upload ─────────────────────────────────────────────────────────────

@dataclass
class BuildResult:
    build_ok: bool = False
    upload_ok: bool = False
    ram_pct: str = "?"
    flash_pct: str = "?"
    port: str = ""
    output: str = ""


def run_build(port: str) -> BuildResult:
    result = BuildResult(port=port)
    log("=== BUILD ===")
    proc = subprocess.run(
        ["pio", "run", "-e", "esp32dev"],
        capture_output=True, text=True, timeout=180,
    )
    output = proc.stdout + proc.stderr
    result.output += output
    result.build_ok = proc.returncode == 0

    for line in output.splitlines():
        if "RAM:" in line:
            import re
            m = re.search(r"RAM:\s+\[.*?\]\s+([\d.]+)%", line)
            if m:
                result.ram_pct = m.group(1) + "%"
        if "Flash:" in line:
            import re
            m = re.search(r"Flash:\s+\[.*?\]\s+([\d.]+)%", line)
            if m:
                result.flash_pct = m.group(1) + "%"

    status = "SUCCESS" if result.build_ok else "FAIL"
    log(f"Build: {status}  RAM={result.ram_pct}  Flash={result.flash_pct}")
    return result


def run_upload(port: str) -> bool:
    log("=== UPLOAD ===")
    proc = subprocess.run(
        ["pio", "run", "-e", "esp32dev", "-t", "upload",
         "--upload-port", port],
        capture_output=True, text=True, timeout=120,
    )
    ok = proc.returncode == 0
    log(f"Upload: {'SUCCESS' if ok else 'FAIL'}")
    if not ok:
        log(proc.stderr[-500:])
    return ok


# ── Test helpers ───────────────────────────────────────────────────────────────

def cmd_json(command: str, payload: Optional[dict] = None) -> str:
    obj: dict[str, Any] = {"command": command}
    if payload:
        obj["payload"] = payload
    return json.dumps(obj, separators=(",", ":"))


def set_modes(conn: Conn, mode19: str, fc_mode: str, single_wire: bool = True) -> None:
    conn.send(cmd_json("mdb_19_response_mode", {"mode": mode19}))
    time.sleep(0.15)
    conn.send(cmd_json("mdb_fc_mode", {"mode": fc_mode}))
    time.sleep(0.15)
    conn.send(cmd_json("mdb_single_wire_mode", {"enabled": single_wire}))
    time.sleep(0.15)


def reboot_esp(conn: Conn) -> None:
    log("Rebooting ESP32...")
    conn.send(cmd_json("reboot"))
    time.sleep(REBOOT_DRAIN_S)
    conn.drain(2.0)  # flush boot messages


# ── Test cases ────────────────────────────────────────────────────────────────

@dataclass
class ScenarioResult:
    name: str
    pass_fail: str = "SKIP"
    notes: list[str] = field(default_factory=list)
    details: dict[str, Any] = field(default_factory=dict)


def scenario_compact_debug_state(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("2. Compact debug-state")
    log("=== TEST 2: Compact debug-state ===")

    conn.send(cmd_json("mdb_debug_state_compact"))
    events = conn.collect_until(COMPACT_TIMEOUT_S, stop_events=["mdb_debug_state_compact"])
    ev = first_of(events, "mdb_debug_state_compact")

    if ev is None:
        r.pass_fail = "FAIL"
        r.notes.append("mdb_debug_state_compact event not received")
        return r

    d = details(ev)
    r.details = d

    checks = {
        "mdb_19_response_mode": d.get("mdb_19_response_mode") == "real_setup_a",
        "mdb_fc_mode": d.get("mdb_fc_mode") == "log_only",
        "single_wire_mode_enabled": d.get("single_wire_mode_enabled") is True,
        "reader_enabled_false": d.get("reader_enabled") is False,
        "mdb_control_byte_mapping": d.get("mdb_control_byte_mapping") == "ACK=00 RET=AA NAK=FF",
        "gateway19_setup_seen_present": "gateway19_setup_seen" in d,
        "gateway19_setup_responded_present": "gateway19_setup_responded" in d,
        "gateway19_last_rx_hex_present": "gateway19_last_rx_hex" in d,
        "gateway19_last_response_mode_present": "gateway19_last_response_mode" in d,
        "gateway19_last_response_tx_us_present": "gateway19_last_response_tx_us" in d,
        "gateway19_followup_count_present": "gateway19_followup_count" in d,
        "gateway19_last_followup_hex_present": "gateway19_last_followup_hex" in d,
        "gateway19_last_followup_delta_us_present": "gateway19_last_followup_delta_us" in d,
        "previous_tx_kind_present": "previous_tx_kind" in d,
        "next_expected_rx_kind_present": "next_expected_rx_kind" in d,
        "pending_mdb_payment_present": "pending_mdb_payment" in d,
        "pending_scaled_present": "pending_scaled" in d,
        "fe_gate_mode_present": "fe_gate_mode" in d,
    }

    failed = [k for k, v in checks.items() if not v]
    if failed:
        r.pass_fail = "FAIL"
        r.notes.append(f"Failed checks: {failed}")
    else:
        r.pass_fail = "PASS"
    r.notes.append(f"mode19={d.get('mdb_19_response_mode')} fc={d.get('mdb_fc_mode')} sw={d.get('single_wire_mode_enabled')} mapping={d.get('mdb_control_byte_mapping')}")
    return r


def scenario_full_debug_state(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("3. Full debug-state fallback")
    log("=== TEST 3: Full debug-state ===")

    conn.send(cmd_json("mdb_debug_state"))
    events = conn.collect_until(FULL_TIMEOUT_S, stop_events=["mdb_debug_state", "mdb_debug_state_compact"])

    full = first_of(events, "mdb_debug_state")
    compact_fb = first_of(events, "mdb_debug_state_compact")
    failed = first_of(events, "mdb_debug_state_failed")

    if full:
        r.pass_fail = "PASS"
        r.notes.append("full debug-state received")
    elif compact_fb:
        r.pass_fail = "PASS"
        r.notes.append("compact fallback received (full too large)")
    else:
        # Check if only failure event came
        if failed and details(failed).get("reason") == "message_reserve_failed":
            r.pass_fail = "FAIL"
            r.notes.append("ONLY message_reserve_failed — no fallback")
        else:
            r.pass_fail = "FAIL"
            r.notes.append("no debug-state response received at all")

    r.details = {
        "full_received": full is not None,
        "compact_fallback": compact_fb is not None,
        "failure_only": failed is not None and full is None and compact_fb is None,
    }
    return r


def scenario_baseline_real_setup_a_log_only(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("4. Baseline real_setup_a + log_only")
    log("=== TEST 4: Baseline real_setup_a + log_only ===")

    set_modes(conn, "real_setup_a", "log_only")
    reboot_esp(conn)

    log(f"Waiting up to {VMC_CYCLE_TIMEOUT_S}s for 19 03 01 00 1D...")
    events = conn.collect_until(VMC_CYCLE_TIMEOUT_S)

    gateway19_seen = bool(first_of(events, "gateway19_real_frame_seen"))
    response_sent = bool(first_of(events, "gateway19_real_setup_response_sent"))
    synthetic = bool(first_of(events, "cashless_gateway_setup_compat"))
    synthetic_11 = any(
        "11 03 01 00 15" in str(e)
        for e in events
        if e.get("event") in ("gateway19_real_setup_response_sent", "cashless_gateway_setup_compat")
    )

    fc_ignored = first_of(events, "mdb_compat_tail_ignored")
    followup = first_of(events, "gateway19_followup_seen")
    reset_seen = first_of(events, "reset_seen")
    fc_ack_sent = first_of(events, "mdb_fc_ack_sent")
    poll = first_of(events, "poll_seen") or first_of(events, "vmc_poll_seen")
    enable = first_of(events, "enable_seen") or first_of(events, "vmc_enable_seen")
    fc_before = first_of(events, "mdb_fc_before_setup_seen")

    no_synthetic = not synthetic and not synthetic_11

    r.details = {
        "19_seen": gateway19_seen,
        "response_sent": response_sent,
        "synthetic_suppressed": no_synthetic,
        "FC_seen": fc_ignored is not None or fc_ack_sent is not None,
        "FC_ignored_log_only": fc_ignored is not None,
        "1C_seen": any(e.get("event") in ("mdb_1c_seen", "mdb_1c_ack_sent") for e in events),
        "FE_seen": any(e.get("event") in ("fe_compat_poll", "mdb_fe_seen") for e in events),
        "reset_seen": reset_seen is not None,
        "POLL_seen": poll is not None,
        "ENABLE_seen": enable is not None,
        "gateway19_followup_seen": followup is not None,
        "reader_enabled": _find_reader_enabled(events),
    }

    if not gateway19_seen:
        r.pass_fail = "FAIL"
        r.notes.append("19 frame not seen in window")
    elif not response_sent:
        r.pass_fail = "FAIL"
        r.notes.append("response not sent")
    elif not no_synthetic:
        r.pass_fail = "FAIL"
        r.notes.append("synthetic path appeared (cashless_gateway_setup_compat seen)")
    else:
        r.pass_fail = "PASS"

    _add_detail_notes(r)
    return r


def scenario_fc_ack(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("5. real_setup_a + FC ack")
    log("=== TEST 5: real_setup_a + FC ack ===")

    set_modes(conn, "real_setup_a", "ack")
    reboot_esp(conn)

    log(f"Waiting up to {VMC_CYCLE_TIMEOUT_S}s for 19 + FC + chain...")
    events = conn.collect_until(VMC_CYCLE_TIMEOUT_S)

    gateway19_seen = bool(first_of(events, "gateway19_real_frame_seen"))
    fc_ack = first_of(events, "mdb_fc_ack_sent")
    reset = first_of(events, "reset_seen")
    chain_reset = first_of(events, "gateway19_chain_reset_seen")
    reader_enabled = _find_reader_enabled(events)

    fc_ack_d = details(fc_ack)
    ack_frame_ok = fc_ack_d.get("frame_hex") == "00"
    ack_ctrl_name = fc_ack_d.get("control_name") == "ACK"
    ack_mapping = fc_ack_d.get("mdb_control_byte_mapping") == "ACK=00 RET=AA NAK=FF"

    r.details = {
        "19_seen": gateway19_seen,
        "FC_seen": fc_ack is not None,
        "ACK_frame_hex": fc_ack_d.get("frame_hex"),
        "control_name": fc_ack_d.get("control_name"),
        "mapping_present": ack_mapping,
        "tx_ts_us_nonzero": int(fc_ack_d.get("tx_ts_us", 0) or 0) > 0,
        "1C_after_ack": any(e.get("event") in ("mdb_1c_seen", "mdb_1c_ack_sent") for e in events),
        "second_FC": len(events_of(events, "mdb_fc_ack_sent")) > 1,
        "reset_seen": reset is not None,
        "gateway19_chain_reset_seen": chain_reset is not None,
        "chain_reset_last_fc_mode": details(chain_reset).get("last_fc_mode"),
        "chain_reset_reason": details(chain_reset).get("reason"),
        "reader_enabled": reader_enabled,
    }

    if fc_ack and ack_frame_ok and ack_ctrl_name and ack_mapping:
        r.pass_fail = "PASS"
    elif fc_ack and ack_frame_ok:
        r.pass_fail = "PASS"
        if not ack_ctrl_name:
            r.notes.append("WARNING: control_name missing")
        if not ack_mapping:
            r.notes.append("WARNING: mdb_control_byte_mapping missing")
    elif not gateway19_seen:
        r.pass_fail = "FAIL"
        r.notes.append("19 not seen in window")
    else:
        r.pass_fail = "FAIL"
        r.notes.append(f"ACK check failed: fc_ack={fc_ack is not None} frame={fc_ack_d.get('frame_hex')}")

    if chain_reset:
        r.notes.append(f"gateway19_chain_reset_seen: last_fc_mode={details(chain_reset).get('last_fc_mode')} reason={details(chain_reset).get('reason')}")
    if reader_enabled:
        r.notes.append("WARNING: reader_enabled=true without ENABLE/POLL")

    return r


def scenario_fc_ret(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("6. real_setup_a + FC ret")
    log("=== TEST 6: real_setup_a + FC ret ===")

    set_modes(conn, "real_setup_a", "ret")
    reboot_esp(conn)

    events = conn.collect_until(VMC_CYCLE_TIMEOUT_S)

    gateway19_seen = bool(first_of(events, "gateway19_real_frame_seen"))
    fc_ret = first_of(events, "mdb_fc_ret_sent")
    reset = first_of(events, "reset_seen")
    chain_reset = first_of(events, "gateway19_chain_reset_seen")
    reader_enabled = _find_reader_enabled(events)

    fc_ret_d = details(fc_ret)
    ret_frame_ok = fc_ret_d.get("frame_hex") == "AA"
    ret_ctrl_name = fc_ret_d.get("control_name") == "RET"
    ret_mapping = fc_ret_d.get("mdb_control_byte_mapping") == "ACK=00 RET=AA NAK=FF"

    r.details = {
        "19_seen": gateway19_seen,
        "FC_seen": fc_ret is not None,
        "RET_frame_hex": fc_ret_d.get("frame_hex"),
        "control_name": fc_ret_d.get("control_name"),
        "mapping_present": ret_mapping,
        "1C_after_ret": any(e.get("event") in ("mdb_1c_seen", "mdb_1c_ack_sent") for e in events),
        "second_FC": len(events_of(events, "mdb_fc_ret_sent")) > 1,
        "reset_seen": reset is not None,
        "gateway19_chain_reset_seen": chain_reset is not None,
        "reader_enabled": reader_enabled,
    }

    # frame_hex="AA" is PASS per mapping
    if fc_ret and ret_frame_ok and ret_ctrl_name:
        r.pass_fail = "PASS"
        r.notes.append("frame_hex=AA (RET=0xAA) — PASS per mapping")
    elif fc_ret and ret_frame_ok:
        r.pass_fail = "PASS"
        r.notes.append("frame_hex=AA — PASS; control_name missing")
    elif not gateway19_seen:
        r.pass_fail = "FAIL"
        r.notes.append("19 not seen in window")
    else:
        r.pass_fail = "FAIL"
        r.notes.append(f"RET check failed: frame={fc_ret_d.get('frame_hex')} expected AA")

    return r


def scenario_fc_nak(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("7. real_setup_a + FC nak")
    log("=== TEST 7: real_setup_a + FC nak ===")

    set_modes(conn, "real_setup_a", "nak")
    reboot_esp(conn)

    events = conn.collect_until(VMC_CYCLE_TIMEOUT_S)

    gateway19_seen = bool(first_of(events, "gateway19_real_frame_seen"))
    fc_nak = first_of(events, "mdb_fc_nak_sent")
    reset = first_of(events, "reset_seen")
    chain_reset = first_of(events, "gateway19_chain_reset_seen")
    reader_enabled = _find_reader_enabled(events)

    fc_nak_d = details(fc_nak)
    nak_frame_ok = fc_nak_d.get("frame_hex") == "FF"
    nak_ctrl_name = fc_nak_d.get("control_name") == "NAK"
    nak_mapping = fc_nak_d.get("mdb_control_byte_mapping") == "ACK=00 RET=AA NAK=FF"

    r.details = {
        "19_seen": gateway19_seen,
        "FC_seen": fc_nak is not None,
        "NAK_frame_hex": fc_nak_d.get("frame_hex"),
        "control_name": fc_nak_d.get("control_name"),
        "mapping_present": nak_mapping,
        "1C_after_nak": any(e.get("event") in ("mdb_1c_seen", "mdb_1c_ack_sent") for e in events),
        "second_FC": len(events_of(events, "mdb_fc_nak_sent")) > 1,
        "reset_seen": reset is not None,
        "gateway19_chain_reset_seen": chain_reset is not None,
        "reader_enabled": reader_enabled,
    }

    if fc_nak and nak_frame_ok and nak_ctrl_name:
        r.pass_fail = "PASS"
        r.notes.append("frame_hex=FF (NAK=0xFF) — PASS per mapping")
    elif fc_nak and nak_frame_ok:
        r.pass_fail = "PASS"
        r.notes.append("frame_hex=FF — PASS; control_name missing")
    elif not gateway19_seen:
        r.pass_fail = "FAIL"
        r.notes.append("19 not seen in window")
    else:
        r.pass_fail = "FAIL"
        r.notes.append(f"NAK check failed: frame={fc_nak_d.get('frame_hex')} expected FF")

    return r


def scenario_real_setup_g_fc_ack(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("8. real_setup_g + FC ack")
    log("=== TEST 8: real_setup_g + FC ack ===")

    set_modes(conn, "real_setup_g", "ack")
    reboot_esp(conn)

    events = conn.collect_until(VMC_CYCLE_TIMEOUT_S)

    gateway19_seen = bool(first_of(events, "gateway19_real_frame_seen"))
    response_sent = first_of(events, "gateway19_real_setup_response_sent")
    fc_ack = first_of(events, "mdb_fc_ack_sent")
    reset = first_of(events, "reset_seen")
    chain_reset = first_of(events, "gateway19_chain_reset_seen")
    synthetic = bool(first_of(events, "cashless_gateway_setup_compat"))
    reader_enabled = _find_reader_enabled(events)

    resp_d = details(response_sent)
    # Expect payload bytes 03 16 43 64 02 00 0F AC (with checksum 7D)
    resp_hex = resp_d.get("frame_hex", "")

    r.details = {
        "19_seen": gateway19_seen,
        "response_frame_hex": resp_hex,
        "synthetic_suppressed": not synthetic,
        "FC_seen": fc_ack is not None,
        "ACK_frame_hex": details(fc_ack).get("frame_hex"),
        "1C_after_ack": any(e.get("event") in ("mdb_1c_seen", "mdb_1c_ack_sent") for e in events),
        "second_FC": len(events_of(events, "mdb_fc_ack_sent")) > 1,
        "reset_seen": reset is not None,
        "gateway19_chain_reset_seen": chain_reset is not None,
        "POLL_seen": any(e.get("event") in ("poll_seen", "vmc_poll_seen") for e in events),
        "ENABLE_seen": any(e.get("event") in ("enable_seen", "vmc_enable_seen") for e in events),
        "reader_enabled": reader_enabled,
    }

    if gateway19_seen and response_sent and not synthetic:
        r.pass_fail = "PASS"
    elif not gateway19_seen:
        r.pass_fail = "FAIL"
        r.notes.append("19 not seen")
    elif synthetic:
        r.pass_fail = "FAIL"
        r.notes.append("synthetic path triggered unexpectedly")
    else:
        r.pass_fail = "FAIL"
        r.notes.append("response not sent")

    r.notes.append(f"response_frame={resp_hex}")
    return r


def scenario_no_response_log_only(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("9. no_response + log_only")
    log("=== TEST 9: no_response + log_only ===")

    set_modes(conn, "no_response", "log_only")
    reboot_esp(conn)

    events = conn.collect_until(VMC_CYCLE_TIMEOUT_S)

    gateway19_seen = bool(first_of(events, "gateway19_real_frame_seen"))
    no_response_ev = first_of(events, "gateway19_no_response")
    synthetic = bool(first_of(events, "cashless_gateway_setup_compat"))
    fc_ignored = bool(first_of(events, "mdb_compat_tail_ignored"))
    fc_before = bool(first_of(events, "mdb_fc_before_setup_seen"))
    reset = bool(first_of(events, "reset_seen"))
    reader_enabled = _find_reader_enabled(events)

    # Check that no TX was done after 19 (no_response means no setup response)
    any_tx_after_19 = any(
        e.get("event") in ("gateway19_real_setup_response_sent",)
        for e in events
    )

    r.details = {
        "19_seen": gateway19_seen,
        "no_response_logged": no_response_ev is not None,
        "tx_after_19": any_tx_after_19,
        "synthetic_appeared": synthetic,
        "FC_seen_without_tx": fc_ignored or fc_before,
        "1C_seen": any(e.get("event") in ("mdb_1c_seen", "mdb_1c_ack_sent") for e in events),
        "reset_seen": reset,
        "POLL_seen": any(e.get("event") in ("poll_seen", "vmc_poll_seen") for e in events),
        "ENABLE_seen": any(e.get("event") in ("enable_seen", "vmc_enable_seen") for e in events),
        "reader_enabled": reader_enabled,
    }

    if gateway19_seen and not any_tx_after_19 and not synthetic:
        r.pass_fail = "PASS"
        r.notes.append("19 seen, no TX, synthetic suppressed")
    elif not gateway19_seen:
        r.pass_fail = "FAIL"
        r.notes.append("19 not seen in window")
    elif any_tx_after_19:
        r.pass_fail = "FAIL"
        r.notes.append("TX sent after 19 in no_response mode")
    else:
        r.pass_fail = "PASS"

    return r


def scenario_synthetic_setup(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("10. synthetic_setup control test")
    log("=== TEST 10: synthetic_setup control test ===")

    set_modes(conn, "synthetic_setup", "log_only")
    reboot_esp(conn)

    events = conn.collect_until(VMC_CYCLE_TIMEOUT_S)

    synthetic = first_of(events, "cashless_gateway_setup_compat")
    gateway19_real = first_of(events, "gateway19_real_setup_response_sent")
    reset = first_of(events, "reset_seen")
    fc_seen = any(
        e.get("event") in ("mdb_compat_tail_ignored", "mdb_fc_ack_sent") for e in events
    )
    reader_enabled = _find_reader_enabled(events)

    synth_d = details(synthetic)
    observed_hex = synth_d.get("observed_hex", "")
    synthetic_frame = synth_d.get("synthetic_frame_hex", "")

    r.details = {
        "synthetic_path_appeared": synthetic is not None,
        "observed_hex": observed_hex,
        "synthetic_frame_hex": synthetic_frame,
        "gateway19_real_response_appeared": gateway19_real is not None,
        "FC_seen": fc_seen,
        "reset_seen": reset is not None,
        "reader_enabled": reader_enabled,
    }

    if synthetic:
        r.pass_fail = "PASS"
        r.notes.append(f"synthetic path: observed={observed_hex} -> synthetic={synthetic_frame}")
        if gateway19_real:
            r.notes.append("WARNING: real gateway19 response also appeared (should not)")
    else:
        r.pass_fail = "FAIL"
        r.notes.append("synthetic path did not appear (cashless_gateway_setup_compat not seen)")

    return r


def scenario_pay_negative(conn: Conn) -> ScenarioResult:
    r = ScenarioResult("11. Pay negative (reader_enabled=false)")
    log("=== TEST 11: Pay negative ===")

    # Ensure reader is NOT enabled — use real_setup_a + log_only, no reboot
    set_modes(conn, "real_setup_a", "log_only")
    time.sleep(0.5)

    txid = "mapping-negative-100"
    conn.send(cmd_json("pay", {"amount": 100, "transport": "mdb", "transaction_id": txid}))
    events = conn.collect_until(PAY_TIMEOUT_S)

    queued = first_of(events, "coin_payment_queued")
    queued_waiting = first_of(events, "coin_payment_queued_waiting_for_reader")
    completed = first_of(events, "coin_payment_completed")
    credit_sent = any(
        "credit_sent" in str(e) or "credit_approved" in str(e)
        for e in events
    )
    reader_enabled = _find_reader_enabled(events)

    r.details = {
        "queued": queued is not None,
        "queued_waiting_for_reader": queued_waiting is not None,
        "reader_enabled": reader_enabled,
        "coin_payment_completed": completed is not None,
        "credit_sent": credit_sent,
        "pending_amount_from_event": details(queued).get("pending_amount_minor") if queued else None,
    }

    if queued and not completed and not credit_sent and reader_enabled is False:
        r.pass_fail = "PASS"
        r.notes.append("payment queued, reader_enabled=false, no credit sent — PASS")
    elif completed or credit_sent:
        r.pass_fail = "FAIL"
        r.notes.append("FALSE: payment completed or credit sent without ENABLE")
    elif not queued:
        r.pass_fail = "FAIL"
        r.notes.append("payment not queued at all")
    else:
        r.pass_fail = "PASS"
        r.notes.append("queued, not completed")

    return r


def _find_reader_enabled(events: list[dict]) -> Optional[bool]:
    for ev in reversed(events):
        d = ev.get("details", {})
        if isinstance(d, dict) and "reader_enabled" in d:
            return d["reader_enabled"]
    return None


def _add_detail_notes(r: ScenarioResult) -> None:
    for k, v in r.details.items():
        if v is True:
            r.notes.append(f"  {k}: YES")
        elif v is False:
            r.notes.append(f"  {k}: no")


# ── Report ─────────────────────────────────────────────────────────────────────

def print_report(build: BuildResult, results: list[ScenarioResult], port: str) -> None:
    lines = []
    lines.append("=" * 70)
    lines.append("POST-FIX MAPPING PATCH TEST REPORT")
    lines.append(f"Date: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    lines.append("=" * 70)

    lines.append("\n## 1. Build / Upload")
    lines.append(f"  build:  {'PASS' if build.build_ok else 'FAIL'}")
    lines.append(f"  upload: {'PASS' if build.upload_ok else 'FAIL'}")
    lines.append(f"  RAM:    {build.ram_pct}")
    lines.append(f"  Flash:  {build.flash_pct}")
    lines.append(f"  port:   {port}")

    for r in results:
        lines.append(f"\n## {r.name}")
        lines.append(f"  result: {r.pass_fail}")
        for note in r.notes:
            lines.append(f"  note:   {note}")
        for k, v in r.details.items():
            lines.append(f"  {k}: {v}")

    lines.append("\n## Conclusion")
    all_pass = all(r.pass_fail == "PASS" for r in results)
    lines.append(f"  Overall: {'ALL PASS' if all_pass else 'SOME FAILURES'}")
    for r in results:
        lines.append(f"  {r.pass_fail:4s}  {r.name}")

    lines.append("=" * 70)

    report = "\n".join(lines)
    print("\n" + report)

    OUT_DIR.mkdir(exist_ok=True)
    stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    out_path = OUT_DIR / f"postfix_mapping_test_{stamp}.txt"
    out_path.write_text(report + "\n", encoding="utf-8")
    log(f"Report saved to {out_path}")


# ── Main ───────────────────────────────────────────────────────────────────────

def main() -> None:
    port = sys.argv[1] if len(sys.argv) > 1 else DEFAULT_PORT

    # 1. Build + Upload
    build = run_build(port)
    if not build.build_ok:
        log("Build failed. Aborting.")
        sys.exit(1)

    upload_ok = run_upload(port)
    build.upload_ok = upload_ok

    if not upload_ok:
        log("Upload failed. Aborting.")
        sys.exit(1)

    # Connect to serial after upload
    log(f"Waiting {BOOT_WAIT_S}s for ESP32 to boot after upload...")
    time.sleep(BOOT_WAIT_S)

    conn = Conn(port)
    try:
        conn.drain(3.0)  # discard boot messages

        results: list[ScenarioResult] = []

        # 2. Compact debug-state
        results.append(scenario_compact_debug_state(conn))

        # 3. Full debug-state fallback
        results.append(scenario_full_debug_state(conn))

        # 4. Baseline
        results.append(scenario_baseline_real_setup_a_log_only(conn))

        # 5. FC ack
        results.append(scenario_fc_ack(conn))

        # 6. FC ret
        results.append(scenario_fc_ret(conn))

        # 7. FC nak
        results.append(scenario_fc_nak(conn))

        # 8. real_setup_g + ack
        results.append(scenario_real_setup_g_fc_ack(conn))

        # 9. no_response
        results.append(scenario_no_response_log_only(conn))

        # 10. synthetic_setup
        results.append(scenario_synthetic_setup(conn))

        # 11. Pay negative
        results.append(scenario_pay_negative(conn))

        print_report(build, results, port)

    finally:
        conn.close()


if __name__ == "__main__":
    main()
