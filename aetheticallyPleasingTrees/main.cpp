#include <iostream>
#include <vector>

using namespace std;

int aetheticallyPleasingTrees(vector<int>& A)
{
 int prunes = 0;
 for(int i{0}; i<A.size(); i++)
 {
    if( abs(A[i] - A[i+1]) == 1 && abs(A[i+1] - A[i+2]) == 1)
    {
        A[i+1] -= 2;
        i += 2;
        prunes++;
        continue;
    }

     if( A[i] == A[i+1])
    {
        A[i+1] -= 2;
        prunes++;
        continue;
    }
 }
 return prunes;
}


int main()
{
vector<int> trees1{5,4,3,2,6};
vector<int> trees2{3,7,4,5};
vector<int> trees3{1, 3, 1, 2};
vector<int> trees4{3, 4, 5, 3, 7};
vector<int> trees5{1, 2, 4, 4, 2, 5};

    cout << aetheticallyPleasingTrees(trees1) << endl;
    cout << aetheticallyPleasingTrees(trees2) << endl;
    cout << aetheticallyPleasingTrees(trees3) << endl;
    cout << aetheticallyPleasingTrees(trees4) << endl;
    cout << aetheticallyPleasingTrees(trees5) << endl;
    return 0;
}
