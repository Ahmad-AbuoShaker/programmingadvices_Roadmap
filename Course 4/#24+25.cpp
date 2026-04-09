// #24+25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
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
	return (From <= Num && Num <= TO);
}

int ReadUntilAgeBetween(int From, int To) {
	int age;
	do {
		age = ReadAge();

	} while (!ValidateNumberInRange(age, From, To));

	return age;
}

void PrintResult(int age) {
	if (ValidateNumberInRange(age, 18, 45))
		cout << "\n is a valid age ";
	else
		cout << " \n is a invalid age ";
}

int main()
{
	PrintResult(ReadUntilAgeBetween(18, 45));

	return 0;
}
