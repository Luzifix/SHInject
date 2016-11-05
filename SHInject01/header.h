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

#include "Opcodes.h"
#include "Offsets.h"

#include "CDataStoreMgr.h"
#include "DetoursMgr.h"

#include "LuaModul.h"

#include "ConsoleModul.h"
#include "ClientCommunicationModul.h"
#include "ClientEventModul.h"

