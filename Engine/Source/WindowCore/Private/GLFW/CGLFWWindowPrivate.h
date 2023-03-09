#ifndef CGLFWWINDOWPRIVATE_H
#define CGLFWWINDOWPRIVATE_H

#include "WindowCore/Private/CWindowPrivate.h"

struct GLFWwindow;

namespace CLGL
{
    class CGLFWWindowPrivate : public CWindowPrivate
    {
    public:
        explicit CGLFWWindowPrivate(CWindow* W);

        bool CreateWindow(CWindowPrivate* Parent) override;

        void DestroyWindow() override;
        
        void SetWindowTitle(const CString& NewTitle) override;

        void SetWindowSize(const CIntSize& NewSize) override;

        void MakeCurrentContext() override;

        GLFWwindow* GetWindowHandle() const { return WindowHandle; }
        
    private:
        friend class CGLFWApplicationPrivate;
        GLFWwindow* WindowHandle = nullptr;
    };
}

#endif