template <typename T> // this is the template parameter declaration
const T& max(const T& x, const T& y)
{
    return (x > y) ? x : y;
}

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents)
        : m_cents{ cents }
    {
    }
     friend bool operator>(const Cents &c1, const Cents &c2)
    {
        return (c1.m_cents > c2.m_cents);
    }
};

int main()
{
    Cents nickle{ 5 };
    Cents dime{ 10 };

    Cents bigger{ max(nickle, dime) };

    return 0;
}
