#include <cstdlib>//provides EXIT SUCCESS
#include <iostream>//I/O definitions
#include <vector>//provides vector
#include <algorithm>//for sort, random shuffle


using namespace std;

// make std:: accessible
int main ()
{
    int a[] = {17, 12, 33, 15, 62, 45};
    vector<int> v(a, a + 6);
// v: 17 12 33 15 62 45
// outputs: 6
    cout << v.size() << endl;
// v: 17 12 33 15 62
    v.pop_back();
    cout << v.size() << endl;
// outputs: 5
// v: 17 12 33 15 62 19
    v.push_back(19);
    cout << v.front() << " " << v.back() << endl; // outputs: 17 19
    sort(v.begin(), v.begin() + 4);
// v: (12 15 17 33) 62 19
    v.erase(v.end() - 4, v.end() - 2);
// v: 12 15 62 19
    cout << v.size() << endl;
// outputs: 4
    char b[] = {'b', 'r', 'a', 'v', 'o'};
    vector<char> w(b, b + 5);// w: b r a v o
    random_shuffle(w.begin(), w.end());// w: o v r a b
    w.insert(w.begin(), 's');// w: s o v r a b

    for (vector<char>::iterator p = w.begin(); p != w.end(); ++p)
        cout << *p << " ";// outputs: s o v r a b

    cout << endl;
    return EXIT_SUCCESS;
}
