#include <iostream>
using namespace std;

int main() {
	int x[] = {1,2,3};
	int *head = x;

	for (int i = 0; i < 3; ++i) {
		head = x + i;
		cout << *head << endl;
	}

}
