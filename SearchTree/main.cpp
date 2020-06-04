#include <iostream>
#include "LinkedBinaryTree.h"

using namespace std;


template <typename K, typename V>
class Entry//a (key, value) pair
{
public://public types
    typedef K Key;//key type
    typedef V Value;//value type
public://public functions
    Entry(const K& k = K(), const V& v = V())//constructor
        : _key(k), _value(v) { }
    const K& key() const//get key (read only)
    {
        return _key;
    }
    const V& value() const//get value (read only)
    {
        return _value;
    }
    void setKey(const K& k)//set key
    {
        _key = k;
    }
    void setValue(const V& v)//set value
    {
        _value = v;
    }
private://private data
    K _key;//key
    V _value;//value
};





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



class NonexistentElement : public RuntimeException
{
public:
    NonexistentElement(const string& err) : RuntimeException(err) { }
};




template <typename E>
class SearchTree  //a binary search tree
{
public://public types
    typedef typename E::Key K;//a key
    typedef typename E::Value V;//a value
    class Iterator;//an iterator/position
public://public functions
    SearchTree();//constructor
    int size() const;//number of entries
    bool empty() const;//is the tree empty?
    Iterator find(const K& k);//find entry with key k
    Iterator insert(const K& k, const V& x);//insert (k,x)
    void erase(const K& k);// remove key k entry
    void erase(const Iterator& p);//remove entry at p
    Iterator begin();//iterator to first entry
    Iterator end();//iterator to end entry
protected://local utilities
    typedef LinkedBinaryTree<E> BinaryTree;//linked binary tree
    typedef typename BinaryTree::Position TPos;//position in the tree
    TPos root() const;//get virtual root
    TPos finder(const K& k, const TPos& v);//find utility
    TPos inserter(const K& k, const V& x);//insert utility
    TPos eraser(TPos& v);//erase utility
    TPos restructure(const TPos& v);//restructure
private://member data
    BinaryTree T;//the binary tree
    int n;//number of entries
public:
// . . .insert Iterator class declaration here


    class Iterator
    {
        // an iterator/position
    private:
        TPos v;// which entry
    public:
        Iterator(const TPos& vv) : v(vv) { }// constructor
        const E& operator*() const// get entry (read only)
        {
            return *v;
        }
        E& operator*()// get entry (read/write)
        {
            return *v;
        }

        bool operator==(const Iterator& p) const// are iterators equal?
        {
            return v == p.v;
        }
        Iterator& operator++();// inorder successor
        friend class SearchTree;// give search tree access
    };

};


template <typename E>
typename SearchTree<E>::Iterator& SearchTree<E>::Iterator::operator++()// inorder successor
{
    TPos w = v.right();
    if (w.isInternal())// have right subtree?
    {
        do// move down left chain
        {
            v = w;
            w = w.left();
        }
        while (w.isInternal());
    }
    else
    {
        w = v.parent();// get parent
        while (v == w.right())// move up right chain
        {
            v = w;
            w = w.parent();
        }
        v = w;// and first link to left
    }
    return *this;
}


template <typename E>
SearchTree<E>::SearchTree() : T(), n(0)// constructor
{
    T.addRoot();    // create the super root
    T.expandExternal(T.root());
}

template <typename E>
typename SearchTree<E>::TPos SearchTree<E>::root() const// get virtual root
{
    return T.root().left();// left child of super root
}



template <typename E>
typename SearchTree<E>::Iterator SearchTree<E>::begin()// iterator to first entry
{
    TPos v = root();// start at virtual root
    while (v.isInternal())// find leftmost node
        v = v.left();
    return Iterator(v.parent());
}


template <typename E>
typename SearchTree<E>::Iterator SearchTree<E>::end()// iterator to end entry
{
    return Iterator(T.root());// return the super root
}


template <typename E>// find utility
typename SearchTree<E>::TPos SearchTree<E>::finder(const K& k, const TPos& v)
{
    if (v.isExternal())
        return v;// key not found
    if (k < v->key())
        return finder(k, v.left());// search left subtree
    else if (v->key() < k)
        return finder(k, v.right()); // search right subtree
    else
        return v;// found it here
}


template <typename E>
typename SearchTree<E>::Iterator SearchTree<E>::find(const K& k)  // find entry with key k
{
    TPos v = finder(k, root());// search from virtual root
    if (v.isInternal())
        return Iterator(v);// found it
    else
        return end();// didn’t find it
}


template <typename E>
typename SearchTree<E>::TPos SearchTree<E>::inserter(const K& k, const V& x)// insert utility
{
    TPos v = finder(k, root());//search from virtual root
    while (v.isInternal())//key already exists?
        v = finder(k, v.right());//look further
    T.expandExternal(v);//add new internal node
    v->setKey(k);//set entry
    v->setValue(x);//
    n++;//one more entry
    return v;//return insert position
}


template <typename E>// insert (k,x)
typename SearchTree<E>::Iterator SearchTree<E>::insert(const K& k, const V& x)
{
    TPos v = inserter(k, x);
    return Iterator(v);
}


template <typename E>// remove utility
typename SearchTree<E>::TPos SearchTree<E>::eraser(TPos& v)
{
    TPos w;
    if (v.left().isExternal())
        w = v.left();// remove from left
    else if (v.right().isExternal())
        w = v.right();// remove from right
    else
    {// both internal?
        w = v.right();// go to right subtree
        do
        {
            w = w.left();
        }
        while (w.isInternal());// get leftmost node
        TPos u = w.parent();
        v->setKey(u->key());
        v->setValue(u->value()); // copy w’s parent to v
    }
    n--;// one less entry
    return T.removeAboveExternal(w);// remove w and parent
}


/* SearchTreehEi :: */
template <typename E>// remove key k entry
void SearchTree<E>::erase(const K& k)
{
    TPos v = finder(k, root());// search from virtual root
    if (v.isExternal())// not found?
        throw NonexistentElement("Erase of nonexistent");
    eraser(v);// remove it
}

/* SearchTreehEi :: */

template <typename E>
void SearchTree<E>::erase(const Iterator& p)
{
    eraser(p.v);// erase entry  at p
}





int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
