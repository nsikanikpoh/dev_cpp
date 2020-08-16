#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int commonChild(string s1, string s2)
{
     int n = s1.size();
    vector<vector<int> > common(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                common[i][j] = 0;
                continue;
            }
            if (s1[i - 1] == s2[j - 1]) {
                common[i][j] = common[i - 1][j - 1] + 1;
                continue;
            }
            common[i][j] = max(common[i - 1][j], common[i][j - 1]);

        }
    }
    return common[n][n];
}

int main()
{
    cout << commonChild("HARRY", "SALLY") << endl;
    cout << commonChild("AA", "BB") << endl;
    cout << commonChild("SHINCHAN", "NOHARAAA") << endl;
    cout << commonChild("OUDFRMYMAW", "AWHYFCCMQX") << endl;
    return 0;
}
