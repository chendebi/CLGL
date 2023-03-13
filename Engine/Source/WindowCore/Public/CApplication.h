#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include "CWindow.h"
#include "Core/Core.h"
#include "WindowCore/Private/CEvent.h"

namespace CLGL
{
    class CApplicationPrivate;
    
    class CApplication
    {
    public:
        
        explicit CApplication(int Argc = 0, char** Argv = nullptr);

        virtual ~CApplication();
        
        static CApplication* Get();

        void LoadOpenGLFunctions() const;

        int Exec();

    protected:
        virtual void Notify(CWindow* RecvWindow, CEvent* Event);
        
    private:
        friend class CWindow;
        
        void AddWindow(CWindow* NewWindow);

        void RemoveWindow(CWindow* RemovedWindow);
        
        void SetCurrentContextWindow(CWindow* Window);
        
    private:
        static CApplication* AppInst;
        
    private:
        CApplicationPrivate* P = nullptr;

        int ArgumentCount;
        
        CArray<CString> Arguments;

        CWindow* CurrentContextWindow;
        
        CList<CWindow*> Windows;
    };
    
}

#endif
