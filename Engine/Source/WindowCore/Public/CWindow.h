#ifndef CWINDOW_H
#define CWINDOW_H

#include "WindowCore/Private/CEvent.h"
#include "WindowCore/Private/CWindowPrivate.h"

namespace CLGL
{
    class CWindow
    {
    public:
        explicit CWindow(CWindow* Parent = nullptr, const CString& Title = "Window", const CIntSize& DefaultSize = CIntSize(600, 400));

        virtual ~CWindow();

        void SetWindowTitle(const CString& NewTitle)
        {
            WindowTitle = NewTitle;
            P->SetWindowTitle(NewTitle);
        }

        void SetWindowSize(const CIntSize& NewSize)
        {
            if (NewSize.IsValid())
            {
                WindowSize = NewSize;
                P->SetWindowSize(NewSize);
            }
        }

        void MakeCurrentContext();

    protected:
        friend class CApplication;
        virtual void Event(CEvent* E);

        virtual void MousePressEvent(CMouseEvent* E) {}

        virtual void CloseEvent(CCloseEvent* E) {}
        
    private:
        CWindowPrivate* P = nullptr;

        CString WindowTitle;

        CIntSize WindowSize;
    };
}

#endif