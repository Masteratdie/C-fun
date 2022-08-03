#include <iostream>
#include <vector>
#include <string>
using namespace std;

//dot notation cheat sheet
/*
vector name should be in front of each .notation
.back() last index
.front() first index
.size() current total vector size
.capacity() total size vector can hold
.push_back() adds another element at the end of the vector
.pop_back() remvoes the last element in the vector
.shrink_to_fit() changes vector capacity to equal its current size
*/

int main() {
	vector<int> v1 = {1, 2, 3};
	v1.push_back(4);
	cout << v1[3];
	
   double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
   double *p;

   p = balance;
   cout << p[1];
}