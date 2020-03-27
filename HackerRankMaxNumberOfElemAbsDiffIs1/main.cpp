
#include <bits/stdc++.h>
using namespace std;

// function to return maximum number of elements
int maxCount(int n,int a[])
{
    // Counting frequencies of elements
    map<int,int> freq;

    for(int i=0;i<n;++i){
        if(freq[a[i]])
            freq[a[i]] += 1;
        else
            freq[a[i]] = 1;
    }

    // Finding max sum of adjacent indices
    int ans = 0, key;

    map<int,int>:: iterator it=freq.begin();

    while(it!=freq.end())
    {
        key = it->first;

        // increment the iterator
        ++it;

        if(freq[key+1]!=0)
            ans=max(ans,freq[key]+freq[key+1]);

    }

    return ans;
}

// Driver Code
int main(){
    int n = 5;
    int arr[] = {2, 2, 3, 4, 5};

    // function call to print required answer
    cout<<maxCount(n,arr);

    return 0;
}


// This code is contributed by Sanjit_Prasad
