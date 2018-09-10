
// BorderShadowTestDlg.h : 头文件
//

#pragma once


// CBorderShadowTestDlg 对话框
class CBorderShadowTestDlg : public CDialog
{
// 构造
public:
	CBorderShadowTestDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CBorderShadowTestDlg();

// 对话框数据
	enum { IDD = IDD_BORDERSHADOWTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


private:
	CRect m_rtClient;
	Image* m_pImage;
	//gdi+用到的两个变量
	GdiplusStartupInput m_gdiplusStartupInput;
	ULONG_PTR m_pGdiToken;
public:
	afx_msg void OnBnClickedOk();
	void InitUI();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg void OnBtn1Click();
	CRect m_rtBtn;
	BOOL m_bTracking;
	CButton* m_pBtn1;
};
