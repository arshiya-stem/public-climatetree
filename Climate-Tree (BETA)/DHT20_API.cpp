#include "DHT20_API.h"

DHT20_API::DHT20_API() {}

void DHT20_API::Initialize() {
  sensor.begin();
}

float DHT20_API::ReadTemperature() {
  float temperature = sensor.getTemperature();
  Serial.println("Temperature (DHT20): " + (String)temperature + " C");
  return temperature;
}

float DHT20_API::ReadHumidity() {
  float humidity = sensor.getHumidity();
  Serial.println("Humidity (DHT20): " + (String)humidity + " %");
  return humidity; 
}