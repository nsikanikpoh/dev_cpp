#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int droppedRequests(vector<int> &requestTime)
{

  std::unordered_map<int, int> frequencyMap;
    for (int &x: requestTime)
    {
        auto search = frequencyMap.find(x);
        if(search != frequencyMap.end())
            frequencyMap[x] = ++frequencyMap[x];
        else
            frequencyMap[x] = 1;
    }

    for(auto &i: frequencyMap)
      cout << i.first << " second: " << i.second << '\n';
    int droppedReqCount{0};
    int currentSecond{requestTime[0]};
    int currentSecondCount{0};
    int reqCount{0};


    for (int i{0}; i < requestTime.size(); i++)
    {

        if(currentSecondCount >= 3 && requestTime[i] == currentSecond)
        droppedReqCount++;
        else if((reqCount >= 20 && requestTime[i] <= 10) || (reqCount >= 20 && requestTime[i]-10 > 0 && frequencyMap[requestTime[i] > 1]) )
        droppedReqCount++;
        else if(reqCount >= 60 && requestTime[i] <= 60 || (reqCount >= 60 && requestTime[i]-60 > 0 && frequencyMap[requestTime[i] > 1]) )
            droppedReqCount++;


        if(requestTime[i] != currentSecond)
        {
            currentSecondCount = 1;
            currentSecond = requestTime[i];
        }
        else
            currentSecondCount++;

        reqCount++;

    }

    return droppedReqCount;
}

int main()
{
    //vector<int> res{1,1,1,1,2,2,2,3,3,3,3,4,5,5,5,6,6,6,6,7,7,7,8,8,8,8,9,9,9,9,9,10,10,11,11,11,11,11,11,12,12,12,12,12,12,12,13,13,13,13,14,14,14,14,14,16,16,16,16,16,16,17,17,17,18,18,18,18,18,18,18,18,19,19,19,19,19,19,19,20,20,20,20,20};
    vector<int> res{1,1,1,1,2,2,2,3,3,3,3,4,5,5,5,6,6,6,6,7,7,7,8,8,8,8,9,9,9,9,9,10,10,11,11,11,11,11,11,12,12,12,12,12,12,12,13,13,13,13,14,14,14,14,14,16,16,16,16,16,16,17,17,17,18,18,18,18,18,18,18,18,19,19,19,19,19,19,19,20,20,20,20,20};

    cout << droppedRequests(res) << endl;
    return 0;
}

