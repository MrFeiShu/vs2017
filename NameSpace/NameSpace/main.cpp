#include <iostream>
using namespace std;

#include "Name1.h"
#include "Name2.h"
#include "Name3.h"

// using namespace name1;
// using namespace name2;
using namespace name3;

// ��ͬ�ĺ������ƣ����������ռ�����
int main(void)
{
	name1::PrintName();
	name2::PrintName();
	name3::PrintName();

	return 0;
}