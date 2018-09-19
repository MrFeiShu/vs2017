#ifndef _LINK_H_
#define _LINK_H_

#define MAX_LABEL_LEN		0x20

typedef struct BLKDEVDATATAG
{
	int		m_u4SlotId;
	char	m_pszLabel[MAX_LABEL_LEN];
}BlkDevData;

typedef struct BLKDEVNODETAG
{
	BlkDevData	m_blkDevData;
	struct BLKDEVNODETAG*	pNext; // 注意：这里需要加上struct关键字
}BlkDevNode;

bool InitDevLink();
BlkDevNode* AddDevNode(int u4SlotId, char* pszDevName);
BlkDevNode* FindDevNode(int u4SlotId);
bool DeleteNode(int u4SlotId);
int GetNodeCount();

#endif