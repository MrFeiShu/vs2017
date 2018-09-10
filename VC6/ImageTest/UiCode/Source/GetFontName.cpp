// GetFontName.cpp: implementation of the CGetFontName class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include <GetFontName.h>
#include <EsCommon/EsCommon.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CGetFontName* CGetFontName::singleInstance = NULL;
CGetFontName::CGarbo CGetFontName::Garbo;

CGetFontName::CGetFontName(u4 u4LangId)
{
	m_u4LangId	= u4LangId;
	m_asFontNameUser_CN.RemoveAll();
	m_asFontName.RemoveAll();

	m_asFontNameUser_CN.Add(_T("微软雅黑"));
	m_asFontNameUser_CN.Add(_T("黑体"));
	m_asFontNameUser_EN.Add(_T("Microsoft YaHei"));	//英文系统下的“微软雅黑”字体名字
	m_asFontNameUser_EN.Add(_T("SimHei"));			//英文系统下的“黑体”字体名字

	CWindowDC pDC(NULL);
	Enumerate(pDC);
}

int CALLBACK EnumFontFamProc(LPENUMLOGFONT lpelf, LPNEWTEXTMETRIC lpntm, DWORD nFontType, long lparam) 
{ 
	CGetFontName*   pThis = ( CGetFontName* )lparam;
	if(pThis->m_strFontName != ( lpelf->elfLogFont.lfFaceName) )
	{
		pThis->m_strFontName = ( lpelf->elfLogFont.lfFaceName );

		if ( 0 == ( pThis->m_strFontName.Compare( pThis->m_asFontNameUser_CN.GetAt(0) ) ) || 0 == ( pThis->m_strFontName.Compare( pThis->m_asFontNameUser_EN.GetAt(0) ) ) )
		{
			pThis->m_asFontName.Add( pThis->m_strFontName );
		}
		if ( 0 == ( pThis->m_strFontName.Compare( pThis->m_asFontNameUser_CN.GetAt(1) ) ) || 0 == ( pThis->m_strFontName.Compare( pThis->m_asFontNameUser_EN.GetAt(1) ) ) )
		{
			pThis->m_asFontName.Add( pThis->m_strFontName );
		}
	}
	return 1;
}

void CGetFontName::DoEnumerate (HDC hdc)
{
	ASSERT(NULL != hdc);
	m_strFontName = "";
	LOGFONT lf;
	memset (&lf, 0, sizeof(lf));
	lf.lfCharSet	= DEFAULT_CHARSET;
	lf.lfFaceName[0]= 0;
	::EnumFontFamiliesEx (hdc, &lf, (FONTENUMPROC)::EnumFontFamProc, (LPARAM)this,0);		
}

void CGetFontName::InternalEnumerate (HDC hdc, bool bWayBack)
{
	// If no valid DC supplied
	if (NULL == hdc && bWayBack)
	{
		TRACE0("Warning! NULL hDC at CWizFontsEnumerator::Enumerate"); 
		// Get main app window (hopefully)
		CClientDC some(NULL);
		//CWnd* pSomeWnd = AfxGetMainWnd();
		InternalEnumerate(some, false); // No way back here again
	}
	else
		DoEnumerate (hdc);
}


void CGetFontName::InternalEnumerate (CDC* pdc,	bool bWayBack)
{
	if (NULL != pdc)
		InternalEnumerate(pdc->m_hAttribDC, bWayBack);
	else
	{
		TRACE0("Warning! NULL pDC at CWizFontsEnumerator::Enumerate");
		if (bWayBack) // try to figure up something
			InternalEnumerate ((HDC)NULL, bWayBack);
	}
}

void CGetFontName::InternalEnumerate (CWnd* pWnd,	bool bWayBack)
{
	if (NULL == pWnd)
	{
		TRACE0("Warning! NULL Window at CWizFontsEnumerator::Enumerate"); 
		if (bWayBack) // try to figure up something
			InternalEnumerate((HDC)NULL, bWayBack);
	}
	else
	{
		// Two attempts to get DC: client DC and, if fails,
		// window DC
		// BLOCK
		{
			CClientDC dc(pWnd);
			if (dc.m_hAttribDC != NULL)
			{
				InternalEnumerate(&dc, bWayBack);
				return;
			}
		}
		// BLOCK
		{
			CWindowDC dc(pWnd);
			InternalEnumerate(&dc, bWayBack);
		}
	}
}

void CGetFontName::Enumerate (HDC hdc)
{
	InternalEnumerate(hdc, true);
}

void CGetFontName::Enumerate (CDC* pdc)
{
	InternalEnumerate(pdc, true);
}

void CGetFontName::Enumerate (CWnd* pWnd)
{
	InternalEnumerate(pWnd, true);
}

void CGetFontName::GetFontName(CString& strFontName) const
{
	//英文系统下，也是按照用户指定的字体优先级去设置字体，所以暂时注释掉以下代码。
	//如果要求英文系统下，要求用Tahoma字体，就不要注释以下代码
// 	if ( LANGE_ZH_CN != m_u4LangId)
// 	{
// 		strFontName = _T("Tahoma");
// 		return;
// 	}
	if ( 0 == m_asFontName.GetSize() )
	{
		strFontName == _T("Tahoma");
	}
	else
	{
		for ( int i = 0; i < m_asFontName.GetSize(); i++)
		{
			
			if ( 0 == ( m_asFontName.GetAt(i).Compare(m_asFontNameUser_CN.GetAt(0)) ) || 0 == ( m_asFontName.GetAt(i).Compare(m_asFontNameUser_EN.GetAt(0)) ) )
			{
				strFontName = m_asFontName.GetAt(i);
				return;
			}
		}
		
		for ( int j = 0; j < m_asFontName.GetSize(); j++)
		{
			if ( 0 == ( m_asFontName.GetAt(j).Compare(m_asFontNameUser_CN.GetAt(1)) ) || 0 == ( m_asFontName.GetAt(j).Compare(m_asFontNameUser_EN.GetAt(1)) ) )
			{
				strFontName = m_asFontName.GetAt(j);
				return;
			}
		}
	}	
}

