#pragma once

#include <Arduino.h>
#include <Preferences.h>

class MdbSettingsStore {
 public:
  struct Settings {
    char manufacturer[4];     // 3 ASCII chars + \0
    char serial[13];          // 12 ASCII chars + \0
    char model[13];           // 12 ASCII chars + \0
    uint8_t version_hi;
    uint8_t version_lo;
    uint8_t feature_level;
    uint16_t country_code;
    uint8_t scale_factor;
    uint8_t decimal_places;
    uint8_t max_response_sec;
    bool isValid;  // false = compiled defaults, not loaded from NVS or server
  };

  static Settings defaults();

  void begin();
  Settings load();
  bool save(const Settings& s);
  bool clear();

 private:
  Preferences prefs_;
};
