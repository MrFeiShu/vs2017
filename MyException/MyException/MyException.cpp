#include <iostream>
#include <exception>
using namespace std;

class MyException
{
public:
	MyException(const char* msg) :m_msg(msg)
	{
		cout << "MyException constructor\n";
	}

	MyException(const MyException & other) :m_msg(other.m_msg)
	{
		cout << "MyException Copy Constructor";
	}
	virtual ~MyException()
	{
		cout << "MyException Destructor\n";
	}

	const char* what() const
	{
		return m_msg.c_str();
	}

private:
	string m_msg;
};

class MyExceptionD :public MyException
{
public:
	MyExceptionD(const char* msg) :MyException(msg)
	{
		cout << "MyExceptionD constructor\n";
	}

	MyExceptionD(const MyExceptionD & other) :MyException(other)
	{
		cout << "MyExceptionD Copy Constructor\n";
	}

	~MyExceptionD()
	{
		cout << "MyExceptionD Destructor\n";
	}
};

void fun(int n) throw(int, MyException, MyExceptionD)
{
	if (1 == n)
	{
		throw 1;
	}
	if (2 == n)
	{
		cout << "2 before\n";
		throw MyException("test myexception");
		cout << "2 after\n";
	}
	if (3 == n)
	{
		cout << "3 before\n";
		throw MyExceptionD("test myexceptionD");
		cout << "3 after\n";
	}
}


/*
catch异常中的子类和父类关系
如果catch按照如下顺序：
MyException
MyExceptionD
那么，抛出MyExceptionD的异常时，会被MyException抓住，从而导致MyExceptionD抓不到异常；
如果catch按照如下顺序:
MyExceptionD
MyException
那么，抛出MyExceptionD的异常时，则会成功的被MyException抓住。
*/
int main(void)
{
	for (int i = 1; i < 4; i++)
	{
		try
		{
			fun(i);
		}
		catch (MyException& e)
		{
			cout << "catch myexception\n";
			cout << e.what() << endl;
		}
		catch (MyExceptionD& e)
		{
			cout << "catch myexceptionD\n";
			cout << e.what() << endl;
		}
		catch (int e)
		{
			cout << "catch int \n";
			cout << e << endl;
		}

		cout << "*************************************************************************************\n";
	}

	return 0;
}