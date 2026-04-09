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
void swap(int& x,int& y){
    int Temp = x;
    x = y;
    y = Temp;

}

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillArrayWith1toN(int Arr[100], int& ArrLength) {
    for (int i = 0; i < ArrLength; i++) {
        Arr[i] = i+1;
    }
}


void PrintArray(int Arr[100], int ArrLength) {
    for (int i = 0; i < ArrLength; i++) {
        cout << Arr[i] << " ";
    }
    cout << "\n";
}

void ShuffleArray(int Arr[100], int ArrLength) {
    int Num;
    for (int i = 0; i < ArrLength; i++) {
        swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int arr[100],Length = 0;

    Length = ReadPositiveNumber(" Enter number of element.");

    FillArrayWith1toN(arr, Length);
    cout << "\n Array 2 elements after copy : \n ";
    PrintArray(arr, Length);


    ShuffleArray(arr, Length);
    cout << "\n Element of Array :\n ";
    PrintArray(arr, Length);

   

}

