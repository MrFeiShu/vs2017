#include <iostream>
using namespace std;

//#define _TEST_DEFAULT_COPY_CONSTRUCT_
//#define _TEST_DEEP_COPY_CONSTRUCT_
#define _TEST_DISABLE_DEFAULT_COPY_CONSTRUCT_

class Demo
{
public:

	// 如果使用默认构造函数，那么静态成员变量的count的值会变成-1
	// 因为默认构造函数不会处理静态成员变量，所以需要重载拷贝构造函数来处理静态成员变量
#ifdef _TEST_DEFAULT_COPY_CONSTRUCT_
	Demo()
	{
		cout << "Construct\n";
		count++;
	}

	Demo(const Demo& demo)
	{
		cout << "copy construct\n";
		count++;
	}

	~Demo()
	{
		cout << "Destruct\n";
		count--;
	}

	static int GetCount()
	{
		return count;
	}
#endif
	// 所谓浅拷贝，指的是在对象复制时，只对对象中的数据成员进行简单的赋值，默认拷贝构造函数执行的也是浅拷贝
	// 大多情况下“浅拷贝”已经能很好地工作了，但是一旦对象存在了动态成员，那么浅拷贝就会出问题，比如下面情况就会崩溃
	// 所以需要深拷贝
#ifdef _TEST_DEEP_COPY_CONSTRUCT_
	Demo()
	{
		psz = new char[100];
		cout << "Construct\n";
	}

	Demo(const Demo& demo)
	{
		cout << "copy construct\n";
		this->psz = new char[100];
		memcpy(this->psz, demo.psz, 100);
	}

	~Demo()
	{
		cout << "destruct\n";
		delete[] psz;

	}
#endif


private:
	static	int count;
	char*	psz;

#ifdef _TEST_DISABLE_DEFAULT_COPY_CONSTRUCT_
public:
	Demo()
	{
		cout << "construct\n";
	}
private:
	Demo(const Demo& demo);
#endif
};

int Demo::count = 0;

int main(void)
{
#ifdef _TEST_DEFAULT_COPY_CONSTRUCT_
	// 把这两个对象放在大括号内，这样才回调用析构函数
	{
		Demo	d1;
		cout << "count:" << Demo::GetCount() << endl;
		Demo	d2(d1);
	}
	cout << "count:" << Demo::GetCount() << endl;
#endif

#ifdef _TEST_DEEP_COPY_CONSTRUCT_
	{
		Demo	d1;
		Demo	d2 = d1;
	}
#endif
#ifdef _TEST_DISABLE_DEFAULT_COPY_CONSTRUCT_
	{
		Demo	d1;
		Demo	d2 = d1;
	}
#endif
	return 0;
}

/*
小结：
	拷贝有两种：深拷贝，浅拷贝。
	  当出现类的等号赋值时，会调用拷贝函数，在未定义显示拷贝构造函数的情况下，系统会调用默认的拷贝函数——即浅拷贝，它能够完成成员的一一复制。当数据成员中没有指针时，浅拷贝是可行的。但当数据成员中有指针时，如果采用简单的浅拷贝，则两类中的两个指针将指向同一个地址，当对象快结束时，会调用两次析构函数，而导致指针悬挂现象。所以，这时，必须采用深拷贝。

	 深拷贝与浅拷贝的区别就在于深拷贝会在堆内存中另外申请空间来储存数据，从而也就解决了指针悬挂的问题。简而言之，当数据成员中有指针时，必须要用深拷贝。


四、拷贝构造函数的几个细节
   1.为什么拷贝构造函数必须是引用传递，不能是值传递？
	 简单的回答是为了防止递归引用。
		  具体一些可以这么讲：
			  当 一个对象需要以值方式传递时，编译器会生成代码调用它的拷贝构造函数以生成一个复本。如果类A的拷贝构造函数是以值方式传递一个类A对象作为参数的话，当 需要调用类A的拷贝构造函数时，需要以值方式传进一个A的对象作为实参； 而以值方式传递需要调用类A的拷贝构造函数；结果就是调用类A的拷贝构造函数导 致又一次调用类A的拷贝构造函数，这就是一个无限递归。

   2. 拷贝构造函数的作用。
		   作用就是用来复制对象的，在使用这个对象的实例来初始化这个对象的一个新的实例。

	 3.参数传递过程到底发生了什么？
	  将地址传递和值传递统一起来，归根结底还是传递的是"值"(地址也是值，只不过通过它可以找到另一个值)！
	  i)值传递:
		 对于内置数据类型的传递时，直接赋值拷贝给形参(注意形参是函数内局部变量)；
		 对于类类型的传递时，需要首先调用该类的拷贝构造函数来初始化形参(局部对象)；如void foo(class_type obj_local){}, 如果调用foo(obj);  首先class_type obj_local(obj) ,这样就定义了局部变量obj_local供函数内部使用
	 ii)引用传递:
		无论对内置类型还是类类型，传递引用或指针最终都是传递的地址值！而地址总是指针类型(属于简单类型), 显然参数传递时，按简单类型的赋值拷贝，而不会有拷贝构造函数的调用(对于类类型).

   4. 在类中有指针数据成员时，拷贝构造函数的使用？
		如果不显式声明拷贝构造函数的时候，编译器也会生成一个默认的拷贝构造函数，而且在一般的情况下运行的也很好。但是在遇到类有指针数据成员时就出现问题 了：因为默认的拷贝构造函数是按成员拷贝构造，这导致了两个不同的指针(如ptr1=ptr2)指向了相同的内存。当一个实例销毁时，调用析构函数 free(ptr1)释放了这段内存，那么剩下的一个实例的指针ptr2就无效了，在被销毁的时候free(ptr2)就会出现错误了, 这相当于重复释放一块内存两次。这种情况必须显式声明并实现自己的拷贝构造函数，来为新的实例的指针分配新的内存。

问题1和2回答了为什么拷贝构造函数使用值传递会产生无限递归调用的问题；
问题3回答了回答了在类中有指针数据成员时，拷贝构造函数使用值传递等于白显式定义了拷贝构造函数，因为默认的拷贝构造函数就是这么干的。

  5. 拷贝构造函数里能调用private成员变量吗?
解答：这个问题是在网上见的，当时一下子有点晕。其时从名子我们就知道拷贝构造函数其时就是一个特殊的构造函数，操作的还是自己类的成员变量，所以不受private的限制。

 6. 以下函数哪个是拷贝构造函数,为什么?

X::X(const X&);   //拷贝构造函数
X::X(X);
X::X(X&, int a=1);   //拷贝构造函数
X::X(X&, int a=1, int b=2);  //拷贝构造函数
   解答：对于一个类X, 如果一个构造函数的第一个参数是下列之一:
   a) X&
   b) const X&
   c) volatile X&
   d) const volatile X&
   且没有其他参数或其他参数都有默认值,那么这个函数是拷贝构造函数.

  7. 一个类中可以存在多于一个的拷贝构造函数吗?
   解答：类中可以存在超过一个拷贝构造函数。

class X {
public:
  X(const X&); // const 的拷贝构造
  X(X&); // 非const的拷贝构造
};

  注意,如果一个类中只存在一个参数为 X& 的拷贝构造函数,那么就不能使用const X或volatile X的对象实行拷贝初始化.
  如果一个类中没有定义拷贝构造函数,那么编译器会自动产生一个默认的拷贝构造函数。
  这个默认的参数可能为 X::X(const X&)或 X::X(X&),由编译器根据上下文决定选择哪一个。


五、C++构造函数以及析构函数的若干面试问题

 Q1：构造函数能否重载，析构函数能否重载，为什么？
 A1：构造函数可以，析构函数不可以。

  Q2：析构函数为什么一般情况下要声明为虚函数？
  A2：虚函数是实现多态的基础，当我们通过基类的指针是析构子类对象时候，如果不定义成虚函数，那只调用基类的析构函数，子类的析构函数将不会被调用。如       果定义为虚函数，则子类父类的析构函数都会被调用。
  Q3：什么情况下必须定义拷贝构造函数？
  A3：当类的对象用于函数值传递时（值参数，返回类对象），拷贝构造函数会被调用。如果对象复制并非简单的值拷贝，那就必须定义拷贝构造函数。例如大的堆       栈数据拷贝。如果定义了拷贝构造函数，那也必须重载赋值操作符。

参考博客：
 http://blog.csdn.net/lwbeyond/article/details/6202256
http://jaden.blog.51cto.com/1549175/324480
http://blog.chinaunix.net/uid-28662931-id-3496322.html
*/