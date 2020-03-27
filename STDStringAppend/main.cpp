#include <iostream>



int main()
{
    std::string sString("one");

    sString += std::string(" two");

    std::string sThree(" three");
    sString.append(sThree);

    const std::string sTemp("twothreefour");
    sString.append(sTemp, 3, 5); // append substring of sTemp starting at index 3 of length 5

    //c-style string
    std::string sString1("one");

    sString1 += " two";
    sString1.append(" three");
    sString1.push_back('2');
    std::cout << sString << std::endl;

    std::cout << sString1 << std::endl;



    std::string sString2("aaaa");
    std::cout << sString2 << std::endl;

    sString2.insert(2, std::string("bbbb"));
    std::cout << sString2 << std::endl;

    sString2.insert(4, "cccc");
    std::cout << sString2 << std::endl;


    const std::string sInsert("01234567");
    sString2.insert(2, sInsert, 3, 4); // insert substring of sInsert from index [3,7) into sString at index 2
    std::cout << sString2 << std::endl;

    //There is a flavor of insert() that inserts the first portion of a C-style string:
    sString2.insert(2, "qwerty", 5);
    std::cout << sString2 << std::endl;


    //There’s also a flavor of insert() that inserts the same character multiple times:
    sString2.insert(2, 4, 'c');
    std::cout << sString2 << std::endl;


    return 0;
}
