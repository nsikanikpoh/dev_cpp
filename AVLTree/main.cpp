#include <iostream>

#include "SearchTree.h"

using namespace std;

template <typename E>
class AVLTree;


template <typename E>
class AVLEntry : public E
{
    // an AVL entry
private:
    int ht;// node height
protected:// local types
    typedef typename E::Key K;// key type
    typedef typename E::Value V;// value type
    int height() const
    {
        return ht;
    }// get height
    void setHeight(int h)
    {
        ht = h;
    }// set height
public:// public functions
    AVLEntry(const K& k = K(), const V& v = V()) // constructor
        : E(k,v), ht(0) { }
    friend class AVLTree<E>;// allow AVLTree access
};



// an AVL tree
template <typename E>
class AVLTree : public SearchTree< AVLEntry<E> >
{
public:// public types
    typedef AVLEntry<E> AVLEntryE;// an entry
    typedef typename SearchTree<AVLEntryE>::Iterator Iterator; // an iterator
protected:// local types
    typedef typename AVLEntryE::Key K;// a key
    typedef typename AVLEntryE::Value V;// a value
    typedef SearchTree<AVLEntryE> ST;// a search tree
    typedef typename ST::TPos TPos;// a tree position
public:// public functions
    AVLTree();// constructor
    Iterator insert(const K& k, const V& x);// insert (k,x)
    void erase(const K& k); // remove key k entry
    void erase(const Iterator& p);// remove entry at p
protected:// utility functions
    int height(const TPos& v) const;// node height utility
    void setHeight(TPos v);// set height utility
    bool isBalanced(const TPos& v) const;// is v balanced?
    TPos tallGrandchild(const TPos& v) const;// get tallest grandchild
    void rebalance(const TPos& v);// rebalance utility
};


template <typename E>
AVLTree<E>::AVLTree() : ST() { } // constructor


template <typename E>
int AVLTree<E>::height(const TPos& v) const
{
    return (v.isExternal() ? 0 : v->height());    // node height utility
}



template <typename E>
void AVLTree<E>::setHeight(TPos v)// set height utility
{
    int hl = height(v.left());
    int hr = height(v.right());
    v->setHeight(1 + std::max(hl, hr));// max of left & right
}


/* AVLTreehEi :: */
template <typename E>
bool AVLTree<E>::isBalanced(const TPos& v) const// is v balanced?
{
    int bal = height(v.left()) - height(v.right());
    return ((-1 <= bal) && (bal <= 1));
}

/* AVLTreehEi :: */
template <typename E>
typename AVLTree<E>::TPos AVLTree<E>::tallGrandchild(const TPos& z) const// get tallest grandchild
{
    TPos zl = z.left();
    TPos zr = z.right();
    if (height(zl) >= height(zr))// left child taller
        if (height(zl.left()) >= height(zl.right()))
            return zl.left();
        else
            return zl.right();
    else // right child taller
        if (height(zr.right()) >= height(zr.left()))
            return zr.right();
        else
            return zr.left();
}


/* AVLTreehEi :: */
template <typename E>
void AVLTree<E>::rebalance(const TPos& v)// rebalancing utility
{
    TPos z = v;
    while (!(z == ST::root()))// rebalance up to root
    {
        z = z.parent();
        setHeight(z);// compute new height
        if (!isBalanced(z))// restructuring needed
        {
            TPos x = tallGrandchild(z);
            z = restructure(x);// trinode restructure
            setHeight(z.left());// update heights
            setHeight(z.right());
            setHeight(z);
        }
    }
}

/* AVLTreehEi :: */
template <typename E>
typename AVLTree<E>::Iterator AVLTree<E>::insert(const K& k, const V& x)// insert (k,x)
{
    TPos v = inserter(k, x);// insert in base tree
    setHeight(v);// compute its height
    rebalance(v);// rebalance if needed
    return Iterator(v);
}




/* AVLTreehEi :: */
template <typename E>
void AVLTree<E>::erase(const K& k)// remove key k entry
{
    TPos v = finder(k, ST::root());// find in base tree
    if (Iterator(v) == ST::end())// not found?
        throw NonexistentElement("Erase of nonexistent");
    TPos w = eraser(v);// remove it
    rebalance(w);// rebalance if needed
}

template <typename E>
void AVLTree<E>::erase(const Iterator& p)
{
   TPos w = eraser(p.v);// erase entry at p
   rebalance(w);// rebalance if needed
}

//implement Restructuring



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
