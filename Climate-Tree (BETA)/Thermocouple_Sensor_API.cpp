#include "Thermocouple_Sensor_API.h"

Thermocouple_Sensor_API::Thermocouple_Sensor_API(int analog_pin1, int analog_pin2) : sensor(analog_pin1, analog_pin2) {}

void Thermocouple_Sensor_API::Initialize() {
  sensor.begin();
}

float Thermocouple_Sensor_API::ReadTemperature() {
  float temperature = sensor.getThmc();
  Serial.println("Temperature (THERMOCOUPLE_SENSOR): " + (String)temperature + " C");
  return temperature;
}