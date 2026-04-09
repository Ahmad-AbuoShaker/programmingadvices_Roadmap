// #7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum enPassFail{Pass=1,Fail=2};

int ReadMark() {
    int mark;
    cout << " Enter the mark :";
    cin >> mark;
    return mark;
}

enPassFail CheckMark(int mark) {
    if (mark < 50)
        return Fail;
    else
        return Pass;
}

void PrintResults(int mark) {
    if (CheckMark(mark) == enPassFail::Pass)
        cout << " You passed" << endl;
    else
        cout << " You faild" << endl;


}

int main()
{
    PrintResults(ReadMark());
}

