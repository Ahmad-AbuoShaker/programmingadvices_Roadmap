#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;

string  ReadString() {
	string S1;
	cout << "\nPlease Enter Your String?\n";
	getline(cin, S1);
	return S1;
}
char  ReadChar() {
	char Ch1;
	cout << "\nPlease Enter a Character?\n";
	cin >> Ch1;
	return Ch1;
}

int CountLatter(string S1, char Latter, bool MatchCase = true) {
	int counter = 0;
	for (int i = 0; i < S1.length(); i++) {
		if (MatchCase) {

			if (S1[i] == Latter)
				counter++;
		}
		else {
			if (toupper(S1[i]) == toupper(Latter))
				counter++;
		}
	}
	return counter;
}

char InvertLatterCase(char char1) {
	return isupper(char1) ? tolower(char1) : toupper(char1);
}



int main()
{
	string S1 = ReadString();
	char Ch1 = ReadChar(); 
	cout << "\nLetter \'" << Ch1 << "\' Count = " << CountLatter(S1, Ch1);
	cout << "\nLetter \'" << Ch1 << "\' ";
	cout << "Or \'" << InvertLatterCase(Ch1) << "\' ";
	
	cout << " Count = " << CountLatter(S1, Ch1, false);




}

