// #17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

float ReadRadios() {
    float R;
    cout << " Enter radios : ";
    cin >> R;
    return R;
}
float TriangleArea(float R) {
    const float pi = 3.141592653589793238;
    return pow(R,2)*pi;

}

void PrintResult(float Area) {
    cout << " Area of circle is :" << Area << endl;
}
int main()
{
    PrintResult(TriangleArea(ReadRadios()));
}
