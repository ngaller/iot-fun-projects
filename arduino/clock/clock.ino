#include <DS3231.h>
#include <Wire.h>
#include <Time.h>
#include <TimeLib.h>

#include "buttons.h"

#define UP_BUTTON 2
#define DOWN_BUTTON 3

Button up = Button(UP_BUTTON);
Button down = Button(DOWN_BUTTON);

/* 
* V1 of the clock, using the RTC module, but without buttons to set it
*/
void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Clock Test\n");
  setup_display();
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
  if(up.handleInput()) {
    rtc_increase();
  }
  if(down.handleInput()) {
    rtc_decrease();
  }
  // put your main code here, to run repeatedly:  
  if(rtc_need_update()) {
    int hour, min;
    rtc_get_time(hour, min);
    write_time(hour, min);
  }  
  delay(300);
}
