#include <iostream>
#include <sstream>



int main()
{
    //Use the insertion (<<) operator:

    std::stringstream os;
    os << "en garde!" << std::endl; // insert "en garde!" into the stringstream

// Use the str(string) function to set the value of the buffer:

    std::stringstream os2;
    os2.str("en garde!"); // set the stringstream buffer to "en garde!"


//Use the str() function to retrieve the results of the buffer:


    std::stringstream os3;
    os3 << "12345 67.89" << std::endl;
    std::cout << os3.str();

//2) Use the extraction (>>) operator:
    std::string strValue;
    os3 >> strValue;

    std::string strValue2;
    os3 >> strValue2;

// print the numbers separated by a dash
    std::cout << strValue << " - " << strValue2 << std::endl;

    return 0;
}
