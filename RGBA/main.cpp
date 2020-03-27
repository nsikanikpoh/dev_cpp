#include <iostream>

int main()
{
	constexpr unsigned int redBits{ 0xFF000000 };
	constexpr unsigned int greenBits{ 0x00FF0000 };
	constexpr unsigned int blueBits{ 0x0000FF00 };
	constexpr unsigned int alphaBits{ 0x000000FF };

	std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
	unsigned int pixel{};
	std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

	// use Bitwise AND to isolate red pixels,
	// then right shift the value into the lower 8 bits
	// (we're not using brace initialization to avoid a static_cast)
	unsigned char red = (pixel & redBits) >> 24;
	unsigned char green = (pixel & greenBits) >> 16;
	unsigned char blue = (pixel & blueBits) >> 8;
	unsigned char alpha = pixel & alphaBits;

	std::cout << "Your color contains:\n";
	std::cout << std::hex; // print the following values in hex
	std::cout << static_cast<int>(red) << " red\n";
	std::cout << static_cast<int>(green) << " green\n";
	std::cout << static_cast<int>(blue) << " blue\n";
	std::cout << static_cast<int>(alpha) << " alpha\n";

	return 0;
}
