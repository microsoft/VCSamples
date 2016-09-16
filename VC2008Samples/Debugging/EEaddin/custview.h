typedef struct tagDEBUGHELPER
{
	DWORD dwVersion;
	HRESULT (WINAPI *ReadDebuggeeMemory)( struct tagDEBUGHELPER *pThis, DWORD dwAddr, DWORD nWant, VOID* pWhere, DWORD *nGot );
	// from here only when dwVersion >= 0x20000
	DWORDLONG (WINAPI *GetRealAddress)( struct tagDEBUGHELPER *pThis );
	HRESULT (WINAPI *ReadDebuggeeMemoryEx)( struct tagDEBUGHELPER *pThis, DWORDLONG qwAddr, DWORD nWant, VOID* pWhere, DWORD *nGot );
	int (WINAPI *GetProcessorType)( struct tagDEBUGHELPER *pThis );
} DEBUGHELPER;

typedef HRESULT (WINAPI *CUSTOMVIEWER)( DWORD dwAddress, DEBUGHELPER *pHelper, int nBase, BOOL bUniStrings, char *pResult, size_t max, DWORD reserved );
