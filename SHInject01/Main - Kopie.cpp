#include <windows.h>

extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

int lua_Test (lua_State *L) {
	int numberOfArgs = lua_gettop(L);
	lua_Number n = 42;
	lua_pushnumber(L, n);
	return 1;
}

void registerLua () {

    // MessageBox(NULL, "TestTestTestText","Title ??", MB_OK | MB_ICONEXCLAMATION);

	// 0x00803b70 == lua_pushcclosure; Credits: berserk85
	// 0x00804070 == lua_setfield; Credits: berserk85
	// 0x00D3F78C == lua_State

	//#define lua_register(L,n,f) (lua_pushcfunction(L, (f)), lua_setglobal(L, (n)))
	//#define lua_pushcfunction(L,f)	lua_pushcclosure(L, (f), 0)
	//#define lua_setglobal(L,s)	lua_setfield(L, LUA_GLOBALSINDEX, (s))
	//#define LUA_GLOBALSINDEX	(-10002)

	lua_State *state = (lua_State*)(*(void **)0x00D3F78C);

	unsigned char * pCodeCave = (unsigned char *)0x005E7367; // replace before use

	DWORD old;
	VirtualProtect((LPVOID)pCodeCave, 5, PAGE_EXECUTE_READWRITE, &old);
	*(byte *)pCodeCave = 0xe9;
	*(int *)(pCodeCave + 1) = (int)lua_Test - (int)pCodeCave - 5;
	VirtualProtect((LPVOID)pCodeCave, 5, old, NULL);

	// /script SendChatMessage(Test(), "WHISPER", nil, UnitName("player"));

	lua_pushcclosure(state, (lua_CFunction)(pCodeCave), 0);
	lua_setfield(state, -10002, "Test");
}

BOOL WINAPI DllMain (HINSTANCE hDLL, DWORD reason, LPVOID reserved) {
	if (reason == DLL_PROCESS_ATTACH) {		
		// patch TLS to be able to access data from WoW's main thread
		// fs:[0x2c] == Linear address of the thread-local storage array
		// ds:[0x012705b0] == g_clientConnection; Credits: FearAndLawyering
		// 0x00002d94 == s_curMgrOffset; Credits: FearAndLawyering
		_asm {
			mov eax, dword ptr fs:[0x2c] 
			mov eax, dword ptr ds:[eax]
			add eax, 8 // current TLS
			mov ebx, dword ptr ds:[0x012705b0]
			mov ebx, dword ptr ds:[eax + 0x009439bc] // WoW's main thread TLS
			mov [eax], ebx // Perform patch
		}

		registerLua();
	}
	return TRUE;
}

