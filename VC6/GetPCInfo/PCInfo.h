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
	// 获取MAC地址
	std::string& GetMAC();
	// 获取IP地址
	std::string& GetIP();
	// 获取操作系统
	std::string& GetOS();
	// 是否为网吧
	bool IsInternetBar();
private:
	std::string m_strIP;
	std::string m_strMAC;
	std::string m_strOS;
	bool m_bIsInternetBar;
};

#endif