#include "Header.h"

typedef int(__cdecl* ClientInitializeGame)(int arg1, int arg2, int arg3, int arg4);
typedef int(__cdecl* FrameScriptRegisterFunction)(const char* command, void *func);
typedef int(__cdecl* FrameScriptUnregisterFunction)(const char* command);
typedef int(__cdecl* ClientServiceSetMessageHandler)(Opcodes msgId, int func, void *param);
typedef int(__cdecl* ClientServiceRemoveMessageHandler)(Opcodes msgId);
typedef int(__fastcall* ClientServiceSendPacket)(int object, CDataStore *data);
typedef int(__cdecl* ClientServiceSendGamePacket)(CDataStore *data);
typedef int(__cdecl* ClientServiceDisconnect)();
typedef int(__cdecl* CGGameObjectInitialize)();

ClientInitializeGame				oClientInitializeGame;
FrameScriptRegisterFunction			oFrameScriptRegisterFunction;
FrameScriptUnregisterFunction		oFrameScriptUnregisterFunction;
ClientServiceSetMessageHandler		oClientServiceSetMessageHandler;
ClientServiceRemoveMessageHandler	oClientServiceRemoveMessageHandler;
ClientServiceSendPacket				oClientServiceSendPacket;
ClientServiceSendGamePacket			oClientServiceSendGamePacket;
ClientServiceDisconnect				oClientServiceDisconnect;
CGGameObjectInitialize				oCGGameObjectInitialize;

int __cdecl onClientInitializeGame(int arg1, int arg2, int arg3, int arg4)
{
	ClientEvent::onClientInitializeGame(arg1, arg2, arg3, arg4);
	return oClientInitializeGame(arg1, arg2, arg3, arg4);
}
int __cdecl onFrameScriptRegisterFunction(const char* command, void *func)
{	
	ClientEvent::onFrameScriptRegisterFunction(command, func);
	return oFrameScriptRegisterFunction(command, func);
}
int __cdecl onFrameScriptUnregisterFunction(const char* command, void *func)
{
	ClientEvent::onFrameScriptUnregisterFunction(command);
	return oFrameScriptUnregisterFunction(command);
}
int __cdecl onClientServiceSetMessageHandler(Opcodes msgId, int func, void *param)
{
	ClientEvent::onClientServiceSetMessageHandler(msgId, func, param);
	return oClientServiceSetMessageHandler(msgId, func, param);
}

int __cdecl onClientServiceRemoveMessageHandler(Opcodes msgId)
{
	ClientEvent::onClientServiceRemoveMessageHandler(msgId);
	return oClientServiceRemoveMessageHandler(msgId);
}
//int __fastcall onClientServiceSendPacket(int object, CDataStore *data)
//{
//	//Not Work
//	ClientEvent::onClientServiceSendPacket(object, data);
//	return oClientServiceSendPacket(object, data);
//}
int __cdecl onClientServiceSendGamePacket(CDataStore *data)
{
	ClientEvent::onClientServiceSendGamePacket(data);
	return oClientServiceSendGamePacket(data);
}
int __cdecl onClientServiceDisconnect()
{
	ClientEvent::onClientServiceDisconnect();
	return oClientServiceDisconnect();
}

int __cdecl onCGGameObjectInitialize()
{
	ClientEvent::onCGGameObjectInitialize();
	return oCGGameObjectInitialize();
}

void DetoursMgr::Initialize(){
	oClientInitializeGame				= (ClientInitializeGame)DetourFunction((PBYTE)ClientInitializeGameAddr, (PBYTE)onClientInitializeGame);
	oFrameScriptRegisterFunction		= (FrameScriptRegisterFunction)DetourFunction((PBYTE)FrameScriptRegisterFunctionAddr, (PBYTE)onFrameScriptRegisterFunction);
	oFrameScriptUnregisterFunction		= (FrameScriptUnregisterFunction)DetourFunction((PBYTE)FrameScriptUnregisterFunctionAddr, (PBYTE)onFrameScriptUnregisterFunction);
	oClientServiceSetMessageHandler		= (ClientServiceSetMessageHandler)DetourFunction((PBYTE)ClientServiceSetMessageHandlerAddr, (PBYTE)onClientServiceSetMessageHandler);
	oClientServiceRemoveMessageHandler	= (ClientServiceRemoveMessageHandler)DetourFunction((PBYTE)ClientServiceRemoveMessageHandlerAddr, (PBYTE)onClientServiceRemoveMessageHandler);
	//oClientServiceSendPacket			= (ClientServiceSendPacket)DetourFunction((PBYTE)ClientServiceSendPacketAddr, (PBYTE)onClientServiceSendPacket); //Not Work
	oClientServiceSendGamePacket		= (ClientServiceSendGamePacket)DetourFunction((PBYTE)ClientServiceSendGamePacketAddr, (PBYTE)onClientServiceSendGamePacket);
	oClientServiceDisconnect			= (ClientServiceDisconnect)DetourFunction((PBYTE)ClientServiceDisconnectAddr, (PBYTE)onClientServiceDisconnect);
	oCGGameObjectInitialize				= (CGGameObjectInitialize)DetourFunction((PBYTE)CGGameObjectInitializeAddr, (PBYTE)onCGGameObjectInitialize);
}
