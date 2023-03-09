#ifndef CMOUSEEVENTPRIVATE_H
#define CMOUSEEVENTPRIVATE_H

#include "CEvent.h"
#include "Core/Core.h"

namespace CLGL
{
    class CWindow;
    
    struct CMouseEventPrivate
    {
        CWindow* Window = nullptr;
        MouseButton Button = NoButton;
        CEvent::EventType Type = CEvent::None;
        
        CMouseEventPrivate(CWindow* W, MouseButton B, CEvent::EventType InType)
            : Window(W), Button(B), Type(InType) {}
    };
}

#endif