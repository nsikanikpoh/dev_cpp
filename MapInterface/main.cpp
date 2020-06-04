#include <iostream>

using namespace std;


template <typename K, typename V>
class Map// map interface
{
public:
    class Entry;// a (key,value) pair
    class Iterator;// an iterator (and position)
    int size() const;// number of entries in the map
    bool empty() const;// is the map empty?
    Iterator find(const K& k) const;//find entry with key k
    Iterator put(const K& k, const V& v);// insert/replace pair (k,v)
    void erase(const K& k);// remove entry with key k
    void erase(const Iterator& p);// erase entry at p
    Iterator begin();// iterator to first entry
    Iterator end();// iterator to end entry

};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
