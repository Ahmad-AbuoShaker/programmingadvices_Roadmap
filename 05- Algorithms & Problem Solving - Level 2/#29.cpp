// #24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum enPrimeNum { Prime = 1, NotPrime = 2 };

enPrimeNum CheckPrimeNum(int Num) {
    for (int i = 2; i <= round(Num / 2); i++)
    {
        if (Num % i == 0) {
            return enPrimeNum::NotPrime;
        }
    }
    return enPrimeNum::Prime;
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

void CopyOnlyPrimeToArray(int ArrSource[100], int ArrDestination[100], int ArrLength, int& Arr2Length) {
    int counter = 0;
    for (int i = 0; i < ArrLength; i++) {
        
            if (CheckPrimeNum(ArrSource[i])==Prime) {
                ArrDestination[counter] =ArrSource[i];
                counter++;
            }
            Arr2Length = counter;
        
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int arr[100], Length, arr2[100], Length2 = 0;

    FillArrayWithRandomNumber(arr, Length);
    CopyOnlyPrimeToArray(arr, arr2, Length, Length2);

    cout << "\n Element of Array :\n ";
    PrintArray(arr, Length);

    cout << "\n Array 2 elements after copy : \n ";
    PrintArray(arr2, Length2);

}

