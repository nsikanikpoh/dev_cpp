#include <iostream>

constexpr int kNotFound{-1};

int BinarySearch(int element, const int* v, int size)
{
    int left{0};
    int right{size - 1};

    while(left <= right)
    {

        int middle = (left + right) / 2;
        if(v[middle] == element)
        {
            //element found
            return middle;
        }
        else if (v[element] < element)
        {
          //search in the right-half: (middle+1..right)
          left = middle + 1;

        }
        else if (v[element] > element)
        {
         //search in the left-half (left...middle-1)
         right = middle - 1;
        }
    }
    return kNotFound;// element not found
}

int main()
{

    return 0;
}
