#include <stdio.h>

int g_s4Count = 0;

void fun()
{
	printf("%d\n", g_s4Count);
	g_s4Count++;
	fun();
}

void main()
{
	fun();
}