#include <iostream>
#include <vector>

using namespace std;

//A coding of in-place quick-sort, assuming distinct elements.
// quick-sort S
template <typename E, typename C>
void quickSort(std::vector<E>& S, const C& less)
{
    if (S.size() <= 1)
        return;// already sorted
    quickSortStep(S, 0, S.size()-1, less);// call sort utility
}
template <typename E, typename C>
void quickSortStep(std::vector<E>& S, int a, int b, const C& less)
{
    if (a >= b)
        return;// 0 or 1 left? done
    E pivot = S[b];// select last as pivot
    int l = a;// left edge
    int r = b - 1;// right edge
    while (l <= r)
    {
        while (l <= r && !less(pivot, S[l]))
            l++;// scan right till larger
        while (r >= l && !less(S[r], pivot))
            r--;// scan left till smaller
        if (l < r)// both elements found
            std::swap(S[l], S[r]);
    }// until indices cross
    std::swap(S[l], S[b]);// store pivot at l
    quickSortStep(S, a, l-1, less);// recur on both sides
    quickSortStep(S, l+1, b, less);
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
