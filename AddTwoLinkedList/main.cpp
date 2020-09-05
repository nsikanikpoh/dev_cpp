#include <iostream>
#include <numeric>
#include <list>
#include <string>

using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::list<T>& v)
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}


int main()
{
    list<int> a{2, 4, 3},  b{5, 6, 4};
    list<char> result;
    string num1 = "", num2 = "";

    for( auto it = a.rbegin(); it != a.rend(); it++)
    {
        string i = to_string(*it);
        num1 += i;
    }

    for( auto it = b.rbegin(); it != b.rend(); it++)
    {
        string i = to_string(*it);
        num2 += i;
    }

    int sum = stoi(num1) + stoi(num2);
    string sum_string = to_string(sum);
    for( auto it = sum_string.rbegin(); it != sum_string.rend(); it++)
        result.push_back(*it);

    cout << a << endl;
    cout << b << endl;
    cout << result << endl;
    return 0;
}
