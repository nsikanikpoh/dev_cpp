#include <iostream>

using namespace std;


//merge sort

//arrays
Algorithm merge(S 1 , S 2 , S):
    Input: Sorted sequences S 1 and S 2 and an empty sequence S, all of which are
        implemented as arrays
    Output: Sorted sequence S containing the elements from S 1 and S 2
    i ← j ← 0
    while i < S 1 .size() and j < S 2 .size() do
        if S 1 [i] ≤ S 2 [ j] then
            S.insertBack(S 1 [i]) {copy ith element of S 1 to end of S}
            i ← i + 1
        else
            S.insertBack(S 2 [ j]) {copy jth element of S 2 to end of S}
            j ← j + 1
    while i < S 1 .size() do {copy the remaining elements of S 1 to S}
        S.insertBack(S 1 [i])
        i ← i + 1
    while j < S 2 .size() do {copy the remaining elements of S 2 to S}
        S.insertBack(S 2 [ j])
    j ← j + 1
//Code Fragment 11.1: Algorithm for merging two sorted  array-based sequences.

//Linked List
Algorithm merge(S 1 , S 2 , S):
    Input: Sorted sequences S 1 and S 2 and an empty sequence S, implemented as
        linked lists
    Output: Sorted sequence S containing the elements from S 1 and S 2
    while S 1 is not empty and S 2 is not empty do
        if S 1 .front().element() ≤ S 2 .front().element() then
            {move the first element of S 1 at the end of S}
            S.insertBack(S 1 .eraseFront())
        else
            {move the first element of S 2 at the end of S}
            S.insertBack(S 2 .eraseFront())
            {move the remaining elements of S 1 to S}
    while S 1 is not empty do
        S.insertBack(S 1 .eraseFront())
            {move the remaining elements of S 2 to S}
    while S 2 is not empty do
        S.insertBack(S 2 .eraseFront())
//Code Fragment 11.2: Algorithm merge for merging two sorted sequences imple-mented as linked lists.



//Quick-Sort
Algorithm QuickSort(S):
    Input: A sequence S implemented as an array or linked list
    Output: The sequence S in sorted order
    if S.size() ≤ 1 then
        return
        {S is already sorted in this case}
    p ← S.back().element()
    {the pivot}
    Let L, E, and G be empty list-based sequences
    while !S.empty() do {scan S backwards, dividing it into L, E, and G}
        if S.back().element() < p then
            L.insertBack(S.eraseBack())
        else if S.back().element() = p then
            E.insertBack(S.eraseBack())
        else {the last element in S is greater than p}
            G.insertBack(S.eraseBack())
    QuickSort(L)
    {Recur on the elements less than p}
    {Recur on the elements greater than p}
    QuickSort(G)
    while !L.empty() do {copy back to S the sorted elements less than p}
        S.insertBack(L.eraseFront())
    while !E.empty() do {copy back to S the elements equal to p}
        S.insertBack(E.eraseFront())
    while !G.empty() do {copy back to S the sorted elements greater than p}
        S.insertBack(G.eraseFront())
    return
        {S is now in sorted order}
//Code Fragment 11.5: Quick-sort for an input sequence S implemented with a linked
//list or an array.


Algorithm inPlaceQuickSort(S, a, b):
    Input: An array S of distinct elements; integers a and b
    Output: Array S with elements originally from indices from a to b, inclusive,
        sorted in nondecreasing order from indices a to b
    if a ≥ b then return
        {at most one element in subrange}
        p ← S[b]
        {the pivot}
        l ← a
        {will scan rightward}
        r ← b − 1
        {will scan leftward}
        while l ≤ r do
            {find an element larger than the pivot}
            while l ≤ r and S[l] ≤ p do
                l ← l + 1
                {find an element smaller than the pivot}
            while r ≥ l and S[r] ≥ p do
                r ← r − 1
        if l < r then
            swap the elements at S[l] and S[r]
        {put the pivot into its final place}
        swap the elements at S[l] and S[b]
        {recursive calls}
        inPlaceQuickSort(S, a, l − 1)
        inPlaceQuickSort(S, l + 1, b)
        {we are done at this point, since the sorted subarrays are already consecutive}
//Code Fragment 11.6: In-place quick-sort for an input array S.

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
