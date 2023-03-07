#include "WindowCore/Public/CWindow.h"

#ifdef CG_PLATFORM_GLFW
#include "GLFW/CGLFWWindowPrivate.h"
#else
#error No rendering platform specified
#endif

CLGL::CWindow::CWindow(CWindow* Parent, const CString& Title, const CIntSize& DefaultSize)
{
#ifdef CG_PLATFORM_GLFW
    P = new CGLFWWindowPrivate();
#endif
    
    CWindowPrivate* PP = Parent ? Parent->P : nullptr;
    P->CreateWindow(PP);
    SetWindowTitle(Title);
    SetWindowSize(DefaultSize);
}

CLGL::CWindow::~CWindow()
{
    P->DestroyWindow();
    delete P;
    P = nullptr;
}

