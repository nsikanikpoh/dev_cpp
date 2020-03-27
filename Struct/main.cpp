#include <iostream>

struct Employee
{
    short id;
    int age;
    double wage;
};

void printInformation(Employee employee)
{
    std::cout << "ID:   " << employee.id << "\n";
    std::cout << "Age:  " << employee.age << "\n";
    std::cout << "Wage: " << employee.wage << "\n";
}

int main()
{
    Employee joe; // create an Employee struct for Joe
    joe.id = 14; // assign a value to member id within struct joe
    joe.age = 32; // assign a value to member age within struct joe
    joe.wage = 24.15; // assign a value to member wage within struct joe

    Employee frank; // create an Employee struct for Frank
    frank.id = 15; // assign a value to member id within struct frank
    frank.age = 28; // assign a value to member age within struct frank
    frank.wage = 18.27; // assign a value to member wage within struct frank

    int totalAge = joe.age + frank.age;

    if (joe.wage > frank.wage)
        std::cout << "Joe makes more than Frank\n";
    else if (joe.wage < frank.wage)
        std::cout << "Joe makes less than Frank\n";
    else
        std::cout << "Joe and Frank make the same amount\n";

// Frank got a promotion
    frank.wage += 2.50;
    std::cout << totalAge << '\n';
// Today is Joe's birthday
    ++joe.age; // use pre-increment to increment Joe's age by 1


    Employee joen = { 1, 32, 60000.0 }; // joe.id = 1, joe.age = 32, joe.wage = 60000.0
    Employee frankn = { 2, 28, 900.0 }; // frank.id = 2, frank.age = 28, frank.wage = 0.0 (default initialization)
    printInformation(joen);
    printInformation(frankn);
    return 0;
}
