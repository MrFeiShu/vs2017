// Image.h: interface for the CImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGE_H__7979A22B_9BE5_4B1C_B943_2287B7EE17E0__INCLUDED_)
#define AFX_IMAGE_H__7979A22B_9BE5_4B1C_B943_2287B7EE17E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum EnImageOperatinFlag
{
    IMAGE_FLAG_NONE	=	0,
    IMAGE_SCALE_H	=	1 << 0,	// ºáÏòËõ·Å
};

class CImageOperation  
{
public:
	CImageOperation();
	virtual ~CImageOperation();
    bool DrawImage(CDC* pDC, const CRect& rect, const CString& strBitmapName, DWORD dwFlag = 0, BOOL bDefaultPath = TRUE);
	int GetFrame(const CString& strBitmapName);
	bool DrawImageFrame(CDC* pDC, const CRect& rect, const CString& strBitmapName, int nFrame);
	HICON LoadIcon(const CString& strBitmapName);

protected:
    bool DrawBmp(CDC* pDC, const CRect& rect, const CString& strBitmapName, BOOL bDefaultPath, DWORD dwFlag = 0);
    bool DrawPng(CDC* pDC, const CRect& rect, const CString& strBitmapName, BOOL bDefaultPath, DWORD dwFlag = 0);
	bool DrawGif(CDC* pDC, const CRect& rect, const CString& strBitmapName, int nFrame);
	bool GetImagePath();
	
private:
	BOOL AdjustRect(const CRect& rectSrc, const CSize& imgSize, CRect& rectDest, DWORD dwFlag = 0);

private:
	CString __strImageRootPath;

};

#endif // !defined(AFX_IMAGE_H__7979A22B_9BE5_4B1C_B943_2287B7EE17E0__INCLUDED_)
