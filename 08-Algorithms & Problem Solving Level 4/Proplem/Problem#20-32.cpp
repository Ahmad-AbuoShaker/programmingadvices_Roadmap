
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

short NumberOfDaysInMonth(short Month, short Year) {
    if (Month < 1 || Month>12) {
        return 0;
    }
    short daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    return Month == 2 && IsLeabYear(Year) ? 29 : daysInMonth[Month];
}

bool IsLastDayInMonth(sDate Date) {
    return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
}
bool IsLastMonthInYear(short Month) {
    return Month == 12;
}

short NumberOfDayFromTheBeginingOfTheYear(short Day, short Month, short Year) {

    for (int i = 1; i < Month; i++) {
        Day += NumberOfDaysInMonth(Year, i);
    }
    return Day;
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

//////////////////////////////////////////////////////////////////////////////

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

sDate IncreaseDateByXDays(sDate Date,int DaysNumber) {
    for (int i = 0; i < DaysNumber;i++) {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

sDate IncreaseDateByOneWeek(sDate Date) {
    for (int i = 0; i < 7; i++) {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

sDate IncreaseDateByXWeeks(sDate Date, int WeeksNumber) {
    for (int i = 0; i < WeeksNumber; i++) {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

sDate IncreaseDateByOneMonth(sDate Date) {

    if (Date.Month==12)
    {
        Date.Month = 1;
        ++Date.Year;
    }
    else {
        ++Date.Month;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

sDate IncreaseDateByXMonths(sDate Date, int MonthsNumber) {
    for (int i = 0; i < MonthsNumber; i++) {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

sDate IncreaseDateByOneYear(sDate Date) {
    if (IsLeabYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
        Date.Day--;
    Date.Year++;
    return Date;
}

sDate IncreaseDateByXYears(sDate Date, int YearsNumber) {

    Date.Year += YearsNumber;
    if (Date.Month == 2 && Date.Day == 29 && !IsLeabYear(Date.Year)) {
       Date.Day = 28;
    }
    return Date;
}

sDate IncreaseDateByOneDecade(sDate Date) {

    Date.Year += 10;
    if (Date.Month == 2 && Date.Day == 29 && !IsLeabYear(Date.Year)) {
        Date.Day = 28;
    }
    return Date;
}

sDate IncreaseDateByXDecades(sDate Date, int DecadesNumber) {
    Date.Year += 10 * DecadesNumber;
    if (Date.Month == 2 && Date.Day == 29 && !IsLeabYear(Date.Year)) {
        Date.Day = 28;
    }
    return Date;

}

sDate IncreaseDateByOneCentury(sDate Date) {
    Date.Year += 100;
    if (Date.Month == 2 && Date.Day == 29 && !IsLeabYear(Date.Year)) {
        Date.Day = 28;
    }
    return Date;

}
sDate IncreaseDateByOneMillennium(sDate Date) {
    Date.Year += 1000;
    if (Date.Month == 2 && Date.Day == 29 && !IsLeabYear(Date.Year)) {
        Date.Day = 28;
    }
    return Date;
}








int main()
{
    std::cout << "Hello World!\n";
}
