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
    arr[5] = 50;
    arr[6] = 50;
    arr[7] = 10;
    arr[8] = 10;
    arr[9] = 10;
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

bool isArrayPalindrome(int Arr[100], int length) {
    for (int i = 0; i <= floor(length / 2); i++) {

        if (Arr[i] != Arr[length - 1 - i]) {
            return false;
        }
    }
    return  true;
}

int main()
{    int  Length1 = 0;
    int arr1[100];

    FillArray(arr1, Length1);

    cout << "\n Element of array 1 : ";
    PrintArray(arr1, Length1);

    if (isArrayPalindrome(arr1, Length1)) {
        cout << "\n Array is Palindrome\n";
    }
    else{
        cout <<"\n Array is not Palindrome\n";
  }


}

