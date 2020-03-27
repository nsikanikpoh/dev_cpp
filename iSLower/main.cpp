#include <iostream>

bool isLowerVowel(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

// not called from anywhere right now
// but here if you want to retest things later
int test()
{
    if (isLowerVowel('a') != true)
        return 1;
    if (isLowerVowel('q') != false)
        return 2;

    return 0;
}

int main()
{
    std::cout << test() << '\n';
    return 0;
}
