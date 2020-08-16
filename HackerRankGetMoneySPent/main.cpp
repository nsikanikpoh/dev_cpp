#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the getMoneySpent function below.
 */
int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    /*
     * Write your code here.
     */
     // sort using a lambda expression
    int res = -1;
    std::sort(keyboards.begin(), keyboards.end(), [](int a, int b) {
        return a > b;
    });

     // sort using the default operator<
    std::sort(drives.begin(), drives.end());

    for(auto &k: keyboards)
    {
        for(auto &d:drives)
        {
            if(k+d > b)
                break;
            if(k+d > res)
             res = k+d;
        }
    }
    return res;

}

int main()
{
   vector<int> drives{5,8,12};
   vector<int> keyboards{40,50,60};
    int moneySpent = getMoneySpent(keyboards, drives, 60);

     cout << "Money Spent out of $60: " << moneySpent  << "\n";
    return 0;
}
