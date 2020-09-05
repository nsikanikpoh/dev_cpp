#include <iostream>

using namespace std;

long strangeCounter(long t) {
    long v=4;

    while(v<=t)
    {
        v=v*2+2;
    }
    return v-t;
}
int main()
{
    cout << strangeCounter(4) << endl;
    return 0;
}
