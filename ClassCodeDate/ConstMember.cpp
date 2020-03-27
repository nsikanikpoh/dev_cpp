class Something
{
public:
    int m_value;

    Something(): m_value(0) { }

    void resetValue() { m_value = 0; }
    void setValue(int value) { m_value = value; }

    int getValue() const { return m_value; } // note addition of const keyword after parameter list, but before function body
};



class Something
{
public:
    int m_value;

    Something(): m_value(0) { }

    void resetValue() { m_value = 0; }
    void setValue(int value) { m_value = value; }

    int getValue() const; // note addition of const keyword here
};

int Something::getValue() const // and here
{
    return m_value;
}

int main()
{
    const Something something; // calls default constructor

    something.m_value = 5; // compiler error: violates const
    something.setValue(5); // compiler error: violates const

    return 0;
}



class MyClass
{
public:
	static std::vector<char> s_mychars;
};

std::vector<char> MyClass::s_mychars = { 'a', 'e', 'i', 'o', 'u' }; // initialize static variable at point of definition
