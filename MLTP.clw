; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMLTPDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MLTP.h"

ClassCount=22
Class1=CMLTPApp
Class2=CMLTPDlg
Class3=CAboutDlg

ResourceCount=20
Resource1=IDD_DDFAFRAME
Resource2=IDR_MAINFRAME
Resource3=IDD_MLTP_DIALOG
Resource4=IDD_GRAMMAR_INFO
Resource5=IDR_TOOLBAR1
Class4=CNewgrammarDlg
Resource6=IDD_ACCEPTED
Class5=CNewVarDlg
Class6=CSetAsStartDlg
Resource7=IDD_ANOUNCE
Class7=CDetDlg
Class8=CCombo
Resource8=IDD_DFAFRAME
Class9=CNewTerminal
Resource9=IDD_ABOUTBOX
Class10=CPDlg
Resource10=IDD_PRODUCTIONS
Class11=CRGInfo
Resource11=IDD_DETSTART
Class12=CDFAFrame
Resource12=IDD_NEWGRAMMAR
Class13=CAnounceDlg
Resource13=IDD_STRING_ACCEPTION
Class14=CSAcception
Resource14=IDD_NEWVAR
Class15=CDDFAFrame
Class16=CSAccepted
Resource15=IDD_DERIVATION
Class17=CAcDlg
Resource16=IDD_PRO
Class18=CPInfo
Class19=CToolbar
Resource17=IDD_DIALOG1
Class20=CDerivationDlg
Resource18=IDD_DELETE_PRODUCTION
Class21=CEditDlg
Resource19=IDD_EDIT
Class22=CDeleteProduction
Resource20=IDR_MAINMENU

[CLS:CMLTPApp]
Type=0
HeaderFile=MLTP.h
ImplementationFile=MLTP.cpp
Filter=N

[CLS:CMLTPDlg]
Type=0
HeaderFile=MLTPDlg.h
ImplementationFile=MLTPDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_DFA_MINIMIZE

[CLS:CAboutDlg]
Type=0
HeaderFile=MLTPDlg.h
ImplementationFile=MLTPDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=7
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_MLTP_DIALOG]
Type=1
Class=CMLTPDlg
ControlCount=0

[MNU:IDR_MAINMENU]
Type=1
Class=CMLTPDlg
Command1=ID_GRAMMAR_NEW
Command2=ID_GRAMMAR_EDIT
Command3=ID_GRAMMAR_SUMMARYINFO
Command4=ID_GRAMMAR_EXIT
Command5=ID_DFA_SHOW
Command6=ID_DDFA_SHOW
Command7=ID_DFA_MINIMIZE
Command8=ID_STRING_ACCEPT
Command9=ID_STRING_SUBSTRINGSACCEPTED
Command10=ID_HELP_ABOUT
CommandCount=10

[TB:IDR_TOOLBAR1]
Type=1
Command1=ID_BUTTON32782
Command2=ID_BUTTON32783
Command3=ID_BUTTON32784
Command4=ID_BUTTON32785
Command5=ID_BUTTON32786
Command6=ID_BUTTON32787
CommandCount=6

[DLG:IDD_NEWGRAMMAR]
Type=1
Class=CNewgrammarDlg
ControlCount=6
Control1=IDC_VARIABLES,button,1342242816
Control2=IDC_TERMINALS,button,1342242816
Control3=IDC_DET,button,1342242816
Control4=IDC_PRODUCTIONS,button,1342242816
Control5=IDC_OK,button,1342242816
Control6=IDC_BUTTON5,button,1342242816

[CLS:CNewgrammarDlg]
Type=0
HeaderFile=NewgrammarDlg.h
ImplementationFile=NewgrammarDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CNewgrammarDlg
VirtualFilter=dWC

[DLG:IDD_NEWVAR]
Type=1
Class=CNewVarDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_AOK,button,1342242816
Control4=IDC_ACANCEL,button,1342242816

[CLS:CNewVarDlg]
Type=0
HeaderFile=NewVarDlg.h
ImplementationFile=NewVarDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CNewVarDlg
VirtualFilter=dWC

[CLS:CSetAsStartDlg]
Type=0
HeaderFile=SetAsStartDlg.h
ImplementationFile=SetAsStartDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON3
VirtualFilter=dWC

[DLG:IDD_DETSTART]
Type=1
Class=CDetDlg
ControlCount=4
Control1=IDC_COMBO1,combobox,1344340290
Control2=IDC_AOK,button,1342242816
Control3=IDC_ACANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[CLS:CDetDlg]
Type=0
HeaderFile=DetDlg.h
ImplementationFile=DetDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_ACANCEL
VirtualFilter=dWC

[CLS:CCombo]
Type=0
HeaderFile=Combo.h
ImplementationFile=Combo.cpp
BaseClass=CComboBox
Filter=W

[DLG:IDD_DIALOG1]
Type=1
Class=CNewTerminal
ControlCount=4
Control1=IDC_EDIT1,edit,1350631552
Control2=IDAOK,button,1342242817
Control3=IDACANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[CLS:CNewTerminal]
Type=0
HeaderFile=NewTerminal.h
ImplementationFile=NewTerminal.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CNewTerminal

[CLS:CPDlg]
Type=0
HeaderFile=PDlg.h
ImplementationFile=PDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPDlg

[DLG:IDD_PRO]
Type=1
Class=CPDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_AOK,button,1342242816
Control4=IDC_ACANCEL,button,1342242816

[DLG:IDD_GRAMMAR_INFO]
Type=1
Class=CRGInfo
ControlCount=8
Control1=IDOK,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_VARIABLES,static,1342308352
Control4=IDC_TERMINALS,static,1342308352
Control5=IDC_S,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_PRODUCTIONS,button,1342242816

[CLS:CRGInfo]
Type=0
HeaderFile=RGInfo.h
ImplementationFile=RGInfo.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_PRODUCTIONS

[CLS:CDFAFrame]
Type=0
HeaderFile=DFAFrame.h
ImplementationFile=DFAFrame.cpp
BaseClass=CDialog
Filter=D
LastObject=CDFAFrame
VirtualFilter=dWC

[DLG:IDD_DFAFRAME]
Type=1
Class=CDFAFrame
ControlCount=0

[DLG:IDD_ANOUNCE]
Type=1
Class=CAnounceDlg
ControlCount=0

[CLS:CAnounceDlg]
Type=0
HeaderFile=AnounceDlg.h
ImplementationFile=AnounceDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CAnounceDlg
VirtualFilter=dWC

[DLG:IDD_STRING_ACCEPTION]
Type=1
Class=CSAcception
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_OK,button,1342242816
Control4=IDC_CANCEL,button,1342242816

[CLS:CSAcception]
Type=0
HeaderFile=SAcception.h
ImplementationFile=SAcception.cpp
BaseClass=CDialog
Filter=D
LastObject=CSAcception
VirtualFilter=dWC

[DLG:IDD_DDFAFRAME]
Type=1
Class=CDDFAFrame
ControlCount=0

[CLS:CDDFAFrame]
Type=0
HeaderFile=DDFAFrame.h
ImplementationFile=DDFAFrame.cpp
BaseClass=CDialog
Filter=D
LastObject=CDDFAFrame
VirtualFilter=dWC

[CLS:CSAccepted]
Type=0
HeaderFile=SAccepted.h
ImplementationFile=SAccepted.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSAccepted

[DLG:IDD_ACCEPTED]
Type=1
Class=CAcDlg
ControlCount=4
Control1=IDC_EXIT,button,1342242816
Control2=IDC_PRE,button,1342242816
Control3=IDC_NEXT,button,1342242816
Control4=IDC_DERIVATION_TREE,button,1342242816

[CLS:CAcDlg]
Type=0
HeaderFile=AcDlg.h
ImplementationFile=AcDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_NEXT

[DLG:IDD_PRODUCTIONS]
Type=1
Class=CPInfo
ControlCount=3
Control1=IDC_PRE,button,1342242816
Control2=IDC_NEXT,button,1342242816
Control3=IDC_POK,button,1342242816

[CLS:CPInfo]
Type=0
HeaderFile=PInfo.h
ImplementationFile=PInfo.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPInfo

[CLS:CToolbar]
Type=0
HeaderFile=Toolbar.h
ImplementationFile=Toolbar.cpp
BaseClass=CButton
Filter=W

[DLG:IDD_DERIVATION]
Type=1
Class=CDerivationDlg
ControlCount=0

[CLS:CDerivationDlg]
Type=0
HeaderFile=DerivationDlg.h
ImplementationFile=DerivationDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDerivationDlg

[DLG:IDD_EDIT]
Type=1
Class=CEditDlg
ControlCount=8
Control1=IDC_VAR,button,1342242816
Control2=IDC_ADD_TO_TERMINALS,button,1342242816
Control3=IDC_SET_AS_START,button,1342242816
Control4=IDC_ADD_TO_PRODUCTIONS,button,1342242816
Control5=IDC_DELETE_PRODUCTION,button,1342242816
Control6=IDC_RESET_LINEARITY,button,1342242816
Control7=IDC_EDIT_OK,button,1342242816
Control8=IDC_EDIT_CANCEL,button,1342242816

[CLS:CEditDlg]
Type=0
HeaderFile=EditDlg.h
ImplementationFile=EditDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_RESET_LINEARITY

[DLG:IDD_DELETE_PRODUCTION]
Type=1
Class=CDeleteProduction
ControlCount=4
Control1=IDC_NEXT,button,1342242816
Control2=IDC_PRE,button,1342242816
Control3=IDC_DELETE,button,1342242816
Control4=IDC_DCANCEL,button,1342242816

[CLS:CDeleteProduction]
Type=0
HeaderFile=DeleteProduction.h
ImplementationFile=DeleteProduction.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_DELETE
VirtualFilter=dWC

