#include <iostream>
#include <string>
// Loop between 1 and 5

std::string getSpace(int num)
{
    switch(num)
    {
    case 1:
        return "  ";
    case 2:
        return "    ";
    case 3:
        return "      ";
    case 4:
        return "        ";
    case 5:
        return "          ";
    default:
      return "";
    }
}

int main()
{
    int outer = 1;
    while (outer <= 5)
    {
        // loop between 1 and outer
        int inner = 1;
        while (inner <= outer)
            std::cout << inner++ << " ";

        // print a newline at the end of each row
        std::cout << "\n";
        ++outer;
    }
    std::cout << "\n";
    std::cout << "INVERT!****************************************\n\n";

    int outer1 = 5;
    while (outer1 >= 1)
    {
        // loop between 1 and outer
        int inner = 1;
        while (inner <= outer1)
            std::cout << inner++ << " ";

        // print a newline at the end of each row
        std::cout << "\n";
        --outer1;
    }



    std::cout << "INVERT2!****************************************\n\n";

    int outer2 = 1;
    while (outer2 <= 5)
    {
        // loop between 1 and outer
        int inner = 1;
        int diff;
        diff = 5 - outer2;
        int diff2 {outer2 - inner};
        std::cout << getSpace(diff);
        while (inner <= outer2)
        {
          if (diff2)
            std::cout << inner++ << " ";
          else
          std::cout << inner++;
          --diff2;

        }
        // print a newline at the end of each row
        std::cout << "\n";
        ++outer2;
    }


      std::cout << "INVERT2 -- Correction !****************************************\n\n";

    // There are 5 rows, we can loop from 1 to 5
	int outer3 = 1;

	while (outer3 <= 5)
	{
		// Row elements appear in descending order, so start from 5 and loop through to 1
		int inner = 5;

		while (inner >= 1)
		{
			// The first number in any row is the same as the row number
			// So number should be printed only if it is <= the row number, space otherwise
			if (inner <= outer3)
				std::cout << inner << " ";
			else
				std::cout << "x "; // extra spaces purely for formatting purpose

			--inner;
		}

		// A row has been printed, move to the next row
		std::cout << "\n";

		++outer3;
	}

    return 0;
}
