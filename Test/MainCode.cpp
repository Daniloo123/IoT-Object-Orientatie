#include <Arduino.h>
#include "AnalogSensorImpl.h"
#include "DigitalSensorImpl.h"

AnalogSensor* analogSensor;
DigitalSensor* digitalSensor;

const int ledPin = 13; // Stel in op de juiste pin voor de LED

void setup() {
    pinMode(ledPin, OUTPUT);

    analogSensor = new PotentiometerSensor();
    digitalSensor = new ButtonSensor();

    attachInterrupt(digitalPinToInterrupt(2), handleInterrupt, CHANGE);
}

void loop() {
    // Polling voor analoge sensor
    int analogValue = analogSensor->read();
    int mappedValue = map(analogValue, 0, 1023, 0, 255);
    analogWrite(ledPin, mappedValue);

    // Polling voor digitale sensor
    bool buttonState = digitalSensor->read();
    if (buttonState) {
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }

    delay(100); // Voeg een kleine vertraging toe om de output te stabiliseren
}

void handleInterrupt() {
    // Interrupt handler voor digitale sensor
    bool buttonState = digitalSensor->read();
    digitalWrite(ledPin, buttonState ? HIGH : LOW);
}
