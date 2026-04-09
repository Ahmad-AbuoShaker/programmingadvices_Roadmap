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

void CopyArray(int ArrSource[100], int ArrDestination[100], int ArrLength) {

    for (int i = 0; i < ArrLength; i++) {
         ArrDestination[i] = ArrSource[i] ;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], Length = 0,arr2[100];

    FillArrayWithRandomNumber(arr, Length);
    CopyArray(arr, arr2, Length);

    cout << "\n Element of Array :\n ";
    PrintArray(arr, Length);

    cout << "\n Array 2 elements after copy : \n ";
    PrintArray(arr2, Length);

}

