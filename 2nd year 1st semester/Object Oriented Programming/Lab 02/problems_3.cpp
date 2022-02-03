#include<iostream>

using namespace std;

class Employee {
private:
	string name;
	int yearOfJoining;
	int salary;
	string address;
public:


	Employee(string eName, int eYearOfJoining, int eSalary, string eAddress) {
		name = eName;
		yearOfJoining = eYearOfJoining;
		salary = eSalary;
		address = eAddress;
	}

	void display() {
		cout << name << "\t   " << yearOfJoining << "\t\t" << address << endl;
	}
};

int main() {

	Employee e1("Robert",1994,22222,"64C- WallsStreat");
	Employee e2("Sam",2000,22222,"64C- WallsStreat");
	Employee e3("John",1999,22222,"64C- WallsStreat");
	cout << "Name" << "\t" << "Year of Joining" << "\t       " << "Address" << endl;
	e1.display();
	e2.display();
	e3.display();

	return 0;
}
