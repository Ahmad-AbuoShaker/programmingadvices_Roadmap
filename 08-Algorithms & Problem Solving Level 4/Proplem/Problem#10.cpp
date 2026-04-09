

#include <iostream>

using namespace std;

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
       Day+= NumberOfDaysInMonth(i,Year);
    }
    return Day;
}


int main()
{
   cout<< NumberOfDayFromTheBeginingOfTheYear(20,9,2022);

}
