#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include <assert.h> // for assert()

template <class T> // This is a template class, the user will provide the data type for T
class Array
{
private:
    int m_length;
    T *m_data;

public:
    Array()
    {
        m_length = 0;
        m_data = nullptr;
    }

    Array(int length)
    {
        m_data = new T[length];
        m_length = length;
    }

    ~Array()
    {
        delete[] m_data;
    }

    void Erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }


    T& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // The length of the array is always an integer
    // It does not depend on the data type of the array
    int getLength(); // templated getLength() function defined below
};

template <typename T> // member functions defined outside the class need their own template declaration
int Array<T>::getLength() { return m_length; } // note class name is Array<T>, not Array



#endif // ARRAY_H_INCLUDED
