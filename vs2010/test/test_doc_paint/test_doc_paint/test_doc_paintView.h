
// test_doc_paintView.h : interface of the Ctest_doc_paintView class
//

#pragma once


class Ctest_doc_paintView : public CView
{
protected: // create from serialization only
	Ctest_doc_paintView();
	DECLARE_DYNCREATE(Ctest_doc_paintView)

// Attributes
public:
	Ctest_doc_paintDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Ctest_doc_paintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()

public:
	BOOL	m_bShiftDown;
	CPoint	m_ptCharacter;

	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in test_doc_paintView.cpp
inline Ctest_doc_paintDoc* Ctest_doc_paintView::GetDocument() const
   { return reinterpret_cast<Ctest_doc_paintDoc*>(m_pDocument); }
#endif

