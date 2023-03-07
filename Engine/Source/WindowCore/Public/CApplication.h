#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include "CWindow.h"
#include "Core/Core.h"

namespace CLGL
{
    class CApplicationPrivate;
    
    class final CApplication
    {
    public:

        static CApplication* GlobalApp;
        
        explicit CApplication(int Argc, char** Argv);

        ~CApplication();

        void LoadOpenGLFunctions() const;

        void AddContextWindow(CWindow* Window);
        
    private:
        CApplicationPrivate* P = nullptr;
        int ArgumentCount;
        CArray<CString> Arguments;

        CWindow* CurrentContextWindow;
    };
    
}

#endif