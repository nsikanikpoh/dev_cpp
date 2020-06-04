#include <iostream>

using namespace std;


Algorithm restructure(x):
    Input: A node x of a binary search tree T that has both a parent y and a grand-
parent z
    Output: Tree T after a trinode restructuring (which corresponds to a single or
    double rotation) involving nodes x, y, and z

1: Let (a, b, c) be a left-to-right (inorder) listing of the nodes x, y, and z, and let
(T 0 , T 1 , T 2 , T 3 ) be a left-to-right (inorder) listing of the four subtrees of x, y, and
z not rooted at x, y, or z.
2: Replace the subtree rooted at z with a new subtree rooted at b.
3: Let a be the left child of b and let T 0 and T 1 be the left and right subtrees of a,
respectively.
4: Let c be the right child of b and let T 2 and T 3 be the left and right subtrees of c,
respectively.


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
