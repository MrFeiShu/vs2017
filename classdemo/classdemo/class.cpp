#include <iostream>
using namespace std;

class Student
{
public:
	Student()
	{
		cout << "Construct\n";
	}

	Student(string name, int age)
	{
		this->name = name;
		this->age = age;
		cout << this->name.c_str() << "***" << this->age << endl;
	}

	Student(const Student& stu) // 注意，拷贝构造函数形参里一定是引用
	{
		cout << "Copy Construct\n";
		this->age = stu.age;
		this->name = stu.name;
	}

	void SetName(string name)
	{
		this->name = name;
	}

	void SetAge(int age)
	{
		this->age = age;
	}

	void Show()
	{
		cout << "name:" << this->name.c_str() << "age:" << this->age << endl;
	}

	~Student()
	{
		cout << "Destruct\n";
	}

private:
	string	name;
	int		age;
};

int main(void)
{
// 	Student	stu1;
// 	stu1.SetName("feifei");
// 	stu1.SetAge(18);
// 
// 	Student stu2 = stu1;
// 	stu2.Show();

	Student("feishu", 18);

	return 0;
}