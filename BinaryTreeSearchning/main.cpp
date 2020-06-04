#include <iostream>

using namespace std;


Algorithm TreeSearch(k, v):
    if T.isExternal(v) then
        return v
    if k < key(v) then
        return TreeSearch(k, T.left(v))
    else if k > key(v) then
        return TreeSearch(k, T.right(v))
    return v {we know k = key(v)}


Algorithm TreeInsert(k, x, v):
    Input: A search key k, an associated value, x, and a node v of T
    Output: A new node w in the subtree T (v) that stores the entry (k, x)
    w ← TreeSearch(k, v)
    if T.isInternal(w) then
        return TreeInsert(k, x, T.left(w)) {going to the right would be correct too}
    T .insertAtExternal(w, (k, x)){this is an appropriate place to put (k, x)}
    return w



int main()
{
    cout << "Hello  world!" << endl;
    return 0;
}
