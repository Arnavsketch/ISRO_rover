int relayPins[] = {2, 3, 4, 5}; // Define the relay pins

void setup() {
  // Initialize relay pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], LOW); // Initially turn off all relays
  }
  Serial.begin(9600); // Start serial communication
}

void loop() {
  // Read incoming serial data
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'f') {
      // Forward motion: Even pins high, odd pins low
      for (int i = 0; i < 4; i++) {
        digitalWrite(relayPins[i], i % 2 == 0 ? HIGH : LOW);
      }
    } else if (command == 'r') {
      // Reverse motion: Even pins low, odd pins high
      for (int i = 0; i < 4; i++) {
        digitalWrite(relayPins[i], i % 2 == 0 ? LOW : HIGH);
      }
    } else if (command == 'l') {
      // All low: Turn off all relays
      for (int i = 0; i < 4; i++) {
        digitalWrite(relayPins[i], LOW);
      }
    } else if (command == 'o') {
      // All off: Turn off all relays
      for (int i = 0; i < 4; i++) {
        digitalWrite(relayPins[i], LOW);
      }
    } else if (command == 'h') {
      // All high: Turn on all relays
      for (int i = 0; i < 4; i++) {
        digitalWrite(relayPins[i], HIGH);
      }
    } else if (command == 'L') {
      // Left configuration: Specific pins high and low
      digitalWrite(relayPins[0], HIGH);
      digitalWrite(relayPins[1], LOW);
      digitalWrite(relayPins[2], HIGH);
      digitalWrite(relayPins[3], LOW);
      digitalWrite(relayPins[4], HIGH);
      digitalWrite(relayPins[5], LOW);
      
    } else if (command == 'R') {
      // Right configuration: Specific pins high and low
      digitalWrite(relayPins[0], LOW);
      digitalWrite(relayPins[1], HIGH);
      digitalWrite(relayPins[2], LOW);
      digitalWrite(relayPins[3], HIGH);
      digitalWrite(relayPins[4], LOW);
      digitalWrite(relayPins[5], HIGH);
     
    }
  }
}