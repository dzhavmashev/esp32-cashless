#!/usr/bin/env python3
"""Five-minute MDB diagnostic capture tool for ESP32 serial CLI.

Default port is /dev/ttyUSB0. You can change DEFAULT_SERIAL_PORT below or pass
another port as the first CLI argument:

    python3 scripts/mdb_diagnostic_capture.py
    python3 scripts/mdb_diagnostic_capture.py /dev/ttyUSB1
"""

from __future__ import annotations

import sys
import time
from datetime import datetime
from pathlib import Path
import re

import serial


DEFAULT_SERIAL_PORT = "/dev/ttyUSB0"
BAUD_RATE = 115200
SERIAL_TIMEOUT_S = 0.20
TEST_DURATION_MIN = 5
RUN_DURATION_S = TEST_DURATION_MIN * 60
POLL_INTERVAL_S = 10
FINAL_DRAIN_S = 1.0

KEYWORD_RE = re.compile(r"(RAW|EDGE|BIT|MDB_RX)", re.IGNORECASE)
SYSTEM_ERROR_RE = re.compile(
    r"(error|unknown command|failed|timeout|exception|mdb_bus_stuck)",
    re.IGNORECASE,
)


def now_stamp() -> str:
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]


def build_log_path() -> Path:
    suffix = datetime.now().strftime("%Y%m%d_%H%M%S")
    return Path.cwd() / f"mdb_diagnostic_log_{suffix}.txt"


def normalize_line(text: str) -> str:
    return " ".join(text.strip().split())


def should_log_line(line: str) -> tuple[bool, bool]:
    """Return (should_log, is_system_error)."""
    is_keyword_line = KEYWORD_RE.search(line) is not None
    is_system_error = SYSTEM_ERROR_RE.search(line) is not None
    return is_keyword_line or is_system_error, is_system_error


def write_log_line(log_file, prefix: str, text: str) -> None:
    stamped = f"[{now_stamp()}] {prefix} {text}\n"
    log_file.write(stamped)
    log_file.flush()


def send_command(ser: serial.Serial, log_file, command: str) -> None:
    print(f"TX> {command}")
    write_log_line(log_file, "TX", command)
    ser.write((command + "\n").encode("utf-8"))
    ser.flush()


def process_incoming_line(
    log_file,
    line: str,
    last_system_error: str | None,
) -> str | None:
    clean_line = line.strip()
    if not clean_line:
        return last_system_error

    should_log, is_system_error = should_log_line(clean_line)
    if not should_log:
        return last_system_error

    normalized = normalize_line(clean_line)
    if is_system_error and normalized == last_system_error:
        return last_system_error

    print(f"RX> {clean_line}")
    write_log_line(log_file, "RX", clean_line)
    if is_system_error:
        return normalized
    return last_system_error


def read_available_lines(
    ser: serial.Serial,
    log_file,
    last_system_error: str | None,
    max_wait_s: float,
) -> str | None:
    end = time.monotonic() + max_wait_s
    while time.monotonic() < end:
        raw = ser.readline()
        if not raw:
            continue
        text = raw.decode("utf-8", errors="ignore")
        last_system_error = process_incoming_line(log_file, text, last_system_error)

        while ser.in_waiting > 0:
            extra = ser.readline()
            if not extra:
                break
            extra_text = extra.decode("utf-8", errors="ignore")
            last_system_error = process_incoming_line(
                log_file, extra_text, last_system_error
            )

    return last_system_error


def run_capture(port: str) -> Path:
    log_path = build_log_path()
    print(f"Opening {port} at {BAUD_RATE} baud")
    print(f"Logging to {log_path}")

    with serial.Serial(port, BAUD_RATE, timeout=SERIAL_TIMEOUT_S) as ser:
        with log_path.open("w", encoding="utf-8", buffering=1) as log_file:
            write_log_line(log_file, "INFO", f"Port opened: {port} @ {BAUD_RATE}")
            write_log_line(
                log_file,
                "INFO",
                f"Capture duration: {RUN_DURATION_S}s, poll interval: {POLL_INTERVAL_S}s",
            )

            ser.reset_input_buffer()
            ser.reset_output_buffer()

            last_system_error: str | None = None

            send_command(ser, log_file, "mdb_rx_invert_on")
            time.sleep(0.10)
            send_command(ser, log_file, "mdb_irq_snapshot")

            capture_started_at = time.monotonic()
            deadline = capture_started_at + RUN_DURATION_S
            next_poll_at = capture_started_at + POLL_INTERVAL_S

            while True:
                now = time.monotonic()
                if now >= deadline:
                    break

                if now >= next_poll_at:
                    send_command(ser, log_file, "mdb_irq_snapshot")
                    time.sleep(0.05)
                    send_command(ser, log_file, "phy_decoder_status")
                    next_poll_at += POLL_INTERVAL_S

                wait_budget = min(0.50, max(0.01, next_poll_at - now, deadline - now))
                last_system_error = read_available_lines(
                    ser,
                    log_file,
                    last_system_error,
                    wait_budget,
                )

            send_command(ser, log_file, "mdb_irq_snapshot")
            last_system_error = read_available_lines(
                ser,
                log_file,
                last_system_error,
                FINAL_DRAIN_S,
            )
            write_log_line(log_file, "INFO", "Capture finished cleanly")

    print("Capture complete")
    return log_path


def main() -> int:
    port = sys.argv[1] if len(sys.argv) > 1 else DEFAULT_SERIAL_PORT
    try:
        log_path = run_capture(port)
    except serial.SerialException as exc:
        print(f"Serial error: {exc}", file=sys.stderr)
        return 1
    except KeyboardInterrupt:
        print("Capture interrupted by user", file=sys.stderr)
        return 130

    print(f"Saved diagnostic log: {log_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
