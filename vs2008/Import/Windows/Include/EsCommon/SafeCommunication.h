//////////////////////////////////////////////////////////////////////////
// Copyright (c) 2012,深圳市文鼎创数据安全有限公司
// All rights reserved.
// 
// 文件名称：
//		SafeCommunication.h
//
// 文件标识：
//
// 摘   要：
//		在命名空间SafeCommunication中，定义一组与安全通讯相关的函数。
//		通讯的安全基于算法的保密。参考了《ICBC-U盾PIN码框加固项目-接口及加解密算法设计.doc》。
// 
// 当前版本：
//		1.0
//
// 作   者：
//		伍友良
//
// 完成日期：
//		2012年11月04日
//////////////////////////////////////////////////////////////////////////
#ifndef _SAFE_COMMUNICATION_INCLUDED_
#define _SAFE_COMMUNICATION_INCLUDED_

namespace SafeCommunication
{
	
	// 生成随机数
	bool GenRand(unsigned char* pbRand, int cbRandLen);
	// 生成3DesKey
	bool TripleDes168GenKey(const unsigned char* pbKeySeed, int cbSeedLen, unsigned char* pbKey, int& cbKeyLen);
	// 设置身份认证参数
	bool SetAuthenticationParam(const unsigned char* pbRand, int cbRandLen, unsigned char* pbParam, int& cbParamLen);
	// 验证身份认证参数
	bool VerifyAuthenticationParam(const unsigned char* pbParam, int cbParamLen);
}
#endif