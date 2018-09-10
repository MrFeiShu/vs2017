//////////////////////////////////////////////////////////////////////
// PictureEx.cpp: implementation of the CPictureEx class.
//
// Picture displaying control with support for the following formats:
// GIF (including animated GIF87a and GIF89a), JPEG, BMP, WMF, ICO, CUR
// 
// Written by Oleg Bykov (oleg_bykoff@rsdn.ru)
// Copyright (c) 2001
//
// To use CPictureEx, follow these steps:
//   - place a static control on your dialog (either a text or a bitmap)
//   - change its identifier to something else (e.g. IDC_MYPIC)
//   - associate a CStatic with it using ClassWizard
//   - in your dialog's header file replace CStatic with CPictureEx
//     (don't forget to #include "PictureEx.h" and add 
//     PictureEx.h and PictureEx.cpp to your project)
//   - call one of the overloaded CPictureEx::Load() functions somewhere
//     (OnInitDialog is a good place to start)
//   - if the preceding Load() succeeded call Draw()
//  
// You can also add the control by defining a member variable of type 
// CPictureEx, calling CPictureEx::Create (derived from CStatic), then 
// CPictureEx::Load and CPictureEx::Draw.
//
// By default, the control initializes its background to COLOR_3DFACE
// (see CPictureEx::PrepareDC()). You can change the background by
// calling CPictureEx::SetBkColor(COLORREF) after CPictureEx::Load().
//
// I decided to leave in the class the functions to write separate frames from 
// animated GIF to disk. If you want to use them, uncomment #define GIF_TRACING 
// and an appropriate section in CPictureEx::Load(HGLOBAL, DWORD). These functions 
// won't be compiled and linked to your project unless you uncomment #define GIF_TRACING,
// so you don't have to worry.
// 
// Warning: this code hasn't been subject to a heavy testing, so
// use it on your own risk. The author accepts no liability for the 
// possible damage caused by this code.
//
// Version 1.0  7 Aug 2001
//              Initial release
//
// Version 1.1  6 Sept 2001
//              ATL version of the class
//
// Version 1.2  14 Oct 2001
//              - Fixed a problem with loading GIFs from resources
//                in MFC-version of the class for multi-modules apps.
//                Thanks to Ruben Avila-Carretero for finding this out.
//
//              - Got rid of waitable timer in ThreadAnimation()
//                Now CPictureEx[Wnd] works in Win95 too.
//                Thanks to Alex Egiazarov and Wayne King for the idea.
//
//              - Fixed a visual glitch of using SetBkColor.
//                Thanks to Kwangjin Lee for finding this out.
//
// Version 1.3  10 Nov 2001
//              - Fixed a DC leak. One DC leaked per each UnLoad()
//                (forgot to put a ReleaseDC() in the end of 
//                CPictureExWnd::PrepareDC() function).
//
//              - Now it is possible to set a clipping rectangle using
//                CPictureEx[Wnd]::SetPaintRect(const LPRECT) function.
//                The LPRECT parameter tells the class what portion of
//                a picture should it display. If the clipping rect is 
//                not set, the whole picture is shown.
//                Thanks to Fabrice Rodriguez for the idea.
//
//              - Added support for Stop/Draw. Now you can Stop() an
//                animated GIF, then Draw() it again, it will continue
//                animation from the frame it was stopped on. You can 
//                also know if a GIF is currently playing with the 
//                IsPlaying() function.
//             
//              - Got rid of math.h and made m_bExitThread volatile. 
//                Thanks to Piotr Sawicki for the suggestion.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "PictureEx.h"
#include <process.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPictureEx::CPictureEx()
{
	m_pPicture		   = NULL;
	m_hThread		   = NULL;
	m_hBitmap          = NULL;
	m_hMemDC		   = NULL;

	m_hDispMemDC       = NULL;
	m_hDispMemBM       = NULL;
	m_hDispOldBM       = NULL;

	m_bIsInitialized   = FALSE;
	m_bExitThread	   = FALSE;
	m_bIsPlaying       = FALSE;
	m_clrBackground    = RGB(255,255,255); // white by default
	m_nCurrFrame	   = 0;
	m_PictureSize.cx = m_PictureSize.cy = 0;
	SetRect(&m_PaintRect,0,0,0,0);


	m_hExitEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
}

CPictureEx::~CPictureEx()
{
	CloseHandle(m_hExitEvent);
}

BEGIN_MESSAGE_MAP(CPictureEx, CStatic)
	//{{AFX_MSG_MAP(CPictureEx)
	ON_WM_DESTROY()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CPictureEx::Load(CxImageGif* pImageGif)
{
	if ( NULL == pImageGif )
	{
		return FALSE;
	}
	m_pImageGif = pImageGif;
	int i = 0;
	for ( ;i < m_pImageGif->GetFrameCount(); i++)
	{
		m_arrFrames.push_back(*(m_pImageGif->GetFrame(i)));
	}
	m_PictureSize	= m_pImageGif->GetSize();
	m_clrBackground	= m_pImageGif->GetBackGroundColor();
	return TRUE;
}

BOOL CPictureEx::Draw()
{
	PrepareDC(m_PictureSize.cx,m_PictureSize.cy);
	if (!m_bIsInitialized)
	{
		TRACE(_T("Call one of the CPictureEx::Load() member functions before calling Draw()\n"));
		return FALSE;
	};

	if (IsAnimatedGIF())
	{
	// the picture needs animation
	// we'll start the thread that will handle it for us
		unsigned int nDummy;
//		unsigned long nDummy;
		m_hThread = (HANDLE) _beginthreadex(NULL,0,_ThreadAnimation,this,
			CREATE_SUSPENDED,&nDummy);
// 		m_hThread = (HANDLE) CreateThread(NULL,0,_ThreadAnimation,this,
// 			CREATE_SUSPENDED,&nDummy);
		if (!m_hThread)
		{
			TRACE(_T("Draw: Couldn't start a GIF animation thread\n"));
			return FALSE;
		} 
		else
		{
// 			CloseHandle(m_hThread);
// 			m_hThread = (HANDLE) CreateThread(NULL,0,_ThreadAnimation,this,
// 				CREATE_SUSPENDED,&nDummy);
			ResumeThread(m_hThread);
		}
	} 
	else
	{
		if (m_pPicture)
		{
			long hmWidth;
			long hmHeight;
			m_pPicture->get_Width(&hmWidth);
			m_pPicture->get_Height(&hmHeight);
			if (m_pPicture->Render(m_hMemDC, 0, 0, m_PictureSize.cx, m_PictureSize.cy, 
				0, hmHeight, hmWidth, -hmHeight, NULL) == S_OK)
			{
				Invalidate(FALSE);
				return TRUE;
			};
		};
	};

	return FALSE;	
}

// unsigned long WINAPI CPictureEx::_ThreadAnimation(LPVOID pParam)
UINT WINAPI CPictureEx::_ThreadAnimation(LPVOID pParam)
{
	ASSERT(pParam);
	CPictureEx *pPic = reinterpret_cast<CPictureEx *> (pParam);

	pPic->m_bIsPlaying = TRUE;
	pPic->ThreadAnimation();
	pPic->m_bIsPlaying = FALSE;

	// this thread has finished its work so we close the handle
	CloseHandle(pPic->m_hThread); 
	// and init the handle to zero (so that Stop() doesn't Wait on it)
	pPic->m_hThread = 0;
	return 0;
}

void CPictureEx::ThreadAnimation()
{
	// first, restore background (for stop/draw support)
	// disposal method #2
	if (m_arrFrames[m_nCurrFrame].m_nDisposal == 2)
	{
		HBRUSH hBrush = CreateSolidBrush(m_clrBackground);
		if (hBrush)
		{
			RECT rect = {
				m_arrFrames[m_nCurrFrame].m_frameOffset.cx,
				m_arrFrames[m_nCurrFrame].m_frameOffset.cy,
				m_arrFrames[m_nCurrFrame].m_frameOffset.cx + m_arrFrames[m_nCurrFrame].m_frameSize.cx,
				m_arrFrames[m_nCurrFrame].m_frameOffset.cy + m_arrFrames[m_nCurrFrame].m_frameSize.cy };
			FillRect(m_hMemDC,&rect,hBrush);
			DeleteObject(hBrush);
		};
	} 
	else
		// disposal method #3
		if (m_hDispMemDC && (m_arrFrames[m_nCurrFrame].m_nDisposal == 3) )
		{
			// put it back
			BitBlt(m_hMemDC,
				m_arrFrames[m_nCurrFrame].m_frameOffset.cx,
				m_arrFrames[m_nCurrFrame].m_frameOffset.cy,
				m_arrFrames[m_nCurrFrame].m_frameSize.cx,
				m_arrFrames[m_nCurrFrame].m_frameSize.cy,
				m_hDispMemDC,0,0, SRCCOPY);
			// init variables
			SelectObject(m_hDispMemDC,m_hDispOldBM);
			DeleteDC(m_hDispMemDC); m_hDispMemDC = NULL;
			DeleteObject(m_hDispMemBM); m_hDispMemBM = NULL;
		};

	while (!m_bExitThread)
	{
		if (m_arrFrames[m_nCurrFrame].m_pPicture)
		{
		///////////////////////////////////////////////////////
		// Before rendering a frame we should take care of what's 
		// behind that frame. TFrame::m_nDisposal will be our guide:
		//   0 - no disposal specified (do nothing)
		//   1 - do not dispose (again, do nothing)
		//   2 - restore to background color (m_clrBackground)
		//   3 - restore to previous

			//////// disposal method #3
			if (m_arrFrames[m_nCurrFrame].m_nDisposal == 3)
			{
				// prepare a memory DC and store the background in it
				m_hDispMemDC = CreateCompatibleDC(m_hMemDC);
				m_hDispMemBM = CreateCompatibleBitmap(m_hMemDC,
							m_arrFrames[m_nCurrFrame].m_frameSize.cx,
							m_arrFrames[m_nCurrFrame].m_frameSize.cy);
				
				if (m_hDispMemDC && m_hDispMemBM)
				{
					m_hDispOldBM = reinterpret_cast<HBITMAP> (SelectObject(m_hDispMemDC,m_hDispMemBM));
					BitBlt(m_hDispMemDC,0,0,
						m_arrFrames[m_nCurrFrame].m_frameSize.cx,
						m_arrFrames[m_nCurrFrame].m_frameSize.cy,
						m_hMemDC,
						m_arrFrames[m_nCurrFrame].m_frameOffset.cx,
						m_arrFrames[m_nCurrFrame].m_frameOffset.cy,
						SRCCOPY);
				};
			};
			///////////////////////

			long hmWidth;
			long hmHeight;
			m_arrFrames[m_nCurrFrame].m_pPicture->get_Width(&hmWidth);
			m_arrFrames[m_nCurrFrame].m_pPicture->get_Height(&hmHeight);

			if (m_arrFrames[m_nCurrFrame].m_pPicture->Render(m_hMemDC, 
				m_arrFrames[m_nCurrFrame].m_frameOffset.cx, 
				m_arrFrames[m_nCurrFrame].m_frameOffset.cy, 
				m_arrFrames[m_nCurrFrame].m_frameSize.cx, 
				m_arrFrames[m_nCurrFrame].m_frameSize.cy, 
				0, hmHeight, hmWidth, -hmHeight, NULL) == S_OK)
			{
				Invalidate(FALSE);
			};
			
			if (m_bExitThread) break;

			::WaitForSingleObject(m_hExitEvent, 10*m_arrFrames[m_nCurrFrame].m_nDelay);

			if (m_bExitThread) break;

			// disposal method #2
			if (m_arrFrames[m_nCurrFrame].m_nDisposal == 2)
			{
				HBRUSH hBrush = CreateSolidBrush(m_clrBackground);
				if (hBrush)
				{
					RECT rect = {
						m_arrFrames[m_nCurrFrame].m_frameOffset.cx,
						m_arrFrames[m_nCurrFrame].m_frameOffset.cy,
						m_arrFrames[m_nCurrFrame].m_frameOffset.cx + m_arrFrames[m_nCurrFrame].m_frameSize.cx,
						m_arrFrames[m_nCurrFrame].m_frameOffset.cy + m_arrFrames[m_nCurrFrame].m_frameSize.cy };
					FillRect(m_hMemDC,&rect,hBrush);
					DeleteObject(hBrush);
				};
			} 
			else
				if (m_hDispMemDC && (m_arrFrames[m_nCurrFrame].m_nDisposal == 3) )
				{
					// put it back
					BitBlt(m_hMemDC,
						m_arrFrames[m_nCurrFrame].m_frameOffset.cx,
						m_arrFrames[m_nCurrFrame].m_frameOffset.cy,
						m_arrFrames[m_nCurrFrame].m_frameSize.cx,
						m_arrFrames[m_nCurrFrame].m_frameSize.cy,
						m_hDispMemDC,0,0, SRCCOPY);
					// init variables
					SelectObject(m_hDispMemDC,m_hDispOldBM);
					DeleteDC(m_hDispMemDC); m_hDispMemDC = NULL;
					DeleteObject(m_hDispMemBM); m_hDispMemBM = NULL;
				};
		};
		m_nCurrFrame++;
		if (m_nCurrFrame == m_arrFrames.size())
		{
			m_nCurrFrame = 0;
			HBRUSH hBrush = CreateSolidBrush(m_clrBackground);
			if (hBrush)
			{
				RECT rect = {0,0,m_PictureSize.cx,m_PictureSize.cy};
				FillRect(m_hMemDC,&rect,hBrush);
				DeleteObject(hBrush);
			};
			GetParent()->PostMessage(MSG_GIF_PLAY_END, 0, 0);
			break;
		};
	};
}

void CPictureEx::Stop()
{
	m_bIsPlaying = FALSE;
	m_bExitThread = TRUE;
	SetEvent(m_hExitEvent);
	if (m_hThread)
	{
		// we'll wait for 0.5 seconds then continue execution
		WaitForSingleObject(m_hThread,500);
		CloseHandle(m_hThread);
		m_hThread = NULL;
	}
	ResetEvent(m_hExitEvent);
	m_arrFrames.clear();
	m_nCurrFrame = 0;
	m_bExitThread = FALSE;
}

BOOL CPictureEx::IsAnimatedGIF() const
{
	return (m_arrFrames.size() > 1);
}

void CPictureEx::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	LONG nPaintWidth = m_PaintRect.right-m_PaintRect.left;

	if (nPaintWidth > 0)
	{
		LONG nPaintHeight = m_PaintRect.bottom - m_PaintRect.top;
		::BitBlt(dc.m_hDC, 0, 0, nPaintWidth, nPaintHeight,	
			m_hMemDC, m_PaintRect.left, m_PaintRect.top, SRCCOPY);
	}
	else
	{
		::BitBlt(dc.m_hDC, 0, 0, m_PictureSize.cx, m_PictureSize.cy,
			m_hMemDC, 0, 0, SRCCOPY);
	};
}

BOOL CPictureEx::PrepareDC(int nWidth, int nHeight)
{
	HDC hWinDC = ::GetDC(m_hWnd);
	if (!hWinDC) return FALSE;
	
	m_hMemDC = CreateCompatibleDC(hWinDC);
	if (!m_hMemDC) 
	{
		::ReleaseDC(m_hWnd,hWinDC);
		return FALSE;
	};

	m_hBitmap  = CreateCompatibleBitmap(hWinDC,nWidth,nHeight);
	if (!m_hBitmap) 
	{
		::ReleaseDC(m_hWnd,hWinDC);
		::DeleteDC(m_hMemDC);
		return FALSE;
	};

	m_hOldBitmap = reinterpret_cast<HBITMAP> 
						(SelectObject(m_hMemDC,m_hBitmap));
	
	// fill the background
	//m_clrBackground = GetSysColor(COLOR_3DFACE);
	RECT rect = {0,0,nWidth,nHeight};
	FillRect(m_hMemDC,&rect,(HBRUSH)(COLOR_WINDOW));

	::ReleaseDC(m_hWnd,hWinDC);
	m_bIsInitialized = TRUE;
	return TRUE;
}

void CPictureEx::OnDestroy() 
{
	Stop();	
	CStatic::OnDestroy();
}

