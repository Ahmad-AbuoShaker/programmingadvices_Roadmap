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

bool  IsRowsMatrixPalindrome(int Matrix1[3][3], int Rows, int Cols) {

    int Max = Matrix1[0][0];
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols/2; j++) {
            if (Matrix1[i][j]!=Matrix1[i][Cols-1-j]) {
                return false;
            };

        }
    }
    return true;

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

 

   
    if (IsRowsMatrixPalindrome(Matrix1, 3, 3)) {
        cout << "\nRows Matrix is Palindrome : ";
    }
    else {
        cout << "\nRows Matrix is not Palindrome : ";
    }
    system("pause>0");

}
