## About
SHInject is a Memory Editing Library for World of Warcraft 3.3.5:12340. I want to make Memory Editing for World of Warcraft simpler.

## Functions
#### GameConsole
* GameConsole::RegisterCommand("CommandName", myFunction, category, "HelpText");
* GameConsole::UnregisterCommand("CommandName");
* GameConsole::Write("MyText", color);

#### Lua
* Lua::DoString("LuaString");
* Lua::Reload();
* Lua::GetState();
* Lua::GetTop();
* Lua::ToNumber(LuaState, Idx);
* Lua::ToString(LuaState, Idx);
* Lua::PushString(LuaState, "MyString");
* Lua::RegisterFunc(FreeFuncAddress, (int)myFunction, "CommandName");
* Lua::UnregisterFunc("CommandName");

## Events
* ClientInitializeGame
* FrameScriptRegisterFunction
* FrameScriptUnregisterFunction
* SetMessageHandler
* CGGameObjectInitialize

## Team
* Luzifix
