#include <iostream>
using namespace std;
#include "link.h"

extern BlkDevNode*	g_pblkDevHead;

int main(void)
{
	BlkDevData blkDevDataArray[5] = {{1, "fuck benkai 1"}, {2, "fuck benkai 2"}, {3, "fuck benkai 3"} , {4, "fuck benkai 4"}, {5, "fuck benkai 5"}};
	BlkDevNode* pblkDevNode;

	InitDevLink();

	// 插入5个节点
	cout << "insert 5 node\n";
	for ( int i = 0; i < 5; i++ )
	{
		AddDevNode(blkDevDataArray[i].m_u4SlotId, blkDevDataArray[i].m_pszLabel);
	}

	cout << "count:" << GetNodeCount() << endl;

	pblkDevNode = g_pblkDevHead;
	while ( NULL != pblkDevNode )
	{
		cout << "SlotId:" << pblkDevNode->m_blkDevData.m_u4SlotId << ",Label:" << pblkDevNode->m_blkDevData.m_pszLabel << endl;
		pblkDevNode = pblkDevNode->pNext;
	}

	// 删除头结点
	cout << "\ndelete first node\n";
	DeleteNode(1);
	cout << "count:" << GetNodeCount() << endl;
	pblkDevNode = g_pblkDevHead;
	while (NULL != pblkDevNode)
	{
		cout << "SlotId:" << pblkDevNode->m_blkDevData.m_u4SlotId << ",Label:" << pblkDevNode->m_blkDevData.m_pszLabel << endl;
		pblkDevNode = pblkDevNode->pNext;
	}

	// 删除中间节点
	cout << "\ndelete normal node\n";
	DeleteNode(3);
	cout << "count:" << GetNodeCount() << endl;
	pblkDevNode = g_pblkDevHead;
	while (NULL != pblkDevNode)
	{
		cout << "SlotId:" << pblkDevNode->m_blkDevData.m_u4SlotId << ",Label:" << pblkDevNode->m_blkDevData.m_pszLabel << endl;
		pblkDevNode = pblkDevNode->pNext;
	}

	// 删除尾节点
	cout << "\ndelete last node\n";
	DeleteNode(5);
	cout << "count:" << GetNodeCount() << endl;
	pblkDevNode = g_pblkDevHead;
	while (NULL != pblkDevNode)
	{
		cout << "SlotId:" << pblkDevNode->m_blkDevData.m_u4SlotId << ",Label:" << pblkDevNode->m_blkDevData.m_pszLabel << endl;
		pblkDevNode = pblkDevNode->pNext;
	}
}