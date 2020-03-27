#include <iostream>

struct S
{
	int m_x;
	double m_y;
};

S returnStruct()
{
	S s;
	s.m_x = 5;
	s.m_y = 6.7;
	return s;
}

int main()
{
	S s = returnStruct();
	std::cout << s.m_x << ' ' << s.m_y << '\n';

	return 0;
}
