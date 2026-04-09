// #15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void ReadNumber(float& A, float& B) {
    cout << " Enter number 1:";
    cin >> A;
    cout << " Enter number 2:";
    cin >> B;
}

float CalculateRectangle(float A, float B) {
    return A * B;
}
void PrintResult(float Area) {
    cout << " Area of rectangle is :" << Area << endl;
}

int main()
{
    float A, B;

    ReadNumber(A, B);
    PrintResult(CalculateRectangle(A, B));
    return 0;

}
