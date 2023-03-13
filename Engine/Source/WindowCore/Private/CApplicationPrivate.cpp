#include "CApplicationPrivate.h"
#include "CWindowPrivate.h"

namespace CLGL
{
    CApplicationPrivate* CApplicationPrivate::AppPrivateInst = NULL;

    void CApplicationPrivate::AddEvent(CWindow* Window, CEvent *E)
    {
        FrameEvents[Window].push_back(E);
    }

    CMap<CWindow*, CArray<CEvent*>> CApplicationPrivate::GetEvents()
    {
        return FrameEvents;
    }

    void CApplicationPrivate::ClearEvents()
    {
        for (auto it : FrameEvents)
        {
			for each (auto E in it.second)
			{
			    delete E;
			}
            it.second.clear();
        }
    }

    void CApplicationPrivate::SetQuitCode(int NewQuitCode)
    {
        QuitCode = NewQuitCode;
    }

    void CApplicationPrivate::AddPrivateWindow(CWindowPrivate* PrivateWindow)
    {
        PrivateWindows.push_back(PrivateWindow);
        FrameEvents.insert(std::make_pair<CWindow*, CArray<CEvent*>>(PrivateWindow->Window(), {}));
    }

    void CApplicationPrivate::RemovePrivateWindow(CWindowPrivate* PrivateWindow)
    {
        PrivateWindows.remove(PrivateWindow);
        if (PrivateWindows.empty())
        {
            SetQuitCode(0);
        }
    }
}
