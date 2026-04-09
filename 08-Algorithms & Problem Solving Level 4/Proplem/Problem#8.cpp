

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
short DayOfWeekOrder(short Day, short Month, short Year) {
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}
string DayName(int DayOfWeekOrder) {
    if (DayOfWeekOrder < 0 || DayOfWeekOrder > 6) {
        return "";
    }
    string ArrDay[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return ArrDay[DayOfWeekOrder];
}
string MonthName(short Month) {
    string Months[] = {"",
    "Jan","Feb","Mar","Apr","May","Jun",
    "Jul","Aug","Sep","Oct","Nov","Dec"
    };
    return Months[Month];
 }

void PrintMonthCalendar(short Year, short Month) {
    int Current = DayOfWeekOrder(1, Month,Year);
    int NumberOfDays = NumberOfDaysInMonth(Year, Month);

    printf("\n     ________________________%s________________________\n", MonthName(Month).c_str());
    printf("     Sun     Mon     Tue     Wed     Thu     Fri     Sat\n");
    int i;
    for (i = 0; i < Current; i++)
        printf("        ");

    for (int j = 1; j <= NumberOfDays; j++) {
        printf("%8d", j);

        if (++i == 7) {
            i = 0;
            printf("\n");
        }
    }
    printf("\n     ____________________________________________________");
}





int main()
{
    PrintMonthCalendar(2025, 9);
}
