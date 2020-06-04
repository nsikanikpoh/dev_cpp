#include <iostream>
#include <algorithm>

using std::begin;
using std::rbegin;
using std::rend;


int main()
{

    bool arr[7] = {true,false,true,true,true,false, true};
    auto it = std::find(rbegin(arr), rend(arr), false);
    if (it != rend(arr))
    {
        auto idx = std::distance(begin(arr), it.base());
        std::cout << "idx  is " << idx << std::endl;
    }
    return 0;
}
