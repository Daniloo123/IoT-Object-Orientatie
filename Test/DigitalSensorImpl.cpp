#include "DigitalSensorImpl.h"
#include <Arduino.h>

bool ButtonSensor::read() {
    return digitalRead(2); // Stel in op de juiste pin
}
