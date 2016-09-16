
# This is a part of the Active Template Library.
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
# This source code is only intended as a supplement to the
# Active Template Library Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Active Template Library product.

CircCops.dll: dlldata.obj CircColl_p.obj CircColl_i.obj
	link /dll /out:CircCops.dll /def:CircCops.def \
		/entry:DllMain dlldata.obj CircColl_p.obj \
		CircColl_i.obj kernel32.lib rpcndr.lib \
		rpcns4.lib rpcrt4.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /DREGISTER_PROXY_DLL $<

clean:
	@del CircCops.dll
	@del CircCops.lib
	@del CircCops.exp
	@del dlldata.obj
	@del CircColl_p.obj
	@del CircColl_i.obj
