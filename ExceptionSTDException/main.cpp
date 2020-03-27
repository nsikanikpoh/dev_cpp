#include <iostream>
#include <exception> // for std::exception
#include <string> // for this example
int main()
{
    try
    {
        // Your code using standard library goes here
        // We'll trigger one of these exceptions intentionally for the sake of example
        std::string s;
        s.resize(-1); // will trigger a std::length_error
    }
    // This handler will catch std::length_error (and any exceptions derived from it) here
    catch (std::length_error &exception)
    {
        std::cerr << "You ran out of memory!" << '\n';
    }
    // This handler will catch std::exception and all the derived exceptions too
    catch (std::exception &exception)
    {
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }

    return 0;
}

