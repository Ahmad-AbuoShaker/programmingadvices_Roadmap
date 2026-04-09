#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;



void PrintMatrix(int Arr[3][3], int Rows, int Cols) {
    cout << "\n";
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << "    " << Arr[i][j] << "   ";
        }
        cout << "\n";
    }

    cout << "\n";
}



int CountNumberInMatrix(int Matrix1[3][3],int Number, int Rows, int Cols) {
    int count = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (Matrix1[i][j] == Number) {
                count++;
            }

        }
    }
    return count;

}

bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols) {
    short MatrixSize = Rows * Cols;
    return(CountNumberInMatrix(Matrix1,0,3,3) > MatrixSize / 2);
}


int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[3][3] = { {0,0,12},{9,0,1},{0,0,9} };



    cout << "\n Matrix 1 : \n";
    PrintMatrix(Matrix1, 3, 3);

    if (IsSparseMatrix(Matrix1, 3, 3))
        cout << "\nYes: It is Sparse\n";
    else
        cout << "\nNo: It's NOT Sparse\n";


    system("pause>0");






}
