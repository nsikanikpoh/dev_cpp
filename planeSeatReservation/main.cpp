#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int planeSeatReservation(int n, string s)
{
    std::vector<std::string> reserve_seats;
    std::istringstream iss(s);
    for(std::string s; iss >> s; )
        reserve_seats.push_back(s);
    int reservations = 0;
    unordered_map<int, vector<char>> lookUp;
    for(auto i: reserve_seats)
    {
        char col = i[i.size() - 1];
        i.erase((i.size() - 1), 1);
        int row = stoi(i);
        lookUp[row].push_back(col);
    }


    for (unordered_map<int, vector<char>> :: iterator it = lookUp.begin(); it != lookUp.end(); it++)
    {
        vector<char> v = it->second;
        int count1 = 0;
        for (char i = 'B'; i <= 'E'; i++)
        {
            if (find(v.begin(), v.end(), i) == v.end())
                count1++;
            else
                break;
        }
        if (count1 == 4)
            reservations++;
        int count2 = 0;
        for (char i = 'F'; i <= 'J'; i++)
        {
            if(i == 'I')
                continue;
            if (find(v.begin(), v.end(), i) == v.end())
                count2++;
            else
                break;
        }
        if (count2 == 4)
            reservations++;
        if (count1 != 4 && count2 != 4)
        {
            count2 = 0;
            for (char i = 'D'; i <= 'G'; i++)
            {
                if (find(v.begin(), v.end(), i) == v.end())
                    count2++;
                else
                    break;
            }
            if (count2 == 4)
                reservations++;
        }
    }
    reservations += (2 * (n - lookUp.size()));
    return reservations;

}

int main()
{
    string reserve1 {"1A 3C 2B 40G 5G"};
    string reserve2 {"1A 2F 1C"};

    cout << planeSeatReservation(40, reserve1) << endl;
    cout << planeSeatReservation(2, reserve2) << endl;
    cout << planeSeatReservation(2, "") << endl;
    return 0;
}
