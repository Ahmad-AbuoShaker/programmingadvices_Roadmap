// #17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

float ReadTriangleData(float&A,float&B) {
   
    cout << " Enter triangle said : ";
    cin >> A; 
    cout << " Enter Triangle base :";
    cin >> B;
}


float circleAreaITriangle(float A,float B) {
    const float pi = 3.141592653589793238;
    return pi * (pow(B, 2) / 4) * ((2*A-B)/(2*A+B));

}

void PrintResult(float Area) {
    cout << " Area of circle is :" << Area << endl;
}
int main()
{
    float A, B;
    ReadTriangleData(A, B);
    PrintResult(circleAreaITriangle(A,B));
    return 0;
}
