/*
 * Project 2 Transmitter
 * Board: Arduino UNO or similar with ATmega328P
 *
 * David Siver
 * CS 4985
 * Fall 2015
 */
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
  pinMode(TX_PIN, OUTPUT);
  pinMode(TX_BUTTON_PIN, INPUT);
}

void loop() {
  txButtonState = digitalRead(TX_BUTTON_PIN);
  if(txButtonState == HIGH){
    toggleLED(ON, TX_LED_PIN);
  }
  else{
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
