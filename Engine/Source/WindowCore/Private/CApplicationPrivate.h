#ifndef CAPPLICATIONPRIVATE_H
#define CAPPLICATIONPRIVATE_H
#include "CMouseEventPrivate.h"
#include "Core/Public/Types/CMap.h"

namespace CLGL
{
    class CWindowPrivate;
}

namespace CLGL
{
    
    class CApplicationPrivate
    {
    public:
        static CApplicationPrivate* AppPrivateInst;
        
        virtual ~CApplicationPrivate() = default;

        virtual void InitApplication() = 0;
        
        virtual void SetOpenGLVersion(int Major, int Minor) = 0;

        virtual void LoadOpenGLFunctions() = 0;

        virtual void PollEvents() = 0;

        virtual void ProcessMouseEvent(CMouseEventPrivate Event) = 0;

        void AddEvent(CWindow* Window, CEvent *E);

        virtual CMap<CWindow*, CArray<CEvent*> > GetEvents();

        virtual void ClearEvents() ;

        // return >= 0 means quit application
        virtual int GetQuitCode() const { return QuitCode; }

        virtual void SetQuitCode(int NewQuitCode);

        virtual void Tick() {}
        
    protected:
        friend class CWindowPrivate;
        void AddPrivateWindow(CWindowPrivate* PrivateWindow);

        void RemovePrivateWindow(CWindowPrivate* PrivateWindow);

        CList<CWindowPrivate*> GetPrivateWindows() const { return PrivateWindows; }
        
    private:
        CList<CWindowPrivate*> PrivateWindows;

        CMap<CWindow*, CArray<CEvent*> > FrameEvents;

        int QuitCode = -1;
    };
}
#endif
