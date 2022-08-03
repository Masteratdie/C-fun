//Aaron Weitekamp, Section 10
//The purpose of the program is to check whether a 8-digit credit card number is valid
//if invalid it also outputs what the check digit should have been to be considered valid
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//prompts and collects the users 8-digit credit card number
	cout << "Please enter the 8-digit credit card number (enter -1 to" << endl << "quit): ";
	string cardNumber;
	cin >> cardNumber;

	//loops until exitted by an input of "-1" which essentially exits the program
	while (cardNumber != "-1")
	{
		//intializes the variables which are the answers to the first two calculations
		int everyOther = 0;
		int addProduct = 0;

		//temporary variables used for type casting between int and string
		string tempStr;
		int tempInt;

		//loops backwards through cardNumber index
		for (int i = 7; i >= 0; i--)
		{
			//adds every other number together starting with the right-most digit
			if (i % 2 != 0)
			{
				tempStr = cardNumber[i];
				everyOther += stoi(tempStr);
			}
			//multiplies the remaing numbers by 2, then adds the digits of each product together
			else
			{
				tempStr = cardNumber[i];
				tempInt = stoi(tempStr) * 2;
				addProduct += (tempInt / 10) % 10;
				addProduct += tempInt % 10;
			}
		}
		//adds both the previous calulations together
		int total = everyOther + addProduct;
		//if the total has 0 as its final digit it's output as valid
		if (total % 10 == 0)
			cout << "Number is valid\n";
		else
		{
			//tells the user their card number is invalid
			cout << "Number is invalid\n";

			//calculates correct check digit by finding the difference between given check digit and the nearest tens place which is then added to the original number
			int checkDigit = (((total / 10 + 1) * 10) - total) + stoi(cardNumber) % 10;
			//if check digit is calculated as over 10 corrects by subtracting 10 away
			if (checkDigit > 9)
				checkDigit -= 10;

			//outputs correct check digit to user
			cout << "Check digit should have been " << checkDigit << endl;
		}

		//re-prompts and collects user input to repeat loop with new card number
		cout << "\nPlease enter the 8-digit credit card number (enter -1 to" << endl << "quit): ";
		cin >> cardNumber;
	}
	//message is outputted right before the program closes
	cout << "Thank you for using \"Credit Card Number Validation\"!";

	return 0;
}