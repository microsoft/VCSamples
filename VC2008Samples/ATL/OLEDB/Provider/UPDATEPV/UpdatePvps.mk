
UpdatePvps.dll: dlldata.obj UpdatePv_p.obj UpdatePv_i.obj
	link /dll /out:UpdatePvps.dll /def:UpdatePvps.def /entry:DllMain dlldata.obj UpdatePv_p.obj UpdatePv_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del UpdatePvps.dll
	@del UpdatePvps.lib
	@del UpdatePvps.exp
	@del dlldata.obj
	@del UpdatePv_p.obj
	@del UpdatePv_i.obj
