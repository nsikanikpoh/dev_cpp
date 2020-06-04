#include <iostream>

using namespace std;


Algorithm binaryPreorder(T, p):
    perform the “visit” action for node p
    if p is an internal node then
        binaryPreorder(T, p.left())
    {
        recursively traverse left subtree
    }
binaryPreorder(T, p.right())
{
    recursively traverse right subtree
}




Algorithm binaryPostorder(T, p):
    if p is an internal node then
    binaryPostorder(T, p.left())
{
    recursively traverse left subtree
}
{
    recursively traverse right subtree
}
binaryPostorder(T, p.right())
perform the “visit” action for the node p




Algorithm evaluateExpression(T, p):
        if p is an internal node then
{

    x ← evaluateExpression(T, p.left())
        y ← evaluateExpression(T, p.right())
        Let ◦ be the operator associated with p
        return x ◦ y
    }
    else
        return the value stored at p




Algorithm inorder(T, p):
     if p is an internal node then
        inorder(T, p.left())
        {
            recursively traverse left subtree
        }
      perform the “visit” action for node p
    if p is an internal node then
    inorder(T, p.right())
    {
        recursively traverse right subtree
    }
Code Fragment 7.27:
Algorithm inorder for performing the inorder traversal of the
subtree of a binary tree T rooted at a node p.




int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
