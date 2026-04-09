

#include <iostream>
using namespace std;
enum enOddOrEven{Odd=1,Even=2};



int ReadNum() {
	int Num;
	cout << " Enter a number :";
	cin >> Num;
	return Num;
}

enOddOrEven CheckOddOrEven(int Num) {
	if (Num % 2 == 0)
		return Even;
	else
		return Odd;

}

int SumEvenNum(int Num) {
	int Sum = 0, Counter;

	for (int i = 0; i <= Num; i+=2)
		Sum += i;

	return Sum;
}

void PrintResult(int Num) {
	cout << " Sum Even number : " << Num;
}

int main()
{
	PrintResult(SumEvenNum(ReadNum()));


	return 0;
}
