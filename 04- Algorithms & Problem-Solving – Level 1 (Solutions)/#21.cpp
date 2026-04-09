// #17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

float ReadCircumference() {
    float L;
    cout << " Enter circumference : ";
    cin >> L;
    return L;
}
float circleAreaByCircumference(float L) {
    const float pi = 3.141592653589793238;
    return pow(L, 2) / (4 * pi);

}

void PrintResult(float Area) {
    cout << " Area of circle is :" << Area << endl;
}
int main()
{
    PrintResult(circleAreaByCircumference(ReadCircumference()));
    return 0;
}
