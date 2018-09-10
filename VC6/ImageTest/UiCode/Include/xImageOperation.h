// Image.h: interface for the CImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CXIMAGEOPERATION_H__7979A22B_9BE5_4B1C_B943_2287B7EE17E0__INCLUDED_)
#define AFX_CXIMAGEOPERATION_H__7979A22B_9BE5_4B1C_B943_2287B7EE17E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <ximage.h>

// Scale:����ͼƬ
// Aspect: ͼƬ����ı���������ͼ�εĳ���ȣ�����ͼƬ�����Ρ�
// ����: �Ŵ�/��С
typedef enum EnImageModeTag
{
	ImageModeZoomOutAspectFit = 0,	// ��С��Ӧ(���ж���): �ڱ�֤����ǰ���£�������С(���Ŵ�!)ͼƬ��������ʾͼƬ
	ImageModeScaleAspectFit,		// ������Ӧ(���ж���): �ڱ�֤����ǰ���£���������ͼƬ��������ʾͼƬ
	ImageModeScaleAspectFill,		// ���(���ж���): �ڱ�֤����ǰ���£���������ͼƬ��ʹͼƬ��������(�п��ܲ���ͼƬ�ᱻ����)
	ImageModeScaleToFill,			// ����: �����������п��ܷŴ�/��С������֤����
}EnImageMode;

const UINT MSG_PLAY_GIF_START = ::RegisterWindowMessage(_T("CxImageOperation_MSG_PLAY_GIF_START"));
const UINT MSG_PLAY_GIF_END = ::RegisterWindowMessage(_T("CxImageOperation_MSG_PLAY_GIF_END"));

class CxImageOperation  
{
public:
	CxImageOperation();
	virtual ~CxImageOperation();

	// ��ͼ: �����gif��Ĭ����ʾ���һ֡
    BOOL DrawImage(CDC* pDC, const CRect& rect, const CString& strPicFileName, DWORD enImageMode=ImageModeZoomOutAspectFit);

	// ����Gif����������
	BOOL LoadGif(const CString& strPicFileName);

	// ����Gif: ���ֻ�е�֡����ֱ����ʾ
	// hReceiver: ���Ҫ���ղ��Ž�������Ϣ�������ô˲���
	BOOL PlayGif(CDC* pDC, const CRect& rect, DWORD enImageMode=ImageModeZoomOutAspectFit, HWND hReceiver=NULL);
	
protected:
    BOOL _DrawImage(CDC* pDC, const CRect& rect, CxImage& image, DWORD enImageMode=ImageModeZoomOutAspectFit);
	BOOL GetImagePath();
	
private:
	BOOL AdjustRect(const CRect& rectSrc, const CSize& imgSize, CRect& rectDest, DWORD dwFlag = 0);
	static void CALLBACK TimerProcPlayGif(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
	void _TimerProcPlayGif(UINT uTimerID);

	void SetPlayGifEnd();	

private:
	CString		m_strImageRootPath;
	CxImage*	m_pImageGif;	// for gif
	BOOL		m_bIsPlayingGif;// for gif
	CDC*		m_pDC;			// for gif DC
	DWORD		m_dwImageMode;	// for gif
	CRect		m_rectGif;		// for gif
	UINT		m_nTimerId;		// for gif
	HWND		m_hReceiver;	// for gif play
};

#endif // !defined(AFX_CXIMAGEOPERATION_H__7979A22B_9BE5_4B1C_B943_2287B7EE17E0__INCLUDED_)
