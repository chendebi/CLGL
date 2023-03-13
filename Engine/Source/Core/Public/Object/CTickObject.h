#ifndef CTICKOBJECT_H
#define CTICKOBJECT_H

#include "CObejct.h"

class CTickObject : public CObject
{
public:
    virtual ~CTickObject() = default;
    
protected:
    virtual void Tick(float Delta) {}
};


#endif