#include <iostream>
#include "constants.h"

#include <cstdint> // for std::int_fast64_t

// note: exp must be non-negative
std::int_fast64_t powint(int base, int exp)
{
	std::int_fast64_t result{ 1 };
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}


bool isNotValidHeight(int num)
{
    if(num == 0 || num < 0)
        return true;
    return false;
}

int getNumber()
{
    std::cout << "Enter the height of the tower in meters:  \n";
    double x;
    std::cin >> x;
    return x;
}

double doCalc(int height, int time)
{
    return (height - (myConstants::gravity * (time*time)/2));
}


int main()
{

std::cout << powint(7, 12) << '\n'; // 7 to the 12th power

// conditional operator
   bool inBigClassroom { false };
    const int classSize { inBigClassroom ? 30 : 20 };
    std::cout << "The class size is: " << classSize << '\n';


while (1)
    {
        int firstNum{ getNumber() };
        if (isNotValidHeight(firstNum))
        {
            std::cout << "warning, you entered zero value, please enter a non zero value \n";
            firstNum = getNumber();
        }
        int i{0};
        for (i=0; i<50; i++)
        {
          if (isNotValidHeight(doCalc(firstNum, i)))
             std::cout << "At " << i << " seconds, the ball is on the ground. \n" ;
          else
            std::cout << "At " << i << " seconds, the ball is at heights: " << doCalc(firstNum, i) << " meters \n" ;

        }
         std::cout << "********************************************************************\n";

    }

    return 0;
}
