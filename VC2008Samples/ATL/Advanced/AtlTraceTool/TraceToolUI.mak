!ifndef DEBUG
DEBUG=1
!endif

TARGETNAME=AtlTraceTool
RCFILE=TraceTool.rc


# Default PLATFORM depending on host environment
!if "$(PLATFORM)" == ""
!if "$(PROCESSOR_ARCHITECTURE)" == ""
!error PLATFORM must be set to intended target
!endif
!if "$(PROCESSOR_ARCHITECTURE)" == "x86"
PLATFORM=INTEL
!endif
!endif



#
# PLATFORM options
#
LINK32=link
RC=rc


#
# Object File Directory
#
!ifndef D
!if "$(DEBUG)" == "0"
D=Release$(_OD_EXT)
!else
D=Debug$(_OD_EXT)
!endif
!if "$(UNICODE)" == "1"
D=$(D)U
!endif
!endif


DEFS=$(DEFS) $(DEBDEFS) $(TARGDEFS)
RCFLAGS=$(RCFLAGS) /l 0x409 $(DEFS)

#############################################################################
# Goals to build

GOALS=resource_dll
goal: $(GOALS)

create.dir:
	@-if not exist $D\*.* mkdir $D

clean:
	-if exist $D\*.obj erase $D\*.obj
	-if exist $D\*.pch erase $D\*.pch
	-if exist $D\*.res erase $D\*.res
	-if exist $D\*.rsc erase $D\*.rsc
	-if exist $D\*.map erase $D\*.map
	-if exist $D\*.pdb erase $D\*.pdb
	-if exist $D\*.tlb erase $D\*.tlb
	-if exist $D\*.h erase $D\*.h
	-if not exist $D\*.* rmdir $D


RESFILE=$(D)\$(RCFILE:.rc=.res)


resource_dll:
	-if not exist $(D) mkdir $(D)
	$(RC) $(RCFLAGS) /fo$(RESFILE) $(RCFILE)
	-if not exist $(D)\1033 mkdir $(D)\1033
	$(LINK32) $(RESFILE) /MACHINE:$(PROCESSOR_ARCHITECTURE) -DLL -NOENTRY /out:$(D)\1033\$(TARGETNAME)UI.dll
	