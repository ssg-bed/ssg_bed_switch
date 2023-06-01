#include "relay.h"

Relay relay = Relay();

void setup() {
  relay.setSwitchPin(3);
  relay.open();
}

void loop() {
  delay(1000);
  relay.open();
  delay(1000);
  relay.close();
}