#include "AnalogSensorImpl.h"
#include <Arduino.h>

int PotentiometerSensor::read() {
    return analogRead(A0); // Stel in op de juiste pin
}
