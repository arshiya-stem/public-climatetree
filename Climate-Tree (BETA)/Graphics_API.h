#ifndef GRAPHICS_API_H
#define GRAPHICS_API_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#define LCD_BLK 23

/// @brief API for displaying multiple sensor values on an ST7735 LCD graph
class Graphics_API {
  private:
    static const int numSensors = 4;

    Adafruit_ST7735 lcd;

    // Graph settings
    const int graphWidth = 120;
    const int graphHeight = 100;
    const int graphX = 20;
    const int graphY = 10;

    int xCoordinate;
    int prevCoordinates[numSensors];
    int data[numSensors];

    uint16_t sensorColors[numSensors];
    const char* sensorLabels[numSensors];

    void drawAxes();

  public:
    /// @brief Constructor
    /// @param cs Chip select pin
    /// @param dc Data/command pin
    /// @param mosi MOSI pin
    /// @param sclk Clock pin
    /// @param rst Reset pin
    Graphics_API(int cs, int dc, int mosi, int sclk, int rst);

    /// @brief Initialize LCD and graph
    void Initialize();

    /// @brief Update graph with new sensor values
    /// @param d1–d6 Sensor values (int for simplicity)
    void UpdateGraph(int d1, int d2, int d3, int d4);
};

#endif