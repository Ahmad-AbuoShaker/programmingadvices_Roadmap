// #24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int ReadNumber()
{
    cout << "\n Enter a number :\n ";
    int num = 0;
    cin >> num;
    return num;
}

void PrintArray(int Arr[100], int ArrLength) {
    for (int i = 0; i < ArrLength; i++) {
        cout << Arr[i] << " ";
    }
    cout << "\n";
}

void AddArrayElement(int element, int Arr[100], int &length) {
    Arr[length] = element;
    length++;
}

void InputUserNumbersInArray(int Arr[100], int &ArrLength) {
    bool AddMore;
    do {
        AddArrayElement(ReadNumber(), Arr, ArrLength);
            cout << " Do you want to add more element ? {NO:(0)/YES(1)} ";
            cin >> AddMore;
    } while (AddMore && ArrLength <= 100);
}


int main()
{
    int  Length = 0;
    int arr[100];
   
    InputUserNumbersInArray(arr, Length);
    cout << "\n Array Length :" << Length;
    cout << "\n Element of array : ";
    PrintArray(arr, Length);

}

