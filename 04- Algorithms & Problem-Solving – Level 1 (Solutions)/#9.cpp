// #7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;



void ReadNumber(int& Num1, int& Num2, int& Num3) {
    
    cout << " Enter the number 1 :";
    cin >> Num1;               
    cout << " Enter the number 2 :";
    cin >> Num2;               
    cout << " Enter the number 3 :";
    cin >> Num3;
}



int SumOfNumbers(int Num1, int Num2, int Num3){
    return Num1 + Num2 + Num3;
}

void PrintResults(int Total) {
    cout << " The total sum of numbers is :" << Total << endl;

}


int main()
{
    int Num1,Num2,Num3;
    ReadNumber(Num1, Num2, Num3);
    PrintResults(SumOfNumbers(Num1, Num2, Num3));
    return 0;
}

