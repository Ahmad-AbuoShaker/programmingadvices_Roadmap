#include <iostream>

using namespace std;
//
//string IsNumberPsitive(int Number) {
//    string Result;
//    (Number > 0) ? Result="Positive" : Result="Nigative";
//    return Result;
//
//}
//string IsZero(int Number) {
//    string Result;
//    (Number == 0) ? Result= "0" : Result=IsNumberPsitive(Number);
//    return Result;
//
//}

int main()
{
    int Number=50;
    string Result;
    Result = (Number == 0) ? "0" : (Number > 0) ? "Positive" : "Nigative";
    cout << Result;
}
