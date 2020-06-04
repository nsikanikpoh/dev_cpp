#include <iostream>

using namespace std;


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
