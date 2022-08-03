/*
* Aaron Weitekamp, Section 10
 * Course: CS215-00x
 * Project: Lab6 (as part of Project 1)
 * Purpose: It focuses on testing the defintion of function named computer_play
 *          the computer takes either “smart” move or “non-smart” move, respectively.
 *          Under “smart-move” mode, the computer needs to make the following legal move to
 *                win the game: take off enough marbles to make the size of the remaining pile
 *                a power of two minus one (1, 3, 7, 15, 31 are some examples of the power of two minus 1)
 *                if the current pile size is not one of those power of two minus 1.
 *                When the current pile size is already a 2’s power – 1, make a random move
 *                taking at least one but at most half of the marbles.
 *          On the other hand, when the computer is under “non-smart-move” mode,
 *                the computer makes a random legal move: taking at least one but at most half of the marbles.
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int PILE_MAX = 50;
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);  //use code 232 in ASCII Table to represent marble
const int WIDTH = 10;   // for layout purpose

// display marbles on the pile
void printMarbles(int pile);

//This functions purpose is to simulate the computer's choice for both smart and non-smart moves
//Under smart move the computer takes away just enough marbles so the pile is equal to a power of 2 minus one, if it's already a power of two minus one it removes a number of marbles between one and up to half the current pile size
//Under a non-smart move the computer always take a random number between 1 and the up to half the current pile size
void computer_play(int& pile, bool smart)
{
    cout << "Computer plays: \n";
    double powerCheck;

    //creates a random number between 1 and the pile size /2
    // the seed used is based on the time you start the program
    int seed = static_cast<int>(time(0));
    srand(seed);
    int random = 1 + rand() % pile / 2;

    //will run when the computer is playing smart
    if (smart == true)
    {
        //intializes the bool used to exit the nested for loops as false
        bool end = false;

        //loop will run until it has checked all numbers from the current pile size down until 2
        for (int marbles = pile; marbles > 1; marbles--)
        {
            //exits the loop when a power of 2 minus one has been found
            if (end == true)
                break;

            //loops until it has checked all powers of a number from 2-9
            for (double power = 2.0; power < 10; power++)
            {
                //calculates whether a number is the power of 2 minus 1
                powerCheck = pow(marbles + 1, 1.0 / power);
                //cout << " marbles: " << marbles << " power: " << power << " result: " << powerCheck << endl;

                //will run if the number is a power of two minus one, or the remaining pile size is 2
                if (powerCheck == 2 || marbles == 2)
                {
                    //checks whether the current pile size was already a power of two minus one
                    if (pile - marbles != 0)
                    {
                        //takes enough marbles so the pile size is equal to a power of two minus one, and outputs this to the user
                        cout << "The computer takes " << pile - marbles << " marbles. \n";
                        pile = marbles;
                    }
                    //will run if the number was not already a power of two minus one
                    else
                        if (random > pile / 2)
                        {
                            //makes the computer not take more than half the remaining pile if it was larger than half
                            pile = (pile - random) + 1;
                            cout << "The computer takes " << random - 1 << " marbles" << endl;
                        }
                        else
                        {
                            pile -= random;
                            cout << "The computer takes " << random << " marbles." << endl;
                        }
                    //sets bool to true so after this for loop is broken out of the second for loop is also broken out of
                    end = true;
                    break;
                }

            }
        }
    }


    //will only run if computer should make a non-smart move
    if (smart == false)
    {
        //ensures the computer never takes more than half the pile in one turn
        if (random > pile / 2)
        {
            //caluclates the new pile size
            pile = (pile - random) + 1;
            //tells user the how many marbles the computer took
            cout << "The computer takes " << random - 1 << " marbles" << endl;
        }
        else
        {
            //calculates the new pile size
            pile -= random;
            //tells user the how many marbles the computer took
            cout << "The computer takes " << random << " marbles." << endl;
        }
    }
}

int main()
{
    cout << "*****************************************************\n";
    cout << "*                 The game of Nim                   *\n";
    cout << "*    Players alternate taking at least one but at   *\n";
    cout << "*    most half of the marbles in the pile.          *\n";
    cout << "*    The player who takes the last marble loses.    *\n";
    cout << "*    It is written by Aaron Weitekamp               *\n";
    cout << "*    I hope you beat the computer:)                 *\n";
    cout << "*    No matter what, have a great day.              *\n";
    cout << "*****************************************************\n";

    // "hard-code" pile size for testing purpose
    // Testing case 1: the computer plays under smart-move mode:
    int pile = 20;
    // demonstrate the computer under smart-move mode
    bool smart = true;
    cout << "Testing case 1: " << endl;
    cout << "The computer will play smart." << endl;

    //use playCount to "fake" taking a turn between the computer and the player
    //after the loop, if playCount is even, it means it is computer's turn to take the last marble
    //                if playCount is odd, it means it is the player's turn to take the last marble
    int playCount = 0;
    while (pile > 1)
    {
        printMarbles(pile);
        computer_play(pile, smart);
        playCount++;
    }

    if (playCount % 2 == 0)
        cout << "\nThe computer takes the last marble!" << endl;
    else
        cout << "\nThe computer leaves the last marble for you:)" << endl;

    // Testing case 2: the computer plays under non-smart-move mode:
    pile = 5;
    // demonstrate the computer under non-smart-move mode
    smart = false;
    cout << endl << endl << "Testing case 2: " << endl;
    cout << "The computer will not play smart." << endl;

    playCount = 0;   // reset playCount back to 0
    while (pile > 1)
    {
        printMarbles(pile);
        computer_play(pile, smart);
        playCount++;
    }

    if (playCount % 2 == 0)
        cout << "\nThe computer takes the last marble!" << endl;
    else
        cout << "\nThe computer leaves the last marble for you:)" << endl;

    cin >> playCount;
    return 0;
}

/*
 * It displays the marbles on the pile: the number of marbles depends on passing in parameter
 *@param pile int: representing how many marbles are on the pile to display
 *@return: void function
 */
void printMarbles(int pile)
{
    cout << endl << "There are " << pile << " marbles in the pile." << endl;
    for (int i = 0; i < pile; i++)
        cout << setw(WIDTH) << MARBLE << endl;
}
