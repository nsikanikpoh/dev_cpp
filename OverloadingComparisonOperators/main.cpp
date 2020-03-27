#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string make, std::string model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car &c1, const Car &c2);
    friend bool operator!= (const Car &c1, const Car &c2);
    friend std::ostream& operator<<(std::ostream& out, const Car& c)
    {
        out << '(' << c.m_make << ", " << c.m_model << ')';
        return out;
    }

    // h/t to reader Olivier for this version of the function
    friend bool operator<(const Car& c1, const Car& c2)
    {
        if (c1.m_make == c2.m_make) // If the car is the same make...
            return c1.m_model < c2.m_model; // then compare the model
        else
            return c1.m_make < c2.m_make; // otherwise compare the makes
    }
};

bool operator== (const Car &c1, const Car &c2)
{
    return (c1.m_make == c2.m_make &&
            c1.m_model == c2.m_model);
}

bool operator!= (const Car &c1, const Car &c2)
{
    return !(c1 == c2);
}

int main()
{
    Car corolla{ "Toyota", "Corolla" };
    Car camry{ "Toyota", "Camry" };

    if (corolla == camry)
        std::cout << "a Corolla and Camry are the same.\n";

    if (corolla != camry)
        std::cout << "a Corolla and Camry are not the same.\n";


    std::vector<Car> v
    {
        { "Toyota", "Corolla" },
        { "Honda", "Accord" },
        { "Toyota", "Camry" },
        { "Honda", "Civic" }
    };

    std::sort(v.begin(), v.end()); // requires an overloaded Car::operator<

    for (const auto& car : v)
        std::cout << car << '\n'; // requires an overloaded Car::operator<<

    return 0;
}
