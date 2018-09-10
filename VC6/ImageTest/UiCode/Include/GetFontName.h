// GetFontName.h: interface for the CGetFontName class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GETFONTNAME_H__89B98BD2_0B67_4FD9_843D_BB217E756334__INCLUDED_)
#define AFX_GETFONTNAME_H__89B98BD2_0B67_4FD9_843D_BB217E756334__INCLUDED_

#include <EsTypeDef.h>
#include <EsCommon/EsSystem.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGetFontName  
{

public:
	static CGetFontName* GetSingleInstance(u4 u4LangId = LANGE_ZH_CN)
	{
		if ( NULL == singleInstance )
		{
			singleInstance  = new CGetFontName(u4LangId);
		}
		return singleInstance;
}

private:
	CGetFontName(u4 u4LangId);
	u4	m_u4LangId;
	static CGetFontName*	singleInstance;
	
	//��CGarbo����������������ɾ��CGetFontName��ʵ��
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if ( CGetFontName::GetSingleInstance() )
			{
				delete CGetFontName::GetSingleInstance();
			}
		}
	};
	static CGarbo Garbo;

	CString			m_strFontName;
	CStringArray	m_asFontNameUser_CN;				//����ϵͳ�£��û�ָ���������������ƣ������ȼ�����
	CStringArray	m_asFontNameUser_EN;				//Ӣ��ϵͳ�£��û�ָ��������Ӣ�����ƣ������ȼ�����
	CStringArray	m_asFontName;						//�û�ָ���Ĳ�����ϵͳ���ڵ�����
protected:
	// Real functions
	void	Enumerate (HDC hdc);
	void	Enumerate (CDC* pdc);
	void	Enumerate (CWnd* pWnd);
	void	DoEnumerate (HDC hdc);
	void	InternalEnumerate (CDC* pdc,	bool bWayBack);
	void	InternalEnumerate (CWnd* pWnd,	bool bWayBack);
	void	InternalEnumerate (HDC hdc,		bool bWayBack);
// Function called from callback in EnumProc
friend int CALLBACK EnumFontFamProc(LPENUMLOGFONT lpelf,LPNEWTEXTMETRIC lpntm, DWORD nFontType,long lparam);

public:
	void GetFontName(CString& strFontName) const;
};

#endif // !defined(AFX_GETFONTNAME_H__89B98BD2_0B67_4FD9_843D_BB217E756334__INCLUDED_)
