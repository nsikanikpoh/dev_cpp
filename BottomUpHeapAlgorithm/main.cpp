#include <iostream>

using namespace std;


Algorithm BottomUpHeap(L):
Input: An STL list L storing n = 2 h+1 − 1 entries
Output: A heap T storing the entries of L.
if L.empty() then
return an empty heap
e ← L.front()
L.pop front()
Split L into two lists, L 1 and L 2 , each of size (n − 1)/2
T 1 ← BottomUpHeap(L 1 )
T 2 ← BottomUpHeap(L 2 )
Create binary tree T with root r storing e, left subtree T 1 , and right subtree T 2
Perform a down-heap bubbling from the root r of T , if necessary
return T



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
