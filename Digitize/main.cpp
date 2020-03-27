#include <iostream>

int sumNumbers(int x)
{
	if (x < 10)
		return x;
	else
		return sumNumbers(x / 10) + x % 10;
}

int main()
{
	std::cout << sumNumbers(93427);
}
