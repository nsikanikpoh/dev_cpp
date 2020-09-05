#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Complete the serviceLane function below.
vector<int> serviceLane(int n, vector<int> width, vector<vector<int>> cases) {
    vector<int> result;
    for(auto &lane_case: cases)
    {
        std::vector<int>::iterator elem = std::min_element(width.begin() + lane_case[0], width.begin() + lane_case[1] + 1);
        result.push_back(*elem);
    }
    return result;
}

int main()
{
vector<int> c{2, 3, 1, 2, 3, 2, 3, 3};
vector<vector<int>> cases {
{0, 3},
{4, 6},
{6, 7},
{3, 5},
{0, 7}
};
vector<int> res = serviceLane(8, c, cases);
for(int &i: res)
    cout << i << " ";
cout << endl;
    return 0;
}
