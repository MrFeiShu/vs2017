; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTestWSDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "testWS.h"

ClassCount=4
Class1=CTestWSApp
Class2=CTestWSDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TESTWS_DIALOG

[CLS:CTestWSApp]
Type=0
HeaderFile=testWS.h
ImplementationFile=testWS.cpp
Filter=N

[CLS:CTestWSDlg]
Type=0
HeaderFile=testWSDlg.h
ImplementationFile=testWSDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=testWSDlg.h
ImplementationFile=testWSDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TESTWS_DIALOG]
Type=1
Class=CTestWSDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

