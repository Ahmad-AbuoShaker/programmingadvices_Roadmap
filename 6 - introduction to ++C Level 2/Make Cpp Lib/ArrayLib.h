#pragma once
#include<iostream>
#include<cmath>
using namespace std;


namespace ArrayLib {

    bool isArrayPalindrome(int Arr[100], int length) {
        for (int i = 0; i <= floor(length / 2); i++) {

            if (Arr[i] != Arr[length - 1 - i]) {
                return false;
            }
        }
        return  true;
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

    void FillArrayWithRandomNumber(int Arr[100], int& ArrLength) {
        cout << "\n Enter the number of element :\n";
        cin >> ArrLength;
        for (int i = 0; i < ArrLength; i++) {
            Arr[i] = RandomNumber(1, 100);
        }
    }

    void FillArrayWith1toN(int Arr[100], int& ArrLength) {
        for (int i = 0; i < ArrLength; i++) {
            Arr[i] = i + 1;
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

    void InputUserNumbersInArray(int Arr[100], int& ArrLength) {
        bool AddMore;
        do {
            AddArrayElement(ReadNumber(), Arr, ArrLength);
            cout << " Do you want to add more element ? {NO:(0)/YES(1)} ";
            cin >> AddMore;
        } while (AddMore && ArrLength <= 100);
    }

    void CopyArray(int ArrSource[100], int ArrDestination[100], int ArrLength) {

        for (int i = 0; i < ArrLength; i++) {
            ArrDestination[i] = ArrSource[i];
        }
    }

    void CopyOddNumbers(int arr1[100], int arr2[100], int length1, int& arr2length) {
        arr2length = 0;
        for (int i = 0; i < length1; i++) {
            if (arr1[i] % 2 != 0) {
                AddArrayElement(arr1[i], arr2, arr2length);
            }
        }
    }

    void CopyPrimeNumbers(int arr1[100], int arr2[100], int length1, int& arr2length) {
        arr2length = 0;
        for (int i = 0; i < length1; i++) {
            if (CheckPrimeNum(arr1[i]) == Prime) {
                AddArrayElement(arr1[i], arr2, arr2length);
            }
        }
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

    int OddCount(int arr1[100], int length1) {
        int counter = 0;
        for (int i = 0; i < length1; i++) {
            if (arr1[i] % 2 != 0) {
                counter++;
            }
        }
        return counter;
    }

    int EvenCount(int arr1[100], int length1) {
        int counter = 0;
        for (int i = 0; i < length1; i++) {
            if (arr1[i] % 2 == 0) {
                counter++;
            }
        }
        return counter;
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

    int NegativeCount(int arr1[100], int length1) {
        int counter = 0;
        for (int i = 0; i < length1; i++) {
            if (arr1[i] < 0) {
                counter++;
            }
        }
        return counter;
    }

    void ShuffleArray(int Arr[100], int ArrLength) {
        int Num;
        for (int i = 0; i < ArrLength; i++) {
            swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
        }
    }

    void CopyOnlyPrimeToArray(int ArrSource[100], int ArrDestination[100], int ArrLength, int& Arr2Length) {
        int counter = 0;
        for (int i = 0; i < ArrLength; i++) {

            if (CheckPrimeNum(ArrSource[i]) == Prime) {
                ArrDestination[counter] = ArrSource[i];
                counter++;
            }
            Arr2Length = counter;

        }
    }

    int MaxNumberInArray(int Arr[100], int ArrLength) {
        int MaxNum = Arr[0];
        for (int i = 0; i < ArrLength; i++) {
            if (Arr[i] > MaxNum) {
                MaxNum = Arr[i];
            }
        }
        return MaxNum;
    }

    int MinNumberInArray(int Arr[100], int ArrLength) {
        int MinNum = Arr[0];
        for (int i = 0; i < ArrLength; i++) {
            if (Arr[i] < MinNum) {
                MinNum = Arr[i];
            }
        }
        return MinNum;
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

    int TimesRepeated(int Number, int Array[100], int ArrLength) {
        int counter = 0;
        for (int i = 0; i < ArrLength; i++) {
            if (Number == Array[i]) {
                counter++;
            }
        }
        return counter;
    }

}