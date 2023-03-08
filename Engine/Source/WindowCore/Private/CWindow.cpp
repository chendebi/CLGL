#include "WindowCore/Public/CWindow.h"
#include "WindowCore/Public/CApplication.h"

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
    CApplication::Get()->AddWindow(this);
}

CLGL::CWindow::~CWindow()
{
    P->DestroyWindow();
    delete P;
    P = nullptr;
}

void CLGL::CWindow::MakeCurrentContext()
{
    P->MakeCurrentContext();
    CApplication::Get()->SetCurrentContextWindow(this);
}

