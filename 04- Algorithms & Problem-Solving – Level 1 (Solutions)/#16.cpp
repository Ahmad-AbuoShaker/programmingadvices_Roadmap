// #16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void ReadNumber(float& A, float& D) {
    cout << " Enter said : ";
    cin >> A;
    cout << " Enter diagonal :";
    cin >> D;
}

float RectangleAreaBySaidAndDiagonal(float A,float D){
    return A * sqrt(pow(D, 2) - pow(A, 2));
}

void PrintResult(float Area){
    cout << " Rectangle Area is :" << Area << endl;
}

int main()
{
    
}
