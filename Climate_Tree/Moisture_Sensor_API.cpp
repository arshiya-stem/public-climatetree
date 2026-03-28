#include "Moisture_Sensor_API.h"

Moisture_Sensor_API::Moisture_Sensor_API(int analog_pin) : pin(analog_pin) {}

float Moisture_Sensor_API::ReadMoisture(){
  float moisture = (analogRead(pin) / 4095.0) * 100;
  Serial.println("Moisture (MOISTURE_SENSOR): " + (String)moisture + " %");
  return moisture;
}


