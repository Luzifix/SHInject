#include "Header.h"

void(*ClientCommunication::SetMessageHandler)(Opcodes msgId, PacketHandler handler, void *param) = reinterpret_cast<CC_SetMessageHandler>(ClientServiceSetMessageHandlerAddr);
void(*ClientCommunication::RemoveMessageHandler)(Opcodes msgId) = reinterpret_cast<CC_RemoveMessageHandler>(ClientServiceRemoveMessageHandlerAddr);
void(*ClientCommunication::Disconnect)() = reinterpret_cast<CC_Disconnect>(ClientServiceDisconnectAddr);
void* (*ClientCommunication::fGetCurrent)() = reinterpret_cast<CC_GetCurrent>(ClientServiceGetCurrentAddr);
void* (*ClientCommunication::fGetSessionKey)() = reinterpret_cast<CC_GetSessionKey>(ClientServiceGetSessionKeyAddr);
void(__thiscall *ClientCommunication::fSendPacket)(void *object, CDataStore *data) = reinterpret_cast<CC_SendPacket>(ClientServiceSendPacketAddr);
void(*ClientCommunication::fSendGamePacket)(CDataStore *data) = reinterpret_cast<CC_SendGamePacket>(ClientServiceSendGamePacketAddr);

