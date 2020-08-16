#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int droppedRequests(vector<int> &requestTime)
{
    if(requestTime.size() <= 3)
        return 0;
    int droppedReqCount{0};
    vector<vector<int>> rules{{1,3}, {10,20}, {60,60}};
    set<int> dropped;

    auto maxIt= max_element(requestTime.begin(), requestTime.end());
    int maximum = *maxIt;

    std::unordered_map<int, int> frequencyMap;
    for (int &x: requestTime)
    {
        auto search = frequencyMap.find(x);
        if(search != frequencyMap.end())
            frequencyMap[x] = ++frequencyMap[x];
        else
            frequencyMap[x] = 1;
    }
    std::unordered_map<int, int> lookup;

    for(int i{1}; i < maximum + 1; i++)
        lookup[i] = lookup[i-1] + frequencyMap[i];
    for( auto &rule: rules)
    {
        int window = min(rule[0], maximum);
        for(int i {0}; i < (maximum - window + 1); i++)
        {
            int numRequest = lookup[i+window] - lookup[i];
            int diff = max(0, numRequest-rule[1]);
            for(int j {0}; j < diff; j++)
            {
                int endIndex = lookup[i+window] - 1;
                dropped.insert(endIndex-j);
            }
        }
    }



    return dropped.size();
}

int main()
{
    vector<int> res{1,1,1,2,2,2,3,3,3,4,4,4,6,6,6,5,5,5,7,7,7,8,8,8,9,9,9};
    //vector<int> res{1,1,1,1,2,2,2,3,3,3,3,4,5,5,5,6,6,6,6,7,7,7,8,8,8,8,9,9,9,9,9,10,10,11,11,11,11,11,11,12,12,12,12,12,12,12,13,13,13,13,14,14,14,14,14,16,16,16,16,16,16,17,17,17,18,18,18,18,18,18,18,18,19,19,19,19,19,19,19,20,20,20,20,20};
    cout << droppedRequests(res) << endl;
    return 0;
}
