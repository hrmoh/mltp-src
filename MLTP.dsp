# Microsoft Developer Studio Project File - Name="MLTP" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=MLTP - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MLTP.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MLTP.mak" CFG="MLTP - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MLTP - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MLTP - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MLTP - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "MLTP - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "MLTP - Win32 Release"
# Name "MLTP - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AcDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AnounceDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DDFAFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\DeleteProduction.cpp
# End Source File
# Begin Source File

SOURCE=.\DerivationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DFA.cpp
# End Source File
# Begin Source File

SOURCE=.\DFAFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\EditDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Grammar.cpp
# End Source File
# Begin Source File

SOURCE=.\MLTP.cpp
# End Source File
# Begin Source File

SOURCE=.\MLTP.rc
# End Source File
# Begin Source File

SOURCE=.\MLTPDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NewgrammarDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NewTerminal.cpp
# End Source File
# Begin Source File

SOURCE=.\NewVarDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NFA.cpp
# End Source File
# Begin Source File

SOURCE=.\PDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\Production.cpp
# End Source File
# Begin Source File

SOURCE=.\RegularGrammar.cpp
# End Source File
# Begin Source File

SOURCE=.\RGInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\SAccepted.cpp
# End Source File
# Begin Source File

SOURCE=.\SAcception.cpp
# End Source File
# Begin Source File

SOURCE=.\State.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TFMember.cpp
# End Source File
# Begin Source File

SOURCE=.\TransitionFunction.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AcDlg.h
# End Source File
# Begin Source File

SOURCE=.\AnounceDlg.h
# End Source File
# Begin Source File

SOURCE=.\DDFAFrame.h
# End Source File
# Begin Source File

SOURCE=.\DeleteProduction.h
# End Source File
# Begin Source File

SOURCE=.\DerivationDlg.h
# End Source File
# Begin Source File

SOURCE=.\DetDlg.h
# End Source File
# Begin Source File

SOURCE=.\DFA.h
# End Source File
# Begin Source File

SOURCE=.\DFAFrame.h
# End Source File
# Begin Source File

SOURCE=.\EditDlg.h
# End Source File
# Begin Source File

SOURCE=.\Grammar.h
# End Source File
# Begin Source File

SOURCE=.\MLTP.h
# End Source File
# Begin Source File

SOURCE=.\MLTPDlg.h
# End Source File
# Begin Source File

SOURCE=.\NewgrammarDlg.h
# End Source File
# Begin Source File

SOURCE=.\NewTerminal.h
# End Source File
# Begin Source File

SOURCE=.\NewVarDlg.h
# End Source File
# Begin Source File

SOURCE=.\NFA.h
# End Source File
# Begin Source File

SOURCE=.\PDlg.h
# End Source File
# Begin Source File

SOURCE=.\PInfo.h
# End Source File
# Begin Source File

SOURCE=.\Production.h
# End Source File
# Begin Source File

SOURCE=.\RegularGrammar.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RGInfo.h
# End Source File
# Begin Source File

SOURCE=.\SAccepted.h
# End Source File
# Begin Source File

SOURCE=.\SAcception.h
# End Source File
# Begin Source File

SOURCE=.\State.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TFMember.h
# End Source File
# Begin Source File

SOURCE=.\TransitionFunction.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\MLTP.ico
# End Source File
# Begin Source File

SOURCE=.\res\MLTP.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
