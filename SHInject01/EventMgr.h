class EventMgr
{
public:
	static void onClientInitializeGame(int arg1, int arg2, int arg3, int arg4);
	static void onFrameScriptRegisterFunction(const char* command, void *func);
	static void onFrameScriptUnregisterFunction(const char* command);
	static void onSetMessageHandler(int msgId, int handler, void *param);
	static void onCGGameObjectInitialize();
};