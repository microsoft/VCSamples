# This is a part of the ActiveX Template Library.
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
# This source code is only intended as a supplement to the
# ActiveX Template Library Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# ActiveX Template Library product.

Labps.dll: dlldata.obj labrador_p.obj Labrador_i.obj
	link /dll /out:Labps.dll /def:Labps.def /entry:DllMain \
		dlldata.obj labrador_p.obj Labrador_i.obj kernel32.lib rpcndr.lib \
		rpcns4.lib rpcrt4.lib uuid.lib

.c.obj:
	cl /c /Ox /DWIN32 /DREGISTER_PROXY_DLL $<
dlldata.obj : dlldata.c
dlldata.c labrador_p.c:
	midl /h labrador_i.h labrador.idl
labrador_p.obj: labrador_p.c

clean:
	@del Labps.dll
	@del Labps.lib
	@del Labps.exp
	@del dlldata.obj
	@del labrador_p.obj
	@del Labrador_i.obj
