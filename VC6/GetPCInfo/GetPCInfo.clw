; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGetPCInfoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GetPCInfo.h"

ClassCount=4
Class1=CGetPCInfoApp
Class2=CGetPCInfoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_GETPCINFO_DIALOG

[CLS:CGetPCInfoApp]
Type=0
HeaderFile=GetPCInfo.h
ImplementationFile=GetPCInfo.cpp
Filter=N

[CLS:CGetPCInfoDlg]
Type=0
HeaderFile=GetPCInfoDlg.h
ImplementationFile=GetPCInfoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=GetPCInfoDlg.h
ImplementationFile=GetPCInfoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_GETPCINFO_DIALOG]
Type=1
Class=CGetPCInfoDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1352734788

