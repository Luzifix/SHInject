#include <windows.h>
#include <string>
#include <map>
#include <vector>
#include "Detours.h"


extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

#include "Offsets.h"
#include "LuaModul.h"
#include "Console.h"
#include "EventMgr.h"
#include "DetoursMgr.h"
