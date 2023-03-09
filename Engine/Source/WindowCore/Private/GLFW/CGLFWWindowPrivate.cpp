#include "CGLFWWindowPrivate.h"

#include "CGLFWApplicationPrivate.h"
#include "GLFW/glfw3.h"
#include "WindowCore/Private/CApplicationPrivate.h"


void MouseButtonCallback(GLFWwindow* Window, int Button, int Action, int Mode)
{
    CLGL::CEvent::EventType Type;
    switch (Action)
    {
    case 1: Type = CLGL::CEvent::MouseButtonRelease; break;
    case 2: Type = CLGL::CEvent::MouseButtonPress; break;
    default:
            Type = CLGL::CEvent::None;
        break;;
    }
    const auto AppInstP = dynamic_cast<CLGL::CGLFWApplicationPrivate*>(CLGL::CApplicationPrivate::AppPrivateInst);
    AppInstP->ProcessMouseEvent(CLGL::CMouseEventPrivate(AppInstP->FindWindowByGLFWwindow(Window)->Window(),
        static_cast<CLGL::MouseButton>(Button), Type));
    LogInfo(LogSystem, "Mouse Event: %d, %d", Button, Action)
}

CLGL::CGLFWWindowPrivate::CGLFWWindowPrivate(CWindow* W)
    : CWindowPrivate(W)
{
}

bool CLGL::CGLFWWindowPrivate::CreateWindow(CWindowPrivate* Parent)
{
    WindowHandle = glfwCreateWindow(600, 400, "Window", NULL, NULL);
    glfwSetMouseButtonCallback(WindowHandle, MouseButtonCallback);
    return WindowHandle;
}

void CLGL::CGLFWWindowPrivate::DestroyWindow()
{
    glfwDestroyWindow(WindowHandle);
    WindowHandle = nullptr;
}

void CLGL::CGLFWWindowPrivate::SetWindowTitle(const CString& NewTitle)
{
    glfwSetWindowTitle(WindowHandle, NewTitle.c_str());
}

void CLGL::CGLFWWindowPrivate::SetWindowSize(const CIntSize& NewSize)
{
    glfwSetWindowSize(WindowHandle, NewSize.Width, NewSize.Height);
}

void CLGL::CGLFWWindowPrivate::MakeCurrentContext()
{
    glfwMakeContextCurrent(WindowHandle);
}
