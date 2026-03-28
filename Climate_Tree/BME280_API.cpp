#include "BME280_API.h"

BME280_API::BME280_API() {}

void BME280_API::Initialize() {
  if (!sensor.begin()) {
     Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(sensor.sensorID(),16);
        Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");
        while (1) delay(10);
  }
}

float BME280_API::ReadTemperature() {
  float temperature = sensor.readTemperature();
  Serial.println("Temperature (BME280): " + (String)temperature + " °C");
  return temperature;
}

float BME280_API::ReadHumidity() {
  float humidity = sensor.readHumidity();
  Serial.println("Humidity (BME280): " + (String)humidity + " %");
  return humidity;
}

float BME280_API::ReadPressure() {
  float pressure = sensor.readPressure() / 100.0;
  Serial.println("Pressure (BME280): " + (String)pressure + " hPa");
  return pressure;
}

float BME280_API::ReadAltitude() {
  float altitude = sensor.readAltitude(SEA_LEVEL_PRESSURE);
  Serial.println("Altitude (BME280): " + (String)altitude + " m");
  return altitude;
}


