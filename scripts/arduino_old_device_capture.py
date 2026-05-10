#!/usr/bin/env python3
"""Arduino passive MDB/one-wire old-device capture.

The script only reads Arduino Serial and never sends commands to VMC/ESP.
It accepts JSONL or text byte logs, groups raw 9-bit words into frames by gap,
and produces JSONL + TXT analysis.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
import time
from collections import Counter, defaultdict
from dataclasses import asdict, dataclass, field
from datetime import datetime
from pathlib import Path
from typing import Any

import serial

BAUD_DEFAULT = 115200
GAP_US_DEFAULT = 5000
RESPONSE_WINDOW_US = 5000
OUT_DIR = Path.cwd() / "test_logs"

ESP_REFERENCE = {
    "19 03 01 00 1D": "A: 03 16 43 64 02 1E 08 E8 / G: 03 16 43 64 02 00 0F AC 7D",
    "FE": "0B 0B / ACK 00 / no_response",
    "FC": "ignore / ACK 00 / RET AA / NAK FF",
    "1C": "ignore / RET AA / NAK FF / ack_enable / ack_only",
    "E0": "ignore / ACK 00 / RET AA / NAK FF",
}


def now_stamp() -> str:
    return datetime.now().strftime("%Y%m%d_%H%M%S")


def log(msg: str) -> None:
    print(f"[{datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3]}] {msg}", flush=True)


@dataclass
class ByteRecord:
    index: int
    host_ts_s: float
    timestamp_us: int | None
    data: int
    ninth_bit: bool | None
    gap_us: int | None
    raw9: int | None
    direction: str = "UNKNOWN"
    packet_id: int = 0
    raw_line: str = ""

    @property
    def hex(self) -> str:
        return f"{self.data:02X}"


@dataclass
class FrameRecord:
    packet_id: int
    start_us: int | None
    end_us: int | None
    host_start_s: float
    host_end_s: float
    frame_hex: str
    ninth_bits: list[bool | None]
    first_byte: str
    candidate_family: str
    candidate_command: int | None
    checksum_valid: bool | None
    direction: str
    bytes: list[dict[str, Any]] = field(default_factory=list)


def parse_bool(value: Any) -> bool | None:
    if isinstance(value, bool):
        return value
    if isinstance(value, int):
        return bool(value)
    if isinstance(value, str):
        v = value.strip().lower()
        if v in {"1", "true", "t", "yes", "y", "addr", "address"}:
            return True
        if v in {"0", "false", "f", "no", "n", "data"}:
            return False
    return None


def parse_int_maybe(value: Any) -> int | None:
    if value is None:
        return None
    if isinstance(value, int):
        return value
    if isinstance(value, float):
        return int(value)
    if isinstance(value, str):
        v = value.strip()
        if not v:
            return None
        try:
            return int(v, 16) if v.lower().startswith("0x") else int(v)
        except ValueError:
            return None
    return None


def parse_hex_byte(value: Any) -> int | None:
    if value is None:
        return None
    if isinstance(value, int):
        return value & 0xFF
    text = str(value).strip()
    text = text.replace("0x", "").replace("0X", "")
    m = re.search(r"\b([0-9A-Fa-f]{1,2})\b", text)
    if not m:
        return None
    return int(m.group(1), 16) & 0xFF


def parse_line(line: str, index: int, host_ts: float) -> ByteRecord | None:
    text = line.strip()
    if not text:
        return None

    obj: dict[str, Any] | None = None
    if text.startswith("{") and text.endswith("}"):
        try:
            parsed = json.loads(text)
            if isinstance(parsed, dict):
                obj = parsed
        except json.JSONDecodeError:
            obj = None

    if obj is not None:
        line_type = str(obj.get("type", obj.get("event", ""))).lower()
        if line_type and line_type not in {"raw_byte", "sniff_byte", "byte", "raw9"}:
            return None
        d = obj.get("details") if isinstance(obj.get("details"), dict) else obj
        raw9 = parse_int_maybe(d.get("raw9") or d.get("word") or d.get("raw_word"))
        data_value = None
        for key in ("data_byte", "byte", "hex", "data", "value"):
            if key in d:
                data_value = d.get(key)
                break
        data = parse_hex_byte(data_value)
        if data is None and raw9 is not None:
            data = raw9 & 0xFF
        if data is None:
            return None
        ninth_value = None
        for key in ("ninth_bit", "ninth", "bit9", "addr"):
            if key in d:
                ninth_value = d.get(key)
                break
        ninth = parse_bool(ninth_value)
        if ninth is None and raw9 is not None:
            ninth = bool(raw9 & 0x100)
        ts_value = None
        for key in ("timestamp_us", "ts_us", "time_us", "micros"):
            if key in d:
                ts_value = d.get(key)
                break
        gap_value = None
        for key in ("gap_us", "delta_us", "gap"):
            if key in d:
                gap_value = d.get(key)
                break
        ts_us = parse_int_maybe(ts_value)
        gap_us = parse_int_maybe(gap_value)
        direction = str(d.get("direction") or d.get("decoded_direction") or "UNKNOWN")
        return ByteRecord(index, host_ts, ts_us, data, ninth, gap_us, raw9, direction, raw_line=text)

    raw9_match = re.search(r"raw9\s*[:=]\s*(0x[0-9A-Fa-f]+|\d+)", text, re.I)
    raw9 = parse_int_maybe(raw9_match.group(1)) if raw9_match else None

    byte_match = re.search(
        r"(?:data_byte|byte|hex|data)\s*[:=]\s*(?:0x)?([0-9A-Fa-f]{1,2})\b", text, re.I
    )
    data = int(byte_match.group(1), 16) if byte_match else None
    if data is None and raw9 is not None:
        data = raw9 & 0xFF
    if data is None:
        loose = re.findall(r"\b(?:0x)?([0-9A-Fa-f]{2})\b", text)
        if loose:
            data = int(loose[-1], 16)
    if data is None:
        return None

    ts_match = re.search(r"(?:timestamp_us|ts_us|time_us|micros|t)\s*[:=]\s*(\d+)", text, re.I)
    gap_match = re.search(r"(?:gap_us|delta_us|gap)\s*[:=]\s*(\d+)", text, re.I)
    ninth_match = re.search(r"(?:ninth_bit|ninth|addr)\s*[:=]\s*(true|false|[01])", text, re.I)
    direction_match = re.search(r"(?:direction|dir)\s*[:=]\s*([A-Za-z_]+)", text, re.I)
    ninth = parse_bool(ninth_match.group(1)) if ninth_match else None
    if ninth is None and raw9 is not None:
        ninth = bool(raw9 & 0x100)
    return ByteRecord(
        index=index,
        host_ts_s=host_ts,
        timestamp_us=parse_int_maybe(ts_match.group(1)) if ts_match else None,
        data=data & 0xFF,
        ninth_bit=ninth,
        gap_us=parse_int_maybe(gap_match.group(1)) if gap_match else None,
        raw9=raw9,
        direction=direction_match.group(1) if direction_match else "UNKNOWN",
        raw_line=text,
    )


def checksum_valid(data: list[int]) -> bool | None:
    if len(data) < 2:
        return None
    return (sum(data[:-1]) & 0xFF) == data[-1]


def candidate_family(first: int) -> str:
    if first in {0xFE, 0xFC, 0x1C, 0xE0, 0x00, 0xAA, 0xFF}:
        return f"compact_{first:02X}"
    fam = first & 0xF8
    if 0x10 <= first <= 0x17:
        label = "cashless-like"
    elif 0x18 <= first <= 0x1F:
        label = "gateway/compat-like"
    elif 0x08 <= first <= 0x0F:
        label = "coin-like"
    elif 0x30 <= first <= 0x37:
        label = "bill-like"
    else:
        label = "other"
    return f"0x{fam:02X} {label}"


def frame_direction(records: list[ByteRecord]) -> str:
    dirs = [r.direction for r in records if r.direction and r.direction.upper() not in {"UNKNOWN", "NONE"}]
    if not dirs:
        return "UNKNOWN"
    common = Counter(dirs).most_common(1)[0][0]
    return common


def group_frames(records: list[ByteRecord], gap_us: int) -> list[FrameRecord]:
    frames: list[FrameRecord] = []
    packet_id = 0
    current: list[ByteRecord] = []
    prev_ts: int | None = None
    prev_host: float | None = None

    def close() -> None:
        nonlocal current, packet_id
        if not current:
            return
        data = [r.data for r in current]
        for r in current:
            r.packet_id = packet_id
        frames.append(
            FrameRecord(
                packet_id=packet_id,
                start_us=current[0].timestamp_us,
                end_us=current[-1].timestamp_us,
                host_start_s=current[0].host_ts_s,
                host_end_s=current[-1].host_ts_s,
                frame_hex=" ".join(f"{b:02X}" for b in data),
                ninth_bits=[r.ninth_bit for r in current],
                first_byte=f"{data[0]:02X}",
                candidate_family=candidate_family(data[0]),
                candidate_command=(data[0] & 0x07) if data[0] not in {0xFE, 0xFC, 0x1C, 0xE0, 0x00, 0xAA, 0xFF} else None,
                checksum_valid=checksum_valid(data),
                direction=frame_direction(current),
                bytes=[asdict(r) for r in current],
            )
        )
        packet_id += 1
        current = []

    for rec in records:
        is_new = False
        if current:
            if rec.gap_us is not None:
                is_new = rec.gap_us > gap_us
            elif rec.timestamp_us is not None and prev_ts is not None:
                delta = rec.timestamp_us - prev_ts if rec.timestamp_us >= prev_ts else 0
                is_new = delta > gap_us
            elif prev_host is not None:
                is_new = (rec.host_ts_s - prev_host) * 1_000_000 > gap_us
        if is_new:
            close()
        current.append(rec)
        prev_ts = rec.timestamp_us
        prev_host = rec.host_ts_s
    close()
    return frames


def is_trigger(frame: FrameRecord, trigger: str) -> bool:
    h = frame.frame_hex.upper()
    if trigger == "19 03 01 00 1D":
        return h == trigger
    if trigger == "10 10":
        return h.startswith("10 10")
    return h == trigger


def frame_time_us(frame: FrameRecord) -> int:
    if frame.start_us is not None:
        return frame.start_us
    return int(frame.host_start_s * 1_000_000)


def frame_end_us(frame: FrameRecord) -> int:
    if frame.end_us is not None:
        return frame.end_us
    return int(frame.host_end_s * 1_000_000)


def trigger_responses(frames: list[FrameRecord], trigger: str) -> list[dict[str, Any]]:
    out: list[dict[str, Any]] = []
    for i, frame in enumerate(frames):
        if not is_trigger(frame, trigger):
            continue
        trig_end = frame_end_us(frame)
        responses = []
        for cand in frames[i + 1 :]:
            delay = frame_time_us(cand) - trig_end
            if delay < 0:
                continue
            if delay > RESPONSE_WINDOW_US:
                break
            responses.append(
                {
                    "frame_hex": cand.frame_hex,
                    "delay_us": delay,
                    "direction": cand.direction,
                    "direction_confidence": "confirmed" if cand.direction != "UNKNOWN" else "inferred_by_timing",
                    "ninth_bits": cand.ninth_bits,
                    "candidate_family": cand.candidate_family,
                }
            )
        out.append(
            {
                "trigger_frame": frame.frame_hex,
                "trigger_start_us": frame.start_us,
                "trigger_index": i,
                "responses": responses,
            }
        )
    return out


def window_patterns(frames: list[FrameRecord], trigger: str, after: int = 8) -> Counter[str]:
    c: Counter[str] = Counter()
    for i, frame in enumerate(frames):
        if is_trigger(frame, trigger):
            seq = [f.frame_hex for f in frames[i : i + after]]
            c[" -> ".join(seq)] += 1
    return c


def contexts(frames: list[FrameRecord], trigger: str, before: int, after: int) -> list[dict[str, Any]]:
    out = []
    for i, frame in enumerate(frames):
        if is_trigger(frame, trigger):
            out.append(
                {
                    "index": i,
                    "trigger": frame.frame_hex,
                    "before": [f.frame_hex for f in frames[max(0, i - before) : i]],
                    "after": [f.frame_hex for f in frames[i + 1 : i + 1 + after]],
                }
            )
    return out


def write_jsonl(path: Path, raw_lines: list[str], bytes_: list[ByteRecord], frames: list[FrameRecord],
                analysis: dict[str, Any]) -> None:
    with path.open("w", encoding="utf-8") as f:
        for line in raw_lines:
            f.write(json.dumps({"kind": "raw_line", "line": line}, ensure_ascii=False) + "\n")
        for b in bytes_:
            f.write(json.dumps({"kind": "byte", **asdict(b)}, ensure_ascii=False) + "\n")
        for fr in frames:
            f.write(json.dumps({"kind": "frame", **asdict(fr)}, ensure_ascii=False) + "\n")
        f.write(json.dumps({"kind": "analysis", **analysis}, ensure_ascii=False) + "\n")


def make_report(port: str, duration: float, baud: int, gap_us: int, raw_lines: list[str],
                bytes_: list[ByteRecord], frames: list[FrameRecord],
                analysis: dict[str, Any]) -> str:
    first_bytes = Counter(f.first_byte for f in frames)
    families = Counter(f.candidate_family for f in frames)
    patterns = Counter(f.frame_hex for f in frames)
    directions = Counter(f.direction for f in frames)
    important = {
        "gateway19": sum(1 for f in frames if is_trigger(f, "19 03 01 00 1D")),
        "FE": sum(1 for f in frames if f.frame_hex == "FE"),
        "FC": sum(1 for f in frames if f.frame_hex == "FC"),
        "1C": sum(1 for f in frames if f.frame_hex == "1C"),
        "E0": sum(1 for f in frames if f.frame_hex == "E0"),
        "reset_10_10": sum(1 for f in frames if is_trigger(f, "10 10")),
        "ACK_00": sum(1 for f in frames if f.frame_hex == "00"),
        "RET_AA": sum(1 for f in frames if f.frame_hex == "AA"),
        "NAK_FF": sum(1 for f in frames if f.frame_hex == "FF"),
    }
    lines: list[str] = []
    lines.append("ARDUINO OLD DEVICE PASSIVE CAPTURE")
    lines.append(f"date: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    lines.append("")
    lines.append("1. Capture info:")
    lines.append(f"- port: {port}")
    lines.append(f"- duration: {duration}")
    lines.append(f"- baud: {baud}")
    lines.append(f"- total raw lines: {len(raw_lines)}")
    lines.append(f"- total parsed bytes: {len(bytes_)}")
    lines.append(f"- total frames: {len(frames)}")
    lines.append(f"- packet gap threshold us: {gap_us}")
    lines.append("- bit timing: from Arduino timestamps/gap_us when present")
    lines.append("")
    lines.append("2. Address/family summary:")
    lines.append(f"- all first bytes seen: {dict(first_bytes)}")
    lines.append(f"- all candidate families: {dict(families)}")
    lines.append("- top 20 frame_hex patterns:")
    for h, n in patterns.most_common(20):
        lines.append(f"  {h}: {n}")
    lines.append("")
    lines.append("3. Important byte counts:")
    for k, v in important.items():
        lines.append(f"- {k}: {v}")
    lines.append("")
    lines.append("4. Trigger-response within 5ms:")
    for trig in ["19 03 01 00 1D", "FE", "FC", "1C", "E0", "10 10"]:
        trs = analysis["trigger_responses"].get(trig, [])
        lines.append(f"- after {trig}: {len(trs)} trigger(s)")
        for item in trs[:10]:
            resp = item["responses"][:5]
            lines.append(f"  trigger_index={item['trigger_index']} responses={resp if resp else 'none'}")
    lines.append("")
    lines.append("5. Sequence patterns:")
    for trig in ["19 03 01 00 1D", "FE", "FC", "1C", "E0"]:
        lines.append(f"- most common after {trig}:")
        for seq, n in analysis["patterns"].get(trig, [])[:5]:
            lines.append(f"  {n}x {seq}")
    lines.append("- most common before reset:")
    for ctx in analysis["reset_contexts"][:5]:
        lines.append(f"  before={ctx['before']} reset={ctx['trigger']} after={ctx['after']}")
    lines.append("")
    lines.append("6. Direction confidence:")
    confirmed = sum(n for d, n in directions.items() if d != "UNKNOWN")
    unknown = directions.get("UNKNOWN", 0)
    inferred = sum(len(item["responses"]) for vals in analysis["trigger_responses"].values() for item in vals)
    lines.append(f"- confirmed direction count: {confirmed}")
    lines.append(f"- inferred direction count: {inferred}")
    lines.append(f"- unknown direction count: {unknown}")
    lines.append(f"- direction breakdown: {dict(directions)}")
    lines.append("")
    lines.append("7. Comparison with ESP:")
    lines.append("Trigger | Old response | Delay us | Direction confidence | ESP response | Match? | Comment")
    for trig in ["19 03 01 00 1D", "FE", "FC", "1C", "E0"]:
        old = "(none observed)"
        delay = ""
        conf = "unknown"
        responses = [r for item in analysis["trigger_responses"].get(trig, []) for r in item["responses"]]
        if responses:
            common = Counter(r["frame_hex"] for r in responses).most_common(1)[0][0]
            first = next(r for r in responses if r["frame_hex"] == common)
            old = common
            delay = str(first["delay_us"])
            conf = first["direction_confidence"]
        esp = ESP_REFERENCE.get(trig, "")
        match = "yes" if old != "(none observed)" and old in esp else "no/unclear"
        lines.append(f"{trig} | {old} | {delay} | {conf} | {esp} | {match} | timing-based unless direction confirmed")
    lines.append("")
    lines.append("8. Final conclusion:")
    lines.append(f"- likely old-device address/family candidates: {families.most_common(5)}")
    for trig in ["19 03 01 00 1D", "FE", "FC", "1C", "E0"]:
        responses = [r["frame_hex"] for item in analysis["trigger_responses"].get(trig, []) for r in item["responses"]]
        common = Counter(responses).most_common(1)[0][0] if responses else "(none observed)"
        lines.append(f"- old device after {trig}: {common}")
    stable = important["reset_10_10"] == 0 and len(frames) > 0
    lines.append(f"- stable accepted-flow candidate: {'yes/unclear' if stable else 'no/unclear'}")
    lines.append("- next ESP replay candidate: use the first confirmed/inferred mismatch above, prioritizing 19 then FE")
    return "\n".join(lines)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("port")
    ap.add_argument("--duration", type=float, default=300.0)
    ap.add_argument("--baud", type=int, default=BAUD_DEFAULT)
    ap.add_argument("--gap-us", type=int, default=GAP_US_DEFAULT)
    ap.add_argument("--input-jsonl", help="Reprocess raw_line entries from an existing capture JSONL")
    args = ap.parse_args()

    OUT_DIR.mkdir(exist_ok=True)
    stamp = now_stamp()
    jsonl_path = OUT_DIR / f"arduino_old_device_capture_{stamp}.jsonl"
    txt_path = OUT_DIR / f"arduino_old_device_capture_{stamp}.txt"

    raw_lines: list[str] = []
    records: list[ByteRecord] = []
    if args.input_jsonl:
        log(f"reprocessing raw lines from {args.input_jsonl}")
        with Path(args.input_jsonl).open("r", encoding="utf-8") as f:
            for raw in f:
                try:
                    obj = json.loads(raw)
                except json.JSONDecodeError:
                    continue
                if obj.get("kind") != "raw_line":
                    continue
                line = str(obj.get("line", ""))
                raw_lines.append(line)
                rec = parse_line(line, len(records), time.time())
                if rec:
                    records.append(rec)
    else:
        log(f"opening Arduino serial port={args.port} baud={args.baud}")
        ser = serial.Serial(args.port, args.baud, timeout=0.1)
        start = time.monotonic()
        next_status = start + 30
        try:
            while time.monotonic() - start < args.duration:
                raw = ser.readline()
                if not raw:
                    if time.monotonic() >= next_status:
                        log(f"{time.monotonic() - start:.0f}s elapsed, raw_lines={len(raw_lines)} bytes={len(records)}")
                        next_status = time.monotonic() + 30
                    continue
                host_ts = time.time()
                line = raw.decode("utf-8", "replace").strip()
                raw_lines.append(line)
                rec = parse_line(line, len(records), host_ts)
                if rec:
                    records.append(rec)
                if time.monotonic() >= next_status:
                    log(f"{time.monotonic() - start:.0f}s elapsed, raw_lines={len(raw_lines)} bytes={len(records)}")
                    next_status = time.monotonic() + 30
        finally:
            ser.close()

    frames = group_frames(records, args.gap_us)
    analysis = {
        "trigger_responses": {t: trigger_responses(frames, t) for t in ["19 03 01 00 1D", "FE", "FC", "1C", "E0", "10 10"]},
        "patterns": {
            t: window_patterns(frames, t).most_common(10)
            for t in ["19 03 01 00 1D", "FE", "FC", "1C", "E0"]
        },
        "contexts_19": contexts(frames, "19 03 01 00 1D", 10, 20),
        "contexts_FE": contexts(frames, "FE", 5, 10),
        "contexts_1C": contexts(frames, "1C", 5, 10),
        "reset_contexts": contexts(frames, "10 10", 10, 5),
    }
    write_jsonl(jsonl_path, raw_lines, records, frames, analysis)
    report = make_report(args.port, args.duration, args.baud, args.gap_us, raw_lines, records, frames, analysis)
    txt_path.write_text(report + "\n", encoding="utf-8")
    print("\n" + report)
    log(f"saved jsonl={jsonl_path}")
    log(f"saved txt={txt_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
