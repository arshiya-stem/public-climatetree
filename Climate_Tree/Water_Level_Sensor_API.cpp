#include "Water_Level_Sensor_API.h"

Water_Level_Sensor_API::Water_Level_Sensor_API(int digital_analog_pin, bool isAnalog) : pin(digital_analog_pin), isAnalog(isAnalog) {}

float Water_Level_Sensor_API::ReadWaterLevel() {
  if (isAnalog) {
    float water_level = 100.0 - (analogRead(pin) / 4095.0) * 100;
    Serial.println("Water Level (WATER_LEVEL_SENSOR): " + (String)water_level + " %");
    return water_level;
  } else {
    bool is_filled = digitalRead(pin);
    if (is_filled) {
      Serial.println("Water Level (WATER_LEVEL_SENSOR): Filled");
    } else {
      Serial.println("Water Level (WATER_LEVEL_SENSOR): Not Filled");
    }
    return is_filled;
  }
}