#include <iostream>
#include <string>
using namespace std;

int main() {
	int x = 5;
	int arr[] = {4, 5, 6, 7,};
	string arr2[] = {"Hello", "how are you"};
	cout << arr[0];
	cout << arr2[0] << endl;

	cout << sizeof(arr2)/sizeof(arr2[0]) << endl;


	//example of shifting removing element from array by shifting over by 1
	//shifts
	int loop[] = {1, 2, 3, 4, 64, 45};
	for (int i = 1; i < (sizeof(loop)/sizeof(loop[0])) - 1; i++)
		loop[i] = loop[i + 1];

	//prints shift
	for (int i = 0; i < sizeof(loop)/sizeof(loop[0]); i++)
		cout << loop[i] << endl;
}