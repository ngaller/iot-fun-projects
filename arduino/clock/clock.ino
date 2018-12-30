#include <DS3231.h>
#include <Wire.h>
#include <Time.h>
#include <TimeLib.h>

#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"


Adafruit_7segment matrix = Adafruit_7segment();
DS3231 rtc;

void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Clock Test\n");
  matrix.begin(0x70);
  delay(500);
  
  matrix.print(8888, DEC);
  matrix.writeDisplay();
  //rtc.setClockMode(false);
  //rtc.setYear(18);  
  //rtc.setMonth(12);
  //rtc.setDate(22);
  //rtc.setHour(9);
  //rtc.setMinute(47);
  //rtc.setSecond(20);  
  //Serial.println(rtc.getYear());

}

void loop() {
  // put your main code here, to run repeatedly:  
  bool r;
  writeTime(rtc.getHour(r, r), rtc.getMinute());
  delay(1000);
}

void writeTime(int hours, int minutes) { 
    matrix.writeDigitNum(0, hours / 10, false);
    matrix.writeDigitNum(1, hours % 10, false);
    matrix.drawColon(true);
    matrix.writeDigitNum(3, minutes / 10, false);
    matrix.writeDigitNum(4, minutes % 10, false);
  matrix.writeDisplay();
}
