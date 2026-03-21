#ifndef _SENSOR_H
#define _SENSOR_H

#include "mbed.h"
#include "DS18X20.h"
#include "onewire.h"
 
/** DS18B20Sensor class.
 *  A wrapper class for the DS18B20 (temperature sensor) and onewire 'c' library.
 *  Based on the OneWireDrv Library by Frederic Blanc. Many thanks to him for making this code available.
 *  
 * Simple Example:
 * @code
#include "mbed.h"
#include "DS18B20Sensor.h"

// Instantiate sensor with hardware in pin p30 
DS18B20Sensor sensor(p30);

// Setup a window to the world
Serial pc(p13, p14);
//Serial pc(USBTX, USBRX);
 
int main()
{
   char sensorBuf[25];
 
   // count will search for sensors, if not already called
   pc.printf("Found %d sensor/s\r", sensor.count());
 
   uint8_t result = sensor.startReading(true);     // start sensor readings and wait
 
   for (uint8_t i = 0; i < sensor.count(); i++) {
      sensor.getReading(sensorBuf, i);         // get result into buf
      pc.printf("Sensor %d : %s\r", i+1, sensorBuf);  // display it to the world
   }
 
}
 * @endcode
 */
class DS18B20Sensor
{
public:
    /** Create DS18B20Sensor instance
    * @param pin The pin number used by the onewire bus.
    */
    DS18B20Sensor(PinName pin);

    /** Copies the sensor results into the parameter text.
    * @param text The target text buffer.
    * @param index The sensor number.
    */
    void getReading(char * text, uint8_t index);

    /** Copies the sensor results into the parameter text.
    * @param text The target text buffer.
    * @param subzero 1 for less than zero.
    * @param cel Degrees Cel
    * @param cel Degrees fraction
    */
    void getReading(char * text, uint8_t subzero, uint8_t cel, uint8_t cel_frac_bits);

    /** Gets the sensors reading results.
    * @param index The sensor number.
    * @param subzero Returns 1 if less than zero.
    * @param cel Returns degrees Cel
    * @param cel Returns degrees fraction
    */
    void getReading(uint8_t index, uint8_t *subzero, uint8_t *cel, uint8_t *cel_frac_bits);

    /** This searches for sensors on the onewire bus.
    *   It can also invoked by just using count()
    *   @returns The number of sensors found on the bus.
    */
    uint8_t search(void);

    /** Starts the sensors reading.
    * @param includeWait If true, the method will wait the specified time for the sensors to complete the reading.
    * @returns
        DS18X20_OK on success,
        Other values in DS18X20.h on failure.
    */
    uint8_t startReading(bool includeWait = true);

    /** If search() was not called before this, then search() is invoked.
    *   @returns The number of sensors found on the bus.
    */
    uint8_t count(void);

protected:

    DigitalInOut _oneWirePort;
    uint8_t gSensorIDs[MAXSENSORS][OW_ROMCODE_SIZE];
    uint8_t nSensors;
    bool _init;

};

#endif // file
