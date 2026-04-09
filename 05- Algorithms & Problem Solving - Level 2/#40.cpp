// #24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void FillArray(int arr[100], int& arrLength)
{
    arrLength = 10;  // Set the array length to 10 elements.

    // Manually assign values to the array elements.
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}

void ReadArray(int Arr[100], int& ArrLength) {
    cout << " Enter the number of element :";
    cin >> ArrLength;
    cout << " Enter array elements :\n";
    for (int i = 0; i < ArrLength; i++) {
        cout << " Elements [" << i + 1 << "] :";
        cin >> Arr[i];
        cout << "\n";
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

short FindNumberPositionInArray(int element, int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        if (element == arr[i])
            return i;
    }
    return -1;
}

bool IsNumberInArray(int element, int arr[100], int arrLength) {
    return FindNumberPositionInArray(element, arr, arrLength) != -1;
}

void CopyDistinctNumbersToArray(int arr1[100], int arr2[100], int length1, int& arr2length) {
    arr2length = 0;
    for (int i = 0; i < length1; i++) {
        if (!IsNumberInArray(arr1[i], arr2, arr2length)) {
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

    FillArray(arr1, Length1);
    CopyDistinctNumbersToArray(arr1, arr2, Length1, Length2);

    cout << "\n Element of array 1 : ";
    PrintArray(arr1, Length1);

    cout << "\n Copy Distinct Numbers To array 2 : ";
    PrintArray(arr2, Length2);

}

