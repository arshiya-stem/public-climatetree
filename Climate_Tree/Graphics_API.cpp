#include "Graphics_API.h"

Graphics_API::Graphics_API(int cs, int dc, int mosi, int sclk, int rst)
  : lcd(cs, dc, mosi, sclk, rst)
{
  xCoordinate = graphX;

  for (int i = 0; i < numSensors; i++) {
    prevCoordinates[i] = graphY + graphHeight;
    data[i] = 0;
  }

  // Define colors
  sensorColors[0] = ST77XX_RED;
  sensorColors[1] = ST77XX_GREEN;
  sensorColors[2] = ST77XX_CYAN;
  sensorColors[3] = ST77XX_YELLOW;
  sensorColors[4] = ST77XX_MAGENTA;
  sensorColors[5] = ST77XX_WHITE;

  // Labels
  sensorLabels[0] = "D1";
  sensorLabels[1] = "D2";
  sensorLabels[2] = "D3";
  sensorLabels[3] = "D4";
  sensorLabels[4] = "D5";
  sensorLabels[5] = "D6";
}

void Graphics_API::Initialize() {
  pinMode(LCD_BLK, OUTPUT);
  digitalWrite(LCD_BLK, HIGH);

  lcd.initR(INITR_BLACKTAB);
  lcd.setRotation(1);
  lcd.fillScreen(ST77XX_BLACK);

  drawAxes();
}

void Graphics_API::drawAxes() {
  lcd.drawLine(graphX, graphY, graphX, graphY + graphHeight, ST77XX_WHITE);
  lcd.drawLine(graphX, graphY + graphHeight, graphX + graphWidth, graphY + graphHeight, ST77XX_WHITE);
  lcd.drawLine(graphX + graphWidth, graphY, graphX + graphWidth, graphY + graphHeight, ST77XX_WHITE);

  for (int i = 0; i <= 10; i++) {
    int y = graphY + i * (graphHeight / 10);
    int val = 100 - i * 10;

    lcd.setCursor(5, y - 4);
    lcd.setTextColor(ST77XX_WHITE);
    lcd.setTextSize(1);
    lcd.print(val);

    lcd.drawFastHLine(graphX + 1, y, graphWidth, ST77XX_WHITE);
  }
}

void Graphics_API::UpdateGraph(int d1, int d2, int d3, int d4) {
  int sensors[numSensors] = {d1, d2, d3, d4};

  // Reset screen if overflow
  if (xCoordinate > graphX + graphWidth) {
    xCoordinate = graphX;
    lcd.fillScreen(ST77XX_BLACK);
    drawAxes();
  }

  int y[numSensors];

  // Map values (customize ranges as needed)
  y[0] = graphY + graphHeight - map(sensors[0], 0, 100, 0, graphHeight);
  y[1] = graphY + graphHeight - map(sensors[1], 0, 100, 0, graphHeight);
  y[2] = graphY + graphHeight - map(sensors[2], 0, 100, 0, graphHeight);
  y[3] = graphY + graphHeight - map(sensors[3], 0, 100, 0, graphHeight);

  // Draw points
  for (int i = 0; i < numSensors; i++) {
    lcd.fillCircle(xCoordinate, y[i], 2, sensorColors[i]);
  }

  // Clear label area
  lcd.fillRect(graphX, graphY + graphHeight, graphWidth, 13, ST77XX_BLACK);

  // Draw labels
  for (int i = 0; i < numSensors; i++) {
    lcd.setCursor(graphX + 20 * i, graphY + graphHeight + 5);
    lcd.setTextColor(sensorColors[i]);
    lcd.setTextSize(1);
    lcd.print(sensorLabels[i]);
  }

  // Draw connecting lines
  if (xCoordinate > graphX) {
    for (int i = 0; i < numSensors; i++) {
      lcd.drawLine(xCoordinate - 20, prevCoordinates[i], xCoordinate, y[i], sensorColors[i]);
    }
  }

  // Save previous values
  for (int i = 0; i < numSensors; i++) {
    prevCoordinates[i] = y[i];
  }

  xCoordinate += 20;
}