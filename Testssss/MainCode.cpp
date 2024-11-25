#include <Arduino.h>
#include "AnalogSensorImpl.h"
#include "DigitalSensorImpl.h"

AnalogSensor* analogSensor;
DigitalSensor* digitalSensor;

const int ledPin = 11; // Stel in op de juiste pin voor de LED


void handleInterrupt() {
    // Interrupt handler voor digitale sensor
    bool buttonState = digitalSensor->read();
    Serial.print("Hier");
    digitalWrite(ledPin, buttonState ? HIGH : LOW);
}

void setup() {
  Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    
    analogSensor = new PotentiometerSensor();
    digitalSensor = new ButtonSensor();

    attachInterrupt(digitalPinToInterrupt(2), handleInterrupt, CHANGE);
}

void loop() {
    // Polling voor analoge sensor
    int analogValue = analogSensor->read();
    Serial.println(analogValue);
    int mappedValue = map(analogValue, 0, 1023, 0, 255);
    

    // Polling voor digitale sensor
    bool buttonState = digitalSensor->read();
    if (buttonState) {
        analogWrite(ledPin, mappedValue);
        Serial.println("Ingedrukt");
    } else {
        digitalWrite(ledPin, LOW);
    }

    delay(100); // Voeg een kleine vertraging toe om de output te stabiliseren
}
