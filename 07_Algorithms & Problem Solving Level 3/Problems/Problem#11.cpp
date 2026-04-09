#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;


int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillMatrixWithOrdereNumbers(int Arr[10][10], int Rows, int Cols) {

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++)
        {

            Arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int Arr[10][10], int Rows, int Cols) {
    cout << "\n";
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf(" %0*d   ", 2, Arr[i][j]);
        }
        cout << "\n";
    }

    cout << "\n";
}

int sumMatrix(int Arr[10][10], int Rows, int Cols) {
    int sum = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++)
        {
            sum += Arr[i][j];
        }
    }
    return sum;
}

bool AreEqualMatrices(int Matrix1[10][10], int Matrix2[10][10], int Rows, int Cols) {
    return(sumMatrix(Matrix1, Rows, Cols), sumMatrix(Matrix2, Rows, Cols));
}

int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[10][10];
    int Matrix2[10][10];

    FillMatrixWithOrdereNumbers(Matrix1, 3, 3);
    cout << "\n Matrix 1 : \n";
    PrintMatrix(Matrix1, 3, 3);

    FillMatrixWithOrdereNumbers(Matrix2, 3, 3);
    cout << "\n Matrix 2 : \n";
    PrintMatrix(Matrix2, 3, 3);

    if (AreEqualMatrices(Matrix1, Matrix2, 3, 3)) {
        cout << "\n Matrix 1 is equal Matrix 2 \n";
    }
    else {
        cout << "\n Matrix 1 is not equal Matrix 2 \n";

    }







}
