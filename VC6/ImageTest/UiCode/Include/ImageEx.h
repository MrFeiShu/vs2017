#ifndef _IMAGE_EX_H_
#define _IMAGE_EX_H_

// ImageEx.h: interface for the CImageEx class.
//
//////////////////////////////////////////////////////////////////////
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

class CxImageEx
{
public:
	CxImageEx();
	virtual ~CxImageEx();
	
	// 绘图: 如果是gif，默认显示最后一帧
    BOOL DrawImage(CDC* pDC, const CRect& rect, const CString& strPicFileName, BOOL bDefaultPath=TRUE, DWORD enImageMode=ImageModeZoomOutAspectFit);
	
protected:
    BOOL _DrawImage(CDC* pDC, const CRect& rect, CxImage& image, DWORD enImageMode=ImageModeZoomOutAspectFit);
	BOOL GetImagePath();
	
private:

	
	
private:
	CString		m_strImageRootPath;
};

#endif