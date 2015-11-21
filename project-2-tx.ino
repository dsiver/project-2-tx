/*
 * Project 2 Transmitter
 * Board: Arduino UNO or similar with ATmega328P
 *
 * David Siver
 * CS 4985
 * Fall 2015
 */

#include <RH_ASK.h>
#include <SPI.h>
#define TX_LED_PIN 4
#define TX_PIN 5
#define OFF "off"
#define ON "on"
#define NONE "none"
#define MESSAGE 0x845FED

RH_ASK txDriver;

void setup() {
  Serial.begin(9600);
  pinMode(TX_LED_PIN, OUTPUT);
  pinMode(TX_PIN, INPUT);
  if (!txDriver.init()){
         Serial.println("TX driver init failed");
  }
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
