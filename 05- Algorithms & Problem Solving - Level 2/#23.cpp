
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
        Arr[i]= RandomNumber(1,100);
    }
}

void PrintArray(int Arr[100], int ArrLength) {
    for (int i = 0; i < ArrLength; i++) {
        cout << Arr[i] << " ";
    }
    cout << "\n";
}


int main()
{
    srand((unsigned)time(NULL));
    int Arr[100], length = 0;
    
    FillArrayWithRandomNumber(Arr, length);

    cout << "\n Array Element : ";
    PrintArray(Arr, length);
    
    return 0;
}
