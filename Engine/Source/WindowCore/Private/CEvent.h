#ifndef CEVENT_H
#define CEVENT_H
#include "Core/Core.h"
#include "Core/Public/Types/CPos.h"

namespace CLGL
{
    class CEvent
    {
    public:
    
        enum EventType
        {
            None,
            MouseButtonPress = 2,
            MouseButtonRelease = 3,
            MouseButtonDbClick = 4
        };

        virtual int Type() const { return None; }
    };

    class CMouseEvent : public CEvent
    {
    public:
        explicit CMouseEvent(CLGL::MouseButton InButton, const EventType InType, CPos InPos)
            : MouseEventType(InType),Button(InButton), Pos(InPos) {}

        int Type() const override { return MouseEventType; }

        int GetButton() const { return Button; }

        CPos GetPos() const { return Pos; }

    private:
        EventType MouseEventType;
        MouseButton Button;
        CPos Pos;
    };
}

#endif