#include <vector>
#include <iostream>

int main()
{
std::vector<int> array;
array = { 0, 1, 2, 3, 4 }; // okay, array length = 5
std::cout << "length: " << array.size() << "  capacity: " << array.capacity() << '\n';

array = { 9, 8, 7 }; // okay, array length is now 3!
std::cout << "length: " << array.size() << "  capacity: " << array.capacity() << '\n';

return 0;
}
