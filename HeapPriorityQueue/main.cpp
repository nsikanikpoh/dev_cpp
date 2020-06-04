#include <iostream>
#include "VectorCompleteTree.h"

using namespace std;


template <typename E, typename C>
class HeapPriorityQueue
{
public:
    int size() const;//number of elements
    bool empty() const;//is the queue empty?
    void insert(const E& e);//insert element
    const E& min();//minimum element
    void removeMin();//remove minimum
private:
    VectorCompleteTree<E> T;// priority queue contents
    C isLess;// shortcut for tree position
    typedef typename VectorCompleteTree<E>::Position Position;
};


template <typename E, typename C>
int HeapPriorityQueue<E,C>::size() const
{
    return T.size();
}
// number of elements
template <typename E, typename C>
// is the queue empty?
bool HeapPriorityQueue<E,C>::empty() const
{
    return size() == 0;
}
template <typename E, typename C>
// minimum element
const E& HeapPriorityQueue<E,C>::min()
{
    return *(T.root());// return reference to root element
}




// insert element
template <typename E, typename C>
void HeapPriorityQueue<E,C>::insert(const E& e)
{
    T.addLast(e);// add e to heap
    Position v = T.last();// e’s position
    while (!T.isRoot(v))
    {
        // up-heap bubbling
        Position u = T.parent(v);
        if (!isLess(*v, *u))
            break;// if v in order, we’re done
        T.swap(v, u);// . . .else swap with parent
        v = u;
    }
}



// remove minimum
template <typename E, typename C>
void HeapPriorityQueue<E,C>::removeMin()
{
    if (size() == 1)// only one node?
        T.removeLast();// . . .remove it
    else
    {
        Position u = T.root();// root position
        T.swap(u, T.last());// swap last with root
        T.removeLast();// . . .and remove last
        while (T.hasLeft(u))
        {// down-heap bubbling
            Position v = T.left(u);
            if (T.hasRight(u) && isLess(*(T.right(u)), *v))
                v = T.right(u);// v is u’s smaller child
            if (isLess(*v, *u))
            {// is u out of order?
                T.swap(u, v);// . . .then swap
                u = v;
            }
            else
                break;// else we’re done
        }
    }
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
