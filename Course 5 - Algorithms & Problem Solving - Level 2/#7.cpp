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

int ReversedNumber(int Num) {

    int Reminder = 0, Num2 = 0;
    while (Num > 0) {
        Reminder = Num % 10;
        Num = Num / 10;
        Num2 = Num2 * 10 + Reminder;
    }
    return Num2;
}


int main()
{
    cout << " Reverse = " << ReversedNumber(ReadPositiveNumber
    (" Enter Positive Number :"))
        << "\n";
}
