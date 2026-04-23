#!/usr/bin/env python3
"""Final MDB post-hardware-improvement checker.

The script talks to the ESP32 USB CLI over Serial, captures diagnostic snapshots
for 300 seconds, keeps RX inversion fixed to OFF, and writes strict-decoder
diagnostic snapshots to a text log when either IRQ activity grows or the decoder
state meaningfully changes.

Usage:
    python3 scripts/mdb_final_check.py
    python3 scripts/mdb_final_check.py /dev/ttyUSB1
"""

from __future__ import annotations

import argparse
import re
import sys
import time
from dataclasses import dataclass, field
from datetime import datetime
from pathlib import Path

import serial


DEFAULT_SERIAL_PORT = "/dev/ttyUSB0"
BAUD_RATE = 115200
SERIAL_TIMEOUT_S = 0.20
TEST_DURATION_S = 60
POLL_INTERVAL_S = 15
POLL_CAPTURE_WINDOW_S = 2.5
INITIAL_CAPTURE_WINDOW_S = 2.0
FINAL_DRAIN_S = 1.0
RX_INVERT_COMMAND = "mdb_rx_invert_off"

RAW_IRQ_RE = re.compile(r'"raw_gpio_interrupt_count":\s*(\d+)')
EVENT_RE = re.compile(r'"event":"([^"]+)"')
BAD_REASON_RE = re.compile(r'"last_bad_reason":"([^"]+)"')
GOOD_FRAME_VALID_RE = re.compile(r'"last_good_frame":\{"valid":(true|false)')
DEBUG_TRACE_VALID_RE = re.compile(r'"debug_frame_trace":\{"valid":(true|false)')


@dataclass
class PollCapture:
    index: int
    started_monotonic: float
    lines: list[str] = field(default_factory=list)
    irq_count: int | None = None
    irq_line: str | None = None
    bad_reason: str | None = None
    good_frame_valid: bool = False
    debug_trace_valid: bool = False
    status_line: str | None = None


def now_stamp() -> str:
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]


def build_log_path() -> Path:
    suffix = datetime.now().strftime("%Y%m%d_%H%M%S")
    return Path.cwd() / f"mdb_final_check_{suffix}.txt"


def write_line(log_file, text: str) -> None:
    log_file.write(text.rstrip("\n") + "\n")
    log_file.flush()


def write_log_entry(log_file, prefix: str, text: str) -> None:
    write_line(log_file, f"[{now_stamp()}] {prefix} {text}")


def send_command(ser: serial.Serial, log_file, command: str) -> None:
    print(f"TX> {command}")
    write_log_entry(log_file, "TX", command)
    ser.write((command + "\n").encode("utf-8"))
    ser.flush()


def normalize_line(text: str) -> str:
    return " ".join(text.strip().split())


def is_relevant_line(line: str) -> bool:
    event = event_name(line)
    return event in {"irq_snapshot", "phy_decoder_status"}


def maybe_extract_irq_count(line: str) -> int | None:
    match = RAW_IRQ_RE.search(line)
    if match is None:
        return None
    return int(match.group(1))


def event_name(line: str) -> str | None:
    match = EVENT_RE.search(line)
    if match is None:
        return None
    return match.group(1)


def store_relevant_line(capture: PollCapture | None, line: str) -> None:
    if capture is None or not is_relevant_line(line):
        return

    clean_line = normalize_line(line)
    if clean_line in capture.lines:
        return

    capture.lines.append(clean_line)

    if event_name(clean_line) == "irq_snapshot":
        irq_count = maybe_extract_irq_count(clean_line)
        if irq_count is not None:
            capture.irq_count = irq_count
            capture.irq_line = clean_line
        return

    if event_name(clean_line) == "phy_decoder_status":
        capture.status_line = clean_line
        bad_reason_match = BAD_REASON_RE.search(clean_line)
        if bad_reason_match is not None:
            capture.bad_reason = bad_reason_match.group(1)
        good_frame_match = GOOD_FRAME_VALID_RE.search(clean_line)
        if good_frame_match is not None:
            capture.good_frame_valid = good_frame_match.group(1) == "true"
        debug_trace_match = DEBUG_TRACE_VALID_RE.search(clean_line)
        if debug_trace_match is not None:
            capture.debug_trace_valid = debug_trace_match.group(1) == "true"


@dataclass
class CaptureState:
    irq_count: int | None = None
    bad_reason: str | None = None
    good_frame_seen: bool = False
    debug_trace_seen: bool = False


def read_serial_lines(
    ser: serial.Serial,
    capture: PollCapture | None,
    duration_s: float,
) -> None:
    end = time.monotonic() + duration_s
    while time.monotonic() < end:
        raw = ser.readline()
        if not raw:
            continue
        text = raw.decode("utf-8", errors="ignore").strip()
        if not text:
            continue
        print(f"RX> {text}")
        store_relevant_line(capture, text)


def finalize_capture(
    log_file,
    capture: PollCapture,
    previous_state: CaptureState,
) -> CaptureState:
    if capture.irq_count is None:
        write_log_entry(
            log_file,
            "WARN",
            f"poll_{capture.index:02d}: no irq_snapshot/raw_gpio_interrupt_count captured",
        )
        return previous_state

    summary = (
        f"irq={capture.irq_count}, bad_reason={capture.bad_reason or 'unknown'}, "
        f"good_frame_valid={capture.good_frame_valid}, "
        f"debug_trace_valid={capture.debug_trace_valid}"
    )

    if previous_state.irq_count is None:
        write_log_entry(
            log_file,
            "BASELINE",
            f"poll_{capture.index:02d}: {summary}",
        )
        for line in capture.lines:
            write_line(log_file, line)
        return CaptureState(
            irq_count=capture.irq_count,
            bad_reason=capture.bad_reason,
            good_frame_seen=capture.good_frame_valid,
            debug_trace_seen=capture.debug_trace_valid,
        )

    irq_grew = (
        previous_state.irq_count is not None
        and capture.irq_count > previous_state.irq_count
    )
    bad_reason_changed = capture.bad_reason != previous_state.bad_reason
    new_good_frame = capture.good_frame_valid and not previous_state.good_frame_seen
    new_debug_trace = (
        capture.debug_trace_valid and not previous_state.debug_trace_seen
    )

    if not (irq_grew or bad_reason_changed or new_good_frame or new_debug_trace):
        print(
            f"SKIP> poll {capture.index:02d}: no meaningful strict-decoder change "
            f"(irq={capture.irq_count}, bad_reason={capture.bad_reason})"
        )
        return CaptureState(
            irq_count=capture.irq_count,
            bad_reason=capture.bad_reason,
            good_frame_seen=previous_state.good_frame_seen or capture.good_frame_valid,
            debug_trace_seen=previous_state.debug_trace_seen or capture.debug_trace_valid,
        )

    delta = (
        capture.irq_count - previous_state.irq_count
        if previous_state.irq_count is not None
        else 0
    )
    write_log_entry(
        log_file,
        "POLL",
        f"poll_{capture.index:02d}: {summary}, delta={delta}",
    )
    for line in capture.lines:
        write_line(log_file, line)
    return CaptureState(
        irq_count=capture.irq_count,
        bad_reason=capture.bad_reason,
        good_frame_seen=previous_state.good_frame_seen or capture.good_frame_valid,
        debug_trace_seen=previous_state.debug_trace_seen or capture.debug_trace_valid,
    )


def run_capture(port: str) -> Path:
    log_path = build_log_path()
    print(f"Opening {port} at {BAUD_RATE} baud")
    print(f"Writing final check log to {log_path}")

    with serial.Serial(port, BAUD_RATE, timeout=SERIAL_TIMEOUT_S) as ser:
        with log_path.open("w", encoding="utf-8", buffering=1) as log_file:
            write_log_entry(log_file, "INFO", f"Port opened: {port} @ {BAUD_RATE}")
            write_log_entry(
                log_file,
                "INFO",
                f"Duration={TEST_DURATION_S}s, poll_interval={POLL_INTERVAL_S}s, "
                f"capture_window={POLL_CAPTURE_WINDOW_S}s, rx_invert=off",
            )

            ser.reset_input_buffer()
            ser.reset_output_buffer()

            send_command(ser, log_file, RX_INVERT_COMMAND)
            time.sleep(0.10)
            baseline_capture = PollCapture(index=0, started_monotonic=time.monotonic())
            send_command(ser, log_file, "mdb_irq_snapshot")
            time.sleep(0.05)
            send_command(ser, log_file, "phy_decoder_status")
            read_serial_lines(ser, baseline_capture, INITIAL_CAPTURE_WINDOW_S)
            state = finalize_capture(log_file, baseline_capture, CaptureState())

            started_at = time.monotonic()
            deadline = started_at + TEST_DURATION_S
            next_poll_at = started_at + POLL_INTERVAL_S
            poll_index = 1

            while True:
                now = time.monotonic()
                if now >= deadline:
                    break

                if now < next_poll_at:
                    read_serial_lines(ser, None, min(0.25, next_poll_at - now))
                    continue

                capture = PollCapture(index=poll_index, started_monotonic=time.monotonic())
                send_command(ser, log_file, "mdb_irq_snapshot")
                time.sleep(0.05)
                send_command(ser, log_file, "phy_decoder_status")
                read_serial_lines(ser, capture, POLL_CAPTURE_WINDOW_S)
                state = finalize_capture(log_file, capture, state)

                poll_index += 1
                next_poll_at += POLL_INTERVAL_S

            final_capture = PollCapture(index=poll_index, started_monotonic=time.monotonic())
            send_command(ser, log_file, "mdb_irq_snapshot")
            time.sleep(0.05)
            send_command(ser, log_file, "phy_decoder_status")
            read_serial_lines(ser, final_capture, FINAL_DRAIN_S)
            state = finalize_capture(log_file, final_capture, state)
            write_log_entry(
                log_file,
                "INFO",
                "Capture finished, "
                f"final raw_gpio_interrupt_count={state.irq_count}, "
                f"last_bad_reason={state.bad_reason}, "
                f"good_frame_seen={state.good_frame_seen}, "
                f"debug_trace_seen={state.debug_trace_seen}",
            )

    print("Final MDB check complete")
    return log_path


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Run final strict MDB RX diagnostics with fixed rx_invert=off and "
            "log meaningful decoder changes."
        )
    )
    parser.add_argument(
        "port",
        nargs="?",
        default=DEFAULT_SERIAL_PORT,
        help=f"Serial port to open (default: {DEFAULT_SERIAL_PORT})",
    )
    parser.add_argument(
        "--rx-invert",
        choices=("off",),
        default="off",
        help="Legacy compatibility option. RX inversion is fixed to off.",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    try:
        log_path = run_capture(args.port)
    except serial.SerialException as exc:
        print(f"Serial error: {exc}", file=sys.stderr)
        return 1
    except KeyboardInterrupt:
        print("Final MDB check interrupted by user", file=sys.stderr)
        return 130

    print(f"Saved final check log: {log_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
