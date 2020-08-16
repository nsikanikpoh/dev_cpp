#include <iostream>
#include <string>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n)
{
    int count{0};
    std::string num = std::to_string(n);
    for(int i = 0; i<num.size(); i++)
    {
        char c = num[i];
        int rep = c - '0';
        if(rep == 0)
            continue;
        if(n%rep == 0)
            count++;
    }
    return count;
}


int main()
{

    int result = findDigits(102);
    std::cout << "Result: " << result <<'\n';
    return 0;
}
