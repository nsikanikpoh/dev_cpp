#include <iostream>
#include <string_view>
#include <cstring>
//#include <string>

std::string_view askForName()
{
    std::cout << "What's your name?\n";

    // Use a std::string, because std::cin needs to modify it.
    std::string str{};
    std::cin >> str;

    // We're switching to std::string_view for demonstrative purposes only.
    // If you already have a std::string, there's no reason to switch to
    // a std::string_view.
    std::string_view view{ str };

    std::cout << "Hello " << view << '\n';

    return view;
} // str dies, and so does the string that str created.

void print(std::string s)
{
    std::cout << s << '\n';
}

int main()
{
    std::string_view sv{ "balloon" };
    std::cout << std::strlen(sv.data()) << '\n';
    sv.remove_suffix(3);

    // print(sv); // compile error: won't implicitly convert

    std::string str5{ sv }; // explicit conversion

    print(str5); // okay

    print(static_cast<std::string>(sv)); // okay


  // Get the null-terminated C-style string.
  auto szNullTerminated{ str5.c_str() };

  // Pass the null-terminated string to the function that we want to use.
  std::cout << str5 << " has " << std::strlen(szNullTerminated) << " letter(s)\n";




    std::string_view view{ askForName() };

    // view is observing a string that already died.
    std::cout << "Your name is " << view << '\n'; // Undefined behavior







// No null-terminator.
    char vowels[] { 'a', 'e', 'i', 'o', 'u' };

    // vowels isn't null-terminated. We need to pass the length manually.
    // Because vowels is an array, we can use std::size to get its length.
    std::string_view str4{ vowels, std::size(vowels) };

    std::cout << str4 << '\n'; // This is safe. std::cout knows how to print std::string_views.



    std::string_view str3{ "Peach" };

    std::cout << str3 << '\n';

    // Ignore the first characters.
    str3.remove_prefix(1);

    std::cout << str3 << '\n';

    // Ignore the last 2 characters.
    str3.remove_suffix(2);

    std::cout << str3 << '\n';


    char arr[] { "Gold" };
    std::string_view str2{ arr };

    std::cout << str2 << '\n'; // Gold

    // Change 'd' to 'f' in arr
    arr[3] = 'f';

    std::cout << str2 << '\n'; // Golf


    std::string_view str{ "Trains are fast!" };

    std::cout << str.length() << '\n'; // 16
    std::cout << str.substr(0, str.find(' ')) << '\n'; // Trains
    std::cout << (str == "Trains are fast!") << '\n'; // 1

    // Since C++20
//  std::cout << str.starts_with("Boats") << '\n'; // 0
// std::cout << str.ends_with("fast!") << '\n'; // 1

    std::cout << str << '\n'; // Trains are fast!

    return 0;
}
