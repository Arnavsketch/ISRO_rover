#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Define the pipes for communication
const uint64_t pipe = 0xE8E8F0F0E1LL; // Use the same on both transmitter and receiver

// Initialize the RF24 module
RF24 radio(9, 10); // Set CE, CSN pins

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, pipe); // Open a reading pipe
  radio.startListening(); // Start listening for data
}

void loop() {
  if (radio.available()) {
    int data;
    radio.read(&data, sizeof(data)); // Read the data sent by transmitter
    Serial.println("Data received: " + String(data));
    if (data == 1) {
      Serial.println("Received: 1");
    } else {
      Serial.println("Received: 0");
    }
  }
}
