#include <iostream>
#include <vector>
#include <list>

using namespace std;


int vectorSum2(vector<int> V)
{
    typedef vector<int>::iterator Iterator;
// iterator type
    int sum = 0;
    for (Iterator p = V.begin(); p != V.end(); ++p)
        sum += *p;
    return sum;
}


int vectorSum3(const vector<int>& V)
{
    typedef vector<int>::const_iterator ConstIterator; // iterator type
    int sum = 0;
    for (ConstIterator p = V.begin(); p != V.end(); ++p)
        sum += *p;
    return sum;
}


int main()
{


    list<int> L;// an STL list of integers
// . . .
    vector<int> V(L.begin(), L.end());// initialize V to be a copy of L

//In addition, A + 1 points to A[1],
//A + 2 points to A[2], and generally A + i points to A[i].
//Addressing the elements of an array in this manner is called pointer arithmetic.
    int A[] = {2, 5, -3, 8, 6};// a C++ array of 5 integers
    vector<int> U(A, A+5);// V = (2, 5, -3, 8, 6)


    cout << "Hello world!" << endl;




    return 0;
}
