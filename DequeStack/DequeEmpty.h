#ifndef DEQUEEMPTY_H_INCLUDED
#define DEQUEEMPTY_H_INCLUDED
#include <string>

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


class StackEmpty : public RuntimeException
{
public:
    StackEmpty(const string& err) : RuntimeException(err) { }
};




#endif // DEQUEEMPTY_H_INCLUDED
