#include "Moisture_Sensor_API.h"

Moisture_Sensor_API::Moisture_Sensor_API(int analog_pin) : pin(analog_pin) {}

float Moisture_Sensor_API::ReadMoisture(){
  return (analogRead(pin) / 1023.0) * 100;
}


