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
	tolower(Char);
			return (Char=='a'||Char=='e'||Char=='i'||Char=='o'||Char=='u');	
}




int main()
{
	
	char Ch1 = ReadChar();
	cout << isVowel(Ch1);




}

