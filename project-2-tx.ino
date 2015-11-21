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

RH_ASK txDriver;
const char *message = "ADAStx1";

void setup() {
  Serial.begin(9600);
  pinMode(TX_LED_PIN, OUTPUT);
  pinMode(TX_PIN, INPUT);
  if (!txDriver.init()) {
    Serial.println("TX driver init failed");
  }
}

void loop() {
  testTransmitter();
}

void testTransmitter() {
  txDriver.send((uint8_t *)message, strlen(message));
  txDriver.waitPacketSent();
  toggleLED(ON, TX_LED_PIN);
  delay(100);
  toggleLED(OFF, TX_LED_PIN);
  delay(60000);
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
