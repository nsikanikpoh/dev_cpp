#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
  std::array months{ // pre-C++17 use std::array<const char*, 12>
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
  };

  // Count how many months consist of 5 letters
  auto fiveLetterMonths{ std::count_if(months.begin(), months.end(),
                                       [](std::string_view str) {
                                         return (str.length() == 5);
                                       }) };

  std::cout << "There are " << fiveLetterMonths << " months with 5 letters\n";

  return 0;
}

//In this example, using auto would infer a type of const char*. C-style strings aren’t easy to work
//with (apart from using operator[]). In this case, we prefer to explicitly define the parameter as
//a std::string_view, which allows us to work with the underlying data much more easily (e.g.
//we can ask the string view for its length, even if the user passed in a C-style array).
