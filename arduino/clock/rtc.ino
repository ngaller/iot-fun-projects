static time_t last_update = 0;
static DS3231 rtc;

bool rtc_need_update() {
  return last_update < millis() - 1000;
}

void rtc_increase() {
  int min = rtc.getMinute() + 1;
  bool r;
  int hour = rtc.getHour(r, r);  
  if(min >= 60) {
    min = 0;
    hour = hour + 1;
  }
  if(hour >= 24) {
    hour = 0;
  }
  rtc.setMinute(min);
  rtc.setHour(hour);
  last_update = 0;
}

void rtc_decrease() {
  int min = rtc.getMinute() - 1;
  bool r;
  int hour = rtc.getHour(r, r);
  if(min <= -1) {
    min = 59;
    hour = hour - 1;
  }
  if(hour <= -1) {
    hour = 23;
  }
  rtc.setMinute(min);
  rtc.setHour(hour);
  last_update = 0;
}

void rtc_get_time(int& hour, int& min) {
  bool r;
  hour = rtc.getHour(r, r);
  min = rtc.getMinute();
  last_update = millis();
}
