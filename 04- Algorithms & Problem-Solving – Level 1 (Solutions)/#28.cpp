

#include <iostream>
using namespace std;

int ReadNum() {
	int Num;
	cout << " Enter a number :";
	cin >> Num;
	return Num;
}


int SumOddNum(int Num) {
	int Sum = 0;
	for (int i = 1; i <= Num; i += 2)
		Sum += i;

	return Sum;
}

void PrintResult(int Num){
	cout << " Sum odd number : " << Num;
}

int main()
{
	PrintResult(SumOddNum(ReadNum()));


	return 0;
}
