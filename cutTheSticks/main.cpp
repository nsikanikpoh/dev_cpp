#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Complete the cutTheSticks function below.
vector<int> cutTheSticks(vector<int> arr)
{
    int min = 0;
    vector<int> rslt;

    while(arr.size() > 1)
    {
        min = *min_element(arr.begin(), arr.end());
        int pos = 0;
        rslt.push_back(arr.size());

        for(unsigned int j = 0; j < arr.size(); j++)
        {
            arr[j] -= min;

            if(arr[j] > 0)
            {
                arr[pos] = arr[j];
                pos++;
            }
        }

        arr.erase(arr.begin() + pos, arr.end());
    }

    if(arr.size() > 0)
    {
        rslt.push_back(arr.size());
    }

    return rslt;
}

int main()
{
    vector<int> cts = {1, 2, 3, 4, 3, 3, 2, 1};
    auto res = cutTheSticks(cts);
    for(int& i: res)
        cout << i << endl;
    return 0;
}
