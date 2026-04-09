// Homework 41.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct stInfo {
    string FirstName;
    string LastName;
    int Age;
    string Phone;
};
void ReadInfo(stInfo &Info) {
    cout << " pleas enter your first name :" << endl;
    cin >> Info.FirstName;
    cout << " pleas enter your last name :" << endl;
    cin >> Info.LastName;
    cout << " pleas enter your age :" << endl;
    cin >> Info.Age;
    cout << " pleas enter your phone number :" << endl;
    cin >> Info.Phone;
}

void PrintInfo(stInfo Info) {
    cout << " ************************" << endl;
    cout << " First Name:" << Info.FirstName << endl;
    cout << " Last Name:" << Info.LastName << endl;
    cout << " age:" << Info.Age << "years" << endl;
    cout << " phone:" << Info.Phone << endl;
    cout << " ************************" << endl;
}

void ReadPersonInfo(stInfo person[2]) {
    ReadInfo(person[0]);
    ReadInfo(person[1]);
}
void PrintPersonInfo(stInfo person[2]) {
    cout << " ******************************************" << endl;
    PrintInfo(person[0]);
    PrintInfo(person[1]);



}


int main(){
    stInfo person[2];
    ReadPersonInfo(person);
    PrintPersonInfo(person);

}
