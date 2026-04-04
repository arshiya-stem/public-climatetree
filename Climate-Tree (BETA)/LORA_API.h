#ifndef LORA_API_H
#define LORA_API_H

#include <Arduino.h>

/**
 * @class LORA_API
 * @brief Simple wrapper for sending AT commands to a LoRa module (e.g., LR1262)
 * 
 * Handles:
 * - Initialization (join network, set keys)
 * - Sending data packets
 */
class LORA_API {
  private:
    /// @brief Device EUI (unique identifier for LoRa device)
    String devEUI;

    /// @brief Application EUI (LoRaWAN application identifier)
    String appEUI;

    /// @brief Application Key (used for OTAA join authentication)
    String appKey;

    /**
     * @brief Sends an AT command and waits until "OK" is received
     * 
     * @param command The AT command string to send to the LoRa module
     */
    void Check_Connection(const String &command);

    /**
     * @brief Converts an integer into a zero-padded hexadecimal string
     * 
     * Example: IntToHexString(21, 4) → "0015"
     * 
     * @param data Integer value to convert
     * @param num_hex_digits Number of hex digits (padding length)
     * @return Hexadecimal string representation
     */
    String IntToHexString(int data, int num_hex_digits);

  public:
    /**
     * @brief Constructor to initialize LoRa credentials
     * 
     * @param n_devEUI Device EUI
     * @param n_appEUI Application EUI
     * @param n_appKey Application Key
     */
    LORA_API(String n_devEUI, String n_appEUI, String n_appKey);

    /**
     * @brief Initializes the LoRa module
     * 
     * Sends required AT commands:
     * - Set channel mode
     * - Set band
     * - Configure DevEUI, AppEUI, AppKey
     * - Join network
     */
    void Initialize();

    /**
     * @brief Sends a formatted data packet over LoRa
     * 
     * @param sensor_data1 data recieved from one of the sensors
     * @param sensor_data2 data recieved from one of the sensors
     * @param sensor_data3 data recieved from one of the sensors
     * @param sensor_data4 data recieved from one of the sensors
     *
     * Encodes integers into hex and transmits using AT+SEND
     */
    void Send_Data(int sensor_data1, int sensor_data2, int sensor_data3, int sensor_data4);
};

#endif