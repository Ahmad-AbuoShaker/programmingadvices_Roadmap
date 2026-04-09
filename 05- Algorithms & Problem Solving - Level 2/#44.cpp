// #24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;



int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillArrayWithRandomNumber(int Arr[100], int& ArrLength) {
    cout << "\n Enter the number of element :\n";
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

int PositiveCount(int arr1[100], int length1) {
    int counter = 0;
    for (int i = 0; i < length1; i++) {
        if (arr1[i] >= 0) {
            counter++;
        }
    }
    return counter;
}

int main()
{
    int  Length1;
    int arr1[100];

    FillArrayWithRandomNumber(arr1, Length1);

    cout << "\n Element of array 1 : ";
    PrintArray(arr1, Length1);


    cout << "\n even number count in array :" << PositiveCount(arr1, Length1) << endl;


}
