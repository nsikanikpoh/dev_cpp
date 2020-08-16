#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int n, int k, vector<int> ar)
{
    int result = 0;
    for(auto it = ar.cbegin(); it != ar.cend(); ++it)
    {
        auto next_itor = it + 1;
        while(next_itor != ar.cend())
        {
            if( (*it + *next_itor) % k == 0)
                result++;
            ++next_itor;
        }
    }
    return result;
}


int main()
{
    vector<int> arr{1,2,3,4,5,6};
    int result = divisibleSumPairs(6, 5, arr);
    cout << "Number of Divible Pairs is: " << result << endl;
    return 0;
}
