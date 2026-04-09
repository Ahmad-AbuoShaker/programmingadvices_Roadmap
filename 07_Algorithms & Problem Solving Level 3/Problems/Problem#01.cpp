#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillMatrixWithRandomNumber(int Arr[100][100], int Rows,int Cols) {
   
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++)
        {
            Arr[i][j] = RandomNumber(1, 99);
        }
    }
}

void PrintMatrix(int Arr[100][100], int Rows, int Cols) {
    cout << "\n";
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout<<setw(3)<< Arr[i][j]<<"  ";
        }
        cout << "\n";
    }

    cout << "\n";
}


int main()
{
    int x[100][100], Rows = 3, Cols = 3;
    FillMatrixWithRandomNumber(x, Rows, Cols);
    cout << "\n Matrix : \n";
    PrintMatrix(x, Rows, Cols);
}
