
#include <iostream>
int main()
{
        // Define a bunch of physical/emotional states
	//constexpr unsigned char isHungry{	1 << 0 }; // 0000 0001
	//constexpr unsigned char isSad{		1 << 1 }; // 0000 0010
	//constexpr unsigned char isMad{		1 << 2 }; // 0000 0100
	constexpr unsigned char isHappy{	1 << 3 }; // 0000 1000
	constexpr unsigned char isLaughing{ 1 << 4 }; // 0001 0000
	//constexpr unsigned char isAsleep{	1 << 5 }; // 0010 0000
	//constexpr unsigned char isDead{		1 << 6 }; // 0100 0000
	//constexpr unsigned char isCrying{	1 << 7 }; // 1000 0000

	unsigned char me{}; // all flags/options turned off to start
	me |= isHappy | isLaughing; // I am happy and laughing
	me &= ~isLaughing; // I am no longer laughing

	// Query a few states
	// (we'll use static_cast<bool> to interpret the results as a boolean value)
	std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
	std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n';

	return 0;
}
