#include <iostream>
#include <string_view>

int main()
{
    std::string_view text{ "hello" }; // view the text "hello", which is stored in the binary
    std::string_view str1{ text }; // view of the same "hello"
    std::string_view more{ str1 }; // view of the same "hello"

    std::cout << text << ' ' << str1 << ' ' << more << '\n';


    std::string_view str{ "Trains are fast!" };

    std::cout << str.length() << '\n'; // 16
    std::cout << str.substr(0, str.find(' ')) << '\n'; // Trains
    std::cout << (str == "Trains are fast!") << '\n'; // 1

    // Since C++20
//  std::cout << str.starts_with("Boats") << '\n'; // 0
// std::cout << str.ends_with("fast!") << '\n'; // 1

    std::cout << str << '\n'; // Trains are fast!


    char arr[] { "Gold" };
    std::string_view str2{ arr };

    std::cout << str2 << '\n'; // Gold

    // Change 'd' to 'f' in arr
    arr[3] = 'f';

    std::cout << str2 << '\n'; // Golf
     std::cout << arr << '\n'; // Golf

    return 0;

    return 0;
}
