#include <iostream>


int getInteger()
{
    std::cout << "Enter an integer: ";
    int x;
    std::cin >> x;
    return x;
}

char getOperation()
{
    char op;

    do
    {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    }
    while (op!='+' && op!='-' && op!='*' && op!='/');

    return op;
}

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

typedef int (*arithmeticFcn)(int, int);

struct arithmeticStruct
{
   char op;
   arithmeticFcn func;
};

    // or C++11 version using uniform initialization
static const arithmeticStruct arithmeticArray[] {
	{ '+', add },
	{ '-', subtract },
	{ '*', multiply },
	{ '/', divide }
};

arithmeticFcn getArithmeticFcn(char op)
{
    for (const auto &arith : arithmeticArray)
	{
		if (arith.op == op)
			return arith.func;
	}

	return add; // default will be to add
}


int main()
{
    int x = getInteger();
    char op = getOperation();
    int y = getInteger();

    arithmeticFcn fcn = getArithmeticFcn(op);
    std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x, y) << '\n';

    return 0;
}
