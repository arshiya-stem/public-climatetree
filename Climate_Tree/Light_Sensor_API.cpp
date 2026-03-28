#include "Light_Sensor_API.h"

Light_Sensor_API::Light_Sensor_API(int analog_pin) : pin(analog_pin){}

float Light_Sensor_API::ReadAmbience() {
  float ambience = (analogRead(pin) / 4095.0 ) * 100;
  Serial.println("Ambience (LIGHT_SENSOR): " + (String)ambience + " %");
  return ambience;
}