#include <iostream>

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

template <typename E>
class Queue
{
public:
    int size() const;
    bool empty() const;
    const E& front() const;
    void enqueue (const E& e);
    void dequeue();
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
