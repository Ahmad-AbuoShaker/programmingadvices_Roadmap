#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;


int CountLatter(string S1,char Latter) {
	int counter = 0;
	for (int i = 0; i < S1.length(); i++) {
		if (S1[i] == Latter)
			counter++;
	}
	return counter;
}



int main()
{
	string s1 = "AAAllhA   ";

	cout << CountLatter(s1,'A');





}

