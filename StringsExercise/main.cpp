#include <string>
#include <iostream>
#include <limits>


int main()
{
	std::cout << "Pick 1 or 2: ";
	int choice{};
	std::cin >> choice;

    //	std::cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore unlimited characters until a \n is removed

	std::cout << "Now enter your name: ";
	std::string name;
	std::getline(std::cin, name);

	std::cout << "Hello, " << name << ", you picked " << choice << '\n';

	std::string a{ "45" };
    std::string b{ "11" };

    std::cout << a + b << '\n'; // a and b will be concatenated
    a += " volts";
    std::cout << a << '\n';

     std::string myName{ "Alex" };
    std::cout << myName << " has " << myName.length() << " characters\n";


     std::cout << "Enter your full name: ";
    std::string namesd{};
    std::getline(std::cin, namesd); // read a full line of text into name

    std::cout << "Enter your age: ";
    int age{}; // age needs to be an integer, not a string, so we can do math with it
    std::cin >> age;

    int letters{ static_cast<int>(namesd.length()) }; // get number of letters in name (including spaces)
    double agePerLetter{ static_cast<double>(age) / letters }; // static cast age to double to avoid integer division
    std::cout << "You've lived " << agePerLetter << " years for each letter in your name.\n";


	return 0;
}
