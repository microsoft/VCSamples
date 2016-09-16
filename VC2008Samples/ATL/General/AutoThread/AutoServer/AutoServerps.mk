
AutoServerps.dll: dlldata.obj AutoServer_p.obj AutoServer_i.obj
	link /dll /out:AutoServerps.dll /def:AutoServerps.def /entry:DllMain dlldata.obj AutoServer_p.obj AutoServer_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del AutoServerps.dll
	@del AutoServerps.lib
	@del AutoServerps.exp
	@del dlldata.obj
	@del AutoServer_p.obj
	@del AutoServer_i.obj
