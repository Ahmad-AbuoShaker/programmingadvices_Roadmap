// #8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int mark;
	cout << " Enter your mark : " << endl << " ";
	cin >> mark;
	if (mark < 50) { cout << " You failed."; }
	else { cout << " You succeeded."; }
	
}

