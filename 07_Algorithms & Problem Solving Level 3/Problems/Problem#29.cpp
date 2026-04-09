#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;

enum enWhatToCount{Capital=1,Small=2,All=3};
int Countlatter(string S1, enWhatToCount WhatToCount = All) {
	int counter = 0;
	for (int i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ')
		{
			{
				switch (WhatToCount)
				{
				case All:
					counter++;
					break;
				case Capital:
					counter++;
					break;
				case Small:
					counter++;
					break;
				default:
					break;
				}
			}
		}
	}
	return counter;
}
int CountCapotalLatter(string S1) {
	int counter = 0;
	for (int i = 0; i < S1.length(); i++) {
		if (S1[i]!=' '&&isupper(S1[i]))
			counter++;
	}
	return counter;
}
int CountSmallLatter(string S1) {
	int counter = 0;
	for (int i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ' && islower(S1[i]))
			counter++;
	}
	return counter;
}


int main()
{
	string s1="AAAllhA   ";

	cout<< Countlatter(s1);

		
		
		

}

