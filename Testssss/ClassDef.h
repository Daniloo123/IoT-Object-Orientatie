#ifndef CLASSDEF_H
#define CLASSDEF_H

// Interface voor analoge sensor
class AnalogSensor {
public:
    virtual int read() = 0;
};

// Interface voor digitale sensor
class DigitalSensor {
public:
    virtual bool read() = 0;
};

#endif
