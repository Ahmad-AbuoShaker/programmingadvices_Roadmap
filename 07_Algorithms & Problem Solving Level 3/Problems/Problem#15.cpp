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

            Arr[i][j] = RandomNumber(1, 9);
        }
    }
}

void PrintMatrix(int Arr[10][10], int Rows, int Cols) {
    cout << "\n";
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << "    " << Arr[i][j] << "   ";
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

int CountNumberInMatrix(int Matrix1[10][10], int Number, int Rows, int Cols) {
    int count = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if ( Matrix1[i][j] == Number) {
                count++;
            }
           
        }
    }
    return count;

}


int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[10][10];


    FillMatrixWithOrdereNumbers(Matrix1, 3, 3);
    cout << "\n Matrix 1 : \n";
    PrintMatrix(Matrix1, 3, 3);

    int Number;
    cout << "\nEnter the number to count in matrix? ";
    cin >> Number;


    cout << "\nNumber " << Number << " count in matrix is "
        << CountNumberInMatrix(Matrix1, Number, 3, 3);
    system("pause>0");






}
