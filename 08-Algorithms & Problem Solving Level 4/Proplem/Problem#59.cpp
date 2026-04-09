

#include <iostream>

using namespace std;

struct sDate {
    short Year;
    short Month;
    short Day;
};
struct stPeriod {
    sDate StartDate;
    sDate EndDate;
};



short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}
short ReadMonth() {
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}
short ReadYear() {
    short Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}
sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
stPeriod ReadPeriod() {
    stPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();
    return Period;
}

bool IsLeabYear(int Year) {
    return(Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
short NumberOfDaysInMonth(short Month, short Year) {
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
short DayOfWeekOrder(sDate Date) {
    return  DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}
bool IsWeekEnd(sDate Date) {
    return DayOfWeekOrder(Date) >= 5;
}
bool IsBusinessDay(sDate Date) {
    return !IsWeekEnd(Date);
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
void swapDates(sDate& Date1, sDate& Date2) {
    sDate TempDate = Date1;
    Date1 = Date2;
    Date2 = TempDate;
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2) {
    return(Date1.Year == Date2.Year) && (Date1.Month == Date2.Month)
        && (Date1.Day == Date2.Day);
}


bool IsDate1AfterDate2(sDate Date1, sDate Date2) {
    return(!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}
enum enDateCompare { Before = -1, Equal = 0, After = 1 };
enDateCompare CompareDates(sDate Date1, sDate Date2) {
    if (IsDate1BeforeDate2(Date1, Date2))
        return Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return Equal;

    return After;
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) {
    if (CompareDates(Period1.StartDate, Period2.EndDate) == After
        ||
        CompareDates(Period1.EndDate, Period2.StartDate) == Before)
        return false;

    return true;
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false) {

    int Days = 0;
    short SwapFlagValue = 1;
    if (!IsDate1BeforeDate2(Date1, Date2)) {
        swapDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);

    }

    return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}

int GetDifferenceInDays(stPeriod Period1, bool IncludeEndDay = false) {
    return GetDifferenceInDays(Period1.StartDate, Period1.EndDate,IncludeEndDay);
}

int main()
{
    std::cout << "Hello World!\n";
}

