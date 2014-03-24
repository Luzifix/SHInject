#include "header.h"

int lua_Test (lua_State *L) {
	MessageBox(NULL, "click", "Testing", MB_OK | MB_ICONEXCLAMATION);
	//luaL_checkstring(L, 1)
	const char* str1 = Lua::ToString(L, 1);
	const char* str2 = Lua::ToString(L, 2);
	const char* str3 = Lua::ToString(L, 3);
	int			int4 = Lua::ToNumber(L, 4);
	int numOfArg = Lua::GetTop(L);
	//const char* para = luaL_checkstring(L, 1);
	//Lua::Pushstring(L, "Bla Bla bla");
	//lua_Number n = 42;
	//lua_pushnumber(L, n);

	//Lua::UnRegisterFunc("LaunchURL");
	return 1;
}

BOOL WINAPI DllMain (HINSTANCE hDLL, DWORD reason, LPVOID reserved) {
	switch (reason)
    {
	case DLL_PROCESS_ATTACH:
		//Wow::PatchTLS();
		Lua::RegisterFunc(0x005E7367, (int)lua_Test, "luzifix");
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

  