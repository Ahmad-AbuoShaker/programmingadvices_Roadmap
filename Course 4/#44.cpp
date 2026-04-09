

#include <iostream>
using namespace std;
enum enWeeekDay { sat = 1,sun = 2, mon = 3, tus = 4, wen = 5, thu = 6, fri = 7 };


int ReadNumberInRange(string Message, int From, int To) {
    int Num = 0;
    do {
        cout << Message << endl;
        cin >> Num;
    } while (Num <= From && Num >= To);
    return Num;
}

enWeeekDay ReadWeekDay() {
    return (enWeeekDay)ReadNumberInRange(" Enter Day Number { sat = 1,sun = 2, mon = 3, tus = 4, wen = 5, thu = 6, fri = 7 }",1,7);
}

string GetDayOfWeek(enWeeekDay WeekDay) {
    switch (WeekDay) {
    case enWeeekDay::sat:
        return "Saturday";
        break;
    case enWeeekDay::sun:
        return "Sunday";
        break;
    case enWeeekDay::mon:
        return "Monday";
        break;
    case enWeeekDay::tus:
        return "Tuesday";
        break;
    case enWeeekDay::wen:
        return "Wednesday";
        break;
    case enWeeekDay::thu:
        return "ThursDay";
        break;
    case enWeeekDay::fri:
        return "Friday";;
        break;
    default:
        return "Not a week day";
    }

}

void main() {

    cout << GetDayOfWeek(ReadWeekDay()) << endl;


}