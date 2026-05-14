#pragma once

#include <Arduino.h>
#include "mdb_settings_store.h"

class PulseService;
class MdbService;
class PulseConfigService;
class OtaManager;

class CommandService {
 public:
  CommandService(PulseService& pulseService, MdbService& mdbService,
                 PulseConfigService& pulseConfigService, OtaManager& otaService,
                 MdbSettingsStore& mdbSettingsStore);

  void handleTextMessage(const uint8_t* payload, size_t length);
  String buildMdbDebugStateJson() const;

  // Called by main loop (APPLYING_MDB_SETTINGS phase) to check for server response.
  bool hasPendingMdbSettingsResponse() const { return hasPendingResponse_; }
  MdbSettingsStore::Settings takePendingMdbSettingsResponse();
  void clearPendingMdbSettingsResponse() { hasPendingResponse_ = false; }

 private:
  PulseService& pulseService_;
  MdbService& mdbService_;
  PulseConfigService& pulseConfigService_;
  OtaManager& otaService_;
  MdbSettingsStore& mdbSettingsStore_;

  bool hasPendingResponse_ = false;
  MdbSettingsStore::Settings pendingResponse_;
};
