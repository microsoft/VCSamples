@echo off
REM -- First, make map file from resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by TESTHELP.HPJ. >hlp\testhelp.hm
echo. >>hlp\testhelp.hm
echo // Commands (ID_* and IDM_*) >>hlp\testhelp.hm
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>hlp\testhelp.hm
echo. >>hlp\testhelp.hm
echo // Prompts (IDP_*) >>hlp\testhelp.hm
makehm IDP_,HIDP_,0x30000 resource.h >>hlp\testhelp.hm
echo. >>hlp\testhelp.hm
echo // Resources (IDR_*) >>hlp\testhelp.hm
makehm IDR_,HIDR_,0x20000 resource.h >>hlp\testhelp.hm
echo. >>hlp\testhelp.hm
echo // Dialogs (IDD_*) >>hlp\testhelp.hm
makehm IDD_,HIDD_,0x20000 resource.h >>hlp\testhelp.hm
echo. >>hlp\testhelp.hm
echo // Frame Controls (IDW_*) >>hlp\testhelp.hm
makehm IDW_,HIDW_,0x50000 resource.h >>hlp\testhelp.hm


REM Appwizard generates a call lto hc31.exe to build your
REM help file.  Since hc31.exe does not ship with VC++
REM anymore, you can just use the Help Workshop (hcw.exe)
REM to edit and build your help project.

REM -- Make help for Project TESTHELP
 call hcw /c /m /e testhelp.hpj
 echo.
