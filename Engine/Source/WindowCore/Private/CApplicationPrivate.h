#ifndef CAPPLICATIONPRIVATE_H
#define CAPPLICATIONPRIVATE_H

namespace CLGL
{
    
    class CApplicationPrivate
    {
    public:
        static CApplicationPrivate* AppPrivateInst;
        
        virtual ~CApplicationPrivate() {}

        virtual void InitApplication() = 0;
        
        virtual void SetOpenGLVersion(int Major, int Minor) = 0;

        virtual void LoadOpenGLFunctions() = 0;
    };
}
#endif
