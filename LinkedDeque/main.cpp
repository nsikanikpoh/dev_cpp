#include <iostream>
#include "DLinkedList.h"


using namespace std;


class RuntimeException
{
// generic run-time exception
private:
    string errorMsg;
public:
    RuntimeException(const string& err)
    {
        errorMsg = err;
    }
    string getMessage() const
    {
        return errorMsg;
    }
};



class DequeEmpty : public RuntimeException
{
public:
    DequeEmpty(const string& err) : RuntimeException(err) { }
};




typedef string Elem;
// deque element type
class LinkedDeque
{
// deque as doubly linked list
public:
    LinkedDeque();
// constructor
    int size() const;
// number of items in the deque
    bool empty() const;
// is the deque empty?
    const Elem& front() const; // the first element
    const Elem& back() const; // the last element
// insert new first element
    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
// insert new last element
    void removeFront(); // remove first element
    void removeBack(); // remove last element
private:
// member data
    DLinkedList D;
// linked list of elements
    int n;
// number of elements
};



LinkedDeque::LinkedDeque()
    : D(), n(0) { } // constructor
int LinkedDeque::size() const
{
    return n;    // number of items in the queue
}
bool LinkedDeque::empty() const
{
    return n == 0;    // is the queue empty?
}
// get the front element
const Elem& LinkedDeque::front() const
{
    if (empty())
        throw DequeEmpty("front of empty deque");
    return D.front();
// list front is queue front
}

// get the front element
const Elem& LinkedDeque::back() const
{
    if (empty())
        throw DequeEmpty("back of empty deque");
    return D.back();
// list front is queue front
}



void LinkedDeque::insertFront(const Elem& e)
{
    D.addFront(e);
    n++;
}
// insert new last element
void LinkedDeque::insertBack(const Elem& e)
{
    D.addBack(e);
    n++;
}
// remove first element
void LinkedDeque::removeFront()
{
    if (empty())
        throw DequeEmpty("removeFront of empty deque");
    D.removeFront();
    n--;
}
// remove last element
void LinkedDeque::removeBack()
{
    if (empty())
        throw DequeEmpty("removeBack of empty deque");
    D.removeBack();
    n--;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
