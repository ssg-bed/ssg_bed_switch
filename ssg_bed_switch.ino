#include <string.h>
#include "relay.h"
#include "serial.h"

Relay *relay;
SerialHandler *serial_handler;

void setup() {
  SoftwareSerialBuilder *builder;
  SoftwareSerial *serial;

  relay = new Relay();
  relay->setSwitchPin(2);

  builder = new SoftwareSerialBuilder();
  builder->setRxPin(3);
  builder->setTxPin(4);
  builder->setBaudRate(9600);

  serial = builder->buildAndListen();
  serial_handler = new SerialHandler(serial);

  free(builder);

  Serial.begin(9600);
}

void loop() {
  const char *data = serial_handler->receive();
  if (strcmp(data, "INSLEEP=FALSE") == 0) {
    relay->close();
    Serial.println("[received] insleep: false");
  }
  else if (strcmp(data, "INSLEEP=TRUE") == 1) {
    relay->open();
    Serial.println("[received] insleep: true");
  }
  delay(100);
}