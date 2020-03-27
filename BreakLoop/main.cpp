#include <iostream>

int breakOrReturn()
{
    while (true) // infinite loop
    {
        std::cout << "Enter 'b' to break or 'r' to return: ";
        char ch;
        std::cin >> ch;

        if (ch == 'b')
            break; // execution will continue at the first statement beyond the loop

        if (ch == 'r')
            return 1; // return will cause the function to immediately return to the caller (in this case, main())
    }

    // breaking the loop causes execution to resume here

    std::cout << "We broke out of the loop\n";

    return 0;
}


int main()
{


    int count(0);
    do
    {
        if (count == 5)
            continue; // jump to end of loop body
        std::cout << count << " ";

        // The continue statement jumps to here
    }
    while (++count < 10);   // this still executes since it's outside the loop body

std::cout << '\n';

    for (int count=0; count  < 20; ++count)
    {
        // if the number is divisible by 4, skip this iteration
        if ((count % 4) == 0)
            continue; // jump to end of loop body

        // If the number is not divisible by 4, keep going
        std::cout << count << std::endl;

        // The continue statement jumps to here
    }



    int sum = 0;

    // Allow the user to enter up to 10 numbers
    for (int count=0; count < 10; ++count)
    {
        std::cout << "Enter a number to add, or 0 to exit: ";
        int num;
        std::cin >> num;

        // exit loop if user enters 0
        if (num == 0)
            break;

        // otherwise add number to our sum
        sum += num;
    }

    std::cout << "The sum of all the numbers you entered is " << sum << "\n";




    int returnValue = breakOrReturn();
    std::cout << "Function breakOrReturn returned " << returnValue << '\n';

    return 0;
}
