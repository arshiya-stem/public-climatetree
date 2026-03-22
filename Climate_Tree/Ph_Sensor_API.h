#ifndef PH_SENSOR_API
#define PH_SENSOR_API

#include <Arduino.h>

class Ph_Sensor_API {
  private:
    int pin;
  public:
    Ph_Sensor_API(int analog_pin);
    float ReadPH();
};

#endif 