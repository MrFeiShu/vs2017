#ifndef _LINK_H_
#define _LINK_H_

#define MAX_LABEL_LEN		0x40

typedef struct BLKDEVDATATAG
{
	int		m_u4SlotId;
	wchar_t	m_pszLabel[MAX_LABEL_LEN];
	wchar_t	m_pszApp[32];
	wchar_t	m_pszCnt[64];
	wchar_t	m_pszCert[64];
	wchar_t	m_pszType[10];
	unsigned char* m_pu1Cert;
}BlkDevData;

typedef struct BLKDEVNODETAG
{
	BlkDevData	m_blkDevData;
	struct BLKDEVNODETAG*	pNext; // 注意：这里需要加上struct关键字
}BlkDevNode;

bool InitDevLink();
BlkDevNode* AddDevNode(BlkDevData* pblkDevData);
BlkDevNode* FindDevNode(BlkDevData* pblkDevData);
BOOL DeleteDev(int s4SlotId);
static BOOL DeleteNode(int u4SlotId);
int GetNodeCount();

#endif
