#include "CApplicationPrivate.h"
#include <stdio.h>

namespace CLGL
{
    CApplicationPrivate* CApplicationPrivate::AppPrivateInst = NULL;

    void CApplicationPrivate::AddPrivateWindow(CWindowPrivate* PrivateWindow)
    {
        PrivateWindows.push_back(PrivateWindow);
    }
}
