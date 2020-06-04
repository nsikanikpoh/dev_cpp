#ifndef ENTRY_H_INCLUDED
#define ENTRY_H_INCLUDED


template <typename K, typename V>
class Entry// a (key, value) pair
{
public:// public functions
    Entry(const K& k = K(), const V& v = V())// constructor
        : _key(k), _value(v) { }
    const K& key() const//get key
    {
        return _key;
    }
    const V& value() const//get value
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


#endif // ENTRY_H_INCLUDED
