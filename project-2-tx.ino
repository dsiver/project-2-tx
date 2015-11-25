/*
 * Project 2 Transmitter
 * Board: Arduino UNO or similar with ATmega328P
 *
 * David Siver
 * CS 4985
 * Fall 2015
 */

#include <VirtualWire.h>
#define TX_LED_PIN 4
#define TX_PIN 5
#define TX_BUTTON_PIN 2
#define OFF "off"
#define ON "on"
#define NONE "none"

int txButtonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TX_LED_PIN, OUTPUT);
  //pinMode(TX_PIN, OUTPUT);
  pinMode(TX_BUTTON_PIN, INPUT);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_set_tx_pin(5);
}

void loop() {
  char *message;
  txButtonState = digitalRead(TX_BUTTON_PIN);
  if (txButtonState == HIGH && !vw_tx_active()) {
    toggleLED(ON, TX_LED_PIN);
    char *message = "1";
    Serial.print("Sending message: ");
    Serial.println(message);
    vw_send((uint8_t *)message, strlen(message));
    vw_wait_tx();
    toggleLED(OFF, TX_LED_PIN);
  }
  else {
    toggleLED(OFF, TX_LED_PIN);
  }
}

void toggleLED(String mode, int pin) {
  if (mode == ON) {
    digitalWrite(pin, HIGH);
    //Serial.println("LED ON");
  }
  else if (mode == OFF) {
    digitalWrite(pin, LOW);
    //Serial.println("LED OFF");
  }
}
