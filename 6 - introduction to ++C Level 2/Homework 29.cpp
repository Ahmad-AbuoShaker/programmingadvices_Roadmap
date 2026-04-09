
#include <iostream>
#include<vector>
using namespace std;

void readNumbers(vector<int>& VNumber) {
	char again = 0;
	int Number = 0;

	do {
		cout << " Enter a Number : ";
		cin >> Number;
		VNumber.push_back(Number);
		cout << "\n Do you want to Enter more [Y/N]: ";
		cin >> again;
	} while (again == 'y' || again == 'Y');
}

void PrintNumbers(vector<int>& VNumber) {
	cout << "\n Numbers :\n ";
	for (int& Number : VNumber) {

		cout << Number << "\n ";
	}
}


int main()
{
	vector<int>VNumber;
	readNumbers(VNumber);
	PrintNumbers(VNumber);
}
