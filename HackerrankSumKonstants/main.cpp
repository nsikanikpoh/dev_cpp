#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int k, vector<int> ar)
{
    int result = false;
    for(auto it = ar.cbegin(); it != ar.cend(); ++it)
    {
        auto next_itor = it + 1;
        while(next_itor != ar.cend())
        {
            if( (*it + *next_itor) == k)
            {
                result = true;
                break;
            }
            ++next_itor;
        }
    }
    return result;
}


int main()
{
    vector<int> arr{10,15,7,3};
    bool result = divisibleSumPairs(17, arr);
    cout << "Result : " << result << endl;
    return 0;
}
