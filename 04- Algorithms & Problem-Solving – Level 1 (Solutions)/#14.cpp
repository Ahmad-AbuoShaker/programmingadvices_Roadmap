// #14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void Read2Number(int& Num1, int& Num2) {
    cout << " Enter the Number 1 :";
    cin >> Num1;
    cout << " Enter the Number 2 :";
    cin >> Num2;
}
void Swap(int& Num1, int& Num2) {
    int Temp = Num1;
    Num1 = Num2;
    Num2 = Temp;
}
void PrintNumber(int Num1,int Num2) {
    cout << " Number 1:" << Num1 << endl;
    cout << " Number 2:" << Num2 << endl;
}
int main()
{ 
    int Num1,Num2;
    Read2Number(Num1, Num2); 
    PrintNumber(Num1, Num2);
    Swap(Num1, Num2);
    PrintNumber(Num1, Num2);
}

