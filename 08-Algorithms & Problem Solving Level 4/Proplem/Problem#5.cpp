

#include <iostream>

using namespace std;

bool IsLeabYear(int Year) {
    return(Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}


short NumberOfDaysInMonth(short Year,short Month) {

    if(Month < 1 || Month>12) {
        return 0;
    }

    if (Month == 2) {
        return IsLeabYear(Year) ? 29 : 28;
    }
    short Arr31Day[7] = { 1,3,5,7,8,10,12 };
    for (int i = 1; i <= 7; i++) {
        if (Arr31Day[i] == Month) {
            return 31;
        }
    }
    return 30;


}
short NumberOfHoursInMonth(short Year, short Month) {
    return NumberOfDaysInMonth(Year,Month) * 24;
}
short NumberOfMinutesInMonth(short Year, short Month) {
    return NumberOfHoursInMonth(Year, Month) * 60;
}
short NumberOfSecondsInMonth(short Year, short Month) {
    return NumberOfMinutesInMonth(Year, Month) * 60;
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
