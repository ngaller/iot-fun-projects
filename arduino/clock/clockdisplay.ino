#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();

void setup_display() {
  matrix.begin(0x70);
  delay(500);
  matrix.print(8888, DEC);
  matrix.writeDisplay();
}


void write_time(int hours, int minutes) { 
  matrix.writeDigitNum(0, hours / 10, false);
  matrix.writeDigitNum(1, hours % 10, false);
  matrix.drawColon(true);
  matrix.writeDigitNum(3, minutes / 10, false);
  matrix.writeDigitNum(4, minutes % 10, false);
  matrix.writeDisplay();
}
