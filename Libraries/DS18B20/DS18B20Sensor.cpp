/**
* @file DS18B20Sensor.cpp
* @brief Wrapper for the OneWireDrv library by Frederic Blanc.
* @author Steve Spence (Published 3 March 2013 www.mbed.org)
*/
#include "DS18B20Sensor.h"

DS18B20Sensor::DS18B20Sensor(PinName pin) : _oneWirePort(pin)
{
    _init = false;
    nSensors = 0;
}

void DS18B20Sensor::getReading(char * text, uint8_t index)
{
    uint8_t subzero, cel, cel_frac_bits;
    DS18X20_read_meas( &gSensorIDs[index][0], &subzero, &cel, &cel_frac_bits);
    DS18B20Sensor::getReading(text, subzero, cel, cel_frac_bits);
}

void DS18B20Sensor::getReading(char * text, uint8_t subzero, uint8_t cel, uint8_t cel_frac_bits)
{
    uint16_t decicelsius;
    char s[10];
    float temperature;
    sprintf(text,"");
    sprintf(s,"%s", (subzero)?"-":"+");
    strcat(text,s);
    decicelsius = DS18X20_temp_to_decicel(subzero, cel, cel_frac_bits);
    temperature = decicelsius;
    temperature = temperature/10;
    sprintf(s,"%4.1f", temperature);
    strcat(text,s);

}

uint8_t DS18B20Sensor::search(void)
{
    search_sensors(&nSensors, &gSensorIDs[0][0]);
    _init = true;
    return nSensors;
}

uint8_t DS18B20Sensor::count(void)
{
    if (_init==false)
        DS18B20Sensor::search();
    return nSensors;
}

uint8_t DS18B20Sensor::startReading(bool includeWait)
{
    uint8_t r = DS18X20_start_meas(DS18X20_POWER_EXTERN, 0 );
    if ((r == DS18X20_OK) && includeWait)
        wait_ms(DS18B20_TCONV_12BIT);
    return r;
}

void DS18B20Sensor::getReading(uint8_t index, uint8_t *subzero, uint8_t *cel, uint8_t *cel_frac_bits)
{
    DS18X20_read_meas( &gSensorIDs[index][0], subzero, cel, cel_frac_bits);
}
