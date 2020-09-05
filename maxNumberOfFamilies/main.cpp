#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int maxNumberOfFamilies(int n, vector<vector<int>>& reserved) {
        unordered_map<int, vector<int>> vmap;
        for (int i = 0; i < reserved.size(); i++)
            vmap[reserved[i][0]].push_back(reserved[i][1]);
        int reservations = 0;
        for (unordered_map<int, vector<int>> :: iterator it = vmap.begin(); it != vmap.end(); it++) {
            vector<int> v = it->second;
            int count1 = 0;
            for (int i = 2; i <= 5; i++) {
                if (find(v.begin(), v.end(), i) == v.end()) count1++;
                else break;
            }
            if (count1 == 4) reservations++;
            int count2 = 0;
            for (int i = 6; i <= 9; i++) {
                if (find(v.begin(), v.end(), i) == v.end()) count2++;
                else break;
            }
            if (count2 == 4) reservations++;
            if (count1 != 4 && count2 != 4) {
                count2 = 0;
                for (int i = 4; i <= 7; i++) {
                    if (find(v.begin(), v.end(), i) == v.end()) count2++;
                    else break;
                }
                if (count2 == 4) reservations++;
            }
        }
        reservations += (2 * (n - vmap.size()));
        return reservations;
    }

int main()
{
vector<vector<int>> reservedSeats1 = {{2,1},{1,8},{2,6}};


vector<vector<int>> reservedSeats2 = {{4,3}, {1,4},{4,6},{1,7}};

    cout << maxNumberOfFamilies(2, reservedSeats1) << endl;
    cout << maxNumberOfFamilies(4, reservedSeats2) << endl;
    return 0;
}
