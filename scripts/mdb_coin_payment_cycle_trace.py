#!/usr/bin/env python3
"""Run repeated MDB coin-payment attempts directly over the USB serial CLI.

The script talks to the ESP32 over `/dev/ttyUSB*` using the same JSON command
envelopes as the WebSocket/backend path, but without HTTP at all.

For each attempt it:
  1. enables MDB monitor + passive sniff,
  2. clears the MDB session and sniff history,
  3. sends `pay transport=mdb`,
  4. waits for the coin flow to finish or time out,
  5. requests `mdb_sniff_recent`,
  6. writes an exact RX/TX log in bytes and a human-readable explanation.
"""

from __future__ import annotations

import argparse
import json
import threading
import time
import uuid
from dataclasses import asdict, dataclass, field
from datetime import datetime
from pathlib import Path
from typing import Any, Optional

import serial
from serial import SerialException


DEFAULT_PORT = "/dev/ttyUSB0"
DEFAULT_BAUD = 115200
DEFAULT_SERIAL_TIMEOUT_S = 0.20
DEFAULT_AMOUNT_MINOR = 100
DEFAULT_ATTEMPTS = 3
DEFAULT_ATTEMPT_TIMEOUT_S = 75.0
DEFAULT_COMMAND_SETTLE_S = 0.60
DEFAULT_POLL_INTERVAL_S = 0.25
DEFAULT_QUIET_AFTER_TERMINAL_S = 2.0
DEFAULT_SNIFF_RECENT_TIMEOUT_S = 1.5
DEFAULT_FINAL_DRAIN_S = 0.75
DEFAULT_OUT_DIR = Path.cwd()
JSON_BUFFER_LIMIT = 256 * 1024

TERMINAL_EVENT_NAMES = {
    "coin_payment_expired",
    "payment_rejected",
    "coin_credit_rejected_by_vmc",
    "coin_payment_completed",
}

RX_EVENT_NAMES = {
    "rx_frame",
    "rx_frame_accepted",
    "rx_frame_tentative",
    "coin_poll_observed_compat",
    "sniff_command_candidate",
}

TX_EVENT_NAMES = {
    "coin_poll_reply_sent",
    "coin_reply_sent_local",
    "mdb_bus_tx_raw",
    "phy_tx_raw",
    "JUST_RESET_SENT",
    "ACK_SENT",
}

COIN_TYPE_VALUES = {
    0: 1,
    1: 5,
    2: 10,
    3: 50,
    4: 100,
}


def now_iso() -> str:
    return datetime.now().astimezone().isoformat(timespec="milliseconds")


def compact_json(value: Any) -> str:
    return json.dumps(value, ensure_ascii=False, sort_keys=True, separators=(",", ":"))


def ensure_dir(path: Path) -> None:
    path.mkdir(parents=True, exist_ok=True)


def human_amount_minor(amount_minor: int, scale_factor: int = 100) -> str:
    major = amount_minor / float(scale_factor)
    return f"{amount_minor} minor ({major:.2f})"


class StepFailure(RuntimeError):
    pass


class StreamJsonExtractor:
    """Incrementally extract top-level JSON objects from a noisy serial stream."""

    def __init__(self, buffer_limit: int = JSON_BUFFER_LIMIT) -> None:
        self.buffer_limit = buffer_limit
        self.buffer = bytearray()

    def feed(self, chunk: bytes) -> tuple[list[dict[str, Any]], list[str]]:
        if chunk:
            self.buffer.extend(chunk)
        objects: list[dict[str, Any]] = []
        notes: list[str] = []

        while self.buffer:
            start = self.buffer.find(b"{")
            if start < 0:
                self.buffer.clear()
                break
            if start > 0:
                del self.buffer[:start]

            end = self._find_balanced_end(self.buffer)
            if end is None:
                if len(self.buffer) > self.buffer_limit:
                    self.buffer.clear()
                    notes.append("partial_buffer_flush")
                break

            candidate = bytes(self.buffer[: end + 1])
            del self.buffer[: end + 1]
            try:
                parsed = json.loads(candidate.decode("utf-8", errors="replace"))
            except json.JSONDecodeError:
                notes.append("malformed_json")
                continue

            if isinstance(parsed, dict):
                objects.append(parsed)
            else:
                notes.append("non_object_json")

        return objects, notes

    @staticmethod
    def _find_balanced_end(buffer: bytearray) -> int | None:
        depth = 0
        in_string = False
        escape = False
        for index, byte in enumerate(buffer):
            ch = chr(byte)
            if in_string:
                if escape:
                    escape = False
                elif ch == "\\":
                    escape = True
                elif ch == '"':
                    in_string = False
                continue

            if ch == '"':
                in_string = True
            elif ch == "{":
                depth += 1
            elif ch == "}":
                depth -= 1
                if depth == 0:
                    return index
        return None


@dataclass
class UsbEvent:
    seq: int
    at: str
    at_ms: int
    payload: dict[str, Any]

    @property
    def event(self) -> str:
        return str(self.payload.get("event") or "")

    @property
    def details(self) -> dict[str, Any]:
        details = self.payload.get("details", {})
        return details if isinstance(details, dict) else {}


@dataclass
class CommandRecord:
    at: str
    command: str
    payload: dict[str, Any]
    usb_json: str
    note: str


@dataclass
class EventRecord:
    at: str
    event: str
    side: str
    raw_hex: str | None
    human: str
    details: dict[str, Any]


@dataclass
class SniffFrameRecord:
    index: int
    raw_hex: str
    normalized_hex: str
    candidate_address: int | None
    candidate_command: int | None
    hint: str
    details: dict[str, Any]


@dataclass
class AttemptReport:
    attempt_index: int
    transaction_id: str
    started_at: str
    finished_at: str = ""
    outcome: str = "unknown"
    commands: list[CommandRecord] = field(default_factory=list)
    events: list[EventRecord] = field(default_factory=list)
    sniff_frames: list[SniffFrameRecord] = field(default_factory=list)
    sniff_meta: dict[str, Any] = field(default_factory=dict)


class LogWriter:
    def __init__(self, path: Path) -> None:
        self.path = path
        self._fp = path.open("w", encoding="utf-8")

    def close(self) -> None:
        self._fp.close()

    def line(self, text: str = "") -> None:
        print(text)
        self._fp.write(text + "\n")
        self._fp.flush()


class SerialUsbClient:
    def __init__(
        self,
        port: str,
        baud: int,
        serial_timeout: float,
        log: LogWriter,
    ) -> None:
        self.port = port
        self.baud = baud
        self.serial_timeout = serial_timeout
        self.log = log
        self.ser: serial.Serial | None = None
        self._extractor = StreamJsonExtractor()
        self._stop_reader = threading.Event()
        self._reader_thread: threading.Thread | None = None
        self._condition = threading.Condition()
        self._reader_exception: BaseException | None = None
        self._event_seq = 0
        self._events: list[UsbEvent] = []

    def __enter__(self) -> "SerialUsbClient":
        self.ser = serial.Serial(self.port, self.baud, timeout=self.serial_timeout)
        self._reader_thread = threading.Thread(
            target=self._reader_loop,
            name="mdb-coin-cycle-usb-reader",
            daemon=True,
        )
        self._reader_thread.start()
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        try:
            self.drain(DEFAULT_FINAL_DRAIN_S)
        except Exception:
            pass
        self._stop_reader.set()
        if self._reader_thread is not None:
            self._reader_thread.join(timeout=1.0)
        if self.ser is not None:
            try:
                self.ser.close()
            except Exception:
                pass

    def _raise_reader_exception_if_needed(self) -> None:
        if self._reader_exception is not None:
            raise StepFailure(f"serial_reader_failed: {self._reader_exception}") from self._reader_exception

    def _reader_loop(self) -> None:
        try:
            while not self._stop_reader.is_set():
                if self.ser is None:
                    return
                raw = self.ser.read(self.ser.in_waiting or 1)
                if not raw:
                    continue
                objects, _notes = self._extractor.feed(raw)
                if not objects:
                    continue
                with self._condition:
                    for obj in objects:
                        event_name = obj.get("event") if isinstance(obj, dict) else None
                        if not isinstance(event_name, str) or not event_name:
                            continue
                        self._event_seq += 1
                        self._events.append(
                            UsbEvent(
                                seq=self._event_seq,
                                at=now_iso(),
                                at_ms=int(time.time() * 1000),
                                payload=obj,
                            )
                        )
                    self._condition.notify_all()
        except BaseException as exc:
            self._reader_exception = exc
            with self._condition:
                self._condition.notify_all()

    def send_command(self, command: str, payload: Optional[dict[str, Any]] = None) -> str:
        if self.ser is None:
            raise StepFailure("serial_port_not_open")
        envelope = {
            "type": "command",
            "payload": {"command": command, "payload": payload or {}},
        }
        text = compact_json(envelope)
        with self._condition:
            self.ser.write((text + "\n").encode("utf-8"))
            self.ser.flush()
        return text

    def snapshot_seq(self) -> int:
        with self._condition:
            return self._event_seq

    def events_after(self, seq: int) -> list[UsbEvent]:
        with self._condition:
            return [event for event in self._events if event.seq > seq]

    def drain(self, duration_s: float) -> None:
        deadline = time.monotonic() + duration_s
        while time.monotonic() < deadline:
            self._raise_reader_exception_if_needed()
            time.sleep(0.01)

    def clear_transport_backlog(self) -> None:
        if self.ser is None:
            raise StepFailure("serial_port_not_open")
        with self._condition:
            self.ser.reset_input_buffer()
            self._extractor = StreamJsonExtractor()
            self._events.clear()
            self._event_seq = 0
            self._condition.notify_all()


def decode_coin_credit_reply(hex_text: str) -> str:
    cleaned = [part for part in hex_text.strip().upper().split() if part]
    if not cleaned:
        return "empty reply"
    if cleaned == ["00"]:
        return "ACK"
    if cleaned in (["0B"], ["0B", "0B"]):
        return "JUST RESET status"
    if len(cleaned) == 3 and cleaned == ["40", "00", "40"]:
        return "coin credit reply for 1 scaled credit via coin type 0"
    if len(cleaned) >= 3:
        payload = cleaned[:-1]
        if len(payload) % 2 == 0:
            decoded_types: list[str] = []
            total_scaled = 0
            valid = True
            for index in range(0, len(payload), 2):
                try:
                    first = int(payload[index], 16)
                    second = int(payload[index + 1], 16)
                except ValueError:
                    valid = False
                    break
                if (first & 0xF0) != 0x40 or second != 0x00:
                    valid = False
                    break
                coin_type = first & 0x0F
                coin_value = COIN_TYPE_VALUES.get(coin_type, 0)
                total_scaled += coin_value
                decoded_types.append(f"type{coin_type}={coin_value}")
            if valid and decoded_types:
                return "coin credit reply: " + ", ".join(decoded_types) + f"; total_scaled={total_scaled}"
    return "unclassified MDB reply"


def explain_raw_hex(raw_hex: str | None) -> str:
    if not raw_hex:
        return ""
    normalized = " ".join(raw_hex.upper().split())
    lookup = {
        "FE": "compat coin poll from VMC",
        "FC": "foreign tail / reader-control-like byte after compat poll",
        "7C": "foreign tail variant after compat poll",
        "1C": "foreign control byte candidate",
        "00": "ACK byte",
        "0B": "JUST RESET status byte",
        "40 00 40": "coin credit reply for one scaled credit",
    }
    if normalized in lookup:
        return lookup[normalized]
    reply_hint = decode_coin_credit_reply(normalized)
    if reply_hint != "unclassified MDB reply":
        return reply_hint
    return "raw MDB frame"


def event_side(event_name: str) -> str:
    if event_name in RX_EVENT_NAMES:
        return "RX"
    if event_name in TX_EVENT_NAMES:
        return "TX"
    if event_name == "command_received":
        return "DEVICE"
    return "EVT"


def extract_event_raw_hex(event_name: str, details: dict[str, Any]) -> str | None:
    if event_name == "rx_frame":
        value = details.get("hex") or details.get("frame_hex")
        return str(value).upper() if value else None
    if event_name in {"rx_frame_accepted", "rx_frame_tentative"}:
        value = details.get("frame_hex") or details.get("data_hex")
        return str(value).upper() if value else None
    if event_name in {"coin_poll_reply_sent", "coin_reply_sent_local"}:
        value = details.get("reply_hex")
        return str(value).upper() if value else None
    if event_name in {"mdb_bus_tx_raw", "phy_tx_raw"}:
        value = details.get("hex")
        return str(value).upper() if value else None
    return None


def describe_event(event_name: str, details: dict[str, Any]) -> str:
    if event_name == "payment_received":
        return (
            "Устройство приняло команду pay: "
            f"amount={human_amount_minor(int(details.get('amount_minor', 0)))}, "
            f"txid={details.get('transaction_id', '')}"
        )
    if event_name == "coin_payment_queued":
        return (
            "Платеж поставлен в очередь coin-emulator: "
            f"amount={human_amount_minor(int(details.get('amount_minor', 0)))}, "
            f"scaled={details.get('scaled_amount')}, "
            f"txid={details.get('transaction_id', '')}"
        )
    if event_name == "coin_poll_observed_compat":
        return (
            "Наблюден compat poll от VMC: "
            f"fast_path={details.get('fast_path')}, "
            f"pending_before={details.get('pending_scaled_before_reply')}, "
            f"remaining_after={details.get('remaining_scaled_after_reply')}"
        )
    if event_name == "coin_poll_reply_sent":
        reply_hex = str(details.get("reply_hex") or "").upper()
        return (
            "Отправлен ответ на coin poll: "
            f"kind={details.get('kind')}, raw={reply_hex}, "
            f"compat={details.get('compat_mode')}, "
            f"emitted_scaled={details.get('emitted_scaled')}, "
            f"remaining_scaled={details.get('remaining_scaled')}; "
            f"{decode_coin_credit_reply(reply_hex)}"
        )
    if event_name == "coin_poll_reply_suppressed":
        return (
            "Ответ на coin poll подавлен: "
            f"reason={details.get('reason')}, "
            f"kind={details.get('suppressed_kind')}, "
            f"pending_scaled={details.get('pending_scaled')}, "
            f"awaiting_vmc_scaled={details.get('awaiting_vmc_scaled')}"
        )
    if event_name == "coin_reply_sent_local":
        reply_hex = str(details.get("reply_hex") or "").upper()
        return (
            "Локально отправлен credit reply: "
            f"raw={reply_hex}, emitted_scaled={details.get('emitted_scaled')}, "
            f"remaining_scaled={details.get('remaining_scaled')}, "
            f"awaiting_vmc_scaled={details.get('awaiting_vmc_scaled')}"
        )
    if event_name == "coin_credit_assumed_local_only":
        return (
            "Прошивка считает кредит только локально отправленным, не подтвержденным VMC: "
            f"awaiting_vmc_scaled={details.get('awaiting_vmc_scaled')}, "
            f"remaining_scaled={details.get('remaining_scaled')}"
        )
    if event_name == "coin_payment_progress":
        return (
            "Прогресс coin-платежа: "
            f"emitted_scaled={details.get('emitted_scaled')}, "
            f"remaining_scaled={details.get('remaining_scaled')}, "
            f"awaiting_vmc_scaled={details.get('awaiting_vmc_scaled')}, "
            f"vmc_credit_accepted={details.get('vmc_credit_accepted')}"
        )
    if event_name == "coin_payment_completed":
        return (
            "Coin payment completed по версии прошивки: "
            f"vmc_credit_accepted={details.get('vmc_credit_accepted')}, "
            f"scope={details.get('completion_scope')}, "
            f"txid={details.get('transaction_id', '')}"
        )
    if event_name == "coin_payment_expired":
        return (
            "Coin payment истек: "
            f"pending_scaled={details.get('pending_scaled')}, "
            f"awaiting_vmc_scaled={details.get('awaiting_vmc_scaled')}, "
            f"vmc_credit_accepted={details.get('vmc_credit_accepted')}, "
            f"reason={details.get('reason')}"
        )
    if event_name == "coin_credit_rejected_by_vmc":
        return (
            "VMC прислал NAK после локального credit reply: "
            f"awaiting_vmc_scaled={details.get('awaiting_vmc_scaled')}, "
            f"txid={details.get('transaction_id', '')}"
        )
    if event_name == "coin_compat_tail_ignored":
        return (
            "Хвост после compat poll проигнорирован: "
            f"raw={details.get('raw_hex')}, normalized={details.get('normalized_hex')}, "
            f"delta_us={details.get('delta_us_from_compat_poll')}"
        )
    if event_name == "payment_rejected":
        return (
            "Команда pay отклонена: "
            f"reason={details.get('reason')}, "
            f"pending_scaled={details.get('pending_scaled')}, "
            f"awaiting_vmc_scaled={details.get('awaiting_vmc_scaled')}"
        )
    if event_name == "rx_frame":
        return (
            "Сырой кадр от VMC: "
            f"raw={details.get('hex')}, normalized={details.get('normalized_hex')}, "
            f"address={details.get('candidate_address')}, "
            f"command={details.get('candidate_command')}, "
            f"checksum_valid={details.get('checksum_valid')}"
        )
    if event_name == "rx_frame_accepted":
        return (
            "Кадр от VMC принят декодером: "
            f"raw={details.get('frame_hex')}, data={details.get('data_hex')}, "
            f"decoded_kind={details.get('decoded_kind')}, "
            f"address={details.get('candidate_address')}, "
            f"command={details.get('candidate_command')}"
        )
    if event_name == "rx_frame_tentative":
        return (
            "Кадр от VMC получил tentative decode: "
            f"raw={details.get('frame_hex')}, "
            f"tentative_kind={details.get('tentative_kind')}, "
            f"reason={details.get('reason_for_unknown')}"
        )
    if event_name == "sniff_command_candidate":
        return (
            "Sniffer предложил команду: "
            f"raw={details.get('raw_hex')}, normalized={details.get('normalized_hex')}, "
            f"candidate={details.get('tentative_kind') or details.get('candidate_kind')}"
        )
    if event_name == "dialogue_trace":
        return (
            "Dialogue trace: "
            f"direction={details.get('direction')}, "
            f"kind={details.get('kind')}, raw9={details.get('raw9')}, "
            f"data_byte={details.get('data_byte')}, ninth_bit={details.get('ninth_bit')}"
        )
    if event_name == "session_cleared":
        return "Локальная MDB-сессия очищена"
    if event_name == "sniff_cleared":
        return "История passive sniff очищена"
    if event_name == "monitor_started":
        return "Подробный MDB monitor включен"
    if event_name == "monitor_stopped":
        return "Подробный MDB monitor выключен"
    if event_name == "passive_sniff_changed":
        return f"Passive sniff changed: enabled={details.get('enabled')}"
    if event_name == "rx_invert_changed":
        return f"RX invert changed: enabled={details.get('rx_invert')}"
    if event_name == "command_received":
        return f"Устройство получило USB-команду: {details.get('command')}"
    if event_name == "state_changed":
        return (
            "Бизнес-состояние изменилось: "
            f"state={details.get('state')}, "
            f"coin_pending={details.get('coin_pending_scaled')}, "
            f"coin_awaiting_vmc={details.get('coin_awaiting_vmc_scaled')}"
        )
    raw_hex = extract_event_raw_hex(event_name, details)
    if raw_hex:
        return f"{event_name}: raw={raw_hex}; {explain_raw_hex(raw_hex)}"
    return f"{event_name}: {compact_json(details)}"


def make_event_record(event: UsbEvent) -> EventRecord:
    raw_hex = extract_event_raw_hex(event.event, event.details)
    return EventRecord(
        at=event.at,
        event=event.event,
        side=event_side(event.event),
        raw_hex=raw_hex,
        human=describe_event(event.event, event.details),
        details=json.loads(json.dumps(event.details)),
    )


def log_command(log: LogWriter, record: CommandRecord) -> None:
    log.line(
        f"[{record.at}] HOST USB command={record.command} payload={compact_json(record.payload)} "
        f"json={record.usb_json} note={record.note}"
    )


def log_event(log: LogWriter, record: EventRecord) -> None:
    raw = f" raw={record.raw_hex}" if record.raw_hex else ""
    hint = f" hint={explain_raw_hex(record.raw_hex)}" if record.raw_hex else ""
    log.line(f"[{record.at}] {record.side:<6} {record.event}{raw}{hint} -> {record.human}")


def send_and_log(
    client: SerialUsbClient,
    log: LogWriter,
    attempt: AttemptReport,
    command: str,
    note: str,
    payload: Optional[dict[str, Any]] = None,
) -> None:
    usb_json = client.send_command(command, payload)
    record = CommandRecord(
        at=now_iso(),
        command=command,
        payload=payload or {},
        usb_json=usb_json,
        note=note,
    )
    attempt.commands.append(record)
    log_command(log, record)


def collect_attempt_events(
    client: SerialUsbClient,
    log: LogWriter,
    after_seq: int,
    duration_s: float,
    poll_interval_s: float,
    quiet_after_terminal_s: float,
) -> tuple[list[EventRecord], int]:
    collected: list[EventRecord] = []
    last_seq = after_seq
    deadline = time.monotonic() + duration_s
    terminal_seen_at: float | None = None
    seen_keys: set[tuple[int, str]] = set()

    while time.monotonic() < deadline:
        client._raise_reader_exception_if_needed()
        for usb_event in client.events_after(last_seq):
            last_seq = max(last_seq, usb_event.seq)
            key = (usb_event.seq, usb_event.event)
            if key in seen_keys:
                continue
            seen_keys.add(key)
            record = make_event_record(usb_event)
            collected.append(record)
            log_event(log, record)
            if record.event in TERMINAL_EVENT_NAMES:
                terminal_seen_at = time.monotonic()
        if terminal_seen_at is not None and (time.monotonic() - terminal_seen_at) >= quiet_after_terminal_s:
            break
        time.sleep(poll_interval_s)

    return collected, last_seq


def request_sniff_recent(
    client: SerialUsbClient,
    log: LogWriter,
    settle_s: float,
    timeout_s: float,
) -> tuple[dict[str, Any], list[SniffFrameRecord]]:
    baseline = client.snapshot_seq()
    usb_json = client.send_command("mdb_sniff_recent", {})
    log.line(f"[{now_iso()}] HOST USB command=mdb_sniff_recent payload={{}} json={usb_json} note=request sniff snapshot")
    client.drain(settle_s)
    deadline = time.monotonic() + timeout_s
    meta_details: dict[str, Any] = {}
    frames: list[SniffFrameRecord] = []
    seen_frame_seq: set[int] = set()
    meta_seen = False

    while time.monotonic() < deadline:
        client._raise_reader_exception_if_needed()
        new_events = client.events_after(baseline)
        for usb_event in new_events:
            baseline = max(baseline, usb_event.seq)
            if usb_event.event == "sniff_recent_meta":
                meta_details = json.loads(json.dumps(usb_event.details))
                meta_seen = True
            elif usb_event.event == "sniff_recent_frame":
                if usb_event.seq in seen_frame_seq:
                    continue
                seen_frame_seq.add(usb_event.seq)
                details = usb_event.details
                best_strategy = details.get("best_strategy") or {}
                frames.append(
                    SniffFrameRecord(
                        index=int(details.get("index", len(frames))),
                        raw_hex=str(details.get("raw_hex") or "").upper(),
                        normalized_hex=str(details.get("normalized_hex") or "").upper(),
                        candidate_address=(
                            int(best_strategy.get("candidate_address"))
                            if isinstance(best_strategy, dict)
                            and best_strategy.get("candidate_address") is not None
                            else None
                        ),
                        candidate_command=(
                            int(best_strategy.get("candidate_command"))
                            if isinstance(best_strategy, dict)
                            and best_strategy.get("candidate_command") is not None
                            else None
                        ),
                        hint=explain_raw_hex(str(details.get("raw_hex") or "").upper()),
                        details=json.loads(json.dumps(details)),
                    )
                )
        if meta_seen:
            expected_frames = int(meta_details.get("returned_frames", 0) or 0)
            if len(frames) >= expected_frames:
                break
        time.sleep(0.05)

    return meta_details, frames


def log_sniff_recent(log: LogWriter, meta: dict[str, Any], frames: list[SniffFrameRecord]) -> None:
    log.line("  Sniff recent:")
    log.line(f"    meta={compact_json(meta)}")
    if not frames:
        log.line("    no sniff frames captured")
        return
    for frame in frames:
        log.line(
            "    "
            f"{frame.index}. raw={frame.raw_hex} normalized={frame.normalized_hex} "
            f"candidate_address={frame.candidate_address} candidate_command={frame.candidate_command} "
            f"hint={frame.hint}"
        )


def summarize_attempt_outcome(attempt: AttemptReport) -> str:
    names = [event.event for event in attempt.events]
    if "payment_rejected" in names:
        return "payment_rejected"
    if "coin_credit_rejected_by_vmc" in names:
        return "vmc_nak_after_credit"
    if any(
        event.event == "coin_payment_completed"
        and bool(event.details.get("vmc_credit_accepted"))
        for event in attempt.events
    ):
        return "vmc_credit_confirmed"
    if "coin_payment_expired" in names:
        return "expired_without_vmc_acceptance"
    if any(event.event == "coin_payment_completed" for event in attempt.events):
        return "local_reply_only_completed"
    if "coin_poll_reply_sent" in names:
        return "reply_sent_waiting_acceptance"
    if "coin_payment_queued" in names:
        return "queued_no_poll_seen"
    return "no_payment_flow_observed"


def run_attempt(
    client: SerialUsbClient,
    log: LogWriter,
    attempt_index: int,
    amount_minor: int,
    command_settle_s: float,
    attempt_timeout_s: float,
    poll_interval_s: float,
    quiet_after_terminal_s: float,
    sniff_recent_timeout_s: float,
) -> AttemptReport:
    txid = f"coin-cycle-{attempt_index:02d}-{uuid.uuid4().hex[:8]}"
    attempt = AttemptReport(
        attempt_index=attempt_index,
        transaction_id=txid,
        started_at=now_iso(),
    )

    log.line("")
    log.line(f"=== Attempt {attempt_index} / txid={txid} ===")

    baseline = client.snapshot_seq()

    send_and_log(client, log, attempt, "mdb_monitor_start", "enable detailed MDB monitor")
    client.drain(command_settle_s)
    send_and_log(client, log, attempt, "mdb_rx_invert_off", "force current board polarity policy")
    client.drain(command_settle_s)
    send_and_log(client, log, attempt, "mdb_passive_sniff_on", "enable passive sniff")
    client.drain(command_settle_s)
    send_and_log(client, log, attempt, "mdb_clear_session", "clear stale MDB business state")
    client.drain(command_settle_s)
    send_and_log(client, log, attempt, "mdb_sniff_clear", "clear passive sniff history")
    client.drain(command_settle_s)

    warmup_events, baseline = collect_attempt_events(
        client=client,
        log=log,
        after_seq=baseline,
        duration_s=1.2,
        poll_interval_s=poll_interval_s,
        quiet_after_terminal_s=quiet_after_terminal_s,
    )
    attempt.events.extend(warmup_events)

    send_and_log(
        client,
        log,
        attempt,
        "pay",
        "queue one MDB coin payment attempt over USB JSON command",
        payload={
            "amount": amount_minor,
            "transport": "mdb",
            "transaction_id": txid,
        },
    )

    flow_events, baseline = collect_attempt_events(
        client=client,
        log=log,
        after_seq=baseline,
        duration_s=attempt_timeout_s,
        poll_interval_s=poll_interval_s,
        quiet_after_terminal_s=quiet_after_terminal_s,
    )
    attempt.events.extend(flow_events)

    meta, frames = request_sniff_recent(
        client=client,
        log=log,
        settle_s=command_settle_s,
        timeout_s=sniff_recent_timeout_s,
    )
    attempt.sniff_meta = meta
    attempt.sniff_frames = frames

    send_and_log(client, log, attempt, "mdb_clear_session", "cleanup after attempt")
    client.drain(command_settle_s)
    tail_events, _ = collect_attempt_events(
        client=client,
        log=log,
        after_seq=baseline,
        duration_s=1.2,
        poll_interval_s=poll_interval_s,
        quiet_after_terminal_s=quiet_after_terminal_s,
    )
    attempt.events.extend(tail_events)

    attempt.outcome = summarize_attempt_outcome(attempt)
    attempt.finished_at = now_iso()
    log.line(f"Attempt outcome: {attempt.outcome}")
    log_sniff_recent(log, attempt.sniff_meta, attempt.sniff_frames)
    return attempt


def build_report(
    port: str,
    baud: int,
    amount_minor: int,
    attempts: list[AttemptReport],
    log_path: Path,
    json_path: Path,
) -> dict[str, Any]:
    return {
        "generated_at": now_iso(),
        "transport": "usb_serial",
        "port": port,
        "baud": baud,
        "amount_minor": amount_minor,
        "log_path": str(log_path),
        "json_path": str(json_path),
        "attempt_count": len(attempts),
        "attempts": [asdict(attempt) for attempt in attempts],
    }


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Run the full MDB coin payment cycle directly over USB serial, "
            "capture exact RX/TX bytes, and explain each step in human terms."
        )
    )
    parser.add_argument("--port", default=DEFAULT_PORT)
    parser.add_argument("--baud", type=int, default=DEFAULT_BAUD)
    parser.add_argument("--timeout", type=float, default=DEFAULT_SERIAL_TIMEOUT_S)
    parser.add_argument("--amount", type=int, default=DEFAULT_AMOUNT_MINOR)
    parser.add_argument("--attempts", type=int, default=DEFAULT_ATTEMPTS)
    parser.add_argument("--attempt-timeout", type=float, default=DEFAULT_ATTEMPT_TIMEOUT_S)
    parser.add_argument("--command-settle", type=float, default=DEFAULT_COMMAND_SETTLE_S)
    parser.add_argument("--poll-interval", type=float, default=DEFAULT_POLL_INTERVAL_S)
    parser.add_argument(
        "--quiet-after-terminal",
        type=float,
        default=DEFAULT_QUIET_AFTER_TERMINAL_S,
    )
    parser.add_argument(
        "--sniff-recent-timeout",
        type=float,
        default=DEFAULT_SNIFF_RECENT_TIMEOUT_S,
    )
    parser.add_argument("--out-dir", type=Path, default=DEFAULT_OUT_DIR)
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    ensure_dir(args.out_dir)
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    stem = f"mdb_coin_payment_cycle_usb_{timestamp}"
    log_path = args.out_dir / f"{stem}.log"
    json_path = args.out_dir / f"{stem}.json"
    log = LogWriter(log_path)
    attempts: list[AttemptReport] = []

    try:
        with SerialUsbClient(
            port=args.port,
            baud=args.baud,
            serial_timeout=args.timeout,
            log=log,
        ) as client:
            log.line(f"[{now_iso()}] INFO serial_open port={args.port} baud={args.baud}")
            client.drain(0.75)
            for attempt_index in range(1, int(args.attempts) + 1):
                attempts.append(
                    run_attempt(
                        client=client,
                        log=log,
                        attempt_index=attempt_index,
                        amount_minor=int(args.amount),
                        command_settle_s=float(args.command_settle),
                        attempt_timeout_s=float(args.attempt_timeout),
                        poll_interval_s=float(args.poll_interval),
                        quiet_after_terminal_s=float(args.quiet_after_terminal),
                        sniff_recent_timeout_s=float(args.sniff_recent_timeout),
                    )
                )
            try:
                client.send_command("mdb_passive_sniff_off", {})
                client.send_command("mdb_monitor_stop", {})
                client.drain(0.4)
            except Exception:
                pass
    except KeyboardInterrupt:
        log.line("")
        log.line("Interrupted by user")
        report = build_report(args.port, int(args.baud), int(args.amount), attempts, log_path, json_path)
        json_path.write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding="utf-8")
        log.close()
        return 130
    except (SerialException, StepFailure, RuntimeError) as exc:
        log.line("")
        log.line(f"ERROR: {exc}")
        report = build_report(args.port, int(args.baud), int(args.amount), attempts, log_path, json_path)
        json_path.write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding="utf-8")
        log.close()
        return 1

    report = build_report(args.port, int(args.baud), int(args.amount), attempts, log_path, json_path)
    json_path.write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding="utf-8")
    log.close()
    print("")
    print(f"Log:  {log_path}")
    print(f"JSON: {json_path}")
    for attempt in attempts:
        print(f"Attempt {attempt.attempt_index}: {attempt.outcome}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
