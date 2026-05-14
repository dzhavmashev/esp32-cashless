#include "mdb_settings_store.h"

#include <cstring>

MdbSettingsStore::Settings MdbSettingsStore::defaults()
{
  Settings s;
  strncpy(s.manufacturer, "ESP",          sizeof(s.manufacturer));
  strncpy(s.serial,       "000000000001", sizeof(s.serial));
  strncpy(s.model,        "MDB-CASHLESS", sizeof(s.model));
  s.version_hi      = 0x00;
  s.version_lo      = 0x01;
  s.feature_level   = 1;
  s.country_code    = 7;
  s.scale_factor    = 1;
  s.decimal_places  = 2;
  s.max_response_sec = 5;
  s.isValid = false;
  return s;
}

void MdbSettingsStore::begin()
{
  prefs_.begin("mdb", false);
}

MdbSettingsStore::Settings MdbSettingsStore::load()
{
  Settings s = defaults();
  if (!prefs_.isKey("manuf"))
    return s;  // isValid remains false

  const String manuf  = prefs_.getString("manuf",   "ESP");
  const String serial = prefs_.getString("serial",  "000000000001");
  const String model  = prefs_.getString("model",   "MDB-CASHLESS");
  strncpy(s.manufacturer, manuf.c_str(),  3); s.manufacturer[3]  = '\0';
  strncpy(s.serial,       serial.c_str(), 12); s.serial[12]      = '\0';
  strncpy(s.model,        model.c_str(),  12); s.model[12]       = '\0';

  s.version_hi       = prefs_.getUChar("ver_hi",   0x00);
  s.version_lo       = prefs_.getUChar("ver_lo",   0x01);
  s.feature_level    = prefs_.getUChar("feat_lv",  1);
  s.country_code     = prefs_.getUShort("country", 7);
  s.scale_factor     = prefs_.getUChar("scale",    1);
  s.decimal_places   = prefs_.getUChar("decimal",  2);
  s.max_response_sec = prefs_.getUChar("maxresp",  5);
  s.isValid = true;
  return s;
}

bool MdbSettingsStore::save(const Settings& s)
{
  prefs_.putString("manuf",   s.manufacturer);
  prefs_.putString("serial",  s.serial);
  prefs_.putString("model",   s.model);
  prefs_.putUChar("ver_hi",   s.version_hi);
  prefs_.putUChar("ver_lo",   s.version_lo);
  prefs_.putUChar("feat_lv",  s.feature_level);
  prefs_.putUShort("country", s.country_code);
  prefs_.putUChar("scale",    s.scale_factor);
  prefs_.putUChar("decimal",  s.decimal_places);
  prefs_.putUChar("maxresp",  s.max_response_sec);
  return true;
}

bool MdbSettingsStore::clear()
{
  prefs_.clear();
  return true;
}
