// #22.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void ReadArray(int Arr[100], int& ArrLength) {
    cout << " Enter the number of element :";
    cin >> ArrLength;
    cout << " Enter array elements :\n";
    for (int i = 0; i < ArrLength; i++) {
        cout << " Elements [" << i+1 << "] :";
        cin >> Arr[i];
        cout << "\n";
    }
}

void PrintArray(int Arr[100], int ArrLength) {
    for (int i = 0; i < ArrLength; i++) {
        cout <<Arr[i] <<" ";
    }
    cout << "\n";
}


int TimesRepeated(int Number,int Array[100], int ArrLength) {
    int counter = 0;
    for (int i = 0; i < ArrLength; i++) {
        if (Number == Array[i]) {
            counter++;
        }
    }
    return counter;
}



int main()
{
    int Array[100], ArrLength = 0, NumberToCheck=0;
    ReadArray(Array, ArrLength);
    NumberToCheck = ReadPositiveNumber(" Enter the number you want to check :");
    cout << "\n Original array :";
    PrintArray(Array, ArrLength);
    cout << "\n Number " << NumberToCheck<< " is repeated "
        << TimesRepeated(NumberToCheck, Array, ArrLength) << endl;
   
    
}

