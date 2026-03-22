#include "Water_Level_Sensor_API.h"

Water_Level_Sensor_API::Water_Level_Sensor_API(int digital_analog_pin, bool isAnalog) : pin(digital_analog_pin), isAnalog(isAnalog) {};

float Water_Level_Sensor_API::ReadWaterLevel() {
  if (isAnalog) {
    return (analogRead(pin) / 1023) * 100;
  } else {
    return digitalRead(pin);
  }
}