#include <iostream>

using namespace std;

int depth(const Tree& T, const Position& p)
{
    if (p.isRoot())
        return 0;
// root has depth 0
    else
        return 1 + depth(T, p.parent());
// 1 + (depth of parent)
}


int height2(const Tree& T, const Position& p)
{
    if (p.isExternal())
        return 0;
// leaf has height 0
    int h = 0;
    PositionList ch = p.children();
// list of children
    for (Iterator q = ch.begin(); q != ch.end(); ++q)
        h = max(h, height2(T, *q));
    return 1 + h;
// 1 + max height of children
}


//Method preorderPrint(T, p) that performs a preorder printing
//of the elements in the subtree associated with position p of T .
void preorderPrint(const Tree& T, const Position& p)
{
    cout << *p;
// print element
    PositionList ch = p.children();
// list of children
    for (Iterator q = ch.begin(); q != ch.end(); ++q)
    {
        cout << " ";
        preorderPrint(T, *q);
    }
}

void postorderPrint(const Tree& T, const Position& p)
{
    PositionList ch = p.children();
// list of children
    for (Iterator q = ch.begin(); q != ch.end(); ++q)
    {
        postorderPrint(T, *q);
        cout << " ";
    }
    cout << *p;
// print element
}


int diskSpace(const Tree& T, const Position& p)
{
    int s = size(p);
// start with size of p
    if (!p.isExternal())
    {
// if p is internal
        PositionList ch = p.children();
// list of p’s children
        for (Iterator q = ch.begin(); q != ch.end(); ++q)
            s += diskSpace(T, *q);
// sum the space of subtrees
        cout << name(p) << ": " << s << endl; // print summary
    }
    return s;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
