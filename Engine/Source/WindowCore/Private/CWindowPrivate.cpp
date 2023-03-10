#include "CWindowPrivate.h"

#include "CApplicationPrivate.h"

namespace CLGL
{
    CWindowPrivate::CWindowPrivate(CWindow* W)
    {
        BelongWindow = W;
        CApplicationPrivate::AppPrivateInst->AddPrivateWindow(this);
    }

}
