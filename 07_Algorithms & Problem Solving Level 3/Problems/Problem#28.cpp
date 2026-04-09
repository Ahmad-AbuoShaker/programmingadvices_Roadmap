#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;


char InvertLatterCase(char char1) {
	return isupper(char1) ? tolower(char1) : toupper(char1);
}

string InvertAllStringLatterCase(string S1) {
	for (int i = 0; i < S1.length(); i++) {
		S1[i] = InvertLatterCase(S1[i]);
	}
	return S1;
}


int main()
{

	cout << InvertAllStringLatterCase("AAAllhA aaAalaA");

}

