

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


sDate DecreaseDateByOneDay(sDate Date) {
   
    if (Date.Day == 1) {
       
        if (Date.Month == 0)
        {
            Date.Year--;
            Date.Month = 12;
            Date.Day = 31;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
        }
    }
    else {
        Date.Day--;
    }
    return Date;
}
sDate DecreaseDateByXDays(sDate Date,int Days) {
    for (int i = 0; i < Days; i++) {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}
sDate DecreaseDateByOneWeek(sDate Date) {
    for (int i = 0; i < 7; i++) {
        DecreaseDateByOneDay(Date);
    }
    return Date;
}
sDate DecreaseDateByXWeeks(sDate Date, int Weeks) {
    for (int i = 0; i < Weeks; i++) {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}
sDate DecreaseDateByOneMonth(sDate Date) {
    
    if (Date.Month == 1) {
        Date.Month = 12;
        Date.Year--;
    }
    else {
        Date.Month--;
    }

    short NumberOfDays = NumberOfDaysInMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDays) {
        Date.Day = NumberOfDays;
    }
    return Date;
}
sDate DecreaseDateByXMonths(sDate Date, int Months) {
    for (int i = 0; i < Months; i++) {
       Date= DecreaseDateByOneMonth(Date);
    }
    return Date;
}
sDate DecreaseDateByOneYear(sDate Date) {

    Date.Year--;
    if (Date.Month == 2 && Date.Day == 29 && !IsLeabYear(Date.Year)) {
        Date.Day = 28;
    }
    return Date;
}
sDate DecreaseDateByXYears(sDate Date, int Years) {
    Date.Year -= Years;
    if (Date.Month == 2 && Date.Day == 29 && !IsLeabYear(Date.Year)) {
        Date.Day = 28;
    }
    return Date;
}
sDate DecreaseDateByOneDecade(sDate Date) {
    Date.Year -= 10;
    if (Date.Month == 2 && Date.Day == 29 && !IsLeabYear(Date.Year)) {
        Date.Day = 28;
    }
    return Date;
}
sDate DecreaseDateByXDecades(sDate Date, int Decades){
    Date.Year -= 10 * Decades;
    if (Date.Month == 2 && Date.Day == 29 && !IsLeabYear(Date.Year)) {
        Date.Day = 28;
    }
    return Date;
}
sDate DecreaseDateByOneCentury(sDate Date) {
    Date.Year -= 100;
    if (Date.Month == 2 && Date.Day == 29 && !IsLeabYear(Date.Year)) {
        Date.Day = 28;
    }
    return Date;
}
sDate DecreaseDateByOneMillennium(sDate Date) {
    Date.Year -= 1000;
    if (Date.Month == 2 && Date.Day == 29 && !IsLeabYear(Date.Year)) {
        Date.Day = 28;
    }
    return Date;
}







int main()
{
    sDate Date = ReadFullDate();
    Date = DecreaseDateByOneDay(Date);
    cout << Date.Year << endl;
    cout << Date.Month << endl;
    cout << Date.Day << endl;

}

