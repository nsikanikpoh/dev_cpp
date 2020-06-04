#include <iostream>
#include <list>

using namespace std;



template <typename E, typename C>
class AdaptPriorityQueue  // adaptable priority queue
{
protected:
    typedef std::list<E> ElementList;// list of elements
public:
// . . .insert Position class definition here
    class Position  // a position in the queue
    {
    private:
        typename ElementList::iterator q;// a position in the list
    public:
        const E& operator*()
        {
            return *q;    // the element at this position
        }
        friend class AdaptPriorityQueue;// grant access
    };

public:
    int size() const;// number of elements
    bool empty() const;// is the queue empty?
    const E& min() const;// minimum element
    Position insert(const E& e);// insert element
    void removeMin();// remove minimum
    void remove(const Position& p);// remove at position p
    Position replace(const Position& p, const E& e); // replace at position p
private:
    ElementList L;// priority queue contents
    C isLess;// less-than comparator
};


template <typename E, typename C>
int AdaptPriorityQueue<E,C>::size() const
{
    return L.size();
}
// number of elements
template <typename E, typename C>
// is the queue empty?
bool AdaptPriorityQueue<E,C>::empty() const
{
    return L.empty();
}


template <typename E, typename C>
const E& AdaptPriorityQueue<E,C>::min() const
{
    return L.front();    // minimum element
}
template <typename E, typename C>
void AdaptPriorityQueue<E,C>::removeMin() // remove minimum
{
    L.pop_front();   // minimum is at the front
}




template <typename E, typename C>
typename AdaptPriorityQueue<E,C>::Position
AdaptPriorityQueue<E,C>::insert(const E& e)// insert element
{
    typename ElementList::iterator p = L.begin();
    while (p != L.end() && !isLess(e, *p))
        ++p;// find larger element
    L.insert(p, e);// insert before p
    Position pos;
    pos.q = --p;
    return pos;// inserted position
}


// remove at position p
template <typename E, typename C>
void AdaptPriorityQueue<E,C>::remove(const Position& p)
{
    L.erase(p.q);
}

template <typename E, typename C>// replace at position p
typename AdaptPriorityQueue<E,C>::Position
AdaptPriorityQueue<E,C>::replace(const Position& p, const E& e)
{
    L.erase(p.q);// remove the old entry
    return insert(e);// insert replacement
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
