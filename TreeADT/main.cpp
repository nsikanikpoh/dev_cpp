#include <iostream>

using namespace std;


template <typename E>// base element type
class Position<E>// a node position
{
public:
    E& operator*();//get element
    Position parent() const;//get parent
    PositionList children() const;//get node’s children
    bool isRoot() const;//root node?
    bool isExternal() const;//external node?
};

template <typename E>// base element type
class Tree<E>
{
public://public types
    class Position;//a node position
    class PositionList;//a list of positions
public://public functions
    int size() const;//number of nodes
    bool empty() const;//is tree empty?
    Position root() const;//get the root
    PositionList positions() const;//get positions of all nodes
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
