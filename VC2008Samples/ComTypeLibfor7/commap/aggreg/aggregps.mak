Aggregps.dll: dlldata.obj Aggreg_p.obj Aggreg_i.obj
	link /dll /out:Aggregps.dll /def:Aggregps.def /entry:DllMain dlldata.obj Aggreg_p.obj Aggreg_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /DREGISTER_PROXY_DLL $<

clean:
	@del Aggregps.dll
	@del Aggregps.lib
	@del Aggregps.exp
	@del dlldata.obj
	@del Aggreg_p.obj
	@del Aggreg_i.obj
