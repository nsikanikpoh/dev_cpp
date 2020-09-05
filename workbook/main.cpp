#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

// Complete the workbook function below.
int workbook(int n, int k, vector<int> arr) {
    int page,page_no=1,count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=arr[i];j++)
        {
            page=(j-1)/k+page_no;
            if(page==j)
                count++;
        }
        page++;
        page_no=page;
    }
    return count;
}

int main()
{
    vector<int> v{4, 2, 6, 1, 10};
    cout << workbook(5, 3, v) << endl;
    return 0;
}
