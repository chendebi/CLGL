
#include <iostream>

#include "Core/Core.h"
#include "WindowCore/Public/CApplication.h"

using namespace CLGL;

DECLARE_LOG_CATEGORY_EXTERN(LogCoreTest)

DEFINE_LOG_CATEGORY(LogCoreTest)

int main(int Argc, char** Argvs)
{
    CApplication App(Argc, Argvs);
    CWindow* MainWindow = new CWindow(nullptr);
    MainWindow->MakeCurrentContext();
    App.LoadOpenGLFunctions();
    return App.Exec();
}