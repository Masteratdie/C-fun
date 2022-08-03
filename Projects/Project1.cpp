//Aaron Weitekamp, Section 10
//The purpose of this program is to create a game against a computer where you take turns removing marbles from a pile, only being allowed to take at most half. Whoever has to grab the last marble loses.
//Your turn order and intial pile size are decided at random, although the pile size must be at least 10, and at most 50
//The computer has two modes smart and non-smart
//Smart mode means the computer will take enough marbles from the pile to make it equal to a power of 2 minus 1. If the pile already meets this requirement the computer takes a random number of marbles between 1 and up to half the current pile size
//Non-smart mode means the computer will always take a random amount of marbles between 1 and up to half the current marble pile size
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

//the range used to generate the intial marble pile size
const int PILE_MAX = 50;
const int PILE_MIN = 10;

const char MARBLE = static_cast<char>(232);  //use code 232 in ASCII Table to represent marble
const int WIDTH = 10;   // for layout purpose

//The purpose of this function is to simulate the player's turn
//The player can only take from one up to half the remaing number of marbles
//Numbers outside this range, or a non-integer first input will output an error and reprompt the player for a valid input
void player_play(int& pile, string& previousTurn)
{
    //ends the function immediately if called when winner only the last marble remains
    if (pile <= 1)
    {
        return;
    }
    //flag used to check if player input is valid
    bool validInput = false;

    //creates variable used for player input
    int player;
    do
    {
        //calculates the maximum amount of marbles the player can take
        int maxTake = pile / 2;

        //tells user what range of numbers is a valid input
        cout << "Your play .. you may take " << "1" << " to " << maxTake << " marbles ";

        //used later in order to figure out who takes the last marble
        previousTurn = "Player";

        //collects user input
        cin >> player;

        //checks if cin fails
        if (cin.fail())
        {
            cout << "Invalid! Please try again..." << endl;
            // Clear the failing state of input stream, so that the further extration operations can be applied
            cin.clear();
        }
        else   // verify input is an integer 
        {
            if (player > maxTake || player <= 0)
                cout << "Ooops, you picked too many or not enough" << endl;
            else    // valid input has been collected
                validInput = true;
        }
        cin.ignore(256, '\n');  //extract and ingore anything left (bad input) in the input stream
    } while (!validInput);
    //subtracts player input from pile total
    pile -= player;
}

// display marbles on the pile
void printMarbles(int pile);

//The purpose of this function is to simulate the computer's choice for both smart and non-smart moves
//Under smart move the computer takes away just enough marbles so the pile is equal to a power of 2 minus one, if it's already a power of two minus one it removes a number of marbles between one and up to half the current pile size
//Under a non-smart move the computer always take a random number between 1 and the up to half the current pile size
void computer_play(int& pile, bool smart, string & previousTurn)
{
    //ends the function immediately if called when winner only the last marble remains
    if (pile <= 1)
    {
        return;
    }
    double powerCheck;

    //creates a random number between 1 and the pile size /2
    // the seed used is based on the time you start the program
    int seed = static_cast<int>(time(0));
    srand(seed);
    int random = 1 + rand() % pile / 2;

    cout << "Computer plays: \n";

    //used later in order to figure out who takes the last marble
    previousTurn = "Computer";

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

    //variable used to decide who takes the last marble
    string previousTurn = "empty";

    //variable decides whether computer plays smart or non-smart
    bool smart;

    //random number generator
    int seed = static_cast<int>(time(0));
    srand(seed);

    //generates total marble pile between 10 and 50
    int pile = rand() % PILE_MAX;
    if (pile < PILE_MIN)
        pile = PILE_MIN;

    //decides whether computer should play smart or non-smart by randomly generating either a 0 or 1
    int decideIntelligence = (rand() % 2);
    if (decideIntelligence == 1)
    {
        smart = true;
        cout << "The computer will play smart\n";
    }
    else
    {
        smart = false;
        cout << "The computer will not play smart\n";
    }

    //counts how many times both players have taken a turn, used to display who plays first only on the first round
    int playCount = 0;

    //random number used to decide who will play first
    int turnOrder = (rand() % 2);
    while (pile > 1)
    {
        if (turnOrder == 1)
        {
            if (playCount == 0)
                cout << "You will play first\n";
            printMarbles(pile);
            player_play(pile, previousTurn);
            printMarbles(pile);
            computer_play(pile, smart, previousTurn);

        }
        else
        {
            if (playCount == 0)
                cout << "The computer will play first\n";
            printMarbles(pile);
            computer_play(pile, smart, previousTurn);
            printMarbles(pile);
            player_play(pile, previousTurn);
        }
        playCount++;

    }

    //displays who won based on who took the second to last marble
    //whoever took the second to last is the winner
    if (previousTurn == "Computer")
        cout << "You must take the last marble. You lose!";
    if (previousTurn == "Player")
        cout << "Computer must take the last marble. You win!";
    
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
