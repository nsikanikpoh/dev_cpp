#include <iostream>

class Fraction
{
private:
    int m_numerator = 0;
    int m_denominator =1;
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
    void print()
    {
        reduce();
        std::cout << m_numerator << "/" << m_denominator << "\n";
    }

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f, int value);
    friend Fraction operator*(int value, const Fraction &f);
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return Fraction(f1.m_numerator*f2.m_numerator, f1.m_denominator*f2.m_denominator);
}
Fraction operator*(const Fraction &f, int value)
{
    return Fraction(f.m_numerator*value, f.m_denominator);
}
Fraction operator*(int value, const Fraction &f)
{
    return Fraction(f.m_numerator*value, f.m_denominator);
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

    return 0;
}
