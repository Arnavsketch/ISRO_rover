#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN pins
const uint64_t pipe = 0xE8E8F0F0E1LL; // Change this address for each pair of modules
int command = 0;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop() {
  // Example: Send command when button is pressed
  if (digitalRead(2) == HIGH) {
    command = 1; // Change this command value based on your requirement
    radio.write(&command, sizeof(command));
    Serial.println("Command sent: " + String(command));
    delay(1000); // Add a delay to avoid sending multiple commands rapidly
  }
}
