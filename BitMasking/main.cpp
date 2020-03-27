#include <iostream>
#include <bitset>


int main()
{

    constexpr unsigned char mask0{ 0b0000'0001 }; // represents bit 0
    constexpr unsigned char mask1{ 0b0000'0010 }; // represents bit 1
    constexpr unsigned char mask2{ 0b0000'0100 }; // represents bit 2
    constexpr unsigned char mask3{ 0b0000'1000 }; // represents bit 3
    constexpr unsigned char mask4{ 0b0001'0000 }; // represents bit 4
    constexpr unsigned char mask5{ 0b0010'0000 }; // represents bit 5
    constexpr unsigned char mask6{ 0b0100'0000 }; // represents bit 6
    constexpr unsigned char mask7{ 0b1000'0000 }; // represents bit 7

    unsigned char flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

    //To determine if a bit is on or off, we use bitwise AND in conjunction with the bit mask for the appropriate bit:

    std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    std::cout << "bit 3 is " << ((flags & mask3) ? "on\n" : "off\n");
    std::cout << "bit 4 is " << ((flags & mask4) ? "on\n" : "off\n");
    std::cout << "bit 5 is " << ((flags & mask5) ? "on\n" : "off\n");
    std::cout << "bit 6 is " << ((flags & mask6) ? "on\n" : "off\n");
    std::cout << "bit 7 is " << ((flags & mask7) ? "on\n" : "off\n");


//To set (turn on) a bit, we use bitwise OR equals (operator |=) in conjunction with the bit mask for the appropriate bit:


    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    flags |= mask1; // turn on bit 1

    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
    std::cout << "bit 4 is " << ((flags & mask4) ? "on\n" : "off\n");
    std::cout << "bit 5 is " << ((flags & mask5) ? "on\n" : "off\n");

    flags |= (mask4 | mask5); // turn bits 4 and 5 on at the same time
    std::cout << "bit 4 is " << ((flags & mask4) ? "on\n" : "off\n");
    std::cout << "bit 5 is " << ((flags & mask5) ? "on\n" : "off\n");

//To clear a bit (turn off), we use Bitwise AND and Bitwise NOT together


    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    flags &= ~mask2; // turn off bit 2

    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");


    flags &= ~(mask4 | mask5); // turn bits 4 and 5 off at the same time

    std::cout << "bit 4 is " << ((flags & mask4) ? "on\n" : "off\n");
    std::cout << "bit 5 is " << ((flags & mask5) ? "on\n" : "off\n");



    //flipping: To toggle a bit state, we use Bitwise XOR:


    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");


    //  We can turn off multiple bits at the same time:

    flags &= ~(mask4 | mask5); // turn bits 4 and 5 off at the same time


    std::cout << "bit 4 is " << ((flags & mask4) ? "on\n" : "off\n");
    std::cout << "bit 5 is " << ((flags & mask5) ? "on\n" : "off\n");




    return 0;
}
