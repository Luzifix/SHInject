/*
Copyright TomRus88
Link: https://github.com/tomrus88/WowAddin/blob/master/WowAddin/CDataStore.h
*/
class CDataStore;

typedef CDataStore* (__thiscall *InitializePtr)(CDataStore *pData);
typedef CDataStore& (__thiscall *PutInt8Ptr)(CDataStore *pData, INT8 val);
typedef CDataStore& (__thiscall *PutInt16Ptr)(CDataStore *pData, INT16 val);
typedef CDataStore& (__thiscall *PutInt32Ptr)(CDataStore *pData, INT32 val);
typedef CDataStore& (__thiscall *PutInt64Ptr)(CDataStore *pData, INT64 val);
typedef CDataStore& (__thiscall *PutFloatPtr)(CDataStore *pData, float val);
typedef CDataStore& (__thiscall *PutStringPtr)(CDataStore *pData, char const* pString);
typedef CDataStore& (__thiscall *PutBytesPtr)(CDataStore *pData, UINT8* pBuf, UINT32 size);

typedef CDataStore& (__thiscall *GetInt8Ptr)(CDataStore *pData, INT8& val);
typedef CDataStore& (__thiscall *GetInt16Ptr)(CDataStore *pData, INT16& val);
typedef CDataStore& (__thiscall *GetInt32Ptr)(CDataStore *pData, INT32& val);
typedef CDataStore& (__thiscall *GetInt64Ptr)(CDataStore *pData, INT64& val);
typedef CDataStore& (__thiscall *GetFloatPtr)(CDataStore *pData, float& val);
typedef CDataStore& (__thiscall *GetStringPtr)(CDataStore *pData, char* pString, UINT32 maxChars);
typedef CDataStore& (__thiscall *GetBytesPtr)(CDataStore *pData, UINT8* pBuf, UINT32 numBytes);

typedef void(__thiscall *FinalizePtr)(CDataStore *pData);
typedef void(__thiscall *DestroyPtr)(CDataStore *pData);

class CDataStore
{
private:
	virtual void Dummy() {};

	UINT8 *m_buffer;
	UINT32 m_base;
	UINT32 m_alloc;
	UINT32 m_size;
	UINT32 m_read;

	static InitializePtr fpInit;
	static PutInt8Ptr fpPutInt8;
	static PutInt16Ptr fpPutInt16;
	static PutInt32Ptr fpPutInt32;
	static PutInt64Ptr fpPutInt64;
	static PutFloatPtr fpPutFloat;
	static PutStringPtr fpPutString;
	static PutBytesPtr fpPutBytes;
	static GetInt8Ptr fpGetInt8;
	static GetInt16Ptr fpGetInt16;
	static GetInt32Ptr fpGetInt32;
	static GetInt64Ptr fpGetInt64;
	static GetFloatPtr fpGetFloat;
	static GetStringPtr fpGetString;
	static GetBytesPtr fpGetBytes;
	static FinalizePtr fpFinalize;
	static DestroyPtr fpDestroy;
public:
	CDataStore() { fpInit(this); }
	~CDataStore() { fpDestroy(this); }
	CDataStore(Opcodes msg) { fpInit(this); fpPutInt32(this, msg); }

	CDataStore& PutINT8(INT8 val) { return fpPutInt8(this, val); }
	CDataStore& PutInt16(INT16 val) { return fpPutInt16(this, val); }
	CDataStore& PutInt32(INT32 val) { return fpPutInt32(this, val); }
	CDataStore& PutInt64(INT64 val) { return fpPutInt64(this, val); }
	CDataStore& PutFloat(float val) { return fpPutFloat(this, val); }
	CDataStore& PutString(char const* pString) { return fpPutString(this, pString); }
	CDataStore& PutPutBytes(UINT8* pBuf, UINT32 size) { return fpPutBytes(this, pBuf, size); }

	CDataStore& GetINT8(INT8& val) { return fpGetInt8(this, val); }
	CDataStore& GetInt16(INT16& val) { return fpGetInt16(this, val); }
	CDataStore& GetInt32(INT32& val) { return fpGetInt32(this, val); }
	CDataStore& GetInt64(INT64& val) { return fpGetInt64(this, val); }
	CDataStore& GetFloat(float& val) { return fpGetFloat(this, val); }
	CDataStore& GetString(char* pString, UINT32 maxChars) { return fpGetString(this, pString, maxChars); }
	CDataStore& GetBytes(UINT8* pBuf, UINT32 numBytes) { return fpGetBytes(this, pBuf, numBytes); }

	void Finalize() { fpFinalize(this); }
};
