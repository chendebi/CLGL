#ifndef CEVENT_H
#define CEVENT_H

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
        explicit CMouseEvent(EventType Intype):MouseEventType(Intype) {}

        int Type() const override { return MouseEventType; }

    private:
        EventType MouseEventType;
    };
}

#endif