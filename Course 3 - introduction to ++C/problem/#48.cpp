// #48.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main()
{
    float L, M;
    cout << "Enter the loan value :"; cin >> L;
    cout << "Enter number of month to repay the loan : "; cin >> M;
    cout << "Amount to be paid each month : " << (L / M);
}
