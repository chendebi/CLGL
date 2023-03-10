#ifndef CGLFWAPPLICATIONPRIVATE_H
#define CGLFWAPPLICATIONPRIVATE_H

#include "WindowCore/Private/CApplicationPrivate.h"

struct GLFWwindow;

namespace CLGL
{
    class CGLFWApplicationPrivate : public CApplicationPrivate
    {
    public:

        void InitApplication() override;

        void SetOpenGLVersion(int Major, int Minor) override;

        void LoadOpenGLFunctions() override;

        void PollEvents() override;

        void ProcessMouseEvent(CMouseEventPrivate Event) override;
        
        CWindowPrivate* FindWindowByGLFWwindow(GLFWwindow* W);

    private:
        
    };
}

#endif
