#include <iostream>
#include <vector>

using namespace std;

string highestValuePalindrome(string s, int n, int k)
{
    int i=0,j=s.length()-1;
    int temp=k;
    vector<bool> rec(s.length(),false);
    while(temp>=0)
    {
        if(i>=j)
            break;
        if(s[i] != s[j])
        {
            s[i] = s[j] = max(s[i],s[j]);
            temp--;
            rec[i]=true;
        }
        i++;
        j--;
    }
    if(temp<0)
        return "-1";
    i=0;
    j=s.size()-1;
    while(temp>0)
    {
        if(i==j)
        {
            s[i] = '9';
            break;
        }
        if(i>j)
            break;
        if(s[i]!='9')
        {
            if(rec[i])
            {
                temp--;
                s[i] = s[j] = '9';
            }
            else if(temp>1)
            {
                temp-=2;
                s[i] = s[j] = '9';
            }
        }
        i++;
        j--;
    }
    return s;
}

int main()
{
    cout << highestValuePalindrome("092282", 6, 3) << endl;
    cout << highestValuePalindrome("0011", 4, 1) << endl;
    cout << highestValuePalindrome("3943", 4, 1) << endl;
    return 0;
}
