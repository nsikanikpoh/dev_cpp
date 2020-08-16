#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Complete the birthday function below.
int birthday(vector<int> s, int d, int m) {
    int squares = 0;
    for(auto it = s.cbegin(); it != s.cend(); ++it){
        if(d == std::accumulate(it, it + m, 0))
            squares++;
    }
    return squares;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
