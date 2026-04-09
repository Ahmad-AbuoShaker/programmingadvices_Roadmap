// #17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void ReadNumber(float& A, float& H) {
    cout << " Enter base : ";
    cin >> A;
    cout << " Enter height :";
    cin >> H;
}
float TriangleArea(float A, float H) {
    return (A / 2) * H;

}

void PrintResult(float Area){
    cout << " Area of triangle is :" << Area << endl;
}
int main()
{
    
}
