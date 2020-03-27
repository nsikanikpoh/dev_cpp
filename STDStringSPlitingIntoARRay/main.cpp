#include <vector>
#include <string>
#include <sstream>
#include <iostream>

int main()
{
    std::string str("Split me by whitespaces");
    std::string buf;                 // Have a buffer string
    std::stringstream ss(str);       // Insert the string into a stream

    std::vector<std::string> tokens; // Create vector to hold our words

    while (ss >> buf)
        tokens.push_back(buf);

    for(const auto& elem: tokens)
        std::cout << elem << '\n';

    return 0;
}
