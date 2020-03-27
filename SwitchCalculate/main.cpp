#include <iostream>

void calculate(int a, int b, char op)
{
    using namespace std;

    switch(op)
    {
    case '+':
        cout << a + b << '\n';
        break;
    case '-':
        cout << a - b << '\n';
        break;
    case '*':
        cout << a * b << '\n';
        break;
    case '/':
        cout << a / b << '\n';
        break;
    case '%':
        cout << a % b << '\n';
        break;
    default:
        cout << "calculate(): Unhandled case\n";
        break;

    }
}

int main()
{
 calculate(5, 2, '+');
 calculate(5, 2, 'l');

    return 0;
}
