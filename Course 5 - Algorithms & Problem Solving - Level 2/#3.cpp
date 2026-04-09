
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

bool isPerfectNumber(int Num) {
    int Sum = 0;
    for (int i = 1; i <= round(Num / 2); i++)
    {
        if (Num % i == 0) {
            Sum += i;
        }
    }
    return Num == Sum;
}

void PrintResult(int Number){
    if (isPerfectNumber(Number)) {
        cout << " The Number is Perfect." << endl;
    }
    else
    {
        cout << " The Number is not Perfect." << endl;
    }
}

int main()
{
    PrintResult(ReadPositiveNumber(" Enter a positive Number :"));
}

