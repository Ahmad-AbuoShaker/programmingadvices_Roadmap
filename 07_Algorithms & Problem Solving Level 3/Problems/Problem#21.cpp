#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;


void PrintFibonacciUsingLoop(int number) {
    int FebNumber = 0, Preves1 = 0, Preves2 = 1;
    cout << " 1";
    for (int i = 0; i < number; i++) {
        FebNumber = Preves1 + Preves2;
        cout << "  " << FebNumber;
        Preves1 = Preves2;
        Preves2 = FebNumber;
        
    }
}

int main()
{

    cout << "\nFibonacci Number : ";
    PrintFibonacciUsingLoop(10);
    

}
