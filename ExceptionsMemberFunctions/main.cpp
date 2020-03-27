#include <iostream>


int& IntArray::operator[](const int index)
{
    if (index < 0 || index >= getLength())
        throw index;

    return m_data[index];
}

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
