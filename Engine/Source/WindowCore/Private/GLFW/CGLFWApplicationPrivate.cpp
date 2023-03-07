#include "CGLFWApplicationPrivate.h"

#include "Core/Core.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

void CLGL::CGLFWApplicationPrivate::InitApplication()
{
    if (!glfwInit())
    {
        LogError(LogSystem, "Glfw Init failed!")
    }
}

void CLGL::CGLFWApplicationPrivate::SetOpenGLVersion(int Major, int Minor)
{
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_VERSION_MAJOR, Major);
    glfwWindowHint(GLFW_VERSION_MINOR, Minor);
}

void CLGL::CGLFWApplicationPrivate::LoadOpenGLFunctions()
{
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    LogInfo(LogSystem, "Load OpenGL Version: %s", glGetString(GL_VERSION))
}

