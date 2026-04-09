
#include <iostream>
#include<vector>
using namespace std;

struct stEmployee { 
	string FirstName;
	string LastName;
	float Salary; 
};

void readEmployees(vector<stEmployee>& Employees) {
	stEmployee Employee;
	char again = 0;
	do {
		cout << " Enter First Name : ";
		cin >> Employee.FirstName;
		cout << " Enter Last Name  : ";
		cin >> Employee.LastName;
		cout << " Enter Salary     : ";
		cin >> Employee.Salary;
		Employees.push_back(Employee);
		cout << "\nDo you want to read more employees? Y/N ?";
		cin >> again;
	} while (again == 'y' || again == 'Y');
}

void PrintEmployees(vector<stEmployee>& Employees) {
	cout << "\n Employees Vavtor :\n";
	for (stEmployee& Employee : Employees) {

		cout << " First Name : " <<Employee.FirstName <<"\n";
		cout << " last Name  : " <<Employee.LastName <<"\n";
		cout << " Salary     : " <<Employee.Salary <<"\n";
		cout << "____________________\n\n";


	}
}


int main()
{
	vector<stEmployee>VEmployee;
	readEmployees(VEmployee);
	PrintEmployees(VEmployee);
}
