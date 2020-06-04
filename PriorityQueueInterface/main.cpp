#include <iostream>

using namespace std;


template <typename E, typename C>// element and comparator
class PriorityQueue// priority-queue interface
{
public:
    int size() const;//number of elements
    bool isEmpty() const;//is the queue empty?
    void insert(const E& e);//insert element
    const E& min() const;//minimum  element
    void removeMin();//remove minimum
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
