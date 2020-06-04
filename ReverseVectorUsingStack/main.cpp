#include <iostream>
#include <vector>
#include "ArrayStack.h"
using namespace std;

template <typename E>
void reverse(vector<E>& V)// reverse a vector
{
    ArrayStack<E> S(V.size());
    for (int i = 0; i < V.size(); i++)// push elements onto stack
        S.push(V[i]);
    for (int i = 0; i < V.size(); i++)// pop them in reverse order
    {
        V[i] = S.top();
        S.pop();
    }
}


int main()
{
    vector<int> arr{9,7,58,6,4,2,8,6,34,9,6};
    reverse(arr);
    for(const auto &elem: arr)
        cout << elem << ", ";
    cout << endl;
    return 0;
}
