
atlduckps.dll: dlldata.obj atlduck_p.obj atlduck_i.obj
	link /dll /out:atlduckps.dll /def:atlduckps.def /entry:DllMain dlldata.obj atlduck_p.obj atlduck_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib uuid.lib 
.c.obj:
	cl /D_DEBUG /DDEBUG /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL $<

clean:
	@del atlduckps.dll
	@del atlduckps.lib
	@del atlduckps.exp
	@del dlldata.obj
	@del atlduck_p.obj
	@del atlduck_i.obj
