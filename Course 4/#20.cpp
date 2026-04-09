// #17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

float ReadSquareSaid() {
    float D;
    cout << " Enter square said : ";
    cin >> D;
    return D;
}
float circleAreaInscribedSquare(float D) {
    const float pi = 3.141592653589793238;
    return pow(D / 2, 2) * pi;

}

void PrintResult(float Area) {
    cout << " Area of circle is :" << Area << endl;
}
int main()
{
    PrintResult(circleAreaInscribedSquare(ReadSquareSaid()));
}
