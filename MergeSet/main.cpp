#include <iostream>
#include <list>

using namespace std;


template <typename E>
class Merge//generic Merge
{
public://global types
    typedef std::list<E> List;//list type
    void merge(List& A, List& B, List& C);//generic merge function
protected://local types
    typedef typename List::iterator Itor;//iterator type
    //overridden functions
    virtual void fromA(const E& a, List& C) = 0;
    virtual void fromBoth(const E& a, const E& b, List& C) = 0;
    virtual void fromB(const E& b, List& C) = 0;
};


// generic merge
template <typename E>
void Merge<E>::merge(List& A, List& B, List& C)
{
    Itor pa = A.begin();// A’s elements
    Itor pb = B.begin();// B’s elements
    while (pa != A.end() && pb != B.end())
    {
        // main merging loop
        if (*pa < *pb)
            fromA(*pa++, C);// take from A
        else if (*pa == *pb)
            fromBoth(*pa++, *pb++, C);// take from both
        else
            fromB(*pb++, C);// take from B
    }
    while (pa != A.end())
    {
        fromA(*pa++, C);// take rest from A
    }
    while (pb != B.end())
    {
        fromB(*pb++, C);// take rest from B
    }
}



template <typename E>// set union
class UnionMerge : public Merge<E>
{
protected:
    typedef typename Merge<E>::List List;
    virtual void fromA(const E& a, List& C)// add a
    {
        C.push_back(a);
    }
    virtual void fromBoth(const E& a, const E& b, List& C)// add a only
    {
        C.push_back(a);
    }
    virtual void fromB(const E& b, List& C)// add b
    {
        C.push_back(b);
    }
};


template <typename E>// set intersection
class IntersectMerge : public Merge<E>
{
protected:
    typedef typename Merge<E>::List List;
    virtual void fromA(const E& a, List& C)
    { }// ignore
    virtual void fromBoth(const E& a, const E& b, List& C)// add a only
    {
        C.push_back(a);
    }
    virtual void fromB(const E& b, List& C)
    { }// ignore
};


template <typename E>// set subtraction
class SubtractMerge : public Merge<E>
{
protected:
    typedef typename Merge<E>::List List;
    virtual void fromA(const E& a, List& C)// add a
    {
        C.push_back(a);
    }
    virtual void fromBoth(const E& a, const E& b, List& C)
    { }// ignore
    virtual void fromB(const E& b, List& C)
    { }// ignore
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
