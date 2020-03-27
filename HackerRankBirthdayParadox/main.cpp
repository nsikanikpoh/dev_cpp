#include <cstdlib>
#include <iostream>
#include <ctime>
// C++ program to approximate number of people in Birthday Paradox
// problem
#include <cmath>
using namespace std;

// Returns approximate number of people for a given probability
int find(double p)
{
    return ceil(sqrt(2*365*log(1/(1-p))));
}

int main()
{
    srand(time(NULL));
    int birthdays[10000][50];
    int numMatches;
    int trials=10000,check;
    for(int n=0; n<trials; n++)
    {
        for(int j=0; j<50; j++)
        {
            birthdays[n][j]=rand()%365+1;
        }
    }
    for(int i=2; i<=50; i++)
    {
        numMatches=0;
        for(int n=0; n<trials; n++)
        {
            check=1;
            for(int j=0; j<i; j++)
            {
                for(int k=j+1; k<=i; k++)
                {
                    if(birthdays[n][j]==birthdays[n][k]&&check)
                    {
                        numMatches++;
                        check=0;
                    }
                }
            }
        }
        cout << "Probability of " << i << " people in a room sharing a birthday is \t" <<
             (static_cast<float>(numMatches) / (trials)) << endl;
    }
}
