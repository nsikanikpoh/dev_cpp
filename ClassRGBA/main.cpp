#include <iostream>
#include <cstdint>

using fast8_t = std::uint_fast8_t;

class RGBA
{
private:
    fast8_t m_red;
    fast8_t m_green;
    fast8_t m_blue;
    fast8_t m_alpha;

public:
    RGBA(fast8_t red = 0, fast8_t green = 0, fast8_t blue = 0, fast8_t alpha = 255)
        : m_red { red },
          m_green { green },
          m_blue { blue},
          m_alpha { alpha }
    {
        //asign nothing
    }

    void print()
    {
      std::cout << "r=" << static_cast<int>(m_red) <<
			" g=" << static_cast<int>(m_green) <<
			" b=" << static_cast<int>(m_blue) <<
			" a=" << static_cast<int>(m_alpha) << '\n';
    }

};

int main()
{
    RGBA pixel {0, 127, 127};
    pixel.print();

    RGBA teal(0, 127, 127);
	teal.print();

    return 0;
}
