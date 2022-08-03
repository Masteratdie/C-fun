#include <iostream>
#include <vector>
#include <string>
using namespace std;


void insertAtFront(int values[], int size, int capacity, int item){
	if (size < capacity) {
		for (int i = size-1; i >= 0; --i) {
			values[i + 1] = values[i];
			cout << values[i]<<endl;
		}
		values[0] = item;
	}
}

int main() {
	int values[4] = {1,2,3};
	insertAtFront(values,3,4,6);
	for (int i = 0; i < sizeof(values)/sizeof(values[0]); ++i)
		cout << values[i];

	return 0;
}

