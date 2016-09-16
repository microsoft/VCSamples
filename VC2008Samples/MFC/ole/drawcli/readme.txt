
	This is a part of the Microsoft Foundation Classes C++ library.
	Copyright (c) Microsoft Corporation
	All rights reserved.

	This source code is only intended as a supplement to the
	Microsoft Foundation Classes Reference and related
	electronic documentation provided with the library.
	See these sources for detailed information regarding the
	Microsoft Foundation Classes product.


-------------------------------------------------------
DRAWCLI Sample Microsoft Foundation Classes Application
-------------------------------------------------------

The DRAWCLI sample application illustrates the integration of OLE container
support with application-specific features, effective use of polymorphism
in C++, and Windows 95 logo compliance.

OLE container support
---------------------
The DRAWCLI was originally a stand-alone drawing application developed using
the MFC classes. The stand-alone version of DRAWCLI was then integrated with
a second skeleton version of DRAWCLI created using AppWizard's OLE Container
feature. This process is similar to how the OLE Visual Editing server tutorial
adds server support to create the Step 7 version of SCRIBBLE.

The design of an MFC OLE container application should look essentially the same,
regardless of whether you're adding OLE functionality to an existing stand-alone
MFC (doc/view) application, or whether you're starting with an AppWizard-generated
OLE container application. The following is a brief description of how DRAWCLI
is separated into application-specific code and OLE container-specific code.

Class CDrawObj, implemented in DRAWOBJ.CPP, is a base class for derived "shape"
classes. This base class handles hit testing of shapes, moving of shapes, and
resizing of shapes. Through the use of polymorphism, DRAWCLI can interact with
objects of different classes through CDrawObj's interface.

Classes CDrawRect and CDrawPoly are derived from CDrawObj. CDrawRect is used to
draw rectangles, rounded rectangles, ellipses, and lines. CDrawPoly is used to
draw polygons. These two classes are independent of DRAWCLI's OLE container
functionality.

Class CDrawOleObj is also derived from CDrawObj, and is used to represent OLE
embedded objects. CDrawOleObj delegates any OLE-specific operation to a contained
CDrawItem object (described below). For generic shape operations, OLE embedded
objects are treated like other shape objects in DRAWCLI because CDrawOleObj is
derived from CDrawObj.

Class CDrawItem, derived from COleClientItem, handles all the OLE-specific behavior
for the OLE embedded object. The implementation of CDrawItem is similar to the
implementation of the COleClientItem-derived classes in the CONTAIN and OCLIENT
samples.

Class CDrawDoc is derived from COleDocument. The document object maintains a
CObjList of CDrawObj objects. CDrawDoc delegates several OLE container-specific
menu commands, such as Edit Paste, Paste Link, and Links, to the base class
COleDocument.

Class CDrawView is derived from CScrollView. The OLE-specific implementation of
CDrawView is similar to the implementation of the view classes in the CONTAIN and
OCLIENT samples. The bulk of DRAWCLI's drawing-specific user interface is also
implemented in CDrawView.


Windows 95 Logo compliance
--------------------------

All MFC applications meet some of the requirements for the Windows 95 logo:
having a Win32 executable, support for long filenames, support for UNC pathnames,
use of system colors and metrics, and compatibility with Windows NT. DRAWCLI
meets the remaining requirements for the Windows 95 logo by including the
following features:
 - OLE support. DRAWCLI is an OLE container that stores its files in
the compound file format, supports in-place activation, and acts as a drop
target for drag-and-drop operations.
 - MAPI support. DRAWCLI provides a "Send as Mail" message on its File menu,
allowing the user to send a document as a mail attachment.
 - Compliance with Win95 shell guidelines, including registration of large and
small icons, use of the system registry instead of an .INI file, and having a
setup and an uninstall program. For the latter, DRAWCLI includes a script
compatible with InstallSHIELD, Stirling Software’s toolkit for creating
setup and uninstall programs.

DRAWCLI also meets the following recommendations for Windows 95 applications:
 - Use of tabbed property pages.
 - Use of Windows 95 common controls.
 - Displays a shortcut menu in response to a right-button mouse click.
 - Storing Summary Information with its documents.

In order to use the setup script (SETUP.RUL), you must first install
InstallSHIELD from the \ishield directory on the CD-ROM. Then create a directory
tree with the following structure:

+--+--DISK1
   |
   +--DATA
	  |
	  +--PROGRAM
	  |
	  +--SHARED
	  |
	  +--SAMPLES
	  |
	  +--HELP

In the DATA directory, create a file named README.TXT (you can use this file).
In the PROGRAM subdirectory, place a copy of DRAWCLI.EXE. In the SHARED
subdirectory, place copies of MFC40.DLL, MFCO40.DLL, and MSVCRT40.DLL. In the
SAMPLES subdirectory, create a file called SAMPLE.DRW. In the HELP subdirectory,
create a file called DUMMY.HLP.(DRAWCLI does not currently support online help;
this file is strictly a placeholder for demonstrating the setup program.)

In the DISK1 directory, create an empty file named DISK1.ID. This acts as a
disk identifier.

Using InstallSHIELD's ICOMP.EXE, compress all the DRAWCLI files into a file
named DATA.Z using the following command:

> icomp data\*.* disk1\data.z -i

Using InstallSHIELD's COMPILE.EXE, compile the script SETUP.RUL into SETUP.INS
using the following command:

> compile setup.rul

Using InstallSHIELD's PACKLIST.EXE, compile the file SETUP.LST into SETUP.PKG
using the following command:

> packlist setup.lst

Copy the following files to a floppy disk:

(from \Program Files\Stirling\InstallSHIELD\Program)
- SETUP.EXE
- UNINST.EXE
- _SETUP.DLL
- _SETUP.LIB
(from the directory where you placed DRAWCLI)
- SETUP.INS
- SETUP.PKG
(from your DISK1 subdirectory)
- DISK1.ID
- DATA.Z

The resulting floppy disk can be used to install DRAWCLI.

See the InstallSHIELD documentation for more information.
