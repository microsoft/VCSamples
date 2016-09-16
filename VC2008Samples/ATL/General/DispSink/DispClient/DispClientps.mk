
DispClientps.dll: dlldata.obj DispClient_p.obj DispClient_i.obj
	link /dll /out:DispClientps.dll /def:DispClientps.def /entry:DllMain dlldata.obj DispClient_p.obj DispClient_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del DispClientps.dll
	@del DispClientps.lib
	@del DispClientps.exp
	@del dlldata.obj
	@del DispClient_p.obj
	@del DispClient_i.obj
