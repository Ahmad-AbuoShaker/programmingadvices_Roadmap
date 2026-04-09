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

void PrintEachRowSum(int Arr[10][10], int Rows, int Cols) {
    cout << "\n The following are the sum each row in the matrix :\n";
    for (int i = 0; i < Rows; i++) {
        cout << " Row " << i + 1 << " Sum = " << SumRow(Arr, i, Cols)<<endl;
    }
}

int main()
{
    int x[10][10], Rows = 3, Cols = 3;
    FillMatrixWithRandomNumber(x, Rows, Cols);
    cout << "\n Matrix : \n";
    PrintMatrix(x, Rows, Cols);

    PrintEachRowSum(x,Rows,Cols);
}
