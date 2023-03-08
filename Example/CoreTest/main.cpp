#include "Core/Core.h"
#include "WindowCore/Public/CApplication.h"

using namespace CLGL;

DECLARE_LOG_CATEGORY_EXTERN(LogCoreTest)

DEFINE_LOG_CATEGORY(LogCoreTest)

int Main(int argc, char** argv)
{
    CApplication App(argc, argv);
    CWindow* MainWindow = new CWindow(nullptr);
    MainWindow->MakeCurrentContext();
    App.LoadOpenGLFunctions();
    return App.Exec();
}