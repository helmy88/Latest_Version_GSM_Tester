#include <SoftwareSerial.h>

// Define the SIM800L module's TX and RX pins
const int sim800lTxPin = 7; // Connect SIM800L TX to Arduino RX (7)
const int sim800lRxPin = 8; // Connect SIM800L RX to Arduino TX (8)

// Create a SoftwareSerial object
SoftwareSerial sim800l(sim800lTxPin, sim800lRxPin);

void setup() {
  // Start serial communication with Arduino IDE Serial Monitor
  Serial.begin(9600);
  delay(1000);
  
  // Initialize the SoftwareSerial connection with SIM800L
  sim800l.begin(9600); // Try 9600 baud rate
  delay(1000);

  // Send AT command to check if SIM800L is responding
  sim800l.println("AT");
  delay(1000);

  // Read and print the response
  while (sim800l.available()) {
    char c = sim800l.read();
    Serial.print(c);
  }
  
  // Close the SoftwareSerial connection
  sim800l.end();
  
  // Repeat the process with other baud rates (e.g., 19200, 115200)
}

void loop() {
  // Nothing in the loop for this example
}
