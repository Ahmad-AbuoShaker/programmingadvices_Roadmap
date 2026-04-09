#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;


void PrintFibonacciUsingLoop(int number ,int Preves1, int Preves2 ) {
    int FebNumber ;
    
    if (number > 0) {


        
        FebNumber = Preves1 + Preves2;
        cout << "  " << FebNumber;
        Preves1 = Preves2;
        Preves2 = FebNumber;
        PrintFibonacciUsingLoop(number - 1, Preves1, Preves2);
    }

}

int main()
{

    cout << "\nFibonacci Number : ";
    PrintFibonacciUsingLoop(10,0,1);


}
