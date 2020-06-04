#include <iostream>
#include <list>
#include <vector>
#include "Entry.h"

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



class NonexistentElement : public RuntimeException
{
public:
    NonexistentElement(const string& err) : RuntimeException(err) { }
};





template <typename K, typename V, typename H>
class HashMap
{
public:// public types
    typedef Entry<const K,V> EntryClass;//a (key,value) pair
    class Iterator;//a iterator/position
public://public functions
    HashMap(int capacity = 100);//constructor
    int size() const;// number of entries
    bool empty() const;//is the map empty?
    Iterator find(const K& k);//find entry with key k
    Iterator put(const K& k, const V& v);//insert/replace (k,v)
    void erase(const K& k);//remove entry with key k
    void erase(const Iterator& p);//erase entry at p
    Iterator begin();//iterator to first entry
    Iterator end();//iterator to end entry
protected://protected types
    typedef std::list<EntryClass> Bucket;//a bucket of entries
    typedef std::vector<Bucket> BktArray;//a bucket array
// . . .insert HashMap utilities here
    Iterator finder(const K& k);// find utility
    Iterator inserter(const Iterator& p, const EntryClass& e); // insert utility
    void eraser(const Iterator& p);// remove utility
    typedef typename BktArray::iterator BItor;// bucket iterator
    typedef typename Bucket::iterator EItor;// entry iterator
    static void nextEntry(Iterator& p)// bucket’s next entry
    {
        ++p.ent;
    }
    static bool endOfBkt(const Iterator& p)// end of bucket?
    {
        return p.ent == p.bkt->end();
    }
private:
    int n;//number of entries
    H hash;//the hash comparator
    BktArray B;//bucket array
public://public types
// . . .insert Iterator class declaration here
    class Iterator
    {
        // an iterator (& position)
    private:
        EItor ent;// which entry
        BItor bkt;// which bucket
        const BktArray* ba;// which bucket array
    public:
        Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor())
            : ent(q), bkt(b), ba(&a) { }
        EntryClass& operator*() const;// get entry
        bool operator==(const Iterator& p) const;// are iterators equal?
        Iterator& operator++();// advance to next entry
        friend class HashMap;// give HashMap access
    };
};


template <typename K, typename V, typename H> // get entry
typename HashMap<K,V,H>::EntryClass&
HashMap<K,V,H>::Iterator::operator*() const
{
    return *ent;
}

template <typename K, typename V, typename H> // get entry

bool HashMap<K,V,H>::Iterator::operator==(const Iterator& p) const//are iterators equal?
{
    if (ba != p.ba || bkt != p.bkt)//ba or bkt differ?
        return false;
    else if (bkt == ba->end())//both at the end?
        return true;
    else
        return (ent == p.ent);//else use entry to decide
}



template <typename K, typename V, typename H>// advance to next entry
typename HashMap<K,V,H>::Iterator& HashMap<K,V,H>::Iterator::operator++()
{
    ++ent;//next entry in bucket
    if (endOfBkt(*this))//at end of bucket?
    {
        ++bkt;//go to next bucket
        while (bkt != ba->end() && bkt->empty())//find nonempty bucket
            ++bkt;
        if (bkt == ba->end())//end of bucket array?
            return *this;//end of bucket array?
        ent = bkt->begin();//first nonempty entry
    }
    return *this;// return self
}


template <typename K, typename V, typename H>// advance to next entry
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::end()
{
    return Iterator(B, B.end());    // iterator to end
}


template <typename K, typename V, typename H>// advance to next entry
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::begin()// iterator to front
{
    if (empty())
        return end();//emtpty - return end
    BItor bkt = B.begin();//else search for an entry
    while (bkt->empty())//find nonempty bucket
        ++bkt;
    return Iterator(B, bkt, bkt->begin());//return first of bucket
}

template <typename K, typename V, typename H>// advance to next entry
HashMap<K,V,H>::HashMap(int capacity) : n(0), B(capacity) { } // constructor


template <typename K, typename V, typename H>// advance to next entry
int HashMap<K,V,H>::size() const
{
    return n;    // number of entries
}


template <typename K, typename V, typename H>// advance to next entry
bool HashMap<K,V,H>::empty() const
{
    return size() == 0;    // is the map empty?
}


template <typename K, typename V, typename H>// find utility
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::finder(const K& k)
{
    int i = hash(k) % B.size();//get hash index i
    BItor bkt = B.begin() + i;//the ith bucket
    Iterator p(B, bkt, bkt->begin());//start of ith bucket
    while (!endOfBkt(p) && (*p).key() != k)//search for k
        nextEntry(p);
    return p;// return final position
}


template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::find(const K& k)// find key
{
    Iterator p = finder(k);// look for k
    if (endOfBkt(p))// didn’t find it?
        return end();// return end iterator
    else
        return p;// return its position
}



template <typename K, typename V, typename H>// insert utility
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::inserter(const Iterator& p, const EntryClass& e)
{
    EItor ins = p.bkt->insert(p.ent, e);// insert before p
    n++;// one more entry
    return Iterator(B, p.bkt, ins);
// return this position
}

template <typename K, typename V, typename H>// insert/replace (v,k)
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::put(const K& k, const V& v)
{
    Iterator p = finder(k);// search for k
    if (endOfBkt(p))// k not found?
    {
        return inserter(p, EntryClass(k, v));// insert at end of bucket
    }
    else// found it?
    {
        p.ent->setValue(v);// replace value with v
        return p;// return this position
    }
}



template <typename K, typename V, typename H>
void HashMap<K,V,H>::eraser(const Iterator& p)// remove utility
{
    p.bkt->erase(p.ent);// remove entry from bucket
    n--;// one fewer entry
}


template <typename K, typename V, typename H>
void HashMap<K,V,H>::erase(const Iterator& p)// remove entry at p
{
    eraser(p);
}



template <typename K, typename V, typename H>
void HashMap<K,V,H>::erase(const K& k)// remove entry with key k
{
    Iterator p = finder(k);// find k
    if (endOfBkt(p))// not found?
        throw NonexistentElement("Erase of nonexistent"); // . . .error
    eraser(p);// remove it
}



template <typename K, typename V, typename H>
class HashDict : public HashMap<K,V,H>
{
public:// public functions
    typedef typename HashMap<K,V,H>::Iterator Iterator;
    typedef typename HashMap<K,V,H>::EntryClass Entry;
    // . . .insert Range class declaration here
    class Range// an iterator range
    {
    private:
        Iterator _begin;// front of range
        Iterator _end;// end of range
    public:
        Range(const Iterator& b, const Iterator& e)// constructor
            : _begin(b), _end(e) { }
        Iterator& begin()// get beginning
        {
            return _begin;
        }
        Iterator& end()// get end
        {
            return _end;
        }
    };
public:// public functions
    HashDict(int capacity = 100);// constructor
    Range findAll(const K& k);// find all entries with k
    Iterator insert(const K& k, const V& v);// insert pair (k,v)
};



template <typename K, typename V, typename H>
HashDict<K,V,H>::HashDict(int capacity) : HashMap<K,V,H>(capacity) { }// constructor

template <typename K, typename V, typename H>
typename HashDict<K,V,H>::Iterator HashDict<K,V,H>::insert(const K& k, const V& v)// insert pair (k,v)
{
    Iterator p = finder(k);// find key
    Iterator q = inserter(p, Entry(k, v));// insert it here
    return q;// return its position
}



template <typename K, typename V, typename H>// find all entries with k
typename HashDict<K,V,H>::Range HashDict<K,V,H>::findAll(const K& k)
{
    Iterator b = finder(k);// look up k
    Iterator p = b;
    while (!endOfBkt(p) && (*p).key() == (*b).key())   // find next unequal key
    {
        ++p;
    }
    return Range(b, p);// return range of positions
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
