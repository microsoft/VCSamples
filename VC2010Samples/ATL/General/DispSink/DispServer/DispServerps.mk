
DispServerps.dll: dlldata.obj DispServer_p.obj DispServer_i.obj
	link /dll /out:DispServerps.dll /def:DispServerps.def /entry:DllMain dlldata.obj DispServer_p.obj DispServer_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del DispServerps.dll
	@del DispServerps.lib
	@del DispServerps.exp
	@del dlldata.obj
	@del DispServer_p.obj
	@del DispServer_i.obj
