#include "legacy_healthcheck.h"

#include <HTTPClient.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>

#include "device_config.h"
#include "logging_utils.h"

// Выполняет простой HTTP healthcheck до backend-сервера.
bool performHealthcheck() {
  HTTPClient http;
  const String portStr = SERVER_PORT == 0 ? "" : ":" + String(SERVER_PORT);
  const String url =
      String(SERVER_SCHEME) + "://" + SERVER_HOST + portStr + SERVER_PATH;

  WiFiClientSecure secureClient;
  WiFiClient client;

  Serial.print("Sending GET request to ");
  Serial.println(url);

  http.setReuse(false);

  if (String(SERVER_SCHEME) == "https") {
    secureClient.setInsecure();
    secureClient.setTimeout(15000);

    if (!http.begin(secureClient, url)) {
      logMessage("HTTP begin failed", url);
      return false;
    }
  } else {
    client.setTimeout(15000);

    if (!http.begin(client, url)) {
      logMessage("HTTP begin failed", url);
      return false;
    }
  }

  const int httpCode = http.GET();

  if (httpCode > 0) {
    Serial.print("HTTP status: ");
    Serial.println(httpCode);
  } else {
    Serial.print("HTTP request failed: ");
    Serial.println(http.errorToString(httpCode));
  }

  http.end();
  return httpCode >= 200 && httpCode < 300;
}
