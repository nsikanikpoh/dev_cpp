#include <iostream>
#include <iomanip>


int main()
{
    std::cout.setf(std::ios::showpos); // turn on the std::ios::showpos flag
    std::cout << 27 << '\n';
    std::cout << -27 << '\n';

    std::cout.setf(std::ios::showpos | std::ios::uppercase); // turn on the std::ios::showpos and std::ios::uppercase flag
    std::cout << 27 << '\n';
//To turn a flag off, use the unsetf() function:


    std::cout.unsetf(std::ios::showpos); // turn off the std::ios::showpos flag
    std::cout << 28 << '\n';

    std::cout.unsetf(std::ios::dec); // turn off decimal output
    std::cout.setf(std::ios::hex); // turn on hexadecimal output
    std::cout << 27 << '\n';

// Turn on std::ios::hex as the only std::ios::basefield flag
    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 27 << '\n';



//using manipulators
    std::cout << std::hex << 27 << '\n'; // print 27 in hex
    std::cout << 28 << '\n'; // we're still in hex
    std::cout << std::dec << 29 << '\n'; // back to decimal


    std::cout << true << " " << false << '\n';

    std::cout.setf(std::ios::boolalpha);
    std::cout << true << " " << false << '\n';

    std::cout << std::noboolalpha << true << " " << false << '\n';

    std::cout << std::boolalpha << true << " " << false << '\n';





    std::cout << 5 << '\n';

    std::cout.setf(std::ios::showpos);
    std::cout << 5 << '\n';

    std::cout << std::noshowpos << 5 << '\n';

    std::cout << std::showpos << 5 << '\n';


    std::cout << 12345678.9 << '\n';

    std::cout.setf(std::ios::uppercase);
    char str[10] {"hjas awq"};
    std::cout << str << '\n';
    std::cout << 12345678.9 << '\n';

    std::cout << std::nouppercase << 12345678.9 << '\n';

    std::cout << std::uppercase << 12345678.9 << '\n';



    std::cout << 27 << '\n';

    std::cout.setf(std::ios::dec, std::ios::basefield);
    std::cout << 27 << '\n';

    std::cout.setf(std::ios::oct, std::ios::basefield);
    std::cout << 27 << '\n';

    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 27 << '\n';

    std::cout << std::dec << 27 << '\n';
    std::cout << std::oct << 27 << '\n';
    std::cout << std::hex << 27 << '\n';



    std::cout << std::fixed << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';

    std::cout << std::scientific << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';
    std::cout << "showpoint\n";
    std::cout << std::showpoint << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';

    std::cout.setf(std::ios::dec, std::ios::basefield);
    std::cout << std::fixed << '\n';
    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
    std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified




//One thing to note is that setw() and width() only affect the next output statement.
//They are not persistent like some other flags/manipulators.

//Now, let’s set a fill character and do the same example:

    std::cout.fill('*');
    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
    std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified
}
