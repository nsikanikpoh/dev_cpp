#include <iostream>

int main()
{
    int countr = 0;
    while (countr < 10)
        {
        std::cout << countr << " ";
        ++countr;
        }
    std::cout << "done!\n";
    std::cout << "*******************************************\n";

    int count = 1;
    while (count <= 100)
    {
        // print the number (pad numbers under 10 with a leading 0 for formatting purposes)
        if (count < 10)
            std::cout << "0" << count << " ";
        else
            std::cout << count << " ";

        // if the loop variable is divisible by 10, print a newline
        if (count % 10 == 0)
            std::cout << "\n";

        // increment the loop counter
        ++count;
    }


    return 0;
}
