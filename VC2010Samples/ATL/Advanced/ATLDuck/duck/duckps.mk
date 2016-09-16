
duckps.dll: dlldata.obj duck_p.obj duck_i.obj
	link /dll /out:duckps.dll /def:duckps.def /entry:DllMain dlldata.obj duck_p.obj duck_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib uuid.lib oleaut32.lib
.c.obj:
	cl /Zi /D_DEBUG /DDEBUG /D_WIN32_WINNT=0x0400 /c /Ox /DWIN32 /DREGISTER_PROXY_DLL $<

clean:
	@del duckps.dll
	@del duckps.lib
	@del duckps.exp
	@del dlldata.obj
	@del duck_p.obj
	@del duck_i.obj
