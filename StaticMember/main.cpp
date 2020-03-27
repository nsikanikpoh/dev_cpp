#include <iostream>

class Something
{
public:
    static int s_value; // declares the static member variable
};

int Something::s_value = 1; // defines the static member variable (we'll discuss this section below)

int main()
{
    // note: we're not instantiating any objects of type Something

    Something::s_value = 2;
    std::cout << Something::s_value << '\n';
    return 0;
}
