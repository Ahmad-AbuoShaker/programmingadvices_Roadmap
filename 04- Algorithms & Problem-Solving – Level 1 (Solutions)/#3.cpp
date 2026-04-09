// #3.cpp : Th9is file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum enNumberTypr{Odd=1,Even=2};
int ReadNumber() {
    int Num;
    cout << " Enter a number :";
        cin >> Num;
        return Num;
}
enNumberTypr CheckNumberType(int Num){
    if (Num % 2 == 0) {
        return Even;
    }
    else {
        return Odd;
    }
}
void PrintNumberType(enNumberTypr NumberType) {

    if (NumberType == enNumberTypr::Even) {
        cout << "\n Number is Even." << endl;
    }
    else {
        cout << "\n Number is Odd." << endl;
    }
}

int main()
{
    PrintNumberType(CheckNumberType(ReadNumber()));
    return 0;
}

 