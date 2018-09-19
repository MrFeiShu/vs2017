#include <iostream>
using namespace std;
#include <string.h>

// �ο���ַ https://www.cnblogs.com/sevenyuan/p/3154346.html
// ģ�嶨�壺ģ�����ʵ�ִ������û��Ƶ�һ�ֹ��ߣ�������ʵ�����Ͳ��������������Ͷ���Ϊ������ �Ӷ�ʵ���������Ĵ���������ԡ�
// ģ����Է�Ϊ���࣬һ���Ǻ���ģ�棬����һ������ģ�档

/*
����ģ��
template <class type> ret-type func-name(parameter list)
{
   // ����������
}
*/

// template <typename T>
template <class T>
inline T const& Max(T const& a, T const& b)
{
	return a < b ? b : a; 
}

/*
��ģ��
*/
template<typename T1, typename T2> // ������ǰ����Ҫ��ģ���������м�

class myClass {
private:
	T1	I;
	T2	J;
public:
	myClass(T1 a, T2 b);
	void show();
};

template<typename T1, typename T2> // ÿ������ǰ�涼��Ҫ��ģ���������м�
myClass<T1, T2>::myClass(T1 a, T2 b) :I(a), J(b)
{

}

template<typename T1, typename T2> // ÿ������ǰ�涼��Ҫ��ģ���������м�
void myClass<T1, T2>::show()
{
	cout << "I=" << I << ", J=" << J << endl;
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

	cout << "***************************************************************************\n";
	myClass<int, int> class1(3, 5);
	class1.show();

	myClass<int, char> class2(3, 'F');
	class2.show();

	myClass<double, int> class3(3.1415926, 5);
	class3.show();

	return 0;
}