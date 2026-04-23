#pragma once

#include <Arduino.h>

class PulseService;
class MdbService;
class PulseConfigService;
class UartService;
class OtaManager;

// Разбирает входящие команды от backend и направляет их в нужные сервисы.
class CommandService {
 public:
  // Принимает ссылки на все прикладные сервисы устройства.
  CommandService(PulseService& pulseService, MdbService& mdbService,
                 PulseConfigService& pulseConfigService, UartService& uartService,
                 OtaManager& otaService);

  // Обрабатывает один текстовый пакет WebSocket с командой.
  void handleTextMessage(const uint8_t* payload, size_t length);
  // Отдаёт текущую MDB-диагностику в JSON-виде.
  String buildMdbDebugStateJson() const;

 private:
  PulseService& pulseService_;
  MdbService& mdbService_;
  PulseConfigService& pulseConfigService_;
  UartService& uartService_;
  OtaManager& otaService_;
};
