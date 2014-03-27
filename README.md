## About
SHInject is a Memory Editing Library for World of Warcraft 3.3.5:12340. I want to make with my library the Memory Editing for World of Warcraft simpler.

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

## How to use
* Cretae the dll file with Visual Studio
* Move the dll in the World of Warcraft main directory
* Inject the dll with a dll injection program

## Thanks
* Cromon for a lot of help
* Nesox for http://tinyurl.com/p7eduq9
* tomrus88 for http://tinyurl.com/pbr6sbg

## Team
* Luzifix
