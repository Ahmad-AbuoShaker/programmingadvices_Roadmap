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



bool  IsNumberInMatrix(int Matrix1[3][3], int Number, int Rows, int Cols) {

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (Matrix1[i][j] == Number) {
                return true;
            };

        }
    }
    return false;

}

void PrintIntersectedNumber(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Cols) {
    int Number = 0;

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++) 
        {
            Number = Matrix2[i][j];
            if (IsNumberInMatrix(Matrix1,Matrix2[i][j], 3, 3)) {
               
                cout << setw(3) << Number << "  ";

            };

        }
    }
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

    FillMatrixWithRandomNumber(Matrix2, 3, 3);
    cout << "\n Matrix 1 : \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "\n Intersected Number : ";
    PrintIntersectedNumber(Matrix1,Matrix2, 3, 3);


    system("pause>0");

}
