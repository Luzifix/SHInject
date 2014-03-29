typedef bool(__cdecl *PacketHandler)(void *param, Opcodes msgId, int time, CDataStore *msg);

typedef void(*CC_SetMessageHandler)(Opcodes msgId, PacketHandler handler, void *param);
typedef void(*CC_RemoveMessageHandler)(Opcodes msgId);
typedef void(*CC_Disconnect)();
typedef void*(__cdecl *CC_GetCurrent)();
typedef void*(__cdecl *CC_GetSessionKey)();
typedef void(__thiscall *CC_SendPacket)(void *object, CDataStore *data);
typedef void(__cdecl *CC_SendGamePacket)(CDataStore *data);


class ClientCommunication
{
public:
	static	CC_SetMessageHandler	SetMessageHandler;
	static	CC_RemoveMessageHandler	RemoveMessageHandler;
	static	CC_Disconnect			Disconnect;
	static	void					SendPacket(CDataStore *data) { data->Finalize(); fSendPacket(GetCurrent(), data); }
	static	void					SendGamePacket(CDataStore *data) { data->Finalize(); fSendGamePacket(data); }
	static	void					*GetCurrent() { return fGetCurrent(); }
	static	void					*GetGetSessionKey() { return fGetSessionKey(); }
private:
	static	CC_GetCurrent			fGetCurrent;
	static	CC_GetSessionKey		fGetSessionKey;
	static	CC_SendPacket			fSendPacket;
	static	CC_SendGamePacket		fSendGamePacket;
};
