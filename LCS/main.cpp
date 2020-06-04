#include <iostream>

using namespace std;

//Here we shall discuss a C++ program to find the Longest Subsequence Common
//to All Sequences in a Set of Sequences.
string matchedPrefixtill(string s1, string s2) {
   string res;
   int n1 = s1.length(); //store length of string s1.
   int n2 = s2.length(); //store length of string s2.
   for (int i = 0, j = 0; i <= n1 - 1 && j <= n2 - 1; i++, j++) {
      if (s1[i] != s2[j])
         break;
      res.push_back(s1[i]);
   }
   return (res);
}
string matchedPrefix (string a[], int n) {
   string pre = a[0];
   for (int i = 1; i <= n - 1; i++)
   pre = matchedPrefixtill(pre, a[i]);
   return (pre);
}
int main() {
   string a[] = {"Tutorialspoint", "Tutor", "Tutorials"}; //taking inputs
   int n = sizeof(a) / sizeof(a[0]);
   string res = matchedPrefix(a, n);
   if (res.length())
      cout<<"Longest common subsequence is matched - "<<res.c_str();
   else
      cout<<"No matched prefix";
   return (0);
}



