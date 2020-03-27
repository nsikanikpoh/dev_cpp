#include <iostream>
#include <string>
#include <cstring>



int main()
{
    std::string sSource{ "abcdefg" };
    std::cout << sSource[5] << '\n';
    sSource[5] = 'X';

    std::cout << sSource.at(5) << '\n';

    //his version is slower since it uses exceptions to check if the nIndex is valid. If you are not
    //sure whether nIndex is valid, you should use this version to access the array
    std::cout << sSource << '\n';

    //convert to c_style string

    std::cout << std::strlen(sSource.c_str()) << '\n';




    std::string sSource1{ "abcdefg" };
    const char *szString{ "abcdefg" };
// memcmp compares the first n characters of two C-style strings and returns 0 if they are equal
    if (std::memcmp(sSource1.data(), szString, sSource1.length()) == 0)
        std::cout << "The strings are equal\n";
    else
        std::cout << "The strings are not equal\n";


    //copy

    std::string sSource9{ "sphinx of black quartz, judge my vow" };

    char szBuf[20];
    int nLength{ static_cast<int>(sSource9.copy(szBuf, 5, 10)) };
    szBuf[nLength] = '\0';  // Make sure we terminate the string in the buffer

    std::cout << szBuf << '\n';

    std::string sDest;

    sDest.assign(sSource, 2, 4); // assign a substring of source from index 2 of length 4
    std::cout << sDest << std::endl;


    std::string sDest1;

    sDest1.assign(4, 'g');
    std::cout << sDest << std::endl;


    std::string sStr1("red");
    std::string sStr2("blue");

    std::cout << sStr1 << " " << sStr2 << std::endl;
    std::swap(sStr1, sStr2);
    std::cout << sStr1 << " " << sStr2 << std::endl;
    sStr1.swap(sStr2);
    std::cout << sStr1 << " " << sStr2 << std::endl;


    return 0;
}
