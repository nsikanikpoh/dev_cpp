#include <iostream>
#include <memory> // for std::unique_ptr and std::make_unique

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

std::unique_ptr<Resource> createResource()
{
     return std::make_unique<Resource>();
}

//In general, you should not return std::unique_ptr by pointer (ever) or
//reference (unless you have a specific compelling reason to).
int main()
{
    std::unique_ptr<Resource> ptr{ createResource() };

    // do whatever

    return 0;
}
