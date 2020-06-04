#include <iostream>
#include <map>

using namespace std;

class RuntimeException
{
// generic run-time  exception
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



class BadCast : public RuntimeException
{
public:
    BadCast(const string& err) : RuntimeException(err) { }
};



class Object// generic object
{
public:
    int intValue() const;
    string stringValue() const;
};


class Integer : public Object
{
private:
    int value;
public:
    Integer(int v = 0) : value(v) { }
    int getValue() const
    {
        return value;
    }
};


class String : public Object
{
private:
    string value;
public:
    String(string v = "") : value(v) { }
    string getValue() const
    {
        return value;
    }
};


int Object::intValue() const  // cast to Integer
{
    const Integer* p = static_cast<const Integer*>(this);
    if (p == NULL)
        throw BadCast("Illegal attempt to cast to Integer");
    return p->getValue();
}


string Object::stringValue() const  // cast to String
{
    const String* p = static_cast<const String*>(this);
    if (p == NULL)
        throw BadCast("Illegal attempt to cast to String");
    return p->getValue();
}


class Decorator
{
private:// member data
    std::map<string,Object*> map;// the map
public:
    Object* get(const string& a)// get value of attribute
    {
        return map[a];
    }
    void set(const string& a, Object* d)// set value
    {
        map[a] = d;
    }
};



int main()
{
    Object* yes = new Object;// decorator values
    Object* no = new Object;
    Decorator v;// a decorable object
// . . .
    v.set("visited", yes);// set “visited” attribute
// . . .
    if (v.get("visited") == yes)
        cout << "v was visited" << '\n';
    else
        cout << "v was not visited" << '\n';


    Decorator u;// a decorable object
    u.set("name", new String("Bob"));// store name as “Bob”
    u.set("age", new Integer(23));// store age as 23
// . . .
    string n = u.get("name")->stringValue();// n = “Bob”
    int a = u.get("age")->intValue();// a = 23

    cout << "string n is: " << n << '\n';
    cout << "integer a is: " << a <<'\n';

    return 0;
}
