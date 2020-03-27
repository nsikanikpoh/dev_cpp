// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the required count
int findPermutation(string str, int k)
{
    bool has[26] = { false };

    // To store the count of distinct characters in str
    int cnt = 0;

    // Traverse str character by character
    for (int i = 0; i < str.length(); i++) {

        // If current character is appearing
        // for the first time in str
        if (!has[str[i] - 'a']) {

            // Increment the distinct character count
            cnt++;

            // Update the appearance of the current character
            has[str[i] - 'a'] = true;
        }
    }

    long long int ans = 1;

    // Since P(n, r) = n! / (n - r)!
    for (int i = 2; i <= cnt; i++)
        ans *= i;

    for (int i = cnt - k; i > 1; i--)
        ans /= i;

    // Return the answer
    return ans;
}

// Driver code
int main()
{
    string str = "geeksforgeeks";
    int k = 4;
    cout << findPermutation(str, k) << '\n';

    string str3 = "cat";
    int k3 = 3;
    cout << findPermutation(str3, k3)  << '\n';

    return 0;
}
