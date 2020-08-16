#include <iostream>
#include <vector>

using namespace std;

vector<int> breakingRecords(vector<int> scores) {
    int highest_score = scores[0];
    int lowest_score = scores[0];
    int count_high = 0;
    int count_low = 0;
    for(auto &s: scores)
    {
        if(s > highest_score)
         {
             highest_score = s;
             count_high++;
         }
         if(s < lowest_score)
         {
             lowest_score = s;
             count_low++;
         }
    }
    vector<int> record{count_high, count_low};
    return record;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
