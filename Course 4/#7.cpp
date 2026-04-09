// #7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int ReadNumber() {
    int Num;
    cout << " Enter a Number :";
    cin >> Num;
    return Num;
}
float CalculatetHalfNumber(int Num) {
    return (float)Num / 2;
}
void PrintResults(int Num) {
    cout << "\n Half of " << Num <<" is :"<<CalculatetHalfNumber(Num)<< endl;
}
int main()
{
    PrintResults(ReadNumber());
}

