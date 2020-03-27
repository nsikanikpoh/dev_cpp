#include <string>
#include <iostream>
#include <cassert>

class Mystring
{
private:
	std::string m_string;

public:
	Mystring(const std::string& string = "")
		:m_string{ string }
	{
	}

	std::string operator()(int start, int length)
	{
		assert(start + length <= static_cast<int>(m_string.length()) && "Mystring::operator(int, int): Substring is out of range");

		std::string ret;
		for (int count{ 0 }; count < length; ++count)
			ret += m_string[static_cast<std::string::size_type>(start + count)];
		return ret;
	}
};

int main()
{
	Mystring string{ "Hello, world!" };
	std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters

	return 0;
}
