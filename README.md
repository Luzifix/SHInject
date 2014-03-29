## About
SHInject is a Memory Editing Library for World of Warcraft 3.3.5:12340. I want to make with my library the Memory Editing for World of Warcraft simpler.

## Functions

#### Client Communication
* ClientCommunication::SetMessageHandler(opcode, myFunction, Parameter);
* ClientCommunication::RemoveMessageHandler(opcode);
* ClientCommunication::Disconnect();
* ClientCommunication::GetCurrent();
* ClientCommunication::GetSessionKey();
* ClientCommunication::SendPacket(data);
* ClientCommunication::SendGamePacket(data);

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

#### GameConsole
* GameConsole::RegisterCommand("CommandName", myFunction, category, "HelpText");
* GameConsole::UnregisterCommand("CommandName");
* GameConsole::Write("MyText", color);

## Events
* ClientServiceSetMessageHandler
* ClientServiceRemoveMessageHandler
* ClientServiceSendGamePacket
* ClientServiceDisconnect
* ClientServiceSetMessageHandler
* FrameScriptRegisterFunction
* FrameScriptUnregisterFunction
* SetMessageHandler
* CGGameObjectInitialize

## How to use
* Download source
* Compile the source with Visual Studio
* Move the SHInject01.dll in the World of Warcraft main directory
* Inject the dll with a dll Injector in the World of Warcraft process.

## Thanks
* Cromon for a lot of help <3
* Nesox for http://tinyurl.com/p7eduq9
* tomrus88 for http://tinyurl.com/pbr6sbg

## Team
* Luzifix
