
#include <iostream>

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents) { m_cents = cents; }

    int getCents() const { return m_cents; }
};

void print(const Cents &cents)
{
   std::cout << cents.getCents() << " cents";
}

int main()
{
    print(Cents(6)); // Note: Now we're passing an anonymous Cents value

    return 0;
}
