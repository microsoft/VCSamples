# This is a part of the Active Template Library.
# Copyright (c) Microsoft Corporation.  All rights reserved.
# 
# This source code is only intended as a supplement to the
# Active Template Library Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Active Template Library product.

Aggregps.dll: dlldata.obj Aggreg_p.obj Aggreg_i.obj
	link /dll /out:Aggregps.dll /def:Aggregps.def \
		/entry:DllMain dlldata.obj Aggreg_p.obj \
		Aggreg_i.obj kernel32.lib rpcndr.lib rpcns4.lib \
		rpcrt4.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /DREGISTER_PROXY_DLL $<

clean:
	@del Aggregps.dll
	@del Aggregps.lib
	@del Aggregps.exp
	@del dlldata.obj
	@del Aggreg_p.obj
	@del Aggreg_i.obj
