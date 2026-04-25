#!/usr/bin/env python3
"""USB CLI hardware tests for the current ESP32 MDB PHY.

The script talks to the firmware over the serial CLI, runs a small set of
physical-layer checks, prints raw device logs in gray for debugging, and emits
PASS / FAIL / ERROR verdicts per test.

Current hardware/firmware assumptions:
  - this board revision keeps ``rx_invert`` disabled;
  - debug TX telemetry is emitted as ``mdb_debug_tx_raw``;
  - ``mdb_raw_send`` uses normal slave-data framing, so every byte has the
    ninth bit forced to 0.
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

PREFERRED_PORT_PREFIXES = ("/dev/ttyUSB", "/dev/ttyACM", "/dev/cu.usb")


@dataclass
class TestResult:
    name: str
    verdict: str
    details: str


@dataclass
class TxRawRecord:
    event: str
    tx_kind: str
    byte_index: int
    hex_value: str
    ninth_bit_text: str
    bit_period_us: int
    character_tx_us: int


@dataclass
class TxTimingRecord:
    tx_kind: str
    byte_index: int
    bit_period_us: int
    character_tx_us: int


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


def sort_ports(ports: list[serial.tools.list_ports.ListPortInfo]) -> list[serial.tools.list_ports.ListPortInfo]:
    def port_score(port: serial.tools.list_ports.ListPortInfo) -> tuple[int, str]:
        device = port.device or ""
        preferred_rank = len(PREFERRED_PORT_PREFIXES)
        for index, prefix in enumerate(PREFERRED_PORT_PREFIXES):
            if device.startswith(prefix):
                preferred_rank = index
                break
        return preferred_rank, device

    return sorted(ports, key=port_score)


def choose_port(cli_port: str | None = None) -> str:
    if cli_port:
        return cli_port

    ports = sort_ports(list(serial.tools.list_ports.comports()))
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


def matching_event_lines(text: str, event_names: Iterable[str]) -> list[str]:
    wanted = set(event_names)
    lines: list[str] = []
    for line in text.splitlines():
        event_match = re.search(r'"event":"([^"]+)"', line)
        if event_match is None:
            continue
        if event_match.group(1) in wanted:
            lines.append(line)
    return lines


def extract_tx_raw_records(text: str, tx_kind: str | None = None) -> list[TxRawRecord]:
    pattern = re.compile(
        r'"event":"(mdb_debug_tx_raw|phy_tx_raw|mdb_bus_tx_raw)".*?'
        r'"tx_kind":"([^"]+)".*?"byte_index":\s*(\d+).*?'
        r'"hex":"([0-9A-F]{2})".*?"ninth_bit":\s*(true|false|0|1).*?'
        r'"bit_period_us":\s*(\d+).*?"character_tx_us":\s*(\d+)'
    )
    records: list[TxRawRecord] = []
    for line in matching_event_lines(
        text, ("mdb_debug_tx_raw", "phy_tx_raw", "mdb_bus_tx_raw")
    ):
        match = pattern.search(line)
        if match is None:
            continue
        record = TxRawRecord(
            event=match.group(1),
            tx_kind=match.group(2),
            byte_index=int(match.group(3)),
            hex_value=match.group(4).upper(),
            ninth_bit_text=match.group(5).lower(),
            bit_period_us=int(match.group(6)),
            character_tx_us=int(match.group(7)),
        )
        if tx_kind is None or record.tx_kind == tx_kind:
            records.append(record)
    return records


def extract_tx_timing_records(text: str, tx_kind: str | None = None) -> list[TxTimingRecord]:
    pattern = re.compile(
        r'"event":"tx_bit_timing".*?"tx_kind":"([^"]+)".*?'
        r'"byte_index":\s*(\d+).*?"bit_period_us":\s*(\d+).*?'
        r'"character_tx_us":\s*(\d+)'
    )
    records: list[TxTimingRecord] = []
    for line in matching_event_lines(text, ("tx_bit_timing",)):
        match = pattern.search(line)
        if match is None:
            continue
        record = TxTimingRecord(
            tx_kind=match.group(1),
            byte_index=int(match.group(2)),
            bit_period_us=int(match.group(3)),
            character_tx_us=int(match.group(4)),
        )
        if tx_kind is None or record.tx_kind == tx_kind:
            records.append(record)
    return records


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
        ["mdb_monitor_stop", "mdb_rx_invert_off", "mdb_irq_snapshot"], 1.0
    )
    match = first_match(
        r'"event":"irq_snapshot".*?"rx_invert":\s*(true|false).*?'
        r'"current_rx_level":\s*(\d+)',
        text,
    )
    if match is None:
        return TestResult(
            "Polarity Check",
            "ERROR",
            "No irq_snapshot with rx_invert/current_rx_level found",
        )
    rx_invert = match.group(1) == "true"
    level = int(match.group(2))
    if rx_invert:
        return TestResult(
            "Polarity Check",
            "FAIL",
            "rx_invert stayed enabled; this board revision expects raw idle-high RX with invert off",
        )
    if level == 1:
        return TestResult(
            "Polarity Check",
            "PASS",
            "Idle RX level is 1 on raw GPIO14 with rx_invert off; board polarity matches current PHY config",
        )
    return TestResult(
        "Polarity Check",
        "FAIL",
        f"Idle RX level is {level}; expected raw idle-high (1) with rx_invert off on this board revision",
    )


def test_echo(client: Esp32CliClient) -> TestResult:
    client.drain(0.5)
    text = client.command_and_collect(
        ["mdb_monitor_start", "mdb_sniff_clear", "mdb_raw_send 00 00"], 1.0
    )
    tx_records = extract_tx_raw_records(text, tx_kind="raw_send")
    tx_seen = any(record.hex_value == "00" for record in tx_records)
    echo_seen = (
        first_match(r'"event":"phy_soft_byte".*?"byte_hex":"00"', text) is not None
        or first_match(r'"event":"phy_soft_byte".*?"byte_hex":"FF"', text) is not None
    )
    if not tx_seen:
        return TestResult(
            "Echo Check",
            "ERROR",
            "No debug TX telemetry for mdb_raw_send 00 00 was captured",
        )
    if echo_seen:
        return TestResult(
            "Echo Check",
            "FAIL",
            "RX produced phy_soft_byte 00/FF immediately after TX; possible parasitic echo",
        )
    return TestResult(
        "Echo Check",
        "PASS",
        "mdb_debug_tx_raw seen for 00 00 and no immediate phy_soft_byte echo was detected",
    )


def test_timings(client: Esp32CliClient) -> TestResult:
    client.drain(0.5)
    text = client.command_and_collect(["mdb_sniff_clear", "mdb_raw_send 55 55"], 1.0)
    timing_records = extract_tx_timing_records(text, tx_kind="raw_send")
    if not timing_records:
        tx_records = extract_tx_raw_records(text, tx_kind="raw_send")
        if tx_records:
            timing_records = [
                TxTimingRecord(
                    tx_kind=record.tx_kind,
                    byte_index=record.byte_index,
                    bit_period_us=record.bit_period_us,
                    character_tx_us=record.character_tx_us,
                )
                for record in tx_records
            ]
    if not timing_records:
        return TestResult(
            "Timing Check",
            "ERROR",
            "No tx_bit_timing or TX debug records found for mdb_raw_send 55 55",
        )

    good = [
        record
        for record in timing_records
        if abs(record.bit_period_us - 104) <= 5
        and abs(record.character_tx_us - 1248) <= 60
    ]
    if len(good) == len(timing_records):
        timing_summary = ", ".join(
            f"byte{record.byte_index}=bit{record.bit_period_us}/char{record.character_tx_us}"
            for record in timing_records
        )
        return TestResult(
            "Timing Check",
            "PASS",
            f"TX timing telemetry matches 9600 baud: {timing_summary}",
        )
    timing_summary = ", ".join(
        f"byte{record.byte_index}=bit{record.bit_period_us}/char{record.character_tx_us}"
        for record in timing_records
    )
    return TestResult(
        "Timing Check",
        "FAIL",
        f"TX timing telemetry is out of range for 9600 baud: {timing_summary}",
    )


def test_ninth_bit(client: Esp32CliClient) -> TestResult:
    client.drain(0.5)
    text = client.command_and_collect(["mdb_sniff_clear", "mdb_raw_send 00 00"], 1.0)
    records = extract_tx_raw_records(text, tx_kind="raw_send")
    if not records:
        return TestResult(
            "Ninth Bit Check",
            "ERROR",
            "No debug TX records found for mdb_raw_send 00 00",
        )

    parsed: dict[int, tuple[str, str]] = {}
    for record in records:
        if record.byte_index not in parsed:
            parsed[record.byte_index] = (record.hex_value, record.ninth_bit_text)

    if 0 not in parsed or 1 not in parsed:
        return TestResult(
            "Ninth Bit Check",
            "ERROR",
            f"Need byte_index 0 and 1, got {sorted(parsed.keys())}",
        )

    first_hex, first_ninth = parsed[0]
    second_hex, second_ninth = parsed[1]
    first_ok = first_hex == "00" and first_ninth in {"false", "0"}
    second_ok = second_hex == "00" and second_ninth in {"false", "0"}
    if first_ok and second_ok:
        return TestResult(
            "Ninth Bit Check",
            "PASS",
            "mdb_raw_send keeps ninth_bit=0 on both bytes, matching current slave-data framing",
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
    port = choose_port(sys.argv[1] if len(sys.argv) > 1 else None)
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
