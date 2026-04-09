#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;


void FillMatrixWithOrdereNumbers(int Arr[10][10], int Rows, int Cols) {
    int counter = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++)
        {
            ++counter;
            Arr[i][j] = counter;
        }
    }
}

void PrintMatrix(int Arr[10][10], int Rows, int Cols) {
    cout << "\n";
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << setw(3) << Arr[i][j] << "    ";
        }
        cout << "\n";
    }

    cout << "\n";
}


int main()
{
    int x[10][10], Rows = 3, Cols = 3;
    FillMatrixWithOrdereNumbers(x, Rows, Cols);
    cout << "\n Matrix : \n";
    PrintMatrix(x, Rows, Cols);
}
