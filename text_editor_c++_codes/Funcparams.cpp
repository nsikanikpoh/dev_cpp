#include <iostream>
 
int getValueFromUser() // this function now returns an integer value
{
 	std::cout << "Enter an integer: ";
	int input{ 0 };
	std::cin >> input;  
 
	return input; // added return statement to return input back to the caller
}
 
void printDouble(int value)
{
	std::cout << value << " doubled is: " << value * 2 << '\n';
}
 
int main()
{
	int num { getValueFromUser() };
 
	printDouble(num);
 
	return 0;
}