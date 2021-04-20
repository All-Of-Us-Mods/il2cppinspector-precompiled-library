
#include <android/log.h>
#include <cstdint>
#include "il2cpp-api-functions-ptr.h"

#include "init.h"
#include "il2cpp.h"

// IL2CPP APIs
#define DO_API(r, n, p) r (*n) p
#include "il2cpp-api-functions.h"
#undef DO_API

// Application-specific functions
#define DO_APP_FUNC(a, r, n, p) r (*n) p
#define DO_APP_FUNC_METHODINFO(a, n) struct MethodInfo ** n
namespace app {
#include "il2cpp-functions.h"
}
#undef DO_APP_FUNC
#undef DO_APP_FUNC_METHODINFO

// TypeInfo pointers
#define DO_TYPEDEF(a, n) n ## __Class** n ## __TypeInfo
namespace app {
#include "il2cpp-types-ptr.h"
}
#undef DO_TYPEDEF

// IL2CPP application initializer
void InitIl2cpp(uintptr_t baseLib)
{
    __android_log_print(ANDROID_LOG_INFO,  "Launchpad", "Initializing Il2cpp");
    using namespace app;

    // Define IL2CPP API function addresses
    #define DO_API(r, n, p) n = (r (*) p)(baseLib + n ## _ptr)
    #include "il2cpp-api-functions.h"
    #undef DO_API

    // Define function addresses
    #define DO_APP_FUNC(a, r, n, p) n = (r (*) p)(baseLib + a)
    #define DO_APP_FUNC_METHODINFO(a, n) n = (struct MethodInfo **)(baseLib + a)
    #include "il2cpp-functions.h"
    #undef DO_APP_FUNC
    #undef DO_APP_FUNC_METHODINFO

    // Define TypeInfo variables
    #define DO_TYPEDEF(a, n) n ## __TypeInfo = (n ## __Class**) (baseLib + a);
    #include "il2cpp-types-ptr.h"
    #undef DO_TYPEDEF

    __android_log_print(ANDROID_LOG_INFO,  "Launchpad", "Il2cpp initialized");
}