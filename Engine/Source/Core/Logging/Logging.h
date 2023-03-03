#ifndef LOGGING_H
#define LOGGING_H

#include "Types/CString.h"

struct CLogBaseCategory
{
    CLGL::CString Name;

    CLogBaseCategory() {}

    CLogBaseCategory(const CLGL::CString& InCategoryName) : Name(InCategoryName)
    {}
};


#define DECLARE_LOG_CATEGORY_EXTERN(CategoryName)\
    extern struct CLogCategory##CategoryName : public CLogBaseCategory\
    {\
        CLogCategory##CategoryName() : CLogBaseCategory(#CategoryName) {}\
    } CategoryName;

#define DEFINE_LOG_CATEGORY(CategoryName)\
    CLogCategory##CategoryName CategoryName;

#define LogInfo(LogCategory, Msg, ...)\
    {\
        CString OutMsg = "[" + LogCategory.Name + "] [Info] " + Msg + "\n";\
        fprintf(stdout, OutMsg.c_str(), __VA_ARGS__);\
    }

#define LogWarning(LogCategory, Msg, ...)\
    {\
        CString OutMsg = "[" + LogCategory.Name + "] [Warning] " + Msg + "\n";\
        fprintf(stdout, OutMsg.c_str(), __VA_ARGS__);\
    }

#define LogError(LogCategory, Msg, ...)\
    {\
        CString OutMsg = "[" + LogCategory.Name + "] [Error] " + Msg + "\n";\
        fprintf(stderr, OutMsg.c_str(), __VA_ARGS__);\
    }

DECLARE_LOG_CATEGORY_EXTERN(LogSystem)

#if defined(_MSC_VER) && !defined(CG_NO_DEBUG) 
#define check(e)\
    if (!(e)) __debugbreak();

#define checkmsg(e, msg, ...)\
    if (!(e))\
    {\
        LogWarning(LogSystem, msg, __VA_ARGS__)\
		__debugbreak();\
    }
#else

#define check(e)

#define checkmsg(e, msg, ...)\
    if (!(e))\
    {\
        LogWarning(LogSystem, msg, __VA_ARGS__)\
    }
#endif

#endif