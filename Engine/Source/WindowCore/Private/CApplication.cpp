#include "WindowCore/Public/CApplication.h"
#include "GLFW/CGLFWApplicationPrivate.h"

namespace CLGL
{

    CApplication* CApplication::GlobalApp = nullptr;
    
    CApplication::CApplication(int Argc, char** Argv)
        : ArgumentCount(Argc),
          CurrentContextWindow(nullptr)
    {
        if (!GlobalApp)
        {
            P = new CGLFWApplicationPrivate();
            for (int i = 0; i < Argc; i++)
            {
                Arguments.push_back(Argv[i]);
            }
            P->InitApplication();
            P->SetOpenGLVersion(CG_GLAD_VERSION_MAJOR, CG_GLAD_VERSION_MINOR);
        }
    }

    CApplication::~CApplication()
    {
        delete P;
        P = nullptr;
        CApplicationPrivate::AppPrivateInst = nullptr;
    }

    void CApplication::LoadOpenGLFunctions() const
    {
        P->LoadOpenGLFunctions();
    }

    void CApplication::AddContextWindow(CWindow* Window)
    {
        if (Window)
        {
            if (CurrentContextWindow)
            {
                
            }
        }
    }
}
