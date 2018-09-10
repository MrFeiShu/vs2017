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
#pragma warning(disable : 4250)							// vc 多继承容易产生警告，这里无害

#define TITLEBAR_HEIGHT							47		// 标题栏的高度
#define BORDER_WIDTH							1		// 画笔的长度

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
	CString				m_strImgPath;        // 背景图存放路径
	CRect				m_rectClose;           // 关闭按钮位置
	CRect				m_rectHelp;            // 帮助按钮位置

	CXColorStatic		m_LabelHelp;		 // help text
	CXColorStatic		m_LabelTitle;        // title text
	BOOL				m_bDrawClosePic;

protected:
	DWORD	m_dWidgetType;					 // 判断显示哪个控件
	BOOL	m_bLogoType;					 // 用来载入有色logo还是无色logo，TRUE为有色，FALSE为无色
	BOOL	m_bEnableEsc;					 // 是否使用Esc键退出对话框
	BOOL    m_bEnableAltF4;					 // 是否使用Alt+F4退出对话框
	BOOL	m_bVirtualDlgExist;					 // 是否存在Logo，用于创建虚拟桌面背景时判断

#ifdef _ES_UI_
	BOOL	m_bActiveWindow;				 // 是否把当前窗口设为激活窗口
	BOOL	m_bEnableMoved;					 // TRUE:窗口可以被移动 FALSE:窗口不能被移动
#endif
#ifdef _ES_SETUP_
	CString m_strUninstallTempPath;
#endif
protected:
	void SetBackground(const CString &imagePath, BOOL bInvalidate= FALSE);     // 设置背景图片
	void SetTitle(const CString& strTitle);                                    // 设置标题

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
