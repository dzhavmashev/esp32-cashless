#!/usr/bin/env python3
"""1C behavior sweep test.

Observes 1C (Cashless Setup) across multiple mode combinations.
Does NOT change firmware business logic.

Step 1: Detect whether firmware supports mdb_1c_mode runtime command.
Step 2: Run observe-only scenarios A-D (always).
Step 3: If 1C modes are supported, run E-H with explicit 1C modes.

For each scenario records:
  - 19_seen, setup_response_frame
  - FC sequence (all FC events in order)
  - 1C sequence with ±context (5 before / 10 after each 1C event)
  - FE events
  - reset, chain_reset
  - POLL, ENABLE, reader_enabled

Usage:
    python3 scripts/mdb_1c_sweep.py [PORT]
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
OBSERVATION_S = 180.0
CMD_DETECT_S = 2.0      # per-command detection window

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

# Events indicating a command was accepted by firmware
CMD_ACCEPTED_EVENTS = frozenset({
    "command_applied", "mode_changed", "mdb_1c_mode_changed", "mdb_mode_changed",
    "mdb_1c_mode_set",
})
# Events indicating command was rejected / unknown
CMD_REJECTED_EVENTS = frozenset({
    "command_rejected", "command_unknown", "unknown_command",
    "error", "command_error",
})

OUT_DIR = Path.cwd() / "test_logs"


# ── Helpers ───────────────────────────────────────────────────────────────────

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

    def collect(self, timeout: float) -> list[dict]:
        return self.drain(timeout)


def cmd_json(command: str, payload: Optional[dict] = None) -> str:
    obj: dict[str, Any] = {"command": command}
    if payload:
        obj["payload"] = payload
    return json.dumps(obj, separators=(",", ":"))


def first_of(events: list[dict], name: str) -> Optional[dict]:
    for e in events:
        if e.get("event") == name:
            return e
    return None


def events_of(events: list[dict], *names: str) -> list[dict]:
    ns = set(names)
    return [e for e in events if e.get("event") in ns]


def details(ev: Optional[dict]) -> dict:
    if ev is None:
        return {}
    d = ev.get("details", {})
    return d if isinstance(d, dict) else {}


def reboot_and_set_modes(
    conn: Conn,
    mode19: str,
    fc_mode: str,
    mode_1c: Optional[str] = None,
) -> None:
    label = f"mode19={mode19} fc={fc_mode}"
    if mode_1c:
        label += f" 1c={mode_1c}"
    log(f"Rebooting ESP32 then setting {label}...")
    conn.send(cmd_json("reboot"))
    time.sleep(BOOT_WAIT_S)
    conn.drain(2.0)

    conn.send(cmd_json("mdb_19_response_mode", {"mode": mode19}))
    time.sleep(0.15)
    conn.send(cmd_json("mdb_fc_mode", {"mode": fc_mode}))
    time.sleep(0.15)
    conn.send(cmd_json("mdb_single_wire_mode", {"enabled": True}))
    time.sleep(0.15)
    if mode_1c:
        conn.send(cmd_json("mdb_1c_mode", {"mode": mode_1c}))
        time.sleep(0.15)
    conn.drain(MODE_APPLY_S)


# ── 1C context extraction ─────────────────────────────────────────────────────

def extract_1c_contexts(events: list[dict]) -> list[dict]:
    """For each 1C event, extract 5 event names before and 10 after."""
    all_names = [e.get("event", "") for e in events]
    contexts = []
    for i, ev in enumerate(events):
        if ev.get("event") in ONE_C_EVENTS:
            before = all_names[max(0, i - 5):i]
            after = all_names[i + 1:i + 11]
            contexts.append({
                "index": i,
                "event": ev.get("event"),
                "details": details(ev),
                "before_5": before,
                "after_10": after,
            })
    return contexts


# ── 1C mode support detection ─────────────────────────────────────────────────

DETECT_MODES = ["ignore", "ack", "ret", "nak", "ack_enable", "ack_only"]


def detect_1c_mode_support(conn: Conn) -> dict[str, str]:
    """
    Send each mdb_1c_mode command and classify the response.
    Returns dict: mode -> "supported" | "rejected" | "no_response"
    """
    log("=== Detecting mdb_1c_mode command support ===")
    results: dict[str, str] = {}
    for mode in DETECT_MODES:
        conn.send(cmd_json("mdb_1c_mode", {"mode": mode}))
        evs = conn.drain(CMD_DETECT_S)
        accepted = any(e.get("event") in CMD_ACCEPTED_EVENTS for e in evs)
        rejected = any(e.get("event") in CMD_REJECTED_EVENTS for e in evs)
        # Also check if any event detail references 1c_mode or the command
        detail_match = any(
            str(e.get("details", "")).lower().find("1c") >= 0
            or str(e.get("details", "")).lower().find(mode) >= 0
            for e in evs if e.get("event") not in ("", None)
        )
        if accepted or detail_match:
            status = "supported"
        elif rejected:
            status = "rejected"
        else:
            status = "no_response"
        log(f"  mdb_1c_mode {mode!r}: {status}")
        results[mode] = status
    return results


# ── Scenario result ───────────────────────────────────────────────────────────

@dataclass
class ScenarioResult:
    name: str
    mode19: str
    fc_mode: str
    mode_1c: Optional[str] = None
    data: dict[str, Any] = field(default_factory=dict)
    one_c_contexts: list[dict] = field(default_factory=list)
    fc_sequence: list[str] = field(default_factory=list)
    fe_sequence: list[str] = field(default_factory=list)
    reset_sequence: list[str] = field(default_factory=list)


def run_scenario(
    conn: Conn,
    name: str,
    mode19: str,
    fc_mode: str,
    mode_1c: Optional[str] = None,
) -> ScenarioResult:
    log(f"=== {name} ===")
    r = ScenarioResult(name=name, mode19=mode19, fc_mode=fc_mode, mode_1c=mode_1c)

    reboot_and_set_modes(conn, mode19, fc_mode, mode_1c)
    log(f"Collecting {OBSERVATION_S:.0f}s...")
    events = conn.collect(OBSERVATION_S)

    gateway19_events = events_of(events, "gateway19_real_frame_seen")
    response_events = events_of(events, "gateway19_real_setup_response_sent")
    fc_evs = [e for e in events if e.get("event") in FC_EVENTS]
    fe_evs = [e for e in events if e.get("event") in FE_EVENTS]
    one_c_evs = [e for e in events if e.get("event") in ONE_C_EVENTS]
    reset_evs = [e for e in events if e.get("event") in RESET_EVENTS]
    chain_resets = events_of(events, "gateway19_chain_reset_seen")
    poll_evs = [e for e in events if e.get("event") in POLL_EVENTS]
    enable_evs = [e for e in events if e.get("event") in ENABLE_EVENTS]

    resp = response_events[0] if response_events else None
    resp_d = details(resp)
    resp_hex = resp_d.get("frame_hex", "")

    chain_reset = chain_resets[0] if chain_resets else None

    r.data = {
        "19_seen": len(gateway19_events),
        "setup_response_frame": resp_hex,
        "FC_count": len(fc_evs),
        "1C_count": len(one_c_evs),
        "FE_count": len(fe_evs),
        "reset_count": len(reset_evs),
        "chain_reset_count": len(chain_resets),
        "chain_reset_fc_mode": details(chain_reset).get("last_fc_mode") if chain_reset else None,
        "chain_reset_delta_us": details(chain_reset).get("delta_us_from_19_rx") if chain_reset else None,
        "POLL_count": len(poll_evs),
        "ENABLE_count": len(enable_evs),
        "reader_enabled_any": any(
            details(e).get("reader_enabled") is True for e in events
        ),
        "total_events": len(events),
    }

    r.fc_sequence = [e.get("event", "") for e in fc_evs]
    r.fe_sequence = [e.get("event", "") for e in fe_evs[:10]]
    r.reset_sequence = [e.get("event", "") for e in reset_evs]
    r.one_c_contexts = extract_1c_contexts(events)

    return r


# ── Report ────────────────────────────────────────────────────────────────────

def format_scenario(r: ScenarioResult) -> list[str]:
    lines = []
    lines.append(f"### {r.name}")
    lines.append(f"  mode19:           {r.mode19}")
    lines.append(f"  fc_mode:          {r.fc_mode}")
    if r.mode_1c:
        lines.append(f"  mode_1c:          {r.mode_1c}")
    lines.append(f"  19_seen:          {r.data['19_seen']}")
    lines.append(f"  setup_response:   {r.data['setup_response_frame']!r}")
    lines.append(f"  FC_count:         {r.data['FC_count']}")
    lines.append(f"  FC_sequence:      {r.fc_sequence}")
    lines.append(f"  FE_count:         {r.data['FE_count']}")
    lines.append(f"  FE_sequence:      {r.fe_sequence}")
    lines.append(f"  1C_count:         {r.data['1C_count']}")
    lines.append(f"  reset_count:      {r.data['reset_count']}")
    lines.append(f"  reset_sequence:   {r.reset_sequence}")
    lines.append(f"  chain_reset:      {r.data['chain_reset_count']}")
    if r.data.get("chain_reset_fc_mode"):
        lines.append(f"    chain_fc_mode:  {r.data['chain_reset_fc_mode']}")
        lines.append(f"    chain_delta_us: {r.data['chain_reset_delta_us']}")
    lines.append(f"  POLL_count:       {r.data['POLL_count']}")
    lines.append(f"  ENABLE_count:     {r.data['ENABLE_count']}")
    lines.append(f"  reader_enabled:   {r.data['reader_enabled_any']}")
    lines.append(f"  total_events:     {r.data['total_events']}")

    if r.one_c_contexts:
        lines.append(f"  1C contexts ({len(r.one_c_contexts)} events):")
        for ctx in r.one_c_contexts:
            lines.append(f"    [{ctx['index']}] {ctx['event']}")
            lines.append(f"      before: {ctx['before_5']}")
            lines.append(f"      after:  {ctx['after_10']}")
            d = ctx["details"]
            if d:
                for k, v in list(d.items())[:6]:
                    lines.append(f"      {k}: {v}")
    else:
        lines.append("  1C contexts:      none")

    return lines


def print_report(
    support: dict[str, str],
    scenarios: list[ScenarioResult],
) -> None:
    lines = []
    lines.append("=" * 70)
    lines.append("1C BEHAVIOR SWEEP REPORT")
    lines.append(f"Date: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    lines.append(f"Observation per scenario: {OBSERVATION_S:.0f}s")
    lines.append("=" * 70)

    # ── Detection ──
    lines.append("")
    lines.append("## 1C mode command detection")
    any_supported = any(s == "supported" for s in support.values())
    lines.append(f"  mdb_1c_mode supported: {'YES' if any_supported else 'NO'}")
    for mode, status in support.items():
        lines.append(f"  mode={mode!r:12s}  {status}")
    if not any_supported:
        lines.append("")
        lines.append("  >> No 1C runtime modes detected.")
        lines.append("  >> Scenarios E-H skipped.")
        lines.append("  >> Observe-only results below.")

    # ── Scenarios ──
    lines.append("")
    lines.append("## Scenario results")
    for r in scenarios:
        lines.append("")
        lines.extend(format_scenario(r))

    # ── Summary table ──
    lines.append("")
    lines.append("## Summary table")
    hdr = (
        f"  {'Scenario':<40} {'19':>4} {'FC':>4} {'1C':>4} "
        f"{'FE':>4} {'RST':>4} {'POL':>4} {'ENA':>4} {'rdr':>4}"
    )
    lines.append(hdr)
    lines.append("  " + "-" * 74)
    for r in scenarios:
        d = r.data
        lines.append(
            f"  {r.name:<40} {d['19_seen']:>4} {d['FC_count']:>4} {d['1C_count']:>4} "
            f"{d['FE_count']:>4} {d['reset_count']:>4} {d['POLL_count']:>4} "
            f"{d['ENABLE_count']:>4} {'Y' if d['reader_enabled_any'] else 'N':>4}"
        )

    # ── Conclusion ──
    lines.append("")
    lines.append("## Conclusion")

    # Does FC response help?
    fc_modes_seen = {r.fc_mode for r in scenarios}
    fc_help_notes = []
    for r in scenarios:
        fc_sent = [ev for ev in r.fc_sequence if ev in (
            "mdb_fc_ack_sent", "mdb_fc_ret_sent", "mdb_fc_nak_sent")]
        still_resets = r.data["reset_count"] > 0
        if fc_sent and still_resets:
            fc_help_notes.append(
                f"  {r.fc_mode}: FC sent ({fc_sent[0]}) but reset followed — "
                f"FC alone does not prevent reset"
            )
        elif fc_sent and not still_resets:
            fc_help_notes.append(
                f"  {r.fc_mode}: FC sent, no reset observed — FC may help"
            )
        elif r.fc_mode == "log_only" and still_resets:
            fc_help_notes.append(
                f"  {r.fc_mode}: no FC response, reset followed"
            )
    lines.append("  FC response impact:")
    lines.extend(fc_help_notes if fc_help_notes else ["  (no data)"])

    # Is 1C consistently before reset?
    lines.append("")
    lines.append("  1C before reset pattern:")
    for r in scenarios:
        if r.one_c_contexts and r.data["reset_count"] > 0:
            ctx = r.one_c_contexts[0]
            reset_in_after = any(
                ev in RESET_EVENTS for ev in ctx["after_10"]
            )
            lines.append(
                f"  [{r.name}]: 1C={ctx['event']}, reset_in_after_10={reset_in_after}"
            )
            lines.append(f"    after: {ctx['after_10']}")
        elif r.data["1C_count"] == 0:
            lines.append(f"  [{r.name}]: no 1C observed")
        elif r.data["reset_count"] == 0:
            lines.append(f"  [{r.name}]: 1C seen but no reset")

    # no_response / log_only produces 1C?
    lines.append("")
    no_resp = next((r for r in scenarios if r.mode19 == "no_response"), None)
    if no_resp:
        lines.append(
            f"  no_response+log_only: 1C_count={no_resp.data['1C_count']}, "
            f"FC_count={no_resp.data['FC_count']}, reset_count={no_resp.data['reset_count']}"
        )
        if no_resp.data["1C_count"] > 0:
            lines.append(
                "  >> 1C arrives even without 19 response — VMC sends 1C independently"
            )

    # Patch recommendation
    lines.append("")
    if not any_supported:
        lines.append("  Firmware patch needed for 1C runtime modes: YES")
        lines.append("  Proposed minimal patch (do not apply in this task):")
        lines.append("    - Add mdb_1c_mode command handler in command_service.cpp")
        lines.append("    - Modes: ignore | ack | ret | nak | ack_enable | ack_only")
        lines.append("    - Default: current behaviour (compact_ignored or equivalent)")
        lines.append("    - Emit mdb_1c_mode_changed event on success")
        lines.append("    - No payment logic changes")
    else:
        supported = [m for m, s in support.items() if s == "supported"]
        lines.append(f"  1C runtime modes already supported: {supported}")
        lines.append("  No firmware patch needed for mode switching.")

    lines.append("")
    lines.append("=" * 70)

    report = "\n".join(lines)
    print("\n" + report)

    OUT_DIR.mkdir(exist_ok=True)
    stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    out_path = OUT_DIR / f"1c_sweep_{stamp}.txt"
    out_path.write_text(report + "\n", encoding="utf-8")
    log(f"Report saved to {out_path}")


# ── Main ──────────────────────────────────────────────────────────────────────

def main() -> None:
    port = sys.argv[1] if len(sys.argv) > 1 else DEFAULT_PORT

    scenario_count = 4      # A-D always; E-H only if 1C supported
    est_s = scenario_count * (BOOT_WAIT_S + MODE_APPLY_S + 2.0 + OBSERVATION_S)
    log(f"Estimated time for A-D: {est_s / 60:.0f} min (+ E-H if 1C modes supported)")

    conn = Conn(port)
    try:
        conn.drain(2.0)

        # Step 1 — detection (no reboot needed, just send commands and observe)
        support = detect_1c_mode_support(conn)
        supported_modes = [m for m, s in support.items() if s == "supported"]

        scenarios: list[ScenarioResult] = []

        # Step 2 — observe-only scenarios A-D
        scenarios.append(run_scenario(
            conn, "A. observe_only: real_setup_a + log_only",
            mode19="real_setup_a", fc_mode="log_only",
        ))
        scenarios.append(run_scenario(
            conn, "B. real_setup_a + fc_ack + 1C observe",
            mode19="real_setup_a", fc_mode="ack",
        ))
        scenarios.append(run_scenario(
            conn, "C. real_setup_g + fc_ack + 1C observe",
            mode19="real_setup_g", fc_mode="ack",
        ))
        scenarios.append(run_scenario(
            conn, "D. no_response + log_only + 1C observe",
            mode19="no_response", fc_mode="log_only",
        ))

        # Step 3 — 1C mode scenarios E-H (only if supported)
        if supported_modes:
            log(f"1C modes supported: {supported_modes} — running E-H")
            for label, m in [("E", "ack"), ("F", "ret"), ("G", "nak"), ("H", "ack_enable")]:
                if m in supported_modes:
                    scenarios.append(run_scenario(
                        conn,
                        f"{label}. real_setup_a + fc_ack + 1c_{m}",
                        mode19="real_setup_a", fc_mode="ack", mode_1c=m,
                    ))
                else:
                    log(f"  Skipping {label} (1c mode={m!r} not supported)")
        else:
            log("No 1C runtime modes detected — skipping E-H (observe-only report only)")

        print_report(support, scenarios)

    finally:
        conn.close()


if __name__ == "__main__":
    main()
