#include <RH_ASK.h>
#include <SPI.h>

#define RF_DATA_PIN 8  // RF receiver data pin

RH_ASK rf_driver;

void setup() {
  Serial.begin(9600);
  if (!rf_driver.init()) {
    Serial.print("RF driver init failed!");
  }
}

void loop() {
  uint8_t buf[10];
  uint8_t buflen = sizeof(buf);

  if (rf_driver.recv(buf, &buflen)) {
    buf[buflen] = '\0'; // Null terminate the received data
    float temperature = digitalRead(RF_DATA_PIN);                                //atof((char*)buf);
    float humidity = atof((char*)buf + 5);

    Serial.println("Received temperature: ");
    Serial.println(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  delay(500);
}