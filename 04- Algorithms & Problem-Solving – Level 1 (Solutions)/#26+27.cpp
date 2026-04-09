

#include <iostream>
using namespace std;

int ReadNum() {
	int Num;
	cout << " Enter a number :";
	cin >> Num;
	return Num;
}

void PrintRangeFromNto1(int Num) {
	for (int i = Num; i > 0; i--)
		cout << i << " " << endl;
}//#27

void PrintRangeFrom1toN(int Num) {
	for (int i = 1; i <= Num; i++)
		cout << i << " " << endl;
}//#26

int main()
{
	PrintRangeFrom1toN(ReadNum());
	PrintRangeFromNto1(ReadNum());

	return 0;
}
