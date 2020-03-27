#include <algorithm>
#include <array>
#include <iostream>
#include <functional>

int main()
{
  std::array arr{ 13, 90, 99, 5, 40, 80 };

   std::sort(arr.begin(), arr.end(), std::greater{}); // use the standard library greater caparison

  for (int i : arr)
  {
    std::cout << i << ' ';
  }

  std::cout << '\n';

  return 0;
}
