#include <iostream>
using namespace std;

int main()
{
    int Pin = 9541, B = 7550, pin, i = 0;

    while (i < 3) {
        cout << "Enter your pin: ";
        cin >> pin;

        if (Pin == pin) {
            cout << "Your balance: " << B;
            break;
        }
        else {
            cout << "Wrong pin, try again\n";
            i++;
        }
    }

    if (i == 3) {
        cout << "The card is locked";
    }

    return 0;
}