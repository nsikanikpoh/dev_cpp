#include <iostream>
#include <vector>

using namespace std;

int nonDivisibleSubset(int k, vector<int> s) {
    std::vector<int> freq(k);
    for (int& i: s)
        freq[i%k]++;
    int count = 0;
    for (int i = 1; i <= k/2; i++)
    {
    	if(i != k-i)
        	count += max(freq[i], freq[k-i]);
        else
        	count += 1;
    }
    if(freq[0] != 0)
    	count += 1;
    return count;
}

int main()
{
vector<int> rd = {19,10,12,10,24,25,22};
    cout << nonDivisibleSubset(4, rd) << endl;
    return 0;
}
