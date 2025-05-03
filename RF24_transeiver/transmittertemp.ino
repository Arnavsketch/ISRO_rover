#include <DHT.h>
#include <RH_ASK.h>
#include <SPI.h>

#define DHTPIN 2      // Pin where the DHT11 is connected
#define DHTTYPE DHT11 // DHT 11

#define RF_DATA_PIN 5
//#define RF_TRANSMIT_LED 

DHT dht(DHTPIN, DHTTYPE);
RH_ASK rf_driver;

void setup() {
  Serial.begin(9600);
  dht.begin();
  if (!rf_driver.init()) {
    Serial.println("RF driver init failed!");
  }
}

void loop() {
  delay(2000); // Wait a few seconds between measurements.

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Convert temperature and humidity to strings
  char data[10];
  dtostrf(temperature, 4, 2, data);
  dtostrf(humidity, 4, 2, data + 5);

  // Send temperature and humidity data via RF
  rf_driver.send((uint8_t*)data, strlen(data));
  rf_driver.waitPacketSent();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

}