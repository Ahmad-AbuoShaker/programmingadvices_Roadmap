// #5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message) {
    int Num = 0;
    do {
        cout << Message << endl << " ";
        cin >> Num;
    } while (Num < 0);
    return Num;
}

int CountDigitFrequency(short DigitToCheck, int Num) {
    int Reminder = 0, Counter = 0;
    while (Num > 0)
    {
        Reminder = Num % 10;
        Num = Num / 10;

        if (DigitToCheck == Reminder) {
            Counter++;
        }

    }
    return Counter;
}


int main()
{
    int Number = ReadPositiveNumber(" Enter a Number :");
    short DigitToCheck = ReadPositiveNumber(" Enter one digit to check :");
        
    cout << " \nDigit "<< DigitToCheck <<" Frequency is " << CountDigitFrequency(DigitToCheck,Number)
        << " Time(s).\n";
}
