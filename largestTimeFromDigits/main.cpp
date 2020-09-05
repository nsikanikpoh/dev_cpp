#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   void depthFirstSearch(vector<int>& A, string& resulting_time, string& currentDigit) {
      if (currentDigit.size() == 5) {
         if (isValidTime(currentDigit) && currentDigit > resulting_time)
            resulting_time = currentDigit;
            return;
         }
         for (int i = 0; i < 4; ++i) {
            if (A[i] != -1) {
               int tempDigit = A[i];
               currentDigit += A[i] + '0';
            if (currentDigit.size() == 2)
               currentDigit += ':';
               A[i] = -1;
               depthFirstSearch(A, resulting_time, currentDigit);
               A[i] = tempDigit;
               currentDigit.pop_back();
               if (currentDigit.size() == 2)
                  currentDigit.pop_back();
            }
         }
   }
   bool isValidTime(const string str) {
      if (str[0] > '2')
         return false;
         if (str[0] == '2' && str[1] > '3')
            return false;
         if (str[3] > '5')
            return false;
         return true;
   }
   string largestTimeFromDigits(vector<int>& A) {
      string resulting_time = "", starting_digit = "";
      depthFirstSearch(A, resulting_time, starting_digit);
      return resulting_time;
   }
};

main(){
Solution ob;
vector<int> v = {1,2,3,4};
cout << (ob.largestTimeFromDigits(v)) << endl;

vector<int> v1 = {0, 0, 0, 9 };
cout << (ob.largestTimeFromDigits(v1)) << endl;

vector<int> v2 = {5,5,5,5};
cout << (ob.largestTimeFromDigits(v2)) << endl;

vector<int> v3 = {2,0,6,6};
cout << (ob.largestTimeFromDigits(v3)) << endl;
}
