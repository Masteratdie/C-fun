//Aaron Weitekamp, Section 10
//the purpose of this program is to check whether the user input of a positive integer is a power of two minus one, and to add up all valid user inputs
//if the input is invalid because it's not an integer or it's negative that error is output to user
//if input is invalid because it's a char of 'Q' of 'q' the program ends
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//intializes sum of all valid input counter
	int counter = 0;
	//intializes user input
	int inputN = 0;
	//intializes variable that checks if input is valid
	bool validInputN = false;
	//checks invalid input to see if program should end
	string inputCheck;
	//intializes counter that checks how many times program has looped, used for output messages
	int loopCount = 0;

	while (true)
	{
		//asks and collects input from user
		cout << "Please enter a series of positive numbers, then type (Q or \nq) to process: ";
		cin >> inputN;

		if (cin.fail())     //verify if cin fails
		{
			cin.clear(); // Clear the failing state of input stream, so that the further extration operations can be applied
			cin >> inputCheck;

			//breaks out of the loop if these characters are entered
			if (inputCheck == "Q" || inputCheck == "q")
				break;

			//outputs error to user
			cout << "Invalid input, please try again..." << endl;

		}
		else
		{
			if (inputN <= 0)   //checks if input is negative
				cout << "Please input a positive integer instead... " << endl;
			else
			{

				validInputN = true; //valid input is entered
				counter += inputN; //adds to total input counter

				//used to exit loop once square check is larger than inputN
				int squareCheck = 2;
				//checks if entered input is a square - 1 or not
				while (squareCheck <= inputN)
				{
					squareCheck *= 2;
				}
				squareCheck -= 1;
				//if square check and inputN are equal the number must be a power of two minus one
				if (squareCheck == inputN)
					cout << inputN << " is a Power of Two Minus One!\n";
				else
					//tells the user whether the number is a power of two minus one, and the sum of all user inputs
					cout << inputN << " is not a Power of Two Minus One!\n";
					cout << "The sum of all user input is: " << counter <<endl ;
			}
		}
		cin.ignore(256, '\n');  //extract and ingore anything left (bad input) in the input stream
		loopCount++; //adds to loop counter used for output
	}
	//tells user nothing was input
	cout << "No input number!\n";
	//won't output exit character was immediately entered
	if (loopCount != 0)
		cout << "The sum of all user input is: " << counter << endl;
	//ending program message
	cout << "Have a great day!";
}
