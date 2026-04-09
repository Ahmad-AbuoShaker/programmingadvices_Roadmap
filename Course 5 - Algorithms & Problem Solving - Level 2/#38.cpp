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

void AddArrayElement(int element, int Arr[100], int& length) {
    Arr[length] = element;
    length++;
}

void CopyOddNumbers(int arr1[100], int arr2[100], int length1, int& arr2length) {
    arr2length = 0;
    for (int i = 0; i < length1; i++) {
        if (arr1[i] % 2 != 0) {
            AddArrayElement(arr1[i], arr2, arr2length);
        }
    }
}

int main()
{ 
    srand((unsigned)time(NULL));
    int  Length1 = 0;
    int arr1[100];
    int arr2[100];
    int  Length2 = 0;

    FillArrayWithRandomNumber(arr1, Length1);
    CopyOddNumbers(arr1, arr2, Length1, Length2);
    
    cout << "\n Element of array 1 : ";
    PrintArray(arr1, Length1);

    cout << "\n Element of array 2 : ";
    PrintArray(arr2, Length2);

}

