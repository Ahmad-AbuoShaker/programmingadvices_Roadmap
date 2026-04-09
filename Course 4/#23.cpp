// #17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

float ReadTriangleData(float& A, float& B, float& C) {

    cout << " Enter triangle said A : ";
    cin >> A;
    cout << " Enter Triangle base B :";
    cin >> B;
    cout << " Enter triangle said c : ";
    cin >> C;
}


float circleAreaByATriangle(float A, float B,float C) {
    const float pi = 3.141592653589793238;
    float P, T;
    P = (A+B+C)/2;
    T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
    return pi * pow(T, 2);

}

void PrintResult(float Area) {
    cout << " Area of circle is :" << Area << endl;
}
int main()
{
    float A, B, C;
    ReadTriangleData(A, B, C);
  PrintResult(circleAreaByATriangle(A, B, C));
    return 0;
}
