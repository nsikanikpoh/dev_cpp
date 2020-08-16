#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int sea_level = 0;
    int valley = 0;
    char * char_array = new char [n+1];
    strcpy (char_array, s.c_str());
    for(int i = 0; i<n; i++)
    {
       // cout << char_array[i] << '\n';
        if(char_array[i] == 'D')
        {
            sea_level -= 1;
        }else if(char_array[i] == 'U'){
            sea_level += 1;
        }
         cout << sea_level << '\n';
        if(sea_level == 0 && char_array[i] == 'U')
        {
               valley += 1;
        }
    }
    return valley;

}

int main()
{
    int result = countingValleys(8, "UDDDUDUU");

    cout << "result: "<< result << "\n";



    return 0;
}
