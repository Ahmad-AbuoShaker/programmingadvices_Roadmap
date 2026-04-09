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




int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[3][3];


    FillMatrixWithRandomNumber(Matrix1, 3, 3);
    cout << "\n Matrix 1 : \n";
    PrintMatrix(Matrix1, 3, 3);
    int Number=0;
    cout << "\n Enter a number to look for it in matrix :";
    cin >> Number;
    if (IsNumberInMatrix(Matrix1,Number, 3, 3))
        cout << "\nYes: It is there\n";
    else
        cout << "\nNo: It's NOT there\n";


    system("pause>0");






}
