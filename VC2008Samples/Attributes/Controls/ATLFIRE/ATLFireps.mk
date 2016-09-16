
ATLFireps.dll: dlldata.obj ATLFire_p.obj ATLFire_i.obj
	link /dll /out:ATLFireps.dll /def:ATLFireps.def /entry:DllMain dlldata.obj ATLFire_p.obj ATLFire_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL $<

clean:
	@del ATLFireps.dll
	@del ATLFireps.lib
	@del ATLFireps.exp
	@del dlldata.obj
	@del ATLFire_p.obj
	@del ATLFire_i.obj
