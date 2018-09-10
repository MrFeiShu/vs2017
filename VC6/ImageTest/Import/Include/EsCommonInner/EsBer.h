#ifndef _ESBER_H_
#define _ESBER_H_

#include "../EsTypeDef.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BlkBerTag
{
	u2			m_u2Tag;			// TAG
	u4			m_u4ValueLen;		// VALUE的长度
	u1*			m_pu1Value;			// VALUE值，由库分配
	u1			m_u1TagLenSize;		// TAG和LEN在编码后占用的长度，TAG最多两个字节，LEN最多5个字节，不支持超过5个字节长度的TLV结构
	ESBOOL		m_bComplex;			// 是否是复合结构，也就是说其VALUE是否是TLV结构
}BlkBer;

typedef struct BlkBerTreeTag BlkBerTree;
typedef struct BlkBerTreeTag
{
	u2			m_u2Tag;
	u4			m_u4ValueLen;
	u1*			m_pu1Value;		// 如果是复合对象，此值为NULL
	u1			m_u1TagLenSize;
	ESBOOL		m_bComplex;		// 到这里与Ber结构保持一致
	BlkBerTree*	m_pblkSibling;
	BlkBerTree*	m_pblkChild;
	BlkBerTree*	m_pblkParent;
}BlkBerTree;

u4 CALL_TYPE EsBerEncodeTag(u2 u2Tag, u1* pu1Tag);
u4 CALL_TYPE EsBerEncodeLen(u4 u4ValueLen, u1* pu1Len);
void CALL_TYPE EsBerCalcTagLenSize(BlkBerTree* pblkBerTree);
u4 CALL_TYPE EsBerParse(const u1* pu1Ber, u4 u4BerLen, BlkBer* pblkBer);
u4 CALL_TYPE EsBerNew(const u1* pu1Ber, u4 u4BerLen, BlkBer** ppblkBer);
void CALL_TYPE EsBerFree(BlkBer* pblkBer);

u4 CALL_TYPE EsBerTreeNew(u2 u2Tag, u4 u4ValueLen, const void* pvValue, BlkBerTree** ppblkBerTree);
void EsBerTreeFree(BlkBerTree* pblkBerTree);
u4 CALL_TYPE EsBerTreeDeflat(const u1* pu1Ber, u4 u4BerLen, BlkBerTree** ppblkBerTree);
u4 CALL_TYPE EsBerTreeFlat(const BlkBerTree* pblkBerTree, u1* pu1Ber, u4* pu4BerLen);
u4 CALL_TYPE EsBerTreeGetChildren(IN const BlkBerTree* pblkBerTree, OUT BlkBerTree** ppblkBerTreeChildren, INOUT u4* pu4ChildrenNum);
u4 CALL_TYPE EsBerTreeGetHeadLen(IN const BlkBerTree* pblkBerTree);
ESBOOL CALL_TYPE EsBerTreeCompare(IN const BlkBerTree* pblkBerTree1, IN const BlkBerTree* pblkBerTree2);

u4 CALL_TYPE EsBerTreeAddChild(BlkBerTree* pblkBerTreeParent, BlkBerTree* pblkBerTreeChild);
u4 CALL_TYPE EsBerTreeMerge(u2 u2Tag, BlkBerTree* pblkBerTree1, BlkBerTree* pblkBerTree2, BlkBerTree** ppblkBerTreeParent);


#ifdef __cplusplus
};
#endif

#endif
