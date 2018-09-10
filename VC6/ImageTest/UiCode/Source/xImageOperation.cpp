// Image.cpp: implementation of the CImage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <xImageOperation.h>
#include <EsTypeDef.h>
#include <EsCommon/EsLog.h>
#include <MMSystem.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#pragma comment(lib, "Winmm.lib")

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

static CString FindExtension(const CString& strFileName)
{
	int len = strFileName.GetLength();
	int i;
	for (i = len-1; i >= 0; i--)
	{
		if (strFileName[i] == '.')
		{
			return strFileName.Mid(i+1);
		}
	}
	return CString(_T(""));
}

static int GetImageType(const CString& strFileName)
{
	CString strExt(FindExtension(strFileName));

	strExt.MakeLower();
	if ( 0 == strExt.GetLength() )
	{
		return CXIMAGE_FORMAT_UNKNOWN;
	}

	return CxImage::GetTypeIdFromName(strExt);
}

//////////////////////////////////////////////////////////////////////////////
CxImageOperation::CxImageOperation()
{
	m_nTimerId = 0;
	m_pImageGif = NULL;
	SetPlayGifEnd();
	GetImagePath();
}

CxImageOperation::~CxImageOperation()
{
	SetPlayGifEnd();
}

void CxImageOperation::SetPlayGifEnd()
{
	timeKillEvent(m_nTimerId);
	
	if ( m_pImageGif != NULL )
	{
		delete m_pImageGif;
		m_pImageGif = NULL;
	}
	m_nTimerId = 0;
	m_hReceiver = NULL;
	m_pDC = NULL;
	m_dwImageMode = ImageModeZoomOutAspectFit;
	m_rectGif = CRect(0,0,0,0);
	m_bIsPlayingGif = FALSE;
}

BOOL CxImageOperation::DrawImage(CDC* pDC, const CRect& rect, const CString& strPicFileName, DWORD enImageMode)
{
	BOOL	bRet = FALSE;
	CxImage image;
	CRect	rectDraw;
	CSize	imgSize;
	CString strPicFilePath = m_strImageRootPath + TEXT("\\");
	int		nImageType = GetImageType(strPicFileName);
	int		nFrameNum = 0;

	strPicFilePath += strPicFileName;
	
	if ( m_bIsPlayingGif )
	{
		ES_LOG((LOG_TYPE_WARNING, FILE_AND_LINE, "CxImageOperation::DrawImage error, there is playing gif!!"));
		return FALSE;
	}

	if ( !image.Load(strPicFilePath, nImageType) || !image.IsValid() )
	{
		ES_LOG((LOG_TYPE_ERROR, FILE_AND_LINE, "CxImageOperation::DrawImage load image error!!"));
		return FALSE;
	}
	
	if ( CXIMAGE_FORMAT_GIF == nImageType )
	{
		nFrameNum = image.GetNumFrames();
		if ( nFrameNum <= 0 )
		{
			ES_LOG((LOG_TYPE_ERROR, FILE_AND_LINE, "CxImageOperation::DrawImage load image error, no any frame in the image!!"));
			return FALSE;
		}

		long n = nFrameNum-1;

		// ȡgif���һ֡
		image.SetRetreiveAllFrames(true);
		image.SetFrame(n);
		image.Load(strPicFilePath, nImageType);
		image.Copy(*(image.GetFrame(n)));
	}

	return _DrawImage(pDC, rect, image, enImageMode);
}

BOOL CxImageOperation::LoadGif(const CString& strPicFileName)
{
	CString strPicFilePath = m_strImageRootPath + TEXT("\\");
	int		nImageType = GetImageType(strPicFileName);
	int		nFrameNum = 0;
	
	strPicFilePath += strPicFileName;
	
	if ( m_bIsPlayingGif )
	{
		ES_LOG((LOG_TYPE_WARNING, FILE_AND_LINE, "CxImageOperation::PlayGif error, there is playing gif!!"));
		return FALSE;
	}
	
	SetPlayGifEnd();
	
	m_pImageGif = new CxImage(strPicFilePath, nImageType);
	
	if ( nImageType != CXIMAGE_FORMAT_GIF )
	{
		ES_LOG((LOG_TYPE_ERROR, FILE_AND_LINE, "CxImageOperation::PlayGif error, the image is not gif!!"));
		return FALSE;
	}
	
	if ( !m_pImageGif->IsValid() )
	{
		ES_LOG((LOG_TYPE_ERROR, FILE_AND_LINE, "CxImageOperation::PlayGif load image error!!"));
		return FALSE;
	}
	
	nFrameNum = m_pImageGif->GetNumFrames();
	if ( nFrameNum <= 0 )
	{
		ES_LOG((LOG_TYPE_ERROR, FILE_AND_LINE, "CxImageOperation::PlayGif error, no any frame in the image!!"));
		return FALSE;
	}

	// ��֡
	m_pImageGif->SetRetreiveAllFrames(true); // ȡ����֡
	m_pImageGif->SetFrame(nFrameNum-1);
	m_pImageGif->Load(strPicFilePath, nImageType); // reload
	m_pImageGif->SetFrame(0);

	return TRUE;
}

BOOL CxImageOperation::PlayGif(CDC* pDC, const CRect& rect, DWORD enImageMode/*=ImageModeZoomOutAspectFit*/, HWND hReceiver/*=NULL*/)
{
	int		nFrameNum = 0;
	
	if ( m_bIsPlayingGif )
	{
		ES_LOG((LOG_TYPE_WARNING, FILE_AND_LINE, "CxImageOperation::PlayGif error, there is playing gif!!"));
		return FALSE;
	}
	
	if ( NULL == m_pImageGif )
	{
		ES_LOG((LOG_TYPE_ERROR, FILE_AND_LINE, "CxImageOperation::PlayGif error, the image is not loaded yet!!"));
		return FALSE;
	}
	
	if ( NULL == m_pImageGif || !m_pImageGif->IsValid() )
	{
		ES_LOG((LOG_TYPE_ERROR, FILE_AND_LINE, "CxImageOperation::PlayGif: image is invalid, please load it first!!"));
		return FALSE;
	}
	
	nFrameNum = m_pImageGif->GetNumFrames();
	if ( nFrameNum <= 0 )
	{
		ES_LOG((LOG_TYPE_ERROR, FILE_AND_LINE, "CxImageOperation::PlayGif error, no any frame in the image!!"));
		return FALSE;
	}
	else if ( 1 == nFrameNum )
	{
		PostMessage(hReceiver, MSG_PLAY_GIF_START, 0, 0);
		BOOL bRet = _DrawImage(pDC, rect, *m_pImageGif, enImageMode);
		PostMessage(hReceiver, MSG_PLAY_GIF_END, 0, 0);
		SetPlayGifEnd();

		return bRet;
	}
	
	// ׼������
	m_hReceiver = hReceiver;
	m_pDC = pDC;
	m_dwImageMode = enImageMode;
	m_rectGif = rect;
	m_bIsPlayingGif = TRUE;
	PostMessage(hReceiver, MSG_PLAY_GIF_START, 0, 0);
	m_nTimerId = timeSetEvent(20, 1, TimerProcPlayGif, (DWORD_PTR)this, TIME_ONESHOT|TIME_CALLBACK_FUNCTION);

	return TRUE;
}

void CALLBACK CxImageOperation::TimerProcPlayGif(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
	CxImageOperation* pThis = (CxImageOperation*)dwUser;
	
	if ( NULL == pThis )
	{
		ES_LOG((LOG_TYPE_INFORMATION, FILE_AND_LINE, "CxImageOperation::TimerProcPlayGif play gif error!!! dwUser is NULL"));
		timeKillEvent(uTimerID);
		return;
	}
	
	pThis->_TimerProcPlayGif(uTimerID);
}

void CxImageOperation::_TimerProcPlayGif(UINT uTimerID)
{
	// ��ʱ�����Ƕ��Timer

	// �ȹر�
	timeKillEvent(uTimerID);
	
	if ( NULL == m_pImageGif )
	{
		ES_LOG((LOG_TYPE_INFORMATION, FILE_AND_LINE, "CxImageOperation::TimerProcPlayGif play gif error!!! image data is NULL"));
		SetPlayGifEnd();
		return;
	}

	// ���Ŵ�֡
	long		m = m_pImageGif->GetNumFrames();
	long		lCurFrame = m_pImageGif->GetFrame();
	DWORD		dwDelay = 10 * max(1, m_pImageGif->GetFrameDelay()); // GetFrameDelay()ȡֵӦ����10��100
	CxImage*	pImage = m_pImageGif->GetFrame(lCurFrame);
	
	m_pImageGif->SetFrame((lCurFrame+1));

	if ( lCurFrame >= m || NULL == pImage )
	{
		ES_LOG((LOG_TYPE_INFORMATION, FILE_AND_LINE, "CxImageOperation::TimerProcPlayGif play gif end"));
		PostMessage(m_hReceiver, MSG_PLAY_GIF_END, 0, 0);
		SetPlayGifEnd();
		return;
	}
	
	if ( !_DrawImage(m_pDC, m_rectGif, *pImage, m_dwImageMode) )
	{
		ES_LOG((LOG_TYPE_ERROR, FILE_AND_LINE, "CxImageOperation::TimerProcPlayGif play gif (%d frame) error!! ", lCurFrame));
	}
	
	timeSetEvent(dwDelay, 1, TimerProcPlayGif, (DWORD_PTR)this, TIME_ONESHOT|TIME_CALLBACK_FUNCTION);
}

BOOL CxImageOperation::_DrawImage(CDC* pDC, const CRect& rect, CxImage& image, DWORD enImageMode/*=ImageModeZoomOutAspectFit*/)
{
	BOOL		bRet = FALSE;
	CxImage		imageNew;
	CSize		imgSize(image.GetWidth(), image.GetHeight());
	double		fRatioImage = 0.00;
	double		fRatioWindow = 0.00;
	CRect		rectDest;
	
	if ( 0 == rect.Height() || 0 == rect.Width() 
		|| 0 == imgSize.cx || 0 == imgSize.cy )
	{
		return FALSE;
	}
	
	fRatioImage = imgSize.cx * 1.0 / imgSize.cy;
	fRatioWindow = rect.Width() * 1.0 / rect.Height();
	
	switch (enImageMode)
	{
	case ImageModeZoomOutAspectFit:  // ��С��Ӧ-���ж���
		{
			if ( (int)imgSize.cx > rect.Width()  || (int)imgSize.cy > rect.Height() ) 
			{
				// ���ο�ߴ粻������1:1�ı�����������ͼƬ
				if ( fRatioImage > fRatioWindow )
				{
					// ͼ���߱ȴ��ڻ�����߱�
					LONG lHeight = (LONG)(rect.Width()/fRatioImage);
					
					rectDest.left = rect.left;
					rectDest.right = rect.right;
					rectDest.top = rect.top + (LONG)((rect.Height()-lHeight)/2.0);
					rectDest.bottom = rectDest.top + lHeight;
				}
				else
				{
					LONG lWidth = (LONG)(rect.Height()*fRatioImage);
					
					rectDest.top = rect.top;
					rectDest.bottom = rect.bottom;
					
					rectDest.left = rect.left + (LONG)((rect.Width()-lWidth)/2.0);
					rectDest.right = rectDest.left + lWidth;
				}
			}
			else
			{
				rectDest.left = ( (rect.Width() - imgSize.cx) / 2) + rect.left;
				rectDest.top = ( (rect.Height() - imgSize.cy) / 2) + rect.top;
				rectDest.right = rectDest.left + imgSize.cx;
				rectDest.bottom = rectDest.top + imgSize.cy;
			}
			
			// ����ͼƬ��С�ٻ��ƣ�CxImage��ͼ�������ͼƬ��С��һ��ʱ���ܻ�������
			image.Resample(rectDest.Width(), rectDest.Height(), 1, &imageNew);
		}
		break;
	case ImageModeScaleAspectFit: // ������Ӧ-���ж���
		{
			if ( fRatioImage > fRatioWindow )
			{
				// ͼ���߱ȴ��ڻ�����߱�
				LONG lHeight = (LONG)(rect.Width()/fRatioImage);

				rectDest.left = rect.left;
				rectDest.right = rect.right;
				rectDest.top = rect.top + (LONG)((rect.Height()-lHeight)/2.0);
				rectDest.bottom = rectDest.top + lHeight;
			}
			else
			{
				LONG lWidth = (LONG)(rect.Height()*fRatioImage);

				rectDest.top = rect.top;
				rectDest.bottom = rect.bottom;

				rectDest.left = rect.left + (LONG)((rect.Width()-lWidth)/2.0);
				rectDest.right = rectDest.left + lWidth;
			}
			
			// ����ͼƬ��С�ٻ��ƣ�CxImage��ͼ�������ͼƬ��С��һ��ʱ���ܻ�������
			image.Resample(rectDest.Width(), rectDest.Height(), 1, &imageNew);
		}
		break;
	case ImageModeScaleAspectFill: // ���-���ж���
		{
			// ��ͼ��������ⲿ��������
			CxImage imageTemp;
			SIZE	imgNewSize;
			RECT	clipRect;

			rectDest = rect;

			// ͼƬ�ȷŴ�/��С��������ͼ����Ĳ���Ҫ�ü���

			if ( fRatioImage > fRatioWindow )
			{
				// ͼ���߱ȴ��ڻ�����߱�
				imgNewSize.cy = rectDest.Height();
				imgNewSize.cx = (long)(imgNewSize.cy * fRatioImage + 0.5);

				clipRect.top = 0;
				clipRect.bottom = clipRect.top+imgNewSize.cy;
				clipRect.left = (imgNewSize.cx - rectDest.Width())/2;
				clipRect.right = clipRect.left + rectDest.Width();
			}
			else
			{
				imgNewSize.cx = rectDest.Width();
				imgNewSize.cy = (long)(imgNewSize.cx / fRatioImage + 0.5);

				clipRect.left = 0;
				clipRect.right = clipRect.left+imgNewSize.cx;
				clipRect.top = (imgNewSize.cy - rectDest.Height())/2;
				clipRect.bottom = clipRect.top + rectDest.Height();
			}
			
			// ������
			image.Resample(imgNewSize.cx, imgNewSize.cy, 1, &imageNew);
			// �ü����������(Ŀǰ���Դ�͸��ͨ����ͼƬ�ڲ��к����ɱ���ɫΪ��ɫ!!!)
			imageNew.Crop(clipRect, NULL);
		}
		break;
	case ImageModeScaleToFill: // Ĭ��������
	default:
		{
			rectDest = rect;
			// ����ͼƬ��С�ٻ��ƣ�CxImage��ͼ�������ͼƬ��С��һ��ʱ���ܻ�������
			image.Resample(rectDest.Width(), rectDest.Height(), 1, &imageNew);
		}
		break;
	}
	
	imageNew.Draw(pDC->GetSafeHdc(), rectDest, NULL, TRUE);

	return TRUE;

}

// Ӳ����Ϊģ�鵱ǰĿ¼�µ�ResĿ¼
BOOL CxImageOperation::GetImagePath()
{
	TCHAR szImagePath[MAX_PATH] = {0};
	GetModuleFileName(GetModuleHandle(NULL), szImagePath, MAX_PATH);
	TCHAR* lpszPos = _tcsrchr(szImagePath, L'\\');
	*(lpszPos+1) = TEXT('\0');
	_tcscat(szImagePath, TEXT("Res"));
	m_strImageRootPath = szImagePath;
	return TRUE;
}
