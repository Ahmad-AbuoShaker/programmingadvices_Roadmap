// #33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    float a, b; char  T;
    cout << " Enter first number :";
    cin >> a;
    cout << " Enter second number :";
    cin >> b;
    cout << " Enter the type of operation :";
    cin >> T;
    switch (T) {
    case '-':
        a -= b; cout << " A" << T << "B =" << a;
        break;
    case '+':
        a += b; cout << " A" << T << "B =" << a;
        break;
    case '/':
        a /= b; cout << " A" << T << "B =" << a;
        break;
    case '*':
        a *= b; cout << " A" << T << "B =" << a;
        break;
    default  cout << " Wrong operation.";
    }
         return 0;
}