#ifndef ANALOGSENSORIMPL_H
#define ANALOGSENSORIMPL_H

#include "ClassDef.h"

// Implementatie van analoge sensor met potentiometer
class PotentiometerSensor : public AnalogSensor {
public:
    int read() override;
};

#endif
