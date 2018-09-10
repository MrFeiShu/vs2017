#ifndef _PRODUCT_H_
#define _PRODUCT_H_

// 每个项目产品代码必须不同
//#define PRODUCT_CODE TEXT("{E4286A55-B434-4344-8392-102A9A69EAB5}")	// 信达汇格
#define PRODUCT_CODE TEXT("{ca13bbb7-1b84-4a73-a7f3-6ddd434bc197}")     // 标准版

// 通过PRODUCT_CODE获取用户版安装路径
int GetProductInstallDir(LPCTSTR lpszProductCode, LPTSTR lpszUserVerDir, int nBufLen);
// 获取当前产品的安装路径
int GetCurrentProductInstallDir( LPTSTR lpszUserVerDir, int nBufLen);

#endif