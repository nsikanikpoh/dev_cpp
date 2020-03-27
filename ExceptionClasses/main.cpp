#include <iostream>
#include <string>

class ArrayException
{
private:
	std::string m_error;

public:
	ArrayException(std::string error)
		: m_error(error)
	{
	}

	 const char* getError() { return m_error.c_str(); }
};

class IntArray
{
private:

	int m_data[3]; // assume array is length 3 for simplicity
public:
	IntArray() {}

	int getLength() { return 3; }

	int& operator[](const int index)
	{
		if (index < 0 || index >= getLength())
			throw ArrayException("Invalid index");

		return m_data[index];
	}

};

int main()
{
	IntArray array;

	try
	{
		int value = array[5];
	}
	catch (ArrayException &exception)
	{
		std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
	}
}
