#include <fstream>
#include <iostream>
#include <cstdlib> // for exit()

int main()
{
    using namespace std;

   // We'll pass the ios:app flag to tell the ofstream to append
    // rather than rewrite the file.  We do not need to pass in ios::out
    // because ofstream defaults to ios::out
    ofstream outf("Sample.dat", ios::app);

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened for writing!" << endl;
        exit(1);
    }

    outf << "This is line 3" << endl;
    outf << "This is line 4" << endl;




  // ifstream is used for reading files
    // We'll read from a file called Sample.dat
    ifstream inf("Sample.dat");

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
        exit(1);
    }

    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        getline(inf, strInput);
        cout << strInput << endl;
    }

    return 0;



    // When outf goes out of scope, the ofstream
    // destructor will close the file
}
