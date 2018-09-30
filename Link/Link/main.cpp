#define CRTDBG_MAP_ALLOC    
#include <stdlib.h>    
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif 
#endif  // _DEBUG

#include <iostream>
using namespace std;
#include "link.h"

extern BlkDevNode*	g_pblkDevHead;

void PrintMsg(BlkDevData blkDevData)
{
	//cout << "SlotId:" << blkDevData.m_u4SlotId << ",Label:" << blkDevData.m_pszLabel << "xxx: "<< blkDevData.m_pszApp<<"Cnt: "<<blkDevData.m_pszCnt << "Cert:"<<blkDevData.m_pszCert<<"Type: "<<blkDevData.m_pszType << endl;
	wprintf(L"SlotID:%d Label:%s App:%s Cnt:%s Cert:%s\n", blkDevData.m_u4SlotId, blkDevData.m_pszLabel, blkDevData.m_pszApp, blkDevData.m_pszCnt, blkDevData.m_pszCert);
}

void InsertDev(int s4SlotId, BlkDevData* pblkDevData, int s4Count)
{
	cout << "insert dev "<<s4SlotId<<" node\n";
	for (int i = 0; i < s4Count; i++)
	{
		AddDevNode(&pblkDevData[i]);
	}
}

void DeleteDev(int s4SlotId)
{
	cout << "delete dev :" << s4SlotId << endl;
	BlkDevNode* pblkDevNode;
	pblkDevNode = FindDevNode(s4SlotId);
	while (NULL != pblkDevNode)
	{
		if (false == DeleteNode(pblkDevNode->m_blkDevData.m_u4SlotId))
		{
			break;
		}
		pblkDevNode = FindDevNode(s4SlotId);
	}
}

void EnumRecord()
{
	BlkDevNode*	pblkDevNode;

	cout << "Enum Record, count:" << GetNodeCount() << endl;

	pblkDevNode = g_pblkDevHead;
	while (NULL != pblkDevNode)
	{
		PrintMsg(pblkDevNode->m_blkDevData);
		pblkDevNode = pblkDevNode->pNext;
	}

	cout << "\n\n" << endl;
}

int main(void)
{
	BlkDevData blkDev1[18] = { 
			{1, L"fuck benkai 1", L"App1", L"Cnt1", L"cert1", L"exch"},
			{1, L"fuck benkai 1", L"App1", L"Cnt1", L"cert2", L"sign"},
			{1, L"fuck benkai 1", L"App1", L"Cnt2", L"cert1", L"exch"},
			{1, L"fuck benkai 1", L"App1", L"Cnt2", L"cert2", L"sign"},
			{1, L"fuck benkai 1", L"App1", L"Cnt3", L"cert1", L"exch"},
			{1, L"fuck benkai 1", L"App1", L"Cnt3", L"cert2", L"sign"},
			{1, L"fuck benkai 1", L"App2", L"Cnt1", L"cert1", L"exch"},
			{1, L"fuck benkai 1", L"App2", L"Cnt1", L"cert2", L"sign"},
			{1, L"fuck benkai 1", L"App2", L"Cnt2", L"cert1", L"exch"},
			{1, L"fuck benkai 1", L"App2", L"Cnt2", L"cert2", L"sign"},
			{1, L"fuck benkai 1", L"App2", L"Cnt3", L"cert1", L"exch"},
			{1, L"fuck benkai 1", L"App2", L"Cnt3", L"cert2", L"sign"},
			{1, L"fuck benkai 1", L"App3", L"Cnt1", L"cert1", L"exch"},
			{1, L"fuck benkai 1", L"App3", L"Cnt1", L"cert2", L"sign"},
			{1, L"fuck benkai 1", L"App3", L"Cnt2", L"cert1", L"exch"},
			{1, L"fuck benkai 1", L"App3", L"Cnt2", L"cert2", L"sign"},
			{1, L"fuck benkai 1", L"App3", L"Cnt3", L"cert1", L"exch"},
			{1, L"fuck benkai 1", L"App3", L"Cnt3", L"cert2", L"sign"}
	};

	BlkDevData blkDev2[18] = {
			{2, L"fuck benkai 2", L"App1", L"Cnt1", L"cert1", L"exch"},
			{2, L"fuck benkai 2", L"App1", L"Cnt1", L"cert2", L"sign"},
			{2, L"fuck benkai 2", L"App1", L"Cnt2", L"cert1", L"exch"},
			{2, L"fuck benkai 2", L"App1", L"Cnt2", L"cert2", L"sign"},
			{2, L"fuck benkai 2", L"App1", L"Cnt3", L"cert1", L"exch"},
			{2, L"fuck benkai 2", L"App1", L"Cnt3", L"cert2", L"sign"},
			{2, L"fuck benkai 2", L"App2", L"Cnt1", L"cert1", L"exch"},
			{2, L"fuck benkai 2", L"App2", L"Cnt1", L"cert2", L"sign"},
			{2, L"fuck benkai 2", L"App2", L"Cnt2", L"cert1", L"exch"},
			{2, L"fuck benkai 2", L"App2", L"Cnt2", L"cert2", L"sign"},
			{2, L"fuck benkai 2", L"App2", L"Cnt3", L"cert1", L"exch"},
			{2, L"fuck benkai 2", L"App2", L"Cnt3", L"cert2", L"sign"},
			{2, L"fuck benkai 2", L"App3", L"Cnt1", L"cert1", L"exch"},
			{2, L"fuck benkai 2", L"App3", L"Cnt1", L"cert2", L"sign"},
			{2, L"fuck benkai 2", L"App3", L"Cnt2", L"cert1", L"exch"},
			{2, L"fuck benkai 2", L"App3", L"Cnt2", L"cert2", L"sign"},
			{2, L"fuck benkai 2", L"App3", L"Cnt3", L"cert1", L"exch"},
			{2, L"fuck benkai 2", L"App3", L"Cnt3", L"cert2", L"sign"}
	};

	BlkDevData blkDev3[18] = {
			{3, L"fuck benkai 3", L"App1", L"Cnt1", L"cert1", L"exch"},
			{3, L"fuck benkai 3", L"App1", L"Cnt1", L"cert2", L"sign"},
			{3, L"fuck benkai 3", L"App1", L"Cnt2", L"cert1", L"exch"},
			{3, L"fuck benkai 3", L"App1", L"Cnt2", L"cert2", L"sign"},
			{3, L"fuck benkai 3", L"App1", L"Cnt3", L"cert1", L"exch"},
			{3, L"fuck benkai 3", L"App1", L"Cnt3", L"cert2", L"sign"},
			{3, L"fuck benkai 3", L"App2", L"Cnt1", L"cert1", L"exch"},
			{3, L"fuck benkai 3", L"App2", L"Cnt1", L"cert2", L"sign"},
			{3, L"fuck benkai 3", L"App2", L"Cnt2", L"cert1", L"exch"},
			{3, L"fuck benkai 3", L"App2", L"Cnt2", L"cert2", L"sign"},
			{3, L"fuck benkai 3", L"App2", L"Cnt3", L"cert1", L"exch"},
			{3, L"fuck benkai 3", L"App2", L"Cnt3", L"cert2", L"sign"},
			{3, L"fuck benkai 3", L"App3", L"Cnt1", L"cert1", L"exch"},
			{3, L"fuck benkai 3", L"App3", L"Cnt1", L"cert2", L"sign"},
			{3, L"fuck benkai 3", L"App3", L"Cnt2", L"cert1", L"exch"},
			{3, L"fuck benkai 3", L"App3", L"Cnt2", L"cert2", L"sign"},
			{3, L"fuck benkai 3", L"App3", L"Cnt3", L"cert1", L"exch"},
			{3, L"fuck benkai 3", L"App3", L"Cnt3", L"cert2", L"sign"}
};

	BlkDevData blkDev4[18] = {
		{4, L"fuck benkai 4", L"App1", L"Cnt1", L"cert1", L"exch"},
		{4, L"fuck benkai 4", L"App1", L"Cnt1", L"cert2", L"sign"},
		{4, L"fuck benkai 4", L"App1", L"Cnt2", L"cert1", L"exch"},
		{4, L"fuck benkai 4", L"App1", L"Cnt2", L"cert2", L"sign"},
		{4, L"fuck benkai 4", L"App1", L"Cnt3", L"cert1", L"exch"},
		{4, L"fuck benkai 4", L"App1", L"Cnt3", L"cert2", L"sign"},
		{4, L"fuck benkai 4", L"App2", L"Cnt1", L"cert1", L"exch"},
		{4, L"fuck benkai 4", L"App2", L"Cnt1", L"cert2", L"sign"},
		{4, L"fuck benkai 4", L"App2", L"Cnt2", L"cert1", L"exch"},
		{4, L"fuck benkai 4", L"App2", L"Cnt2", L"cert2", L"sign"},
		{4, L"fuck benkai 4", L"App2", L"Cnt3", L"cert1", L"exch"},
		{4, L"fuck benkai 4", L"App2", L"Cnt3", L"cert2", L"sign"},
		{4, L"fuck benkai 4", L"App3", L"Cnt1", L"cert1", L"exch"},
		{4, L"fuck benkai 4", L"App3", L"Cnt1", L"cert2", L"sign"},
		{4, L"fuck benkai 4", L"App3", L"Cnt2", L"cert1", L"exch"},
		{4, L"fuck benkai 4", L"App3", L"Cnt2", L"cert2", L"sign"},
		{4, L"fuck benkai 4", L"App3", L"Cnt3", L"cert1", L"exch"},
		{4, L"fuck benkai 4", L"App3", L"Cnt3", L"cert2", L"sign"}
	};

	BlkDevData blkDev5[18] = {
		{5, L"fuck benkai 5", L"App1", L"Cnt1", L"cert1", L"exch"},
		{5, L"fuck benkai 5", L"App1", L"Cnt1", L"cert2", L"sign"},
		{5, L"fuck benkai 5", L"App1", L"Cnt2", L"cert1", L"exch"},
		{5, L"fuck benkai 5", L"App1", L"Cnt2", L"cert2", L"sign"},
		{5, L"fuck benkai 5", L"App1", L"Cnt3", L"cert1", L"exch"},
		{5, L"fuck benkai 5", L"App1", L"Cnt3", L"cert2", L"sign"},
		{5, L"fuck benkai 5", L"App2", L"Cnt1", L"cert1", L"exch"},
		{5, L"fuck benkai 5", L"App2", L"Cnt1", L"cert2", L"sign"},
		{5, L"fuck benkai 5", L"App2", L"Cnt2", L"cert1", L"exch"},
		{5, L"fuck benkai 5", L"App2", L"Cnt2", L"cert2", L"sign"},
		{5, L"fuck benkai 5", L"App2", L"Cnt3", L"cert1", L"exch"},
		{5, L"fuck benkai 5", L"App2", L"Cnt3", L"cert2", L"sign"},
		{5, L"fuck benkai 5", L"App3", L"Cnt1", L"cert1", L"exch"},
		{5, L"fuck benkai 5", L"App3", L"Cnt1", L"cert2", L"sign"},
		{5, L"fuck benkai 5", L"App3", L"Cnt2", L"cert1", L"exch"},
		{5, L"fuck benkai 5", L"App3", L"Cnt2", L"cert2", L"sign"},
		{5, L"fuck benkai 5", L"App3", L"Cnt3", L"cert1", L"exch"},
		{5, L"fuck benkai 5", L"App3", L"Cnt3", L"cert2", L"sign"}
	};

	InitDevLink();

	int u4Count = 10000;

//	for ( int i = 0; i<u4Count; i++ )
	{
		// 插入dev1
		InsertDev(1, blkDev1, _countof(blkDev2));
		EnumRecord();

		// 插入dev2
		InsertDev(2, blkDev2, _countof(blkDev2));
		EnumRecord();

		// 删除设备1
		DeleteDev(1);
		EnumRecord();

		// 插入dev3
		InsertDev(3, blkDev3, _countof(blkDev3));
		EnumRecord();

		// 删除设备2
		DeleteDev(2);
		EnumRecord();

		// 插入dev4
		InsertDev(4, blkDev4, _countof(blkDev4));
		EnumRecord();

		// 插入dev5
		InsertDev(5, blkDev5, _countof(blkDev5));
		EnumRecord();

		// 删除设备4
		DeleteDev(4);
		EnumRecord();

		// 删除设备5
		DeleteDev(5);
		EnumRecord();

		// 删除设备5
		DeleteDev(3);
		EnumRecord();
	}

	_CrtDumpMemoryLeaks();
}