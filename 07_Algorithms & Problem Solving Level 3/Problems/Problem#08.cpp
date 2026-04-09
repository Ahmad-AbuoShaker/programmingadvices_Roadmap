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
            
            Arr[i][j] = RandomNumber(1,10);
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

void MultiplyTowMatrix(int Matrix1[10][10], int Matrix2[10][10],int MatrixResult[10][10], int Rows, int Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            MatrixResult[i][j]= Matrix1[i][j] * Matrix2[i][j];
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[10][10], Matrix2[10][10], MatrixResult[10][10];
    
    FillMatrixWithOrdereNumbers(Matrix1,3,3);
    cout << "\n Matrix 1 : \n";
    PrintMatrix(Matrix1, 3, 3);

    FillMatrixWithOrdereNumbers(Matrix2,3,3);
    cout << "\n Matrix 2 : \n";
    PrintMatrix(Matrix2, 3, 3);

    MultiplyTowMatrix(Matrix1, Matrix2, MatrixResult, 3, 3);
    cout << "\n Multiply Matrix :\n";
    PrintMatrix(MatrixResult, 3, 3);





}
