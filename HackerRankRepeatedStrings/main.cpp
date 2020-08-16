#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
//handy function to repeat a string number of times.
 std::string repeat(const std::string& input, size_t num)
 {
    std::ostringstream os;
    std::fill_n(std::ostream_iterator<std::string>(os), num, input);
    return os.str();
 }


long repeatedString(string s, long n) {
    auto repetition = n / s.size();
    auto partial = n % s.size();
    auto aCountInString = count(begin(s), end(s), 'a');
    auto aCountInPartial = count(begin(s), begin(s) + partial, 'a');
    return aCountInString * repetition + aCountInPartial;
}

int main()
{


    long result = repeatedString("aba", 10);

    cout << result << "\n";



    return 0;
}
