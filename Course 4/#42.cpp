
#include <iostream>

using namespace std;

struct strTaskDuration {
    int NumOfDays, NumOfHours, NumOfMinutes, NumOfSeconds;
};

float ReadPositiveNum(string Message) {
    int Num;
    do {
        cout << Message;
        cin >> Num;
    } while (Num <= 0);
    return Num;
}

strTaskDuration ReadTaskDuration() {
    strTaskDuration TaskDuration;
    TaskDuration.NumOfDays = ReadPositiveNum(" Enter the Number of Days : ");
    TaskDuration.NumOfHours = ReadPositiveNum(" Enter the Number of Hours : ");
    TaskDuration.NumOfMinutes = ReadPositiveNum(" Enter the Number of minutes : ");
    TaskDuration.NumOfSeconds = ReadPositiveNum(" Enter the Number of Seconds : ");
    return TaskDuration;

}

float TaskDurationInSeconds(strTaskDuration TaskDuration) {
    float DurationInSeconds = 0;

    DurationInSeconds = TaskDuration.NumOfDays * (24 * 60 * 60);
    DurationInSeconds += TaskDuration.NumOfHours * 60 * 60;
    DurationInSeconds += TaskDuration.NumOfMinutes * 60;
    DurationInSeconds += TaskDuration.NumOfSeconds;
    return DurationInSeconds;

}


int main()
{
   
    cout << " Task Duration in Seconds : " <<
        TaskDurationInSeconds(ReadTaskDuration()) << endl;

    return 0;
}
