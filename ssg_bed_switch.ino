#include <string.h>
#include "relay.h"
#include <SoftwareSerial.h>

Relay relay = Relay();
SoftwareSerial mySerial(10, 11);
int i;
char buffer[1024];

void setup() {
  relay.setSwitchPin(2);

  Serial.begin(9600);
  mySerial.begin(9600);

  mySerial.write("AT");
}

void loop() {
  if (Serial.available()) {
    while (Serial.available()) {
      mySerial.write(Serial.read());
    }
  }

  delay(100);

  for (i = 0; mySerial.available(); i++) {
    buffer[i] = mySerial.read();
    Serial.write(buffer[i]);
  }
  buffer[i] = '\0';

  if (strcmp(buffer, "INSLEEP=FALSE") == 0) {
    relay.close();
    Serial.println("[received] insleep: false");
  }
  else if (strcmp(buffer, "INSLEEP=TRUE") == 0) {
    relay.open();
    Serial.println("[received] insleep: true");
  }
  delay(100);
}