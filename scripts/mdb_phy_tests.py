#!/usr/bin/env python3
"""USB CLI hardware tests for MDB PHY on ESP32.

The script talks to the firmware over the serial CLI, runs a small set of
physical-layer checks, prints raw device logs in gray for debugging, and emits
PASS / FAIL / ERROR verdicts per test.
"""

from __future__ import annotations

import re
import sys
import time
from dataclasses import dataclass
from typing import Iterable

import serial
import serial.tools.list_ports


BAUD_RATE = 115200
SERIAL_TIMEOUT_S = 0.10
COMMAND_SETTLE_S = 0.15

GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
CYAN = "\033[96m"
GRAY = "\033[90m"
BOLD = "\033[1m"
RESET = "\033[0m"


@dataclass
class TestResult:
    name: str
    verdict: str
    details: str


class Esp32CliClient:
    def __init__(self, port: str, baud_rate: int = BAUD_RATE) -> None:
        self.port = port
        self.serial = serial.Serial(port, baud_rate, timeout=SERIAL_TIMEOUT_S)

    def close(self) -> None:
        if self.serial.is_open:
            self.serial.close()

    def drain(self, seconds: float = 0.75) -> str:
        end = time.time() + seconds
        chunks: list[str] = []
        while time.time() < end:
            chunk = self.serial.read(4096)
            if not chunk:
                continue
            text = chunk.decode("utf-8", errors="ignore")
            if text:
                self._print_raw(text)
                chunks.append(text)
        return "".join(chunks)

    def send(self, command: str) -> None:
        sys.stdout.write(f"{CYAN}>> {command}{RESET}\n")
        sys.stdout.flush()
        self.serial.write((command + "\n").encode("utf-8"))
        self.serial.flush()
        time.sleep(COMMAND_SETTLE_S)

    def collect(self, seconds: float) -> str:
        end = time.time() + seconds
        chunks: list[str] = []
        while time.time() < end:
            chunk = self.serial.read(4096)
            if not chunk:
                continue
            text = chunk.decode("utf-8", errors="ignore")
            if text:
                self._print_raw(text)
                chunks.append(text)
        return "".join(chunks)

    def command_and_collect(self, commands: Iterable[str], seconds: float) -> str:
        buffer = ""
        for command in commands:
            self.send(command)
            buffer += self.collect(0.35)
        buffer += self.collect(seconds)
        return buffer

    @staticmethod
    def _print_raw(text: str) -> None:
        sys.stdout.write(f"{GRAY}{text}{RESET}")
        if not text.endswith("\n"):
            sys.stdout.write("\n")
        sys.stdout.flush()


def choose_port() -> str:
    ports = list(serial.tools.list_ports.comports())
    if ports:
        print(f"{BOLD}Available serial ports:{RESET}")
        for index, port in enumerate(ports, start=1):
            description = port.description or "Unknown device"
            print(f"  {index}. {port.device}  {description}")
        default_port = ports[0].device
    else:
        print(f"{YELLOW}No serial ports auto-detected.{RESET}")
        default_port = ""

    prompt = "Enter serial port"
    if default_port:
        prompt += f" [{default_port}]"
    prompt += ": "

    selected = input(prompt).strip()
    return selected or default_port


def verdict_line(result: TestResult) -> None:
    color = GREEN if result.verdict == "PASS" else RED if result.verdict == "FAIL" else YELLOW
    print(f"{color}{result.name}: {result.verdict}{RESET}  {result.details}")


def first_match(pattern: str, text: str) -> re.Match[str] | None:
    return re.search(pattern, text, re.S)


def extract_irq_snapshot(text: str) -> tuple[int, int, list[int]] | None:
    snapshot = first_match(
        r'"event":"irq_snapshot".*?"current_rx_level":\s*(\d+).*?'
        r'"raw_gpio_interrupt_count":\s*(\d+).*?"recent_interrupts":\[(.*?)\]',
        text,
    )
    if snapshot is None:
        return None
    current_rx_level = int(snapshot.group(1))
    interrupt_count = int(snapshot.group(2))
    recent_blob = snapshot.group(3)
    timestamps = [int(value) for value in re.findall(r'"ts_us":\s*(\d+)', recent_blob)]
    deltas = [b - a for a, b in zip(timestamps, timestamps[1:]) if b >= a]
    return current_rx_level, interrupt_count, deltas


def format_ranges(values: list[int]) -> str:
    if not values:
        return "[]"
    return "[" + ", ".join(str(v) for v in values) + "]"


def test_polarity(client: Esp32CliClient) -> TestResult:
    client.drain(0.5)
    text = client.command_and_collect(
        ["mdb_monitor_stop", "mdb_rx_invert_on", "mdb_irq_snapshot"], 1.0
    )
    match = first_match(r'"event":"irq_snapshot".*?"current_rx_level":\s*(\d+)', text)
    if match is None:
        return TestResult("Polarity Check", "ERROR", "No irq_snapshot/current_rx_level found")
    level = int(match.group(1))
    if level == 0:
        return TestResult(
            "Polarity Check",
            "PASS",
            "Idle RX level is 0 on GPIO14; inverted 6N137 polarity looks correct",
        )
    return TestResult(
        "Polarity Check",
        "FAIL",
        f"Idle RX level is {level}; expected 0 when 6N137 pulls idle-low",
    )


def test_echo(client: Esp32CliClient) -> TestResult:
    client.drain(0.5)
    text = client.command_and_collect(
        ["mdb_monitor_start", "mdb_sniff_clear", "mdb_raw_send 00 00"], 1.0
    )
    tx_seen = first_match(r'"event":"phy_tx_raw".*?"hex":"00"', text) is not None
    echo_seen = (
        first_match(r'"event":"phy_soft_byte".*?"byte_hex":"00"', text) is not None
        or first_match(r'"event":"phy_soft_byte".*?"byte_hex":"FF"', text) is not None
    )
    if not tx_seen:
        return TestResult("Echo Check", "ERROR", "No phy_tx_raw for 00 00 captured")
    if echo_seen:
        return TestResult(
            "Echo Check",
            "FAIL",
            "RX produced phy_soft_byte 00/FF immediately after TX; possible parasitic echo",
        )
    return TestResult(
        "Echo Check",
        "PASS",
        "phy_tx_raw seen for 00 00 and no immediate phy_soft_byte echo was detected",
    )


def test_timings(client: Esp32CliClient) -> TestResult:
    client.drain(0.5)
    text = client.command_and_collect(
        ["mdb_sniff_clear", "mdb_raw_send 55 55", "mdb_irq_snapshot"], 1.0
    )
    snapshot = extract_irq_snapshot(text)
    if snapshot is None:
        return TestResult("Timing Check", "ERROR", "No irq_snapshot with timing data found")
    _, interrupt_count, deltas = snapshot
    if len(deltas) == 0:
        delta_match = first_match(r'"event":"irq_snapshot".*?"delta_us":\s*(\d+)', text)
        if delta_match is not None:
            deltas = [int(delta_match.group(1))]
    if len(deltas) == 0:
        return TestResult(
            "Timing Check",
            "ERROR",
            f"No edge deltas found; raw_gpio_interrupt_count={interrupt_count}",
        )

    targets = (104, 208, 312)
    tolerance = 15
    good = [
        delta
        for delta in deltas
        if any(abs(delta - target) <= tolerance for target in targets)
    ]
    if len(good) * 2 >= len(deltas):
        return TestResult(
            "Timing Check",
            "PASS",
            f"Edge deltas look sane for 9600 baud: {format_ranges(deltas)}",
        )
    return TestResult(
        "Timing Check",
        "FAIL",
        f"Edge deltas are chaotic or out of range: {format_ranges(deltas)}",
    )


def test_ninth_bit(client: Esp32CliClient) -> TestResult:
    client.drain(0.5)
    text = client.command_and_collect(["mdb_sniff_clear", "mdb_raw_send 00 00"], 1.0)
    matches = re.findall(
        r'"event":"phy_tx_raw".*?"byte_index":\s*(\d+).*?"hex":"([0-9A-F]{2})".*?'
        r'"ninth_bit":\s*(true|false|0|1)',
        text,
        re.S,
    )
    if not matches:
        return TestResult("Ninth Bit Check", "ERROR", "No phy_tx_raw entries found")

    parsed: dict[int, tuple[str, str]] = {}
    for index_text, hex_value, ninth_text in matches:
        index = int(index_text)
        if index not in parsed:
          parsed[index] = (hex_value.upper(), ninth_text.lower())

    if 0 not in parsed or 1 not in parsed:
        return TestResult(
            "Ninth Bit Check",
            "ERROR",
            f"Need byte_index 0 and 1, got {sorted(parsed.keys())}",
        )

    first_hex, first_ninth = parsed[0]
    second_hex, second_ninth = parsed[1]
    first_ok = first_hex == "00" and first_ninth in {"false", "0"}
    second_ok = second_hex == "00" and second_ninth in {"true", "1"}
    if first_ok and second_ok:
        return TestResult(
            "Ninth Bit Check",
            "PASS",
            "First TX byte has ninth_bit=0, second TX byte has ninth_bit=1",
        )
    return TestResult(
        "Ninth Bit Check",
        "FAIL",
        f"Unexpected ninth_bit pattern: byte0={first_hex}/{first_ninth}, "
        f"byte1={second_hex}/{second_ninth}",
    )


def run_tests(client: Esp32CliClient) -> list[TestResult]:
    return [
        test_polarity(client),
        test_echo(client),
        test_timings(client),
        test_ninth_bit(client),
    ]


def main() -> int:
    port = choose_port()
    if not port:
        print(f"{RED}No serial port selected.{RESET}")
        return 1

    try:
        client = Esp32CliClient(port)
    except serial.SerialException as exc:
        print(f"{RED}Failed to open {port}: {exc}{RESET}")
        return 1

    print(f"{BOLD}Connected to {port} at {BAUD_RATE} baud{RESET}")

    try:
        client.drain(1.0)
        results = run_tests(client)
    except serial.SerialException as exc:
        print(f"{RED}Serial error during tests: {exc}{RESET}")
        client.close()
        return 1
    finally:
        client.close()

    print(f"\n{BOLD}Summary{RESET}")
    for result in results:
        verdict_line(result)

    verdicts = {result.verdict for result in results}
    if "FAIL" in verdicts:
        return 2
    if "ERROR" in verdicts:
        return 3
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
