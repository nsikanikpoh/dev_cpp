#include <iostream>

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents=0)
        : m_cents{ cents }
    {
    }

    // Overloaded int cast
    operator int() const
    {
        return m_cents;
    }

    int getCents() const
    {
        return m_cents;
    }
    void setCents(int cents)
    {
        m_cents = cents;
    }
};


void printInt(int value)
{
    std::cout << value;
}


int main()
{

    Cents cents{ 7 };
    printInt(cents); // print 7

    std::cout << '\n';
    //We can now also explicitly cast our Cents variable to an int:
    int c{ static_cast<int>(cents) };


    printInt(c); // print 7

    std::cout << '\n';
    return 0;
}
