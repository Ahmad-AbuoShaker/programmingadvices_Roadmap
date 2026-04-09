#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillMatrixWithRandomNumber(int Arr[10][10], int RowNumber, int Cols) {

    for (int i = 0; i < RowNumber; i++) {
        for (int j = 0; j < Cols; j++)
        {
            Arr[i][j] = RandomNumber(1, 99);
        }
    }
}

void PrintMatrix(int Arr[10][10], int RowNumber, int Cols) {
    cout << "\n";
    for (int i = 0; i < RowNumber; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << setw(3) << Arr[i][j] << "  ";
        }
        cout << "\n";
    }

    cout << "\n";
}

int SumRow(int Arr[10][10], int RowNumber, int Cols) {

    int sum = 0;
    for (int i = 0; i < Cols; i++) {
        sum += Arr[RowNumber][i];
    }
    return sum;
}

void Sum_MatrixRowsIn_Array(int x[10], int Arr[10][10], int Rows, int Cols) {
    for (int i = 0; i < Rows; i++) {
        x[i] = SumRow(Arr, i, Cols);
    }
}

void Print_RowSum_Array(int x[10],int Arr[10][10], int Rows, int Cols) {

    cout << "\n The following are the sum each row in the matrix :\n";
    for (int i = 0; i < Rows; i++) {
        cout << " Row " << i + 1 << " Sum = " << x[i] << endl;
    }
}

int main()
{
    int Arr[10][10],x[10], Rows = 3, Cols = 3;
    FillMatrixWithRandomNumber(Arr, Rows, Cols);
    cout << "\n Matrix : \n";
    PrintMatrix(Arr, Rows, Cols);
    Sum_MatrixRowsIn_Array(x,Arr, Rows, Cols);

    Print_RowSum_Array(x,Arr, Rows, Cols);
}
