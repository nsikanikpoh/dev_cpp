// C++ Program to convert a 'struct' in 'hex string'
// and vice versa
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

struct Student_data
{
    int  student_id;
    char name[16];
};

void convert_to_hex_string(ostringstream &op,
                      const unsigned char* data, int size)
{
    // Format flags
    ostream::fmtflags old_flags = op.flags();

    // Fill characters
    char old_fill  = op.fill();
    op << hex << setfill('0');

    for (int i = 0; i < size; i++)
    {
        // Give space between two hex values
        if (i>0)
            op << ' ';

        // force output to use hex version of ascii code
        op << "0x" << setw(2) << static_cast<int>(data[i]);
    }

    op.flags(old_flags);
    op.fill(old_fill);
}

void convert_to_struct(istream& ip, unsigned char* data,
                       int size)
{
    // Get the line we want to process
    string line;
    getline(ip, line);

    istringstream ip_convert(line);
    ip_convert >> hex;

    // Read in unsigned ints, as wrote out hex version
    // of ascii code
    unsigned int u = 0;
    int i = 0;

    while ((ip_convert >> u) && (i < size))
        if((0x00 <= u) && (0xff >= u))
            data[i++] = static_cast<unsigned char>(u);
}

// Driver code
int main()
{
    Student_data student1 = {1, "Rohit"};
    ostringstream op;

    // Function call to convert 'struct' into 'hex string'
    convert_to_hex_string(op,
             reinterpret_cast<const unsigned char*>(&student1),
             sizeof(Student_data));

    string output = op.str();
    cout << "After conversion from struct to hex string:\n"
         << output << endl;

    // Get te hex string
    istringstream ip(output);
    Student_data student2 = {0};

    // Function call to convert 'hex string' to 'struct'
    convert_to_struct(ip,
                reinterpret_cast<unsigned char*>(&student2),
                sizeof(Student_data));

    cout << "\nAfter Conversion form hex to struct: \n";
    cout << "Id \t: " << student2.student_id << endl;
    cout << "Name \t: "<< student2.name << endl;

    return 0;
}
