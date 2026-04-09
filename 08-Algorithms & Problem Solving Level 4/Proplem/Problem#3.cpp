

#include <iostream>

using namespace std;

bool IsLeabYear(int Year) {
    return(Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

int main()
{
    do {
        int Number;
        cout << " ";
        cin >> Number;
        cout << IsLeabYear(Number);
    } while (1);
}
