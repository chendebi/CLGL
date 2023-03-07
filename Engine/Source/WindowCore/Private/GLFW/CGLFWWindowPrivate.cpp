#include "CGLFWWindowPrivate.h"
#include "GLFW/glfw3.h"

CLGL::CGLFWWindowPrivate::CGLFWWindowPrivate()
{
    
}

bool CLGL::CGLFWWindowPrivate::CreateWindow(CWindowPrivate* Parent)
{
    WindowHandle = glfwCreateWindow(600, 400, "Window", nullptr, nullptr);
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

