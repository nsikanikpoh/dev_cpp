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
Code Fragment 7.24:
Algorithm binaryPreorder, which performs the preorder
traversal of the subtree of a binary tree T rooted at node p.



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

Code Fragment 7.25:
Algorithm binaryPostorder for performing the postorder
    traversal of the subtree of a binary tree T rooted at node p.





    Algorithm evaluateExpression(T, p):
            if p is an internal node then
            x ← evaluateExpression(T, p.left())
                y ← evaluateExpression(T, p.right())
                Let ◦ be the operator associated with p
                return x ◦ y
                       else
                           return the value stored at p

              Code Fragment 7.26:
                                  Algorithm evaluateExpression for evaluating the expression
                                  represented by the subtree of an arithmetic-expression tree T rooted at node p.





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





“On the left” action:
if the node is internal, print “(”
   • “From below” action: print the value or operator stored at the node
   • “On the right” action:
   if the node is internal, print “)
            ”
    Algorithm printExpression(T, p):
        if p.isExternal()
            then
            print the value stored at p
        else
            print “(”
          printExpression(T, p.left())
          print the operator stored at p
          printExpression(T, p.right())
          print “)”
Code Fragment 7.29:
An algorithm for printing the arithmetic expression associated
with the subtree of an arithmetic-expression tree T rooted at p.



Algorithm templateEulerTour(T, p):
r ← initResult()
if p.isExternal() then
r.finalResult ← visitExternal(T, p, r)
else
visitLeft(T, p, r)
r.leftResult ← templateEulerTour(T, p.left())
visitBelow(T, p, r)
r.rightResult ← templateEulerTour(T, p.right())
visitRight(T, p, r)
return returnResult(r)
Code Fragment 7.30: Function templateEulerTour for computing a generic Euler
tour traversal of the subtree of a binary tree T rooted at a node p, following the
template function pattern. This function calls the functions initResult, visitExter-
nal, visitLeft, visitBelow, visitRight, and returnResult.

    int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
