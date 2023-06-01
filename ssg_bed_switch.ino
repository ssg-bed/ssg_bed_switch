#include <string.h>

#include <Wire.h>
#include <IRremote.h>

#include "relay.h"

#define PIN_RELAY 2
#define WIRE_ADDR 8

Relay relay = Relay();
char buffer[128];

void setup() {
  relay.setSwitchPin(PIN_RELAY);

  Wire.begin(WIRE_ADDR);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  delay(100);
}

void receiveEvent(int howMany) {
  int i = 0;
  while (Wire.available()) {
    buffer[i++] = Wire.read();
  }
  buffer[i] = '\0';

  Serial.println(buffer);

  if (strcmp(buffer, "INSLEEP=FALSE") == 0) {
    relay.open(); // TURN LIGHT ON
  }
  if (strcmp(buffer, "INSLEEP=TRUE") == 0) {
    relay.close(); // TURN LIGHT OFF
  }
}