#include<iostream>
using namespace std;
main() {
   int n;
   char hex_string[20];
   cout << "Enter a number: ";
   cin >> n;
   sprintf(hex_string, "%X", n); //convert number to hex
   cout << hex_string;
}
