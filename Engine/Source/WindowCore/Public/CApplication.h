#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include "CWindow.h"
#include "Core/Core.h"

namespace CLGL
{
    class CApplicationPrivate;
    
    class CApplication
    {
    public:
        
        explicit CApplication(int Argc, char** Argv);

        ~CApplication();
        
        static CApplication* Get();

        void LoadOpenGLFunctions() const;

        int Exec() const;
        
    private:
        friend class CWindow;
        
        void AddWindow(CWindow* NewWindow);

        void SetCurrentContextWindow(CWindow* Window);
        
    private:
        static CApplication* AppInst;
        
    private:
        CApplicationPrivate* P = nullptr;

        int ArgumentCount;
        
        CArray<CString> Arguments;

        CWindow* CurrentContextWindow;
        
        CArray<CWindow*> Windows;
    };
    
}

#endif
