// #4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int age; bool Dl;

    cout << " pleas enter your age :" << endl<<" ";
    cin >> age;
    cout << " Did you have a driving license ?0/1" << endl<<" ";
    cin >> Dl;
    if (age >= 21 && Dl) { cout << " You succeeded."; }
    else { cout << " You failed."; }


}

