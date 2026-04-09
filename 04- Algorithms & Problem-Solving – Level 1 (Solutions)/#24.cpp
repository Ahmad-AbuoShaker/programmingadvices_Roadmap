// #17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int ReadAge() {
	int age;
	cout << " Enter you age :";
	cin >> age;
	return age;
}

bool ValidateNumberInRange(int Num, int From, int TO) {
	return (From <= Num&& Num <= TO);
}

int ReadUntilAgeBetween(int From, int To) {
	int age;
	do{
		age = ReadAge();
		
	} while (!ValidateNumberInRange(age, From, To));



	return age;

}
void PrintResult(int age){
	if (ValidateNumberInRange(age, 18, 45))
		cout << "\n is a valid age ";
	else
		cout << " \n is a invalid age ";
}

int main()
{
	PrintResult(ReadUntilAgeBetween(18,45));

	return 0;
}
