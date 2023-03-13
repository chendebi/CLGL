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
            P->SetOpenGLVersion(CG_GLAD_VERSION_MAJOR, CG_GLAD_VERSION_MINOR);
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
		while (P->GetQuitCode() < 0)
		{
		    P->Tick();
            for (auto Event : P->GetEvents())
            {
                for (const auto E : Event.second)
                {
                    Notify(Event.first, E);
                }
            }
		    P->ClearEvents();
			P->PollEvents();
		}
        return P->GetQuitCode();
    }

    void CApplication::Notify(CWindow* RecvWindow, CEvent* Event)
    {
        RecvWindow->Event(Event);
        if (Event->Type() == CEvent::Close && dynamic_cast<CCloseEvent*>(Event)->IsAccepted())
        {
            delete RecvWindow;
        }
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

    void CApplication::RemoveWindow(CWindow* RemovedWindow)
    {
        Windows.remove(RemovedWindow);
    }
}
