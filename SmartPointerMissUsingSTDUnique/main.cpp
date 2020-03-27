#include <iostream>
#include <memory> // for std::unique_ptr


class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }

	friend std::ostream& operator<<(std::ostream& out, const Resource &res)
	{
		out << "I am a resource\n";
		return out;
	}
};


Resource *res{ new Resource() };
std::unique_ptr<Resource> res1{ res };
std::unique_ptr<Resource> res2{ res };

//While this is legal syntactically, the end result will be that both res1 and
//res2 will try to delete the Resource, which will lead to undefined behavior.



//Second, don’t manually delete the resource out from underneath the std::unique_ptr.


Resource *res{ new Resource() };
std::unique_ptr<Resource> res1{ res };
delete res;



//If you do, the std::unique_ptr will try to delete an already deleted resource, again leading to undefined behavior.

//Note that std::make_unique() prevents both of the above cases from happening inadvertently.

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
