#include <iostream>

using namespace std;


Algorithm find(k):
    Input: A key k
    Output: The position of the matching entry of L, or end if there is no key k in L
    for each position p ∈ [L.begin(), L.end()) do
        if p.key() = k then
            return p
        return end
        { there is no entry with key equal to k}



Algorithm put(k, v):
    Input: A key-value pair (k, v)
    Output: The position of the inserted/modified entry
    for each position p ∈ [L.begin(), L.end()) do
        if p.key() = k then
            *p ← (k, v)
            return p
        {return the position of the modified entry}
        p ← L.insertBack((k, v))
        n ← n + 1
        {increment variable storing number of entries}
        return p
        {return the position of the inserted entry}


Algorithm erase(k):
    Input: A key k
    Output: None
    for each position p ∈ [L.begin(), L.end()) do
        if p.key() = k then
            L.erase(p)
            n ← n − 1
        {decrement variable storing number of entries}

Code Fragment 9.4: Algorithms for find, put, and erase for a map stored in a list L.




Algorithm find(k):
    Output: The position of the matching entry of the map, or end if there is no key
    k in the map
        return A[h(k)].find(k) {delegate the find(k) to the list-based map at A[h(k)]}

Algorithm put(k, v):
    p ← A[h(k)].put(k, v) {delegate the put to the list-based map at A[h(k)]}
    n ← n + 1
    return p

Algorithm erase(k):
    Output: None
    A[h(k)].erase(k) {delegate the erase to the list-based map at A[h(k)]}
    n ← n − 1

Code Fragment 9.5: The fundamental functions of the map ADT, implemented with
a hash table that uses separate chaining to resolve collisions among its n entries.

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
