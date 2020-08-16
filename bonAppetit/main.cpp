#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Complete the bonAppetit function below.
void bonAppetit(vector<int> bill, int k, int b) {
    int sum = accumulate(begin(bill), end(bill), 0);
    (b == (sum - bill[k])/2) ? cout << "Bon Appetit" << '\n' : cout << b - (sum - bill[k])/2 << '\n';
}


int main()
{
    vector<int> bill {4,10,2,9};
    bonAppetit(bill, 1, 12);
    return 0;
}
