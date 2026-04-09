
#include <iostream>

using namespace std;

float ReadPositiveNum(string Message) {
    int Num;
    do {
        cout << Message;
        cin >> Num;
    } while (Num <= 0);
    return Num;
}

float HoursToDay(float NumberOfHours) {
    return (float)NumberOfHours / 24;
}

float HoursToWeeks(float NumberOfHours) {
    return (float)NumberOfHours / (24 * 7);
}

float DaysToWeek(float NumberOfDays) {
    return (float)NumberOfDays / 7;
}


int main()
{
    float NumberOfHours = ReadPositiveNum(" Enter Number of Hours : ");
    float NumberOfDays  = HoursToDay(NumberOfHours);
    float NumberOfWeeks = HoursToWeeks(NumberOfHours);
    cout << endl;
    cout << " Total Hours : " << NumberOfHours << endl;
    cout << " Total Days : " << NumberOfDays << endl;
    cout << " Total Weeks : " << NumberOfWeeks << endl;

    return 0;
}
