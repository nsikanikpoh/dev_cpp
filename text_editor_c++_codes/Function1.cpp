#include <iostream>

// Definition of user-defined function doPrint()
void doPrint() //doPrint() is the call func in this example
{
	std::cout<< "In doPrint()\n";
}

int main(){
	std::cout << "starting main()\n";
	doPrint();
	std::cout << "ending main()\n";
	return 0;
}