#include <iostream>

using namespace std;

struct sDate {
    short Year;
    short Month;
    short Day;
};

bool IsDate1EqualDate2(sDate Date1, sDate Date2) {
    return(Date1.Year == Date2.Year) && (Date1.Month == Date2.Month)
        && (Date1.Day == Date2.Day);
}

int main() {

}