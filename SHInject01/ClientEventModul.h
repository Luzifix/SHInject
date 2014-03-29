class ClientEvent
{
public:
	static void onClientInitializeGame(int arg1, int arg2, int arg3, int arg4);
	static void onFrameScriptRegisterFunction(const char* command, void *func);
	static void onFrameScriptUnregisterFunction(const char* command);
	static void onClientServiceSetMessageHandler(Opcodes msgId, int func, void *param);
	static void onClientServiceRemoveMessageHandler(Opcodes msgId);
	static void onClientServiceSendPacket(int object, CDataStore *data);
	static void onClientServiceSendGamePacket(CDataStore *data);
	static void onClientServiceDisconnect();
	static void onCGGameObjectInitialize();
};