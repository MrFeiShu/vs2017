; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAcceleratorDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Accelerator.h"

ClassCount=3
Class1=CAcceleratorApp
Class2=CAcceleratorDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ACCELERATOR_DIALOG
Resource4=IDR_ACCELERATOR_HIDE

[CLS:CAcceleratorApp]
Type=0
HeaderFile=Accelerator.h
ImplementationFile=Accelerator.cpp
Filter=N

[CLS:CAcceleratorDlg]
Type=0
HeaderFile=AcceleratorDlg.h
ImplementationFile=AcceleratorDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDR_ACCELERATOR_HIDE

[CLS:CAboutDlg]
Type=0
HeaderFile=AcceleratorDlg.h
ImplementationFile=AcceleratorDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ACCELERATOR_DIALOG]
Type=1
Class=CAcceleratorDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816

[ACL:IDR_ACCELERATOR_HIDE]
Type=1
Class=CAcceleratorDlg
Command1=IDC_BUTTON1
Command2=IDC_BUTTON2
CommandCount=2

