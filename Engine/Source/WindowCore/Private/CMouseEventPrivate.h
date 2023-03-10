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
        CPos Pos = {0, 0};
        
        CMouseEventPrivate(CWindow* W, MouseButton B, CEvent::EventType InType, CPos InPos)
            : Window(W), Button(B), Type(InType), Pos(InPos) {}
    };
}

#endif