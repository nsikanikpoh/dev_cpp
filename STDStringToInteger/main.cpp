#include <vector>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <iterator>

int main()
{



// get string
    std::string input_str;
    std::getline( std::cin, input_str );

// convert to a stream
    std::stringstream in( input_str );

// convert to vector of ints
    std::vector<int> ints;
    copy( std::istream_iterator<int, char>(in), std::istream_iterator<int, char>(), back_inserter( ints ) );

    for(const auto& elem: ints)
        std::cout << elem << '\n';

    return 0;
}
