#include "WindowCore/Public/CWindow.h"

CLGL::CWindow::CWindow(CWindow* Parent, const CString& Title, const CIntSize& DefaultSize)
{
    // TODO: Create platform private window
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
