#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vect{ 7, -3, 6, 2, -5, 0, 4 };

    // sort the vector
    std::sort(vect.begin(), vect.end());

    for (int i : vect)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    // reverse the vector
    std::reverse(vect.begin(), vect.end());

    for (int i : vect)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    //Alternatively, we could pass a custom comparison function as the third argument to std::sort.
    //There are several comparison functions in the <functional> header which we can use so we don’t
    // have to write our own. We can pass std::greater to std::sort and remove the call to std::reverse.
    //The vector will be sorted from high to low right away.

//Note that std::sort() doesn’t work on list container classes -- the list class provides its own sort()
//member function, which is much more efficient than the generic version would be.

    return 0;
}
