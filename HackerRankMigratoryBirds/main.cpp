#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr)
{
    int one=0,two=0,three=0,four=0,five=0;
    int arr_count = arr.size();
    for(int i=0; i<arr_count; i++)
    {
        switch(arr[i])
        {
        case 1:
            one++;
            break;
        case 2:
            two++;
            break;
        case 3:
            three++;
            break;
        case 4:
            four++;
            break;
        case 5:
            five++;
            break;
        default:
            five++;
        }
    }
    int bird[5]= {one,two,three,four,five};
    int max=0,ans=0;
    for(int i=0; i<5; i++)
    {
        if(bird[i]>max)
        {
            max=bird[i];
            ans=i+1;
        }
    }
    return ans;
}


int main()
{
    vector<int> arr{1,2,3,4,5,4,3,2,1,3,4};
    int result = migratoryBirds(arr);
    cout << "Result: " << result <<'\n';
    return 0;
}
