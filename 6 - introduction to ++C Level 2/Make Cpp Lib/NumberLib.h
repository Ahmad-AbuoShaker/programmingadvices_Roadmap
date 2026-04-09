#pragma once

#include<iostream>
using namespace std;

namespace NumberLib {

    int ReadNumber() {
        int Number = 0;
        cout << " Enter a Number : ";
        cin >> Number;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << " Invaild Number, Enter a vail Number :";
            cin >> Number;
        }
        return Number;
    }


    enum enPrimeNum { Prime = 1, NotPrime = 2 };
    enPrimeNum CheckPrimeNum(int Num) {
        for (int i = 2; i <= round(Num / 2); i++)
        {
            if (Num % i == 0) {
                return enPrimeNum::NotPrime;
            }
        }
        return enPrimeNum::Prime;
    }

    bool isPerfectNumber(int Num) {
        int Sum = 0;
        for (int i = 1; i <= round(Num / 2); i++)
        {
            if (Num % i == 0) {
                Sum += i;
            }
        }
        return Num == Sum;
    }

    int ReversedNumber(int Num) {
        //???? ???? ????? ???????
        int Reminder = 0, Num2 = 0;
        while (Num > 0) {
            Reminder = Num % 10;
            Num = Num / 10;
            Num2 = Num2 * 10 + Reminder;
        }
        return Num2;
    }

    bool isNumberPalindrome(int Number) {

        return Number == ReversedNumber(Number);
    }

    int Sum_Print_OfDigits(int Num)
    {
        int Reminder = 0, Sum = 0;
        while (Num > 0) {
            Reminder = Num % 10;
            Num = Num / 10;
            cout << Reminder << endl;
            Sum += Reminder;
        }
        return Sum;
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


}