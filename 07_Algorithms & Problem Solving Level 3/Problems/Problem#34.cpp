#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;

char  ReadChar() {
	char Ch1;
	cout << "\nPlease Enter a Character?\n";
	cin >> Ch1;
	return Ch1;
}

bool isVowel(char Char) {
	Char=tolower(Char);
	return (Char == 'a' || Char == 'e' || Char == 'i' || Char == 'o' || Char == 'u');
}

void PrintVowels(string S1) {
	for (int i = 0; i < S1.length(); i++)
	{
		if (isVowel(S1[i]))
			cout << " " << S1[i];
	}
}



int main()
{
	cout << tolower('A');
	PrintVowels("Aa");



}

