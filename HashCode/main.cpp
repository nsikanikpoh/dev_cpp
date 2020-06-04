#include <iostream>

using namespace std;


int hashCode(const char* p, int len)// hash a character array
{
    unsigned int h = 0;
    for (int i = 0; i < len; i++)
    {
        h = (h << 5) | (h >> 27);// 5-bit cyclic  shift
        h += (unsigned int) p[i];// add in next character
    }
    return hashCode(int(h));
}



int hashCode(const float& x)// hash a float
{
    int len = sizeof(x);
    const char* p = reinterpret cast<const char*>(&x);
    return hashCode(p, len);
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
