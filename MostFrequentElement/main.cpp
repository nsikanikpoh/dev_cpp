#include <vector>
#include  <unordered_map>
#include <iostream>

template<typename T>
T most_frequent_element(std::vector<T> const& v)
{
    // Precondition: v is not empty
    std::unordered_map<int, int> frequencyMap;
    int mostFrequentElement = 0;
    int max_count = 0;

    for (int x : v)
    {
        auto search = frequencyMap.find(x);
        if(search != frequencyMap.end())
        {
            int new_highest_frequence = ++frequencyMap[x];
            frequencyMap[x] = new_highest_frequence;
            if(new_highest_frequence > max_count)
            {
                max_count = new_highest_frequence;
                mostFrequentElement = x;
            }
        }
        else
        {
            frequencyMap[x] = 0;
        }

    }
    return mostFrequentElement;
}


int main()
{
    std::vector<int> v { 1, 3, 5, 1,6, 6, 1,2, 3, 4,1, 3,1, 5,1, 1};
    std::cout << most_frequent_element(v);
}
