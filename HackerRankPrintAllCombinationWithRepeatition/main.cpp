#include <iostream>
#include <cstring>
#include <string>
using namespace std;
void printPermutations(char* str, char* permutations, int last, int index){
   int i, len = strlen(str);
   for ( i = 0; i < len; i++ ) {
      permutations[index] = str[i] ;
      if (index == last)
         cout << permutations << endl;
      else
         printPermutations (str, permutations, last, index+1);
   }
}
int main() {
   char str[] = "ABC";
   cout<<"All permutations of the string with repetition of "<<str<<" are: "<<endl ;
   int len = strlen(str) ;
   char permutations[len];
   printPermutations (str, permutations, len-1, 0);
   return 0;
}
