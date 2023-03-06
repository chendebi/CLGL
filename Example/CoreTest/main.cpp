#include "Core.h"
#include "Types/CString.h"
#include "Logging/Logging.h"

using namespace CLGL;

struct Person
{
    int Id;
    CString Name;

    Person() : Id(1), Name("李华")
    {
        
    }
};

DECLARE_LOG_CATEGORY_EXTERN(LogCoreTest)

DEFINE_LOG_CATEGORY(LogCoreTest)

int main(int argc, char** argv)
{
    Person P;
    LogInfo(LogCoreTest, "这个人的id是%d, 姓名是%s", P.Id, P.Name.c_str())
    LogWarning(LogCoreTest, "这个人的id是%d, 姓名是%s", P.Id, P.Name.c_str())
    LogError(LogCoreTest, "这个人的id是%d, 姓名是%s", P.Id, P.Name.c_str())

    //check(0)

    //checkmsg(false, "check failed!")
    
	LogError(LogCoreTest,"测试已经结束")

#ifdef CG_NO_DEBUG
	LogInfo(LogCoreTest, "当前是Release")
#else
	LogInfo(LogCoreTest, "当前是Debug")
#endif

	return 0;
}