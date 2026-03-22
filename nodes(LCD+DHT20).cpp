/*-----libraries-----*/
#include <Crowbits_DHT20.h>
#include <Wire.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_GFX.h>
#include <SPI.h>

/*-----pins-----*/
#define PH_PIN A0
#define LIGHT_PIN A0
#define MOISTURE_PIN A1
#define LCD_DC 16
#define LCD_CS 17
#define LCD_SCLK 18
#define LCD_MOSI 19
#define LCD_RST 22
#define LCD_BLK 23

/*-----AT commands-----*/
const char* L7 = "AT+RFS";
const char* L8 = "AT+RESET";
const char* L1 = "AT+ChannelMode=0";
const char* L2 = "AT+BAND=8,0";
const char* L3 = "AT+DevEui=70B3D57ED8004637";                  //replace with your end-device's DEV EUI
const char* L4 = "AT+AppEui=70B3D57EF0002A9C";                  //replace with your end-device's APP EUI
const char* L5 = "AT+AppKey=7852F8E3682FEEB294CBAA98678AB764";  //replace with your end-device's APP KEY
const char* L6 = "AT+JOIN=1,8";
const char* L9 = "AT+SEND=1:0:0134";
String TEXT = "AT+SEND=1:0:01";

/*----- hex strings -----*/
String Humidity_hex = "";
String Temperature_hex = "";
String Soil_Moisture_hex = "";
String Ph_hex = "";
String Light_hex = "";

/*----- variable declaration -----*/
int humidity = 0;
int temperature = 0;
int moisture = 0;
int ph = 0;
int light = 0;

const int numSensors = 4;
const uint16_t sensorColors[numSensors] = {ST77XX_RED, ST77XX_GREEN, ST77XX_CYAN, ST77XX_YELLOW};
const char* sensorLabels[numSensors]={"M", "T", "H", "Ph"};
const int graphWidth = 120;
const int graphHeight = 100;
const int graphX = 20;
const int graphY = 10;
const int maxData = graphWidth;
int xCoordinate = graphX;
int prevCoordinates[numSensors] = {graphX};
int data[numSensors]={0};

/*----- instantiate classes-----*/
Crowbits_DHT20 dht20;
Adafruit_ST7735 lcd = Adafruit_ST7735(LCD_CS, LCD_DC, LCD_MOSI, LCD_SCLK, LCD_RST);

/*----- check-----*/
void check(const char* str)
{
  if (Serial1.available()) { // Check if data is available in the serial port buffer
    String input = Serial1.readStringUntil('\n'); // read a row of data
    Serial.println(input); // If it contains, print it out
    if (input.indexOf("OK") >= 0) { // Determine whether the read data contains the "distance" string
      Serial.println("NEXT");
    } else
    {
      if (str == L1) {
        Serial1.println(L1);
        check(L1);
      }
      if (str == L2) {
        Serial1.println(L2);
        check(L2);
      }
      if (str == L3) {
        Serial1.println(L3);
        check(L3);
      }
      if (str == L4) {
        Serial1.println(L4);
        check(L4);
      }
      if (str == L5) {
        Serial1.println(L5);
        check(L5);
      }
      if (str == L6) {
        Serial1.println(L6);
        check(L6);
      } 
      }
    }
  }

/*----- intToHexString -----*/
String intToHexString(int num, int digit) {
  char hexStr[digit + 1];
  sprintf(hexStr, "%0*X", digit, num);
  return String(hexStr);
}

void drawAxes(){
  lcd.drawLine(graphX, graphY, graphX, graphY+graphHeight, ST77XX_WHITE);
  lcd.drawLine(graphX, graphY + graphHeight, graphX + graphWidth, graphY + graphHeight, ST77XX_WHITE);
  lcd.drawLine(graphX+graphWidth, graphY, graphX+graphWidth, graphY + graphHeight, ST77XX_WHITE);

  for (int i = 0; i <= 10; i++){
    int y = graphY + i * (graphHeight/10);
    int val = 100 - i * 10;
    lcd.setCursor(5, y-4);
    lcd.setTextColor(ST77XX_WHITE);
    lcd.setTextSize(1);
    lcd.print(val);
    lcd.drawFastHLine(graphX + 1, y, graphWidth, ST77XX_WHITE);
  }

  for (int i = 0; i <= 7; i++){
    int y = graphY + i * graphHeight/7;
    int val = 14 - i * 2;
    lcd.setCursor(graphWidth + graphX+ 5, y - 4);
    lcd.setTextColor(0x8410);
    lcd.setTextSize(1);
    lcd.print(val);
    lcd.drawFastHLine(graphX+ 1, y, graphWidth, 0x8410);
  }
}

/*-----setup-----*/
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Wire.setSDA(20);
  Wire.setSCL(21);
  Wire.begin();
  dht20.begin();
  pinMode(LCD_BLK, OUTPUT);
  digitalWrite(LCD_BLK, HIGH);
  lcd.initR(INITR_BLACKTAB);
  lcd.setRotation(1);
  lcd.fillScreen(ST77XX_BLACK);

  Serial1.println(L7);
  delay(3000);
  Serial1.println(L8);
  delay(3000);

  Serial1.println(L1);
  check(L1);
  delay(1000);
  Serial1.println(L2);
  check(L2);
  delay(1000);
  Serial1.println(L3);
  check(L3);
  delay(1000);
  Serial1.println(L4);
  check(L4);
  delay(1000);
  Serial1.println(L5);
  check(L5);
  delay(1000);
  Serial1.println(L6);
  check(L6);
  delay(6000);
  lcd.println("OTAA connection successful!\nBeginning transmission...");
  delay(6000);
lcd.fillScreen(ST77XX_BLACK);

  drawAxes();
}

void loop() {
  /*-----Moisture Sensor-----*/
  moisture = analogRead(MOISTURE_PIN);           //read input from pin                           //write the input into Serial
  Soil_Moisture_hex = intToHexString(moisture, 4);  //turn input into hexstring
  data[0] = moisture;

  /*-----Temperature/Humidity Sensor (DHT20)-----*/
  temperature = dht20.getTemperature();              //get temperature from I2C pin
  humidity = dht20.getHumidity();                    //get humidity from I2C pin                         
  Temperature_hex = intToHexString(temperature, 4);  //turn temperature into hexstring
  Humidity_hex = intToHexString(humidity, 4);        //turn humidity into hexstring
  data[1] = temperature;
  data[2] = humidity;

  /*----- PH Sensor -----*/
  ph = 7-1000*(analogRead(PH_PIN)-360)*4.95/59.16/1023;
  Ph_hex = intToHexString(ph, 4);
  data[3] = ph;

  /*-----Light Sensor-----*/
  /*
  light = analogRead(LIGHT_PIN);
  Light_hex = intToHexString(light, 4);
  data[3] = light;
  */

  /*-----Graphing-----*/

  if (xCoordinate > graphWidth + graphX){
    xCoordinate = graphX;
    lcd.fillScreen(ST77XX_BLACK);
    drawAxes();
  }

  int sensors[numSensors];
  sensors[0] = moisture; 
  sensors[1] = temperature;
  sensors[2] = humidity;
  sensors[3] = ph;

  int y1 = graphY + graphHeight - map(sensors[0],0,100,0,graphHeight);
  int y2 = graphY + graphHeight - map(sensors[1],0,100,0,graphHeight);
  int y3 = graphY + graphHeight - map(sensors[2],0,100,0,graphHeight);
  int y4 = graphY + graphHeight - map(sensors[3],0,14,0,graphHeight);

  lcd.fillCircle(xCoordinate, y1, 2, sensorColors[0]);
  lcd.fillCircle(xCoordinate, y2, 2, sensorColors[1]);
  lcd.fillCircle(xCoordinate, y3, 2, sensorColors[2]);
  lcd.fillCircle(xCoordinate, y4, 2, sensorColors[3]);

  lcd.fillRect(graphX, graphY + graphHeight, 120, 13, ST77XX_BLACK);
  
  for (int i = 0; i<numSensors; i++){
    lcd.setCursor(graphX + 30*i, graphY + graphHeight + 5);
    lcd.setTextColor(sensorColors[i]);
    lcd.setTextSize(1);
    lcd.print(sensorLabels[i]);
    lcd.print(":");
    lcd.print((String)data[i]);
  }

  if (xCoordinate > graphX){
    lcd.drawLine(xCoordinate-20, prevCoordinates[0], xCoordinate, y1, sensorColors[0]);
    lcd.drawLine(xCoordinate-20, prevCoordinates[1], xCoordinate, y2, sensorColors[1]);
    lcd.drawLine(xCoordinate-20, prevCoordinates[2], xCoordinate, y3, sensorColors[2]);
    lcd.drawLine(xCoordinate-20, prevCoordinates[3], xCoordinate, y4, sensorColors[3]);
  }

  prevCoordinates[0] = y1;
  prevCoordinates[1] = y2;
  prevCoordinates[2] = y3;
  prevCoordinates[3] = y4;

  xCoordinate += 20;

  /*-----Timer-----*/
  delay(1000);

  String Send_hex = TEXT + Soil_Moisture_hex + Temperature_hex + Humidity_hex + Ph_hex;  //turn all data into one string
  Serial1.println(Send_hex);                                                             //write the string into Serial1
}
