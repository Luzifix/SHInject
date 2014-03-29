/*
Copyright TomRus88
Link: https://github.com/tomrus88/WowAddin/blob/master/WowAddin/CDataStore.cpp
*/
#include "Header.h"

CDataStore* (__thiscall *CDataStore::fpInit)(CDataStore *pData) = reinterpret_cast<InitializePtr>(0x00401050);

CDataStore& (__thiscall *CDataStore::fpPutInt8)(CDataStore *pData, INT8 val) = reinterpret_cast<PutInt8Ptr>(0x0047AFE0);
CDataStore& (__thiscall *CDataStore::fpPutInt16)(CDataStore *pData, INT16 val) = reinterpret_cast<PutInt16Ptr>(0x0047B040);
CDataStore& (__thiscall *CDataStore::fpPutInt32)(CDataStore *pData, INT32 val) = reinterpret_cast<PutInt32Ptr>(0x0047B0A0);
CDataStore& (__thiscall *CDataStore::fpPutInt64)(CDataStore *pData, INT64 val) = reinterpret_cast<PutInt64Ptr>(0x0047B100);
CDataStore& (__thiscall *CDataStore::fpPutFloat)(CDataStore *pData, float val) = reinterpret_cast<PutFloatPtr>(0x0047B160);
CDataStore& (__thiscall *CDataStore::fpPutString)(CDataStore *pData, char const* pString) = reinterpret_cast<PutStringPtr>(0x0047B300);
CDataStore& (__thiscall *CDataStore::fpPutBytes)(CDataStore *pData, UINT8* pBuf, UINT32 size) = reinterpret_cast<PutBytesPtr>(0x0047B1C0);

CDataStore& (__thiscall *CDataStore::fpGetInt8)(CDataStore *pData, INT8& val) = reinterpret_cast<GetInt8Ptr>(0x0047B340);
CDataStore& (__thiscall *CDataStore::fpGetInt16)(CDataStore *pData, INT16& val) = reinterpret_cast<GetInt16Ptr>(0x0047B380);
CDataStore& (__thiscall *CDataStore::fpGetInt32)(CDataStore *pData, INT32& val) = reinterpret_cast<GetInt32Ptr>(0x0047B3C0);
CDataStore& (__thiscall *CDataStore::fpGetInt64)(CDataStore *pData, INT64& val) = reinterpret_cast<GetInt64Ptr>(0x0047B400);
CDataStore& (__thiscall *CDataStore::fpGetFloat)(CDataStore *pData, float& val) = reinterpret_cast<GetFloatPtr>(0x0047B440);
CDataStore& (__thiscall *CDataStore::fpGetString)(CDataStore *pData, char* pString, UINT32 maxChars) = reinterpret_cast<GetStringPtr>(0x0047B480);
CDataStore& (__thiscall *CDataStore::fpGetBytes)(CDataStore *pData, UINT8* pBuf, UINT32 numBytes) = reinterpret_cast<GetBytesPtr>(0x0047B560);

void(__thiscall *CDataStore::fpFinalize)(CDataStore *pData) = reinterpret_cast<FinalizePtr>(0x00401130);
void(__thiscall *CDataStore::fpDestroy)(CDataStore *pData) = reinterpret_cast<DestroyPtr>(0x00403880);
