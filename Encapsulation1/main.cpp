#include <iostream>

class IntArray
{
private:
    int m_array[10]; // user can not access this directly any more

public:
    void setValue(int index, int value)
    {
        // If the index is invalid, do nothing
        if (index < 0 || index >= 10)
            return;

        m_array[index] = value;
    }
};

class Something
{
private:
    int m_value1;
    int m_value2;
    int m_value3;

public:
    void setValue1(int value)
    {
        m_value1 = value;
    }
    int getValue1()
    {
        return m_value1;
    }
};


int main()
{
    Something something;
    something.setValue1(5);
    std::cout << something.getValue1() << '\n';
}
