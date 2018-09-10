// Image.h: interface for the CImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CXIMAGEOPERATION_H__7979A22B_9BE5_4B1C_B943_2287B7EE17E0__INCLUDED_)
#define AFX_CXIMAGEOPERATION_H__7979A22B_9BE5_4B1C_B943_2287B7EE17E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <ximage.h>

// Scale:拉伸图片
// Aspect: 图片长宽的比例，保持图形的长宽比，保持图片不变形。
// 缩放: 放大/缩小
typedef enum EnImageModeTag
{
	ImageModeZoomOutAspectFit = 0,	// 缩小适应(居中对齐): 在保证比例前提下，居中缩小(不放大!)图片，完整显示图片
	ImageModeScaleAspectFit,		// 缩放适应(居中对齐): 在保证比例前提下，居中缩放图片，完整显示图片
	ImageModeScaleAspectFill,		// 填充(居中对齐): 在保证比例前提下，居中缩放图片，使图片充满容器(有可能部分图片会被裁切)
	ImageModeScaleToFill,			// 拉伸: 拉伸铺满，有可能放大/缩小，不保证比例
}EnImageMode;

const UINT MSG_PLAY_GIF_START = ::RegisterWindowMessage(_T("CxImageOperation_MSG_PLAY_GIF_START"));
const UINT MSG_PLAY_GIF_END = ::RegisterWindowMessage(_T("CxImageOperation_MSG_PLAY_GIF_END"));

class CxImageOperation  
{
public:
	CxImageOperation();
	virtual ~CxImageOperation();

	// 绘图: 如果是gif，默认显示最后一帧
    BOOL DrawImage(CDC* pDC, const CRect& rect, const CString& strPicFileName, DWORD enImageMode=ImageModeZoomOutAspectFit);

	// 加载Gif：不做绘制
	BOOL LoadGif(const CString& strPicFileName);

	// 播放Gif: 如果只有单帧，则直接显示
	// hReceiver: 如果要接收播放结束的消息，请设置此参数
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
