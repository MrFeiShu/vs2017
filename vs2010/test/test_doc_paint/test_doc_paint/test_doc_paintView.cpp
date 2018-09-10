
// test_doc_paintView.cpp : implementation of the Ctest_doc_paintView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "test_doc_paint.h"
#endif

#include "test_doc_paintDoc.h"
#include "test_doc_paintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest_doc_paintView

IMPLEMENT_DYNCREATE(Ctest_doc_paintView, CView)

BEGIN_MESSAGE_MAP(Ctest_doc_paintView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Ctest_doc_paintView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_SETFOCUS()
	ON_WM_KEYUP()
END_MESSAGE_MAP()

// Ctest_doc_paintView construction/destruction

Ctest_doc_paintView::Ctest_doc_paintView()
{
	// TODO: add construction code here
	m_bShiftDown = TRUE;
	m_ptCharacter.x = 0;
	m_ptCharacter.y = 0;
}

Ctest_doc_paintView::~Ctest_doc_paintView()
{
}

BOOL Ctest_doc_paintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Ctest_doc_paintView drawing

void Ctest_doc_paintView::OnDraw(CDC* /*pDC*/)
{
	Ctest_doc_paintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Ctest_doc_paintView printing


void Ctest_doc_paintView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Ctest_doc_paintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Ctest_doc_paintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Ctest_doc_paintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Ctest_doc_paintView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Ctest_doc_paintView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Ctest_doc_paintView diagnostics

#ifdef _DEBUG
void Ctest_doc_paintView::AssertValid() const
{
	CView::AssertValid();
}

void Ctest_doc_paintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest_doc_paintDoc* Ctest_doc_paintView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest_doc_paintDoc)));
	return (Ctest_doc_paintDoc*)m_pDocument;
}
#endif //_DEBUG


// Ctest_doc_paintView message handlers


void Ctest_doc_paintView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if ( m_bShiftDown )
	{
		if ( nChar == 13 )
		{
			m_ptCharacter.x = 0;
			m_ptCharacter.y += 25;
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
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void Ctest_doc_paintView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if ( nChar == VK_SHIFT )
	{
		m_bShiftDown = m_bShiftDown ? FALSE:TRUE;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void Ctest_doc_paintView::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);

	// TODO: Add your message handler code here
	CreateSolidCaret(3, 8);
	SetCaretPos(m_ptCharacter);
	ShowCaret();
}


void Ctest_doc_paintView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
// 	if ( nChar == VK_SHIFT )
// 	{
// 		m_bShiftDown = m_bShiftDown ? FALSE:TRUE;
// 	}
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
