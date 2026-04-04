#ifndef HTU21D_API_H
#define HTU21D_API_H

#include <Arduino.h>           // Core Arduino functions
#include <SparkFunHTU21D.h>   // HTU21D sensor library

/// @brief API wrapper for the HTU21D temperature & humidity sensor (I2C)
class HTU21D_API {
  private:
    HTU21D sensor;   ///< Instance of the HTU21D sensor object

  public:
    /// @brief Constructor
    /// @note Sensor initialization should be done in Initialize()
    HTU21D_API();

    /// @brief Initializes the sensor and I2C communication
    /// @note Should call Wire.begin() and sensor.begin() in implementation
    void Initialize();

    /// @brief Reads temperature from the sensor
    /// @return Temperature in degrees Celsius (°C)
    float ReadTemperature();

    /// @brief Reads humidity from the sensor
    /// @return Relative humidity in percentage (%)
    float ReadHumidity();
};

#endif