#ifndef THERMOCOUPLE_SENSOR_API
#define THERMOCOUPLE_SENSOR_API

#include <Arduino.h>
#include "High_Temp.h"

class Thermocouple_Sensor_API {
  private:
    int pin1;
    int pin2;
    HighTemp sensor;
  public:
    Thermocouple_Sensor_API(int analog_pin1, int analog_pin2);

    void Initialize();

    float ReadTemperature();
};

#endif