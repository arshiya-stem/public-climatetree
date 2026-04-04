#ifndef MOISTURE_SENSOR_API_H
#define MOISTURE_SENSOR_API_H

#include <Arduino.h>

/**
 * @class Moisture_Sensor_API
 * @brief Interface for reading soil moisture levels from an analog sensor
 * 
 * This class abstracts:
 * - Reading analog values from a moisture sensor
 * - Returning a usable moisture level (raw or scaled)
 */
class Moisture_Sensor_API {
  private:
    /// @brief Analog pin connected to the moisture sensor output
    int pin;

  public:
    /**
     * @brief Constructor
     * 
     * @param analog_pin The analog input pin connected to the sensor
     */
    Moisture_Sensor_API(int analog_pin);

    /**
     * @brief Reads the soil moisture level
     * 
     * @return A float representing moisture level 
     *         (raw ADC value or scaled percentage depending on implementation)
     */
    float ReadMoisture();
};

#endif