#include <iostream>
#include <iterator> // for std::size
#include <cstring>

int main()
{

  // Ask the user to enter a string
    char buffer[255];
    std::cout << "Enter a string: ";

    std::cin >> buffer;

    int spacesFound{ 0 };
    int bufferLength{ static_cast<int>(std::strlen(buffer)) };
    // Loop through all of the characters the user entered
    for (int index{ 0 }; index < bufferLength; ++index)
    {
        // If the current character is a space, count it
        if (buffer[index] == ' ')
            ++spacesFound;
    }

    std::cout << "You typed " << spacesFound << " spaces!\n";




    char source[] { "Copy this!" };
    char dest[50];
    std::strcpy(dest, source);

    std::cout << dest << '\n'; // prints "Copy this!"



    char name[255]; // declare array large enough to hold 255 characters
    std::cout << "Enter your name: ";
   // const int len{ sizeof(name) / sizeof(name[0]) }; // use instead if not C++17 capable
    std::cin.getline(name, std::size(name));
    std::cout << "You entered: " << name << '\n';



    char dmyString[] { "string" };
    dmyString[1] = 'p';
    std::cout << dmyString << '\n';


    char myString[] { "string" };
    const int length{ static_cast<int>(std::size(myString)) };
   // const int length{ sizeof(myString) / sizeof(myString[0]) }; // use instead if not C++17 capable
    std::cout << myString<< " has " << length << " characters.\n";

    for (int index{ 0 }; index < length; ++index)
        std::cout << static_cast<int>(myString[index]) << " ";

    std::cout << '\n';

    return 0;
}
