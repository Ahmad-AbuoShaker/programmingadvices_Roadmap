/*√” Œœ„ structur + enum + function
*/
#include <iostream>
#include<string>
using namespace std;

enum enStatus { single, married };
enum enGander { male, female };
enum enColor { black, whiht, red, green, yellow, blue };

struct setAddress {
	string country;
	string cite;
	string street;
};
struct connectData {
	string phone;
	string email;
};
struct EmpPersonalData {
	setAddress Address;
	connectData conD;
	int age;
	enGander gender;
	enStatus married;
};
struct EmpSalary {
	int MonthlySalary;
	int YearlySalary;
};
struct EmpData {
	int ID;
	string FirstName;
	string LastName;
	EmpSalary salary;
	EmpPersonalData personalData;
};

void ReadInfo(EmpData& Info) {
	int c;
	cout << " Please enter your ID: ";
	cin >> Info.ID;
	cin.ignore();
	cout << " pleas enter your first name :";
	getline(cin, Info.FirstName);
	cout << " pleas enter your last name :";
	getline(cin, Info.LastName);
	cout << " pleas enter your Phone number :";
	getline(cin, Info.personalData.conD.phone);
	cout << " pleas enter your age :";
	cin >> Info.personalData.age; cin.ignore();
	cout << " pleas enter your country :";
	getline(cin, Info.personalData.Address.country);
	cout << " pleas enter your city :";
	getline(cin, Info.personalData.Address.cite);
	cout << " pleas enter your Monthly Salary :";
	cin >> Info.salary.MonthlySalary;
	cout << " pleas enter your gander";
	cout << " [(0) Male or (1) Female] :";
	cin >> c;
	Info.personalData.gender = (enGander)c;
	cout << " are you married? 0/1 :";
	cin >> c;
	Info.personalData.married = (enStatus)c;
}
void PrintInfo(EmpData Info) {

	cout << " ************************" << endl;
	cout << " ID:" << Info.ID << endl;
	cout << " First name:" << Info.FirstName << endl;
	cout << " Last name:" << Info.LastName << endl;
	cout << " Phone:" << Info.personalData.conD.phone << endl;
	cout << " age:" << Info.personalData.age << " years" << endl;
	cout << " city: " << Info.personalData.Address.cite << endl;
	cout << " country: " << Info.personalData.Address.country << endl;
	cout << " Monthly Salary: " << Info.salary.MonthlySalary << endl;
	cout << " Yearly Salary: " << Info.salary.MonthlySalary * 12 << endl;

	if (Info.personalData.gender == enGander::male) {
		cout << " Gander: male" << endl;
	}
	else { cout << " Gander: female" << endl; }

	if (Info.personalData.married == enStatus::single) {
		cout << " Status: single" << endl;
	}
	else { cout << " Status: married" << endl; }
	cout << " ************************" << endl;

}

void ReadPersonInfo(EmpData person[100], int& NumberOfPerson) {
	cout << " How many person ?" << endl;
	cin >> NumberOfPerson;
	cin.ignore();
	for (int i = 0; i < NumberOfPerson; i++) {
		cout << " Enter the information for person (" << i + 1 << ") :\n";
		ReadInfo(person[i]);
		cout << " ************" << endl;
	}
}

void PrintPersonInfo(EmpData person[100], int NumberOfPerson) {
	cout << " ******************************************" << endl;
	for (int i = 0; i < NumberOfPerson; i++) {
		cout << " Person (" << i + 1 << ")'s information :" << endl;
		PrintInfo(person[i]);
	}
}

int main() {
	EmpData pr[100]; int n = 0;
	ReadPersonInfo(pr, n);
	PrintPersonInfo(pr, n);
}