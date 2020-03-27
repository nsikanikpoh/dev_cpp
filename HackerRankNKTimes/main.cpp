#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// A structure to store an element and its current count
struct Element
{
    int value;  // Element
    int count;  // Count
};

//Function to print elements whose occurences is:
//Greater than n/k
void CountGreaterThan(int array[], int n, int k)
{
    //k must be greater than 1
    if (k <= 1)
    {
       return;
    }
    //Temporary array is temp and size is k-1
    //Initialize all elemets count equal to 0
    struct Element temp[k-1];
    for (int i=0; i<k-1; i++)
    {
        temp[i].count = 0;
    }
    //If element already present then increment count
    //If not present and position available then:
    //add element with count equal to 1
    //If there is new element and no available space then:
    //decrese count of all elements by 1
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j=0; j<k-1; j++)
        {
            if (temp[j].value == array[i])
            {
                 temp[j].count = temp[j].count + 1;
                 break;
            }
        }
        //new element comes
        //position available
        if (j == k-1)
        {
            int p;
            for (p=0; p<k-1; p++)
            {
                if (temp[p].count == 0)
                {
                    temp[p].value = array[i];
                    temp[p].count = 1;
                    break;
                }
            }
            //new element comes
            //no available space to add element
            if (p == k-1)
                for (p=0; p<k; p++)
                {
                    temp[p].count = temp[p].count + 1;
                }
        }
    }
    //In final temp[]
    //check if elements actual count is greater than n/k
    //print if count grater than n/k
    cout<<"Final Output:"<<endl;
    for (int i=0; i<k-1; i++)
    {
        int correct_count = 0;
        for (int j=0; j<n; j++)
        {
            if (array[j] == temp[i].value)
            {
                correct_count++;
            }
        }
        if (correct_count > n/k)
        {
           cout << "Element: " << temp[i].value<< " with count: " << correct_count << endl;
        }
    }
}

/* Driver program to test above function */
int main()
{
    int input_array[] = {1, 1, 1, 2, 2, 2, 2, 4, 4, 5};
    int size = sizeof(input_array)/sizeof(int);
    int k = 5;
    CountGreaterThan(input_array,size,k);
    return 0;
}
