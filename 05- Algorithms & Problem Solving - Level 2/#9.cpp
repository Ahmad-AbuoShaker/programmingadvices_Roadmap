
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

int CountDigitFrequency(short DigitToCheck, int Num) {
    int Reminder = 0, Counter = 0;
    while (Num > 0)
    {
        Reminder = Num % 10;
        Num = Num / 10;

        if (DigitToCheck == Reminder) {
            Counter++;
        }

    }
    return Counter;
}

void PrintAllDigitFrequency(int Number) {
    short DigitFrequency = 0;
    for (short i = 1; i <= 9; i++) {
        DigitFrequency = CountDigitFrequency(i, Number);
        if (DigitFrequency > 0) {
            cout << " Digit " << i << " Frequency is "
                << DigitFrequency << " Time(s).\n";
        }
    }
}

int main()
{
    PrintAllDigitFrequency(ReadPositiveNumber(" Enter a Number :"));
}
