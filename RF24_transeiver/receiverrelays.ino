#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial SerialPi(10, 11); // RX, TX pins
int command;

void setup() {
  Serial.begin(9600);
  SerialPi.begin(9600);
}

void loop() {
  if (SerialPi.available() > 0) {
    command = SerialPi.parseInt();
    Serial.println("Received command: " + String(command));
    executeCommand(command);
  }
}

void executeCommand(int command) {
  switch (command) {
    case 1:
      // Execute the first sketch stored in Raspberry Pi's Arduino
      Serial.println("Executing Sketch 1");
      // Add your code to execute Sketch 1 here
      break;
    // Add more cases for additional commands and corresponding sketches
    default:
      Serial.println("Invalid command");
      break;
  }
}
