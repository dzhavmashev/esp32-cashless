# Read-only ESP32 old device extract report

Дата: 2026-04-28  
Порт: `/dev/ttyUSB0`

## A. Что удалось получить с устройства

| Факт | Значение | Источник |
|---|---:|---|
| Serial port | `/dev/ttyUSB0` | `ls -l /dev/ttyUSB* /dev/ttyACM*` |
| USB adapter | Silicon Labs CP2102 / CP210x UART Bridge | `udevadm info -q property -n /dev/ttyUSB0`, `lsusb` |
| USB VID:PID | `10c4:ea60` | `udevadm`, `lsusb` |
| Доступ к `dmesg` | не найдено: `Operation not permitted` | `dmesg \| tail -n 80` |
| Читаемый serial startup log | 115200 baud | `console_commands.log`, секция `BAUD 115200`, `[initial]` |
| Запрошенные boot captures | `boot_115200.log`, `boot_74880.log`, `boot_9600.log`, `boot_57600.log`, `boot_230400.log`, `boot_921600.log` сохранены; в них читаемый boot log не найден | файлы `boot_*.log` |
| Interactive serial console | не найдено: команды не дали распознаваемого command response, шли только точки/фоновые Wi-Fi логи | `console_commands.log` |
| Chip type | ESP32-D0WDQ6 revision v1.1 | `esptool_info.log`, `chip_id --no-stub` |
| MAC | `fc:e8:c0:de:e9:30` | `esptool_info.log`, `read_mac --no-stub` |
| Crystal frequency | 40MHz | `esptool_info.log` |
| Flash size | 4MB | `esptool_info.log`, `flash_id --no-stub` |
| Flash manufacturer/device | manufacturer `0x20`, device `0x4016` | `esptool_info.log`, `flash_id --no-stub` |
| Secure boot | выключен: `ABS_DONE_0=False`, `ABS_DONE_1=False` | `esptool_info.log`, `espefuse summary` |
| Flash encryption | выключено: `FLASH_CRYPT_CNT=0` | `esptool_info.log`, `espefuse summary` |
| Flash dump | доступен, считано 4194304 bytes | `read_flash.log`, `old_device_flash.bin` |
| Firmware app metadata | project `arduino-lib-builder`; app version `esp-idf: v4.4.7 38eeba213a`; compile time `Mar 5 2024 12:36:24`; ESP-IDF `v4.4.7-dirty` | `app0_image_info.log` |
| Firmware string version | `firmware_version` рядом со строкой `2.3.1` | `strings_relevant_masked.txt`, строки 617-618 |
| Partition table | `nvs`, `otadata`, `app0`, `app1`, `nvs_cert`, `spiffs`, `coredump` | `partition_table.log` |

Все `esptool` команды выполнялись read-only. Для `chip_id`, `read_mac`, `flash_id`, `read_flash` использовался `--no-stub`.

## B. Найденные MDB/GPIO параметры

| Параметр | Значение | Источник | Уверенность |
|---|---:|---|---|
| MDB RX GPIO | 26 | `console_commands.log`: `MDB RX Pin: 26`; `nvs_parsed_relevant.txt`: `dev_mdb_rx=26` | подтверждено |
| MDB TX GPIO | 27 | `console_commands.log`: `TX Pin: 27`; `nvs_parsed_relevant.txt`: `dev_mdb_tx=27` | подтверждено |
| MDB peripheral RX GPIO | 13 | `console_commands.log`: `Periph RX Pin: 13`; `nvs_parsed_relevant.txt`: `dev_mdb_prx=13` | подтверждено |
| MDB address raw | `0x10` | `console_commands.log`: `MDB Address: 0x10`; `nvs_parsed_relevant.txt`: `dev_mdb_addr=16` | подтверждено |
| MDB session timeout | 60 sec | `console_commands.log`: `MDB Session Timeout: 60 sec`; `nvs_parsed_relevant.txt`: `dev_mdb_tout=60` | подтверждено |
| Payment mode NVS value | 4 | `nvs_parsed_relevant.txt`: `dev_pay_mode=4`; startup log says `MDB mode` | подтверждено |
| Device type NVS value | 6 | `console_commands.log`: `DeviceType: 6`; `nvs_parsed_relevant.txt`: `dev_type=6` | подтверждено |
| MDB mode | MDB Cashless mode / BV sniffing | `console_commands.log`: `InputPulseTracker skipped - MDB Cashless mode uses BV sniffing instead` | подтверждено |
| Control GPIO | 26 | `nvs_parsed_relevant.txt`: `dev_ctrl_pin=26` | подтверждено |
| Activity GPIO | 14 | `nvs_parsed_relevant.txt`: `dev_act_pin=14` | подтверждено |
| Cash acceptor power GPIO | 19 HIGH | `console_commands.log`: `GPIO 19 set to HIGH (cash acceptor power)` | подтверждено |
| Modem power relay GPIO | 33, active-high note says `LOW=ON` | `console_commands.log`: `ModemPowerRelay: Initialized on pin 33 (active-high: LOW=ON, modem power ON)` | подтверждено |
| Baudrate для читаемого startup log | 115200 | `console_commands.log`, секция `BAUD 115200` | подтверждено |
| UART number | не найдено | нет строки/команды с номером UART для MDB | не найдено |
| hardware UART или bit-bang | не найдено | строка `ISR-based read` есть только для `MDB Coin Emulator`, но активный режим подтверждён как MDB Cashless/BV sniffing | не найдено |
| RX inversion | не найдено | поиск `invert/inverted` не дал параметра MDB | не найдено |
| TX inversion | не найдено | поиск `invert/inverted` не дал параметра MDB | не найдено |
| `bit_us` | не найдено | поиск `bit_us` не дал значения | не найдено |
| MDB baudrate | не найдено | нет строки с MDB baudrate | не найдено |
| Parity | не найдено | нет строки с MDB parity | не найдено |
| Checksum algorithm | не найдено | есть generic firmware строки checksum, но MDB algorithm не найден | не найдено |
| SETUP response bytes | не найдено | нет подтверждённых bytes | не найдено |
| POLL response | не найдено | нет подтверждённых bytes | не найдено |
| RESET response | не найдено | нет подтверждённых bytes | не найдено |
| TUBE STATUS response | не найдено | нет подтверждённых bytes | не найдено |
| COIN TYPE response | не найдено | нет подтверждённых bytes | не найдено |
| EXPANSION ID response | не найдено | есть литералы `3769G600351`, `CF7900MDB`, `022290281967`, `VN2600RU`, но без подтверждённой привязки к EXPANSION ID | не найдено |

## C. Найденные команды serial console

| Команда | Ответ | Полезность для MDB |
|---|---|---|
| `help` | точка/нет распознаваемого ответа | не найдено |
| `?` | точка/нет распознаваемого ответа | не найдено |
| `status` | точки/нет распознаваемого ответа | не найдено |
| `info` | точка/нет распознаваемого ответа | не найдено |
| `version` | точки/нет распознаваемого ответа | не найдено |
| `config` | точка/нет распознаваемого ответа | не найдено |
| `dump` | точка/нет распознаваемого ответа | не найдено |
| `mdb` | точка/нет распознаваемого ответа; параллельно шли Wi-Fi reconnect logs | не найдено |
| `mdb_status` | точка/нет распознаваемого ответа | не найдено |
| `mdb_debug` | точка/нет распознаваемого ответа | не найдено |
| `debug` | точки/нет распознаваемого ответа | не найдено |
| `pins` | точка/нет распознаваемого ответа | не найдено |
| `gpio` | точки/нет распознаваемого ответа | не найдено |
| `get_config` | точка/нет распознаваемого ответа | не найдено |
| `show_config` | точка/нет распознаваемого ответа | не найдено |
| `diag` | точки/нет распознаваемого ответа | не найдено |
| `diagnostics` | точка/нет распознаваемого ответа | не найдено |
| `state` | точки/нет распознаваемого ответа | не найдено |
| `mdb_state` | точка/нет распознаваемого ответа | не найдено |
| `mdb_config` | точка/нет распознаваемого ответа | не найдено |
| `mdb_summary` | точки/нет распознаваемого ответа | не найдено |
| `rx_diag` | точка/нет распознаваемого ответа | не найдено |
| `reset_state` | не отправлялась: потенциально меняет состояние | не найдено |
| `tx_line_test` | не отправлялась: потенциально активный тест линии, не read-only | не найдено |

## D. Найденные строки из firmware dump

| Строка | Контекст | Что подтверждает |
|---|---|---|
| `firmware_version` + `2.3.1` | `strings_relevant_masked.txt`: строки 617-618 | В firmware есть строковая версия `2.3.1` |
| `dev_mdb_rx`, `dev_mdb_tx`, `dev_mdb_prx`, `dev_mdb_addr`, `dev_mdb_tout` | `strings_relevant_masked.txt`: строки 828-835 | Имена NVS/config ключей MDB |
| `MDB RX Pin: %d, TX Pin: %d, Periph RX Pin: %d` | `strings_relevant_masked.txt`: строка 833 | Формат startup/debug лога для MDB GPIO |
| `MDB Coin Emulator Address: 0x08 (fixed)` | `strings_relevant_masked.txt`: строка 837 | В firmware есть режим coin emulator с fixed address `0x08`; активность этого режима на устройстве не подтверждена |
| `MDB Coin Emulator initialized (ISR-based read, Core 1)` | `strings_relevant_masked.txt`: строка 1090 | В firmware есть реализация coin emulator; активность этого режима на устройстве не подтверждена |
| `[MDB-DIAG] COIN CMD...`, `[MDB-DIAG] BILL CMD...` | `strings_relevant_masked.txt`: строки 1094-1098 | В firmware есть диагностические MDB counters |
| `3769G600351`, `CF7900MDB`, `022290281967`, `VN2600RU` | `strings_relevant_masked.txt`: строки 1099-1102 | Литералы присутствуют в firmware; назначение без дополнительного лога не подтверждено |
| `[MDB] Initialized (RX:%d, TX:%d, Addr:0x%02X, Timeout:%u sec)` | `strings_relevant_masked.txt`: строка 1113 | Формат active MDB startup лога |
| `cashless_loop` | `strings_relevant_masked.txt`: строка 1114 | В firmware есть cashless loop |
| `show_config`, `update_config`, `ota_check`, `ota_update`, `ota_abort` | `strings_relevant_masked.txt`: строки 1162-1166 | Эти строки есть в firmware command layer; serial console response не подтверждён |

## E. Что НЕ найдено

RX GPIO: найдено `26`.  
TX GPIO: найдено `27`.  
SETUP response: не найдено.  
POLL response: не найдено.  
RESET response: не найдено.  
TUBE STATUS response: не найдено.  
COIN TYPE response: не найдено.  
EXPANSION ID response bytes: не найдено.  
Coin changer active mode: не найдено.  
Cashless active mode: найдено.  
Bill validator active mode: не найдено как самостоятельный режим; найдено только `BV sniffing` в строке Cashless mode.  
MDB baudrate: не найдено.  
UART number: не найдено.  
9th bit / mode bit logic: не найдено.  
RX/TX inversion: не найдено.  
Idle/active levels: не найдено.  
Open drain / push-pull: не найдено.  
Pull-up / pull-down: не найдено.  
Response delay / inter-byte delay / frame gap: не найдено.  
Checksum algorithm MDB: не найдено.

## F. Что можно перенести в новый проект

Только фактически найденные значения:

| Параметр | Значение | Источник |
|---|---:|---|
| MDB RX GPIO | 26 | startup log + NVS |
| MDB TX GPIO | 27 | startup log + NVS |
| MDB peripheral RX GPIO | 13 | startup log + NVS |
| MDB address | `0x10` | startup log + NVS |
| MDB session timeout | 60 sec | startup log + NVS |
| Active MDB mode | Cashless / BV sniffing | startup log |
| Device type value | 6 | startup log + NVS |
| Payment mode value | 4 | NVS + startup log `MDB mode` |
| Cash acceptor power GPIO | 19 HIGH | startup log |
| Modem relay GPIO | 33 | startup log |

Не переносить без дополнительных фактов: MDB baudrate, inversion, timing, SETUP/POLL/RESET/TUBE/COIN/EXPANSION response bytes, checksum logic, UART number, electrical idle/active levels.

## G. Следующие безопасные действия

1. Повторить 115200 serial capture с ручным EN/RESET и сохранить отдельный чистый boot log, если нужен именно reset-time ROM/app log без фонового probing.
2. Измерить MDB RX/TX линии логическим анализатором или осциллографом: idle level, active level, bit timing, inversion, frame gap.
3. Снять пассивный лог MDB/VMC обмена на линиях без инжекта команд.
4. Если нужен serial command layer, проверить, не ожидает ли устройство JSON-команды через MQTT/backend, потому что строки `CMD: JSON parse failed`, `show_config`, `update_config` найдены в firmware, но interactive USB console не подтверждён.

## Артефакты

| Файл | Назначение |
|---|---|
| `boot_115200.log`, `boot_74880.log`, `boot_9600.log`, `boot_57600.log`, `boot_230400.log`, `boot_921600.log` | raw captures на стандартных скоростях |
| `console_commands.log` | masked serial command probing log |
| `esptool_info.log` | chip/read_mac/flash_id/eFuse вывод |
| `read_flash.log` | read-only flash dump log |
| `old_device_flash.bin` | 4MB flash dump |
| `old_device_strings.txt` | `strings -a` dump |
| `strings_relevant_masked.txt` | релевантные строки с маскированием секретов |
| `nvs_parsed_relevant.txt` | parsed relevant NVS values |
| `partition_table.log` | parsed partition table |
| `app0_image_info.log` | app metadata |
| `checksums.txt` | SHA256 артефактов |
