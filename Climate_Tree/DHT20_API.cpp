#include "DHT20_API.h"

DHT20_API::DHT20_API() {}

void DHT20_API::Initialize() {
  sensor.begin();
}

float DHT20_API::ReadTemperature() {
  return sensor.getTemperature();
}

float DHT20_API::ReadHumidity() {
  return sensor.getHumidity();
}