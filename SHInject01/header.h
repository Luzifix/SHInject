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
<<<<<<< HEAD
#include "ConsoleModul.h"
#include "ClientCommunicationModul.h"
#include "ClientEventModul.h"
=======
#include "Console.h"
#include "EventMgr.h"
#include "DetoursMgr.h"
>>>>>>> 4acfba781e1e9f21688bf9e166bf843af457917c
