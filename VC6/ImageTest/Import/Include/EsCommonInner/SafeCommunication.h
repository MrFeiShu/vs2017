//////////////////////////////////////////////////////////////////////////
// Copyright (c) 2012,�������Ķ������ݰ�ȫ���޹�˾
// All rights reserved.
// 
// �ļ����ƣ�
//		SafeCommunication.h
//
// �ļ���ʶ��
//
// ժ   Ҫ��
//		�������ռ�SafeCommunication�У�����һ���밲ȫͨѶ��صĺ�����
//		ͨѶ�İ�ȫ�����㷨�ı��ܡ��ο��ˡ�ICBC-U��PIN���ӹ���Ŀ-�ӿڼ��ӽ����㷨���.doc����
// 
// ��ǰ�汾��
//		1.0
//
// ��   �ߣ�
//		������
//
// ������ڣ�
//		2012��11��04��
//////////////////////////////////////////////////////////////////////////
#ifndef _SAFE_COMMUNICATION_INCLUDED_
#define _SAFE_COMMUNICATION_INCLUDED_

namespace SafeCommunication
{
	
	// ���������
	bool GenRand(unsigned char* pbRand, int cbRandLen);
	// ����3DesKey
	bool TripleDes168GenKey(const unsigned char* pbKeySeed, int cbSeedLen, unsigned char* pbKey, int& cbKeyLen);
	// ���������֤����
	bool SetAuthenticationParam(const unsigned char* pbRand, int cbRandLen, unsigned char* pbParam, int& cbParamLen);
	// ��֤�����֤����
	bool VerifyAuthenticationParam(const unsigned char* pbParam, int cbParamLen);
}
#endif