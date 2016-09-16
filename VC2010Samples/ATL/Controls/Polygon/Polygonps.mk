
Polygonps.dll: dlldata.obj Polygon_p.obj Polygon_i.obj
	link /dll /out:Polygonps.dll /def:Polygonps.def /entry:DllMain dlldata.obj Polygon_p.obj Polygon_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del Polygonps.dll
	@del Polygonps.lib
	@del Polygonps.exp
	@del dlldata.obj
	@del Polygon_p.obj
	@del Polygon_i.obj
