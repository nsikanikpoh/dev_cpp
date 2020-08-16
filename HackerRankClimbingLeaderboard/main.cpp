#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;


vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    sort(begin(scores), end(scores),[](int a, int b){return a > b;});

    map<int, int> ranking;
    vector<int> result;
    int rank = 1;
    int old_rank = scores[0];

    ranking[old_rank] = rank;
     for (int &x : scores)
     {
       auto search = ranking.find(x);
       if(search == ranking.end())
       {
           if(x < old_rank){
               ranking[x] = ++rank;
               old_rank = x;
           }

       }
    }

     for(int &el:alice)
    {
        auto it = ranking.upper_bound(el);
        if((*it).second == 0)
            result.push_back(1);
        else
            result.push_back((*it).second + 1);
    }


    return result;

}

int main()
{
    vector<int> scores{100, 100, 50, 40, 40, 20, 10};
    vector<int> alice{5, 25, 50, 120};
    vector<int> arr = climbingLeaderboard(scores, alice);

    for(auto &i: arr)
        cout << "score: " << i <<'\n';


    return 0;
}
