#if !defined(AFX_DIALOGEX_H__1EC4EC31_8A45_4CD2_9820_47473704170E__INCLUDED_)
#define AFX_DIALOGEX_H__1EC4EC31_8A45_4CD2_9820_47473704170E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogEx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogEx dialog
#include "resource.h"
#include <Image.h>
#include <XColorStatic.h>

typedef enum EnWidgetTypeTag
{
	WIDGET_TYPE_CLOSE	= 0x0001,
	WIDGET_TYPE_HELP	= 0x0002,
	WIDGET_TYPE_TITLE	= 0x0004,
	WIDGET_TYPE_NONE	= 0x0008,
	WIDGET_TYPE_ALL		= 0xFFFF,
}EnWidgetType;

#pragma warning(push)
#pragma warning(disable : 4250)							// vc ��̳����ײ������棬�����޺�

#define TITLEBAR_HEIGHT							47		// �������ĸ߶�
#define BORDER_WIDTH							1		// ���ʵĳ���

class CDialogEx : public CDialog
{
// Construction
public:
	CDialogEx(UINT nIDTemplate, CWnd* pParent = NULL);  // standard constructor
	virtual ~CDialogEx();

// Dialog Data
	//{{AFX_DATA(CDialogEx)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogEx)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogEx)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaintClipboard(CWnd* pClipAppWnd, HGLOBAL hPaintStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString				m_strImgPath;        // ����ͼ���·��
	CRect				m_rectClose;           // �رհ�ťλ��
	CRect				m_rectHelp;            // ������ťλ��

	CXColorStatic		m_LabelHelp;		 // help text
	CXColorStatic		m_LabelTitle;        // title text
	BOOL				m_bDrawClosePic;

protected:
	DWORD	m_dWidgetType;					 // �ж���ʾ�ĸ��ؼ�
	BOOL	m_bLogoType;					 // ����������ɫlogo������ɫlogo��TRUEΪ��ɫ��FALSEΪ��ɫ
	BOOL	m_bEnableEsc;					 // �Ƿ�ʹ��Esc���˳��Ի���
	BOOL    m_bEnableAltF4;					 // �Ƿ�ʹ��Alt+F4�˳��Ի���
	BOOL	m_bVirtualDlgExist;					 // �Ƿ����Logo�����ڴ����������汳��ʱ�ж�

#ifdef _ES_UI_
	BOOL	m_bActiveWindow;				 // �Ƿ�ѵ�ǰ������Ϊ�����
	BOOL	m_bEnableMoved;					 // TRUE:���ڿ��Ա��ƶ� FALSE:���ڲ��ܱ��ƶ�
#endif
#ifdef _ES_SETUP_
	CString m_strUninstallTempPath;
#endif
protected:
	void SetBackground(const CString &imagePath, BOOL bInvalidate= FALSE);     // ���ñ���ͼƬ
	void SetTitle(const CString& strTitle);                                    // ���ñ���

public:
	void DrawTitleBar(CDC* pDC, BOOL bCalcRect=FALSE);
	void DrawPicture(CDC* pDC, CRect &rect, CString &imgPath);
	void ShowDialog(int nCmdShow);
	virtual void OpenHelpLink();
	virtual void SetFocusInput();
	void CenterDialog();
};

#pragma warning(pop)

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGEX_H__1EC4EC31_8A45_4CD2_9820_47473704170E__INCLUDED_)
