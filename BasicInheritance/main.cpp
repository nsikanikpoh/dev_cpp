#include <iostream>
#include <string>

class Person
{
public:
    std::string m_name;
    int m_age;

    Person(std::string name = "", int age = 0)
        : m_name(name), m_age(age)
    {
    }

    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }

};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
public:
    double m_battingAverage;
    int m_homeRuns;

    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
       : m_battingAverage(battingAverage), m_homeRuns(homeRuns)
    {
    }
};


// Employee publicly inherits from Person
class Employee: public Person
{
public:
    double m_hourlySalary;
    long m_employeeID;

    Employee(double hourlySalary = 0.0, long employeeID = 0)
        : m_hourlySalary(hourlySalary), m_employeeID(employeeID)
    {
    }

    void printNameAndSalary() const
    {
        std::cout << m_name << ": " << m_hourlySalary << '\n';
    }
};


class Supervisor: public Employee
{
public:
    // This Supervisor can oversee a max of 5 employees
    long m_overseesIDs[5];

    Supervisor()
    {
    }

};

int main()
{
    // Create a new BaseballPlayer object
    BaseballPlayer joe;
    // Assign it a name (we can do this directly because m_name is public)
    joe.m_name = "Joe";
    // Print out the name
    std::cout << joe.getName() << '\n'; // use the getName() function we've acquired from the Person base class

    Employee frank(20.25, 12345);
    frank.m_name = "Frank"; // we can do this because m_name is public

    frank.printNameAndSalary();

    Supervisor sup;

    sup.m_name = "Sly";

    std::cout << sup.getName() << '\n'; // use the getName() function we've acquired from the Person base class

    return 0;
}
