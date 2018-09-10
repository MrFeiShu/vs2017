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

#if !defined(AFX_PICTUREEX_H__0EFE5DE0_7B68_4DB7_8B34_5DC634948438__INCLUDED_)
#define AFX_PICTUREEX_H__0EFE5DE0_7B68_4DB7_8B34_5DC634948438__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include "xImageGif.h"

const UINT MSG_GIF_PLAY_END	= RegisterWindowMessage(_T("GifPlayEnd"));

//#define GIF_TRACING  // uncomment it if you want detailed TRACEs
class CPictureEx : public CStatic
{
public:
	CPictureEx();
	virtual ~CPictureEx();
	void Stop();   // stops animation
	BOOL IsAnimatedGIF() const;
	BOOL Draw();
	BOOL Load(CxImageGif* pImageGif);

protected:
	CxImageGif* m_pImageGif;

	RECT m_PaintRect;
	COLORREF m_clrBackground;
	UINT m_nCurrFrame;
	BOOL m_bIsPlaying;
	volatile BOOL m_bExitThread;
	BOOL m_bIsInitialized;
	HDC m_hMemDC;

	HDC m_hDispMemDC;
	HBITMAP m_hDispMemBM;
	HBITMAP m_hDispOldBM;

	HBITMAP m_hBitmap;
	HBITMAP m_hOldBitmap;
	HANDLE m_hThread;
	HANDLE m_hExitEvent;
	IPicture * m_pPicture;
	unsigned char * m_pRawData;
	SIZE m_PictureSize;
	std::vector<TFrame> m_arrFrames;
//	TFrame m_arrFrames;
	void ThreadAnimation();
// 	static unsigned long WINAPI _ThreadAnimation(LPVOID pParam);
	static UINT WINAPI _ThreadAnimation(LPVOID pParam);

	BOOL PrepareDC(int nWidth, int nHeight);
	// Generated message map functions
	//{{AFX_MSG(CPictureEx)
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_PICTUREEX_H__0EFE5DE0_7B68_4DB7_8B34_5DC634948438__INCLUDED_)
