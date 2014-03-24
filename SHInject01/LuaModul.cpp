#include "header.h"

void (*Lua::DoString)(char const* luastring, ...) = reinterpret_cast<Lua_Dostring>(LuaDostringAddr);
void (*Lua::Reload)(...) = reinterpret_cast<Lua_Reload>(LuaReloadAddr);
void (*Lua::Setfield)(lua_State *L, int idx, const char* k) = reinterpret_cast<Lua_Setfield>(LuaSetfieldAddr);
void (*Lua::Pushcclosure)(lua_State *L, lua_CFunction fn, int n) = reinterpret_cast<Lua_Pushcclosure>(LuaPushcclosureAddr);

//Functions
void Lua::Pushstring(lua_State *L, const char *s) {
	Lua_Pushstring Pushstring = (Lua_Pushstring)LuaPushstringAddr;
	Pushstring(L, s);
}
void Lua::RegisterFunc(unsigned int FreeFuncAddress, int callback, const char* command) {
	lua_State *state = Lua::GetState();
	unsigned char * pCodeCave = (unsigned char *)FreeFuncAddress; // replace before use

	DWORD old;
	VirtualProtect((LPVOID)pCodeCave, 5, PAGE_EXECUTE_READWRITE, &old);
	*(byte *)pCodeCave = 0xe9;
	*(int *)(pCodeCave + 1) = callback - (int)pCodeCave - 5;
	VirtualProtect((LPVOID)pCodeCave, 5, old, NULL);

	Lua::Pushcclosure(state, (lua_CFunction)(pCodeCave), 0);
	Lua::Setfield(state, LUA_GLOBALSINDEX, command);
};