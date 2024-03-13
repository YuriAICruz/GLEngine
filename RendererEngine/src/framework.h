#define GLY_DLL_EXPORTS

#include <windows.h>

#ifdef GLY_DLL_EXPORTS
#define GLY_API __declspec(dllexport)
#else
#define GLY_API __declspec(dllimport)
#endif // GLY_DLL_EXPORTS