#include "buttons.h"

Button::Button(int pin) {
  pinMode(pin, INPUT);
  this->pin = pin;
  this->is_reading = false;
}

bool Button::handleInput() {
  if(digitalRead(pin)== HIGH) {
    return true;
    /*
    if(!this->is_reading) {
      this->is_reading = true;
      return true;
    }
    */    
  } else {
    // LOW
    this->is_reading = false;
  }
  return false;
}
