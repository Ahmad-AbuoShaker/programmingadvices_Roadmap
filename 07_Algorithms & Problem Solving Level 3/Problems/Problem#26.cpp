#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;


string LowerAllString(string S1) {
	for (int i = 0; i < S1.length(); i++) {
		S1[i] = tolower(S1[i]);
	}
	return S1;
}


string UpperAllString(string& S1) {
	for (int i = 0; i < S1.length(); i++) {
		S1[i] = toupper(S1[i]);
	}
	return S1;
} 


int main()
{
	string S1 = " AAa aAA AAA HH K hhh";
	cout << S1 << "\n";
	cout<<UpperAllString(S1);
	

}

