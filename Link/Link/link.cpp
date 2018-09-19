#include <stdio.h>
#include <string.h>
#include "link.h"

BlkDevNode*	g_pblkDevHead;

bool InitDevLink()
{
	g_pblkDevHead = NULL;

	return true;
}

// 内部申请内存，返回节点地址
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

	// 查找尾部节点
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
		while (NULL != pblkDevPos->pNext) // 此处只需要找到最后一个节点，所以需要判断pNext。
		{
			pblkDevPos = pblkDevPos->pNext;
		}

		// 将新节点放入尾部节点，并将新的尾部的next赋NULL
		pblkDevPos->pNext = pblkDev;
		pblkDev->pNext = NULL;
	}

	return pblkDev;
}

// 根据SlotID查找节点
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

// 删除节点，并释放内存
bool DeleteNode(int u4SlotId)
{
	int			u4Count;
	BlkDevNode*	pblkDevNode = g_pblkDevHead;

	u4Count = GetNodeCount();
	// 先判断节点个数
	if (0 == u4Count) // 如果为0，则直接返回？ TODO
	{
		return false;
	}
	// 如果节点个数为1，那么就必须将g_blkDevNodeHead赋NULL
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
	else // 如果是多个，则需要逐个比对查找
	{
		BlkDevNode* pblkBefore = NULL; // 保存上一个节点的指针。
		while (NULL != pblkDevNode && u4SlotId != pblkDevNode->m_blkDevData.m_u4SlotId) // 此处不能判断pNext，因为如果判断pNext，就会略过最后一个节点。
		{
			pblkBefore = pblkDevNode;
			pblkDevNode = pblkDevNode->pNext;
		}

		if (NULL != pblkDevNode)
		{
			// 如果是头结点，那么将第二个节点赋给头结点，并释放头结点的内存
			if ( g_pblkDevHead == pblkDevNode )
			{
				g_pblkDevHead = pblkDevNode->pNext;
				delete pblkDevNode;
			}
			else if ( NULL != pblkDevNode->pNext ) // 如果pNext指针不为空，则说明是中间节点；那么需要将删除节点的下一个节点指针赋给上一个节点的pNext，然后释放内存即可。
			{
				// BlkDevNode* pblkTemp = pblkDevNode;
				pblkBefore->pNext = pblkDevNode->pNext;
				delete pblkDevNode;
			}
			else // 如果上述都不是，则是尾部节点；则需要将上一节点的pNext置为NULL，然后释放内存。
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

// 获取节点个数
int GetNodeCount()
{
	int u4Count = 0;
	BlkDevNode*	pblkDevNode = g_pblkDevHead;

	while (NULL != pblkDevNode) // 不能使用do-while。因为第一次头指针是空的，pblkDevNode->pNext赋值为崩溃
	{
		u4Count++;
		pblkDevNode = pblkDevNode->pNext;
	}

	return u4Count;
}