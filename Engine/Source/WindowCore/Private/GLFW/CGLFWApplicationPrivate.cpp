#include "CGLFWApplicationPrivate.h"

#include "Core/Core.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

void GLFWErrorCallBack(int ErrorCode, const char* Description)
{
    LogError(LogSystem, "GLFW Error[%d]: %s", ErrorCode, Description)
}

void CLGL::CGLFWApplicationPrivate::InitApplication()
{
    if (!glfwInit())
    {
        LogError(LogSystem, "Glfw Init failed!")
    }
    LogInfo(LogSystem, "GLFW Init Success!")
    glfwSetErrorCallback(GLFWErrorCallBack);
}

void CLGL::CGLFWApplicationPrivate::SetOpenGLVersion(int Major, int Minor)
{
    glfwWindowHint(GLFW_VERSION_MAJOR, Major);
    glfwWindowHint(GLFW_VERSION_MINOR, Minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void CLGL::CGLFWApplicationPrivate::LoadOpenGLFunctions()
{
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    LogInfo(LogSystem, "Load OpenGL Version: %s", glGetString(GL_VERSION))
}

void CLGL::CGLFWApplicationPrivate::PollEvents()
{
    glfwPollEvents();
}

