#include <iostream>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator=0, int denominator=1):
        m_numerator(numerator), m_denominator(denominator)
    {
        // We put reduce() in the constructor to ensure any fractions we make get reduced!
        // Since all of the overloaded operators create new Fractions, we can guarantee this will get called here
        reduce();
    }

    // We'll make gcd static so that it can be part of class Fraction without requiring an object of type Fraction to use
    static int gcd(int a, int b)
    {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }

    void reduce()
    {
        if (m_numerator != 0 && m_denominator != 0)
        {
            int gcd = Fraction::gcd(m_numerator, m_denominator);
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, int value);
    friend Fraction operator*(int value, const Fraction &f1);
    friend std::ostream& operator<< (std::ostream &out, const Fraction &f);
    friend std::istream& operator>> (std::istream &in, Fraction &f);

    void print()
    {
        std::cout << m_numerator << "/" << m_denominator << "\n";
    }

};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction &f1, int value)
{
    return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction &f1)
{
    return Fraction(f1.m_numerator * value, f1.m_denominator);
}

std::ostream& operator<< (std::ostream &out, const Fraction &f)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << f.m_numerator << "/" << f.m_denominator; // actual output done here

    return out; // return std::ostream so we can chain calls to operator<<
}

std::istream& operator>> (std::istream &in, Fraction &f)
{
    // Overwrite the values of f1
    in >> f1.m_numerator;

    // Ignore the '/' separator
    in.ignore(std::numeric_limits<std::streamsize>::max(), '/');

    in >> f1.m_denominator;

    // Since we overwrite the existing f1, we need to reduce again
    f1.reduce();

    return in;
}



int main()
{
    Fraction f1(2, 5);
    f1.print();

    Fraction f2(3, 8);
    f2.print();

    Fraction f3 = f1 * f2;
    f3.print();

    Fraction f4 = f1 * 2;
    f4.print();

    Fraction f5 = 2 * f2;
    f5.print();

    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();

    Fraction f7(0, 6);
    f7.print();

    Fraction f8;
    std::cout << "Enter fraction 1: ";
    std::cin >> f8;

    Fraction f9;
    std::cout << "Enter fraction 2: ";
    std::cin >> f9;

    std::cout << f8 << " * " << f9 << " is " << f8 * f9 << '\n'; // note: The result of f1 * f2 is an r-value

    return 0;
}
