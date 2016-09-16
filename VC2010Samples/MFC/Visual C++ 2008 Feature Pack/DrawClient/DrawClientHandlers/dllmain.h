// dllmain.h : Declaration of module class.

class CDrawClientHandlersModule : public CAtlDllModuleT< CDrawClientHandlersModule >
{
public :
	DECLARE_LIBID(LIBID_DrawClientHandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DRAWCLIENTHANDLERS, "{7D291C91-3924-4EAA-A9B1-CEF35C627498}")
};

extern class CDrawClientHandlersModule _AtlModule;
