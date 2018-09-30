#include "stdafx.h"
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
BlkDevNode* AddDevNode(BlkDevData* pblkDevData)
{
	BlkDevNode*	pblkDev = new BlkDevNode;
	int			u4Count;

// 	pblkDev->m_blkDevData.m_u4SlotId = u4SlotId;
// 	strcpy_s(pblkDev->m_blkDevData.m_pszLabel, MAX_LABEL_LEN, pszDevLabel);
	memcpy(&pblkDev->m_blkDevData, pblkDevData, sizeof(BlkDevData));

	// 查找尾部节点
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

// 查找节点
BlkDevNode* FindDevNode(BlkDevData* pblkDevData)
{
	BOOL		bRet = FALSE;
	BlkDevNode* pblkPos = NULL;

	pblkPos = g_pblkDevHead;
	while (NULL != pblkPos )
	{
		{ // 匹配Dev
			if (pblkDevData->m_u4SlotId != pblkPos->m_blkDevData.m_u4SlotId) 
			{
				// slotid不匹配，找下一个
				continue;
			}
			// SlotID相同，才会走到这儿来
			if (NULL == *pblkDevData->m_pszApp) // 判断查找项的App是否为空
			{
				// 为空，说明只找dev。那么，你已经找到了
				bRet = TRUE;
				break;
			}
		}

		{// 匹配App
			// 查找项的app不为空，继续比较App
			if (NULL == *pblkPos->m_blkDevData.m_pszApp) // 判断比较项的app是否为空
			{
				// 为空，那么，肯定不是同一个;找下一个
				continue;
			}
			if (0 != wcscmp(pblkDevData->m_pszApp, pblkPos->m_blkDevData.m_pszApp))
			{
				// app不同，那么不是同一个;找下一个
				continue;
			}

			if (NULL == *pblkDevData->m_pszCnt) // 判断查找项的Cnt是否为空
			{
				// 为空，说明只找App。那么，已经找到了。退出
				bRet = TRUE;
				break;
			}
		}

		{// 匹配Cnt
			// 查找项的Cnt不为空，继续比较Cnt
			if (NULL == *pblkPos->m_blkDevData.m_pszCnt) // 判断比较项的Cnt是否为空
			{
				// 为空，那么，肯定不是同一个;找下一个
				continue;
			}
			if (0 != wcscmp(pblkDevData->m_pszCnt, pblkPos->m_blkDevData.m_pszCnt))
			{
				// Cnt不同，那么不是同一个;找下一个
				continue;
			}
			if ( NULL == *pblkDevData->m_pszCert ) // 判断查找项的Cert是否为空
			{
				// 为空，说明只找Cnt。那么，已经找到了。退出
				bRet = TRUE;
				break;
			}
		}

		{// 匹配Cert
			// 查找项的Cert不为空，继续比较Cert
			if (NULL == *pblkPos->m_blkDevData.m_pszCert) // 判断比较项的Cnt是否为空
			{
				// 为空，那么，肯定不是同一个;找下一个
				continue;
			}
			if (0 != wcscmp(pblkDevData->m_pszCert, pblkPos->m_blkDevData.m_pszCert))
			{
				// Cnt不同，那么不是同一个;找下一个
				continue;
			}
			if (NULL == *pblkDevData->m_pszType) // 判断查找项的Cert是否为空
			{
				// 为空，说明只找Cnt。那么，已经找到了。退出
				bRet = TRUE;
				break;
			}
		}

		{// 匹配Cert type
			// 查找项的Cert type不为空，继续比较Cert type
			if (NULL == *pblkPos->m_blkDevData.m_pszType) // 判断比较项的Cert type是否为空
			{
				// 为空，那么，肯定不是同一个;找下一个
				continue;
			}
			if (0 != wcscmp(pblkDevData->m_pszType, pblkPos->m_blkDevData.m_pszType))
			{
				// Cert type不同，那么不是同一个;找下一个
				continue;
			}
			// 都到这儿了，说明Cert type相同
			bRet = TRUE;
			break;
		}

		pblkPos = pblkPos->pNext;
	}

	return bRet?pblkPos:NULL; // TODO 貌似这个bRet有点多余
}

void FreeNode(BlkDevNode* pblkDevNode)
{
	if ( NULL != pblkDevNode->m_blkDevData.m_pu1Cert )
	{
		delete[] pblkDevNode->m_blkDevData.m_pu1Cert; // 先释放证书的内存
		pblkDevNode->m_blkDevData.m_pu1Cert = NULL;
	}
	delete pblkDevNode; // 在销毁节点
	pblkDevNode = NULL;
}

BOOL DeleteDev(int s4SlotId)
{
	BlkDevNode* pblkDevNode;
	BlkDevData	blkDevData = {0};

	blkDevData.m_u4SlotId = s4SlotId;
	pblkDevNode = FindDevNode(&blkDevData);
	while (NULL != pblkDevNode)
	{
		if (false == DeleteNode(pblkDevNode->m_blkDevData.m_u4SlotId))
		{
			break;
		}
		pblkDevNode = FindDevNode(&blkDevData);
	}

	return TRUE;
}

// 删除节点，并释放内存
static BOOL DeleteNode(int u4SlotId)
{
	BlkDevNode*	pblkDevNode = g_pblkDevHead;

	BlkDevNode* pblkBefore = NULL; // 保存上一个节点的指针。
	while (NULL != pblkDevNode && u4SlotId != pblkDevNode->m_blkDevData.m_u4SlotId) // 此处不能判断pNext，因为如果判断pNext，就会略过最后一个节点。
	{
		pblkBefore = pblkDevNode;
		pblkDevNode = pblkDevNode->pNext;
	}

	if (NULL != pblkDevNode)
	{
		// 如果是头结点，那么将第二个节点赋给头结点，并释放头结点的内存
		if (g_pblkDevHead == pblkDevNode)
		{
			g_pblkDevHead = pblkDevNode->pNext;
		}
		else// 中间节点和尾节点的处理一致。
		{
			pblkBefore->pNext = pblkDevNode->pNext;
		}
		
		FreeNode(pblkDevNode); // 销毁并释放节点内存
	}
	else
	{
		return false;
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