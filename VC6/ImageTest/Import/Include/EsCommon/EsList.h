#ifndef _ES_LIST_H_
#define _ES_LIST_H_

#ifdef __cplusplus
extern "C" 
{
#endif

	typedef void*	(CALL_TYPE *FunNewData)(const void* pvData);
	typedef int		(CALL_TYPE *FunFreeData)(void* pvNodeData);
	typedef int		(CALL_TYPE *FunCompareData)(const void* pvNodeData, const void* pvData);
	typedef u4		(CALL_TYPE *FunTravelData)(const void* pvNodeData, const void* pvParam);

	// 三个指针函数可以为空，内部使用默认函数
	u4 CALL_TYPE EsListInit(ESHANDLE* phList, FunNewData funNewData, FunFreeData funFreeData, FunCompareData funCompareData);
	// 默认删除函数为空，也就是不对节点数据做任何处理
	u4 CALL_TYPE EsListRelease(ESHANDLE hList);
	// 设置新增加节点时的回调函数，在EsListAdd函数中被调用
	u4 CALL_TYPE EsListSetFunNew(ESHANDLE hList, FunNewData funNewData);
	// 设置新删除节点时的回调函数，在EsListRelease、EsListDelete函数中被调用
	u4 CALL_TYPE EsListSetFunFree(ESHANDLE hList, FunFreeData funFreeData);
	// 设置新比较节点时的回调函数，在EsListFind、EsListDelete函数中被调用
	u4 CALL_TYPE EsListSetFunCompare(ESHANDLE hList, FunCompareData funCompareData);
	// 默认建立函数是不做任何处理，只将pvNodeData保存在链表中
	u4 CALL_TYPE EsListAdd(ESHANDLE hList, const void* pvNodeData);
	// 默认建立函数是不做任何处理，只将pvNodeData保存在链表的尾部
	u4 CALL_TYPE EsListAddTail(ESHANDLE hList, const void* pvNodeData);
	// 查找相同数据的节点，如果没有比较回调函数，只是简单地比较节点地址
	u4 CALL_TYPE EsListFind(ESHANDLE hList, const void* pvFindData, void** ppvNodeData);
	// 删除数据，如果没有比较回调函数，只是简单地比较节点地址
	u4 CALL_TYPE EsListDelete(ESHANDLE hList, const void* pvFindData);
	// 删除数据，如果回调函数为NULL，采用已经设置好的比较回调函数
	u4 CALL_TYPE EsListDeleteAll(ESHANDLE hList, const void* pvFindData, FunCompareData funCompareData);
	// 生成一个ID值（最高字节保持为00，只生成三个字节的数据），使得这个ID值在整个链表中是唯一的
	u4 CALL_TYPE EsListGenNewId(ESHANDLE hList, u4* pu4Id);
	// 遍历整个链表，遍历过程中调用传入的回调函数，如果回调函数返回失败，则不继续遍历
	u4 CALL_TYPE EsListTravel(ESHANDLE hList, FunTravelData funTravelData, const void* pvParam);
	// 更新一个节点的内容，内部调用删除、新建的回调函数，注意：此函数会改变节点数据的指针
	u4 CALL_TYPE EsListUpdate(ESHANDLE hList, const void* pvUpdateData);
	// 合并两个链表，最终结果存储在hListDst中
	u4 CALL_TYPE EsListMerge(ESHANDLE hListSrc, ESHANDLE hListDst);
	// 查找链表中下一个节点保存的数据，pvDataPrev为NULL表示查找链表头
	u4 CALL_TYPE EsListGetNext(ESHANDLE hList, const void* pvDataPrev, void** ppvDataNext);

#ifdef __cplusplus
};
#endif

#endif