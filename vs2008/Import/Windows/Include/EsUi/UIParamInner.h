///////////////////////////////////////////////////////////
//  UIParamInner.h
//  Some type definitions
//  Created on:      27-ʮ��-2012 21:33:15
//  Original author: Simon
///////////////////////////////////////////////////////////

#if !defined(EA_37552088_CC47_4b76_8933_04ECD020300A__INCLUDED_)
#define EA_37552088_CC47_4b76_8933_04ECD020300A__INCLUDED_

// ��ͷ�ļ�����ĸ����������Ϳ��Ա��ͻ�����ͷ�������ͬʱʹ�ã������ܱ��ͻ�����ʹ�á�
// Ҳ����˵����Щ���������ǲ����⿪�ŵġ�


// UIParamInner�����˿ͻ����������ڲ�ͨѶЭ��
typedef struct tagUIParamInner
{
	enum EnUIPIType
	{
		UIPIT_UNKNOWN				= 0,				// ��Ч��ֵ
		UIPIT_CONNECT_INTERACTION	= 1,				// ����һ���Ự
		UIPIT_FINISH_INTERACTION	= 2,				// �����Ự 
	}type;

	enum EnUIPIResult
	{
		UIPIR_NOT_PROCESSED			= 0,
		UIPIR_FAILURE				= 1,
		UIPIR_SUCCESS				= 2
	}result;

	struct UIPIData
	{
		// �����ỰID
		unsigned int		uInteractionID;
		// ��typeΪUIPIT_CONNECT_INTERACTION��ʱ��szTokenName����Ϊ�գ����Դ����ִ��������Ự��
		// ���򣬷������Զ�����һ������(UUID)���������Ự���������ɵ����ֻ�����szTokenName
		wchar_t				szSessionName[256];
		unsigned int		uServerPid; // UI��������PID
	}data;

}BlkUIParamInner;

#endif // !defined(EA_37552088_CC47_4b76_8933_04ECD020300A__INCLUDED_)
