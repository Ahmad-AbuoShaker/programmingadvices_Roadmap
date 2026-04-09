#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;


void PrintFirstLetterOfEachWord(string S1) {
	bool IsFirstNumber = true;
	for (int i = 0; i < S1.length(); i++) {
		if (S1[i] != ' '&&IsFirstNumber) {
			cout << " " << S1[i];
		}

		IsFirstNumber = (S1[i] == ' ' ? true : false);
	}
}

int main()
{

 
	PrintFirstLetterOfEachWord("ajimi ko okjna oina");

}
