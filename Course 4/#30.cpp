

#include <iostream>
using namespace std;




int ReadPositiveNum(string Massage) {
	int Num;
	do {
		cout << Massage;
		cin >> Num;
	} while (Num<0);
	return Num;
}


int Factorial(int Num) {
	int Fact = 1;

	for (int i = 1; i <= Num; i++)
		Fact *= i;

	return Fact;
}

void PrintResult(int Num) {
	cout << " Factorial of number is : " << Num;
}

int main()
{
	PrintResult(Factorial(ReadPositiveNum(" Enter positive number :")));


	return 0;
}
