#include <iostream>
#include <string>

class Car
{
private:
	std::string m_name;
	int m_id;

public:
	Car(std::string name, int id)
		: m_name(name), m_id(id)
	{
	}

	std::string getName() { return m_name; }
	int getId() { return m_id;  }
};

// Our CarLot is essentially just a static array of Cars and a lookup function to retrieve them.
// Because it's static, we don't need to allocate an object of type CarLot to use it
class CarLot
{
private:
	static Car s_carLot[4];

public:
	CarLot() = delete; // Ensure we don't try to allocate a CarLot

	static Car* getCar(int id)
	{
		for (int count = 0; count < 4; ++count)
			if (s_carLot[count].getId() == id)
				return &(s_carLot[count]);

		return nullptr;
	}
};

Car CarLot::s_carLot[4] = { Car("Prius", 4), Car("Corolla", 17), Car("Accord", 84), Car("Matrix", 62) };

class Driver
{
private:
	std::string m_name;
	int m_carId; // we're associated with the Car by ID rather than pointer

public:
	Driver(std::string name, int carId)
		: m_name(name), m_carId(carId)
	{
	}

	std::string getName() { return m_name; }
	int getCarId() { return m_carId; }

};

int main()
{
	Driver d("Franz", 17); // Franz is driving the car with ID 17

	Car *car = CarLot::getCar(d.getCarId()); // Get that car from the car lot

	if (car)
		std::cout << d.getName() << " is driving a " << car->getName() << '\n';
	else
		std::cout << d.getName() << " couldn't find his car\n";

	return 0;
}
