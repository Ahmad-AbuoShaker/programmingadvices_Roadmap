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

int ReversedNumber(int Num) {
    //���� ���� ����� �������
    int Reminder = 0, Num2 = 0;
    while (Num > 0) {
        Reminder = Num % 10;
        Num = Num / 10;
        Num2 = Num2 * 10 + Reminder;
    }
    return Num2;
}

bool isNumberPalindrome(int Number) {

    return Number == ReversedNumber(Number);
}

int main()
{
    if (isNumberPalindrome(ReadPositiveNumber(" Enter Number :"))) {
        cout << "\n Yes, Number is  Palindrome.\n";
   }
    else {
        cout << "\n No, Number is Not Palindrome.\n";
    }
   
}
