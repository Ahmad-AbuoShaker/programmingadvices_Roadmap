# pragma warning(disable : 4996)

#include <iostream>
#include<ctime>

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
        Day += NumberOfDaysInMonth(Year, i);
    }
    return Day;
}

bool IsLastDayInMonth(sDate Date) {


    return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
}
bool IsLastMonthInYear(short Month) {
    return Month == 12;
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {
    return  (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ?
        (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ?
            (Date1.Day < Date2.Day) : false)) : false;
}
bool IsDate1EqualDate2(sDate Date1, sDate Date2) {
    return(Date1.Year == Date2.Year) && (Date1.Month == Date2.Month)
        && (Date1.Day == Date2.Day);
}

sDate IncreaseDateByOneDay(sDate Date) {

    if (IsLastDayInMonth(Date)) {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            ++Date.Year;
        }
        else {
            Date.Day = 1;
            ++Date.Month;
        }
    }
    else {
        ++Date.Day;
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


int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false) {

    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);

    }

    return IncludeEndDay ? ++Days : Days;
}




int main() {

}


