#include <bits/stdc++.h>

using namespace std;


int removeDuplicates(vector<int>& nums)
{
    int mark = INT_MIN;
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] > mark)
        {
            nums[index] = nums[i];
            index++;
            mark = nums[i];
        }
    }
    return index;
}

int main()
{
    vector<int> v1{1,1,2};
    vector<int> v2{0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(v1) << endl;
    cout << removeDuplicates(v2) << endl;
    return 0;
}
