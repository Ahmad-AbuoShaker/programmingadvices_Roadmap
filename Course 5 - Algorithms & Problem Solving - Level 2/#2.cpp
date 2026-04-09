
#include <iostream>
using namespace std; 
enum enPrimeNum{ Prime = 1, NotPrime = 2 };

int ReadPositiveNumber(string Message) {
    int Num = 0;
    do {
        cout << Message << endl<<" ";
        cin >> Num;
    } while (Num<0);
    return Num;
}

enPrimeNum CheckPrimeNum(int Num) {
    for (int i = 2; i <= round(Num / 2); i++)
    {
        if (Num % i == 0) {
            return enPrimeNum::NotPrime;
        }
    }
    return enPrimeNum::Prime;
}

void PrintPrimeNumberFrom1ToN(int Number) {
    cout << "\n Prime Number from 1 to " << Number << " are :\n";
    for (int i = 1; i <= Number; i++) {
        if (CheckPrimeNum(i) == enPrimeNum::Prime) {
            cout <<" " << i << endl;
        }
    }
}

int main()
{
    PrintPrimeNumberFrom1ToN(ReadPositiveNumber(" Enter a positive Number :"));
}


