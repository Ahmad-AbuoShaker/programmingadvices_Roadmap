

#include <iostream>

using namespace std;

struct sDate {
    short Year;
    short Month;
    short Day;
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

bool IsLeabYear(int Year) {
    return(Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
int NumberOfDaysInYear(int Year) {
    return(IsLeabYear(Year)) ? 366 : 365;
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
short DayOfWeekOrder(short Day, short Month, short Year) {
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}
void swapDates(sDate& Date1, sDate& Date2) {
    sDate TempDate = Date1;
    Date1 = Date2;
    Date2 = TempDate;
}
bool IsLastDayInMonth(sDate Date) {
    return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
}
bool IsLastMonthInYear(short Month) {
    return Month == 12;
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
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {
    return  (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ?
        (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ?
            (Date1.Day < Date2.Day) : false)) : false;
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


short DayOfWeekOrder(sDate Date) {
    return  DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}
string DayShortName(int DayOfWeekOrder) {
    string ArrDay[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return ArrDay[DayOfWeekOrder];
}
bool IsEndOfWeek(sDate Date) {
    return DayOfWeekOrder(Date) == 6;
}
bool IsWeekEnd(sDate Date) {
    return DayOfWeekOrder(Date) >= 5;
}
bool IsBusinessDay(sDate Date) {
    return !IsWeekEnd(Date);
}
short DaysUntilTheEndOfWeek(sDate Date) {
    return 6 - DayOfWeekOrder(Date);
}
short DaysUntilTheEndOfMonth(sDate Date) {

    sDate EndOfMonthDate;
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Month,Date.Year);
    EndOfMonthDate.Year = Date.Year;
    GetDifferenceInDays(Date, EndOfMonthDate, true);

}
short DaysUntilTheEndOfYear(sDate Date) {

    sDate EndOfYearDate;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Day = 31;
    EndOfYearDate.Year = Date.Year;
    GetDifferenceInDays(Date, EndOfYearDate,true);
}


















int main()
{
   
}

