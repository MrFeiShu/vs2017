#include <iostream>
using namespace std;
#include <string.h>

/*
����ģ��
template <class type> ret-type func-name(parameter list)
{
   // ����������
}
*/

template <typename T>
inline T const& Max(T const& a, T const& b)
{
	return a < b ? b : a; 
}

/*
template <class type> class class-name {
.
.
.
}
*/
int main(void)
{
	int	i = 38;
	int j = 23;

	cout << "max(i,j):" << Max(i, j) << endl;

	double f1 = 2.34;
	double f2 = 3.43;
	cout << "max(f1,f2):" << Max(f1, f2) << endl;

	return 0;
}