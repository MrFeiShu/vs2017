#include <stdio.h>
#include <string.h>
#include <time.h>

__int64 g_s8Count = 0;

void hano(int n, char* pszA, char* pszB, char* pszC)
{
	if (1 == n)
	{
//		printf("%s --> %s\n", pszA, pszC);
		g_s8Count++;
		return;
	}

	if (2 == n)
	{
//		printf("%s --> %s\n", pszA, pszB);
//		printf("%s --> %s\n", pszA, pszC);
//		printf("%s --> %s\n", pszB, pszC);
		g_s8Count += 3;
		return;
	}

	hano(n - 1, pszA, pszC, pszB);
//	printf("%s --> %s\n", pszA, pszC);
	g_s8Count++;
	hano(n - 1, pszB, pszA, pszC);
}

void main()
{
	double startTime, endTime, useTime;
	int s4N = 50;
	char pszA[2] = { 0 };
	char pszB[2] = { 0 };
	char pszC[2] = { 0 };

	strcpy_s(pszA, 2, "A");
	strcpy_s(pszB, 2, "B");
	strcpy_s(pszC, 2, "C");
	startTime = time(NULL);
//	for (int i = 1; i < 64; i++)
	{
		hano(28, pszA, pszB, pszC);
		endTime = time(NULL);
		useTime = difftime(endTime, startTime);
		printf("hello world, size:%d, num:%d, count:%ld, useTime:%ld\n", sizeof(g_s8Count), 28, g_s8Count, useTime);
	}
	getchar();

	return;
}