#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;


void LowerFirstLetterOfEachWord(string& S1) {
	bool IsFirstLater = true;

	for (int i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ' && IsFirstLater) {

			S1[i] = tolower(S1[i]);
		}

		IsFirstLater = (S1[i] == ' ' ? true : false);
	}
}

int main()
{
	string S1 = " AAa aAA AAA HH K hhh";
	cout << S1 << "\n";
	LowerFirstLetterOfEachWord(S1);
	cout << S1;

}
