// Image.cpp: implementation of the CImage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <Image.h>
#include <ximage.h>
#include <Product.h>
#include <EsTypeDef.h>
#include <EsCommon/EsCommon.h>
//#include "UIAtlImage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CImageOperation::CImageOperation()
{
	GetImagePath();
}

CImageOperation::~CImageOperation()
{

}

BOOL CImageOperation::AdjustRect(const CRect& rectSrc, const CSize& imgSize, CRect& rectDest, DWORD dwFlag)
{
	double fRatioImage = 0.00;
	double fRatioWindow = 0.00;
	
	if ( 0 == rectSrc.Height() || 0 == rectSrc.Width() 
		|| 0 == imgSize.cx || 0 == imgSize.cy )
	{
		return FALSE;
	}
	
	fRatioImage = imgSize.cx * 1.0 / imgSize.cy;
	fRatioWindow = rectSrc.Width() * 1.0 / rectSrc.Height();
	
	// 矩形框尺寸不足以以1:1的比例容纳整幅图片
	if ( (int)imgSize.cx > rectSrc.Width()  || (int)imgSize.cy > rectSrc.Height() ) 
	{
		rectDest.top = rectSrc.top;
		if ( fRatioImage > fRatioWindow )
		{
			rectDest.left = rectSrc.left;
			rectDest.right = rectSrc.Width()+rectDest.left;
			rectDest.bottom = (LONG)(rectSrc.Width()*1.0/fRatioImage)+rectDest.top;
		}
		else
		{
			LONG lWidth = (LONG)(rectSrc.Height()*fRatioImage);
			rectDest.left = rectSrc.left + (LONG)((rectSrc.Width()-lWidth)/2.0);
			rectDest.right = rectDest.left + lWidth;
			rectDest.bottom = rectSrc.Height()+rectDest.top;
		}
	}
	else // 矩形框尺寸足以以1:1的比例容纳整幅图片，但我们不放大之
	{
		double	fScale = 1;
		if ( dwFlag & IMAGE_SCALE_H )
		{
			fScale = rectSrc.Width() /(double)imgSize.cx;
		}
		rectDest.left = ( (rectSrc.Width() - (LONG)(imgSize.cx * fScale)) / 2) + rectSrc.left;
		rectDest.top = rectSrc.top;
		rectDest.right = rectDest.left + (LONG)(imgSize.cx * fScale + 0.5);
		rectDest.bottom = rectDest.top + (LONG)(imgSize.cy * fScale + 0.5);
	}
	
	return TRUE;	
}

bool CImageOperation::DrawImage(CDC* pDC, const CRect& rect, const CString& strBitmapName, DWORD dwFlag, BOOL bDefaultPath)
{
	CString strExt = strBitmapName.Right(3);
	strExt.MakeUpper();
	if ( strExt == CString(TEXT("PNG")) )
	{
		return DrawPng(pDC, rect, strBitmapName, bDefaultPath, dwFlag);
	}
	else
	{
		return DrawBmp(pDC, rect, strBitmapName, bDefaultPath, dwFlag);
	}
}

bool CImageOperation::DrawImageFrame(CDC* pDC, const CRect& rect, const CString& strBitmapName, int nFrame)
{
	CString strExt = strBitmapName.Right(3);
	strExt.MakeUpper();
	if ( strExt != CString(TEXT("GIF")) )
	{
		return false;
	}
	return DrawGif(pDC, rect, strBitmapName, nFrame);
}

int CImageOperation::GetFrame(const CString& strBitmapName)
{
	bool bRet = false;
	CString strBitmapRealPathName = __strImageRootPath + TEXT("\\");
	strBitmapRealPathName += strBitmapName;

	CxImage img;
	bRet = img.Load(strBitmapRealPathName.GetBuffer(0), CXIMAGE_FORMAT_GIF);

	if ( false == bRet )
	{
		return 0;
	}	
	int nFrameCount = img.GetNumFrames();
	return nFrameCount;
}

bool CImageOperation::DrawBmp(CDC* pDC, const CRect& rect, const CString& strBitmapName, BOOL bDefaultPath, DWORD dwFlag)
{
	bool	bRet = false;
	CRect	rectDraw;
	CSize	imgSize;
	CString strBitmapRealPathName;

	if ( bDefaultPath )
	{
		strBitmapRealPathName = __strImageRootPath + TEXT("\\");
		strBitmapRealPathName += strBitmapName;
	} 
	else
	{
		strBitmapRealPathName += strBitmapName;
	}

	// 载入
	HANDLE hImage = ::LoadImage(NULL, strBitmapRealPathName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if ( NULL == hImage )
	{
		return false;
	}

	do 
	{
		CBitmap objBmp;
		if ( FALSE == objBmp.Attach(hImage))
		{
			break;
		}
		BITMAP blkBmp = {0};
		objBmp.GetBitmap(&blkBmp);
		CDC objDCMem;
		objDCMem.CreateCompatibleDC(pDC);
		objDCMem.SelectObject(objBmp);
		pDC->SetStretchBltMode(HALFTONE);
		// 保持宽高比例
		// 比较宽高比
		double fRatioImage = blkBmp.bmWidth*1.0/blkBmp.bmHeight;
		double fRatioWindow = rect.Width()*1.0/rect.Height();
		BOOL bOk = FALSE;
	
		// 只缩小（若矩形框不能容纳整张图片的话），但不放大（否则图片看起来很模糊）
		// 横向居中，纵向靠顶
		CRect rectDraw;
		// 矩形框尺寸不足以以1:1的比例容纳整幅图片
		if ( blkBmp.bmWidth > rect.Width()  || blkBmp.bmHeight > rect.Height() ) 
		{
			rectDraw.top = rect.top;
			if ( fRatioImage > fRatioWindow )
			{
				rectDraw.left = rect.left;
				rectDraw.right = rect.Width()+rectDraw.left;
				rectDraw.bottom = (LONG)(rect.Width()*1.0/fRatioImage)+rectDraw.top;
			}
			else
			{
				rectDraw.left = (LONG)((rect.Width()-rect.Height()*fRatioImage)/2.0);
				rectDraw.right = (LONG)(rect.Height()*fRatioImage)+rectDraw.left;
				rectDraw.bottom = rect.Height()+rectDraw.top;
			}
		}
		else // 矩形框尺寸足以以1:1的比例容纳整幅图片，但我们不放大之
		{
			double	fScale = 1;
			if ( dwFlag & IMAGE_SCALE_H )
			{
				fScale = rect.Width() /(double)blkBmp.bmWidth;
            }
            rectDraw.left = ( (rect.Width() - (LONG)(blkBmp.bmWidth * fScale)) / 2) + rect.left;
            rectDraw.top = rect.top;
            rectDraw.right = rectDraw.left + (LONG)(blkBmp.bmWidth * fScale);
            rectDraw.bottom = rectDraw.top + (LONG)(blkBmp.bmHeight * fScale);
		}

		bOk = pDC->StretchBlt(rectDraw.left, rectDraw.top, rectDraw.Width(), rectDraw.Height(),
			 				&objDCMem, 
			 				0, 0, blkBmp.bmWidth, blkBmp.bmHeight,
			 				SRCCOPY);
		
		objBmp.Detach();
		objDCMem.DeleteDC();
		bRet = true;
	} while ( false );

	DeleteObject(hImage);
	hImage = NULL;

	return bRet;
}

bool CImageOperation::DrawPng(CDC* pDC, const CRect& rect, const CString& strBitmapName, BOOL bDefaultPath, DWORD dwFlag)
{
	bool bRet = false;
	CxImage img;
	CRect	rectDraw;
	CSize	imgSize;
	CString strBitmapRealPathName;
	
	if ( bDefaultPath )
	{
		strBitmapRealPathName = __strImageRootPath + TEXT("\\");
		strBitmapRealPathName += strBitmapName;
	} 
	else
	{
		strBitmapRealPathName += strBitmapName;
	}
	bRet = img.Load(strBitmapRealPathName.GetBuffer(0), CXIMAGE_FORMAT_PNG);

	if ( false == bRet )
	{
		ES_LOG((LOG_TYPE_ERROR, FILE_AND_LINE, \
			"CImageOperation::DrawPng()->Failed to call CxImage::Load, image name: %s, last error: %d!", strBitmapRealPathName.GetBuffer(0), GetLastError()));
		return false;
	}

	double fRatioImage = img.GetWidth()*1.0/img.GetHeight();
	double fRatioWindow = rect.Width()*1.0/rect.Height();
	BOOL bOk = FALSE;
	
	// 只缩小（若矩形框不能容纳整张图片的话），但不放大（否则图片看起来很模糊）
	// 横向居中，纵向靠顶
	
	// 矩形框尺寸不足以以1:1的比例容纳整幅图片
	if ( (int)img.GetWidth() > rect.Width()  || (int)img.GetHeight() > rect.Height() ) 
	{
		rectDraw.top = rect.top;
		if ( fRatioImage > fRatioWindow )
		{
			rectDraw.left = rect.left;
			rectDraw.right = rect.Width()+rectDraw.left;
			rectDraw.bottom = (LONG)(rect.Width()*1.0/fRatioImage)+rectDraw.top;
		}
		else
		{
			LONG lWidth = (LONG)(rect.Height()*fRatioImage);
			rectDraw.left = rect.left + (LONG)((rect.Width()-lWidth)/2.0);
			rectDraw.right = rectDraw.left + lWidth;
			rectDraw.bottom = rect.Height()+rectDraw.top;
		}
	}
	else // 矩形框尺寸足以以1:1的比例容纳整幅图片，但我们不放大之
	{
		double	fScale = 1;
		if ( dwFlag & IMAGE_SCALE_H )
		{
			fScale = rect.Width() /(double)img.GetWidth();
		}
		rectDraw.left = ( (rect.Width() - (LONG)(img.GetWidth() * fScale)) / 2) + rect.left;
		rectDraw.top = rect.top;
		rectDraw.right = rectDraw.left + (LONG)(img.GetWidth() * fScale + 0.5);
		rectDraw.bottom = rectDraw.top + (LONG)(img.GetHeight() * fScale + 0.5);
    }
    

	img.Draw(pDC->GetSafeHdc(), rectDraw, NULL, true);

	
	return true;
}

bool CImageOperation::DrawGif(CDC* pDC, const CRect& rect, const CString& strBitmapName, int nFrame)
{
	bool bRet = false;
	CString strBitmapRealPathName = __strImageRootPath + TEXT("\\");
	strBitmapRealPathName += strBitmapName;
	
	CxImage img;
	//img.SetFrame(nFrame);
	
	bRet = img.Load(strBitmapRealPathName.GetBuffer(0), CXIMAGE_FORMAT_GIF);
	img.SetRetreiveAllFrames(true);
	img.SetFrame(img.GetNumFrames()-1);
	bRet = img.Load(strBitmapRealPathName.GetBuffer(0), CXIMAGE_FORMAT_GIF);
	CxImage* pImg = img.GetFrame(nFrame);
	

	double fRatioImage = img.GetWidth()*1.0/img.GetHeight();
	double fRatioWindow = rect.Width()*1.0/rect.Height();
	BOOL bOk = FALSE;
	
	// 只缩小（若矩形框不能容纳整张图片的话），但不放大（否则图片看起来很模糊）
	// 横向居中，纵向靠顶
	CRect rectDraw;
	
	// 矩形框尺寸不足以以1:1的比例容纳整幅图片
	if ( (int)img.GetWidth() > rect.Width()  || (int)img.GetHeight() > rect.Height() ) 
	{
		rectDraw.top = rect.top;
		if ( fRatioImage > fRatioWindow )
		{
			rectDraw.left = rect.left;
			rectDraw.right = rect.Width()+rectDraw.left;
			rectDraw.bottom = (LONG)(rect.Width()*1.0/fRatioImage)+rectDraw.top;
		}
		else
		{
			rectDraw.left = (LONG)((rect.Width()-rect.Height()*fRatioImage)/2.0);
			rectDraw.right = (LONG)(rect.Height()*fRatioImage)+rectDraw.left;
			rectDraw.bottom = rect.Height()+rectDraw.top;
		}
	}
	else // 矩形框尺寸足以以1:1的比例容纳整幅图片，但我们不放大之
	{
		rectDraw.left = (LONG)((rect.Width()-img.GetWidth())/2.0)+rect.left;
		rectDraw.top = rect.top;
		rectDraw.right = rectDraw.left+ img.GetWidth();
		rectDraw.bottom = img.GetHeight()+rectDraw.top;
	}

	CDC objMemDc;
	objMemDc.CreateCompatibleDC(pDC);
	objMemDc.SetBkColor(RGB(255, 255, 255));
	objMemDc.SetBkMode(TRANSPARENT);
	CBitmap	btScreen;

	btScreen.CreateCompatibleBitmap (pDC, rectDraw.Width(), rectDraw.Height());
	objMemDc.SelectObject (&btScreen);

	CRect rectDrawMem(0, 0, rectDraw.Width(), rectDraw.Height());
	
	if ( NULL != pImg )
	{
		//pImg->Draw(objMemDc.GetSafeHdc(), rectDrawMem, NULL, true);
		//pDC->BitBlt(rectDraw.left, rectDraw.top, rectDraw.Width(), rectDraw.Height(), &objMemDc, 0, 0, SRCCOPY);
		//pDC->I
		pImg->Draw(pDC->GetSafeHdc(), rectDraw, NULL, true);
	}

	// 回收资源
	objMemDc.DeleteDC();
	btScreen.DeleteObject();
	
	if ( false == bRet )
	{
		return false;
	}	
	return true;
}

HICON CImageOperation::LoadIcon(const CString& strBitmapName)
{
	CString strBitmapRealPathName = __strImageRootPath + TEXT("\\");
	strBitmapRealPathName += strBitmapName;

	return (HICON)LoadImage(NULL, strBitmapRealPathName, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
}

// 还没有确定路径怎么定，先硬编码
bool CImageOperation::GetImagePath()
{
	TCHAR szImagePath[MAX_PATH] = {0};
	GetModuleFileName(GetModuleHandle(NULL), szImagePath, MAX_PATH);
	TCHAR* lpszPos = _tcsrchr(szImagePath, L'\\');
	*(lpszPos+1) = TEXT('\0');
	_tcscat(szImagePath, TEXT("Res"));
	__strImageRootPath = szImagePath;
	return true;
}
