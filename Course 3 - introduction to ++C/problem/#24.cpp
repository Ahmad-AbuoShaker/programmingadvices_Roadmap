// #24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int age;
    cout << " Enter your age :" << endl;
    cin >> age;
    if (18 <= age >= 45) { cout << " You succeeded."; }
    else { cout << " You failed."; }


}