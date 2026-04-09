// #33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    long float p, s, T;
    cout << " Enter your salary :" << endl << " ";
    cin >> s;
    if (s >= 1000000) { p = 0.01; }
    else if (s >= 500000) { p = 0.02; }
    else if (s >= 100000) { p = 0.03; }
    else if (s >= 50000) { p = 0.05; }
    else { p = 0.0; }
    T = s + s * p;
    cout << " " << T;

    return 0;
}