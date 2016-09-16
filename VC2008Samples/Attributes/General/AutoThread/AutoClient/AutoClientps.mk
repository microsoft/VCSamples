
AutoClientps.dll: dlldata.obj AutoClient_p.obj AutoClient_i.obj
	link /dll /out:AutoClientps.dll /def:AutoClientps.def /entry:DllMain dlldata.obj AutoClient_p.obj AutoClient_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del AutoClientps.dll
	@del AutoClientps.lib
	@del AutoClientps.exp
	@del dlldata.obj
	@del AutoClient_p.obj
	@del AutoClient_i.obj
