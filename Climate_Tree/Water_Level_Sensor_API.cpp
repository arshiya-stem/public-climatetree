#include "Water_Level_Sensor_API.h"

Water_Level_Sensor_API::Water_Level_Sensor_API(int digital_analog_pin, bool isAnalog) : pin(digital_analog_pin), isAnalog(isAnalog) {}

float Water_Level_Sensor_API::ReadWaterLevel() {
  if (isAnalog) {
    return 100.0 - (analogRead(pin) / 4095.0) * 100;
  } else {
    return digitalRead(pin);
  }
}