# This is a part of the Active Template Library.
# Copyright (c) Microsoft Corporation.  All rights reserved.
# 
# This source code is only intended as a supplement to the
# Active Template Library Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Active Template Library product.

COMMapps.dll: dlldata.obj COMMap_p.obj COMMap_i.obj
	link /dll /out:COMMapps.dll /def:COMMapps.def /entry:DllMain \
		dlldata.obj COMMap_p.obj COMMap_i.obj kernel32.lib \
		rpcndr.lib rpcns4.lib rpcrt4.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /DREGISTER_PROXY_DLL $<

clean:
	@del COMMapps.dll
	@del COMMapps.lib
	@del COMMapps.exp
	@del dlldata.obj
	@del COMMap_p.obj
	@del COMMap_i.obj
 
