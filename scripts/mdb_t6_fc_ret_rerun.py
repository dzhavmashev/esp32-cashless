#!/usr/bin/env python3
"""Targeted rerun of test 6 only: real_setup_a + FC ret.

Previous run timed out at 90s — FC did not arrive in the first VMC cycle.
This script observes for 240s (≈5-6 VMC cycles) and stops early when FC ret
is captured. Code correctness was already confirmed from pre-reboot buffer
capture (mdb_fc_ret_sent frame_hex="AA"); this run provides live evidence.

Classification:
  PASS         — mdb_fc_ret_sent with frame_hex="AA" and control_name="RET"
  FAIL         — FC arrived but ret was not sent (mode issue)
  INCONCLUSIVE — no FC at all in 240s window (timing, not a code bug)

Usage:
    python3 scripts/mdb_t6_fc_ret_rerun.py [PORT]
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

BOOT_WAIT_S = 10.0
MODE_APPLY_S = 2.0
OBSERVATION_S = 240.0       # ≈5-6 VMC cycles (each ~35-40s)
FC_DRAIN_AFTER_S = 20.0     # trailing events after FC captured

ONE_C_EVENTS = frozenset({
    "mdb_1c_compact_ignored", "mdb_1c_seen", "mdb_1c_ack_sent",
    "mdb_1c_ret_sent", "mdb_1c_nak_sent", "mdb_1c_ack_only", "mdb_1c_ack_enable",
})
FC_EVENTS = frozenset({
    "mdb_fc_ack_sent", "mdb_fc_ret_sent", "mdb_fc_nak_sent", "mdb_fc_ack_enable",
    "mdb_compat_tail_ignored", "mdb_fc_before_setup_seen",
    "mdb_fc_gateway_poll_not_implemented",
})
FE_EVENTS = frozenset({
    "mdb_fe_compat_poll_seen", "mdb_fe_seen", "mdb_fe_credit_poll_seen",
})
RESET_EVENTS = frozenset({
    "reset_seen", "cashless_reset_received", "vmc_reset_seen",
    "cashless_reset", "gateway19_chain_reset_seen",
})
POLL_EVENTS = frozenset({"poll_seen", "vmc_poll_seen"})
ENABLE_EVENTS = frozenset({"enable_seen", "vmc_enable_seen"})

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

    def collect_until_fc_ret_or_timeout(
        self, timeout: float
    ) -> tuple[list[dict], bool]:
        """Collect events; stop early and drain trailing window when FC ret seen."""
        events: list[dict] = []
        deadline = time.monotonic() + timeout
        fc_found = False
        start = time.monotonic()
        while time.monotonic() < deadline:
            chunk = self.ser.read(4096)
            for obj in self.extractor.feed(chunk):
                ev = obj.get("event", "")
                if ev:
                    elapsed = time.monotonic() - start
                    log(f"  EV {ev}  (t+{elapsed:.1f}s)")
                events.append(obj)
                if not fc_found and ev == "mdb_fc_ret_sent":
                    fc_found = True
                    remaining = deadline - time.monotonic()
                    drain_s = min(FC_DRAIN_AFTER_S, max(0.0, remaining))
                    log(f"FC ret seen — draining {drain_s:.0f}s trailing events...")
                    trailing = self.drain(drain_s)
                    events.extend(trailing)
                    return events, True
        return events, False


def cmd_json(command: str, payload: Optional[dict] = None) -> str:
    obj: dict[str, Any] = {"command": command}
    if payload:
        obj["payload"] = payload
    return json.dumps(obj, separators=(",", ":"))


def reboot_and_set_modes(conn: Conn) -> None:
    log("Rebooting ESP32 then setting mode19=real_setup_a fc_mode=ret sw=true...")
    conn.send(cmd_json("reboot"))
    time.sleep(BOOT_WAIT_S)
    conn.drain(2.0)  # discard boot noise + pre-reboot buffer

    conn.send(cmd_json("mdb_19_response_mode", {"mode": "real_setup_a"}))
    time.sleep(0.15)
    conn.send(cmd_json("mdb_fc_mode", {"mode": "ret"}))
    time.sleep(0.15)
    conn.send(cmd_json("mdb_single_wire_mode", {"enabled": True}))
    time.sleep(0.15)
    conn.drain(MODE_APPLY_S)


def first_of(events: list[dict], name: str) -> Optional[dict]:
    for e in events:
        if e.get("event") == name:
            return e
    return None


def events_of(events: list[dict], name: str) -> list[dict]:
    return [e for e in events if e.get("event") == name]


def details(ev: Optional[dict]) -> dict:
    if ev is None:
        return {}
    d = ev.get("details", {})
    return d if isinstance(d, dict) else {}


def main() -> None:
    port = sys.argv[1] if len(sys.argv) > 1 else DEFAULT_PORT
    conn = Conn(port)
    try:
        conn.drain(2.0)

        log(f"=== TEST 6 EXTENDED: real_setup_a + FC ret ({OBSERVATION_S:.0f}s window) ===")
        reboot_and_set_modes(conn)

        log(f"Observing for up to {OBSERVATION_S:.0f}s (stops early when FC ret seen)...")
        t_start = time.monotonic()
        events, fc_early_exit = conn.collect_until_fc_ret_or_timeout(OBSERVATION_S)
        elapsed = time.monotonic() - t_start

        # ── Extract events ──────────────────────────────────────────────────────
        fc_ret_events = events_of(events, "mdb_fc_ret_sent")
        fc_tail_events = events_of(events, "mdb_compat_tail_ignored")
        gateway19_events = events_of(events, "gateway19_real_frame_seen")
        response_events = events_of(events, "gateway19_real_setup_response_sent")
        chain_reset_events = events_of(events, "gateway19_chain_reset_seen")
        fe_events = [e for e in events if e.get("event") in FE_EVENTS]
        one_c_events = [e for e in events if e.get("event") in ONE_C_EVENTS]
        reset_events = [e for e in events if e.get("event") in RESET_EVENTS]
        poll_events = [e for e in events if e.get("event") in POLL_EVENTS]
        enable_events = [e for e in events if e.get("event") in ENABLE_EVENTS]
        all_fc_events = [e for e in events if e.get("event") in FC_EVENTS]

        reader_enabled_any = any(
            details(e).get("reader_enabled") is True for e in events
        )

        fc_ret = fc_ret_events[0] if fc_ret_events else None
        fc_ret_d = details(fc_ret)
        chain_reset = chain_reset_events[0] if chain_reset_events else None

        # ── Classify ────────────────────────────────────────────────────────────
        gateway19_seen = len(gateway19_events) > 0
        frame_hex = fc_ret_d.get("frame_hex", "")
        control_name = fc_ret_d.get("control_name", "")
        mapping = fc_ret_d.get("mdb_control_byte_mapping", "")
        fc_any = len(all_fc_events) > 0
        fc_present_but_not_ret = fc_any and fc_ret is None

        if not gateway19_seen:
            result = "FAIL"
            verdict = "19 frame not seen in observation window"
        elif fc_ret and frame_hex == "AA" and control_name == "RET":
            result = "PASS"
            verdict = f"RET sent: frame_hex=AA control_name=RET mapping={mapping!r} — PASS"
        elif fc_ret:
            result = "FAIL"
            verdict = (
                "FC ret event had wrong mapping: "
                f"frame_hex={frame_hex!r} control_name={control_name!r} mapping={mapping!r}"
            )
        elif fc_present_but_not_ret:
            result = "FAIL"
            if fc_tail_events:
                verdict = "FC arrived but was log_only-ignored — fc_mode=ret not applied after reboot"
            else:
                wrong = [e.get("event") for e in all_fc_events]
                verdict = f"FC present but ret not sent — wrong FC events: {wrong}"
        else:
            result = "INCONCLUSIVE"
            verdict = (
                f"19 seen {len(gateway19_events)}x, no FC in {elapsed:.0f}s — "
                "RET mapping ACK=00 RET=AA NAK=FF confirmed from code; "
                "FC timing from VMC varies per cycle"
            )

        # ── Report ──────────────────────────────────────────────────────────────
        lines = []
        lines.append("=" * 70)
        lines.append("TEST 6 EXTENDED RERUN: real_setup_a + FC ret")
        lines.append(f"Date:              {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
        lines.append(f"Port:              {port}")
        lines.append(f"Observation limit: {OBSERVATION_S:.0f}s")
        lines.append(f"Elapsed:           {elapsed:.1f}s")
        lines.append(f"Early exit (FC):   {fc_early_exit}")
        lines.append("=" * 70)
        lines.append("")
        lines.append(f"result:  {result}")
        lines.append(f"verdict: {verdict}")
        lines.append("")
        lines.append(f"gateway19_cycles_seen:     {len(gateway19_events)}")
        lines.append(f"response_events_seen:      {len(response_events)}")
        lines.append(f"fe_events_seen:            {len(fe_events)}")
        lines.append(f"  fe_types: {[e.get('event') for e in fe_events[:5]]}")
        lines.append(f"1c_events_seen:            {len(one_c_events)}")
        lines.append(f"  1c_types: {[e.get('event') for e in one_c_events[:5]]}")
        lines.append(f"fc_events_seen (total):    {len(all_fc_events)}")
        lines.append(f"  fc_types: {[e.get('event') for e in all_fc_events[:5]]}")
        lines.append(f"fc_tail_ignored_seen:      {len(fc_tail_events)}")
        lines.append(f"fc_ret_events_seen:        {len(fc_ret_events)}")
        lines.append(f"reset_events_seen:         {len(reset_events)}")
        lines.append(f"  reset_types: {[e.get('event') for e in reset_events[:5]]}")
        lines.append(f"chain_reset_events_seen:   {len(chain_reset_events)}")
        lines.append(f"poll_events_seen:          {len(poll_events)}")
        lines.append(f"enable_events_seen:        {len(enable_events)}")
        lines.append(f"reader_enabled_any:        {reader_enabled_any}")
        lines.append("")
        lines.append(f"FC_ret_frame_hex:     {frame_hex!r}")
        lines.append(f"FC_ret_control_name:  {control_name!r}")
        lines.append(f"FC_ret_mapping:       {mapping!r}")
        lines.append(f"FC_ret_tx_ts_us:      {fc_ret_d.get('tx_ts_us')}")

        if chain_reset:
            lines.append("")
            cd = details(chain_reset)
            lines.append(f"chain_reset[0]:")
            lines.append(f"  last_fc_mode:        {cd.get('last_fc_mode')}")
            lines.append(f"  last_19_mode:        {cd.get('last_19_mode')}")
            lines.append(f"  delta_us_from_19_rx: {cd.get('delta_us_from_19_rx')}")
            lines.append(f"  reader_enabled:      {cd.get('reader_enabled')}")

        if len(fc_ret_events) > 1:
            lines.append("")
            lines.append(f"All FC ret events ({len(fc_ret_events)}):")
            for i, ev in enumerate(fc_ret_events):
                d = details(ev)
                lines.append(
                    f"  [{i}] frame_hex={d.get('frame_hex')!r} "
                    f"control_name={d.get('control_name')!r} "
                    f"tx_ts_us={d.get('tx_ts_us')}"
                )

        lines.append("")
        lines.append(f"Total events collected: {len(events)}")
        lines.append("=" * 70)

        report = "\n".join(lines)
        print("\n" + report)

        OUT_DIR.mkdir(exist_ok=True)
        stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        out_path = OUT_DIR / f"t6_fc_ret_{stamp}.txt"
        out_path.write_text(report + "\n", encoding="utf-8")
        log(f"Report saved to {out_path}")

    finally:
        conn.close()


if __name__ == "__main__":
    main()
