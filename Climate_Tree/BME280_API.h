#ifndef BME280_API_H
#define BME280_API_H

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEA_LEVEL_PRESSURE 1013.25

class BME280_API {
  private:
    Adafruit_BME280 sensor;
  
  public:
    BME280_API();

    void Initialize();

    float ReadTemperature();
    float ReadHumidity();
    float ReadPressure();
    float ReadAltitude();
};

#endif