#include <iostream>

using namespace std;

typedef string Elem;
class DNode  // doubly linked list node
{
private:
    Elem elem;//node element value
    DNode* prev;//previous node in list
    DNode* next;//next node in list
    friend class DLinkedList;//allow DLinkedList access
};


class DLinkedList// doubly linked list
{
public:
    DLinkedList();//constructor
    ~DLinkedList();//destructor
    bool empty() const;//is list empty?
    const Elem& front() const;//get front element
    const Elem& back() const;//get back element
    void addFront(const Elem& e);//add to front of list
    void addBack(const Elem& e);//add to back of list
    void removeFront();//remove from front
    void removeBack();//remove from back
private://local type definitions
    DNode* header;//list sentinels
    DNode* trailer;
protected:// local utilities
    void add(DNode* v, const Elem& e);// insert new node before v
    void remove(DNode* v);// remove node v
};


DLinkedList::DLinkedList() // constructor
{
    header = new DNode;// create sentinels
    trailer = new DNode;
    header->next = trailer;// have them point to each other
    trailer->prev = header;
}

DLinkedList::~DLinkedList()// destructor
{
    while (!empty())
        removeFront();// remove all but sentinels
    delete header;// remove the sentinels
    delete trailer;
}

bool DLinkedList::empty() const
{
    return (header->next == trailer);    // is list empty?
}
const Elem& DLinkedList::front() const
{
    return header->next->elem;    // get front element
}
const Elem& DLinkedList::back() const
{
    return trailer->prev->elem;    // get back element
}

//insert new node before v
void DLinkedList::add(DNode* v, const Elem& e)
{
    DNode* u = new DNode;
    u->elem = e; //create a new node for e
    u->next = v;//link u in between v
    u->prev = v->prev;//. . .and v->prev
    v->prev->next = v->prev = u;
}


void DLinkedList::addFront(const Elem& e) // add to front of list
{
    add(header->next, e);
}
void DLinkedList::addBack(const Elem& e) // add to back of list
{
    add(trailer, e);
}

void DLinkedList::remove(DNode* v)//remove node v
{
    DNode* u = v->prev;//predecessor
    DNode* w = v->next;//successor
    u->next = w;//unlink v from list
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront()
{
    remove(header->next);    // remove from font
}
void DLinkedList::removeBack()
{
    remove(trailer->prev);    // remove from back
}

//Reversing a Linked List
void listReverse(DLinkedList& L)// reverse a list
{
    DLinkedList T;// temporary list
    while (!L.empty())// reverse L into T
    {
        string s = L.front();
        L.removeFront();
        T.addFront(s);
    }
    while (!T.empty())// copy T back to L
    {
        string s = T.front();
        T.removeFront();
        L.addBack(s);
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
