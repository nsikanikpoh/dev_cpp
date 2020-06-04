#ifndef CIRCLELIST_H_INCLUDED
#define CIRCLELIST_H_INCLUDED
#include <string>
using namespace std;

typedef string Elem;// element type
class CNode// circularly linked list node
{
private:
    Elem elem;// linked list element value
    CNode* next;// next item in the list
    friend class CircleList;// provide CircleList access
};

class CircleList// a circularly linked list
{
public:
    CircleList();//constructor
    ~CircleList();//destructor
    bool empty() const;//is list empty?
    const Elem& front() const;//element at cursor
    const Elem& back() const;//element following cursor
    void advance();//advance cursor
    void add(const Elem& e);//add after cursor
    void remove();//remove node after cursor
    void print_list();//prints the list container
private:
    CNode* cursor;// the cursor
};

CircleList::CircleList()// constructor
    : cursor(NULL) { }
CircleList::~CircleList()// destructor
{
    while (!empty())
        remove();
}

bool CircleList::empty() const// is list empty?
{
    return cursor == NULL;
}
const Elem& CircleList::back() const// element at cursor
{
    return cursor->elem;
}
const Elem& CircleList::front() const// element following cursor
{
    return cursor->next->elem;
}
void CircleList::advance()// advance cursor
{
    cursor = cursor->next;
}


void CircleList::add(const Elem& e)// add after cursor
{
    CNode* v = new CNode;// create a new node
    v->elem = e;
    if (cursor == NULL)// list is empty?
    {
        v->next = v;// v points to itself
        cursor = v;// cursor points to v
    }
    else
    {
        v->next = cursor->next;// list is nonempty?
        cursor->next = v;// link in v after cursor
    }
}

void CircleList::remove()//remove node after cursor
{
    CNode* old = cursor->next;//the node being removed
    if (old == cursor)//removing the only node?
        cursor = NULL;//list is now empty
    else
        cursor->next = old->next;// link out the old node
    delete old;//delete the old node
}

void CircleList::print_list()
{
    CNode *tmp = cursor->next;//the node being removed
    while(tmp->next != cursor->next)
    {
        cout << tmp->elem << "\n";
        tmp=tmp->next;
    }
    cout << back()  << "*" << endl;//print the cursor element with indicator
}



#endif // CIRCLELIST_H_INCLUDED
