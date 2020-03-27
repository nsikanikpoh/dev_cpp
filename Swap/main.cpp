#include <iostream>

void mySwap(int &xref, int &yref)
{
    int temp = xref;
    xref = yref;
    yref = temp;

}

int main()
{
    int x = 5;
    int y = 6;
    mySwap(x,y);
    std::cout << "x: \t" << x << '\t' << "y: \t" << y<< std::endl;

    if (x == 6 && y == 5)
		std::cout << "It works!";
	else
		std::cout << "It's broken!";
    return 0;
}
