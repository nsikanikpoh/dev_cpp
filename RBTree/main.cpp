#include <iostream>
#include "SearchTree.h"


using namespace std;

template <typename E>
class RBTree;

enum Color // node colors
{
    RED,
    BLACK
};

template <typename E>
class RBEntry : public E// a red-black entry
{
private:
    Color col;// node color
protected:// local types
    typedef typename E::Key K;// key type
    typedef typename E::Value V;// value type
    Color color() const// get color
    {
        return col;
    }
    bool isRed() const
    {
        return col == RED;
    }
    bool isBlack() const
    {
        return col == BLACK;
    }
    void setColor(Color c)
    {
        col = c;
    }
public:// public functions
    RBEntry(const K& k = K(), const V& v = V()) // constructor
        : E(k,v), col(BLACK) { }
    friend class RBTree<E>;// allow RBTree access
};


// a red-black tree
template <typename E>
class RBTree : public SearchTree< RBEntry<E> >
{
public:// public types
    typedef RBEntry<E> RBEntryE;// an entry
    typedef typename SearchTree<RBEntryE>::Iterator Iterator; // an iterator
protected:// local types
    typedef typename RBEntryE::Key K;// a key
    typedef typename RBEntryE::Value V;// a value
    typedef SearchTree<RBEntryE> ST;// a search tree
    typedef typename ST::TPos TPos;// a tree position
public:// public functions
    RBTree();// constructor
    Iterator insert(const K& k, const V& x);// insert (k,x)
    void erase(const K& k); // remove key k entry
    void erase(const Iterator& p);// remove entry at p
protected:// utility functions// fix double-red z
    void remedyDoubleRed(const TPos& z);
    void remedyDoubleBlack(const TPos& r);// fix double-black r
// . . .(other utilities omitted)
};


/* RBTreehEi :: */
template <typename E>
typename RBTree<E>::Iterator RBTree<E>::insert(const K& k, const V& x)// insert (k,x)
{
    TPos v = inserter(k, x);// insert in base tree
    if (v == ST::root())
        setBlack(v);// root is always black
    else
    {
        setRed(v);
        remedyDoubleRed(v);// rebalance if needed
    }
    return Iterator(v);
}


/* RBTreehEi :: */
template <typename E>
void RBTree<E>::remedyDoubleRed(const TPos& z)// fix double-red z
{
    TPos v = z.parent();//v is z’s parent
    if (v == ST::root() || v->isBlack())//v is black, all ok
        return;//z, v are double-red

    if (sibling(v)->isBlack())//Case 1:restructuring
    {
        v = restructure(z);
        setBlack(v);// top vertex now black
        setRed(v.left());// set children red
        setRed(v.right());
    }
    else// Case 2: recoloring
    {
        setBlack(v);// set v and sibling black
        setBlack(sibling(v));
        TPos u = v.parent();// u is v’s parent
        if (u == ST::root())
            return;
        setRed(u);// make u red
        remedyDoubleRed(u);// may need to fix u now
    }
}




/* RBTreehEi :: */
template <typename E>// remove key k entry
void RBTree<E>::erase(const K& k)
{
    TPos u = finder(k, ST::root());// find the node
    if (Iterator(u) == ST::end())
        throw NonexistentElement("Erase of nonexistent");
    TPos r = eraser(u);// remove u
    if (r == ST::root() || r->isRed() || wasParentRed(r))
        setBlack(r);// fix by color change
    else// r, parent both black
        remedyDoubleBlack(r);// fix double-black r
}

/* RBTreehEi :: */
template <typename E>
void RBTree<E>::remedyDoubleBlack(const TPos& r)// fix double-black r
{
    TPos x = r.parent();// r’s parent
    TPos y = sibling(r);// r’s sibling
    if (y->isBlack())// Case 1: restructuring
    {
        if (y.left()->isRed() || y.right()->isRed())
        {
            TPos z = (y.left()->isRed() ? y.left() : y.right());// z is y’s red child
            Color topColor = x->color();// save top vertex color
            z = restructure(z);// restructure x,y,z
            setColor(z, topColor);// give z saved color
            setBlack(r);// set r black
            setBlack(z.left());
            setBlack(z.right());// set z’s children black
        }
        else// Case 2: recoloring
        {
            setBlack(r);// r=black, y=red
            setRed(y);
            if (x->isBlack() && !(x == ST::root()))
                remedyDoubleBlack(x);// fix double-black x
            setBlack(x);
        }
    }

    else
    {// Case 3: adjustment
        TPos z = (y == x.right() ? y.right() : y.left()); // grandchild on y’s side
        restructure(z);// restructure x,y,z
        setBlack(y);
        setRed(x);// y=black, x=red
        remedyDoubleBlack(r);// fix r by Case 1 or 2
    }

}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
