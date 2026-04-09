// #4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct stInfo {
    int age;
    bool HasDrivingLicense;
    bool HasRecommendation;

};
stInfo ReadInfo() {
    stInfo Info;
    cout << " Enter your age :";
    cin >> Info.age;
    cout << " DO you have Driving License ?\n [No:0/Yes:1] :";
    cin >> Info.HasDrivingLicense;
    cout << " DO you have Recommendation?\n [No:0/Yes:1] :";
    cin >> Info.HasRecommendation;
    return Info;
}
bool IsAccepted(stInfo Info) {
    if (Info.HasRecommendation) {
        return true;
    }
    else {
        return (Info.age > 18 && Info.HasDrivingLicense);
    }
}
void PrintResult(stInfo Info) {

    if (IsAccepted(Info)) {
        cout << " Hired";
    }
    else {
        cout << " Rejected";
    }

}
int main()
{
    PrintResult(ReadInfo());
        return 0;
}

