@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by SCRIBBLE.HPJ. >"hlp\Scribble.hm"
echo. >>"hlp\Scribble.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Scribble.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Scribble.hm"
echo. >>"hlp\Scribble.hm"
echo // Prompts (IDP_*) >>"hlp\Scribble.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Scribble.hm"
echo. >>"hlp\Scribble.hm"
echo // Resources (IDR_*) >>"hlp\Scribble.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Scribble.hm"
echo. >>"hlp\Scribble.hm"
echo // Dialogs (IDD_*) >>"hlp\Scribble.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Scribble.hm"
echo. >>"hlp\Scribble.hm"
echo // Frame Controls (IDW_*) >>"hlp\Scribble.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Scribble.hm"
REM -- Make help for Project SCRIBBLE

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
start /wait hcrtf -x "hlp\Scribble.hpj"
echo.
if exist Debug\nul if exist hlp\Scribble.hlp copy "hlp\Scribble.hlp" Debug
if exist Debug\nul if exist hlp\Scribble.cnt copy "hlp\Scribble.cnt" Debug
if exist Release\nul if exist hlp\Scribble.hlp copy "hlp\Scribble.hlp" Release
if exist Release\nul if exist hlp\Scribble.cnt copy "hlp\Scribble.cnt" Release
goto :done

:Mac
echo Building Macintosh Help files
call hc35 hlp\ScriMac.hpj

if %2x == x goto :done
echo Copying to remote machine
mfile copy -c MSH2 -t HELP "ScriMac.hlp" %2
goto :done

:Error
echo Usage MAKEHELP [MAC [macintosh-path]]
echo       Where macintosh-path is of the form:
echo       ":<MacintoshName>:...:<MacintoshHelpFile>"

:done
echo.

