

#include <iostream>

using namespace std;

bool IsLeabYear(int Year) {
    return(Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
short NumberOfDaysInMonth(short Year, short Month) {
    if (Month < 1 || Month>12) {
        return 0;
    }
    short daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    return Month == 2 && IsLeabYear(Year) ? 29 : daysInMonth[Month];
}
short NumberOfHoursInMonth(short Year, short Month) {
    return NumberOfDaysInMonth(Year, Month) * 24;
}
short NumberOfMinutesInMonth(short Year, short Month) {
    return NumberOfHoursInMonth(Year, Month) * 60;
}
short NumberOfSecondsInMonth(short Year, short Month) {
    return NumberOfMinutesInMonth(Year, Month) * 60;
}

short DayOfWeekOrder(short Year, short Month, short Day) {
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    
}
string DayName(int DayOfWeekOrder) {
    string ArrDay[] = { "Sunday","Monday","Tusday","Wednesday",
        "Thursday","Friday","Saturday" };
    return ArrDay[DayOfWeekOrder];
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
