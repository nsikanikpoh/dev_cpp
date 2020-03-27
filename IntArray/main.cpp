#include <iostream>
#include <cassert>

class IntArray
{
private:
	int m_length{ 0 };
	int *m_array{ nullptr };

public:
	IntArray(int length):
		m_length{ length }
	{
		assert(length > 0 && "IntArray length should be a positive integer");

		m_array = new int[m_length]{};
	}

	// Copy constructor that does a deep copy
	IntArray(const IntArray &array):
		m_length{ array.m_length }
	{
		// Allocate a new array
		m_array = new int[m_length];

		// Copy elements from original array to new array
		for (int count{ 0 }; count < array.m_length; ++count)
			m_array[count] = array.m_array[count];
	}

  ~IntArray()
	{
		delete[] m_array;
	}

	int& operator[] (int index);
    const int& operator[] (int index) const;

    friend std::ostream& operator<<(std::ostream &out, const IntArray &arr)
	{
        for (int count{ 0 }; count < arr.m_length; ++count)
			out << arr.m_array[count] << " ";
		return out;
	}



	// Assignment operator that does a deep copy
	IntArray& operator= (const IntArray &array)
	{
		// self-assignment guard
		if (this == &array)
			return *this;

		// If this array already exists, delete it so we don't leak memory
		delete[] m_array;

		m_length = array.m_length;

		// Allocate a new array
		m_array = new int[m_length];

		// Copy elements from original array to new array
		for (int count{ 0 }; count < array.m_length; ++count)
			m_array[count] = array.m_array[count];

		return *this;
	}

};



int& IntArray::operator[] (int index) // for non-const objects: can be used for assignment
{
    assert(index >= 0 && index < 10);
    return m_array[index];
}

const int& IntArray::operator[] (int index) const // for const objects: can only be used for access
{
    assert(index >= 0 && index < m_length);
    return m_array[index];
}

IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main()
{
    IntArray a{ fillArray() };
    std::cout << a << '\n';

    auto &ref{ a }; // we're using this reference to avoid compiler self-assignment errors
    a = ref;

    IntArray b(1);
    b = a;

    std::cout << b << '\n';

    return 0;
}
