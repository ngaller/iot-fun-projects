#ifndef BUTTONS_H
#define BUTTONS_H 1

class Button {
  int pin;
  bool is_reading;
  
  
  public:  
    Button(int pin);
    bool handleInput();
};

#endif
