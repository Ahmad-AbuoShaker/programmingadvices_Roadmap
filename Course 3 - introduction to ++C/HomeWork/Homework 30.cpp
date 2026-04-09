// Homework 30.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1, s2, s3, s4;  
    int i1, i2, i3;
    float f1, f2;
    double d1, d2;

    s1 = "413.54";
    i2 = 544;
    f2 = 68.56;
    d2 = 6.864864;


    i1 = stoi(s1);
    f1 = stof(s1);
    d1 = stod(s1);
    s2 = to_string(i2);
    s3 = to_string(f2);
    s4 = to_string(d2);
    i3 = f2;
    cout << i3;

    return 0;
}
