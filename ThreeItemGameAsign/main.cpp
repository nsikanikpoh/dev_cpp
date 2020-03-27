#include <iostream>

enum Items
{
    HEALTH_OPTIONS,
    TORCHES,
    ARROWS,
    ITEMS_LENGTH
};

int  countTotalItems(int *array)
{
    int sum(0);
    for(int index = 0; index<ITEMS_LENGTH; ++index)
        sum += array[index];
    return sum;
}

int main()
{
    int itemArrays[ITEMS_LENGTH];
    itemArrays[HEALTH_OPTIONS] = 2;
    itemArrays[TORCHES] = 5;
    itemArrays[ARROWS] = 10;

    std::cout << "Total: " <<  countTotalItems(itemArrays)<< std::endl;
    return 0;
}
