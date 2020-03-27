#include <array>
#include <iostream>
#include <iterator> // For std::begin and std::end

int main()
{
  std::array array{ 1, 2, 3 };

  // Use std::begin and std::end to get the begin and end points.
  auto begin{ std::begin(array) };
  auto end{ std::end(array) };

  for (auto p{ begin }; p != end; ++p) // ++ to move to next element
  {
    std::cout << *p << ' '; // dereference to get value of current element
  }
  std::cout << '\n';

  return 0;
}
