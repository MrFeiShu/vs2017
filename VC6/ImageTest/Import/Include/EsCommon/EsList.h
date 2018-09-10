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

	// ����ָ�뺯������Ϊ�գ��ڲ�ʹ��Ĭ�Ϻ���
	u4 CALL_TYPE EsListInit(ESHANDLE* phList, FunNewData funNewData, FunFreeData funFreeData, FunCompareData funCompareData);
	// Ĭ��ɾ������Ϊ�գ�Ҳ���ǲ��Խڵ��������κδ���
	u4 CALL_TYPE EsListRelease(ESHANDLE hList);
	// ���������ӽڵ�ʱ�Ļص���������EsListAdd�����б�����
	u4 CALL_TYPE EsListSetFunNew(ESHANDLE hList, FunNewData funNewData);
	// ������ɾ���ڵ�ʱ�Ļص���������EsListRelease��EsListDelete�����б�����
	u4 CALL_TYPE EsListSetFunFree(ESHANDLE hList, FunFreeData funFreeData);
	// �����±ȽϽڵ�ʱ�Ļص���������EsListFind��EsListDelete�����б�����
	u4 CALL_TYPE EsListSetFunCompare(ESHANDLE hList, FunCompareData funCompareData);
	// Ĭ�Ͻ��������ǲ����κδ���ֻ��pvNodeData������������
	u4 CALL_TYPE EsListAdd(ESHANDLE hList, const void* pvNodeData);
	// Ĭ�Ͻ��������ǲ����κδ���ֻ��pvNodeData�����������β��
	u4 CALL_TYPE EsListAddTail(ESHANDLE hList, const void* pvNodeData);
	// ������ͬ���ݵĽڵ㣬���û�бȽϻص�������ֻ�Ǽ򵥵رȽϽڵ��ַ
	u4 CALL_TYPE EsListFind(ESHANDLE hList, const void* pvFindData, void** ppvNodeData);
	// ɾ�����ݣ����û�бȽϻص�������ֻ�Ǽ򵥵رȽϽڵ��ַ
	u4 CALL_TYPE EsListDelete(ESHANDLE hList, const void* pvFindData);
	// ɾ�����ݣ�����ص�����ΪNULL�������Ѿ����úõıȽϻص�����
	u4 CALL_TYPE EsListDeleteAll(ESHANDLE hList, const void* pvFindData, FunCompareData funCompareData);
	// ����һ��IDֵ������ֽڱ���Ϊ00��ֻ���������ֽڵ����ݣ���ʹ�����IDֵ��������������Ψһ��
	u4 CALL_TYPE EsListGenNewId(ESHANDLE hList, u4* pu4Id);
	// ���������������������е��ô���Ļص�����������ص���������ʧ�ܣ��򲻼�������
	u4 CALL_TYPE EsListTravel(ESHANDLE hList, FunTravelData funTravelData, const void* pvParam);
	// ����һ���ڵ�����ݣ��ڲ�����ɾ�����½��Ļص�������ע�⣺�˺�����ı�ڵ����ݵ�ָ��
	u4 CALL_TYPE EsListUpdate(ESHANDLE hList, const void* pvUpdateData);
	// �ϲ������������ս���洢��hListDst��
	u4 CALL_TYPE EsListMerge(ESHANDLE hListSrc, ESHANDLE hListDst);
	// ������������һ���ڵ㱣������ݣ�pvDataPrevΪNULL��ʾ��������ͷ
	u4 CALL_TYPE EsListGetNext(ESHANDLE hList, const void* pvDataPrev, void** ppvDataNext);

#ifdef __cplusplus
};
#endif

#endif