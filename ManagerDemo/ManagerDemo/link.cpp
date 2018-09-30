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

// ���ҽڵ�
BlkDevNode* FindDevNode(BlkDevData* pblkDevData)
{
	BOOL		bRet = FALSE;
	BlkDevNode* pblkPos = NULL;

	pblkPos = g_pblkDevHead;
	while (NULL != pblkPos )
	{
		{ // ƥ��Dev
			if (pblkDevData->m_u4SlotId != pblkPos->m_blkDevData.m_u4SlotId) 
			{
				// slotid��ƥ�䣬����һ��
				continue;
			}
			// SlotID��ͬ���Ż��ߵ������
			if (NULL == *pblkDevData->m_pszApp) // �жϲ������App�Ƿ�Ϊ��
			{
				// Ϊ�գ�˵��ֻ��dev����ô�����Ѿ��ҵ���
				bRet = TRUE;
				break;
			}
		}

		{// ƥ��App
			// �������app��Ϊ�գ������Ƚ�App
			if (NULL == *pblkPos->m_blkDevData.m_pszApp) // �жϱȽ����app�Ƿ�Ϊ��
			{
				// Ϊ�գ���ô���϶�����ͬһ��;����һ��
				continue;
			}
			if (0 != wcscmp(pblkDevData->m_pszApp, pblkPos->m_blkDevData.m_pszApp))
			{
				// app��ͬ����ô����ͬһ��;����һ��
				continue;
			}

			if (NULL == *pblkDevData->m_pszCnt) // �жϲ������Cnt�Ƿ�Ϊ��
			{
				// Ϊ�գ�˵��ֻ��App����ô���Ѿ��ҵ��ˡ��˳�
				bRet = TRUE;
				break;
			}
		}

		{// ƥ��Cnt
			// �������Cnt��Ϊ�գ������Ƚ�Cnt
			if (NULL == *pblkPos->m_blkDevData.m_pszCnt) // �жϱȽ����Cnt�Ƿ�Ϊ��
			{
				// Ϊ�գ���ô���϶�����ͬһ��;����һ��
				continue;
			}
			if (0 != wcscmp(pblkDevData->m_pszCnt, pblkPos->m_blkDevData.m_pszCnt))
			{
				// Cnt��ͬ����ô����ͬһ��;����һ��
				continue;
			}
			if ( NULL == *pblkDevData->m_pszCert ) // �жϲ������Cert�Ƿ�Ϊ��
			{
				// Ϊ�գ�˵��ֻ��Cnt����ô���Ѿ��ҵ��ˡ��˳�
				bRet = TRUE;
				break;
			}
		}

		{// ƥ��Cert
			// �������Cert��Ϊ�գ������Ƚ�Cert
			if (NULL == *pblkPos->m_blkDevData.m_pszCert) // �жϱȽ����Cnt�Ƿ�Ϊ��
			{
				// Ϊ�գ���ô���϶�����ͬһ��;����һ��
				continue;
			}
			if (0 != wcscmp(pblkDevData->m_pszCert, pblkPos->m_blkDevData.m_pszCert))
			{
				// Cnt��ͬ����ô����ͬһ��;����һ��
				continue;
			}
			if (NULL == *pblkDevData->m_pszType) // �жϲ������Cert�Ƿ�Ϊ��
			{
				// Ϊ�գ�˵��ֻ��Cnt����ô���Ѿ��ҵ��ˡ��˳�
				bRet = TRUE;
				break;
			}
		}

		{// ƥ��Cert type
			// �������Cert type��Ϊ�գ������Ƚ�Cert type
			if (NULL == *pblkPos->m_blkDevData.m_pszType) // �жϱȽ����Cert type�Ƿ�Ϊ��
			{
				// Ϊ�գ���ô���϶�����ͬһ��;����һ��
				continue;
			}
			if (0 != wcscmp(pblkDevData->m_pszType, pblkPos->m_blkDevData.m_pszType))
			{
				// Cert type��ͬ����ô����ͬһ��;����һ��
				continue;
			}
			// ��������ˣ�˵��Cert type��ͬ
			bRet = TRUE;
			break;
		}

		pblkPos = pblkPos->pNext;
	}

	return bRet?pblkPos:NULL; // TODO ò�����bRet�е����
}

void FreeNode(BlkDevNode* pblkDevNode)
{
	if ( NULL != pblkDevNode->m_blkDevData.m_pu1Cert )
	{
		delete[] pblkDevNode->m_blkDevData.m_pu1Cert; // ���ͷ�֤����ڴ�
		pblkDevNode->m_blkDevData.m_pu1Cert = NULL;
	}
	delete pblkDevNode; // �����ٽڵ�
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

// ɾ���ڵ㣬���ͷ��ڴ�
static BOOL DeleteNode(int u4SlotId)
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
		
		FreeNode(pblkDevNode); // ���ٲ��ͷŽڵ��ڴ�
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