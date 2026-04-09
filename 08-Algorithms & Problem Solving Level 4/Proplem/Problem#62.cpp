

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
bool isValideDate(sDate Date) {
   return !(Date.Month < 1 || Date.Month>12 || Date.Day<1 || Date.Day>NumberOfDaysInMonth(Date.Month, Date.Year));
}


