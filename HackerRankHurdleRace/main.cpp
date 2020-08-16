#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hurdleRace(int k, vector<int> height) {
    auto highest = max_element(begin(height), end(height));
    int result = 0;
    if(*highest > k)
        result = *highest - k;
    return result;
}

int main()
{
    vector<int> arr{1,6,3,5,2};
     int integer_count = hurdleRace(4, arr);

    cout << "Required Dose: " << integer_count << endl;
    return 0;
}
