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
    P = new CGLFWWindowPrivate(this);
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
    CApplication::Get()->RemoveWindow(this);
}

void CLGL::CWindow::MakeCurrentContext()
{
    P->MakeCurrentContext();
    CApplication::Get()->SetCurrentContextWindow(this);
}

void CLGL::CWindow::Event(CEvent* E)
{
    switch (E->Type())
    {
    case CEvent::Close:
        CloseEvent(dynamic_cast<CCloseEvent*>(E));
        break;
    default:
        break;
    }
}


