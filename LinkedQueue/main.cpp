#include <iostream>
#include "CircleList.h"

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



class QueueEmpty : public RuntimeException
{
public:
    QueueEmpty(const string& err) : RuntimeException(err) { }
};



typedef string Elem;
// queue element type
class LinkedQueue
{
// queue as doubly linked list
public:
    LinkedQueue();
// constructor
// number of items in the queue
    int size() const;
    bool empty() const;
// is the queue empty?
    const Elem& front() const; // the front element
    void enqueue(const Elem& e);
// enqueue element at rear
    void dequeue();
// dequeue element at front
private:
// member data
    CircleList C;
// circular list of elements
    int n;
// number of elements
};


LinkedQueue::LinkedQueue()
    : C(), n(0) { } // constructor
int LinkedQueue::size() const
{
    return n;    // number of items  in the queue
}
bool LinkedQueue::empty() const
{
    return n == 0;    // is the queue empty?
}
// get the front element
const Elem& LinkedQueue::front() const
{
    if (empty())
        throw QueueEmpty("front of empty queue");
    return C.front();
// list front is queue front
}


// enqueue element at rear
void LinkedQueue::enqueue(const Elem& e)
{
    C.add(e);
// insert after cursor
    C.advance();
// . . .and advance
    n++;
}
// dequeue element at front
void LinkedQueue::dequeue()
{
    if (empty())
        throw QueueEmpty("dequeue of empty queue");
    C.remove();
// remove from list front
    n--;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
