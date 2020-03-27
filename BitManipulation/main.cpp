#include <iostream>
#include <bitset>

std::bitset<4> rotl(std::bitset<4> bits)
{
    bool leftbit = bits.test(3);

    bits <<= 1; // do left shift

    if (leftbit)
        bits.set(0);

    return bits;


    // bits << 1 does the left shift
    // bits >> 3 handle the rotation of the leftmost bit
    //return (bits<<1) | (bits>>3);


}

int main()
{

    std::bitset<4> bits1{ 0b0001 };
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2{ 0b1001 };
    std::cout << rotl(bits2) << '\n';



    std::bitset<4> x { 0b1100 };

    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
    std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000
    std::cout << std::bitset<4>(~0b0100u) << ' ' << std::bitset<8>(~0b0100u) << '\n';
    std::cout << (std::bitset<4>(0b0111) | std::bitset<4>(0b0011) | std::bitset<4>(0b0001)) << '\n';
    std::cout << (std::bitset<4>(0b0101) | std::bitset<4>(0b0110)) << '\n';

    std::cout << (std::bitset<4>(0b0101) & std::bitset<4>(0b0110)) << '\n';
    std::cout << (std::bitset<4>(0b0001) & std::bitset<4>(0b0011) & std::bitset<4>(0b0111)) << '\n';

    std::cout << (std::bitset<4>(0b0101) ^ std::bitset<4>(0b0110)) << '\n';
    std::cout << (std::bitset<4>(0b0001) ^ std::bitset<4>(0b0011) ^ std::bitset<4>(0b0111)) << '\n';


    //bitwise assignment
    std::bitset<4> bits { 0b0100 };
    bits >>= 1;
    std::cout << bits;


    return 0;
}
