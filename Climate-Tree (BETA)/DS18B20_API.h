#ifndef DS18B20_API_H
#define DS18B20_API_H

#include <Arduino.h>
#include <7semi_DS18B20.h>   // Make sure this is the correct library header

/**
 * @class DS18B20_API
 * @brief Wrapper class for interfacing with a DS18B20 temperature sensor
 * 
 * Handles:
 * - Sensor initialization
 * - Reading temperature values
 */
class DS18B20_API {
  private:
    /// @brief Digital pin connected to the DS18B20 data line
    int pin;

    /// @brief 64-bit unique address of the DS18B20 sensor
    uint8_t sensor_addr[8];

    /// @brief Sensor object from 7semi library
    DS18B20_7semi sensor;

  public:
    /**
     * @brief Constructor
     * 
     * @param digital_pin GPIO pin connected to the sensor
     */
    DS18B20_API(int digital_pin);

    /**
     * @brief Initializes the sensor and retrieves its address
     */
    void Initialize();

    /**
     * @brief Reads temperature from the sensor
     * 
     * @return Temperature in degrees Celsius
     */
    float ReadTemperature();
};

#endif