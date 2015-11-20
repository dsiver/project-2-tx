/*
 * Project 2 Transmitter
 * Board: Arduino UNO or similar with ATmega328P
 *
 * David Siver
 * CS 4985
 * Fall 2015
 */

#define TX_LED_PIN 4
#define OFF "off"
#define ON "on"
#define NONE "none"

void setup() {
  Serial.begin(9600);
  pinMode(TX_LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void toggleLED(String mode, int pin) {
  if (mode == ON) {
    digitalWrite(pin, HIGH);
    Serial.println("LED ON");
  }
  else if (mode == OFF) {
    digitalWrite(pin, LOW);
    Serial.println("LED OFF");
  }
}
