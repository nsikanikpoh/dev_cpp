#include <iostream>
#include <cassert>

class IntList
{
private:
    int m_list[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // give this class some initial state for this example

public:
    int& operator[] (int index);
    const int& operator[] (int index) const;
};

int& IntList::operator[] (int index) // for non-const objects: can be used for assignment
{
    assert(index >= 0 && index < 10);
    return m_list[index];
}

const int& IntList::operator[] (int index) const // for const objects: can only be used for access
{
    assert(index >= 0 && index < 10);
    return m_list[index];
}

int main()
{
    IntList list;
    list[2] = 9; // okay: calls non-const version of operator[]
    std::cout << list[2] << '\n';

    const IntList clist;
    //  clist[2] = 3; // compile error: calls const version of operator[], which returns a const reference.  Cannot assign to this.
    std::cout << clist[2] << '\n';
    return 0;
}
