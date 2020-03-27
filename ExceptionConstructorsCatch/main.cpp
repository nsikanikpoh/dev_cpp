#include <iostream>

class Member
{
public:
	Member()
	{
		std::cerr << "Member allocated some resources\n";
	}

	~Member()
	{
		std::cerr << "Member cleaned up\n";
	}
};

class A
{
private:
	int m_x;
	Member m_member;

public:
	A(int x) : m_x(x)
	{
		if (x <= 0)
			throw 1;
	}

	~A()
	{
		std::cerr << "~A\n"; // should not be called
	}
};


int main()
{
	try
	{
		A a(0);
	}
	catch (int)
	{
		std::cerr << "Oops\n";
	}

	return 0;
}
