#include <iostream>
using namespace std;

class CRectangle
{
public:
	CRectangle()
	{

	}

	CRectangle(int s4Width, int s4Height)
	{
		this->m_s4Width = s4Width;
		this->m_s4Height = s4Height;
	}

	CRectangle operator+(const CRectangle& rect1)
	{
		CRectangle rect;
		rect.m_s4Width = this->m_s4Width + rect1.m_s4Width;
		rect.m_s4Height = this->m_s4Height + rect1.m_s4Height;

		return rect;
	}

	void Show()
	{
		cout << this->m_s4Width << "---" << this->m_s4Height << endl;
	}

	void SetValue(int s4Width, int s4Height)
	{
		this->m_s4Width = s4Width;
		this->m_s4Height = s4Height;
	}

private:
	int		m_s4Width;
	int		m_s4Height;
};

void main()
{
	CRectangle	rect1;
	CRectangle	rect2;
	CRectangle	rect3;

	rect1.SetValue(12, 34);
	rect2.SetValue(23, 45);

	rect3 = rect1 + rect2;
	rect3.Show();
	cout << "hello world" << endl;
}