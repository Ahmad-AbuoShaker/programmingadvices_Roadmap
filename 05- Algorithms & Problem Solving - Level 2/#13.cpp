#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message) {
    int Num = 0;
    do {
        cout << Message << endl << " ";
        cin >> Num;
    } while (Num < 0);
    return Num;
}

void PrintNumberPatter(short Num) {
    for (int i = 1; i <= Num; i++) {

        for (int j = 1; j <= i; j++) {
            cout <<" "<< i;
        }
        cout << "\n";



    }
}
int main()
{
    PrintNumberPatter(ReadPositiveNumber(" Enter a Number :"));
}

