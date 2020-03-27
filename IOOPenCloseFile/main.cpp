#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outf("Sample.dat");
    outf << "This is line 1" << endl;
    outf << "This is line 2" << endl;
    outf.close(); // explicitly close the file

// Oops, we forgot something
    outf.open("Sample.dat", ios::app);
    outf << "This is line 3" << endl;
    outf << "This is line 4" << '\n';
    outf.close();


    //ifstream inf("Sample.dat");
    ifstream inf("Sample.dat", ifstream::binary);

    //ifstream inf("Sample.dat");

    //Two other useful functions are tellg() and tellp(), which return the absolute position of
    //the file pointer. This can be used to determine the size of a file:
    inf.seekg(0, ios::end); // move to end of file
    cout << inf.tellg() << '\n';

    // If we couldn't open the input file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
        exit(1);
    }

    string strData;

    inf.seekg(5); // move to 5th character
    // Get the rest of the line and print it
    getline(inf, strData);
    cout << strData << endl;

    inf.seekg(8, ios::cur); // move 8 more bytes into file
    // Get rest of the line and print it
    getline(inf, strData);
    cout << strData << endl;

    inf.seekg(-15, ios::end); // move 15 bytes before end of file
    // Get rest of the line and print it
    getline(inf, strData);
    cout << strData << endl;


    return 0;
}
