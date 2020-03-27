#include <iostream>
#include <string>

 void printString(const char *cstring)
{
    // Only print if cstring is non-null
    if (cstring)
        std::cout << cstring;
}

int main()
{
    std::string hello{ "Hello, world!" };
    std::cout << "Enter a letter: ";

    char ch;
    std::cin >> ch;

    int index{ static_cast<int>(hello.find(ch)) };
     if (index != -1) // handle case where find() failed to find the character in the string
        std::cout << ch << " was found at index " << index << '\n';
    else
        std::cout << ch << " wasn't found" << '\n';

    return 0;
}
