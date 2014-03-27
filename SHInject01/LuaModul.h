typedef void		(*Lua_Dostring)(char const* luastring); 
typedef void		(*Lua_Reload)(); 
typedef void		(*Lua_Setfield)(lua_State *L, int idx, const char* k); 
typedef void		(*Lua_Pushcclosure)(lua_State *L, lua_CFunction fn, int n); 
typedef int			(*Lua_Gettop)(lua_State *L);
typedef int			(*Lua_Tonumber)(lua_State *L, int idx);
typedef const char*	(*Lua_Tostring)(lua_State *L, int idx);
typedef void		(*Lua_Pushstring)(lua_State *L, const char *s);
typedef void		(*LuaUnregisterfunc)(const char* command);

class Lua
{
private:
	static	Lua_Setfield		Setfield;	
	static	Lua_Pushcclosure	Pushcclosure;
public:
    static	Lua_Dostring		DoString;
	static	Lua_Reload			Reload;
	static	lua_State*			GetState() {return (lua_State*)(*(void **)LuaGetstateAddr);}
	static	int					GetTop(lua_State *L) {Lua_Gettop gettop=(Lua_Gettop)LuaGettopAddr; return gettop(L);}
	static	int					ToNumber(lua_State *L, int idx) {Lua_Tonumber tonumber=(Lua_Tonumber)LuaTonumberAddr; return tonumber(L, idx);}
	static	const char*			ToString(lua_State *L, int idx) {Lua_Tostring tostring=(Lua_Tostring)LuaTostringAddr; return tostring(L, idx);}
	static	void				Pushstring(lua_State *L, const char *s);
	static	void				RegisterFunc(unsigned int FreeFuncAddress, int callback, const char* command);
	static	void				UnRegisterFunc(const char* command){ LuaUnregisterfunc unregister = (LuaUnregisterfunc)FrameScriptUnregisterFunctionAddr; unregister(command); };
};