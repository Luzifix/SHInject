#include "Header.h"

BOOL WINAPI DllMain (HINSTANCE hDLL, DWORD reason, LPVOID reserved) {
	switch (reason)
    {
	case DLL_PROCESS_ATTACH:
		DetoursMgr::Initialize();
		break;
	case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
	case DLL_PROCESS_DETACH:		
        break;
	}
	return TRUE;
}