#include <iostream>
#include "GenericSinglyLinkedList.h"

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

// Exception thrown on performing top or pop of an empty stack.
class StackEmpty : public RuntimeException
{
public:
    StackEmpty(const string& err) : RuntimeException(err) {}
};




typedef string Elem;
// stack element type
class LinkedStack
{
// stack as a linked list
public:
    LinkedStack();
// constructor
    int size() const;
// number of items in the stack
    bool empty() const;
// is the stack empty?
    Elem top() const; // the top element
    void push(const Elem& e);
// push element onto stack
    void pop();
// pop the stack
private:
// member data
    SLinkedList<Elem> S;
// linked list of elements
    int n;
// number of elements
};


LinkedStack::LinkedStack()
    : S(), n(0) { } // constructor
int LinkedStack::size() const
{
    return n;    // number of items in the stack
}
bool LinkedStack::empty() const
{
    return n == 0;    // is the stack empty?
}



// get the top element
Elem LinkedStack::top() const
{
    if (empty())
        throw StackEmpty("Top of empty stack");
    return S.front();
}
void LinkedStack::push(const Elem& e)   // push element onto stack
{
    ++n;
    S.addFront(e);
}
// pop the stack
void LinkedStack::pop()
{
    if (empty())
        throw StackEmpty("Pop from empty stack");
    --n;
    S.removeFront();
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
