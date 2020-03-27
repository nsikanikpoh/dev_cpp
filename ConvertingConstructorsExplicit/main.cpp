#include <string>
#include <iostream>

class MyString
{
private:
	std::string m_string;
public:
        // explicit keyword makes this constructor ineligible for implicit conversions
	explicit MyString(int x) // allocate string of size x
	{
		m_string.resize(x);
	}

	MyString(const char *string) // allocate string to hold string value
	{
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream& out, const MyString &s);

};

std::ostream& operator<<(std::ostream& out, const MyString &s)
{
	out << s.m_string;
	return out;
}

void printString(const MyString &s)
{
	std::cout << s;
}

int main()
{
	MyString mine = 'x'; // compile error, since MyString(int) is now explicit and nothing will match this
	std::cout << mine;

	printString('x'); // compile error, since MyString(int) can't be used for implicit conversions

	return 0;
}
