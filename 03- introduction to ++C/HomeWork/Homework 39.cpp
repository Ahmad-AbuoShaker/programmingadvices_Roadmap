// Homework 39.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void ReadGrade(int Grade[3]) {

    cout << "Enter Grade1" << endl;
    cin >> Grade[0];
    cout << "Enter Grade2" << endl;
    cin >> Grade[1];
    cout << "Enter Grade3" << endl;
    cin >> Grade[2];
}
float AverageGrade (int Grade[3]){
  return ( Grade[0] + Grade[1] + Grade[2]) / 3; 
}

int main()
{
    int Grade[3];
    ReadGrade(Grade);
    cout << "Average :" << AverageGrade(Grade) << endl;
    
}

