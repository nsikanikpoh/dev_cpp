#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string convertToBinary(int n, std::string& res)
{
    if (n > 1) // we only recurse if n > 1, so this is our termination case for n == 0
        convertToBinary(n / 2, res);
    res += std::to_string(n % 2);
    return res;
}


int solution(int N)
{
    // write your code in C++14 (g++ 6.2.0)
    std::string res = "";
    std::string binary = convertToBinary(N, res);
    std::cout << binary << std::endl;
    std::vector<int> res_container;
    int counter = 0;
    for(char &i: binary)
    {
        if(i == '1')
        {
            res_container.push_back(counter);
            counter = 0;
        }

        else
            counter++;

    }
    auto it = std::max_element(std::begin(res_container), std::end(res_container));
    return *it;
}
int main()
{
    std::cout << solution(1041) << std::endl;
    std::cout << solution(32) << std::endl;
    return 0;
}
