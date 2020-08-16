#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getTotalX(vector<int> a, vector<int> b) {
    int count = 0;
    int start = a[0];
    int ending = b[b.size() - 1];
    for(int i = a[0]; i < ending + 1; i++)
    {
     bool i_a_div{false};
     bool i_b_div{false};
    if (std::all_of(a.cbegin(), a.cend(), [i](int j){ return i % j == 0; }))
             i_a_div = true;;
    if (std::all_of(b.cbegin(), b.cend(), [i](int k){ return k % i == 0; }))
             i_b_div = true;
    if (i_a_div == true && i_b_div == true)
       count += 1;

    }
    return count;

}

int main()
{
    vector<int> arr1 = {2,4};
    vector<int> arr2 = {16,32,96};
   int integer_count = getTotalX(arr1, arr2);

    cout << "Integer Count: " << integer_count << endl;
    return 0;
}
