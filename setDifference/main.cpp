 #include <algorithm>
    #include <iostream>
    #include <iterator>
    #include <vector>
    #include <set>
#include <string>

using namespace std;
set<string> a;
set<string> b;
set<string> result;

    int main()
    {
       int aa[] = { 1, 2, 3 };
       int bb[] = { 3, 4, 5 };
       std::vector<int> cv;
       std::set_difference(std::begin(aa), std::end(aa),
                           std::begin(bb), std::end(bb),
                           std::back_inserter(cv));
       for (auto& s : cv)
         std::cout << s << "\n";



    a.insert("x");
    a.insert("a");
    a.insert("x");
 a.insert("b");

    b.insert("b");
    a.insert("b");
    a.insert("x");
    a.insert("x");

    set_difference( a.begin(), a.end(), b.begin(), b.end(), inserter(result, result.begin()));

    cout << "Difference" << endl << "-------------" << endl;

    for (set<string>::const_iterator i = result.begin(); i != result.end(); ++i) {
        cout << *i << endl;
    }

    result.clear();
    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(result, result.begin()));

    cout << "Symmetric Difference" << endl << "-------------" << endl;

    for (set<string>::const_iterator i = result.begin(); i != result.end(); ++i) {
        cout << *i << endl;
    }
    }
