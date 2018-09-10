// ChildDialog.cpp : implementation file
//

#include "stdafx.h"
#include "DialogDemo1.h"
#include "ChildDialog.h"


// CChildDialog dialog

IMPLEMENT_DYNAMIC(CChildDialog, CDialog)

CChildDialog::CChildDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CChildDialog::IDD, pParent)
{

}

CChildDialog::~CChildDialog()
{
}

void CChildDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChildDialog, CDialog)
END_MESSAGE_MAP()


// CChildDialog message handlers
