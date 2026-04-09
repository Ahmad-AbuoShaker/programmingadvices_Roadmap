// Homework 31.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s,s1, s2, s3, s4;
	cout << "Enter fullname :";
	getline(cin,s);
	cout << "Enter s1 :";
	cin >> s1;
	cout << "Enter s2 :";
	cin >> s2;
	cout << "\n***********************";
	cout << "\nlength of name is :" << s.length();
	cout << "\ncharacters at 0,2,4,7 is :" << s[0] << s[2] << s[4] << s[7];
	cout << "\nconcatenating s1 and s2 = " << s1 + s2;
	cout << "\ns1 * "<<"s2 = " << stoi(s1) * stoi(s2);
}

