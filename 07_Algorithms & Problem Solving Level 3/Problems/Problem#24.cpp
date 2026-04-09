#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;


void UpperFirstLetterOfEachWord(string& S1) {
	bool IsFirstLater = true;

	for (int i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ' && IsFirstLater) {
			
			S1[i] = toupper(S1[i]);
		}

		IsFirstLater = (S1[i] == ' ' ? true : false);
	}
}

int main()
{
	string S1 = "a a a hhh";

	UpperFirstLetterOfEachWord(S1);
	cout << S1;

}
