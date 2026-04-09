

#include <iostream>
#include<string>
using namespace std;

int main()
{  
	string Name="Ahamd" ;
	string Country = "syria";
	string City = "damas";
	short int Age = 44, MonthlySalray = 5000, YearlySalry = 60000;
	char Gander = 'M';
	bool Married = 0;

	
	cout << "pleas enter your name " << endl;
	cin >> Name;
	cout << "pleas enter your country " << endl;
	cin >> Country;
	cout << "pleas enter your city" << endl;
	cin >> City;
	cout << "pleas enter your age" << endl;
	cin >> Age;
	cout << "pleas enter your Monthly Salary" << endl;
	cin >> MonthlySalray;
	cout << "pleas enter your gander" << endl;
	cin >> Gander;
	cout << "are you married? 0/1" << endl;
	cin >> Married;



	cout<< "************************" << endl
		<< "Name:" << Name << endl
		<< "age:" << Age << "years" << endl
		<< "city: " << City << endl
		<< "country: " << Country << endl
		<< "MonthlySalray: " << MonthlySalray << endl
		<< "YearlySalry: " << MonthlySalray * 12 << endl
		<< "gander: " << Gander << endl
		<< "married: " << Married << endl
		<< "************************" << endl;

		return 0;
}