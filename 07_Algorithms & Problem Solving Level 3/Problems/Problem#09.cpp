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

void PrintMiddleRowOfMatrix(int Arr[10][10], int Rows, int Cols) {
    short MiddleRow = Rows / 2;
    cout << "\n  Middle Row Of Matrix is :\n";
    for (int i = 0; i < Cols; i++) {
            printf(" %0*d ", 2, Arr[MiddleRow][i]);
    }
    cout << "\n";
}

void PrintMiddleColOfMatrix(int Arr[10][10], int Rows, int Cols) {
    short MiddleCol = Cols / 2;
    cout << "\n  Middle Col Of Matrix is :\n";
    for (int i = 0; i < Rows; i++) {
            printf(" %0*d ", 2, Arr[i][MiddleCol]);
    }
    cout << "\n";
}



int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[10][10];

    FillMatrixWithOrdereNumbers(Matrix1, 3, 3);
    cout << "\n Matrix 1 : \n";
    PrintMatrix(Matrix1, 3, 3);

    PrintMiddleRowOfMatrix(Matrix1, 3, 3);

    PrintMiddleColOfMatrix(Matrix1, 3, 3);





}
