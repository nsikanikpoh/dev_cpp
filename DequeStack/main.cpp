#include <iostream>
#include "DequeEmpty.h"
#include "LinkedDeque.h"


using namespace std;


typedef string Elem;
// element type
class DequeStack
{
// stack as a deque
public:
    DequeStack();
// constructor
// number of elements
    int size() const;
    bool empty() const;
// is the stack empty?
    const Elem& top() const; // the top element
    void push(const Elem& e);
// push element onto stack
    void pop();
// pop the stack
private:
    LinkedDeque D;
// deque of elements
};


DequeStack::DequeStack()
    : D() { }
int DequeStack::size() const
{
    return D.size();
}
// constructor
// number of elements
// is the stack empty?
bool DequeStack::empty() const
{
    return D.empty();
}
// the top element
const Elem& DequeStack::top() const
{
    if (empty())
        throw StackEmpty("top of empty stack");
    return D.front();
}
// push element onto stack
void DequeStack::push(const Elem& e)
{
    D.insertFront(e);
}
// pop the stack
void DequeStack::pop()
{
    if (empty())
        throw StackEmpty("pop of empty stack");
    D.removeFront();
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
