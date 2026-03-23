#ifndef LIGHT_SENSOR_API_H
#define LIGHT_SENSOR_API_H

#include <Arduino.h>

/**
 * @class Light_Sensor_API
 * @brief Interface for reading ambient light levels from an analog light sensor
 * 
 * This class abstracts:
 * - Reading raw analog values
 * - Converting them into a usable light/ambience measurement
 */
class Light_Sensor_API {
  private:
    /// @brief Analog pin connected to the light sensor output
    int pin;

  public:
    /**
     * @brief Constructor
     * 
     * @param analog_pin The analog input pin connected to the sensor
     */
    Light_Sensor_API(int analog_pin);

    /**
     * @brief Reads the ambient light level
     * 
     * @return A float representing the light level 
     *         (could be raw ADC value or scaled depending on implementation)
     */
    float ReadAmbience();
};

#endif