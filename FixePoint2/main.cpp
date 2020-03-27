#include <iostream>
#include <cstdint> // for fixed width integers
#include <cmath> // for round()

class FixedPoint2
{
private:
    std::int_least16_t m_base{}; // here's our non-fractional part
    std::int_least8_t m_decimal{}; // here's our factional part

public:
    FixedPoint2(std::int_least16_t base = 0, std::int_least8_t decimal = 0)
        : m_base{ base }, m_decimal{ decimal }
    {
        // We should handle the case where decimal is > 99 or < -99 here
        // but will leave as an exercise for the reader

        // If either the base or decimal or negative
        if (m_base < 0 || m_decimal < 0)
        {
            // Make sure base is negative
            if (m_base > 0)
                m_base = -m_base;
            // Make sure decimal is negative
            if (m_decimal > 0)
                m_decimal = -m_decimal;
        }
    }

    FixedPoint2(double d):
        // First we need to get the non-fractional component
        // We can do this by casting our double to an integer
        m_base { static_cast<int_least16_t>(d) },

        // Now we need to get the fractional component:
        // 1) d - m_base leaves only the fractional portion
        // 2) which can we multiply by 100 to move the digits to the left of the decimal
        // 3) then we can round this
        // 4) and finally static cast to an integer to drop any extra decimals
        m_decimal { static_cast<std::int_least8_t>(round((d - m_base) * 100)) }
    {
    }

    operator double() const
    {
        return m_base + static_cast<double>(m_decimal) / 100.0;
    }


    friend bool operator==(const FixedPoint2 &fp1, const FixedPoint2 &fp2)
    {
        return (fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal);
    }

    FixedPoint2 operator-() const
    {
        return FixedPoint2(-m_base, -m_decimal);
    }


};

// This doesn't require access to the internals of the class, so it can be defined outside the class
std::ostream& operator<<(std::ostream &out, const FixedPoint2 &fp)
{
    out << static_cast<double>(fp);
    return out;
}

FixedPoint2 operator+(const FixedPoint2 &fp1, const FixedPoint2 &fp2)
{
    return FixedPoint2(static_cast<double>(fp1) + static_cast<double>(fp2));
}

void testAddition()
{
    // h/t to reader Sharjeel Safdar for this function
    std::cout << std::boolalpha;
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}

int main()
{
    FixedPoint2 a{ 34, 56 };
    std::cout << a << '\n';

    FixedPoint2 b{ -2, 8 };
    std::cout << b << '\n';

    FixedPoint2 c{ 2, -8 };
    std::cout << c << '\n';

    FixedPoint2 d{ -2, -8 };
    std::cout << d << '\n';

    FixedPoint2 e{ 0, -5 };
    std::cout << e << '\n';

    std::cout << static_cast<double>(e) << '\n';


    FixedPoint2 f{ 0.01 };
    std::cout << f << '\n';

    FixedPoint2 g{ -0.01 };
    std::cout << g << '\n';

    FixedPoint2 i{ 5.01 }; // stored as 5.0099999... so we'll need to round this
    std::cout << i << '\n';

    FixedPoint2 s{ -5.01 }; // stored as -5.0099999... so we'll need to round this
    std::cout << s << '\n';



    return 0;
}
