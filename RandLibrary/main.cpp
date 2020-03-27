#include <iostream>
#include "random.hpp"

// get base random alias which is auto seeded and has static API and internal state
using Random = effolkronium::random_static;

int main()
{
std::cout << Random::get(1, 2) << '\n';
	std::cout << Random::get(1, 6) << '\n';
	std::cout << Random::get(1, 10) << '\n';
	std::cout << Random::get(1, 20) << '\n';

	return 0;
}
