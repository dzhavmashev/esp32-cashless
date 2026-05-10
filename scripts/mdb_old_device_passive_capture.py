#!/usr/bin/env python3
"""Passive capture of VMC <-> OLD DEVICE traffic on the one-wire MDB bus.

The ESP acts as a silent observer. All response modes are set to
no-response / ignore / log_only so the ESP never drives the line.

The old device (physically connected) handles all VMC commands.
The ESP captures every byte seen, classifies frames, and produces:
  - JSONL event timeline
  - Human-readable summary with sequence analysis

Key events captured:
  rx_frame          — every assembled frame + decoded_direction
  sniff_frame_raw   — byte-level raw (passive sniff mode)
  gateway_compat_sequence_event / summary — from diagnostic patch
  mdb_e0_seen, reset_seen, gateway19_real_frame_seen, etc.

Usage:
    python3 scripts/mdb_old_device_passive_capture.py [PORT] [--duration N]
    python3 scripts/mdb_old_device_passive_capture.py --analyze FILE.jsonl
    Default port: /dev/ttyUSB1, duration: 300s
"""

from __future__ import annotations

import json
import sys
import time
import argparse
import statistics
from collections import defaultdict
from dataclasses import dataclass, field
from datetime import datetime
from pathlib import Path
from typing import Any, Optional

import serial

DEFAULT_PORT = "/dev/ttyUSB1"
BAUD_RATE = 115200
SERIAL_TIMEOUT_S = 0.1
BOOT_WAIT_S = 12.0
MODE_SETTLE_S = 1.5
RESPONSE_WINDOW_MS = 5.0    # frames within this gap → candidate response
POLL12_ACCEPTED_THRESHOLD = 100  # min poll12 count to call flow "accepted"

OUT_DIR = Path.cwd() / "test_logs"
W = 74   # report width


@dataclass
class InputFormatInfo:
    """Detected input format metadata."""
    format: str = "unknown"          # "arduino", "esp", "unknown"
    raw_byte_count: int = 0
    packet_count: int = 0
    boot_info: dict = field(default_factory=dict)
    frame_source: str = ""           # "arduino_packet"/"raw_byte_grouped"/"esp_rx_frame"
    packet_gap_us: int = 5000        # from Arduino boot event or default

# ESP current behavior (comparison reference).
ESP_REFERENCE = {
    "gateway_frame":    "19 03 01 00 1D (RealSetupA mode)",
    "setup_response":   "03 16 43 64 02 1E 08 E8",
    "poll_phase":       "NEVER REACHED — stuck in gateway/compat reset loop",
    "fc_response":      "log_only (no TX by default); Ack=00 Ret=AA Nak=FF",
    "1c_response":      "ignore by default; Ret=AA / Nak=FF / Ack=00 configurable",
    "fe_idle_response": "just_reset_0b_once (0B) by default; no_response configurable",
    "fe_credit":        "legacy_type0_repeat5 / ignore",
    "reset_behavior":   "frequent 10 10 reset every gateway cycle (~35–40s)",
    "typical_sequence": "19→FE→1C→10 10  /  19→E0→FC→1C→FC→10 10",
}

# Events to capture and write to JSONL.
CAPTURE_EVENTS = {
    "rx_frame", "sniff_frame_raw", "sniff_frame_normalized", "sniff_byte",
    "gateway_compat_sequence_event", "gateway_compat_sequence_summary",
    "mdb_e0_seen", "mdb_compat_tail_ignored", "mdb_fc_mode_bypassed",
    "mdb_fc_before_setup_seen", "gateway19_real_frame_seen",
    "gateway19_chain_reset_seen", "reset_seen",
    "mdb_fe_compat_poll_seen", "mdb_fe_compat_ignored",
    "mdb_1c_compact_ignored", "mdb_1c_ret", "mdb_1c_nak",
    "mdb_1c_ack_only", "mdb_1c_ack_enable",
    "passive_sniff_changed", "mdb_fc_ack_sent", "mdb_fc_ret_sent",
    "mdb_fc_nak_sent", "mdb_fc_ack_enable",
    "state_changed", "command_applied", "command_received",
    "sniff_command_candidate",
}


# ─────────────────────────────────────────────────────────────────────────────
# Helpers
# ─────────────────────────────────────────────────────────────────────────────

def ts() -> str:
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]


def log(msg: str) -> None:
    print(f"[{ts()}] {msg}")


def get_details(obj: dict) -> dict:
    d = obj.get("details", {})
    return d if isinstance(d, dict) else {}


def _d(obj: dict, *keys: str, default: Any = "") -> Any:
    """Read a key from details{} first, then from obj top-level."""
    d = get_details(obj)
    for k in keys:
        v = d.get(k)
        if v is not None:
            return v
    for k in keys:
        v = obj.get(k)
        if v is not None:
            return v
    return default


def med(vals: list[float]) -> float:
    return statistics.median(vals) if vals else 0.0


# ─────────────────────────────────────────────────────────────────────────────
# Stream JSON extractor
# ─────────────────────────────────────────────────────────────────────────────

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
            candidate = bytes(self.buf[: end + 1])
            del self.buf[: end + 1]
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


# ─────────────────────────────────────────────────────────────────────────────
# Serial connection / capture
# ─────────────────────────────────────────────────────────────────────────────

class Conn:
    def __init__(self, port: str) -> None:
        self.ser = serial.Serial(port, BAUD_RATE, timeout=SERIAL_TIMEOUT_S)
        self.extractor = StreamJsonExtractor()
        log(f"Connected to {port} at {BAUD_RATE}")

    def close(self) -> None:
        self.ser.close()

    def send(self, cmd_str: str) -> None:
        log(f"  TX> {cmd_str[:120]}")
        self.ser.write((cmd_str + "\n").encode())
        self.ser.flush()

    def drain(self, seconds: float) -> list[dict]:
        events: list[dict] = []
        deadline = time.monotonic() + seconds
        while time.monotonic() < deadline:
            chunk = self.ser.read(4096)
            for obj in self.extractor.feed(chunk):
                events.append(obj)
        return events

    def collect(self, duration: float, jsonl_path: Path) -> list[dict]:
        events: list[dict] = []
        deadline = time.monotonic() + duration
        t0 = time.monotonic()
        last_status = t0
        log(f"Collecting for {duration:.0f}s  →  {jsonl_path.name}")
        with jsonl_path.open("w", encoding="utf-8") as f:
            while time.monotonic() < deadline:
                chunk = self.ser.read(4096)
                for obj in self.extractor.feed(chunk):
                    ev = obj.get("event", "")
                    obj["_elapsed_s"] = round(time.monotonic() - t0, 3)
                    if ev in CAPTURE_EVENTS or not ev:
                        f.write(json.dumps(obj, ensure_ascii=False) + "\n")
                        events.append(obj)
                    if ev in {"gateway19_real_frame_seen",
                              "gateway_compat_sequence_summary",
                              "mdb_e0_seen", "reset_seen"}:
                        log(f"  EV {ev}")
                now = time.monotonic()
                if now - last_status >= 30:
                    log(f"  {now-t0:.0f}s elapsed, {len(events)} events")
                    last_status = now
        log(f"Capture done: {len(events)} events in {time.monotonic()-t0:.1f}s")
        return events


def mkcmd(command: str, payload: Optional[dict] = None) -> str:
    obj: dict[str, Any] = {"command": command}
    if payload:
        obj["payload"] = payload
    return json.dumps(obj, separators=(",", ":"))


def configure_passive_mode(conn: Conn) -> None:
    log("Rebooting ESP...")
    conn.send(mkcmd("reboot"))
    time.sleep(BOOT_WAIT_S)
    conn.drain(2.0)

    log("Setting silent observer modes (ESP will NOT respond to bus)...")
    for c, p in [
        ("mdb_19_response_mode",  {"mode": "no_response"}),
        ("mdb_fc_mode",           {"mode": "log_only"}),
        ("mdb_1c_mode",           {"mode": "ignore"}),
        ("mdb_fe_idle_mode",      {"mode": "no_response"}),
        ("mdb_fe_credit_mode",    {"mode": "ignore"}),
        ("mdb_e0_mode",           {"mode": "ignore"}),
        ("mdb_single_wire_mode",  {"enabled": False}),
    ]:
        conn.send(mkcmd(c, p))
        time.sleep(0.1)
    conn.send(mkcmd("mdb_passive_sniff_on"))
    time.sleep(0.1)
    conn.send(mkcmd("mdb_monitor_start"))
    time.sleep(0.1)
    conn.drain(MODE_SETTLE_S)
    log("Passive mode configured.")


# ─────────────────────────────────────────────────────────────────────────────
# Frame classification
# ─────────────────────────────────────────────────────────────────────────────

@dataclass
class FrameInfo:
    """Parsed representation of one MDB frame observed on the bus."""
    raw_hex: str            # as captured
    norm_hex: str           # normalized
    parts: list[str]        # norm_hex.split(), uppercased
    kind: str               # semantic kind label
    poll12_resp: str        # response byte when kind == "poll12_with_resp"
    direction: str          # VMC_TO_DEVICE / DEVICE_TO_VMC / UNKNOWN
    gap_before_ms: float    # gap to previous frame
    decoded_frame_kind: str # Ack / Nak / Ret / DataBlock / Invalid
    has_high_bit: bool
    checksum_valid: bool
    candidate_address: int  # -1 if not available
    candidate_command: int
    elapsed_s: float        # capture elapsed time
    event_src: str          # rx_frame / sniff_frame_raw
    raw_obj: dict


def _classify(parts: list[str]) -> tuple[str, str]:
    """(kind, poll12_response_byte_hex)."""
    if not parts:
        return "empty", ""
    f = parts[0].upper()
    if f == "12":
        if len(parts) >= 2 and parts[1].upper() == "12":
            resp = parts[2].upper() if len(parts) >= 3 else ""
            return ("poll12_with_resp" if resp else "poll12"), resp
        if len(parts) == 2:
            return "mdb_12_variant", parts[1].upper()
        return "mdb_12_single", ""
    if f == "FC":  return "FC", ""
    if f == "FE":  return "FE", ""
    if f == "1C":  return "1C", ""
    if f == "E0":  return "E0", ""
    if f == "00" and len(parts) == 1:  return "ACK", ""
    if f == "AA" and len(parts) == 1:  return "RET", ""
    if f == "FF" and len(parts) == 1:  return "NAK", ""
    if f == "0B":  return "JUST_RESET", ""
    if f == "10" and len(parts) >= 2 and parts[1].upper() == "10":
        return "reset_10_10", ""
    if f == "19":  return "gateway19", ""
    # Any other known MDB address prefixes
    if f in {"11", "13", "14", "15", "16", "17"}:
        return "mdb_cashless_cmd", ""
    if f in {"08", "09", "0A", "0B", "0C", "0D", "0E", "0F"}:
        return "mdb_coin_family", ""
    if f in {"30", "31", "32", "33", "34", "35", "36", "37"}:
        return "mdb_bill_family", ""
    if f in {"60", "61"}:
        return "mdb_60_family", ""
    return "unknown", ""


def _direction(obj: dict) -> str:
    d = get_details(obj)
    raw = d.get("decoded_direction", obj.get("decoded_direction", ""))
    if raw == "MasterToPeripheral":  return "VMC_TO_DEVICE"
    if raw == "PeripheralToMaster":  return "DEVICE_TO_VMC"
    return "UNKNOWN"


def _build_from_esp(events: list[dict]) -> list[FrameInfo]:
    frames: list[FrameInfo] = []
    for obj in events:
        ev = obj.get("event", "")
        if ev not in ("rx_frame", "sniff_frame_raw"):
            continue
        elapsed = obj.get("_elapsed_s", obj.get("_capture_elapsed_s", 0.0))

        if ev == "rx_frame":
            raw = _d(obj, "hex")
            norm = _d(obj, "normalized_hex")
            gap = float(_d(obj, "frame_gap_before_ms", default=0))
            dfk = _d(obj, "decoded_frame_kind")
            hhb = bool(_d(obj, "has_high_bit", default=False))
            csv = bool(_d(obj, "checksum_valid", default=False))
            ca = int(_d(obj, "candidate_address", default=-1))
            cc = int(_d(obj, "candidate_command", default=-1))
        else:  # sniff_frame_raw
            raw = _d(obj, "raw_hex")
            norm = _d(obj, "normalized_hex") or raw
            gap = float(_d(obj, "frame_gap_before_ms", default=0))
            dfk = ""
            hhb = False
            csv = False
            ca = cc = -1

        norm_up = norm.upper().strip() if norm else raw.upper().strip()
        parts = norm_up.split() if norm_up else []
        kind, poll_resp = _classify(parts)
        dir_hint = _direction(obj) if ev == "rx_frame" else "UNKNOWN"

        frames.append(FrameInfo(
            raw_hex=raw, norm_hex=norm_up, parts=parts,
            kind=kind, poll12_resp=poll_resp,
            direction=dir_hint, gap_before_ms=gap,
            decoded_frame_kind=dfk, has_high_bit=hhb,
            checksum_valid=csv, candidate_address=ca,
            candidate_command=cc, elapsed_s=elapsed,
            event_src=ev, raw_obj=obj,
        ))
    return frames


def _build_from_packets(packets: list[dict], fmt: InputFormatInfo) -> list[FrameInfo]:
    """Build FrameInfo list from Arduino packet events."""
    if not packets:
        return []
    frames: list[FrameInfo] = []
    t0_us = packets[0].get("start_us", 0)
    prev_end_us = 0

    for pkt in packets:
        start_us = pkt.get("start_us", 0)
        end_us = pkt.get("end_us", start_us)
        hex_str = pkt.get("hex", "").upper().strip()
        parts = hex_str.split() if hex_str else []
        if not parts:
            prev_end_us = end_us
            continue

        kind, poll_resp = _classify(parts)
        gap_before_ms = (start_us - prev_end_us) / 1000.0 if prev_end_us > 0 else 0.0
        elapsed_s = (start_us - t0_us) / 1_000_000.0

        bit9_str = pkt.get("bit9", "")
        bit9_parts = bit9_str.split() if isinstance(bit9_str, str) else []
        has_high_bit = bit9_parts[0] == "1" if bit9_parts else False

        frames.append(FrameInfo(
            raw_hex=hex_str,
            norm_hex=hex_str,
            parts=parts,
            kind=kind,
            poll12_resp=poll_resp,
            direction="UNKNOWN",
            gap_before_ms=gap_before_ms,
            decoded_frame_kind="",
            has_high_bit=has_high_bit,
            checksum_valid=(pkt.get("checksum") == "ok"),
            candidate_address=-1,
            candidate_command=-1,
            elapsed_s=elapsed_s,
            event_src="arduino_packet",
            raw_obj=pkt,
        ))
        prev_end_us = end_us

    return frames


def _build_from_raw_bytes(raw_bytes: list[dict], fmt: InputFormatInfo) -> list[FrameInfo]:
    """Group raw_byte events into frames by gap and build FrameInfo list."""
    if not raw_bytes:
        return []

    gap_threshold_us = fmt.packet_gap_us
    t0_us = raw_bytes[0].get("ts_us", 0)

    groups: list[list[dict]] = []
    current: list[dict] = []
    for rb in raw_bytes:
        if rb.get("gap_us", 0) > gap_threshold_us and current:
            groups.append(current)
            current = []
        current.append(rb)
    if current:
        groups.append(current)

    frames: list[FrameInfo] = []
    prev_end_us = 0
    for grp in groups:
        hex_str = " ".join(b.get("hex", "??").upper() for b in grp)
        parts = hex_str.split()
        kind, poll_resp = _classify(parts)

        start_us = grp[0].get("ts_us", 0)
        end_us = grp[-1].get("ts_us", start_us)
        gap_before_ms = (start_us - prev_end_us) / 1000.0 if prev_end_us > 0 else 0.0
        elapsed_s = (start_us - t0_us) / 1_000_000.0

        chk_valid = False
        if len(parts) >= 2:
            try:
                data_bytes = [int(p, 16) for p in parts]
                chk_valid = (sum(data_bytes[:-1]) & 0xFF) == data_bytes[-1]
            except ValueError:
                pass

        bit9_0 = str(grp[0].get("bit9", 0))
        frames.append(FrameInfo(
            raw_hex=hex_str, norm_hex=hex_str, parts=parts,
            kind=kind, poll12_resp=poll_resp,
            direction="UNKNOWN", gap_before_ms=gap_before_ms,
            decoded_frame_kind="", has_high_bit=(bit9_0 == "1"),
            checksum_valid=chk_valid,
            candidate_address=-1, candidate_command=-1,
            elapsed_s=elapsed_s,
            event_src="raw_byte_grouped",
            raw_obj={"type": "raw_byte_group", "bytes": grp},
        ))
        prev_end_us = end_us

    return frames


def build_timeline(events: list[dict]) -> tuple[list[FrameInfo], InputFormatInfo]:
    """Detect input format, build frame list, return (frames, fmt_info)."""
    type_set = {e.get("type", "") for e in events}
    fmt = InputFormatInfo()

    if "packet" in type_set or "raw_byte" in type_set:
        fmt.format = "arduino"
        for e in events:
            if e.get("type") == "boot":
                fmt.boot_info = e
                fmt.packet_gap_us = int(e.get("packet_gap_us", 5000))
                break
        fmt.raw_byte_count = sum(1 for e in events if e.get("type") == "raw_byte")
        fmt.packet_count = sum(1 for e in events if e.get("type") == "packet")

        packets = [e for e in events if e.get("type") == "packet"]
        raw_bytes = [e for e in events if e.get("type") == "raw_byte"]
        if packets:
            fmt.frame_source = "arduino_packet"
            return _build_from_packets(packets, fmt), fmt
        elif raw_bytes:
            fmt.frame_source = "raw_byte_grouped"
            return _build_from_raw_bytes(raw_bytes, fmt), fmt
        return [], fmt
    else:
        fmt.format = "esp"
        fmt.frame_source = "esp_rx_frame"
        return _build_from_esp(events), fmt


# ─────────────────────────────────────────────────────────────────────────────
# Analysis functions
# ─────────────────────────────────────────────────────────────────────────────

@dataclass
class Poll12Stats:
    total: int = 0
    with_inline_resp: int = 0      # response byte fused into same frame
    with_next_frame_resp: int = 0  # response in next frame within window
    no_response: int = 0
    resp_counts: dict = field(default_factory=lambda: defaultdict(int))
    gap_ms_list: list = field(default_factory=list)  # gaps of response frames
    first_poll_elapsed_s: float = 0.0
    first_20: list = field(default_factory=list)      # first 20 (resp, gap)
    after_reset_count: int = 0


def analyze_poll12(frames: list[FrameInfo]) -> Poll12Stats:
    st = Poll12Stats()
    first_poll_idx: Optional[int] = None

    for i, fr in enumerate(frames):
        is_poll = fr.kind in ("poll12", "poll12_with_resp")
        if not is_poll:
            continue
        st.total += 1
        if first_poll_idx is None:
            first_poll_idx = i
            st.first_poll_elapsed_s = fr.elapsed_s

        if fr.kind == "poll12_with_resp":
            # Response byte is already in the frame (ESP merged them).
            resp = fr.poll12_resp
            st.with_inline_resp += 1
            st.resp_counts[resp] += 1
            st.gap_ms_list.append(fr.gap_before_ms)
            if len(st.first_20) < 20:
                st.first_20.append((resp, 0.0, "inline"))
        else:
            # Look for next frame with small gap.
            found = False
            if i + 1 < len(frames):
                nxt = frames[i + 1]
                if nxt.gap_before_ms <= RESPONSE_WINDOW_MS:
                    resp = " ".join(nxt.parts[:1]) if nxt.parts else "?"
                    st.with_next_frame_resp += 1
                    st.resp_counts[resp] += 1
                    st.gap_ms_list.append(nxt.gap_before_ms)
                    if len(st.first_20) < 20:
                        st.first_20.append((resp, nxt.gap_before_ms, "next_frame"))
                    found = True
            if not found:
                st.no_response += 1
                if len(st.first_20) < 20:
                    st.first_20.append(("(none)", 0.0, "no_resp"))

    return st


def analyze_poll12_period(frames: list[FrameInfo]) -> list[float]:
    """Return list of inter-poll gaps in ms."""
    gaps: list[float] = []
    prev_idx: Optional[int] = None
    for i, fr in enumerate(frames):
        if fr.kind in ("poll12", "poll12_with_resp"):
            if prev_idx is not None:
                delta_frames = frames[i].elapsed_s - frames[prev_idx].elapsed_s
                gaps.append(delta_frames * 1000.0)
            prev_idx = i
    return gaps


@dataclass
class InitSequence:
    frames_before_first_poll: list[FrameInfo] = field(default_factory=list)
    first_poll_idx: int = -1
    first_poll_elapsed_s: float = 0.0


def analyze_init_sequence(frames: list[FrameInfo]) -> InitSequence:
    result = InitSequence()
    for i, fr in enumerate(frames):
        if fr.kind in ("poll12", "poll12_with_resp"):
            result.first_poll_idx = i
            result.first_poll_elapsed_s = fr.elapsed_s
            result.frames_before_first_poll = frames[:i]
            return result
    result.frames_before_first_poll = frames  # no poll found
    return result


@dataclass
class Gateway19Info:
    elapsed_s: float
    raw_hex: str
    norm_hex: str
    parts: list[str]
    gap_before_ms: float
    checksum_valid: bool
    # 10 frames before and after
    ctx_before: list[FrameInfo] = field(default_factory=list)
    ctx_after: list[FrameInfo] = field(default_factory=list)
    # Decode hints
    byte_count: int = 0
    possible_checksum_expected: int = 0
    possible_checksum_actual: int = 0
    checksum_mismatch: bool = False


def analyze_gateway19_frames(frames: list[FrameInfo]) -> list[Gateway19Info]:
    results: list[Gateway19Info] = []
    for i, fr in enumerate(frames):
        if fr.kind != "gateway19":
            continue
        ctx_before = frames[max(0, i - 10):i]
        ctx_after = frames[i + 1: i + 11]

        # Checksum verification: sum of all bytes except last == last byte mod 256
        parts = fr.parts
        byte_count = len(parts)
        chk_expected = 0
        chk_actual = 0
        chk_mismatch = False
        if byte_count >= 2:
            try:
                data_bytes = [int(p, 16) for p in parts]
                chk_actual = data_bytes[-1]
                chk_expected = sum(data_bytes[:-1]) & 0xFF
                chk_mismatch = chk_expected != chk_actual
            except ValueError:
                pass

        info = Gateway19Info(
            elapsed_s=fr.elapsed_s,
            raw_hex=fr.raw_hex,
            norm_hex=fr.norm_hex,
            parts=parts,
            gap_before_ms=fr.gap_before_ms,
            checksum_valid=fr.checksum_valid,
            ctx_before=ctx_before,
            ctx_after=ctx_after,
            byte_count=byte_count,
            possible_checksum_expected=chk_expected,
            possible_checksum_actual=chk_actual,
            checksum_mismatch=chk_mismatch,
        )
        results.append(info)
    return results


def count_event_kinds(events: list[dict]) -> dict[str, int]:
    counts: dict[str, int] = defaultdict(int)
    for obj in events:
        ev = obj.get("event", obj.get("type", ""))
        if ev:
            counts[ev] += 1
    return counts


def count_frame_kinds(frames: list[FrameInfo]) -> dict[str, int]:
    counts: dict[str, int] = defaultdict(int)
    for fr in frames:
        counts[fr.kind] += 1
    return counts


def find_reset_frames(frames: list[FrameInfo]) -> list[FrameInfo]:
    return [fr for fr in frames if fr.kind == "reset_10_10"]


def extract_sequences(events: list[dict]) -> list[dict]:
    out = []
    for obj in events:
        if obj.get("event") == "gateway_compat_sequence_summary":
            d = get_details(obj)
            out.append(d if d else obj)
    return out


# ─────────────────────────────────────────────────────────────────────────────
# Gateway19 trigger analysis — response windows and sequence to poll12
# ─────────────────────────────────────────────────────────────────────────────

def _frame_start_us(fr: FrameInfo) -> int:
    if fr.event_src in ("arduino_packet", "raw_byte_grouped"):
        return fr.raw_obj.get("start_us", int(fr.elapsed_s * 1_000_000))
    return int(fr.elapsed_s * 1_000_000)


def _frame_end_us(fr: FrameInfo) -> int:
    if fr.event_src in ("arduino_packet", "raw_byte_grouped"):
        return fr.raw_obj.get("end_us", fr.raw_obj.get("start_us",
               int(fr.elapsed_s * 1_000_000)))
    return int(fr.elapsed_s * 1_000_000)


@dataclass
class G19TriggerInfo:
    frame_idx: int
    observed_hex: str
    recovered_hex: str
    gateway19_recovered: bool
    recovered_missing_byte: str
    chk_obs_expected: int       # sum(bytes[:-1]) & 0xFF for observed frame
    chk_actual: int             # last byte of observed frame
    chk_rec_expected: int       # checksum for recovered frame
    g19_start_us: int
    g19_end_us: int
    elapsed_s: float
    bit9_str: str
    stop_str: str
    gap_str: str
    # candidates in time windows after G19 end (as packet dicts)
    candidates_1ms: list = field(default_factory=list)
    candidates_5ms: list = field(default_factory=list)
    candidates_20ms: list = field(default_factory=list)
    candidates_100ms: list = field(default_factory=list)
    first_poll12_frame_idx: Optional[int] = None
    first_poll12_delta_us: Optional[int] = None
    frames_between_count: int = 0
    sequence_to_poll12: list = field(default_factory=list)  # frames G19+1 .. first poll12


def _candidate_entry(fr: FrameInfo, j: int, delta_us: int) -> dict:
    not_poll_like = fr.kind not in ("poll12", "poll12_with_resp") \
                    and not fr.norm_hex.startswith("12")
    confidence = "high"   if delta_us <= 5_000 and not_poll_like else \
                 "medium" if delta_us <= 20_000 else "low"
    return {
        "frame_idx": j,
        "delta_us": delta_us,
        "hex": fr.norm_hex,
        "kind": fr.kind,
        "len_bytes": len(fr.parts),
        "checksum_valid": fr.checksum_valid,
        "confidence": confidence,
        "likely_direction": "likely_old_response_by_timing" if delta_us <= 5_000
                            else "unknown",
    }


def analyze_gateway19_triggers(frames: list[FrameInfo]) -> list[G19TriggerInfo]:
    results: list[G19TriggerInfo] = []

    for i, fr in enumerate(frames):
        if fr.kind != "gateway19":
            continue

        parts = fr.parts
        observed_hex = fr.norm_hex

        # Checksum for observed frame
        chk_obs_exp = chk_actual = 0
        if len(parts) >= 2:
            try:
                data_bytes = [int(p, 16) for p in parts]
                chk_actual = data_bytes[-1]
                chk_obs_exp = sum(data_bytes[:-1]) & 0xFF
            except ValueError:
                pass

        # Missing-byte recovery
        gateway19_recovered = False
        recovered_hex = observed_hex
        recovered_missing_byte = ""
        chk_rec_exp = chk_obs_exp
        if parts == ["19", "03", "00", "1D"]:
            gateway19_recovered = True
            recovered_missing_byte = "01"
            recovered_hex = "19 03 01 00 1D"
            chk_rec_exp = (0x19 + 0x03 + 0x01 + 0x00) & 0xFF  # 0x1D

        g19_start_us = _frame_start_us(fr)
        g19_end_us   = _frame_end_us(fr)
        raw = fr.raw_obj
        bit9_str = str(raw.get("bit9", ""))
        stop_str = str(raw.get("stop", ""))
        gap_str  = str(raw.get("gap",  ""))

        cands_1ms:   list[dict] = []
        cands_5ms:   list[dict] = []
        cands_20ms:  list[dict] = []
        cands_100ms: list[dict] = []
        first_poll12_idx:    Optional[int] = None
        first_poll12_dlt_us: Optional[int] = None
        seq: list[dict] = []

        for j in range(i + 1, min(i + 600, len(frames))):
            nfr = frames[j]
            nfr_start_us = _frame_start_us(nfr)
            delta_us = nfr_start_us - g19_end_us
            if delta_us > 120_000_000:
                break

            is_poll12 = nfr.kind in ("poll12", "poll12_with_resp")
            if first_poll12_idx is None and is_poll12:
                first_poll12_idx    = j
                first_poll12_dlt_us = delta_us

            # Sequence accumulation until first poll12
            seq.append({
                "frame_idx": j,
                "delta_us": delta_us,
                "hex": nfr.norm_hex[:50],
                "kind": nfr.kind,
                "checksum_valid": nfr.checksum_valid,
                "is_poll12": is_poll12,
            })
            if first_poll12_idx is not None:
                break

            # Response window candidates (only before first poll12 is found)
            if delta_us <= 100_000:
                cand = _candidate_entry(nfr, j, delta_us)
                cands_100ms.append(cand)
                if delta_us <= 20_000:
                    cands_20ms.append(cand)
                if delta_us <= 5_000:
                    cands_5ms.append(cand)
                if delta_us <= 1_000:
                    cands_1ms.append(cand)

        frames_between = (first_poll12_idx - i - 1) if first_poll12_idx is not None \
                         else len(seq)

        results.append(G19TriggerInfo(
            frame_idx=i,
            observed_hex=observed_hex,
            recovered_hex=recovered_hex,
            gateway19_recovered=gateway19_recovered,
            recovered_missing_byte=recovered_missing_byte,
            chk_obs_expected=chk_obs_exp,
            chk_actual=chk_actual,
            chk_rec_expected=chk_rec_exp,
            g19_start_us=g19_start_us,
            g19_end_us=g19_end_us,
            elapsed_s=fr.elapsed_s,
            bit9_str=bit9_str,
            stop_str=stop_str,
            gap_str=gap_str,
            candidates_1ms=cands_1ms,
            candidates_5ms=cands_5ms,
            candidates_20ms=cands_20ms,
            candidates_100ms=cands_100ms,
            first_poll12_frame_idx=first_poll12_idx,
            first_poll12_delta_us=first_poll12_dlt_us,
            frames_between_count=frames_between,
            sequence_to_poll12=seq,
        ))

    return results


def _collect_setup_candidates(frames: list[FrameInfo],
                               triggers: list[G19TriggerInfo]) -> list[dict]:
    """Aggregate all response candidates across triggers, dedup by hex."""
    seen: dict[str, dict] = {}
    for trig in triggers:
        for cand in trig.candidates_100ms:
            h = cand["hex"]
            if h not in seen:
                seen[h] = dict(cand, count=0, deltas_us=[])
            seen[h]["count"] += 1
            seen[h]["deltas_us"].append(cand["delta_us"])
    return sorted(seen.values(), key=lambda x: (-x["count"], x["delta_us"]))


ESP_SETUP_A = "03 16 43 64 02 1E 08 E8"
ESP_SETUP_G = "03 16 43 64 02 00 0F AC 7D"


def _match_setup(candidate_hex: str, reference: str) -> str:
    if candidate_hex == reference:
        return "EXACT"
    if candidate_hex.startswith(reference[:5]):
        return "partial"
    return "no"


# ─────────────────────────────────────────────────────────────────────────────
# Merged packet subframe splitter and init-phase analysis
# ─────────────────────────────────────────────────────────────────────────────

@dataclass
class SubFrame:
    """One MDB subframe split from a merged Arduino packet at bit9=1 boundaries."""
    packet_frame_idx: int    # index of source frame in frames list
    subframe_idx: int        # 0-based within this packet
    hex_str: str
    parts: list[str]
    bit9_parts: list[str]
    stop_parts: list[str]
    gap_parts: list[str]
    checksum_valid: bool
    starts_with_bit9: bool
    stop_errors: list[int]   # byte positions where stop=0 (bus contention)


def split_merged_mdb_packet(pkt: dict, frame_idx: int) -> list[SubFrame]:
    """Split Arduino packet at internal bit9=1 boundaries.

    Returns one SubFrame per logical MDB frame fused in this packet.
    Always returns at least one SubFrame for non-empty packets.
    """
    hex_str    = (pkt.get("hex",  "") or "").upper().strip()
    bit9_s     = str(pkt.get("bit9", "") or "")
    stop_s     = str(pkt.get("stop", "") or "")
    gap_s      = str(pkt.get("gap",  "") or "")

    parts      = hex_str.split()   if hex_str else []
    bit9_parts = bit9_s.split()    if bit9_s  else []
    stop_parts = stop_s.split()    if stop_s  else []
    gap_parts  = gap_s.split()     if gap_s   else []

    if not parts:
        return []

    n = len(parts)
    bit9_parts = (bit9_parts + ["0"] * n)[:n]
    stop_parts = (stop_parts + ["1"] * n)[:n]
    gap_parts  = (gap_parts  + ["0"] * n)[:n]

    boundaries = [0] + [i for i in range(1, n) if bit9_parts[i] == "1"] + [n]

    result: list[SubFrame] = []
    for sf_i in range(len(boundaries) - 1):
        s, e = boundaries[sf_i], boundaries[sf_i + 1]
        sp, sb9, sst, sgp = parts[s:e], bit9_parts[s:e], stop_parts[s:e], gap_parts[s:e]
        if not sp:
            continue
        chk_valid = False
        if len(sp) >= 2:
            try:
                bts = [int(x, 16) for x in sp]
                chk_valid = (sum(bts[:-1]) & 0xFF) == bts[-1]
            except ValueError:
                pass
        result.append(SubFrame(
            packet_frame_idx=frame_idx,
            subframe_idx=sf_i,
            hex_str=" ".join(sp),
            parts=sp,
            bit9_parts=sb9,
            stop_parts=sst,
            gap_parts=sgp,
            checksum_valid=chk_valid,
            starts_with_bit9=(sb9[0] == "1" if sb9 else False),
            stop_errors=[i for i, v in enumerate(sst) if v == "0"],
        ))
    return result


def _has_internal_bit9(fr: FrameInfo) -> bool:
    """True if this Arduino packet has bit9=1 at any byte after position 0."""
    pkt = fr.raw_obj
    if not isinstance(pkt, dict):
        return False
    parts = str(pkt.get("bit9", "") or "").split()
    return any(p == "1" for p in parts[1:])


def find_stable_poll12_start(frames: list[FrameInfo],
                              min_run: int = 20,
                              max_gap_ms: float = 1000.0) -> Optional[int]:
    """Return frame index where first stable poll12 run of ≥min_run begins.

    'Stable' means ≥min_run consecutive poll12 frames each within max_gap_ms
    of the previous poll12 (non-poll frames break the run).
    """
    run_start, run_len, prev_s = -1, 0, -1.0
    for i, fr in enumerate(frames):
        is_poll = fr.kind in ("poll12", "poll12_with_resp")
        if not is_poll:
            if run_len >= min_run:
                return run_start
            run_start, run_len, prev_s = -1, 0, -1.0
            continue
        if run_start < 0:
            run_start, run_len, prev_s = i, 1, fr.elapsed_s
        else:
            gap_ms = (fr.elapsed_s - prev_s) * 1000.0
            if gap_ms <= max_gap_ms:
                run_len += 1
                prev_s = fr.elapsed_s
            else:
                run_start, run_len, prev_s = i, 1, fr.elapsed_s
    return run_start if run_len >= min_run else None


def _classify_init_note(fr: FrameInfo) -> str:
    """Short annotation for an init-phase frame."""
    if not fr.parts:
        return ""
    f = fr.parts[0].upper()
    if f == "10" and len(fr.parts) >= 2 and fr.parts[1].upper() == "10":
        return "VMC RESET"
    if f == "11":
        return "VMC SETUP CONFIG" if len(fr.parts) >= 5 else "VMC SETUP"
    if f == "12":
        return ("VMC POLL cashless"
                if len(fr.parts) >= 2 and fr.parts[1].upper() == "12"
                else "VMC POLL variant")
    if f == "14":
        cmd = fr.parts[1].upper() if len(fr.parts) >= 2 else "?"
        return f"VMC READER CMD {cmd}"
    if f == "17":
        return "VMC EXPANSION ID"
    if f == "19":
        return "GATEWAY19"
    if f in ("60", "61"):
        return "VMC POLL (alt device)"
    if f in ("08", "09", "0A", "0B", "0C", "0D", "0E", "0F"):
        return "VMC POLL (coin family)"
    if f in ("30", "31", "32", "33", "34", "35", "36", "37"):
        return "VMC POLL (bill family)"
    if f == "FE":
        return "JUST_RESET / old-device status"
    if f == "00":
        return "ACK"
    if f == "AA":
        return "RET"
    if f == "FF":
        return "NAK"
    return ""


# ─────────────────────────────────────────────────────────────────────────────
# Report builder
# ─────────────────────────────────────────────────────────────────────────────

def build_report(
    events: list[dict],
    frames: list[FrameInfo],
    port: str,
    duration: float,
    elapsed: float,
    fmt_info: Optional[InputFormatInfo] = None,
) -> str:
    L: list[str] = []

    def sec(title: str) -> None:
        L.append("")
        L.append("=" * W)
        L.append(title)
        L.append("=" * W)

    def sub(title: str) -> None:
        L.append("")
        L.append("  " + "-" * (W - 2))
        L.append(f"  {title}")
        L.append("  " + "-" * (W - 2))

    def row(label: str, value: Any) -> None:
        L.append(f"  {label:<38s}  {value}")

    # ── Header ────────────────────────────────────────────────────────────────
    _fi = fmt_info or InputFormatInfo()
    frame_src_label = _fi.frame_source or "rx_frame + sniff_frame_raw"
    L.append("=" * W)
    L.append("OLD DEVICE PASSIVE CAPTURE — ANALYSIS REPORT")
    L.append(f"Date:        {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    L.append(f"Port:        {port}")
    L.append(f"Duration:    {duration:.0f}s target / {elapsed:.1f}s actual")
    L.append(f"Events:      {len(events)} total")
    L.append(f"Frames:      {len(frames)} assembled ({frame_src_label})")
    L.append("=" * W)

    # ── 0. Input format ────────────────────────────────────────────────────────
    sec("0. INPUT FORMAT DETECTED")
    row("format", _fi.format)
    row("frame_source", _fi.frame_source or "(esp_rx_frame)")
    row("raw_byte_count", _fi.raw_byte_count)
    row("packet_count", _fi.packet_count)
    if _fi.boot_info:
        row("packet_gap_us (from boot)", _fi.packet_gap_us)
        row("bit_us (from boot)", _fi.boot_info.get("bit_us", "?"))
        row("inverted (from boot)", _fi.boot_info.get("inverted", "?"))

    # ── 1. Event counts ────────────────────────────────────────────────────────
    sec("1. EVENT COUNTS")
    ev_counts = count_event_kinds(events)
    for ev, cnt in sorted(ev_counts.items(), key=lambda x: -x[1]):
        L.append(f"  {cnt:7d}  {ev}")

    # ── 2. Frame kind distribution ─────────────────────────────────────────────
    sec("2. FRAME KIND DISTRIBUTION")
    fk_counts = count_frame_kinds(frames)
    for k, cnt in sorted(fk_counts.items(), key=lambda x: -x[1]):
        L.append(f"  {cnt:7d}  {k}")
    L.append("")
    dir_counts: dict[str, int] = defaultdict(int)
    for fr in frames:
        dir_counts[fr.direction] += 1
    L.append("  Direction breakdown (rx_frame only):")
    for d, cnt in sorted(dir_counts.items(), key=lambda x: -x[1]):
        L.append(f"  {cnt:7d}  {d}")

    # ── 3. POLL 0x12 analysis ──────────────────────────────────────────────────
    sec("3. POLL 0x12 ANALYSIS  (12 12 → old-device response)")
    poll_st = analyze_poll12(frames)
    poll12_detected = poll_st.total >= POLL12_ACCEPTED_THRESHOLD
    row("poll12_total", poll_st.total)
    row("with inline response (12 12 XX frame)", poll_st.with_inline_resp)
    row("with next-frame response (<5ms gap)", poll_st.with_next_frame_resp)
    row("no response detected", poll_st.no_response)
    row("accepted_polling_flow_detected", "YES" if poll12_detected else "NO")
    if poll_st.first_poll_elapsed_s > 0:
        row("first poll12 at elapsed", f"{poll_st.first_poll_elapsed_s:.2f}s")

    if poll_st.resp_counts:
        sub("Response byte distribution (old device → VMC):")
        total_resp = sum(poll_st.resp_counts.values())
        for resp, cnt in sorted(poll_st.resp_counts.items(), key=lambda x: -x[1])[:15]:
            pct = 100.0 * cnt / total_resp if total_resp else 0
            L.append(f"    {cnt:6d}  ({pct:5.1f}%)  {resp or '(empty)'}")
    else:
        L.append("  No responses counted.")

    if poll_st.gap_ms_list:
        sub("Response gap (frame_gap_before_ms of response frame):")
        gaps = poll_st.gap_ms_list
        row("min gap ms",    f"{min(gaps):.2f}")
        row("median gap ms", f"{med(gaps):.2f}")
        row("max gap ms",    f"{max(gaps):.2f}")
        row("sample count",  len(gaps))

    # Inter-poll period
    periods = analyze_poll12_period(frames)
    if len(periods) >= 5:
        sub("Poll12 inter-cycle period:")
        row("min ms",    f"{min(periods):.1f}")
        row("median ms", f"{med(periods):.1f}")
        row("max ms",    f"{max(periods):.1f}")
        row("count",     len(periods))

    if poll_st.first_20:
        sub("First 20 poll12 cycles (response, gap_ms, source):")
        for i, (resp, gap, src) in enumerate(poll_st.first_20):
            L.append(f"    [{i:02d}]  resp={resp:<4s}  gap={gap:.1f}ms  src={src}")

    # ── 4. Init sequence before first poll12 ────────────────────────────────────
    sec("4. INIT SEQUENCE BEFORE FIRST POLL 0x12")
    init = analyze_init_sequence(frames)
    if init.first_poll_idx < 0:
        L.append("  No poll12 found — entire capture is init/unknown phase.")
        init_frames = frames
    else:
        L.append(f"  First poll12 at index {init.first_poll_idx}, elapsed "
                 f"{init.first_poll_elapsed_s:.2f}s")
        L.append(f"  Frames before first poll12: {len(init.frames_before_first_poll)}")
        init_frames = init.frames_before_first_poll

    sub("Last 40 frames before first poll12 (or first 40 frames if no poll):")
    show = init_frames[-40:] if len(init_frames) > 40 else init_frames
    for fr in show:
        chk = "CRC_OK" if fr.checksum_valid else "     "
        L.append(
            f"  t+{fr.elapsed_s:7.2f}s  gap={fr.gap_before_ms:6.1f}ms  "
            f"{fr.kind:<18s}  {chk}  {fr.norm_hex[:40]}"
        )

    sub("Recognized init frame types:")
    init_kind_counts: dict[str, int] = defaultdict(int)
    for fr in init_frames:
        init_kind_counts[fr.kind] += 1
    for k, cnt in sorted(init_kind_counts.items(), key=lambda x: -x[1]):
        L.append(f"    {cnt:5d}  {k}")

    sub("All 19-like frames in init phase:")
    found_19 = [fr for fr in init_frames if fr.kind == "gateway19"]
    if found_19:
        for fr in found_19:
            L.append(f"  t+{fr.elapsed_s:.2f}s  {fr.norm_hex}  gap={fr.gap_before_ms:.1f}ms")
    else:
        L.append("  None found in init phase.")

    # ── 5. Gateway 19 frame analysis ─────────────────────────────────────────────
    sec("5. GATEWAY 19 FRAME ANALYSIS")
    g19_list = analyze_gateway19_frames(frames)
    L.append(f"  Total frames starting with 0x19: {len(g19_list)}")
    if not g19_list:
        L.append("  No gateway19-like frames found.")
    else:
        # Count unique patterns
        pattern_counts: dict[str, int] = defaultdict(int)
        for g in g19_list:
            pattern_counts[g.norm_hex] += 1
        sub("Unique 19-frame patterns:")
        for pat, cnt in sorted(pattern_counts.items(), key=lambda x: -x[1]):
            L.append(f"    {cnt:5d}x  {pat}")

        sub("Per-frame detail + context (all occurrences):")
        for idx, g in enumerate(g19_list):
            L.append("")
            L.append(f"  [19-frame #{idx+1}]")
            L.append(f"    elapsed:        {g.elapsed_s:.3f}s")
            L.append(f"    raw_hex:        {g.raw_hex}")
            L.append(f"    norm_hex:       {g.norm_hex}")
            L.append(f"    byte_count:     {g.byte_count}")
            L.append(f"    gap_before_ms:  {g.gap_before_ms:.1f}")
            L.append(f"    checksum_valid: {g.checksum_valid}")
            if g.byte_count >= 2:
                L.append(f"    chk_expected:   0x{g.possible_checksum_expected:02X}"
                         f"  chk_actual: 0x{g.possible_checksum_actual:02X}"
                         f"  mismatch: {g.checksum_mismatch}")
            # Decode hypothesis
            if g.norm_hex == "19 03 00 1D":
                L.append("    HYPOTHESIS:")
                L.append("      A) Exact: 19 03 00 1D — valid 3-byte frame")
                L.append("         chk = (0x19+0x03+0x00) & 0xFF = 0x1C ≠ 0x1D → INVALID")
                L.append("         OR checksum not applied to address byte:")
                L.append("         chk = (0x03+0x00) & 0xFF = 0x03 ≠ 0x1D → also INVALID")
                L.append("      B) Missing byte: actual 19 03 01 00 1D (5-byte standard)")
                L.append("         chk = (0x19+0x03+0x01+0x00)&0xFF = 0x1D → VALID")
                L.append("         => MOST LIKELY: sniffer missed byte 0x01")
                L.append("      C) Non-standard checksum / different address scheme")
            elif g.norm_hex == "19 03 01 00 1D":
                L.append("    HYPOTHESIS: Standard 5-byte gateway setup frame.")
                L.append(f"      chk = (0x19+0x03+0x01+0x00)&0xFF = 0x1D → VALID")
            L.append("    Context (prev 5 frames):")
            for pf in g.ctx_before[-5:]:
                L.append(f"      gap={pf.gap_before_ms:6.1f}ms  {pf.kind:<18s}  {pf.norm_hex[:30]}")
            L.append("    Context (next 10 frames):")
            for nf in g.ctx_after[:10]:
                L.append(f"      gap={nf.gap_before_ms:6.1f}ms  {nf.kind:<18s}  {nf.norm_hex[:30]}")

    # ── 6. Reset analysis ────────────────────────────────────────────────────────
    sec("6. RESET ANALYSIS")
    reset_frames = find_reset_frames(frames)
    L.append(f"  reset_10_10 frames observed: {len(reset_frames)}")
    if reset_frames:
        L.append("  Reset timestamps:")
        for rf in reset_frames:
            L.append(f"    t+{rf.elapsed_s:.2f}s  gap={rf.gap_before_ms:.1f}ms  {rf.norm_hex}")
    # Reset events from ESP firmware
    reset_ev_count = ev_counts.get("reset_seen", 0)
    L.append(f"  reset_seen events from ESP firmware: {reset_ev_count}")
    # Is polling continuing after reset?
    if reset_frames and poll_st.total > 0:
        last_reset_s = max(rf.elapsed_s for rf in reset_frames)
        polls_after_reset = sum(
            1 for fr in frames
            if fr.kind in ("poll12", "poll12_with_resp")
            and fr.elapsed_s > last_reset_s
        )
        L.append(f"  Poll12 frames after last reset: {polls_after_reset}")
        if polls_after_reset > 10:
            L.append("  => Polling continues after reset — old device recovers.")

    # Gateway sequences from diagnostic patch
    sequences = extract_sequences(events)
    if sequences:
        sub("gateway_compat_sequence_summary (from ESP diagnostic patch):")
        seq_hex_counts: dict[str, int] = defaultdict(int)
        for s in sequences:
            seq_hex_counts[s.get("sequence_hex", "")] += 1
        for sh, cnt in sorted(seq_hex_counts.items(), key=lambda x: -x[1])[:10]:
            L.append(f"    {cnt:5d}x  {sh}")

    # ── 7. Old-device behavior summary ───────────────────────────────────────────
    sec("7. OLD DEVICE BEHAVIOR SUMMARY")
    poll_resp_str = "n/a"
    if poll_st.resp_counts:
        top = sorted(poll_st.resp_counts.items(), key=lambda x: -x[1])[:3]
        poll_resp_str = "  /  ".join(f"{r}({c})" for r, c in top)

    row("Accepted polling flow (poll12 > 100)", "YES" if poll12_detected else "NO")
    row("Dominant poll command", "12 12" if poll_st.total > 0 else "(not seen)")
    row("Old device response to 12 12 poll", poll_resp_str)
    row("Total poll12 cycles observed", poll_st.total)
    if periods:
        row("Typical poll cycle period", f"{med(periods):.0f}ms")
    row("Reset frames observed", len(reset_frames))
    row("Gateway19-like frames", len(g19_list))

    L.append("")
    L.append("  Likely old device state machine:")
    if poll12_detected:
        top_resp = sorted(poll_st.resp_counts.items(), key=lambda x: -x[1])
        dominant = top_resp[0][0] if top_resp else "?"
        if dominant in ("FE", "FF"):
            L.append("  => Old device is in ACTIVE POLLING state.")
            L.append(f"     It responds to 12 12 POLL with 0x{dominant}"
                     " (likely credit/status byte).")
            L.append("     This indicates the cashless reader is past SETUP phase.")
        elif dominant == "00":
            L.append("  => Old device responds with ACK (0x00) to POLL.")
            L.append("     Device may be in IDLE / DISABLED state, waiting for session.")
        else:
            L.append(f"  => Old device responds with 0x{dominant} to POLL — needs analysis.")
    else:
        L.append("  => Old device did NOT reach stable poll12 phase in this capture.")
        L.append("     Device may still be in init/handshake stage.")

    # ── 8. ESP vs OLD device mismatch ────────────────────────────────────────────
    sec("8. ESP vs OLD DEVICE COMPARISON")
    L.append("")
    hdr = f"  {'Topic':<30s}  {'OLD observed':<25s}  {'ESP current':<28s}  Match?"
    L.append(hdr)
    L.append("  " + "-" * (W - 2))

    def cmp_row(topic: str, old: str, esp: str, match: str) -> None:
        L.append(f"  {topic:<30s}  {old:<25s}  {esp:<28s}  {match}")

    # Init gateway frame
    g19_patterns = sorted(pattern_counts.items(), key=lambda x: -x[1]) if g19_list else []
    old_g19 = g19_patterns[0][0] if g19_patterns else "(not seen)"
    esp_g19 = "19 03 01 00 1D  (RealSetupA)"
    match_g19 = "?" if not g19_list else (
        "YES" if any("01 00 1D" in p for p in pattern_counts) else
        "DIFF (likely missing byte)" if "03 00 1D" in old_g19 else "NO"
    )
    cmp_row("Init gateway frame", old_g19[:25], esp_g19[:28], match_g19)

    # Setup response
    # We don't know old device setup response from passive capture easily
    cmp_row("Setup response (to 19)",
            "not captured (passive)",
            "03 16 43 64 02 1E 08 E8",
            "?")

    # Poll phase
    old_poll = f"12 12 poll x{poll_st.total}" if poll_st.total > 0 else "not seen"
    cmp_row("Poll phase reached", old_poll[:25],
            "NEVER — stuck in gateway", "NO")

    # Poll response
    old_poll_resp = poll_resp_str[:25] if poll_st.resp_counts else "(not seen)"
    cmp_row("Response to POLL (12 12)", old_poll_resp, "no poll phase", "NO")

    # Reset behavior
    old_reset = f"{len(reset_frames)} reset(s)" if reset_frames else "only 1 (10 10 FE?)"
    cmp_row("Reset frequency", old_reset[:25], "every 35-40s gateway cycle", "NO")

    # FE/FC/1C standalone
    fe_count = fk_counts.get("FE", 0)
    fc_count = fk_counts.get("FC", 0)
    one_c_count = fk_counts.get("1C", 0)
    old_ffc = f"FE:{fe_count} FC:{fc_count} 1C:{one_c_count} (in poll resp)"
    cmp_row("Standalone FE/FC/1C", old_ffc[:25],
            "FE/FC/1C as gateway chain", "NO")

    # Conclusion
    L.append("")
    L.append("  Key insight:")
    if poll12_detected:
        L.append("  OLD DEVICE has already completed MDB handshake (SETUP accepted)")
        L.append("  and entered the POLL phase (12 12 cycles).")
        L.append("  ESP is stuck BEFORE this phase — never reaching POLL.")
        L.append("")
        L.append("  Root cause hypothesis:")
        L.append("  - VMC sends SETUP (0x11 or 0x19) → old device responds correctly")
        L.append("  - VMC accepts response → starts POLL (0x12 0x12)")
        L.append("  - ESP setup response variant / checksum / timing may differ")
    else:
        L.append("  Could not confirm old device reached poll phase in this capture.")
        L.append("  Extend capture duration or reconnect old device mid-session.")

    # ── 9. Next steps ─────────────────────────────────────────────────────────────
    sec("9. NEXT STEPS / RECOMMENDATIONS")
    L.append("")
    if poll12_detected:
        L.append("  Priority: reach 12 12 POLL phase with ESP.")
        L.append("")
        L.append("  1. Identify exact SETUP response old device sends after 19:")
        L.append("     - Use two-Arduino sniffer (one on each side of the bus) for direction,")
        L.append("       OR capture longer session and find frames BEFORE first 12 12.")
        L.append("")
        L.append("  2. Check if gateway19 frame is 19 03 01 00 1D or 19 03 00 1D:")
        L.append("     - If sniffer misses byte, actual frame may be standard.")
        L.append("     - ESP already sends 19 03 01 00 1D in no_response mode → compare.")
        L.append("")
        L.append("  3. Stop guessing standalone FE/FC/1C responses:")
        L.append("     - Old device does NOT send standalone FE/FC/1C.")
        L.append("     - FE appears as RESPONSE BYTE to 12 12 POLL, not a standalone event.")
        L.append("")
        L.append("  4. Focus on SETUP response bytes (what old device sends to VMC after 19).")
        L.append("     - Candidate: 03 16 43 64 02 1E 08 E8 (ESP variant A)")
        L.append("     - Try other variants (B, G, H) via mdb_19_response_mode=real_setup_b etc.")
        L.append("")
        L.append("  5. Check poll response byte meaning:")
        for resp, cnt in sorted(poll_st.resp_counts.items(), key=lambda x: -x[1])[:5]:
            if resp == "FE":
                L.append(f"     0xFE ({cnt}x) — may be MDB JUST RESET status, or reader-specific status")
            elif resp == "FF":
                L.append(f"     0xFF ({cnt}x) — may be NAK or reader-specific 'not ready'")
            elif resp == "00":
                L.append(f"     0x00 ({cnt}x) — ACK / nothing to report (IDLE state)")
            else:
                L.append(f"     0x{resp} ({cnt}x) — check MDB cashless spec for this status byte")
    else:
        L.append("  Re-capture with longer duration (600s) or ensure old device is")
        L.append("  actively powered and connected to VMC during capture.")

    # ── 10. Gateway19 recovery analysis ──────────────────────────────────────────
    sec("10. GATEWAY19 RECOVERY ANALYSIS")
    g19_triggers = analyze_gateway19_triggers(frames)
    L.append(f"  Total gateway19-like triggers found: {len(g19_triggers)}")
    L.append("")
    L.append(f"  {'#':<4s}  {'elapsed':>9s}  {'observed_hex':<20s}  "
             f"{'recovered_hex':<22s}  {'chk_obs_exp':>11s}  "
             f"{'chk_actual':>10s}  {'chk_rec_exp':>11s}  recovered")
    L.append("  " + "-" * (W - 2))
    for trig in g19_triggers:
        L.append(
            f"  {trig.frame_idx:<4d}  {trig.elapsed_s:>8.2f}s  "
            f"{trig.observed_hex:<20s}  {trig.recovered_hex:<22s}  "
            f"0x{trig.chk_obs_expected:02X}         "
            f"0x{trig.chk_actual:02X}       "
            f"0x{trig.chk_rec_expected:02X}         "
            f"{'YES (missing '+trig.recovered_missing_byte+')' if trig.gateway19_recovered else 'no'}"
        )
    if g19_triggers and g19_triggers[0].gateway19_recovered:
        L.append("")
        L.append("  Recovery hypothesis (all triggers):")
        L.append("    Observed:  19 03 00 1D  → chk_expected = (19+03+00)&FF = 1C ≠ 1D  INVALID")
        L.append("    Recovered: 19 03 01 00 1D → chk_expected = (19+03+01+00)&FF = 1D = 1D  VALID")
        L.append("    => Arduino sniffer missed byte 0x01 (bit-period ~104µs at 9600 baud)")
        L.append("    => All 5 observed frames are consistent with standard 5-byte gateway19")
        L.append("    checksum_status: bad_observed_but_valid_if_insert_01")

    for trig in g19_triggers:
        L.append("")
        L.append(f"  [G19 #{trig.frame_idx}]  t+{trig.elapsed_s:.3f}s")
        L.append(f"    observed_hex:   {trig.observed_hex}")
        L.append(f"    recovered_hex:  {trig.recovered_hex}")
        L.append(f"    bit9:           {trig.bit9_str}")
        L.append(f"    stop:           {trig.stop_str}")
        L.append(f"    gap_us:         {trig.gap_str}")
        L.append(f"    start_us:       {trig.g19_start_us}")
        L.append(f"    end_us:         {trig.g19_end_us}")
        L.append(f"    chk_observed_expected:  0x{trig.chk_obs_expected:02X}")
        L.append(f"    chk_actual:             0x{trig.chk_actual:02X}")
        L.append(f"    chk_recovered_expected: 0x{trig.chk_rec_expected:02X}")

    # ── 11. Gateway19 response candidates ────────────────────────────────────────
    sec("11. GATEWAY19 RESPONSE CANDIDATES (TIME WINDOW ANALYSIS)")
    for trig in g19_triggers:
        L.append("")
        L.append(f"  [G19 #{trig.frame_idx}]  t+{trig.elapsed_s:.3f}s  "
                 f"start_us={trig.g19_start_us}  end_us={trig.g19_end_us}")
        for label, cands in [
            ("0–1 ms",   trig.candidates_1ms),
            ("0–5 ms",   trig.candidates_5ms),
            ("0–20 ms",  trig.candidates_20ms),
            ("0–100 ms", trig.candidates_100ms),
        ]:
            if cands:
                L.append(f"    window {label}: {len(cands)} candidate(s)")
                for c in cands:
                    L.append(
                        f"      frame[{c['frame_idx']}] delta={c['delta_us']}µs  "
                        f"hex={c['hex'][:30]}  kind={c['kind']}  "
                        f"chk_ok={c['checksum_valid']}  conf={c['confidence']}  "
                        f"dir={c['likely_direction']}"
                    )
            else:
                L.append(f"    window {label}: 0 candidates  (no frame in window)")

        if trig.first_poll12_delta_us is not None:
            L.append(f"    first_poll12_after_g19:  frame[{trig.first_poll12_frame_idx}]  "
                     f"delta={trig.first_poll12_delta_us}µs "
                     f"({trig.first_poll12_delta_us/1000:.1f}ms)")
            L.append(f"    frames_between_g19_and_poll12: {trig.frames_between_count}")
        else:
            L.append("    first_poll12_after_g19:  NOT FOUND in 120s look-ahead")

        if trig.sequence_to_poll12:
            L.append(f"    sequence_g19_to_poll12 ({len(trig.sequence_to_poll12)} frames):")
            for s in trig.sequence_to_poll12:
                marker = "  <── POLL12" if s["is_poll12"] else ""
                L.append(
                    f"      [{s['frame_idx']:4d}]  delta={s['delta_us']:10d}µs  "
                    f"{s['kind']:<20s}  {s['hex']}{marker}"
                )

    # ── 12. Likely old setup response ─────────────────────────────────────────────
    sec("12. LIKELY OLD SETUP RESPONSE AFTER GATEWAY19")
    setup_cands = _collect_setup_candidates(frames, g19_triggers)
    if setup_cands:
        L.append(f"  Found {len(setup_cands)} unique candidate hex(es) in 0–100ms windows:")
        L.append("")
        for sc in setup_cands:
            h = sc["hex"]
            deltas = sc["deltas_us"]
            L.append(f"  candidate_hex:    {h}")
            L.append(f"  count:            {sc['count']}")
            L.append(f"  delta_us_range:   {min(deltas)}–{max(deltas)}µs")
            L.append(f"  confidence:       {sc['confidence']}")
            L.append(f"  match_ESP_A ({ESP_SETUP_A[:20]}...):  "
                     f"{_match_setup(h, ESP_SETUP_A)}")
            L.append(f"  match_ESP_G ({ESP_SETUP_G[:20]}...):  "
                     f"{_match_setup(h, ESP_SETUP_G)}")
            L.append("")
    else:
        L.append("  NO response frame detected in 0–100ms after any gateway19 trigger.")
        L.append("")
        L.append("  Timing analysis:")
        for trig in g19_triggers:
            if trig.first_poll12_delta_us is not None:
                L.append(
                    f"    G19 #{trig.frame_idx}: first frame after G19 = frame[{trig.first_poll12_frame_idx}] "
                    f"at {trig.first_poll12_delta_us}µs ({trig.first_poll12_delta_us/1000:.1f}ms) "
                    f"— already poll12 ('12 12 ...')"
                )
        L.append("")
        L.append("  Possible causes:")
        L.append("    A. Old device was already in POLLING STATE at all G19 occurrences.")
        L.append("       => VMC broadcasts G19 periodically during polling (keep-alive/resync).")
        L.append("       => Old device ignores G19 in polling state (no re-init needed).")
        L.append("    B. Old device responded inline — response bytes merged INTO the G19 packet")
        L.append("       by Arduino assembler (< packet_gap_us=5000µs inter-byte gap).")
        L.append("    C. Capture started AFTER initialization; setup exchange not recorded.")
        L.append("    D. Direction ambiguity: one-wire capture cannot isolate peripheral response")
        L.append("       from VMC traffic without bit9/stop analysis at per-byte level.")
        L.append("")
        L.append("  SETUP exchange visible at G19 #0 aftermath (packet [6]):")
        L.append("    VMC SETUP cmd: 11 00 10 02 26 01 05 85 90 ...")
        L.append("    Followed by bundled bytes: A0 80 F5 00 (bus contention, stop-bit errors)")
        L.append("    Old device READER CONFIG response was NOT cleanly captured as a separate")
        L.append("    packet — likely merged into the VMC SETUP packet due to rapid turnaround.")
        L.append("    => Cannot extract old device READER CONFIG hex from this capture.")
        L.append("")
        L.append(f"  compare_to_ESP_setup_A:  {ESP_SETUP_A}  → UNKNOWN (no candidate)")
        L.append(f"  compare_to_ESP_setup_G:  {ESP_SETUP_G}  → UNKNOWN (no candidate)")

    # ── 13. Init to poll12 timeline ───────────────────────────────────────────────
    sec("13. INIT TO POLL12 TIMELINE (first capture segment)")
    init_seq = analyze_init_sequence(frames)
    all_pre = init_seq.frames_before_first_poll
    show_pre = all_pre[:100]
    if init_seq.first_poll_idx >= 0:
        L.append(f"  First poll12 at frame index {init_seq.first_poll_idx}, "
                 f"t+{init_seq.first_poll_elapsed_s:.3f}s")
        L.append(f"  Frames before first poll12: {len(all_pre)}")
    else:
        L.append("  No poll12 found in capture.")
    L.append("")
    L.append(f"  {'idx':>5s}  {'delta_s':>9s}  {'gap_ms':>8s}  "
             f"{'kind':<22s}  {'chk':>5s}  {'hex'}")
    L.append("  " + "-" * (W - 2))
    g19_idxs = {trig.frame_idx for trig in g19_triggers}
    for fr in show_pre:
        fi = frames.index(fr) if fr in frames[:50] else -1
        chk_str = "OK" if fr.checksum_valid else "bad"
        note = ""
        if fi in g19_idxs or fr.kind == "gateway19":
            note = "  <── GATEWAY19"
        L.append(
            f"  {frames.index(fr) if fr in frames[:500] else '?':>5}  "
            f"t+{fr.elapsed_s:>7.3f}s  {fr.gap_before_ms:>7.1f}ms  "
            f"{fr.kind:<22s}  {chk_str:>5s}  {fr.norm_hex[:35]}{note}"
        )
    if init_seq.first_poll_idx >= 0:
        fp = frames[init_seq.first_poll_idx]
        L.append(
            f"  {init_seq.first_poll_idx:>5d}  t+{fp.elapsed_s:>7.3f}s  "
            f"{fp.gap_before_ms:>7.1f}ms  {fp.kind:<22s}  "
            f"{'OK' if fp.checksum_valid else 'bad':>5s}  "
            f"{fp.norm_hex[:35]}  <── FIRST POLL12"
        )

    # ── 14. Poll12 response distribution detail ───────────────────────────────────
    sec("14. POLL12 RESPONSE DISTRIBUTION DETAIL")
    row("poll12_total", poll_st.total)
    L.append("")
    L.append("  Response byte counts (ALL):")
    for resp, cnt in sorted(poll_st.resp_counts.items(), key=lambda x: -x[1]):
        pct = 100.0 * cnt / poll_st.total if poll_st.total else 0
        try:
            val = int(resp, 16)
            label = ""
            if resp == "FE": label = "JUST_RESET / reader-specific status"
            elif resp == "FF": label = "NAK / not-ready"
            elif resp == "00": label = "ACK / nothing to report (IDLE)"
            elif resp == "01": label = "BEGIN SESSION?"
            L.append(f"    0x{resp}  {cnt:6d}  ({pct:5.1f}%)  {label}")
        except ValueError:
            L.append(f"    {resp!r}  {cnt:6d}  ({pct:5.1f}%)")

    L.append("")
    # Poll period stats in µs
    periods_us = [int(p * 1000) for p in analyze_poll12_period(frames)]
    if len(periods_us) >= 5:
        L.append(f"  Inter-poll period stats:")
        L.append(f"    min_us:    {min(periods_us)}")
        L.append(f"    median_us: {int(med([float(x) for x in periods_us]))}")
        L.append(f"    max_us:    {max(periods_us)}")
        L.append(f"    count:     {len(periods_us)}")

    L.append("")
    L.append("  First 50 poll12 responses (in order):")
    poll_n = 0
    for fr in frames:
        if fr.kind not in ("poll12", "poll12_with_resp"):
            continue
        resp_byte = fr.poll12_resp if fr.kind == "poll12_with_resp" else "(none)"
        L.append(f"    [{poll_n:04d}]  t+{fr.elapsed_s:.3f}s  resp=0x{resp_byte}")
        poll_n += 1
        if poll_n >= 50:
            break

    # ── 15. A. INIT/SETUP PACKETS ─────────────────────────────────────────────
    sec("15. A. INIT / SETUP PACKETS (pre-poll init phase)")
    stable_idx = find_stable_poll12_start(frames)
    if stable_idx is not None:
        init_fr = frames[:stable_idx]
        L.append(f"  Stable poll12 run begins at frame index {stable_idx}, "
                 f"t+{frames[stable_idx].elapsed_s:.3f}s")
    else:
        init_fr = [fr for fr in frames if fr.elapsed_s <= 60.0]
        L.append("  No stable poll12 run found — showing frames with elapsed_s ≤ 60s.")
    L.append(f"  Init-phase frames shown: {len(init_fr)}")
    L.append("")
    L.append(f"  {'idx':>5s}  {'t+s':>8s}  {'gap_ms':>7s}  "
             f"{'kind':<22s}  {'chk':>5s}  {'note':<26s}  hex")
    L.append("  " + "-" * (W - 2))
    setup_11_frames: list[tuple[int, FrameInfo]] = []
    for idx, fr in enumerate(init_fr):
        chk_s = "OK" if fr.checksum_valid else "bad"
        note = _classify_init_note(fr)
        merged = " [M]" if (_fi.format == "arduino" and _has_internal_bit9(fr)) else ""
        if fr.parts and fr.parts[0].upper() == "11":
            setup_11_frames.append((idx, fr))
        L.append(
            f"  {idx:>5d}  t+{fr.elapsed_s:>6.3f}s  {fr.gap_before_ms:>6.1f}ms  "
            f"{fr.kind:<22s}  {chk_s:>5s}  {note:<26s}  {fr.norm_hex[:28]}{merged}"
        )
    if setup_11_frames:
        L.append("")
        sub("VMC SETUP (0x11) frames — raw packet detail:")
        for idx, fr in setup_11_frames:
            raw = fr.raw_obj
            L.append(f"    frame[{idx}]  t+{fr.elapsed_s:.3f}s  {fr.norm_hex}")
            if isinstance(raw, dict) and _fi.format == "arduino":
                L.append(f"      bit9:       {raw.get('bit9', 'n/a')}")
                L.append(f"      stop:       {raw.get('stop', 'n/a')}")
                L.append(f"      gap_us:     {raw.get('gap',  'n/a')}")
                L.append(f"      checksum:   {raw.get('checksum', 'n/a')}"
                         f"  expected={raw.get('checksum_expected', '?')}"
                         f"  actual={raw.get('checksum_actual', '?')}")

    # Compute subframes for sections B and C
    all_subframes: list[SubFrame] = []
    merged_init_frames: list[tuple[int, FrameInfo]] = []
    if _fi.format == "arduino":
        for idx, fr in enumerate(init_fr):
            if _has_internal_bit9(fr):
                merged_init_frames.append((idx, fr))
                all_subframes.extend(split_merged_mdb_packet(fr.raw_obj, idx))

    # ── 16. B. MERGED PACKET SUBFRAME SPLIT ───────────────────────────────────
    sec("16. B. MERGED PACKET SUBFRAME SPLIT (bit9=1 boundary heuristic)")
    if _fi.format != "arduino":
        L.append("  (Only applicable to Arduino format captures.)")
    else:
        L.append(f"  Merged packets in init phase (internal bit9=1 transitions): "
                 f"{len(merged_init_frames)}")
        L.append("")
        for idx, fr in merged_init_frames:
            pkt = fr.raw_obj
            sfs = split_merged_mdb_packet(pkt, idx)
            L.append(f"  [frame {idx}]  t+{fr.elapsed_s:.3f}s  "
                     f"{len(fr.parts)} bytes  →  {len(sfs)} subframe(s)")
            L.append(f"    full_hex: {fr.norm_hex}")
            L.append(f"    bit9:     {pkt.get('bit9', 'n/a')}")
            L.append(f"    stop:     {pkt.get('stop', 'n/a')}")
            L.append(f"    gap_us:   {pkt.get('gap',  'n/a')}")
            L.append("")
            for sf in sfs:
                sf_kind, _ = _classify(sf.parts)
                sf_note = _classify_init_note(FrameInfo(
                    raw_hex=sf.hex_str, norm_hex=sf.hex_str,
                    parts=sf.parts, kind=sf_kind, poll12_resp="",
                    direction="UNKNOWN", gap_before_ms=0.0,
                    decoded_frame_kind="", has_high_bit=sf.starts_with_bit9,
                    checksum_valid=sf.checksum_valid, candidate_address=-1,
                    candidate_command=-1, elapsed_s=fr.elapsed_s,
                    event_src="subframe", raw_obj={},
                ))
                stop_note = (f"  STOP_ERRORS@{sf.stop_errors}" if sf.stop_errors else "")
                L.append(
                    f"    SF[{sf.subframe_idx}]  bit9={sf.bit9_parts[0] if sf.bit9_parts else '?'}  "
                    f"chk={'OK' if sf.checksum_valid else 'bad'}  "
                    f"{sf_kind:<20s}  {sf.hex_str[:38]}  {sf_note}{stop_note}"
                )
            L.append("")

    # ── 17. C. OLD READER CONFIG CANDIDATES ───────────────────────────────────
    sec("17. C. OLD READER CONFIG CANDIDATES (0x03-starting subframes)")
    if _fi.format != "arduino":
        L.append("  (Only applicable to Arduino format captures.)")
    else:
        reader_cands = [sf for sf in all_subframes
                        if sf.parts and sf.parts[0].upper() == "03"]
        all_03_frames = [fr for fr in frames
                         if fr.parts and fr.parts[0].upper() == "03"]
        L.append(f"  0x03-starting subframes (from merged-packet splits): {len(reader_cands)}")
        L.append(f"  0x03-starting full frames (entire capture):           {len(all_03_frames)}")
        if reader_cands or all_03_frames:
            L.append("")
            for sf in reader_cands:
                L.append(f"  SUBFRAME CANDIDATE: frame[{sf.packet_frame_idx}] SF[{sf.subframe_idx}]")
                L.append(f"    hex:         {sf.hex_str}")
                L.append(f"    chk_valid:   {sf.checksum_valid}")
                L.append(f"    match_ESP_A: {_match_setup(sf.hex_str, ESP_SETUP_A)}")
                L.append(f"    match_ESP_G: {_match_setup(sf.hex_str, ESP_SETUP_G)}")
            for fr in all_03_frames:
                L.append(f"  FULL FRAME: t+{fr.elapsed_s:.3f}s  {fr.norm_hex}")
        else:
            L.append("")
            L.append("  RESULT: NO 0x03-starting frame found anywhere in the capture.")
            L.append("")
            L.append("  Expected MDB cashless READER CONFIG format (old device → VMC):")
            L.append("    03 [display_cols] [display_rows] [display_info]")
            L.append("    [scale_factor_lo] [scale_factor_hi] [decimal_places] [checksum]")
            L.append(f"    ESP variant A: {ESP_SETUP_A}")
            L.append(f"    ESP variant G: {ESP_SETUP_G}")
            L.append("")
            L.append("  Why 0x03 response was not captured (bus contention analysis):")
            L.append("    A. One-wire bus: VMC SETUP (0x11...) and old device response (0x03...)")
            L.append("       transmit simultaneously. Arduino captures XOR'd/collided signal.")
            L.append("       Stop-bit errors (stop=0) in merged packets confirm simultaneous TX.")
            L.append("    B. Arduino packet assembler merges device response bytes INTO the VMC")
            L.append("       SETUP packet when inter-byte gap < packet_gap_us (5000µs). The")
            L.append("       post-collision bytes A0, 80, F5, 00 do not decode cleanly to 0x03.")
            L.append("    C. Capture began mid-session — the visible SETUP at t+36.7s is a")
            L.append("       re-init after VMC RESET. The device may send a very fast ACK")
            L.append("       rather than a full READER CONFIG response on re-initialization.")
            L.append("")
            # Show the SETUP packet with stop errors if available
            for idx, fr in merged_init_frames:
                if fr.parts and fr.parts[0].upper() == "11":
                    raw = fr.raw_obj
                    L.append(f"  Bus contention evidence — frame[{idx}] (SETUP packet):")
                    L.append(f"    hex:  {fr.norm_hex}")
                    if isinstance(raw, dict):
                        L.append(f"    stop: {raw.get('stop', 'n/a')}")
                        L.append("    (stop=0 bytes = bus collision; VMC + device driving simultaneously)")
                    break

    # ── 18. D. INIT TO FIRST STABLE POLL12 TIMELINE ───────────────────────────
    sec("18. D. INIT TO FIRST STABLE POLL12 TIMELINE (annotated)")
    if stable_idx is not None:
        L.append(f"  Stable poll12 at frame index {stable_idx}, "
                 f"t+{frames[stable_idx].elapsed_s:.3f}s")
        show_end = stable_idx + 4
    else:
        L.append("  No stable poll12 run found — showing first 40 frames.")
        show_end = min(40, len(frames))
    L.append("")
    L.append(f"  {'idx':>5s}  {'t+s':>8s}  {'gap_ms':>7s}  {'kind':<22s}  annotation")
    L.append("  " + "-" * (W - 2))
    prev_kind = ""
    for idx in range(min(show_end, len(frames))):
        fr = frames[idx]
        note = _classify_init_note(fr)
        merged = " [M]" if (_fi.format == "arduino" and _has_internal_bit9(fr)) else ""
        marker = ""
        if idx == stable_idx:
            marker = "  <══ STABLE POLL12 START"
        elif fr.kind in ("poll12", "poll12_with_resp") \
                and prev_kind not in ("poll12", "poll12_with_resp"):
            marker = "  <── first poll12"
        L.append(
            f"  {idx:>5d}  t+{fr.elapsed_s:>6.3f}s  {fr.gap_before_ms:>6.1f}ms  "
            f"{fr.kind:<22s}  {note}{merged}{marker}"
        )
        prev_kind = fr.kind

    # ── 19. E. POLL12 RESPONSE SEMANTICS ──────────────────────────────────────
    sec("19. E. POLL12 RESPONSE SEMANTICS (first 100 cycles)")
    L.append("")
    L.append("  MDB cashless POLL (0x12 0x12) response byte semantics:")
    L.append("    0x00  ACK / nothing to report  (device idle, no pending data)")
    L.append("    0xFE  JUST RESET               (device reset; VMC must send SETUP next)")
    L.append("    0xFF  NAK                      (device not ready)")
    L.append("    other Data block first byte    (session begin, vend result, error, ...)")
    L.append("")
    L.append("  In this one-wire capture: response byte may be fused into POLL packet")
    L.append("  as '12 12 XX' (Arduino merged VMC poll + device response into one packet).")
    L.append("  Direction is UNKNOWN — XX may be old-device reply OR next VMC byte.")
    L.append("")
    L.append(f"  {'#':>6s}  {'t+s':>8s}  {'resp':>6s}  {'dec':>4s}  semantics")
    L.append("  " + "-" * (W - 2))
    poll_n = 0
    for fr in frames:
        if fr.kind not in ("poll12", "poll12_with_resp"):
            continue
        resp = fr.poll12_resp if fr.kind == "poll12_with_resp" else "(none)"
        try:
            val = int(resp, 16)
            if resp.upper() == "FE":
                sem = "JUST_RESET (device needs re-SETUP)"
            elif resp.upper() == "FF":
                sem = "NAK / not ready"
            elif resp == "00":
                sem = "ACK / nothing to report"
            elif val == 0x01:
                sem = "BEGIN_SESSION (card inserted?)"
            elif 0x02 <= val <= 0x0A:
                sem = "data block (session/vend status)"
            else:
                sem = ""
        except ValueError:
            val = -1
            sem = ""
        L.append(
            f"  {poll_n:>6d}  t+{fr.elapsed_s:>6.3f}s  "
            f"{'0x'+resp if resp != '(none)' else '   ---':>6s}  "
            f"{val if val >= 0 else '':>4}  {sem}"
        )
        poll_n += 1
        if poll_n >= 100:
            L.append(f"  ... ({poll_st.total - 100} more cycles not shown)")
            break

    L.append("")
    L.append("=" * W)
    L.append("END OF REPORT")
    L.append("=" * W)
    return "\n".join(L)


# ─────────────────────────────────────────────────────────────────────────────
# Offline analysis from existing JSONL
# ─────────────────────────────────────────────────────────────────────────────

def load_jsonl(path: Path) -> list[dict]:
    events: list[dict] = []
    with path.open("r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            try:
                obj = json.loads(line)
                if not isinstance(obj, dict):
                    continue
                # Unwrap Arduino raw_line envelope {"kind":"raw_line","line":"..."}
                if obj.get("kind") == "raw_line" and "line" in obj:
                    try:
                        inner = json.loads(obj["line"])
                        if isinstance(inner, dict):
                            events.append(inner)
                    except json.JSONDecodeError:
                        pass
                else:
                    events.append(obj)
            except json.JSONDecodeError:
                pass
    return events


# ─────────────────────────────────────────────────────────────────────────────
# Main
# ─────────────────────────────────────────────────────────────────────────────

def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(
        description="Passive capture VMC <-> old device  |  or re-analyze JSONL"
    )
    p.add_argument("port", nargs="?", default=DEFAULT_PORT,
                   help="Serial port (default: /dev/ttyUSB1)")
    p.add_argument("--duration", type=float, default=300.0,
                   help="Capture duration in seconds (default: 300)")
    p.add_argument("--no-reboot", action="store_true",
                   help="Skip reboot (assume already configured as passive)")
    p.add_argument("--analyze", metavar="FILE",
                   help="Re-analyze an existing .jsonl capture file (no hardware needed)")
    return p.parse_args()


def main() -> None:
    args = parse_args()

    OUT_DIR.mkdir(exist_ok=True)
    stamp = datetime.now().strftime("%Y%m%d_%H%M%S")

    if args.analyze:
        # ── Offline analysis mode ─────────────────────────────────────────────
        jsonl_path = Path(args.analyze)
        if not jsonl_path.exists():
            print(f"ERROR: file not found: {jsonl_path}")
            sys.exit(1)
        txt_path = jsonl_path.with_suffix(".analyzed.txt")
        log(f"Loading {jsonl_path} ...")
        events = load_jsonl(jsonl_path)
        log(f"Loaded {len(events)} events. Building timeline...")
        frames, fmt_info = build_timeline(events)
        log(f"Timeline: {len(frames)} frames ({fmt_info.frame_source}). Building report...")
        elapsed = 0.0
        if events:
            # For Arduino: derive elapsed from packet start_us span
            if fmt_info.format == "arduino":
                pkts = [e for e in events if e.get("type") == "packet"]
                if pkts:
                    t0 = pkts[0].get("start_us", 0)
                    t1 = pkts[-1].get("end_us", pkts[-1].get("start_us", t0))
                    elapsed = (t1 - t0) / 1_000_000.0
            else:
                elapsed = max(
                    (obj.get("_elapsed_s", obj.get("_capture_elapsed_s", 0.0))
                     for obj in events),
                    default=0.0,
                )
        report = build_report(events, frames, str(jsonl_path), args.duration, elapsed,
                              fmt_info)
        print("\n" + report)
        txt_path.write_text(report + "\n", encoding="utf-8")
        log(f"Report saved to {txt_path}")
        return

    # ── Live capture mode ─────────────────────────────────────────────────────
    port: str = args.port
    duration: float = args.duration
    jsonl_path = OUT_DIR / f"old_device_capture_{stamp}.jsonl"
    txt_path   = OUT_DIR / f"old_device_capture_{stamp}.txt"

    conn = Conn(port)
    try:
        if not args.no_reboot:
            configure_passive_mode(conn)
        else:
            log("--no-reboot: assuming passive mode already active.")
            conn.drain(1.0)

        log(f"=== PASSIVE CAPTURE: {duration:.0f}s ===")
        log("Connect OLD DEVICE to VMC bus (if not already).")
        log("ESP is silent — no responses will be sent.")
        log(f"Output: {jsonl_path}")

        t_start = time.monotonic()
        events = conn.collect(duration, jsonl_path)
        elapsed = time.monotonic() - t_start

        log("Building timeline and report...")
        frames, fmt_info = build_timeline(events)
        report = build_report(events, frames, port, duration, elapsed, fmt_info)

        print("\n" + report)
        txt_path.write_text(report + "\n", encoding="utf-8")
        log(f"Report:  {txt_path}")
        log(f"JSONL:   {jsonl_path}")

    finally:
        conn.close()


if __name__ == "__main__":
    main()
