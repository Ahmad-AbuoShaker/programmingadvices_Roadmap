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

int main() {

}