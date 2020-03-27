#include <array>
#include <iostream>

int main()
{
  std::array data{ 0, 1, 2, 3, 4, 5, 6 };

  auto begin{ &data[0] };
  // note that this points to one spot beyond the last element
  auto end{ begin + std::size(data) };

  // for-loop with pointer
  for (auto ptr{ begin }; ptr != end; ++ptr) // ++ to move to next element
  {
    std::cout << *ptr << ' '; // dereference to get value of current element
  }
  std::cout << '\n';

  return 0;
}
