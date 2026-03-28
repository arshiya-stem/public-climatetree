#include "DHT11_API.h"

DHT11_API::DHT11_API(int digital_pin)
  : pin(digital_pin), sensor(digital_pin, DHT11) {}

void DHT11_API::Initialize() {
  sensor.begin();
}

float DHT11_API::ReadTemperature() {
  float temperature = sensor.readTemperature();
  Serial.println("Temperature (DHT11): " + (String)temperature + " C");
  return temperature;
}

float DHT11_API::ReadHumidity() {
  float humidity = sensor.readHumidity();
  Serial.println("Humidity (DHT20): " + (String)humidity + " %");
  return humidity;
}