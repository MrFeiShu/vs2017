#ifndef _PRODUCT_H_
#define _PRODUCT_H_

// ÿ����Ŀ��Ʒ������벻ͬ
//#define PRODUCT_CODE TEXT("{E4286A55-B434-4344-8392-102A9A69EAB5}")	// �Ŵ���
#define PRODUCT_CODE TEXT("{ca13bbb7-1b84-4a73-a7f3-6ddd434bc197}")     // ��׼��

// ͨ��PRODUCT_CODE��ȡ�û��氲װ·��
int GetProductInstallDir(LPCTSTR lpszProductCode, LPTSTR lpszUserVerDir, int nBufLen);
// ��ȡ��ǰ��Ʒ�İ�װ·��
int GetCurrentProductInstallDir( LPTSTR lpszUserVerDir, int nBufLen);

#endif