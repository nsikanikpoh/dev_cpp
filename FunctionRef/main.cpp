#include <iostream>

void addOne(int &ref)
{
    ref = ref + 1;
}

int main()
{
    int value = 5;

    std::cout << "value = " << value << '\n';
    addOne(value);
    std::cout << "value = " << value << '\n';
    return 0;
}
