#include <iostream>
#include <list>

using namespace std;

template <typename E, typename C>
class ListPriorityQueue
{
public:
    int size() const;//number of elements
    bool empty() const;//is the queue empty?
    void insert(const E& e);//insert element
    const E& min() const;//minimum element
    void removeMin();//remove minimum
private:
    std::list<E> L;// priority queue contents
    C isLess;// less-than comparator
};


template <typename E, typename C>
int ListPriorityQueue<E,C>::size() const
{
    return L.size();
}
// number of elements
template <typename E, typename C>
// is the queue empty?
bool ListPriorityQueue<E,C>::empty() const
{
    return L.empty();
}


// insert element
template <typename E, typename C>
void ListPriorityQueue<E,C>::insert(const E& e)
{
    typename std::list<E>::iterator p;
    p = L.begin();
    while (p != L.end() && !isLess(e, *p))
        ++p;
// find larger element
    L.insert(p, e);
// insert e before p
}


template <typename E, typename C>
const E& ListPriorityQueue<E,C>::min() const
{
    return L.front();    // minimum element
}
template <typename E, typename C>
void ListPriorityQueue<E,C>::removeMin() // remove minimum
{
    L.pop_front();   // minimum is at the front
}




int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
