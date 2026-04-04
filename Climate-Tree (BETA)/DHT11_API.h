#ifndef DHT11_API_H
#define DHT11_API_H

#include "DHT.h" // Library for DHT11/DHT22 sensors

/// @brief Wrapper API for interfacing with a DHT11 temperature & humidity sensor
class DHT11_API {
  private:
    int pin;        ///< GPIO pin connected to the DHT11 data line
    DHT sensor;     ///< DHT sensor object (from DHT library)

  public:
    /// @brief Constructor
    /// @param digital_pin GPIO pin where the DHT11 is connected
    /// @note You will also need to specify the sensor type (DHT11) in the .cpp
    DHT11_API(int digital_pin);

    /// @brief Initializes the sensor
    /// @note Should call sensor.begin() in implementation
    void Initialize();

    /// @brief Reads temperature from the sensor
    /// @return Temperature in degrees Celsius (°C)
    float ReadTemperature();

    /// @brief Reads humidity from the sensor
    /// @return Relative humidity in percentage (%)
    float ReadHumidity();
};

#endif