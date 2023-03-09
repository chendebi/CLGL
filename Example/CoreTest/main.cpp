
#include "Core/Core.h"
#include "WindowCore/Public/CApplication.h"

using namespace CLGL;

DECLARE_LOG_CATEGORY_EXTERN(LogCoreTest)

DEFINE_LOG_CATEGORY(LogCoreTest)

int main(int argc, char** argv)
{
    CApplication App(argc, argv);
    CWindow* MainWindow = new CWindow(nullptr);
    MainWindow->MakeCurrentContext();
    App.LoadOpenGLFunctions();
    return App.Exec();
}


/*
#include "glad/glad.h"
#include "GLFW/glfw3.h"

int main(int argc, char** argv)
{
	if (!glfwInit())
		return 1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* W = glfwCreateWindow(600, 400, "SS", NULL, NULL);

	while (true)
	{

	}
	return 0;
}
*/