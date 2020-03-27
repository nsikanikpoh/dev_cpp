#include <string>
#include <iostream>

class Employee
{
private:
    int m_id;
    std::string m_name;

public:
    Employee(int id=0, const std::string &name=""):
        m_id(id), m_name(name)
    {
        std::cout << "Employee " << m_name << " created.\n";
    }

    // Use a delegating constructors to minimize redundant code
    Employee(const std::string &name) : Employee(0, name) { }
};

int main()
{
    Employee staff;
    Employee staff1 {"Sly"};
    Employee staff2 {"Tina UZor Etana"};

    return 0;
}
