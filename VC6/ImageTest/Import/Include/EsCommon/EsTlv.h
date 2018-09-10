#ifndef _ESTLV_H_
#define _ESTLV_H_

#include "../EsTypeDef.h"
#include "../EsCommon/EsCommon.h"

#define MIN_TAGLEN_SIZE	(2)

// ���̶����ֽ�������
#pragma pack(push, 1)

typedef struct BlkTlvTreeTag BlkTlvTree;
typedef struct BlkTlvTreeTag
{
	u4			m_u4Tag;
	u4			m_u4ValueLen;
	u1*			m_pu1Value;		// ����Ǹ��϶��󣬴�ֵΪNULL
	u1			m_u1TagLenSize;
	BlkTlvTree*	m_pblkNext;		// ͬ������һ���ڵ�
	BlkTlvTree*	m_pblkChild;	// �ж��Ƿ�Ϊ���϶��������
	BlkTlvTree*	m_pblkParent;
}BlkTlvTree;

#pragma pack(pop)

#ifdef __cplusplus
extern "C"
{
#endif
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			����һ�����ݣ����������е�һ��TLV��T��L����Ϣ��
	// ����	
	//			pu1Tlv			[IN] TLV������һ�Σ���TLV�е�Tag��ʼ
	//			u1Len			[IN] pu1Data�ĳ��ȡ�����������Ҫ��֤�ܹ���pu1Data�н�����T��L
	//			pu4Tag			[OUT] ��pu1Data�н���������Tag������ΪNULL
	//			pu4ValueLen		[OUT] ��pu1Data�н���������value length������ΪNULL
	//			pu1IsComplex	[OUT] 0: �Ǹ��϶���;����: ���϶��󡣿���ΪNULL
	// ����ֵ
	//			size of (Tag and value len) 0 ��ʾ������Ч.
	//////////////////////////////////////////////////////////////////////////
	typedef u1 (CALL_TYPE *FunGetTagAndLen)(const u1* pu1Tlv, u4 u4Len, u4* pu4Tag, u4* pu4ValueLen);

	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			��Tag���б��룬�����Ϊ�ֽ���
	// ����	
	//			u4Tag		[IN] Tag
	//			pu1Tag		[OUT] ������Tag.
	// ����ֵ
	//			�����Tagռ�õ��ֽ���
	//////////////////////////////////////////////////////////////////////////
	typedef u1 (CALL_TYPE *FunEncodeTag)(u4 u4Tag, u1* pu1Tag);
	
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			��value length���б��룬�����Ϊ�ֽ���
	// ����	
	//			u4ValueLen	[IN] value length
	//			pu1ValueLen	[OUT] ������value length.
	// ����ֵ
	//			�����Lengthռ�õ��ֽ���
	//////////////////////////////////////////////////////////////////////////
	typedef u1 (CALL_TYPE *FunEncodeLength)(u4 u4ValueLen, u1* pu1ValueLen);

	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			��ʼ��TLV
	// ����
	//			funGetTagAndLen	[IN] TAG and len�Ľ���ӿڡ�ΪNULLʱʹ�ñ�׼TLV����ʽ
	//			funEncodeTag	[IN] TAG��������ӿڡ�ΪNULLʱʹ�ñ�׼TLV����ʽ
	//			funEncodeLength	[IN] Value length�Ľ���ӿڡ�ΪNULLʱʹ�ñ�׼TLV����ʽ
	//			phTlv			[OUT] ���TLV�ľ��
	// ����ֵ
	//			0: �ɹ�������: ʧ��
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvInit(const FunGetTagAndLen funGetTagAndLen, const FunEncodeTag funEncodeTag, const FunEncodeLength funEncodeLength, ESHANDLE* phTlv);

	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			����ʼ��TLV
	// ����
	//			hTlv [IN] TLV�ľ��
	// ����ֵ
	//			0: �ɹ�������: ʧ��
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvDeinit(ESHANDLE hTlv);

	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			��tag���б���
	// ����
	//			hTlv		[IN] TLV�ľ��
	//			u4Tag		[IN] tag
	//			pu1Tag		[OUT] ������tag������ʱ��ص����������ĳ����ɵ�����ȷ��������ΪNULL��
	//			pu1TagSize	[IN/OUT] ����pu1Tag�ĳ��ȣ���������tagռ�õ��ֽ�����
	// ����ֵ
	//			0: �ɹ�������: ʧ�� 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvEncodeTag(ESHANDLE hTlv, u4 u4Tag, u1* pu1Tag, u1* pu1TagSize);
	
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			��ValueLen���б���
	// ����
	//			hTlv		[IN] TLV�ľ��
	//			u4ValueLen	[IN] ValueLentag
	//			pu1ValueLen	[OUT] ������ValueLen������ʱ��ص����������ĳ����ɵ�����ȷ��������ΪNULL��
	//			pu1LenSize	[IN/OUT] ����pu1ValueLen�ĳ��ȣ���������ValueLenռ�õ��ֽ�����
	// ����ֵ
	//			0: �ɹ�������: ʧ�� 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvEncodeLen(ESHANDLE hTlv, u4 u4ValueLen, u1* pu1ValueLen, u1* pu1LenSize);
	
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			��ָ����TLV���ݴ���һ��TLV�ڵ㡣������Ƕ�׻����ֵܽڵ�
	// ����
	//			hTlv			[IN] TLV�ľ��
	//			pu1Tlv			[IN] TLV����
	//			u4TlvLen		[IN] TLV���ݳ���
	//			ppblkTlvTree	[OUT] �ǿա������´�����TLV�ڵ�
	// ����ֵ
	//			0: �ɹ�������: ʧ�� 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvNewOneNode(ESHANDLE hTlv, const u1* pu1Tlv, u4 u4TlvLen, BlkTlvTree** ppblkTlvTree);
	
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			����һ��TLV�ڵ㡣������Ƕ�׻����ֵܽڵ�
	// ����
	//			hTlv			[IN] TLV�ľ��
	//			u4Tag			[IN] u4Tag
	//			u4ValueLen		[IN] value len
	//			pvValue			[OUT] value����
	//			ppblkTlvTree	[OUT] �ǿա������´�����TLV�ڵ�
	// ����ֵ
	//			0: �ɹ�������: ʧ�� 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvNewOneNode2(ESHANDLE hTlv, u4 u4Tag, u4 u4ValueLen, const void* pvValue, BlkTlvTree** ppblkTlvTree);
	
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			�ͷ�TLV���ڴ�
	// ����
	//			ppblkTlvTree	[IN] TLV���ĵ�ַ
	// ����ֵ
	//			0: �ɹ�������: ʧ�� 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvTreeFree(BlkTlvTree** ppblkTlvTree);
	
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			����TLV���ݣ���ת��ΪTLV�����ᴦ���ӽڵ���ֵܽڵ㣩
	// ����
	//			hTlv			[IN] TLV�ľ��
	//			pu1Tlv			[IN] TLV����
	//			u4TlvLen		[IN] TLV���ݳ���
	//			ppblkTlvTree	[OUT] �ǿա������´�����TLV�ڵ�
	// ����ֵ
	//			0: �ɹ�������: ʧ�� 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvTreeDeflat(ESHANDLE hTlv, const u1* pu1Tlv, u4 u4TlvLen, BlkTlvTree** ppblkTlvTree);
	
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			չ��TLV����
	// ����
	//			hTlv			[IN] TLV�ľ��
	//			pblkTlvTree		[IN] TLV����ַ
	//			pu1Tlv			[IN] չ�����TLV���ݡ�����ΪNULL
	//			pu4TlvLen		[OUT] �ǿա�����չ�����TLV����ռ�õ��ڴ��ֽ���
	// ����ֵ
	//			0: �ɹ�������: ʧ�� 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvTreeFlat(ESHANDLE hTlv, const BlkTlvTree* pblkTlvTree, u1* pu1Tlv, u4* pu4TlvLen);
	
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			����ӽڵ�
	// ����
	//			hTlv				[IN] TLV�ľ��
	//			pblkTlvTreeParent	[IN] ���ڵ�
	//			pblkTlvTreeChild	[IN] �ӽڵ�
	// ����ֵ
	//			0: �ɹ�������: ʧ�� 
	// ��ע:
	//			[ע��]!!! 
	//			1. ���ڵ�ֱ���������ӽڵ㣬�ӽڵ��ѷ�����ڴ�ᱻ�ӹܣ�����Ҫ�����ͷ�
	//			2. ��ӳɹ��󣬻���¸��ڵ�����и��ڵ�ĳ�����Ϣ
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvTreeAddChild(ESHANDLE hTlv, BlkTlvTree* pblkTlvTreeParent, BlkTlvTree* pblkTlvTreeChild);
	
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			����ֵܽڵ�
	// ����
	//			hTlv				[IN] TLV�ľ��
	//			pblkTlvTreeRoot		[IN] ���ڵ�
	//			pblkTlvTreeSibling	[IN] �ֽڵ�
	// ����ֵ
	//			0: �ɹ�������: ʧ�� 
	// ��ע:
	//			[ע��]!!! 
	//			1. ���ڵ��������ֵܽڵ㣬�ֵܽڵ��ѷ�����ڴ�ᱻ�ӹܣ�����Ҫ�����ͷ�
	//			2. ��ӳɹ��󣬻���¸��ڵ�����и��ڵ�ĳ�����Ϣ
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvTreeAddSibling(ESHANDLE hTlv, BlkTlvTree* pblkTlvTreeRoot, BlkTlvTree* pblkTlvTreeSibling);
	
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			ͨ��tag����TLV�ڵ�
	// ����
	//			pblkTlvTree		[IN] TLV�ڵ�
	//			u4Tag			[IN] tag
	// ����ֵ
	//			���ҵ���TLV�ڵ�ָ�� 
	//////////////////////////////////////////////////////////////////////////
	const BlkTlvTree* EsTlvFindViaTag(const BlkTlvTree* pblkTlvTree, u4 u4Tag);
	
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//			�Ƚ�����TLV���Ƿ����
	// ����
	//			pblkTlvTree1	[IN] TLV��1
	//			pblkTlvTree2	[IN] TLV��2 
	// ����ֵ
	//			ESFALSE: �����
	//////////////////////////////////////////////////////////////////////////
	ESBOOL CALL_TYPE EsTlvTreeCompare(IN const BlkTlvTree* pblkTlvTree1, IN const BlkTlvTree* pblkTlvTree2);

#ifdef __cplusplus
};
#endif

#endif	// !define _ESTLV_H_
