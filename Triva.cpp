#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "hello";
	int middle[7] = {1,2,3,4,5,6};
	cout << middle[0];

	for (int i = 6; i >= 4; --i)
		middle[i + i] = middle[i];


	for (int i = 0; i <=7; ++i)
		cout << middle[i];

	return 0;
}