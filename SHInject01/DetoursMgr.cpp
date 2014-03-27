#include "Header.h"

typedef int(__cdecl* ClientInitializeGame)(int arg1, int arg2, int arg3, int arg4);
typedef int(__cdecl* FrameScriptRegisterFunction)(const char* command, void *func);
typedef int(__cdecl* FrameScriptUnregisterFunction)(const char* command);

typedef int(__cdecl* SetMessageHandler)(int msgId, int handler, void *param);
typedef int(__cdecl* CGGameObjectInitialize)();

ClientInitializeGame			oClientInitializeGame;
FrameScriptRegisterFunction		oFrameScriptRegisterFunction;
FrameScriptUnregisterFunction	oFrameScriptUnregisterFunction;
SetMessageHandler				oSetMessageHandler;
CGGameObjectInitialize			oCGGameObjectInitialize;

int __cdecl onClientInitializeGame(int arg1, int arg2, int arg3, int arg4)
{
	EventMgr::onClientInitializeGame(arg1, arg2, arg3, arg4);
	return oClientInitializeGame(arg1, arg2, arg3, arg4);
}
int __cdecl onFrameScriptRegisterFunction(const char* command, void *func)
{	
	EventMgr::onFrameScriptRegisterFunction(command, func);
	return oFrameScriptRegisterFunction(command, func);
}
int __cdecl onFrameScriptUnregisterFunction(const char* command, void *func)
{
	EventMgr::onFrameScriptUnregisterFunction(command);
	return oFrameScriptUnregisterFunction(command);
}
int __cdecl onSetMessageHandler(int msgId, int handler, void *param)
{
	EventMgr::onSetMessageHandler(msgId, handler, param);
	return oSetMessageHandler(msgId, handler, param);
}
int __cdecl onCGGameObjectInitialize()
{
	EventMgr::onCGGameObjectInitialize();
	return oCGGameObjectInitialize();
}



void DetoursMgr::Initialize(){
	oClientInitializeGame			= (ClientInitializeGame)DetourFunction((PBYTE)ClientInitializeGameAddr, (PBYTE)onClientInitializeGame);
	oFrameScriptRegisterFunction	= (FrameScriptRegisterFunction)DetourFunction((PBYTE)FrameScriptRegisterFunctionAddr, (PBYTE)onFrameScriptRegisterFunction);
	oFrameScriptUnregisterFunction	= (FrameScriptUnregisterFunction)DetourFunction((PBYTE)FrameScriptUnregisterFunctionAddr, (PBYTE)onFrameScriptUnregisterFunction);
	oSetMessageHandler				= (SetMessageHandler)DetourFunction((PBYTE)ClientServiceSetMessageHandlerAddr, (PBYTE)onSetMessageHandler);
	oCGGameObjectInitialize			= (CGGameObjectInitialize)DetourFunction((PBYTE)CGGameObjectInitializeAddr, (PBYTE)onCGGameObjectInitialize);
}
