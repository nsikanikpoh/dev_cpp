#include <iostream>

using namespace std;


template <typename E>
class CompleteTree
{
// left-complete tree interface
public:
// publicly accessible types
    class Position;
// node position type
    int size() const;
// number of elements
    Position left(const Position& p);
// get left child
    Position right(const Position& p);
// get right child
    Position parent(const Position& p);
// get parent
    bool hasLeft(const Position& p) const; // does node have left child?
    bool hasRight(const Position& p) const; // does node have right child?
    bool isRoot(const Position& p) const;
// is this the root?
    Position root();
// get root position
    Position last();
// get last node
    void addLast(const E& e);
// add a new last node
    void removeLast();
// remove the last node
    void swap(const Position& p, const Position& q); // swap node contents
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
