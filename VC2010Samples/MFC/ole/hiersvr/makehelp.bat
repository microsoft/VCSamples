@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by HIERSVR.HPJ. >"hlp\hiersvr.hm"
echo. >>"hlp\hiersvr.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\hiersvr.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\hiersvr.hm"
echo. >>"hlp\hiersvr.hm"
echo // Prompts (IDP_*) >>"hlp\hiersvr.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\hiersvr.hm"
echo. >>"hlp\hiersvr.hm"
echo // Resources (IDR_*) >>"hlp\hiersvr.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\hiersvr.hm"
echo. >>"hlp\hiersvr.hm"
echo // Dialogs (IDD_*) >>"hlp\hiersvr.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\hiersvr.hm"
echo. >>"hlp\hiersvr.hm"
echo // Frame Controls (IDW_*) >>"hlp\hiersvr.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\hiersvr.hm"
REM -- Make help for Project hiersvr

if "%1" == "?" goto :Error
if "%1" == "/?" goto :Error
if "%1" == "-?" goto :Error
if "%1" == "help" goto :Error
if "%1" == "-help" goto :Error
if "%1" == "/help" goto :Error


if "%1" == "MAC" goto Mac

:Intel
if not "%1" == "" goto :Error
if not "%2" == "" goto :Error

echo Building Win32 Help files
start /wait hcrtf -x hlp\hiersvr.hpj
echo.
if exist Debug\nul if exist hlp\hiersvr.hlp copy "hlp\hiersvr.hlp" Debug
if exist Debug\nul if exist hlp\hiersvr.cnt copy "hlp\hiersvr.cnt" Debug
if exist Release\nul if exist hlp\hiersvr.hlp copy "hlp\hiersvr.hlp" Release
if exist Release\nul if exist hlp\hiersvr.cnt copy "hlp\hiersvr.cnt" Release
if exist UniDebug\nul if exist hlp\hiersvr.hlp copy "hlp\hiersvr.hlp" UniDebug
if exist UniDebug\nul if exist hlp\hiersvr.cnt copy "hlp\hiersvr.cnt" UniDebug
if exist UniRelease\nul if exist hlp\hiersvr.hlp copy "hlp\hiersvr.hlp" UniRelease
if exist UniRelease\nul if exist hlp\hiersvr.cnt copy "hlp\hiersvr.cnt" UniRelease
goto :done

:Mac
echo Building Macintosh Help files
call hc35 hlp\hierMac.hpj

if %2x == x goto :done
echo Copying to remote machine
mfile copy -c MSH2 -t HELP "hierMac.hlp" %2
goto :done

:Error
echo Usage MAKEHELP [MAC [macintosh-path]]
echo       Where macintosh-path is of the form:
echo       ":<MacintoshName>:...:<MacintoshHelpFile>"

:done
echo.
