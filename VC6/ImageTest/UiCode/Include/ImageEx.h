#ifndef _IMAGE_EX_H_
#define _IMAGE_EX_H_

// ImageEx.h: interface for the CImageEx class.
//
//////////////////////////////////////////////////////////////////////
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

class CxImageEx
{
public:
	CxImageEx();
	virtual ~CxImageEx();
	
	// ��ͼ: �����gif��Ĭ����ʾ���һ֡
    BOOL DrawImage(CDC* pDC, const CRect& rect, const CString& strPicFileName, BOOL bDefaultPath=TRUE, DWORD enImageMode=ImageModeZoomOutAspectFit);
	
protected:
    BOOL _DrawImage(CDC* pDC, const CRect& rect, CxImage& image, DWORD enImageMode=ImageModeZoomOutAspectFit);
	BOOL GetImagePath();
	
private:

	
	
private:
	CString		m_strImageRootPath;
};

#endif