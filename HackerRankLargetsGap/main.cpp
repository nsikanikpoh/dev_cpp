#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

std::vector<bool> to_binary(int num)
{
  std::vector<bool> binary;
  while(num != 0)
  {
    binary.emplace_back(num % 2 != 0);
    num /= 2;
  }
  return binary;
}

int findlargestGap(int num)
{
  int largest_gap = 0;
  auto binary       = to_binary(num);
  auto       it     = binary.begin();
  const auto it_end = binary.end();
  while(it != it_end)
  {
    auto current_true = std::find(it, it_end, true);
    if(current_true == it_end)
      break;

    auto next_true = std::find(current_true+1, it_end, true);
    if(next_true == it_end)
      break;

    const auto d = std::distance(current_true, next_true) - 1;
    largest_gap = std::max(largest_gap, static_cast<int>(d));

    it = next_true;
  }

  return largest_gap;
}


constexpr int biggest_binary_gap(unsigned n) noexcept {
    while (n && !(n & 1))
        n >>= 1;
    int r = 0;
    for (;;) {
        while (n & 1)
            n >>= 1;
        if (!n)
            return r;
        int m = 0;
        while (!(n & 1)) {
            ++m;
            n >>= 1;
        }
        if (r < m)
            r = m;
    }
}

int main(int argc, char** argv)
{
  std::cout << "largest gap for 9: "   << biggest_binary_gap(9) << '\n';
  std::cout << "largest gap for 529: " << biggest_binary_gap(529) << '\n';
  std::cout << "largest gap for 20: "  << biggest_binary_gap(20) << '\n';
  std::cout << "largest gap for 15: "  << biggest_binary_gap(15) << '\n';
  std::cout << "largest gap for 32: "  << findlargestGap(32) << '\n';
}
