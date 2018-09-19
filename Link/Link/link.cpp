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
BlkDevNode* AddDevNode(int u4SlotId, char* pszDevLabel)
{
	BlkDevNode*	pblkDev = new BlkDevNode;
	int			u4Count;

	if ( 0 == u4SlotId || NULL == pszDevLabel )
	{
		return NULL;
	}
	pblkDev->m_blkDevData.m_u4SlotId = u4SlotId;
	strcpy_s(pblkDev->m_blkDevData.m_pszLabel, MAX_LABEL_LEN, pszDevLabel);

	// ����β���ڵ�
	u4Count = GetNodeCount();
	if ( 0 == u4Count )
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
	while ( NULL != pblkPos && u4SlotId != pblkPos->m_blkDevData.m_u4SlotId )
	{
		pblkPos = pblkPos->pNext;
	}

	return pblkPos;
}

// ɾ���ڵ㣬���ͷ��ڴ�
bool DeleteNode(int u4SlotId)
{
	int			u4Count;
	BlkDevNode*	pblkDevNode = g_pblkDevHead;

	u4Count = GetNodeCount();
	// ���жϽڵ����
	if (0 == u4Count) // ���Ϊ0����ֱ�ӷ��أ� TODO
	{
		return false;
	}
	// ����ڵ����Ϊ1����ô�ͱ��뽫g_blkDevNodeHead��NULL
	else if (1 == u4Count)
	{
		if ( g_pblkDevHead == pblkDevNode )
		{
			delete g_pblkDevHead;
			g_pblkDevHead = NULL;
		} 
		else
		{
			return false;
		}
	}
	else // ����Ƕ��������Ҫ����ȶԲ���
	{
		BlkDevNode* pblkBefore = NULL; // ������һ���ڵ��ָ�롣
		while (NULL != pblkDevNode && u4SlotId != pblkDevNode->m_blkDevData.m_u4SlotId) // �˴������ж�pNext����Ϊ����ж�pNext���ͻ��Թ����һ���ڵ㡣
		{
			pblkBefore = pblkDevNode;
			pblkDevNode = pblkDevNode->pNext;
		}

		if (NULL != pblkDevNode)
		{
			// �����ͷ��㣬��ô���ڶ����ڵ㸳��ͷ��㣬���ͷ�ͷ�����ڴ�
			if ( g_pblkDevHead == pblkDevNode )
			{
				g_pblkDevHead = pblkDevNode->pNext;
				delete pblkDevNode;
			}
			else if ( NULL != pblkDevNode->pNext ) // ���pNextָ�벻Ϊ�գ���˵�����м�ڵ㣻��ô��Ҫ��ɾ���ڵ����һ���ڵ�ָ�븳����һ���ڵ��pNext��Ȼ���ͷ��ڴ漴�ɡ�
			{
				// BlkDevNode* pblkTemp = pblkDevNode;
				pblkBefore->pNext = pblkDevNode->pNext;
				delete pblkDevNode;
			}
			else // ������������ǣ�����β���ڵ㣻����Ҫ����һ�ڵ��pNext��ΪNULL��Ȼ���ͷ��ڴ档
			{
				// BlkDevNode* pblkTemp = pblkDevNode;
				pblkBefore->pNext = NULL;
				delete pblkDevNode;
			}
		}
		else
		{
			return false;
		}
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