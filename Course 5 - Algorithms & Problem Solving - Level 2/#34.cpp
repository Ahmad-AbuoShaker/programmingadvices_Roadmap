// #24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int ReadNumber()
{
    int num = 0;
    cin >> num;
    return num;
}

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

int FindNumberPositionInArray( int element, int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        if (element == arr[i])
            return i;
    }
    return -1;
}

int main()
{
    srand((unsigned)time(NULL));
    int  Length = 0,E;
    int arr[100];

    FillArrayWithRandomNumber(arr, Length);
    cout << " Element of array : \n ";
    PrintArray(arr, Length);
    cout << "\n Number you are looking for : \n ";
    int Element = ReadNumber();
  short NumberPosition = FindNumberPositionInArray(Element,arr,Length);
  if (NumberPosition == -1) {
      cout << " The number is not found :-(";
  }
  else {
      cout << " The number found at position :" << NumberPosition << endl;
      cout << " The number found it's order :" << NumberPosition + 1 << endl;
  }

}

