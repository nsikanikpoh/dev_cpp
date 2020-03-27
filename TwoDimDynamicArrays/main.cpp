#include <iostream>

using namespace std;

int main()
{
    int **array = new int*[10]; // allocate an array of 10 int pointers — these are our rows
    for (int count = 0; count < 10; ++count)
        array[count] = new int[5]; // these are our columns

    array[9][4] = 3;
    cout << array[9][4] << endl;

    //With this method, because each array column is dynamically allocated independently,
    //it’s possible to make dynamically allocated two dimensional arrays that are not rectangular.
    //For example, we can make a triangle-shaped array
for (int count = 0; count < 10; ++count)
    delete[] array[count];
delete[] array; // this needs to be done last


    int **array2 = new int*[10]; // allocate an array of 10 int pointers — these are our rows
    for (int count = 0; count < 10; ++count)
        array2[count] = new int[count+1]; // these are our columns

    array2[9][3] = 6;

    cout << array2[9][3] << endl;

    for (int count = 0; count < 10; ++count)
    delete[] array2[count];
delete[] array2; // this needs to be done last

    return 0;
}
