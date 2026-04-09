

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

sDate CalculateVacationReturnDate(sDate DateFrom, short VacationDays) {

    short  DaWeekEndCounter = 0;
    while (IsWeekEnd(DateFrom)) {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    for (int i = 0; i < VacationDays + DaWeekEndCounter; i++) {
        if (IsWeekEnd(DateFrom))
            DaWeekEndCounter++;
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    while (IsWeekEnd(DateFrom)) {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    return DateFrom;
}










int main()
{
    std::cout << "Hello World!\n";
}

