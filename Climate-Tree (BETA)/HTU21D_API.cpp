#include "HTU21D_API.h"

HTU21D_API::HTU21D_API() {}

void HTU21D_API::Initialize() {
  sensor.begin();
}

float HTU21D_API::ReadTemperature() {
  float temperature = sensor.readTemperature();
  Serial.println("Temperature (HTU21D): " + (String)temperature + " C");
  return temperature;
}

float HTU21D_API::ReadHumidity() {
  float humidity = sensor.readHumidity();
  Serial.println("Humidity (HTU21D): " + (String)humidity + " %");
  return humidity;
}