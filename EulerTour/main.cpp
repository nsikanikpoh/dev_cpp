#include <iostream>
#include "LinkedBinaryTree.h"

using namespace std;


template <typename E, typename R>
// element and result types
class EulerTour
{
// a template for Euler tour
protected:
    struct Result
    {
// stores tour results
        R leftResult;
// result from left subtree
        R rightResult;
// result from right subtree
        R finalResult;
// combined result
    };
    typedef LinkedBinaryTree BinaryTree;
// the tree
    typedef typename BinaryTree::Position Position; // a position in the tree
protected:
// data member
    const BinaryTree* tree;
// pointer to the tree
public:
    void initialize(const BinaryTree& T)
// initialize
    {
        tree = &T;
    }
protected:
// local utilities
    int eulerTour(const Position& p) const; // perform the Euler tour
// functions given by subclasses
    virtual void visitExternal(const Position& p, Result& r) const {}
    virtual void visitLeft(const Position& p, Result& r) const {}
    virtual void visitBelow(const Position& p, Result& r) const {}
    virtual void visitRight(const Position& p, Result& r) const {}

    Result initResult() const
    {
        return Result();
    }

    int result(const Result& r) const
    {
        return r.finalResult;
    }
};



template <typename E, typename R>
// do the tour
int EulerTour<E, R>::eulerTour(const Position& p) const
{
    Result r = initResult();
    if (p.isExternal())
    {
// external node
        visitExternal(p, r);
    }
// internal node
    else
    {
        visitLeft(p, r);
        r.leftResult = eulerTour(p.left());
// recurse on left
        visitBelow(p, r);
        r.rightResult = eulerTour(p.right());
// recurse on right
        visitRight(p, r);
    }
    return result(r);
}



template <typename E, typename R>
class EvaluateExpressionTour : public EulerTour<E, R>
{
protected:
// shortcut type names
    typedef typename EulerTour<E, R>::BinaryTree BinaryTree;
    typedef typename EulerTour<E, R>::Position Position;
    typedef typename EulerTour<E, R>::Result Result;
public:
    void execute(const BinaryTree& T)
    {
// execute the tour
        initialize(T);
        std::cout << "The value is: " << eulerTour(T.root()) << "\n";
    }
protected:
// leaf: return value
    virtual void visitExternal(const Position& p, Result& r) const
    {
        r.finalResult = (*p).value();
    }
// internal: do operation
    virtual void visitRight(const Position& p, Result& r) const
    {
        r.finalResult = (*p).operation(r.leftResult, r.rightResult);
    }
};

template <typename E, typename R>
class PrintExpressionTour : public EulerTour<E, R>
{
protected: // . . .same type name shortcuts as in EvaluateExpressionTour
public:
    void execute(const LinkedBinaryTree& T)
    {
// execute the tour
        initialize(T);
        cout << "Expression: ";
        eulerTour(T.root());
        cout << endl;
    }
protected:
// leaf: print value
    virtual void visitExternal(const Position& p, Result& r) const
    {
        (*p).print();
    }
// left: open new expression
    virtual void visitLeft(const Position& p, Result& r) const
    {
        cout << "(";
    }
// below: print operator
    virtual void visitBelow(const Position& p, Result& r) const
    {
        (*p).print();
    }
// right: close expression
    virtual void visitRight(const Position& p, Result& r) const
    {
        cout << ")";
    }
};





int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
