// #33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int mark;
    cout << " Enter your mark :" << endl<<" ";
    cin >> mark;
    if (mark > 100) { cout << " Wrong.\a" <<; }
    else if (mark >= 90) { cout << " A" << endl; }
    else if (mark >= 80) { cout << " B" << endl; }
    else if (mark >= 70) { cout << " C" << endl; }
    else if (mark >= 60) { cout << " D" << endl; }
    else if (mark >= 50) { cout << " E" << endl; }
    else { cout << " F" << endl; }
    return 0;
}