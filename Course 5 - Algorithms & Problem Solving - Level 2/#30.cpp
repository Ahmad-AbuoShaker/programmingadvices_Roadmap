// #24.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillArrayWithRandomNumber(int Arr[100], int& ArrLength) {
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
        ArrSource[i] = ArrDestination[i];
    }
}

void SumElementForTowArray(int Arr1[100],int Arr2[100],int SumArr[100], int ArrLength) {
    for (int i = 0; i < ArrLength; i++) {
        SumArr[i]= Arr1[i] + Arr2[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arr2[100],SumArr[100], Length = 0;

    Length = ReadPositiveNumber(" Enter number of element.");

    FillArrayWithRandomNumber(arr, Length);

    cout << "\n Element of Array :\n ";
    PrintArray(arr, Length);

    FillArrayWithRandomNumber(arr2, Length);

    cout << "\n Array 2 elements after copy : \n ";
    PrintArray(arr2, Length);

    SumElementForTowArray(arr, arr2,SumArr ,Length);


    cout << "\n Sum of tow Arrays elements : \n ";
    PrintArray(SumArr, Length);


}

