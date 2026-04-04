#ifndef WATER_LEVEL_SENSOR_API
#define WATER_LEVEL_SENSOR_API

#include <Arduino.h>   // Provides analogRead, digitalRead, and basic types

/// @brief API wrapper for a water level sensor
/// @note Supports both analog and digital-type sensors
class Water_Level_Sensor_API {
  private:
    int pin;        ///< GPIO pin connected to the sensor output
    bool isAnalog;  ///< true = analog sensor, false = digital sensor

  public:
    /// @brief Constructor
    /// @param pin GPIO pin used for the sensor
    /// @param isAnalog Set to true if using analog output, false for digital
    Water_Level_Sensor_API(int digital_analog_pin, bool isAnalog);

    /// @brief Reads the current water level
    /// @return 
    /// - If analog: returns a normalized value (e.g., 0.0–1.0 or raw ADC)
    /// - If digital: returns 0.0 (LOW) or 1.0 (HIGH)
    float ReadWaterLevel();  
};

#endif
