#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	int age;

public:
	//adding parameters means you must create object with arguments
	Person(string pName, int pAge) {
		cout << "Constructor called!" << endl;
		name = pName;
		age = pAge;
	}

	~Person() {
		cout << "Destructor called!" << endl;
	}

	//Accessors (GETTERS)
	const string& getName() const {
		return name;
	}

	const int& getAge() const {
		return age;
	}	

	// Modifiers (SETTERS)
	void setName(const string personName) {
		name = personName;

	}

	void setAge(const int personAge) {
		age = personAge;

	}

	//Functions
	const string toString() const {
		return "Name: " + name + " Age: " + to_string(age);
	}
};



int main() {
	Person Aaron("Aaron",19);
	Aaron.setAge(30);
	//Aaron.setName("Aaron");

	cout << Aaron.getAge();



	return 0;
}

