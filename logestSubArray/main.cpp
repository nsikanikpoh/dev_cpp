#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int longestSubarray(vector<int> ar) {

 int result = 0;
     vector<int> arr_lens;
     vector <int> unique_set(2);
     if (ar[0]) unique_set[0] = ar[0];
     if (ar[1]) unique_set[1] = ar[1];
    for(auto it = ar.cbegin(); it != ar.cend(); ++it)
    {
        auto next_itor = it + 1;
        while(next_itor != ar.cend())
        {
            if( abs(*it - *next_itor) == 0 || abs(*it - *next_itor) == 1)
            {
                result++;
            }
            else
            {
                unique_set.pop_back();
                unique_set.pop_back();
                unique_set.push_back(*it);
                unique_set.push_back(*next_itor);
                arr_lens.push_back(result);
                result = 0;
            }
            ++next_itor;
        }
       // arr_lens.push_back(result);
    }
    auto res = max_element(arr_lens.begin(),arr_lens.end());
    return *res;

}

int main()
{

   // vector<int> arr{0,1,2,1,2,3}; //ans=[1,2,1,2]

    vector<int> arr{2,2,1}; //ans=[1,2,1,2]
// arr=[1,1,1,3,3,2,2] ans=[3,3,2,2]
//arr=[1,2,3,4,5] ans=5
//arr=[2,2,1] ans=3

  cout << longestSubarray(arr) << endl;
    return 0;
}
