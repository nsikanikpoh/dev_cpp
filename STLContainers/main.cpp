#include <vector>
#include <iostream>
#include <deque>

int main()
{

    std::vector<int> vect;
    for (int count=0; count < 6; ++count)
        vect.push_back(10 - count); // insert at end of array

    for (int index=0; index < vect.size(); ++index)
        std::cout << vect[index] << ' ';

    std::cout << '\n';


    std::deque<int> deq;
    for (int count=0; count < 3; ++count)
    {
        deq.push_back(count); // insert at end of array
        deq.push_front(10 - count); // insert at front of array
    }

    for (int index=0; index < deq.size(); ++index)
        std::cout << deq[index] << ' ';

    std::cout << '\n';



    return 0;
}
