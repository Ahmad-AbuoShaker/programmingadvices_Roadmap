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

void PrintLetterPatter(short Num) {
    for (int i = 65; i <= 65 + Num - 1; i++) {
        cout << " ";
        for (int j = 65; j <= i; j++) {
            cout << char(i);
        }
        cout << "\n";
    }
}

int main()
{
    PrintLetterPatter(ReadPositiveNumber(" Enter a Number :"));
}

