
#include <iostream>

using namespace std;

struct strTaskDuration {
    int NumOfDays, NumOfHours, NumOfMinutes, NumOfSeconds;
};

int ReadPositiveNum(string Message) {
    int Num;
    do {
        cout << Message;
        cin >> Num;
    } while (Num <= 0);
    return Num;
}

strTaskDuration SecondsToTaskDuration(int TotalSeconds) {
    strTaskDuration TaskDuration;
    const int SecondsPreDay = 24 * 60 * 60;
    const int SecondsPreHour = 60 * 60;
    const int SecondsPreMinute = 60;

    
    int Remainder = 0;
    TaskDuration.NumOfDays = TotalSeconds / SecondsPreDay;
    Remainder = TotalSeconds % SecondsPreDay;
    TaskDuration.NumOfHours = Remainder / SecondsPreHour;
    Remainder = Remainder % SecondsPreHour;
    TaskDuration.NumOfMinutes = Remainder / SecondsPreMinute;
    Remainder = Remainder % SecondsPreMinute;
    TaskDuration.NumOfSeconds = Remainder;
    return TaskDuration;

}

void PrintTaskDurationDetails(strTaskDuration TaskDuration) {
    

    cout << TaskDuration.NumOfDays << ":" <<  TaskDuration.NumOfHours << ":" <<
        TaskDuration.NumOfMinutes << ":" << TaskDuration.NumOfSeconds << endl;
    

}


int main()
{ 
    int TotalSeconds = ReadPositiveNum(" Enter Number of the Seconds :");
    PrintTaskDurationDetails(SecondsToTaskDuration(TotalSeconds));


    return 0;
}
