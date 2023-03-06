#ifndef CGLFWWINDOWPRIVATE_H
#define CGLFWWINDOWPRIVATE_H

#include "CWindowPrivate.h"

namespace CLGL
{
    class CGLFWWindowPrivate : public CWindowPrivate
    {
    public:
        explicit CGLFWWindowPrivate(CWindowPrivate* Parent = nullptr);

        bool CreateWindow(CWindowPrivate* Parent) override;

        void DestroyWindow() override;
        
        void SetWindowTitle(const CString& NewTitle) override;

        void SetWindowSize(const CIntSize& NewSize) override;

        void MakeOpenGLContext() override;
    };
}

#endif