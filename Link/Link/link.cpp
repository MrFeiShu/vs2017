#include <stdio.h>
#include <string.h>
#include "link.h"

BlkDevNode*	g_pblkDevHead;

bool InitDevLink()
{
	g_pblkDevHead = NULL;

	return true;
}

// �ڲ������ڴ棬���ؽڵ��ַ
BlkDevNode* AddDevNode(BlkDevData* pblkDevData)
{
	BlkDevNode*	pblkDev = new BlkDevNode;
	int			u4Count;

// 	pblkDev->m_blkDevData.m_u4SlotId = u4SlotId;
// 	strcpy_s(pblkDev->m_blkDevData.m_pszLabel, MAX_LABEL_LEN, pszDevLabel);
	memcpy(&pblkDev->m_blkDevData, pblkDevData, sizeof(BlkDevData));

	// ����β���ڵ�
	u4Count = GetNodeCount();
	if (0 == u4Count)
	{
		g_pblkDevHead = pblkDev;
		g_pblkDevHead->pNext = NULL;
	}
	else
	{
		BlkDevNode*	pblkDevPos;

		pblkDevPos = g_pblkDevHead;
		while (NULL != pblkDevPos->pNext) // �˴�ֻ��Ҫ�ҵ����һ���ڵ㣬������Ҫ�ж�pNext��
		{
			pblkDevPos = pblkDevPos->pNext;
		}

		// ���½ڵ����β���ڵ㣬�����µ�β����next��NULL
		pblkDevPos->pNext = pblkDev;
		pblkDev->pNext = NULL;
	}

	return pblkDev;
}

// ����SlotID���ҽڵ�
BlkDevNode* FindDevNode(int u4SlotId)
{
	BlkDevNode* pblkPos = NULL;

	pblkPos = g_pblkDevHead;
	while (NULL != pblkPos && u4SlotId != pblkPos->m_blkDevData.m_u4SlotId)
	{
		pblkPos = pblkPos->pNext;
	}

	return pblkPos;
}

// ɾ���ڵ㣬���ͷ��ڴ�
bool DeleteNode(int u4SlotId)
{
	BlkDevNode*	pblkDevNode = g_pblkDevHead;

	BlkDevNode* pblkBefore = NULL; // ������һ���ڵ��ָ�롣
	while (NULL != pblkDevNode && u4SlotId != pblkDevNode->m_blkDevData.m_u4SlotId) // �˴������ж�pNext����Ϊ����ж�pNext���ͻ��Թ����һ���ڵ㡣
	{
		pblkBefore = pblkDevNode;
		pblkDevNode = pblkDevNode->pNext;
	}

	if (NULL != pblkDevNode)
	{
		// �����ͷ��㣬��ô���ڶ����ڵ㸳��ͷ��㣬���ͷ�ͷ�����ڴ�
		if (g_pblkDevHead == pblkDevNode)
		{
			g_pblkDevHead = pblkDevNode->pNext;
		}
		else// �м�ڵ��β�ڵ�Ĵ���һ�¡�
		{
			pblkBefore->pNext = pblkDevNode->pNext;
		}
		delete pblkDevNode;
	}
	else
	{
		return false;
	}

	return true;
}

// ��ȡ�ڵ����
int GetNodeCount()
{
	int u4Count = 0;
	BlkDevNode*	pblkDevNode = g_pblkDevHead;

	while (NULL != pblkDevNode) // ����ʹ��do-while����Ϊ��һ��ͷָ���ǿյģ�pblkDevNode->pNext��ֵΪ����
	{
		u4Count++;
		pblkDevNode = pblkDevNode->pNext;
	}

	return u4Count;
}