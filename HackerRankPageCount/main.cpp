#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    /*
     * Write your code here.
     */
    return min(p/2, (n/2 - p/2));
}


int main()
{
     int result = pageCount(6, 2);

    cout << "page turn count: " << result << "\n";
    return 0;
}
