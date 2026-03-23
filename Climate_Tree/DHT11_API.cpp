#include "DHT11_API.h"

DHT11_API::DHT11_API(int digital_pin)
  : pin(digital_pin), sensor(digital_pin, DHT11) {}

void DHT11_API::Initialize() {
  sensor.begin();
}

float DHT11_API::ReadTemperature() {
  return sensor.readTemperature();
}

float DHT11_API::ReadHumidity() {
  return sensor.readHumidity();
}