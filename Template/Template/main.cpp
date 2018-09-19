#include <iostream>
using namespace std;
#include <string.h>

// 参考网址 https://www.cnblogs.com/sevenyuan/p/3154346.html
// 模板定义：模板就是实现代码重用机制的一种工具，它可以实现类型参数化，即把类型定义为参数， 从而实现了真正的代码可重用性。
// 模版可以分为两类，一个是函数模版，另外一个是类模版。

/*
函数模板
template <class type> ret-type func-name(parameter list)
{
   // 函数的主体
}
*/

// template <typename T>
template <class T>
inline T const& Max(T const& a, T const& b)
{
	return a < b ? b : a; 
}

/*
类模板
*/
template<typename T1, typename T2> // 类声明前面需要有模板声明，切记

class myClass {
private:
	T1	I;
	T2	J;
public:
	myClass(T1 a, T2 b);
	void show();
};

template<typename T1, typename T2> // 每个函数前面都需要有模板声明，切记
myClass<T1, T2>::myClass(T1 a, T2 b) :I(a), J(b)
{

}

template<typename T1, typename T2> // 每个函数前面都需要有模板声明，切记
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