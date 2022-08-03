#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//intializes
	double due;
	double received;

	cout << "Enter the amount due : $ ";
	cin >> due;
	cout << "Enter the amount received: $ ";
	cin >> received;
	cout << "The change is:" << endl;

	double change = received - due;

	// const int wholeDollar = 1;
	// const int twentyFiveCents = 25;
	// const int tenCents = 10;
	// const int fiveCents = 5;
	// const int oneCents = 1;
	// const int roundUp = 0.5;

	int cents = change * 100 + 0.5;
	int dollars = cents / 100;
	cents = cents % 100;
	int quarters = cents / 25;
	cents = cents % 25;
	int dimes = cents / 10;
	cents = cents % 10;
	int nickels = cents / 5;
	cents = cents % 5;
	int pennies = cents;

	cout << "\nDollars: \t\t" << setw(6) << dollars << "\nQuarters: \t\t" << setw(6) << quarters << "\nDimes: \t\t" << setw(6) << dimes << "\nNickels: \t\t" << setw(6) << nickels << "\nPennies: \t\t" << setw(6) << pennies;

}