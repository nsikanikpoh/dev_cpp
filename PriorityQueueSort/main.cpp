#include <iostream>

using namespace std;


Algorithm PriorityQueueSort(L, P):
Input:
    An STL list L of n elements and a priority queue, P, that compares
    elements using a total order relation
Output:
    The sorted list L
    while !L.empty()
        do
            e ← L.front
            L.pop front()
    {
        remove an element e from the list
    }
P.insert(e)
{
    . . . and it to the priority queue
}
while !P.empty()
    do
        e ← P.min()
        P.removeMin()
    {
        remove the smallest element e from the queue
    }
{
    . . . and append it to the back of L
}
L.push back(e)


Code Fragment 8.5: Algorithm PriorityQueueSort, which sorts an STL list L with
the aid of a priority queue P.

int main()
{
    cout << "Hello world! " << endl;
    return 0;
}
