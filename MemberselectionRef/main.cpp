#include <iostream>

struct Person
{
    int age;
    double weight;
};



int main()
{
    Person person; // define a person

// Member selection using reference to struct
    Person &ref = person;
    ref.age = 5;

    std::cout << ref.age << std::endl;
    // Member selection using pointer to struct
    Person *ptr = &person;
    (*ptr).age= 8;
    ptr->age = 9;



    std::cout << ptr->age << std::endl;
    return 0;
}
