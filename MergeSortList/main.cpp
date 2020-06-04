#include <iostream>
#include <list>

using namespace std;


template <typename E, typename C>
void mergeSort(list<E>& S, const C& less)// merge-sort S
{
    typedef typename list<E>::iterator Itor;// sequence of elements
    int n = S.size();
    if (n <= 1)
        return;// already sorted
    list<E> S1, S2;
    Itor p = S.begin();
    for (int i = 0; i < n/2; i++)
        S1.push_back(*p++); // copy first half to S1
    for (int i = n/2; i < n; i++)
        S2.push_back(*p++); // copy second half to S2
    S.clear();// clear S’s contents
    mergeSort(S1, less);// recur on first half
    mergeSort(S2, less);// recur on second half
    merge(S1, S2, S, less);// merge S1 and S2 into S
}
template <typename E, typename C>
void merge(list<E>& S1, list<E>& S2, list<E>& S, const C& less)// merge utility
{
    typedef typename list<E>::iterator Itor;// sequence of elements
    Itor p1 = S1.begin();
    Itor p2 = S2.begin();
    while(p1 != S1.end() && p2 != S2.end())// until either is empty
    {
        if(less(*p1, *p2))// append smaller to S
            S.push_back(*p1++);
        else
            S.push_back(*p2++);
    }
    while(p1 != S1.end())// copy rest of S1 to S
        S.push_back(*p1++);
    while(p2 != S2.end())
        S.push_back(*p2++);// copy rest of S2 to S
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
