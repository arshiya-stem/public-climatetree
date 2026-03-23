#include "HTU21D_API.h"

HTU21D_API::HTU21D_API() {}

void HTU21D_API::Initialize() {
  sensor.begin();
}

float HTU21D_API::ReadTemperature() {
  return sensor.readTemperature();
}

float HTU21D_API::ReadHumidity() {
  return sensor.readHumidity();
}