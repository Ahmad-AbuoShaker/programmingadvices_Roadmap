
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

void PrintPerfectNumFrom1ToN(int Number) {
    cout << " Perfect Number from 1 to " << Number << " :\n";
    for (int i = 1; i <= Number; i++) {
        if (isPerfectNumber(i)) {
            cout << i << endl;
        }
    }
    
}

int main()
{
    PrintPerfectNumFrom1ToN(ReadPositiveNumber(" Enter a positive Number :"));
}

