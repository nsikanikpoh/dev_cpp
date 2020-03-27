#include <iostream>
int main()
{
    enum class Color // "enum class" defines this as a scoped enumeration instead of a standard enumeration
    {
        RED, // RED is inside the scope of Color
        BLUE
    };

    enum class Fruit
    {
        BANANA, // BANANA is inside the scope of Fruit
        APPLE
    };

    Color color = Color::RED; // note: RED is not directly accessible any more, we have to use Color::RED
   // Fruit fruit = Fruit::BANANA; // note: BANANA is not directly accessible any more, we have to use Fruit::BANANA
	if (color == Color::RED) // this is okay
        std::cout << "The color is red!\n";
    else if (color == Color::BLUE)
        std::cout << "The color is blue!\n";

    Color colorb = Color::BLUE;

   // std::cout << colorb; // won't work, because there's no implicit conversion to int
    std::cout << static_cast<int>(colorb); // will print 1


    return 0;
}
