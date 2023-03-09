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

        virtual CMap<CWindow*, CArray<CEvent> > GetEvents() = 0;

        // return >= 0 means quit application
        virtual int GetQuitCode() = 0;
        
    protected:
        friend class CWindowPrivate;
        void AddPrivateWindow(CWindowPrivate* PrivateWindow);

        CArray<CWindowPrivate*> GetPrivateWindows() const { return PrivateWindows; }
        
    private:
        CArray<CWindowPrivate*> PrivateWindows;
    };
}
#endif
