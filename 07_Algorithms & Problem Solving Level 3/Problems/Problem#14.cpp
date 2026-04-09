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

            Arr[i][j] = RandomNumber(0,9 );
        }
    }
}

void PrintMatrix(int Arr[10][10], int Rows, int Cols) {
    cout << "\n";
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout<<"    " << Arr[i][j] << "   ";
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

bool IsScalarMarix(int Matrix1[10][10], int Rows, int Cols) {
    short FirstDiagElemment = Matrix1[0][0];
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (i == j && Matrix1[i][j] != FirstDiagElemment) {
                return false;
            }
            else if (i != j && Matrix1[i][j] != 0) {
                return false;
            }
        }
    }
    return true;

}


int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[10][10] = { {9,0,0},{0,9,0},{0,0,9} };


  //  FillMatrixWithOrdereNumbers(Matrix1, 3, 3);
    cout << "\n Matrix 1 : \n";
    PrintMatrix(Matrix1, 3, 3);


    if (IsScalarMarix(Matrix1, 3, 3))  
        cout << "\nYES: Matrix is scalar."; 
    else 
        cout << "\nNo: Matrix is NOT scalar.";

    







}
