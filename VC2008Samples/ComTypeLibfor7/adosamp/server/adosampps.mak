
ADOSampps.dll: dlldata.obj ADOSamp_p.obj ADOSamp_i.obj
	link /dll /out:ADOSampps.dll /def:ADOSampps.def /entry:DllMain dlldata.obj ADOSamp_p.obj ADOSamp_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib uuid.lib ole32.lib oleaut32.lib
.c.obj:
	cl /c /Ox /DWIN32 /DREGISTER_PROXY_DLL /D_WIN32_WINNT=0x400 $<

clean:
	@del ADOSampps.dll
	@del ADOSampps.lib
	@del ADOSampps.exp
	@del dlldata.obj
	@del ADOSamp_p.obj
	@del ADOSamp_i.obj
