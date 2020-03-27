#include <iostream>
#include <string>
#include <utility> // for std::swap, if you're not C++11 compatible, #include <algorithm> instead


int main()
{
	std::cout << "Enter a name:  ";
	std::string inp;
	std::cin >> inp;

	// Allocate an array to hold the names
	std::string names[]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    bool found{false};
	for (const auto &element: names)
	{
	 if(element == inp)
	 {
	   found = true;
	   break;
	 }

	}
	if(found)
	  std::cout << inp << " was found.\n";
    else
    std::cout << inp << " was not found.\n";


	return 0;
}
