# OTA Runbook

## Preconditions

- `platformio.ini` uses `partitions.csv`
- `partitions.csv` contains:
  - `otadata`
  - `app0`
  - `app1`
- device is online in `GET /devices/{device_id}/info`
- device is not in active vend/session state, or OTA will stay deferred

## Build Firmware Binary

```bash
cd /home/user/projects/scheme/software/source
$HOME/.platformio/penv/bin/pio run
```

Expected artifact:

```text
.pio/build/esp32dev/firmware.bin
```

## Validate Server Copy

The backend serves the latest binary directly from the build output path:

```bash
curl -I http://192.168.192.188:8000/devices/firmware/latest.bin
curl http://192.168.192.188:8000/devices/firmware/latest.sha256
```

If `latest.bin` returns `200 OK`, the server can already distribute the new binary.

## Send OTA Command to Remote ESP32

```bash
curl -X POST http://192.168.192.188:8000/devices/007007848fb8/ota/update \
  -H "Content-Type: application/json" \
  -d '{"version":"2026.03.30.220000","sha256":"<sha256-from-endpoint>"}'
```

The backend will generate the firmware URL automatically if `url` is omitted.

## Validate Update Progress

```bash
curl http://192.168.192.188:8000/devices/007007848fb8/ota/state
curl http://192.168.192.188:8000/devices/007007848fb8/ota/events
curl http://192.168.192.188:8000/devices/007007848fb8/info
```

Expected sequence:

1. `queued`
2. `start`
3. `progress`
4. `end`
5. `rebooting`
6. `info.firmware_version` changes to the new version after reconnect

## One-Step Release

```bash
cd /home/user/projects/scheme/software/source
bash scripts/release_ota.sh 007007848fb8
```

This script:

1. bumps `firmware_version.h`
2. builds `firmware.bin`
3. computes local `sha256`
4. sends OTA command to the backend
5. prints `/devices/{device_id}/info`
