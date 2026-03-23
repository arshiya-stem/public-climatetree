#include "DS18B20_API.h"

DS18B20_API::DS18B20_API(int digital_pin)
  : pin(digital_pin), sensor(digital_pin) {}

void DS18B20_API::Initialize() {
  if (!sensor.begin()) {
    Serial.println("Error: DS18B20 init failed");
    while (true);
  }

  sensor.searchDevices();

  if (!sensor.getAddress(0, sensor_addr)) {
    Serial.println("Error: DS18B20 address failed");
    while (true);
  }

  Serial.println("DS18B20 ready!");
}

float DS18B20_API::ReadTemperature() {
  return sensor.readTemperature(sensor_addr);
}

