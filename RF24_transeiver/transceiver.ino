#include <SPI.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 8

const byte address[6] = "00001";

RF24 radio(CE_PIN, CSN_PIN);

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char receivedMessage[32] = "";
    radio.read(&receivedMessage, sizeof(receivedMessage));
    Serial.print("Received: ");
    Serial.println(receivedMessage);
  }
  
  if (Serial.available()) {
    char sendMessage[32] = "";
    Serial.readBytesUntil('\n', sendMessage, sizeof(sendMessage));
    radio.stopListening();
    radio.write(&sendMessage, sizeof(sendMessage));
    radio.startListening();
    Serial.print("Sent: ");
    Serial.println(sendMessage);
  }
}
