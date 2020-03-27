#include <iostream>
#include <vector>


int main()
{
    int health{ 33 };
    int armor{ 100 };
    std::vector<CEnemy> enemies{};

// Capture health and armor by value, and enemies by reference.
    [health, armor, &enemies]() {};


    // Capture health and armor by value, and enemies by reference.
    [health, armor, &enemies]() {};

// Capture enemies by reference and everything else by value.
    [=, &enemies]() {};

// Capture armor by value and everything else by reference.
    [&, armor]() {};

// Illegal, we already said we want to capture everything by reference.
    [&, &armor]() {};

// Illegal, we already said we want to capture everything by value.
    [=, armor]() {};

// Illegal, armor appears twice.
    [armor, &health, &armor]() {};

// Illegal, the default capture has to be the first element in the capture group.
    [armor, &]() {};



    return 0;
}
