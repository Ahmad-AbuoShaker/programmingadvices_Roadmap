

#include <iostream>

using namespace std;

bool IsLeabYear(int Year) {
    return(Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

int NumberOfDaysInYear(int Year) {
    return(IsLeabYear) ? 366 : 365;
}
int NumberOfHoursInYear(int Year) {
    return NumberOfDaysInYear(Year) * 24;
}
int NumberOfMinutesInYear(int Year) {
    return NumberOfHoursInYear(Year) * 60;
}
int NumberOfSecondsInYear(int Year) {
    return NumberOfMinutesInYear(Year) * 60;
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
