#include "Light_Sensor_API.h"

Light_Sensor_API::Light_Sensor_API(int analog_pin) : pin(analog_pin){}

float Light_Sensor_API::ReadAmbience() {
  return (analogRead(pin) / 1023 ) * 100;
}