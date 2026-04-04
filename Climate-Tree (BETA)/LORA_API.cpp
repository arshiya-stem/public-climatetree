#include "LORA_API.h"

/// Commands array (must be defined in .cpp)
const String COMMANDS[10] = {
  "AT+RFS",
  "AT+RESET",
  "AT+ChannelMode=0",
  "AT+BAND=8,0",
  "AT+DevEui=",
  "AT+AppEui=",
  "AT+AppKey=",
  "AT+JOIN=1,8",
  "AT+SEND=1:0:0134"
};

void LORA_API::Check_Connection(const String &command) {
  Serial1.println(command);

  while (true) {
    String input = Serial1.readStringUntil('\n');

    if (input.indexOf("OK") >= 0) {
      break;
    }
  }
}

String LORA_API::IntToHexString(int num, int digit) {
  char hexStr[digit + 1];
  sprintf(hexStr, "%0*X", digit, num);
  return String(hexStr);
}

LORA_API::LORA_API(String n_devEUI, String n_appEUI, String n_appKey) 
: devEUI(n_devEUI), appEUI(n_appEUI), appKey(n_appKey) {}

void LORA_API::Initialize() {
  Check_Connection(COMMANDS[2]);
  Check_Connection(COMMANDS[3]);
  Check_Connection(COMMANDS[4] + devEUI);
  Check_Connection(COMMANDS[5] + appEUI);
  Check_Connection(COMMANDS[6] + appKey);
  Check_Connection(COMMANDS[7]);

  Serial.println("Initialization Successful!");
}

void LORA_API::Send_Data(int sensor_data1, int sensor_data2, int sensor_data3, int sensor_data4) {
  String send = "AT+SEND=1:0:01" 
                + IntToHexString(sensor_data1, 4) 
                + IntToHexString(sensor_data2, 4)
                + IntToHexString(sensor_data3, 4) 
                + IntToHexString(sensor_data4, 4);

  Serial1.println(send);
}
