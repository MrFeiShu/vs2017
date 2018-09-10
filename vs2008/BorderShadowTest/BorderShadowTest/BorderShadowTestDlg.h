
// BorderShadowTestDlg.h : ͷ�ļ�
//

#pragma once


// CBorderShadowTestDlg �Ի���
class CBorderShadowTestDlg : public CDialog
{
// ����
public:
	CBorderShadowTestDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CBorderShadowTestDlg();

// �Ի�������
	enum { IDD = IDD_BORDERSHADOWTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


private:
	CRect m_rtClient;
	Image* m_pImage;
	//gdi+�õ�����������
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
