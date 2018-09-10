#ifndef _PC_INFO_H_
#define _PC_INFO_H_

//PCInfo.h

#pragma once
#include <string>

class CPCInfo
{
public:
	CPCInfo(void);
	~CPCInfo(void);
public:
	// ��ȡMAC��ַ
	std::string& GetMAC();
	// ��ȡIP��ַ
	std::string& GetIP();
	// ��ȡ����ϵͳ
	std::string& GetOS();
	// �Ƿ�Ϊ����
	bool IsInternetBar();
private:
	std::string m_strIP;
	std::string m_strMAC;
	std::string m_strOS;
	bool m_bIsInternetBar;
};

#endif