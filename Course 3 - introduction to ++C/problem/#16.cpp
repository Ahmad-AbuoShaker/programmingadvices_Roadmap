// #16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;
int RectArea(int a, int b) {
   return a* sqrt(pow(b, 2) - pow(a, 2));
}
int RectArea() {
    int a, b, s;
    cout << "Enter the length of the side :"; cin >> a; cout << "and the diameter :"; cin >> b;
    s = a * sqrt(pow(b, 2) - pow(a, 2));
    cout << "Area of a rectangle : " << s << endl;
    return s;
}
int main()
{
    int a, b, s;
    cout << "Enter the length of the side :"; cin >> a; cout << "and the diameter :"; cin >> b;    
    cout << "Area of a rectangle : " << RectArea(a, b) << endl;
    s = RectArea();

    return 0;
}

