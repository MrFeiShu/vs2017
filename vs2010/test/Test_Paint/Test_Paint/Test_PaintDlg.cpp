
// Test_PaintDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test_Paint.h"
#include "Test_PaintDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTest_PaintDlg dialog


static UINT g_u4PaintCount;

CTest_PaintDlg::CTest_PaintDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTest_PaintDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_bShiftDown = TRUE;
	m_ptCharacter.x = 0;
	m_ptCharacter.y = 0;
}

void CTest_PaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTest_PaintDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTest_PaintDlg::OnBnClickedButton1)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()


// CTest_PaintDlg message handlers

BOOL CTest_PaintDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTest_PaintDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	g_u4PaintCount++;
	SetDlgItemInt(IDC_EDIT_PAINT, g_u4PaintCount);
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTest_PaintDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTest_PaintDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	Invalidate();
}


void CTest_PaintDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if ( nChar == VK_SHIFT )
	{
		m_bShiftDown = m_bShiftDown ? FALSE:TRUE;
	}

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CTest_PaintDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if ( m_bShiftDown )
	{
		if ( nChar = 13 )
		{
			m_ptCharacter.x = 0;
			m_ptCharacter.y = 25;
			SetCaretPos(m_ptCharacter);
			ShowCaret();
		}
		else
		{
			CClientDC dc(this);
			HideCaret();
			dc.TextOut(m_ptCharacter.x, m_ptCharacter.y, (LPCTSTR)&nChar);
			CSize	textSize;
			textSize = dc.GetTextExtent((LPCTSTR)&nChar);
			m_ptCharacter.x += textSize.cx;
			SetCaretPos(m_ptCharacter);
			ShowCaret();
		}
	}
	CDialogEx::OnChar(nChar, nRepCnt, nFlags);
}


void CTest_PaintDlg::OnSetFocus(CWnd* pOldWnd)
{
	CDialogEx::OnSetFocus(pOldWnd);

	// TODO: Add your message handler code here
	CreateSolidCaret(3, 8);
	SetCaretPos(m_ptCharacter);
	ShowCaret();
}
