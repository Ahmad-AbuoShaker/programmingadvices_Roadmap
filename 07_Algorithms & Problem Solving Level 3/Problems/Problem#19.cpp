#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillMatrixWithRandomNumber(int Arr[3][3], int Rows, int Cols) {

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++)
        {
            Arr[i][j] = RandomNumber(1, 99);
        }
    }
}


void PrintMatrix(int Arr[3][3], int Rows, int Cols) {
    cout << "\n";
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << setw(2) << Arr[i][j] << "   ";
        }
        cout << "\n";
    }

    cout << "\n";
}



int  MaxNumberInMatrix(int Matrix1[3][3], int Rows, int Cols) {

    int Max = Matrix1[0][0];
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (Matrix1[i][j] > Max) {
                Max = Matrix1[i][j];
            };

        }
    }
    return Max;

}
int  MinNumberInMatrix(int Matrix1[3][3], int Rows, int Cols) {

    int Min = Matrix1[0][0];
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (Matrix1[i][j] < Min) {
                Min = Matrix1[i][j];
            };

        }
    }
    return Min;

}


int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[3][3];
    int Matrix2[3][3];
    int x[10];


    FillMatrixWithRandomNumber(Matrix1, 3, 3);
    cout << "\n Matrix 1 : \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMinimum Number is: ";
    cout << MinNumberInMatrix(Matrix1, 3, 3);

    cout << "\n\nMax Number is: ";
    cout << MaxNumberInMatrix(Matrix1, 3, 3);

    system("pause>0");

}
