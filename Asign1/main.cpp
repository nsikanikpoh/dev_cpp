#include <iostream>

bool isZero(int num)
{
    if(num == 0)
        return true;
    return false;
}

double performCalc(double firstNum, double secondNum, char operand)
{
    if (operand == '+')
        return firstNum + secondNum;
    else if (operand == '-')
        return firstNum - secondNum;
    else if (operand == '*')
        return firstNum * secondNum;
    else
        return firstNum / secondNum;
}

double getNumber()
{
    std::cout << "Enter Floating point number: \n";
    double x;
    std::cin >> x;
    return x;
}

char getOperand()
{
    std::cout << "enter one of the following +, -, *, or / \n";
    char op;
    std::cin >> op;
    return op;
}

bool isNotValidSimbol(char input)
{
    if (input == '+')
        return false;
    else if (input == '-')
        return false;
    else if (input == '*')
        return false;
    else if (input == '/')
        return false;
    else
        return true;

}

void printResult(double firstNum, double secondNum, char operand, double result)
{
    std::cout << firstNum << '\t' << operand << '\t' << secondNum << '\t' << "= \t" << result << '\n';
}


int main()
{
    while (true)
    {
        double firstNum{ getNumber() };
        if (isZero(firstNum))
        {
            std::cout << "warning, you entered zero value, please enter a non zero value \n";
            firstNum = getNumber();
        }

        double secondNum{ getNumber() };
        if (isZero(secondNum))
        {
            std::cout << "warning, you entered zero value, please enter a non zero value \n";
            secondNum = getNumber();
        }

        char operand{ getOperand() };
        if (isNotValidSimbol(operand))
        {
            std::cout << "warning, you did not enter a valid operator\n";
            operand =  getOperand();
        }

         printResult(firstNum, secondNum, operand, performCalc(firstNum, secondNum, operand));

         std::cout << "********************************************************************\n";

    }
    return 0;
}
