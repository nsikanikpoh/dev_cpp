#include <iostream>

using namespace std;

void bubbleSort1(Sequence& S)
{
// bubble-sort by indices
    int n = S.size();
    for (int i = 0; i < n; i++)
    {
// i-th pass
        for (int j = 1; j < n-i; j++)
        {
            Sequence::Iterator prec = S.atIndex(j-1);
// predecessor
            Sequence::Iterator succ = S.atIndex(j);
// successor
// swap if out of order
            if (*prec > *succ)
            {
                int tmp = *prec;
                *prec = *succ;
                *succ = tmp;
            }
        }
    }




    void bubbleSort2(Sequence& S)
    {
// bubble-sort by positions
        int n = S.size();
        for (int i = 0; i < n; i++)
        {
// i-th pass
            Sequence::Iterator prec = S.begin();
// predecessor
            for (int j = 1; j < n-i; j++)
            {
                Sequence::Iterator succ = prec;
                ++succ;
// successor
// swap if out of order
                if (*prec > *succ)
                {
                    int tmp = *prec;
                    *prec = *succ;
                    *succ = tmp;
                }
                ++prec;
// advance predecessor
            }
        }
    }


    int main()
    {
        cout << "Hello world!" << endl;
        return 0;
    }
