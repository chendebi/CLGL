#ifndef CWINDOWPRIVATE_H
#define CWINDOWPRIVATE_H

#include "Core/Core.h"

namespace CLGL
{
    class CWindow;
}

namespace CLGL
{
    class CWindowPrivate
    {
    public:
        explicit CWindowPrivate(CWindow* W);

        CWindow* Window() const { return BelongWindow; }
        
        virtual ~CWindowPrivate();

        virtual bool CreateWindow(CWindowPrivate* Parent = nullptr) = 0;

        virtual void DestroyWindow() = 0;
        
        virtual void SetWindowTitle(const CString& NewTitle) = 0;

        virtual void SetWindowSize(const CIntSize& NewSize) = 0;

        virtual void MakeCurrentContext() = 0;

    private:
        CWindow* BelongWindow = nullptr;
    };
    
}

#endif
