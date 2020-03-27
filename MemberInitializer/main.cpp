#include <iostream>

class Something
{
private:
    const int m_value1;
    double m_value2;
    char m_value3;

public:
    Something() : m_value1(1), m_value2(2.2), m_value3('c') // directly initialize our member variables
    {
    // No need for assignment here
    }

    Something(int value1, double value2, char value3='P')
        : m_value1{value1}, m_value2 { value2 }, m_value3{value3} // directly initialize our member variables
    {
    // No need for assignment here
    }

    void print()
    {
         std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }
};

int main()
{
    Something something;
    something.print();
    Something something2(6, 7.96); // value1 = 1, value2=2.2, value3 gets default value 'c'
    something2.print();
    return 0;
}
