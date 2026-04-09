
#include <iostream>
#include<string>
#include<cmath>
using namespace std;

int ReadPositiveNum(string Message) {
    int Num;
    do {
        cout << Message;
        cin >> Num;
    } while (Num <= 0);
    return Num;
}

bool CheckPrime(int Num) {
    for (int Counter = 2; Counter <= round(Num / 2); Counter++) {
        if (Num % Counter == 0) {
            return false;
        }
    }
    return true;
}

void PrintNumberType(int Num) {
    if (CheckPrime(Num))
        cout << " Number is Prime\n";
    else
        cout << " Number is Not Prime\n";
}

int main()
{
     PrintNumberType(ReadPositiveNum(" Enter positive Number :"));
}

