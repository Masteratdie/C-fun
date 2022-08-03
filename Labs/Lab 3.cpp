//Aaron Weitekamp, Section 10
//The purpose of this program is to calculate how many vehicles a school needs for a field trip
//This includes not wasting unneeded vehicle space or going over the vehicle maximum if applicable
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//prompts and gets number of students from user input
	cout << "Please enter the number of students: ";
	int numStudent;
	cin >> numStudent;

	//checks if user input is valid (greater than 0)
	bool validInput = false;
	if (numStudent > 0)
		validInput = true;

	//intializes constant for each vehicle's passenger size and the vehicle count limit
	const int busSize = 56;
	const int busLimit = 4;
	const int vanSize = 13;
	const int vanLimit = 5;
	const int suvSize = 7;
	const int sedanSize = 3;

	//intializes vehicle counters
	int bus = 0;
	int van = 0;
	int suv = 0;
	int sedan = 0;

	//will loop if there's a valid input and will stop once all students have a vehicle seat
	while (numStudent > 0 && validInput == true)
		//calculates vehicles needed by subtracting the space on each vehicle by the total number of students
		//starts with busses and goes down the list when no more of that vehicle is needed
	{
		if (numStudent >= busSize && bus < busLimit)
		{
			numStudent -= busSize;
			bus++;
		}
		if (numStudent >= vanSize && numStudent < busSize && van < vanLimit || bus == busLimit && van != vanLimit && numStudent >= vanSize)
		{
			numStudent -= vanSize;
			van++;
		}
		if (numStudent >= suvSize && numStudent < vanSize || bus == busLimit && van == vanLimit && numStudent >= suvSize)
		{
			numStudent -= suvSize;
			suv++;
		}
		if (numStudent > 0 && numStudent < suvSize || bus == busLimit && van == vanLimit && numStudent < suvSize)
		{
			numStudent -= sedanSize;
			sedan++;
		}
	}
	//will only output if user entered a valid input
	if (validInput == true)
	{
		//will only output a vehicle if it is needed for rent
		cout << "The Travel Team needs to rent:\n";
		if (bus > 0)
			cout << setw(5) << bus << " Bus(es)\n";
		if (van > 0)
			cout << setw(5) << van << " Van(s)\n";
		if (suv > 0)
			cout << setw(5) << suv << " SUV(s)\n";
		if (sedan > 0)
			cout << setw(5) << sedan << " Sedan(s)\n";
	}
	else
		//outputs this error message if an invalid input is entered
		cout << "Invalid number of passengers!";

	return 0;
}