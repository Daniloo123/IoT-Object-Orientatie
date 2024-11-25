#include "DigitalSensorImpl.h"
#include <Arduino.h>

bool ButtonSensor::read() {
    return digitalRead(12); // Stel in op de juiste pin
}
