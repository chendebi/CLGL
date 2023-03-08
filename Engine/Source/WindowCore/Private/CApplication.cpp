#include "WindowCore/Public/CApplication.h"
#include "GLFW/CGLFWApplicationPrivate.h"

namespace CLGL
{

    CApplication* CApplication::AppInst = nullptr;
    
    CApplication::CApplication(int Argc, char** Argv)
        : ArgumentCount(Argc),
          CurrentContextWindow(nullptr)
    {
        if (!AppInst)
        {
            AppInst = this;
            P = new CGLFWApplicationPrivate();
            CApplicationPrivate::AppPrivateInst = P;
            for (int i = 0; i < Argc; i++)
            {
                Arguments.push_back(Argv[i]);
            }
            P->InitApplication();
            //P->SetOpenGLVersion(CG_GLAD_VERSION_MAJOR, CG_GLAD_VERSION_MINOR);
            P->SetOpenGLVersion(3,3);
        }
    }

    CApplication::~CApplication()
    {
        delete P;
        P = nullptr;
        CApplicationPrivate::AppPrivateInst = nullptr;
    }

    CApplication* CApplication::Get()
    {
        return AppInst;
    }

    void CApplication::LoadOpenGLFunctions() const
    {
        P->LoadOpenGLFunctions();
    }

    int CApplication::Exec()
    {
        P->PollEvents();
        return 0;
    }

    void CApplication::SetCurrentContextWindow(CWindow* Window)
    {
        if (Window)
        {
            CurrentContextWindow = Window;
        }
    }

    void CApplication::AddWindow(CWindow *NewWindow)
    {
        Windows.push_back(NewWindow);
    }
}
