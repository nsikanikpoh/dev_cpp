class MyClass
{
private:
	static std::vector<char> s_mychars;

public:

	class _init // we're defining a nested class named _init
	{
	public:
		_init() // the _init constructor will initialize our static variable
		{
			s_mychars.push_back('a');
			s_mychars.push_back('e');
			s_mychars.push_back('i');
			s_mychars.push_back('o');
			s_mychars.push_back('u');
		}
	} ;

private:
	static _init s_initializer; // we'll use this static object to ensure the _init constructor is called
};

std::vector<char> MyClass::s_mychars; // define our static member variable
MyClass::_init MyClass::s_initializer; // define our static initializer, which will call the _init constructor, which will initialize s_mychars


class MyClass
{
public:
	static std::vector<char> s_mychars;
};

std::vector<char> MyClass::s_mychars = { 'a', 'e', 'i', 'o', 'u' }; // initialize static variable at point of definition
