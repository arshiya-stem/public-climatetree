/*

*/

#include <Wire.h>

#include "LORA_API.h"
#include "DS18B20_API.h"
#include "DHT20_API.h"
#include "DHT11_API.h"
#include "Light_Sensor_API.h"
#include "Ph_Sensor_API.h"
#include "Water_Level_Sensor_API.h"
#include "HTU21D_API.h"
#include "BME280_API.h"
//#include "Thermocouple_Sensor_API.h"
#include "Graphics_API.h"

#define NOT_BEING_USED 255
#define SECOND_TO_MILLISECOND 1000

///@brief Pins
#define D0 14
#define D1 15
#define A0 A0
#define A1 A1
#define LCD_DC 16
#define LCD_CS 17
#define LCD_SCLK 18
#define LCD_MOSI 19
#define LCD_RST 22


LORA_API lora("devEUI", "appEUI", "appKey");    // <-- replace parameters with TTN info
Graphics_API display(LCD_CS, LCD_DC, LCD_MOSI, LCD_SCLK, LCD_RST);

//DSB1820_API ds18b20(D#);
//DHT20_API dht20;
//DHT11_API dht11(D#);
//Light_Sensor_API light(A#);
//Ph_Sensor_API ph(A#);
//Water_Level_Sensor_API waterlevel(D#, false);
//Water_Level_Sensor_API waterlevel(A#, true);
//Moisture_Sensor_API moisture(A#);
//HTU21D_API htu21d;
//BME280_API bme280;
//Thermocouple_Sensor_API thermocouple;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  Wire.setSDA(20);
  Wire.setSCL(21);
  Wire.begin();
  pinMode(D0, INPUT_PULLDOWN);
  pinMode(D1, INPUT_PULLDOWN);
  
  lora.Initialize();
  display.Initialize();

  //ds18b20.Initialize();
  //dht20.Initialize();
  //dht11.Initialize();
  //htu21d.Initialize();
  //bme280.Initialize();

}

void loop() {
  // put your main code here, to run repeatedly:
  
  float data1 = NOT_BEING_USED;
  float data2 = NOT_BEING_USED;
  float data3 = NOT_BEING_USED;
  float data4 = NOT_BEING_USED;

  lora.Send_Data(data1, data2, data3, data4);
  display.UpdateGraph(data1, data2, data3, data4);
  
  delay(5 * SECOND_TO_MILLISECOND); //time in milliseconds

}
