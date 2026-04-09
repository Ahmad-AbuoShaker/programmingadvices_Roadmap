// #24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillArrayWithRandomNumber(int Arr[100], int& ArrLength) {
    cout << "\n Enter the number of element :\n ";
    cin >> ArrLength;
    for (int i = 0; i < ArrLength; i++) {
        Arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int Arr[100], int ArrLength) {
    for (int i = 0; i < ArrLength; i++) {
        cout << Arr[i] << " ";
    }
    cout << "\n";
}

int SumArray(int Arr[100], int ArrLength) {
    int Sum = 0;
    for (int i = 0; i < ArrLength; i++) {
        Sum += Arr[i];
    }
    return Sum;
}

float ArrayAverage(int Arr[100], int ArrLength) {
    return (float)(SumArray(Arr, ArrLength) / ArrLength);
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], Length = 0;

    FillArrayWithRandomNumber(arr, Length);
    cout << " Element of Array :";
    PrintArray(arr, Length);
    cout << "\n Average of all Number in Random Array is : ";
    cout << ArrayAverage(arr, Length) << endl;

}

