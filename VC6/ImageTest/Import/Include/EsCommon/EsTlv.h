#ifndef _ESTLV_H_
#define _ESTLV_H_

#include "../EsTypeDef.h"
#include "../EsCommon/EsCommon.h"

#define MIN_TAGLEN_SIZE	(2)

// 按固定的字节数对齐
#pragma pack(push, 1)

typedef struct BlkTlvTreeTag BlkTlvTree;
typedef struct BlkTlvTreeTag
{
	u4			m_u4Tag;
	u4			m_u4ValueLen;
	u1*			m_pu1Value;		// 如果是复合对象，此值为NULL
	u1			m_u1TagLenSize;
	BlkTlvTree*	m_pblkNext;		// 同级的下一个节点
	BlkTlvTree*	m_pblkChild;	// 判断是否为复合对象的依据
	BlkTlvTree*	m_pblkParent;
}BlkTlvTree;

#pragma pack(pop)

#ifdef __cplusplus
extern "C"
{
#endif
	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			输入一段数据，返回数据中第一个TLV的T和L的信息。
	// 参数	
	//			pu1Tlv			[IN] TLV数据中一段，以TLV中的Tag开始
	//			u1Len			[IN] pu1Data的长度。长度理论上要保证能够从pu1Data中解析出T和L
	//			pu4Tag			[OUT] 从pu1Data中解析出来的Tag。可以为NULL
	//			pu4ValueLen		[OUT] 从pu1Data中解析出来的value length。可以为NULL
	//			pu1IsComplex	[OUT] 0: 非复合对象;其它: 复合对象。可以为NULL
	// 返回值
	//			size of (Tag and value len) 0 表示数据无效.
	//////////////////////////////////////////////////////////////////////////
	typedef u1 (CALL_TYPE *FunGetTagAndLen)(const u1* pu1Tlv, u4 u4Len, u4* pu4Tag, u4* pu4ValueLen);

	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			对Tag进行编码，并输出为字节流
	// 参数	
	//			u4Tag		[IN] Tag
	//			pu1Tag		[OUT] 编码后的Tag.
	// 返回值
	//			编码后Tag占用的字节数
	//////////////////////////////////////////////////////////////////////////
	typedef u1 (CALL_TYPE *FunEncodeTag)(u4 u4Tag, u1* pu1Tag);
	
	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			对value length进行编码，并输出为字节流
	// 参数	
	//			u4ValueLen	[IN] value length
	//			pu1ValueLen	[OUT] 编码后的value length.
	// 返回值
	//			编码后Length占用的字节数
	//////////////////////////////////////////////////////////////////////////
	typedef u1 (CALL_TYPE *FunEncodeLength)(u4 u4ValueLen, u1* pu1ValueLen);

	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			初始化TLV
	// 参数
	//			funGetTagAndLen	[IN] TAG and len的解码接口。为NULL时使用标准TLV处理方式
	//			funEncodeTag	[IN] TAG编码解析接口。为NULL时使用标准TLV处理方式
	//			funEncodeLength	[IN] Value length的解码接口。为NULL时使用标准TLV处理方式
	//			phTlv			[OUT] 输出TLV的句柄
	// 返回值
	//			0: 成功。其它: 失败
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvInit(const FunGetTagAndLen funGetTagAndLen, const FunEncodeTag funEncodeTag, const FunEncodeLength funEncodeLength, ESHANDLE* phTlv);

	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			反初始化TLV
	// 参数
	//			hTlv [IN] TLV的句柄
	// 返回值
	//			0: 成功。其它: 失败
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvDeinit(ESHANDLE hTlv);

	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			对tag进行编码
	// 参数
	//			hTlv		[IN] TLV的句柄
	//			u4Tag		[IN] tag
	//			pu1Tag		[OUT] 编码后的tag。编码时会回调，缓冲区的长度由调用者确定。可以为NULL。
	//			pu1TagSize	[IN/OUT] 输入pu1Tag的长度，输出编码后tag占用的字节数。
	// 返回值
	//			0: 成功。其它: 失败 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvEncodeTag(ESHANDLE hTlv, u4 u4Tag, u1* pu1Tag, u1* pu1TagSize);
	
	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			对ValueLen进行编码
	// 参数
	//			hTlv		[IN] TLV的句柄
	//			u4ValueLen	[IN] ValueLentag
	//			pu1ValueLen	[OUT] 编码后的ValueLen。编码时会回调，缓冲区的长度由调用者确定。可以为NULL。
	//			pu1LenSize	[IN/OUT] 输入pu1ValueLen的长度，输出编码后ValueLen占用的字节数。
	// 返回值
	//			0: 成功。其它: 失败 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvEncodeLen(ESHANDLE hTlv, u4 u4ValueLen, u1* pu1ValueLen, u1* pu1LenSize);
	
	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			由指定的TLV数据创建一个TLV节点。不处理嵌套或者兄弟节点
	// 参数
	//			hTlv			[IN] TLV的句柄
	//			pu1Tlv			[IN] TLV数据
	//			u4TlvLen		[IN] TLV数据长度
	//			ppblkTlvTree	[OUT] 非空。返回新创建的TLV节点
	// 返回值
	//			0: 成功。其它: 失败 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvNewOneNode(ESHANDLE hTlv, const u1* pu1Tlv, u4 u4TlvLen, BlkTlvTree** ppblkTlvTree);
	
	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			创建一个TLV节点。不处理嵌套或者兄弟节点
	// 参数
	//			hTlv			[IN] TLV的句柄
	//			u4Tag			[IN] u4Tag
	//			u4ValueLen		[IN] value len
	//			pvValue			[OUT] value内容
	//			ppblkTlvTree	[OUT] 非空。返回新创建的TLV节点
	// 返回值
	//			0: 成功。其它: 失败 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvNewOneNode2(ESHANDLE hTlv, u4 u4Tag, u4 u4ValueLen, const void* pvValue, BlkTlvTree** ppblkTlvTree);
	
	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			释放TLV树内存
	// 参数
	//			ppblkTlvTree	[IN] TLV数的地址
	// 返回值
	//			0: 成功。其它: 失败 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvTreeFree(BlkTlvTree** ppblkTlvTree);
	
	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			解码TLV数据，并转换为TLV树（会处理子节点和兄弟节点）
	// 参数
	//			hTlv			[IN] TLV的句柄
	//			pu1Tlv			[IN] TLV数据
	//			u4TlvLen		[IN] TLV数据长度
	//			ppblkTlvTree	[OUT] 非空。返回新创建的TLV节点
	// 返回值
	//			0: 成功。其它: 失败 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvTreeDeflat(ESHANDLE hTlv, const u1* pu1Tlv, u4 u4TlvLen, BlkTlvTree** ppblkTlvTree);
	
	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			展开TLV数据
	// 参数
	//			hTlv			[IN] TLV的句柄
	//			pblkTlvTree		[IN] TLV树地址
	//			pu1Tlv			[IN] 展开后的TLV数据。可以为NULL
	//			pu4TlvLen		[OUT] 非空。返回展开后的TLV数据占用的内存字节数
	// 返回值
	//			0: 成功。其它: 失败 
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvTreeFlat(ESHANDLE hTlv, const BlkTlvTree* pblkTlvTree, u1* pu1Tlv, u4* pu4TlvLen);
	
	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			添加子节点
	// 参数
	//			hTlv				[IN] TLV的句柄
	//			pblkTlvTreeParent	[IN] 父节点
	//			pblkTlvTreeChild	[IN] 子节点
	// 返回值
	//			0: 成功。其它: 失败 
	// 备注:
	//			[注意]!!! 
	//			1. 父节点直接链接了子节点，子节点已分配的内存会被接管，不需要单独释放
	//			2. 添加成功后，会更新父节点的所有父节点的长度信息
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvTreeAddChild(ESHANDLE hTlv, BlkTlvTree* pblkTlvTreeParent, BlkTlvTree* pblkTlvTreeChild);
	
	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			添加兄弟节点
	// 参数
	//			hTlv				[IN] TLV的句柄
	//			pblkTlvTreeRoot		[IN] 根节点
	//			pblkTlvTreeSibling	[IN] 兄节点
	// 返回值
	//			0: 成功。其它: 失败 
	// 备注:
	//			[注意]!!! 
	//			1. 根节点链接了兄弟节点，兄弟节点已分配的内存会被接管，不需要单独释放
	//			2. 添加成功后，会更新根节点的所有父节点的长度信息
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsTlvTreeAddSibling(ESHANDLE hTlv, BlkTlvTree* pblkTlvTreeRoot, BlkTlvTree* pblkTlvTreeSibling);
	
	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			通过tag查找TLV节点
	// 参数
	//			pblkTlvTree		[IN] TLV节点
	//			u4Tag			[IN] tag
	// 返回值
	//			查找到的TLV节点指针 
	//////////////////////////////////////////////////////////////////////////
	const BlkTlvTree* EsTlvFindViaTag(const BlkTlvTree* pblkTlvTree, u4 u4Tag);
	
	//////////////////////////////////////////////////////////////////////////
	// 功能描述
	//			比较两个TLV树是否相等
	// 参数
	//			pblkTlvTree1	[IN] TLV树1
	//			pblkTlvTree2	[IN] TLV树2 
	// 返回值
	//			ESFALSE: 不相等
	//////////////////////////////////////////////////////////////////////////
	ESBOOL CALL_TYPE EsTlvTreeCompare(IN const BlkTlvTree* pblkTlvTree1, IN const BlkTlvTree* pblkTlvTree2);

#ifdef __cplusplus
};
#endif

#endif	// !define _ESTLV_H_
