#ifndef _SSG_BED_LIBRARY__RELAY_H    // Put these two lines at the top of your file.
#define _SSG_BED_LIBRARY__RELAY_H

#define RELAY_OPEN 0
#define RELAY_CLOSE 1

class Relay {
private:
  unsigned char switch_pin;
  bool status = RELAY_OPEN;

  void apply() {
    digitalWrite(switch_pin, status);
  }

public:
  void setSwitchPin(unsigned char pin) {
    switch_pin = pin;
    pinMode(pin, OUTPUT);
  }

  bool isOpen() {
    return status == RELAY_OPEN;
  }

  bool isClose() {
    return status == RELAY_CLOSE;
  }

  void open() {
    status = RELAY_OPEN;
    apply();
  }

  void close() {
    status = RELAY_CLOSE;
    apply();
  }
};

#endif