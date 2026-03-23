#include "Ph_Sensor_API.h"

Ph_Sensor_API::Ph_Sensor_API(int analog_pin) : pin(analog_pin) {}

float Ph_Sensor_API::ReadPH() {
  return 7 - 1000.0 * (analogRead(pin) - 361) * 3.3 / 59.16 / 4095.0;
}
