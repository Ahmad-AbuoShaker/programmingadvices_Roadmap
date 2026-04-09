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

int SumCol(int Arr[10][10], int Rows, int ColNumber) {

    int sum = 0;
    for (int i = 0; i < Rows; i++) {
        sum += Arr[i][ColNumber];
    }
    return sum;
}

void PrintEachColSum(int Arr[10][10], int Rows, int Cols) {
    cout << "\n The following are the sum each row in the matrix :\n";
    for (int i = 0; i < Cols; i++) {
        cout << " col " << i + 1 << " Sum = " << SumCol(Arr, Rows, i) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int x[10][10], Rows = 3, Cols = 3;
    FillMatrixWithRandomNumber(x, Rows, Cols);
    cout << "\n Matrix : \n";
    PrintMatrix(x, Rows, Cols);

    PrintEachColSum(x, Rows, Cols);
}
