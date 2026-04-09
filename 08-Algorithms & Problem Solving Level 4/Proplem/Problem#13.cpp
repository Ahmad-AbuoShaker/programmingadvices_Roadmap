

#include <iostream>

using namespace std;

struct sDate {
    short Year;
    short Month;
    short Day;
};

bool IsLeabYear(int Year) {
    return(Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
int NumberOfDaysInYear(int Year) {
    return(IsLeabYear) ? 366 : 365;
}

short NumberOfDaysInMonth(short Month, short Year) {
    if (Month < 1 || Month>12) {
        return 0;
    }
    short daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    return Month == 2 && IsLeabYear(Year) ? 29 : daysInMonth[Month];
}

short NumberOfDayFromTheBeginingOfTheYear(short Day, short Month, short Year) {

    for (int i = 1; i < Month; i++) {
        Day += NumberOfDaysInMonth(i, Year);
    }
    return Day;
}


sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {
    sDate Date;
    int RemainingDays = DateOrderInYear;
    int MonthDaays = 0;
    Date.Year = Year;
    Date.Month = 1;
    while (true) {
        MonthDaays = NumberOfDaysInMonth(Date.Month, Year);
        if (RemainingDays > MonthDaays) {
            Date.Month++;
            RemainingDays -= MonthDaays;
        }
        else {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

sDate DateAddDays(short DaysToAdd, sDate Date) {

    int RemainingDays = DaysToAdd + NumberOfDayFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
    int MonthDays = 0;
    Date.Month = 1;

    while (true) {
        MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
        if (RemainingDays > MonthDays) {
            Date.Month++;
            RemainingDays -= MonthDays;

            if (Date.Month > 12) {
                Date.Year++;
                Date.Month = 1;
            }

        }
        else {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

bool IsDate1BeforeDate2(sDate Date1,sDate Date2) {
    return  (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ?
        (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ?
        (Date1.Day < Date2.Day) : false)) : false;
}


int main()
{
    cout << NumberOfDayFromTheBeginingOfTheYear(20, 2, 2022) << endl;
    cout << NumberOfDaysInMonth(2, 2022) << endl;


}
