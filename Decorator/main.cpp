#include <iostream>
#include <map>

using namespace std;

struct Object
{
};

class Decorator
{
private:// member data
    std::map<string,Object*> map;// the map
public:
    Object* get(const string& a)// get  value of attribute
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
        cout << "v was visited";
    else
        cout << "v was not visited";
    return 0;
}
