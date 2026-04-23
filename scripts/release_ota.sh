#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SERVICE_DIR="$(cd "$ROOT_DIR/../service" && pwd)"
VERSION_FILE="$ROOT_DIR/firmware_version.h"
PIO_BIN="${HOME}/.platformio/penv/bin/pio"
SERVER_BASE="${SERVER_BASE:-http://192.168.192.188:8000}"
DEVICE_ID="${1:-007007848fb8}"
VERSION="${2:-$(date '+%Y.%m.%d.%H%M%S')}"

if [[ ! -x "$PIO_BIN" ]]; then
  echo "PlatformIO not found at $PIO_BIN" >&2
  exit 1
fi

python3 - "$VERSION_FILE" "$VERSION" <<'PY'
from pathlib import Path
import re
import sys

path = Path(sys.argv[1])
version = sys.argv[2]
text = path.read_text()
updated = re.sub(
    r'constexpr char FIRMWARE_VERSION\[] = "[^"]+";',
    f'constexpr char FIRMWARE_VERSION[] = "{version}";',
    text,
)
if text == updated:
    raise SystemExit("failed to update firmware version")
path.write_text(updated)
print(version)
PY

echo "Building firmware version $VERSION"
cd "$ROOT_DIR"
"$PIO_BIN" run

FIRMWARE_BIN="$ROOT_DIR/.pio/build/esp32dev/firmware.bin"
if [[ ! -f "$FIRMWARE_BIN" ]]; then
  echo "Firmware binary not found at $FIRMWARE_BIN" >&2
  exit 1
fi

SHA256="$(sha256sum "$FIRMWARE_BIN" | awk '{print $1}')"
echo "Firmware sha256: $SHA256"

echo "Queueing OTA update for device $DEVICE_ID"
curl -sS -X POST "$SERVER_BASE/devices/$DEVICE_ID/ota/update" \
  -H 'Content-Type: application/json' \
  -d "{\"version\":\"$VERSION\",\"sha256\":\"$SHA256\"}"
echo

echo "Firmware info endpoint:"
curl -sS "$SERVER_BASE/devices/$DEVICE_ID/info" || true
echo
