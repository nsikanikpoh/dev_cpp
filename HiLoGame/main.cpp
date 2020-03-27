#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time

namespace MyRandom
{
// Initialize our mersenne twister with a random seed based on the clock (once at system startup)
std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int getRandomNumber(int min, int max)
{
    std::uniform_int_distribution<> die{ min, max }; // we can create a distribution in any function that needs it
    return die(MyRandom::mersenne); // and then generate a random number from our global generator
}

int checkEndGame()
{

    while (true) // Loop until user enters a valid input
    {
        std::cout << "Would you like to play again (y/n)? ";
        char op;
        std::cin >> op;

        // Chars can accept any single input character, so no need to check for an invalid extraction here

        std::cin.ignore(32767,'\n'); // remove any extraneous input

        // Check whether the user entered meaningful input
        if (op == 'y' || op == 'n')
            if(op == 'y')
                return 0; // return it to the caller
            else
                return 1;
        else // otherwise tell the user what went wrong
            std::cout << "Would you like to play again (y/n)? ";
    } // and try again
}


int main()
{
    bool gameInitiator{true};
    while(gameInitiator)
    {
        int computerGuess {getRandomNumber(1, 100)};
        int count {1};
        std::cout << "Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.\n";
        while (count <= 7) // Loop until user enters a valid input
        {
            std::cout << "Guess #: " << count << "  ";
            int inp;
            std::cin >> inp;

            // Check for failed extraction
            if (std::cin.fail()) // has a previous extraction failed?
            {
                // yep, so let's handle the failure
                std::cin.clear(); // put us back in 'normal' operation mode
                std::cin.ignore(32767,'\n'); // and remove the bad input
                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                std::cin.ignore(32767,'\n'); // remove any extraneous input

                // the user can't enter a meaningless double value, so we don't need to worry about validating that
                if(inp < computerGuess)
                    std::cout << "Your guess is too low.\n";
                if(inp > computerGuess)
                    std::cout << "Your guess is too high.\n";
                if(inp == computerGuess)
                {

                    std::cout << "Correct! You win!\n";
                    int t{checkEndGame()};
                    switch(t)
                    {
                    case 1:
                        std::cout << "Thank you for playing.";
                        gameInitiator = false;
                        break;
                    case 0:
                        break;
                    }
                    break;
                }


                if(count == 7)
                {
                    std::cout << "Sorry, you lose.  The correct number was " << computerGuess << ".\n";

                    int t{checkEndGame()};
                    switch(t)
                    {
                    case 1:
                        std::cout << "Thank you for playing.";
                        gameInitiator = false;
                        break;
                    case 0:
                        break;
                    }
                }
            }
            ++count;
        }

    }

    return 0;
}
