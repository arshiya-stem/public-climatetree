#ifndef DHT20_API_H
#define DHT20_API_H

#include <DHT20.h>   // Library for the DHT20 temperature & humidity sensor

/// @brief Simple wrapper API for the DHT20 sensor
class DHT20_API {
  private:
    DHT20 sensor;  ///< Instance of the DHT20 sensor object

  public:
    /// @brief Constructor
    /// Initializes the DHT20 sensor (implementation should call sensor.begin())
    DHT20_API();

    /// @brief initializes the sensor
    void Initialize();

    /// @brief Reads temperature from the sensor
    /// @return Temperature in degrees Celsius
    float ReadTemperature();

    /// @brief Reads humidity from the sensor
    /// @return Relative humidity in percentage (%)
    float ReadHumidity();
};

#endif