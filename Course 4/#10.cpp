// #7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum enPassFail{pass=1, fail =2};

void ReadNumber(int& Mark1, int& Mark2, int& Mark3) {

    cout << " Enter the Mark 1 :";
    cin >> Mark1;
    cout << " Enter the Mark 2 :";
    cin >> Mark2;
    cout << " Enter the Mark 3 :";
    cin >> Mark3;
}

int SumOf3Marks(int Mark1, int Mark2, int Mark3) {
    return Mark1 + Mark2 + Mark3;
}

float CalculateAverage(int Mark1, int Mark2, int Mark3) {
    return (float)SumOf3Marks(Mark1, Mark2, Mark3) / 3;
}
 
enPassFail CheckAverage(float Average) {
    if (Average < 50)
        return fail;
    else
        return pass;

}

void PrintResults(float Total) {
    cout << " The average is :" << Total << endl;
    if (CheckAverage(Total) == enPassFail::pass)
        cout << " You pass" << endl;
    else
        cout << " You fail" << endl;


}


int main()
{
    int Num1, Num2, Num3;
    ReadNumber(Num1, Num2, Num3);
    PrintResults(CalculateAverage(Num1, Num2, Num3));
    return 0;
}

