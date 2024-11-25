#ifndef DIGITALSENSORIMPL_H
#define DIGITALSENSORIMPL_H

#include "ClassDef.h"

// Implementatie van digitale sensor met drukknop
class ButtonSensor : public DigitalSensor {
public:
    bool read() override;
};

#endif
