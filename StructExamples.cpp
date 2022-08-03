#include <iostream>
using namespace std;

struct User {
	string firstName;
	string lastName;

	string get_status() {
		return status;
	}
private:
	string status = "Gold";

};


int main() {

	User user;
	user.firstName = "Aaron";

	cout << user.get_status();
	return 0;

	}
