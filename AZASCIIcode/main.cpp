#include <iostream>



int main()
{
    char alpha{'a'};

    while (alpha <= 'z')
    {
        std::cout <<  alpha << '\t' << static_cast<int>(alpha) << '\n';
        ++alpha;

    }

    return 0;
}
